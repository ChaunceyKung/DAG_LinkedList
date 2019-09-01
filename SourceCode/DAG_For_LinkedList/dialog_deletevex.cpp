#include "dialog_deletevex.h"
#include "ui_dialog_deletevex.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

Dialog_DeleteVex::Dialog_DeleteVex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_DeleteVex)
{
    ui->setupUi(this);

    /*在表单上打印当前已经有的结点信息*/
    /*设置表格数据*/
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(LG_u->vex_num);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"结点编号"<<"结点名称");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个

    for (int i = 0; i < LG_u->vex_num; i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem( QString::fromStdString(LG_u->vex_hash[i]->vex_name)));
    }
}

Dialog_DeleteVex::~Dialog_DeleteVex()
{
    delete ui;
}

void Dialog_DeleteVex::on_buttonBox_accepted()
{
    dialog_failalert = new Dialog_FailAlert(this);
    dialog_successalert =  new Dialog_SuccessAlert(this);

    string deletedVexName = ui->lineEdit->text().toStdString();
    if(false == ListGraph_DeleteOneVex(LG_u, deletedVexName)){
        dialog_failalert->show();
    }else{
        dialog_successalert->show();
    }
}



