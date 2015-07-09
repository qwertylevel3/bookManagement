#ifndef CHANGEMANAGERINFODIALOG_H
#define CHANGEMANAGERINFODIALOG_H

#include <QDialog>

namespace Ui {
class ChangeManagerInfoDialog;
}

class ChangeManagerInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeManagerInfoDialog(QWidget *parent = 0);
    ~ChangeManagerInfoDialog();

    QString getOldPassword();
    QString getNewPassword();
signals:
    void isConfirmed(bool);
private slots:
    void confirm();
private:
    Ui::ChangeManagerInfoDialog *ui;

};

#endif // CHANGEMANAGERINFODIALOG_H
