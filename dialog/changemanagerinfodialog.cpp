#include "changemanagerinfodialog.h"
#include "ui_changemanagerinfodialog.h"

ChangeManagerInfoDialog::ChangeManagerInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeManagerInfoDialog)
{
    ui->setupUi(this);

    ui->oldPwLineEdit->setEchoMode(QLineEdit::Password);
    ui->newPwLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPwLineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->oldPwLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->newPwLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->confirmPwLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(this,SIGNAL(isConfirmed(bool)),ui->okButton,SLOT(setEnabled(bool)));
}

ChangeManagerInfoDialog::~ChangeManagerInfoDialog()
{
    delete ui;
}

QString ChangeManagerInfoDialog::getNewPassword()
{
    return ui->newPwLineEdit->text();
}

QString ChangeManagerInfoDialog::getOldPassword()
{
    return ui->oldPwLineEdit->text();
}
void ChangeManagerInfoDialog::confirm()
{
    if(ui->newPwLineEdit->text() == ui->confirmPwLineEdit->text())
    {
        if(ui->newPwLineEdit->text()!="")
        {
            emit isConfirmed(true);
            ui->messageLabel->setText("");
            return;
        }
        else
        {
            ui->messageLabel->setText("密码不能为空");
        }
    }
    ui->messageLabel->setText("请输入密码");
    emit isConfirmed(false);
}
