#ifndef SEARCHREADERDIALOG_H
#define SEARCHREADERDIALOG_H

#include <QDialog>

namespace Ui {
class SearchReaderDialog;
}

class SearchReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchReaderDialog(QWidget *parent = 0);
    ~SearchReaderDialog();

    void setID(QString id);
    void setReaderName(QString name);
    void setSex(QString sex);
    void setTel(QString tel);
    void setMoney(double money);
private:
    Ui::SearchReaderDialog *ui;
};

#endif // SEARCHREADERDIALOG_H
