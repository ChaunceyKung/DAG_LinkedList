#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog_addarc.h"
#include "dialog_addvex.h"
#include "dialog_criticalpath.h"
#include "dialog_deletearc.h"
#include "dialog_deletevex.h"
#include "dialog_showadjacentlist.h"
#include "dialog_topologysort.h"
#include "dialog_vexinit.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_AddArc* dialog_addarc;
    Dialog_AddVex* dialog_addvex;
    Dialog_CriticalPath* dialog_criticalpath;
    Dialog_DeleteArc* dialog_deletearc;
    Dialog_DeleteVex* dialog_deletevex;
    Dialog_ShowAdjacentList* dialog_showadjacentlist;
    Dialog_TopologySort* dialog_topologysort;
    Dialog_VexInit* dialog_vexinit;
};

#endif // MAINWINDOW_H
