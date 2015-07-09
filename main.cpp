#include "mainwindow.h"
#include <QApplication>
#include<QtSql>
#include<QMessageBox>
#include"dialog/logindialog.h"



bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bookManagement");
    db.setUserName("root");
    db.setPassword("52544869");
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}

bool login(QString name,QString pw)
{
    QSqlQuery query;
    query.prepare("select * from staff"
                  " where sname=? and password=?");
    query.bindValue(0,name);
    query.bindValue(1,pw);

    query.exec();

    if(query.next())
    {
        return true;
    }
    return false;

}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString staffName;

    if(!createConnection())
    {
        return 1;
    }

    LoginDialog loginDialog;
    bool isQuit = false;
    while(true)
    {
        if(loginDialog.exec())
        {

            if(login(loginDialog.getManagerName(),loginDialog.getPassword()))
            {
                staffName=loginDialog.getManagerName();
                break;
            }
            else
            {
                QMessageBox::warning(0,"密码错误","输入账号或密码错误！");
            }

        }
        else
        {
            isQuit = true;
            break;
        }
    }
    if(isQuit)
    {
        return 0;
    }


    MainWindow w;
    w.setCurStaff(staffName);
    w.show();

    return a.exec();
}
