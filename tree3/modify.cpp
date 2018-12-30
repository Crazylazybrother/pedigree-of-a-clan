#include "modify.h"
#include "ui_modify.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Tree *array[100];
extern qint16 i;
extern struct Tree *u;

modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}

Tree *Find4(Tree *b,QString cname)    //查询
{
    Tree *p;
    if(b==NULL)
         return NULL;
    else
          if(b->name==cname)
          {
            return b;
          }
          else
          {
               p=Find4(b->child,cname);
               {
                    if(p!=NULL)
                       return p;
                    else
                       return Find4(b->brother,cname);
               }
          }
}

void modify::on_pushButton_clicked()
{
    QString name = ui->lineEdit_5->text();
    Tree *p;
    p=Find4(u,name);
    p->name=ui->lineEdit_4->text();
    p->sex =ui->lineEdit_3->text();
    p->fed = ui->lineEdit_2->text();
    p->borth = ui->lineEdit->text();
    p->thing = ui->lineEdit_6->text();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
 }
