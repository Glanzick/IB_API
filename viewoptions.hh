#ifndef VIEWOPTIONS_HH
#define VIEWOPTIONS_HH

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class ViewOptions;
}

class ViewOptions : public QDialog
{
    Q_OBJECT

public:
    explicit ViewOptions(QWidget *parent = 0);
    ~ViewOptions();

private:
    Ui::ViewOptions *ui;
    QSqlTableModel* b_table;
    int b_row_count;
};

#endif // VIEWOPTIONS_HH
