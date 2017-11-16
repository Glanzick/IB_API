#include "addposition.h"
#include "ui_addposition.h"

#include "options.h"

AddPosition::AddPosition(Positions* positions,
                         QWidget*   parent)
    : QTabWidget(parent)
    , ui(new Ui::AddPosition)
    , b_positions(positions)
{
    ui->setupUi(this);
}

AddPosition::~AddPosition()
{
    delete ui;
}

void AddPosition::on_pushButton_clicked()
{
    // Determine the next position id:
    auto id = b_positions->num_options();

    // Create option based on user values.
    Options opt;
    opt.set_sql_id(id);
    opt.set_ticker(ui->lineEdit->text());
    opt.set_number_short(ui->spinBox->value());
    opt.set_premium(ui->doubleSpinBox->value());
    opt.set_expiry(ui->dateEdit->date());
    opt.mark_modified();
    b_positions->add_option(std::move(opt));
}
