#include "inquire.h"
#include "ui_inquire.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Tree *array[100];
extern qint16 i;
extern struct Tree *u;

inquire::inquire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inquire)
{
    ui->setupUi(this);
}

inquire::~inquire()
{
    delete ui;
}

Tree *Find3(Tree *b,QString cname)    //查询
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
               p=Find3(b->child,cname);
               {
                    if(p!=NULL)
                       return p;
                    else
                       return Find3(b->brother,cname);
               }
          }
}

void inquire::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    Tree *o =Find3(u,name);
         QString s="0";
        if(o->parent==NULL)
            ui->textBrowser->append(s);
         else
            ui->textBrowser->append(o->parent->name);

        ui->textBrowser_2->append(QString::number(o->level, 10));

        ui->textBrowser_3->append(o->sex);
        ui->textBrowser_4->append(o->fed);
        ui->textBrowser_5->append(o->borth);
        if(o->brother==NULL)
            ui->textBrowser_6->append(s);
        else
            ui->textBrowser_6->append(o->brother->name);
        if(o->child==NULL)
            ui->textBrowser_7->append(s);
        else
            ui->textBrowser_7->append(o->child->name);
        ui->textBrowser_8->append(o->thing);

}

void inquire::on_pushButton_2_clicked()
{
    this->close();
}
