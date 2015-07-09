#include "updatereaderdialog.h"
#include "ui_updatereaderdialog.h"

UpdateReaderDialog::UpdateReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateReaderDialog)
{
    ui->setupUi(this);

    connect(ui->readerNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(this,SIGNAL(isConfirmed(bool)),ui->okButton,SLOT(setEnabled(bool)));
}

UpdateReaderDialog::~UpdateReaderDialog()
{
    delete ui;
}

QString UpdateReaderDialog::getID()
{
    return ui->IDLineEdit->text();
}

QString UpdateReaderDialog::getReaderName()
{
    return ui->readerNameLineEdit->text();
}

QString UpdateReaderDialog::getSex()
{
    return ui->sexComboBox->currentText();
}

QString UpdateReaderDialog::getTel()
{
    return ui->telLineEdit->text();
}

double UpdateReaderDialog::getKeepmoney()
{
    return ui->keepmoneyDoubleSpinBox->value();
}

void UpdateReaderDialog::setID(QString id)
{
    ui->IDLineEdit->setText(id);
}

void UpdateReaderDialog::setReaderName(QString name)
{
    ui->readerNameLineEdit->setText(name);
}

void UpdateReaderDialog::setSex(QString sex)
{
    ui->sexComboBox->setCurrentText(sex);
}

void UpdateReaderDialog::setTel(QString tel)
{
    ui->telLineEdit->setText(tel);
}

void UpdateReaderDialog::setkeepmoney(double money)
{
    ui->keepmoneyDoubleSpinBox->setValue(money);
}

void UpdateReaderDialog::confirm()
{
    if(ui->readerNameLineEdit->text()=="")
    {
        ui->messageLabel->setText("读者姓名不能为空");
        emit isConfirmed(false);
        return;
    }
    ui->messageLabel->setText("");
    emit isConfirmed(true);
}
