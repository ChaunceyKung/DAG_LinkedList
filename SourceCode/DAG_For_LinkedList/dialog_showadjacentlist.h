#ifndef DIALOG_SHOWADJACENTLIST_H
#define DIALOG_SHOWADJACENTLIST_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_ShowAdjacentList;
}

class Dialog_ShowAdjacentList : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ShowAdjacentList(QWidget *parent = nullptr);
    ~Dialog_ShowAdjacentList();

private slots:


private:
    Ui::Dialog_ShowAdjacentList *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_SHOWADJACENTLIST_H
