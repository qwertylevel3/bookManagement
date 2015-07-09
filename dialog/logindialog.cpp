#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

QString LoginDialog::getManagerName()
{
    return ui->maganerNameLineEdit->text();
}

QString LoginDialog::getPassword()
{
    return ui->passwordLineEdit->text();
}


LoginDialog::~LoginDialog()
{
    delete ui;
}
