#ifndef DIALOG_DELETEARC_H
#define DIALOG_DELETEARC_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_DeleteArc;
}

class Dialog_DeleteArc : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_DeleteArc(QWidget *parent = nullptr);
    ~Dialog_DeleteArc();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_DeleteArc *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_DELETEARC_H
