#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

#include<QLabel>
#include<dialog/addmanagerdialog.h>
#include<dialog/deletemanagerdialog.h>
#include<dialog/changemanagerinfodialog.h>
#include<dialog/searchdialog.h>
#include<dialog/inputbookcarddialog.h>
#include<dialog/inputbookiddialog.h>
#include<dialog/inputbookinformationdialog.h>
#include<dialog/searchreaderdialog.h>
#include<dialog/addreaderdialog.h>
#include<dialog/updatereaderdialog.h>
#include<QSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowTitle("BookManagement");

    createActions();
    createMenus();

    model=new QSqlTableModel(this);
    model->setTable("book");
    updateModel();

    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(this->ui->borrowButton,SIGNAL(clicked()),this,SLOT(borrowBook()));
    connect(this->ui->returnButton,SIGNAL(clicked()),this,SLOT(returnBook()));
    connect(this->ui->searchButton,SIGNAL(clicked()),this,SLOT(search()));
    connect(this->ui->updateButton,SIGNAL(clicked()),this,SLOT(updateAll()));
    connect(this->ui->quitButton,SIGNAL(clicked()),this,SLOT(close()));
}

void MainWindow::createActions()
{
    quitAction=new QAction(tr("退出"),this);
    quitAction->setShortcut(QKeySequence::Quit);
    quitAction->setStatusTip(tr("退出"));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(close()));

    addManagerAction=new QAction(tr("添加管理员账号"),this);
    addManagerAction->setStatusTip(tr("添加管理员账号"));
    connect(addManagerAction,SIGNAL(triggered()),this,SLOT(addManager()));

    deleteManagerAction=new QAction(tr("删除管理员账号"),this);
    deleteManagerAction->setStatusTip(tr("删除管理员账号"));
    connect(deleteManagerAction,SIGNAL(triggered()),this,SLOT(deleteManager()));

    changeManagerInfoAction=new QAction(tr("更改密码"),this);
    changeManagerInfoAction->setStatusTip(tr("更改密码"));
    connect(changeManagerInfoAction,SIGNAL(triggered()),this,SLOT(changeManagerInfo()));

    searchAction=new QAction(tr("查找"),this);
    searchAction->setStatusTip(tr("查找图书"));
    connect(searchAction,SIGNAL(triggered()),this,SLOT(search()));

    returnBookAction=new QAction(tr("还书事务"),this);
    returnBookAction->setStatusTip(tr("还书事务"));
    connect(returnBookAction,SIGNAL(triggered()),this,SLOT(returnBook()));

    borrowBookAction=new QAction(tr("借书事务"),this);
    borrowBookAction->setStatusTip(tr("借书事务"));
    connect(borrowBookAction,SIGNAL(triggered()),this,SLOT(borrowBook()));

    addBookAction=new QAction(tr("添加图书"),this);
    addBookAction->setStatusTip(tr("添加图书"));
    connect(addBookAction,SIGNAL(triggered()),this,SLOT(addBook()));

    deleteBookAction=new QAction(tr("删除图书"),this);
    deleteBookAction->setStatusTip(tr("删除图书"));
    connect(deleteBookAction,SIGNAL(triggered()),this,SLOT(deleteBook()));

    updateBookAction=new QAction(tr("更新图书信息"),this);
    updateBookAction->setStatusTip(tr("更新图书信息"));
    connect(updateBookAction,SIGNAL(triggered()),this,SLOT(updateBook()));

    searchReaderAction=new QAction(tr("查找读者信息"),this);
    searchReaderAction->setStatusTip(tr("查找读者信息"));
    connect(searchReaderAction,SIGNAL(triggered()),this,SLOT(searchReader()));

    addReaderAction=new QAction(tr("添加读者"),this);
    addReaderAction->setStatusTip(tr("添加读者"));
    connect(addReaderAction,SIGNAL(triggered()),this,SLOT(addReader()));

    deleteReaderAction=new QAction(tr("删除读者"),this);
    deleteReaderAction->setStatusTip(tr("删除读者"));
    connect(deleteReaderAction,SIGNAL(triggered()),this,SLOT(deleteReader()));

    updateReaderAction=new QAction(tr("更新读者信息"),this);
    updateReaderAction->setStatusTip(tr("更新读者信息"));
    connect(updateReaderAction,SIGNAL(triggered()),this,SLOT(updateReader()));

    aboutAction=new QAction(tr("关于图书管理系统"),this);
    aboutAction->setStatusTip(tr("关于图书管理系统"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

    aboutQtAction=new QAction(tr("关于Qt"),this);
    aboutQtAction->setStatusTip(tr("关于Qt"));
    connect(aboutQtAction,SIGNAL(triggered()),this,SLOT(aboutQt()));

}

void MainWindow::createMenus()
{
    systemMenu=menuBar()->addMenu(tr("系统(&System)"));
    systemMenu->addAction(quitAction);

    managerMenu=menuBar()->addMenu(tr("管理员(&Manager)"));
    managerMenu->addAction(addManagerAction);
    managerMenu->addAction(deleteManagerAction);
    managerMenu->addAction(changeManagerInfoAction);

    bookMenu=menuBar()->addMenu(tr("图书管理(&Book)"));
    bookMenu->addAction(searchAction);
    bookMenu->addAction(returnBookAction);
    bookMenu->addAction(borrowBookAction);
    bookMenu->addAction(addBookAction);
    bookMenu->addAction(deleteBookAction);
    bookMenu->addAction(updateBookAction);

    readerMenu=menuBar()->addMenu(tr("读者账号管理(&Reader)"));
    readerMenu->addAction(searchReaderAction);
    readerMenu->addAction(addReaderAction);
    readerMenu->addAction(deleteReaderAction);
    readerMenu->addAction(updateReaderAction);


    helpMenu=menuBar()->addMenu(tr("帮助(&Help)"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MainWindow::about()
{
    QMessageBox::about(this,tr("About bookManagement"),
                       tr("<h2>bookManagement</h2>"
                          "<p>just a simpol bookManagement</p>"
                          "<p>write by qwertylevel3</p>"));
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this,tr("about Qt"));
}

void MainWindow::addManager()
{
    AddManagerDialog addManagerDialog;
    if(addManagerDialog.exec())
    {
        QString name=addManagerDialog.getName();
        QString pw=addManagerDialog.getPassword();
        QString sex=addManagerDialog.getSex();
        QString tel=addManagerDialog.getTel();
        QSqlQuery query;

        QDateTime current_date_time = QDateTime::currentDateTime();
        QString id = current_date_time.toString("yyMMddhhmmss");


        query.prepare("insert into staff values(?,?,?,?,?)");
        query.bindValue(0,id);
        query.bindValue(1,pw);
        query.bindValue(2,name);
        query.bindValue(3,sex);
        query.bindValue(4,tel);

        query.exec();
    }
}

void MainWindow::deleteManager()
{
    if(curStaff!="root")
    {
        QMessageBox::critical(0,QObject::tr("Database Error"),
                              QObject::tr("you are not root"));
        return ;
    }

    DeleteManagerDialog dialog;
    if(dialog.exec())
    {
        QSqlQuery query;
        QString name=dialog.getName();

        if(name=="root")
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("you can not delete root"));
            return;
        }

        query.prepare("select * from staff where sname=?");
        query.bindValue(0,name);

        query.exec();

        if(query.next())
        {
            query.prepare("delete from staff where sname=?");
            query.bindValue(0,name);
            query.exec();
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("can not find this staff name"));
        }
    }
}

