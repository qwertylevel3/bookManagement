#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

namespace Ui {
class deleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = 0);
    ~DeleteDialog();
    QString getID();
    QString getNum();

private:
    Ui::deleteDialog *ui;
};

#endif // DELETEDIALOG_H
