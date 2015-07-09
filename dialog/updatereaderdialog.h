#ifndef UPDATEREADERDIALOG_H
#define UPDATEREADERDIALOG_H

#include <QDialog>

namespace Ui {
class UpdateReaderDialog;
}

class UpdateReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateReaderDialog(QWidget *parent = 0);
    ~UpdateReaderDialog();
    QString getID();
    QString getReaderName();
    QString getSex();
    QString getTel();
    double getKeepmoney();

    void setID(QString id);
    void setReaderName(QString name);
    void setSex(QString sex);
    void setTel(QString tel);
    void setkeepmoney(double money);


signals:
    void isConfirmed(bool);
private slots:
    void confirm();
private:
    Ui::UpdateReaderDialog *ui;
};

#endif // UPDATEREADERDIALOG_H
