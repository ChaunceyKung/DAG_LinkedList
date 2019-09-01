#ifndef DIALOG_DELETEVEX_H
#define DIALOG_DELETEVEX_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_DeleteVex;
}

class Dialog_DeleteVex : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DeleteVex(QWidget *parent = nullptr);
    ~Dialog_DeleteVex();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_DeleteVex *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_DELETEVEX_H
