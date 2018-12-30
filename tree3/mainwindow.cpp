#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QAction>
#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QMessageBox>
#include <QDialog>

struct Tree *array[100];
qint16 i;
struct Tree *u;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action,SIGNAL(triggered()),this,SLOT(actions()));
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(actions_2()));
    connect(ui->action_3,SIGNAL(triggered()),this,SLOT(actions_3()));
    connect(ui->action_4,SIGNAL(triggered()),this,SLOT(actions_4()));
    connect(ui->action_5,SIGNAL(triggered()),this,SLOT(actions_5()));
    connect(ui->action_6,SIGNAL(triggered()),this,SLOT(actions_6()));
    connect(ui->action_7,SIGNAL(triggered()),this,SLOT(actions_7()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actions()               //调用add函数；
{
    add = new Add(this);
    add->show();
}

void MainWindow::actions_2()              //调用修改函数
{
    modif = new modify(this);
    modif->show();
}

void MainWindow::actions_3()            //调用删除函数
{
    dele = new delet(this);
    dele->show();
}

void MainWindow::actions_4()          //调用查找函数
{
    inquir = new inquire(this);
    inquir ->show();
}

Tree *Find(Tree *b,QString cname)    //查询
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
               p=Find(b->child,cname);
               {
                    if(p!=NULL)
                       return p;
                    else
                       return Find(b->brother,cname);
               }
          }
}

void fTraversal(Tree *b)   //文件遍历
{
    if(b!=NULL)
    {
        array[i]=b;
        i++;

        if(b->child!=NULL || b->brother!=NULL )
        {
            fTraversal(b->child);
            fTraversal(b->brother);
        }
    }
}

void MainWindow::actions_5()         //保存入文件；
{
    QFile file("fmily.dat");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    fTraversal(u);
    for(int j=0;j<i;j++)
         {
            QString a;
            if(j==0)
            {
                QString a="0";
                out<<array[j]->name;  out<<a;  out<<array[j]->sex;
                out<<array[j]->fed;  out<<array[j]->borth;  out<<array[j]->thing;
            }
            else
            {
                out<<array[j]->name ;out<<array[j]->parent->name; out<<array[j]->sex;
                out<<array[j]->fed; out<<array[j]->borth; out<<array[j]->thing;
            }


         }
    i=0;
    file.close();
}

Tree *fCreat(Tree *t,QString name,QString sex,QString fed,QString borth,QString thing)    //文件输入专用；
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

void fcreat(Tree * &u,QString name,QString sex,QString fed,QString borth,QString thing)   //文件专用；
{
    u=fCreat(u,name,sex,fed,borth,thing);

}

void fAdd(Tree *b,QString name,QString parent,QString sex,QString fed,QString thing,QString borth)
{
   int zuigaomax=1;
    Tree *p,*q;
    p = Find(b,parent);
    if(p==NULL)
        {
         QMessageBox::warning(NULL,"警告","尚未建立族谱");
          return;
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


void MainWindow::actions_6()         //载入
{
    QFile file("fmily.dat");
    if(!file.open(QIODevice::ReadOnly))               //判断文件是否为空；
    {
        QMessageBox::warning(NULL,"提示","文件为空");
    }
    QDataStream in(&file);
    while(!in.atEnd())
    {
        QString name;   QString parent;  QString sex;
        QString fed;    QString thing;   QString borth;
        in>>name;  in>>parent;  in>>sex;
        in>>fed;   in>>borth;   in>>thing;

           if(parent =="0")
               {
                  fcreat(u,name,sex,fed,borth,thing);
               }
            else
                {
                    fAdd(u,name,parent,sex,fed,thing,borth);
                }
    }
    file.close();
}

void MainWindow::actions_7()
{
    crea =new creat(this);
    crea->show();
}

void MainWindow::on_pushButton_clicked()
{
    fTraversal(u);
    ui->textBrowser->clear();
    for(qint16 j=0;j<i;j++)
    {
        QString a;
        if(j==0)
        {
            a=array[j]->name + "\t" + "0" + "\t"  + array[j]->sex + "\t" +array[j]->fed+"\t"+array[j]->borth+"\t"+ array[j]->thing;
        }
        else
        {
            a=array[j]->name + "\t"+ array[j]->parent->name+ "\t"  + array[j]->sex + "\t" +array[j]->fed+"\t"+array[j]->borth+"\t"+ array[j]->thing;
        }
        ui->textBrowser->append(a);
     }
    i=0;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
