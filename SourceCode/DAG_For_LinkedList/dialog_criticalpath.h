#ifndef DIALOG_CRITICALPATH_H
#define DIALOG_CRITICALPATH_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_CriticalPath;
}

class Dialog_CriticalPath : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CriticalPath(QWidget *parent = nullptr);
    ~Dialog_CriticalPath();

private:
    Ui::Dialog_CriticalPath *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_CRITICALPATH_H
