#ifndef ADDREADERDIALOG_H
#define ADDREADERDIALOG_H

#include <QDialog>

namespace Ui {
class addReaderDialog;
}

class AddReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddReaderDialog(QWidget *parent = 0);
    ~AddReaderDialog();
    QString getRid();
    QString getReaderName();
    QString getSex();
    QString getTel();

signals:
    void isConfirmed(bool);
private slots:
    void confirm();
private:
    Ui::addReaderDialog *ui;
};

#endif // ADDREADERDIALOG_H
