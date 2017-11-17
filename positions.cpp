#include "positions.h"

#include <QSqlDatabase>
#include <QSqlRecord>

#include <iostream>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>

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
    if (! QSqlDatabase::contains()) return;

    auto db = QSqlDatabase::database();
    auto tables = db.tables();

    if (! b_options.empty() && ! tables.contains("options"))
    {
        qInfo() << "trying to create table";
        db.exec(Options::table_definition());
    }

    for (auto& opt : b_options)
    {
        opt.save_to_sql();
    }
}

void Positions::load_options_from_sql()
{
    if (! QSqlDatabase::contains()) return;

    QSqlTableModel table;
    table.setTable("options");
    table.select();

    for (int i = 0; i < table.rowCount(); i++)
    {
        qInfo() << "loading record : " << i;
        QSqlRecord record = table.record(i);
        Options opt;
        opt.set_sql_id(record.value("id").toUInt());
        opt.set_number_short(record.value("number").toUInt());
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
