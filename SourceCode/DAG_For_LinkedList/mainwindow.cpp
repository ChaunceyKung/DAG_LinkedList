#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在没有初始化之前让其余按键变灰
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*button for "初始化顶点"*/
    dialog_vexinit = new Dialog_VexInit(this);

    dialog_vexinit->show();

    //在初始化之后让其余按键可以点击
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);

}

void MainWindow::on_pushButton_2_clicked()
{
    /*button for "添加顶点"*/
    dialog_addvex = new Dialog_AddVex(this);

    /**/
    dialog_addvex->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    /*button for "删除顶点"*/
    dialog_deletevex = new Dialog_DeleteVex(this);

    dialog_deletevex->show();
}





void MainWindow::on_pushButton_4_clicked()
{
    /*button for "添加边"*/
    dialog_addarc = new Dialog_AddArc(this);

    dialog_addarc->show();
}



void MainWindow::on_pushButton_8_clicked()
{
    /*button for "删除边"*/
    dialog_deletearc = new Dialog_DeleteArc(this);

    dialog_deletearc->show();
}




void MainWindow::on_pushButton_5_clicked()
{
    /*button for "邻接链表显示"*/
    dialog_showadjacentlist = new Dialog_ShowAdjacentList(this);

    dialog_showadjacentlist->show();
}



void MainWindow::on_pushButton_6_clicked()
{
    /*button for "拓扑排序"*/
    dialog_topologysort = new Dialog_TopologySort(this);

    dialog_topologysort->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    /*button for "计算关键路径"*/
    dialog_criticalpath = new Dialog_CriticalPath(this);

    dialog_criticalpath->show();
}
