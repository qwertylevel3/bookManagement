#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

QString SearchDialog::getBookName()
{
    return ui->nameLineEdit->text();
}

QString SearchDialog::getBookISBN()
{
    return ui->ISBNLineEdit->text();
}

QString SearchDialog::getPublisher()
{
    return ui->publisherLineEdit->text();
}

QString SearchDialog::getTranslater()
{
    return ui->translatorLineEdit->text();
}

QString SearchDialog::getWriter()
{
    return ui->writerLineEdit->text();
}

QString SearchDialog::getTypename()
{
    return ui->typenameLineEdit->text();
}
