#include "searchreaderdialog.h"
#include "ui_searchreaderdialog.h"

SearchReaderDialog::SearchReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchReaderDialog)
{
    ui->setupUi(this);
}

SearchReaderDialog::~SearchReaderDialog()
{
    delete ui;
}

void SearchReaderDialog::setID(QString id)
{
    ui->IDLineEdit->setText(id);
}

void SearchReaderDialog::setReaderName(QString name)
{
    ui->readerNameLineEdit->setText(name);
}

void SearchReaderDialog::setSex(QString sex)
{
    ui->sexLineEdit->setText(sex);
}

void SearchReaderDialog::setTel(QString tel)
{
    ui->telLineEdit->setText(tel);
}

void SearchReaderDialog::setMoney(double money)
{
    ui->doubleSpinBox->setValue(money);
}
