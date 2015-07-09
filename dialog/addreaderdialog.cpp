#include "addreaderdialog.h"
#include "ui_addreaderdialog.h"

AddReaderDialog::AddReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addReaderDialog)
{
    ui->setupUi(this);

    connect(ui->readerNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->IDLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(this,SIGNAL(isConfirmed(bool)),ui->okButton,SLOT(setEnabled(bool)));
}

AddReaderDialog::~AddReaderDialog()
{
    delete ui;
}

QString AddReaderDialog::getRid()
{
    return ui->IDLineEdit->text();
}

QString AddReaderDialog::getReaderName()
{
    return ui->readerNameLineEdit->text();
}

QString AddReaderDialog::getSex()
{
    return ui->comboBox->currentText();
}

QString AddReaderDialog::getTel()
{
    return ui->telLineEdit->text();
}

void AddReaderDialog::confirm()
{
    if(ui->readerNameLineEdit->text()=="")
    {
        ui->messageLabel->setText("读者姓名不能为空");
        emit isConfirmed(false);
        return;
    }
    if(ui->IDLineEdit->text()=="")
    {
        ui->messageLabel->setText("读者ID不能为空");
        emit isConfirmed(false);
        return;
    }
    ui->messageLabel->setText("");
    emit isConfirmed(true);
    return;
}


