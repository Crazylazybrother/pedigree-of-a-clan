#include "delet.h"
#include "ui_delet.h"

delet::delet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delet)
{
    ui->setupUi(this);
}

delet::~delet()
{
    delete ui;
}
