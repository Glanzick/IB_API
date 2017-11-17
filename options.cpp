#include "options.h"

#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>

Options::Options()
    : b_modified(false)
{

}

void Options::save_to_sql()
{
    if (! b_modified) return;

    auto db = QSqlDatabase::database();

    auto record = db.record("options");
    record.setValue("num", b_number_short);
    record.setValue("ticker", b_ticker);
    record.setValue("premium", b_premium);
    record.setValue("expiry", b_expiry.toString("yyyy-MM-dd"));

    QSqlTableModel table;
    table.setTable("options");
    table.select();

    if (! table.setRecord(b_sql_id, record))
    {
        table.insertRecord(-1, record);
    }

    b_modified = false;
}
