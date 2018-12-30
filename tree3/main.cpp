#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QDebug>
#include<windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login login;
     MainWindow w;
    if(login.exec()==QDialog::Accepted)          // 从登录界面获取一个值和允许登录的值进行比较；
    {
        w.show();                                //  展开主界面；
        return a.exec();                          //把控制权转给QT；
    }
    else
    return 0;                                    //关闭界面；
}
