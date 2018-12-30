#include "creat.h"
#include "ui_creat.h"
#include <QMessageBox>
#include <QDialog>
#include "mainwindow.h"

extern struct Tree *array[100];
extern qint16 i;
extern struct Tree *u;

creat::creat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creat)
{
    ui->setupUi(this);
}

creat::~creat()
{
    delete ui;
}

Tree *fCreat1(Tree *t,QString name,QString sex,QString fed,QString borth,QString thing)    //文件输入专用；
{
    Tree *p;
    p = new Tree;
    p->name=name;
    p->brother=NULL;                      //规定祖先只有一个人，即指向兄弟的指针为空，指向父亲节点的指针为空
    p->child=NULL;                        //暂且将孩子指针赋值为空
    p->parent=NULL;
    p->level=1;
    p->sex=sex;
    p->fed=fed;
    p->borth=borth;
    p->thing=thing;

    t=p;
    return t;
}

void creat::on_pushButton_clicked()
{
     QString name=ui->lineEdit->text();
     QString sex = ui->lineEdit_5->text();
     QString fed =ui->lineEdit_2->text();
     QString borth = ui->lineEdit_3->text();
     QString thing = ui->lineEdit_4->text();

     u=fCreat1(u,name,sex,fed,borth,thing);

     ui->lineEdit->clear();
     ui->lineEdit_2->clear();
     ui->lineEdit_3->clear();
     ui->lineEdit_4->clear();
     ui->lineEdit_5->clear();

     this->close();
}
