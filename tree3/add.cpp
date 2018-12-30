#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Tree *array[100];
extern qint16 i;
extern struct Tree *u;

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}


Tree *Find1(Tree *b,QString cname)    //查询
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
               p=Find1(b->child,cname);
               {
                    if(p!=NULL)
                       return p;
                    else
                       return Find1(b->brother,cname);
               }
          }
}


void Add::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString parent = ui->lineEdit_4->text();
    QString borth =ui->lineEdit_2->text();
    QString fed = ui->lineEdit_3->text();
    QString sex = ui->lineEdit_5->text();
    QString thing = ui->lineEdit_6->text();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    qint16 zuigaomax=1;
    Tree *p,*q;
    p = Find1(u,parent);
    if(p==NULL)
       {
           QMessageBox::warning(NULL,"警告","尚未建立族谱"); //提示；
       }
     q= new Tree;
     q->name = name;
     q->level = p->level+1;
     q->sex=sex;
     q->fed=fed;
     q->borth=borth;
     q->thing=thing;
     if(p->level+1 > zuigaomax)
         {
             zuigaomax = p->level+1;
         }
         q->child =NULL;
         q->brother=NULL;
         q->parent =p;
            if(p->child==NULL)
                 p->child=q;
             else
                {
                   p=p->child;
                   while(p->brother!=NULL)
                   {
                      p = p->brother;
                   }
                     p->brother = q;
                }
}

void Add::on_pushButton_2_clicked()
{
    this->close();
}
