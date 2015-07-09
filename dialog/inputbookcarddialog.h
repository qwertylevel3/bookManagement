#ifndef INPUTBOOKCARDDIALOG_H
#define INPUTBOOKCARDDIALOG_H

#include <QDialog>

namespace Ui {
class InputBookCardDialog;
}

class InputBookCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputBookCardDialog(QWidget *parent = 0);
    ~InputBookCardDialog();
    QString getCard();
private slots:
    void enableOkButton();
private:
    Ui::InputBookCardDialog *ui;
};

#endif // INPUTBOOKCARDDIALOG_H
