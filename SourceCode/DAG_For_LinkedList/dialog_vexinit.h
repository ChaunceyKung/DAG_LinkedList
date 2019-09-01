#ifndef DIALOG_VEXINIT_H
#define DIALOG_VEXINIT_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_VexInit;
}

class Dialog_VexInit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_VexInit(QWidget *parent = nullptr);
    ~Dialog_VexInit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_VexInit *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_VEXINIT_H