void MainWindow::changeManagerInfo()
{
    ChangeManagerInfoDialog dialog;
    if(dialog.exec())
    {
        QString oldPw=dialog.getOldPassword();
        QString newPw=dialog.getNewPassword();

        QSqlQuery query;
        query.prepare("select * from staff where sname=? and password=?");
        query.bindValue(0,curStaff);
        query.bindValue(1,oldPw);
        query.exec();

        if(query.next())
        {
            query.prepare("update staff set password=? where sname=? and password=?");
            query.bindValue(0,newPw);
            query.bindValue(1,curStaff);
            query.bindValue(2,oldPw);
            query.exec();
            return ;
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("账号或密码错误"));
        }
    }
}

void MainWindow::search()
{
    SearchDialog dialog;
    if(dialog.exec())
    {
        QString ISBN=dialog.getBookISBN();
        QString bookName=dialog.getBookName();
        QString publisher=dialog.getPublisher();
        QString translater=dialog.getTranslater();
        QString writer=dialog.getWriter();
        QString bookTypename=dialog.getTypename();

        model->setTable("book");
        QString queryLine;
        if(ISBN!="")
        {
            queryLine+="ISBN='"+ISBN+"'";
        }
        if(bookName!="")
        {
            if(queryLine!="")
            {
                queryLine+=" and ";
            }
            queryLine+="bname='"+bookName+"'";
        }
        if(publisher!="")
        {
            if(queryLine!="")
            {
                queryLine+=" and ";
            }
            queryLine+="publisher='"+publisher+"'";
        }
        if(translater!="")
        {
            if(queryLine!="")
            {
                queryLine+=" and ";
            }
            queryLine+="translater='"+translater+"'";
        }
        if(writer!="")
        {
            if(queryLine!="")
            {
                queryLine+=" and ";
            }
            queryLine+="writer='"+writer+"'";
        }
        if(bookTypename!="")
        {
            if(queryLine!="")
            {
                queryLine+=" and ";
            }
            queryLine+="typename='"+bookTypename+"'";
        }
        model->setFilter(queryLine);
        updateModel();
    }
}

