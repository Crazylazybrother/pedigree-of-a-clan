#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDialog>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_pushButton_2_clicked()
{
    QDialog::reject();
}



void login::on_pushButton_clicked()
{
    QString stru=ui->lineEdit_2->text();
    QString strp=ui->lineEdit->text();

    if(stru==NULL)
         QMessageBox::warning(NULL,"警告","账号不能为空");
    else if(strp==NULL)
         QMessageBox::warning(NULL,"warning","密码不能为空");
    if(stru=="123456"&&strp=="123456")
    {
        QDialog::accept();          //返回一个值在main函数里进行比较；
    }
     else
        {
         QMessageBox::critical(NULL,"fail","登陆失败");
         ui->lineEdit_2->clear();
         ui->lineEdit->clear();
         }
}
