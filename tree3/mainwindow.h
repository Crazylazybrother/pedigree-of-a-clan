#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include "add.h"
#include "delet.h"
#include "inquire.h"
#include "modify.h"
#include "creat.h"

struct Tree
{
    QString name;
    QString sex;
    QString fed;//配偶
    QString thing;//个人简介
    QString borth;//生日
    qint16 level;//辈分
    struct Tree *child;              //孩子指针
    struct Tree *brother;            //兄弟指针
    struct Tree *parent;             //父亲指针
    int lenth;
};

extern struct Tree *array[100];
extern qint16 i;
extern struct Tree *u;

//全局变量；

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actions();
    void actions_2();
    void actions_3();
    void actions_4();
    void actions_5();
    void actions_6();
    void actions_7();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Add *add;
    modify *modif;
    delet *dele;
    inquire *inquir;
    creat *crea;
};

#endif // MAINWINDOW_H
