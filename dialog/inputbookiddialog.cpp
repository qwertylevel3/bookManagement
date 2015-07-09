#include "inputbookiddialog.h"
#include "ui_inputbookiddialog.h"

InputBookIDDialog::InputBookIDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputBookIDDialog)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(enableOkButton()));
}

void InputBookIDDialog::enableOkButton()
{
    ui->okButton->setEnabled(true);
}

QString InputBookIDDialog::getBookID()
{
    return ui->lineEdit->text();
}

InputBookIDDialog::~InputBookIDDialog()
{
    delete ui;
}
