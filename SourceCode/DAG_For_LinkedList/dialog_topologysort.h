#ifndef DIALOG_TOPOLOGYSORT_H
#define DIALOG_TOPOLOGYSORT_H

#include <QDialog>

#include "dialog_failalert.h"
#include "dialog_successalert.h"

namespace Ui {
class Dialog_TopologySort;
}

class Dialog_TopologySort : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_TopologySort(QWidget *parent = nullptr);
    ~Dialog_TopologySort();

private:
    Ui::Dialog_TopologySort *ui;
    Dialog_FailAlert* dialog_failalert;
    Dialog_SuccessAlert* dialog_successalert;
};

#endif // DIALOG_TOPOLOGYSORT_H
