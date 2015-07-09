#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteDialog)
{
    ui->setupUi(this);
}

QString DeleteDialog::getID()
{
    return ui->lineEdit->text();
}

QString DeleteDialog::getNum()
{
    return ui->spinBox->text();
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}
