#ifndef DIALOG_ADDARC_H
#define DIALOG_ADDARC_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_AddArc;
}

class Dialog_AddArc : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_AddArc(QWidget *parent = nullptr);
    ~Dialog_AddArc();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_AddArc *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_ADDARC_H
