#ifndef CREAT_H
#define CREAT_H

#include <QDialog>

namespace Ui {
class creat;
}

class creat : public QDialog
{
    Q_OBJECT

public:
    explicit creat(QWidget *parent = 0);
    ~creat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::creat *ui;
};

#endif // CREAT_H
