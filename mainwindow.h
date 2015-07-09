#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlTableModel>

class QLabel;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setCurStaff(const QString& name);
    QString getCurStaff();
private:
    Ui::MainWindow *ui;
    QSqlTableModel* model;
    QString curStaff;


    void createActions();
    void createMenus();

    QMenu* systemMenu;
    QMenu* managerMenu;
    QMenu* bookMenu;
    QMenu* readerMenu;
    QMenu* helpMenu;

    QAction* quitAction;

    QAction* addManagerAction;
    QAction* deleteManagerAction;
    QAction* changeManagerInfoAction;

    QAction* searchAction;
    QAction* returnBookAction;
    QAction* borrowBookAction;
    QAction* addBookAction;
    QAction* deleteBookAction;
    QAction* updateBookAction;

    QAction* searchReaderAction;
    QAction* addReaderAction;
    QAction* deleteReaderAction;
    QAction* updateReaderAction;


    QAction* aboutAction;
    QAction* aboutQtAction;
private slots:
    void about();
    void aboutQt();

    void addManager();
    void deleteManager();
    void changeManagerInfo();

    void search();
    void returnBook();
    void borrowBook();
    void addBook();
    void deleteBook();

    void searchReader();
    void addReader();
    void deleteReader();
    void updateReader();

    void updateBook();

    void updateModel();
    void updateAll();
};

#endif // MAINWINDOW_H
