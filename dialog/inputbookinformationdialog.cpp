#include "inputbookinformationdialog.h"
#include "ui_inputbookinformationdialog.h"

InputBookInformationDialog::InputBookInformationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputBookInformationDialog)
{
    ui->setupUi(this);

    connect(ui->bookIDLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->nameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(ui->typenameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(confirm()));
    connect(this,SIGNAL(isConfirmed(bool)),ui->okButton,SLOT(setEnabled(bool)));
}

QString InputBookInformationDialog::getISBN()
{
    return ui->bookIDLineEdit->text();
}
QString InputBookInformationDialog::getBookName()
{
    return ui->nameLineEdit->text();
}
QString InputBookInformationDialog::getPublisher()
{
    return ui->publisherLineEdit->text();
}
QString InputBookInformationDialog::getWriter()
{
    return ui->writerLineEdit->text();
}
QString InputBookInformationDialog::getNumber()
{
    return ui->spinBox->text();
}

QString InputBookInformationDialog::getTranslater()
{
    return ui->translaterLineEdit->text();
}

QDate InputBookInformationDialog::getDate()
{
    return ui->dateEdit->date();
}

QString InputBookInformationDialog::getPrice()
{
    return ui->priceSpinBox->text();
}

QString InputBookInformationDialog::getTypename()
{
    return ui->typenameLineEdit->text();
}

void InputBookInformationDialog::setBookName(QString name)
{
    ui->nameLineEdit->setText(name);
}

void InputBookInformationDialog::setISBN(QString ISBN)
{
    ui->bookIDLineEdit->setText(ISBN);
}

void InputBookInformationDialog::setWriter(QString writer)
{
    ui->writerLineEdit->setText(writer);
}

void InputBookInformationDialog::setPublisher(QString publisher)
{
    ui->publisherLineEdit->setText(publisher);
}

void InputBookInformationDialog::setNumber(int number)
{
    ui->spinBox->setValue(number);
}

void InputBookInformationDialog::setTranslater(QString translater)
{
    ui->translaterLineEdit->setText(translater);
}

void InputBookInformationDialog::setDate(QDate date)
{
    ui->dateEdit->setDate(date);
}

void InputBookInformationDialog::setPrice(double price)
{
    ui->priceSpinBox->setValue(price);
}

void InputBookInformationDialog::setTypename(QString bookTypename)
{
    ui->typenameLineEdit->setText(bookTypename);
}

void InputBookInformationDialog::setISBNEditable(bool editable)
{
    ui->bookIDLineEdit->setEnabled(editable);
}

void InputBookInformationDialog::confirm()
{
    if(ui->bookIDLineEdit->text()=="")
    {
        ui->messageLabel->setText("ISBN不能为空");
        emit isConfirmed(false);
        return;
    }
    if(ui->nameLineEdit->text()=="")
    {
        ui->messageLabel->setText("书名不能为空");
        emit isConfirmed(false);
        return;
    }
    if(ui->typenameLineEdit->text()=="")
    {
        ui->messageLabel->setText("图书类别不能为空");
        emit isConfirmed(false);
        return ;
    }

    emit isConfirmed(true);
    ui->messageLabel->setText("");
}


InputBookInformationDialog::~InputBookInformationDialog()
{
    delete ui;
}
