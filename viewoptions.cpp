#include "viewoptions.hh"
#include "ui_viewoptions.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <memory>
#include <QDebug>

ViewOptions::ViewOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewOptions)
{
    auto db = QSqlDatabase::database();
    db.open();

    b_table = new QSqlTableModel(this, db);
    b_table->setTable("Options");
    b_table->select();
    b_row_count = b_table->rowCount();

    ui->setupUi(this);

    ui->lcdNumber->display(b_row_count);

    ui->tableView->setModel(b_table);
    db.close();
}

ViewOptions::~ViewOptions()
{
    delete ui;
}
