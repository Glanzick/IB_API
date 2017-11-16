#include "positions.h"

#include <QSqlDatabase>
#include <QSqlRecord>

#include <iostream>
#include <QSqlTableModel>
#include <QDebug>

Positions::Positions()
{

}

void Positions::load_positions_from_sql()
{
    auto db = QSqlDatabase::database();
    auto tables = db.tables();

    if (tables.contains("options"))
    {
        load_options_from_sql();
    }
}

void Positions::save_positions_to_sql()
{
    for (auto& opt : b_options)
    {
        opt.save_to_sql();
    }
}

void Positions::load_options_from_sql()
{
    QSqlTableModel table;
    table.setTable("options");
    table.select();

    for (int i = 0; i < table.rowCount(); i++)
    {
        QSqlRecord record = table.record(i);
        Options opt;
        opt.set_sql_id(record.value("id").toInt());
        opt.set_number_short(record.value("number").toInt());
        opt.set_ticker(record.value("ticker").toString());
        opt.set_premium(record.value("premium").toFloat());
        opt.set_expiry(QDate::fromString(record.value("expiry").toString(), "yyyy-m-d"));
        b_options.push_back(std::move(opt));
    }
}

void Positions::add_option(Options &&opt)
{
    b_options.push_back(std::move(opt));
}
