#include "inputbookcarddialog.h"
#include "ui_inputbookcarddialog.h"

InputBookCardDialog::InputBookCardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputBookCardDialog)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(enableOkButton()));
}

QString InputBookCardDialog::getCard()
{
    return ui->lineEdit->text();
}

void InputBookCardDialog::enableOkButton()
{
    ui->okButton->setEnabled(true);
}

InputBookCardDialog::~InputBookCardDialog()
{
    delete ui;
}