void MainWindow::borrowBook()
{
    InputBookCardDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getCard();
        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            InputBookIDDialog bookDialog;
            if(bookDialog.exec())
            {
                QString bookID=bookDialog.getBookID();
                query.prepare("select * from book where ISBN=? and number>0");
                query.bindValue(0,bookID);
                query.exec();

                if(query.next())
                {
                    query.prepare("select * from borrow where ISBN=? and rid=?");
                    query.bindValue(0,bookID);
                    query.bindValue(1,rid);
                    query.exec();
                    if(query.next())
                    {
                        QMessageBox::critical(0,QObject::tr("Database Error"),
                                              QObject::tr("不得重复借阅"));
                        return;
                    }

                    query.prepare("update book set number=number-1 where ISBN=?");
                    query.bindValue(0,bookID);
                    query.exec();

                    QDateTime current_date_time = QDateTime::currentDateTime();
                    QString bid = current_date_time.toString("yyMMddhhmmss");

                    query.prepare("insert into borrow values("
                                  "?,?,?,?,?)");
                    query.bindValue(0,bid);
                    query.bindValue(1,bookID);
                    query.bindValue(2,rid);
                    query.bindValue(3,current_date_time.toString("yyyy-MM-dd"));
                    query.bindValue(4,current_date_time.addMonths(1).toString("yyyy-MM-dd"));
                    query.exec();
                }
                else
                {
                    QMessageBox::critical(0,QObject::tr("Database Error"),
                                          QObject::tr("该图书无法借出"));
                }
            }
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("改学生账号不存在"));
        }
    }
    updateModel();
}

void MainWindow::returnBook()
{
    InputBookCardDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getCard();
        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            bool flag=true;
            while(flag)
            {
                InputBookIDDialog bookDialog;
                if(bookDialog.exec())
                {
                    QString bookID=bookDialog.getBookID();
                    query.prepare("select * from book where ISBN=?");
                    query.bindValue(0,bookID);
                    query.exec();

                    if(query.next())
                    {
                        flag=false;

                        query.prepare("select * from borrow where ISBN=? and rid=?");
                        query.bindValue(0,bookID);
                        query.bindValue(1,rid);
                        query.exec();

                        if(query.next())
                        {
                            QDate backdate=query.value(4).toDate();
                            QDate currdate=QDate::currentDate();

                            if(currdate>backdate)
                            {
                                query.prepare("update reader set keepmoney=keepmoney+10 where rid=?");
                                query.bindValue(0,rid);
                                query.exec();
                            }

                            query.prepare("update book set number=number+1 where ISBN=?");
                            query.bindValue(0,bookID);
                            query.exec();

                            query.prepare("delete from borrow where ISBN=? and rid=?");
                            query.bindValue(0,bookID);
                            query.bindValue(1,rid);
                            query.exec();
                        }
                        else
                        {
                            QMessageBox::critical(0,QObject::tr("Database Error"),
                                                  QObject::tr("错误"));
                        }
                    }
                    else
                    {
                        QMessageBox::critical(0,QObject::tr("Database Error"),
                                              QObject::tr("ISBN错误"));
                    }

                }
                else
                {
                    flag=false;
                }
            }
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("改学生账号不存在"));
        }
    }
    updateModel();
}

