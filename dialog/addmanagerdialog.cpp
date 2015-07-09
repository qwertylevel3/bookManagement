#include "addmanagerdialog.h"
#include "ui_addmanagerdialog.h"

AddManagerDialog::AddManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddManagerDialog)
{
    ui->setupUi(this);

    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    connect(ui->nameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->passwordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->confirmPasswordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(this,SIGNAL(isConfirmed(bool)),ui->okButton,SLOT(setEnabled(bool)));
}

QString AddManagerDialog::getName()
{
    return ui->nameLineEdit->text();
}

QString AddManagerDialog::getPassword()
{
    return ui->passwordLineEdit->text();
}

QString AddManagerDialog::getSex()
{
    return ui->sexComboBox->currentText();
}

QString AddManagerDialog::getTel()
{
    return ui->telLineEdit->text();
}

void AddManagerDialog::confirm()
{
    if(ui->passwordLineEdit->text() == ui->confirmPasswordLineEdit->text())
    {
        if(ui->passwordLineEdit->text()!="")
        {
            if(ui->nameLineEdit->text()!="")
            {
                emit isConfirmed(true);
                ui->messageLabel->setText("");
                return;
            }
            else
            {
                ui->messageLabel->setText("名称不能为空");
            }
        }
        else
        {
            ui->messageLabel->setText("密码不能为空");
        }
    }
    emit isConfirmed(false);
}


AddManagerDialog::~AddManagerDialog()
{
    delete ui;
}
