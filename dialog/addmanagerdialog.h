#ifndef ADDMANAGERDIALOG_H
#define ADDMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class AddManagerDialog;
}

class AddManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddManagerDialog(QWidget *parent = 0);
    ~AddManagerDialog();
    QString getName();
    QString getPassword();
    QString getSex();
    QString getTel();
signals:
    void isConfirmed(bool);
private slots:
    void confirm();
private:
    Ui::AddManagerDialog *ui;
};

#endif // ADDMANAGERDIALOG_H