void MainWindow::addBook()
{
    InputBookInformationDialog dialog;
    if(dialog.exec())
    {
        QString ISBN=dialog.getISBN();
        QString bname=dialog.getBookName();
        int number=dialog.getNumber().toInt();
        double price=dialog.getPrice().toDouble();
        QString publisher=dialog.getTranslater();
        QDate date=dialog.getDate();
        QString translater=dialog.getTranslater();
        QString writer=dialog.getWriter();
        QString bookTypename=dialog.getTypename();


        QSqlQuery query;
        query.prepare("select * from book where ISBN=?");
        query.bindValue(0,ISBN);
        query.exec();
        if(query.next())
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("该图书已存在"));
            return;
        }

        query.prepare("insert into book values(?,?,?,?,?,?,?,?,?)");

        query.bindValue(0,ISBN);
        query.bindValue(1,bname);
        query.bindValue(2,number);
        query.bindValue(3,price);
        query.bindValue(4,publisher);
        query.bindValue(5,date);
        query.bindValue(6,translater);
        query.bindValue(7,writer);
        query.bindValue(8,bookTypename);

        query.exec();
    }
    updateModel();
}

void MainWindow::deleteBook()
{
    InputBookIDDialog dialog;
    if(dialog.exec())
    {
        QString ISBN=dialog.getBookID();

        QSqlQuery query;

        query.prepare("select * from book where ISBN=?");
        query.bindValue(0,ISBN);

        query.exec();

        if(query.next())
        {
            query.prepare("select * from borrower where ISBN=?");
            query.bindValue(0,ISBN);
            query.exec();
            if(query.next())
            {
                QMessageBox::critical(0,QObject::tr("Database Error"),
                                      QObject::tr("仍有该图书事务未处理，拒绝删除"));
                return;
            }

            query.prepare("delete from book where ISBN=?");
            query.bindValue(0,ISBN);
            query.exec();
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("该图书不存在"));
        }
    }
    updateModel();
}

void MainWindow::searchReader()
{
    InputBookCardDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getCard();
        QString rname;
        QString rsex;
        QString rtel;
        double keepmoney;

        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            rname=query.value(1).toString();
            rsex=query.value(2).toString();
            rtel=query.value(3).toString();
            keepmoney=query.value(4).toDouble();

            SearchReaderDialog searchDialog;
            searchDialog.setID(rid);
            searchDialog.setReaderName(rname);
            searchDialog.setSex(rsex);
            searchDialog.setTel(rtel);
            searchDialog.setMoney(keepmoney);

            searchDialog.exec();
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("改读者账号不存在"));
        }

    }
}

void MainWindow::addReader()
{
    AddReaderDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getRid();
        QString rname=dialog.getReaderName();
        QString rsex=dialog.getSex();
        QString rtel=dialog.getTel();

        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("该账号已存在"));
        }
        else
        {
            query.prepare("insert into reader values(?,?,?,?,?)");
            query.bindValue(0,rid);
            query.bindValue(1,rname);
            query.bindValue(2,rsex);
            query.bindValue(3,rtel);
            query.bindValue(4,0);
            query.exec();

        }
    }
}

void MainWindow::deleteReader()
{
    InputBookCardDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getCard();

        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            query.prepare("select * from borrower where rid=?");
            query.bindValue(0,rid);
            query.exec();
            if(query.next())
            {
                QMessageBox::critical(0,QObject::tr("Database Error"),
                                      QObject::tr("仍有该读者事务未处理，拒绝删除"));
                return;
            }

            query.prepare("delete from reader where rid=?");
            query.bindValue(0,rid);
            query.exec();
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("改读者账号不存在"));
        }
    }
}

