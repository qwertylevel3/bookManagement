#ifndef INPUTBOOKIDDIALOG_H
#define INPUTBOOKIDDIALOG_H

#include <QDialog>

namespace Ui {
class InputBookIDDialog;
}

class InputBookIDDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputBookIDDialog(QWidget *parent = 0);
    ~InputBookIDDialog();
    QString getBookID();
private slots:
    void enableOkButton();
private:
    Ui::InputBookIDDialog *ui;
};

#endif // INPUTBOOKIDDIALOG_H
