#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QFileDialog>
#include <QDir>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>

#include <memory>

#include "viewoptions.hh"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Open_Database_triggered()
{
    auto DB_name = QFileDialog::getOpenFileName(this, tr("New Dfatabase Name"),
                                                QDir::homePath(),
                                                tr("Databases (*.db)"));

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_name);
}

void MainWindow::on_action_New_Database_triggered()
{
    auto DB_name = QFileDialog::getSaveFileName(this, tr("New Database Name"),
                                                QDir::homePath(),
                                                tr("Databases (*.db)"));

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_name);
}


void MainWindow::on_actionEdit_Options_triggered()
{
    auto options = new ViewOptions(this);
    options->exec();
}
