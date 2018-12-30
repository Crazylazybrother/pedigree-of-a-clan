#ifndef DELET_H
#define DELET_H

#include <QDialog>

namespace Ui {
class delet;
}

class delet : public QDialog
{
    Q_OBJECT

public:
    explicit delet(QWidget *parent = 0);
    ~delet();

private:
    Ui::delet *ui;
};

#endif // DELET_H
