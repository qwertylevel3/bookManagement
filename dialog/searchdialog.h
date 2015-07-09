#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = 0);
    ~SearchDialog();
    QString getBookName();
    QString getBookISBN();
    QString getPublisher();
    QString getTranslater();
    QString getWriter();
    QString getTypename();
private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
