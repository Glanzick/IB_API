#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Open_Database_triggered();

    void on_action_New_Database_triggered();

    void on_actionEdit_Options_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
