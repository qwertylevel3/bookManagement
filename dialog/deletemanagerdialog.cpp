#include "deletemanagerdialog.h"
#include "ui_deletemanagerdialog.h"

DeleteManagerDialog::DeleteManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteManagerDialog)
{
    ui->setupUi(this);
}

DeleteManagerDialog::~DeleteManagerDialog()
{
    delete ui;
}

QString DeleteManagerDialog::getName()
{
    return ui->nameLineEdit->text();
}