void MainWindow::updateReader()
{
    InputBookCardDialog dialog;
    if(dialog.exec())
    {
        QString rid=dialog.getCard();
        QString rname;
        QString rsex;
        QString rtel;
        double keepmoney;

        QSqlQuery query;
        query.prepare("select * from reader where rid=?");
        query.bindValue(0,rid);
        query.exec();

        if(query.next())
        {
            rname=query.value(1).toString();
            rsex=query.value(2).toString();
            rtel=query.value(3).toString();
            keepmoney=query.value(4).toDouble();

            UpdateReaderDialog updateReaderDialog;
            updateReaderDialog.setID(rid);
            updateReaderDialog.setReaderName(rname);
            updateReaderDialog.setSex(rsex);
            updateReaderDialog.setTel(rtel);
            updateReaderDialog.setkeepmoney(keepmoney);
            if(updateReaderDialog.exec())
            {
                rname=updateReaderDialog.getReaderName();
                rsex=updateReaderDialog.getSex();
                rtel=updateReaderDialog.getTel();
                keepmoney=updateReaderDialog.getKeepmoney();


                query.prepare("update reader set rname=?,"
                              "rsex=?,"
                              "rtel=?,"
                              "keepmoney=? where rid=?");
                query.bindValue(0,rname);
                query.bindValue(1,rsex);
                query.bindValue(2,rtel);
                query.bindValue(3,keepmoney);
                query.bindValue(4,rid);

                query.exec();
            }
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("改读者账号不存在"));
        }
    }
}

void MainWindow::updateBook()
{
    InputBookIDDialog dialog;
    if(dialog.exec())
    {
        QString ISBN=dialog.getBookID();

        QSqlQuery query;

        query.prepare("select * from book where ISBN=?");
        query.bindValue(0,ISBN);

        query.exec();

        if(query.next())
        {
            QString ISBN=query.value(0).toString();
            QString bname=query.value(1).toString();
            int number=query.value(2).toInt();
            double price=query.value(3).toDouble();
            QString publisher=query.value(4).toString();
            QDate date=query.value(5).toDate();
            QString translater=query.value(6).toString();
            QString writer=query.value(7).toString();
            QString bookTypename=query.value(8).toString();


            InputBookInformationDialog bookInfodialog;
            bookInfodialog.setISBN(ISBN);
            bookInfodialog.setBookName(bname);
            bookInfodialog.setNumber(number);
            bookInfodialog.setPrice(price);
            bookInfodialog.setPublisher(publisher);
            bookInfodialog.setDate(date);
            bookInfodialog.setTranslater(translater);
            bookInfodialog.setWriter(writer);
            bookInfodialog.setTypename(bookTypename);

            bookInfodialog.setISBNEditable(false);

            if(bookInfodialog.exec())
            {
                bname=bookInfodialog.getBookName();
                number=bookInfodialog.getNumber().toInt();
                price=bookInfodialog.getPrice().toDouble();
                publisher=bookInfodialog.getTranslater();
                date=bookInfodialog.getDate();
                translater=bookInfodialog.getTranslater();
                writer=bookInfodialog.getWriter();
                bookTypename=bookInfodialog.getTypename();


                query.prepare("update book set bname=?,"
                              "number=?,"
                              "price=?,"
                              "publisher=?,"
                              "date=?,"
                              "translater=?,"
                              "writer=?,"
                              "typename=? where ISBN=?");


                query.bindValue(0,bname);
                query.bindValue(1,number);
                query.bindValue(2,price);
                query.bindValue(3,publisher);
                query.bindValue(4,date);
                query.bindValue(5,translater);
                query.bindValue(6,writer);
                query.bindValue(7,bookTypename);
                query.bindValue(8,ISBN);

                query.exec();
            }
        }
        else
        {
            QMessageBox::critical(0,QObject::tr("Database Error"),
                                  QObject::tr("该图书不存在"));
        }
    }
    updateModel();
}

void MainWindow::updateModel()
{
    model->setSort(0,Qt::AscendingOrder);
    model->setHeaderData(1,Qt::Horizontal,tr("书名"));
    model->setHeaderData(2,Qt::Horizontal,tr("剩余数量"));
    model->setHeaderData(3,Qt::Horizontal,tr("价格"));
    model->setHeaderData(4,Qt::Horizontal,tr("出版社"));
    model->setHeaderData(5,Qt::Horizontal,tr("出版日期"));
    model->setHeaderData(6,Qt::Horizontal,tr("译者"));
    model->setHeaderData(7,Qt::Horizontal,tr("作者"));
    model->setHeaderData(8,Qt::Horizontal,tr("图书类别"));
    model->select();
}

void MainWindow::updateAll()
{
    model->setTable("book");
    model->setFilter("");
    updateModel();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurStaff(const QString &name)
{
    curStaff=name;
}

QString MainWindow::getCurStaff()
{
    return curStaff;
}
