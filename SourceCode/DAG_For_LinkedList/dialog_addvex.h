#ifndef DIALOG_ADDVEX_H
#define DIALOG_ADDVEX_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_AddVex;
}

class Dialog_AddVex : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddVex(QWidget *parent = nullptr);
    ~Dialog_AddVex();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_AddVex *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_ADDVEX_H
