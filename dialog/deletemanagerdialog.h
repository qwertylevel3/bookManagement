#ifndef DELETEMANAGERDIALOG_H
#define DELETEMANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteManagerDialog;
}

class DeleteManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteManagerDialog(QWidget *parent = 0);
    ~DeleteManagerDialog();
    QString getName();
private:
    Ui::DeleteManagerDialog *ui;
};

#endif // DELETEMANAGERDIALOG_H
