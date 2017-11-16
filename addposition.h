#ifndef ADDPOSITION_H
#define ADDPOSITION_H

#include <QTabWidget>
#include "positions.h"

namespace Ui {
class AddPosition;
}

class AddPosition : public QTabWidget
{
    Q_OBJECT

public:
    explicit AddPosition(Positions* positions,
                         QWidget*   parent = 0);
    ~AddPosition();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddPosition *ui;
    Positions* b_positions;
};

#endif // ADDPOSITION_H
