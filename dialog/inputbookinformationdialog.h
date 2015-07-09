#ifndef INPUTBOOKINFORMATIONDIALOG_H
#define INPUTBOOKINFORMATIONDIALOG_H

#include <QDialog>

namespace Ui {
class InputBookInformationDialog;
}

class InputBookInformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputBookInformationDialog(QWidget *parent = 0);
    ~InputBookInformationDialog();
    QString getBookName();
    QString getISBN();
    QString getWriter();
    QString getPublisher();
    QString getNumber();
    QString getTranslater();
    QDate getDate();
    QString getPrice();
    QString getTypename();

    void setBookName(QString name);
    void setISBN(QString ISBN);
    void setWriter(QString writer);
    void setPublisher(QString publisher);
    void setNumber(int number);
    void setTranslater(QString translater);
    void setDate(QDate date);
    void setPrice(double price);
    void setTypename(QString bookTypename);

    void setISBNEditable(bool editable);
signals:
    void isConfirmed(bool);
private slots:
    void confirm();
private:
    Ui::InputBookInformationDialog *ui;
};

#endif // INPUTBOOKINFORMATIONDIALOG_H
