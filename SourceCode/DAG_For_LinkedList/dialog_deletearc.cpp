#include "dialog_deletearc.h"
#include "ui_dialog_deletearc.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

Dialog_DeleteArc::Dialog_DeleteArc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_DeleteArc)
{
    ui->setupUi(this);

    /*在表单上打印当前已经有的结点信息*/
    /*设置表格数据*/
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(LG_u->edge_num);   //总边数为row数
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"边序"<<"起点名称"<<"终点名称");

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个



    int edge_cnt = 0;
    for (int i = 0; i < LG_u->vex_num; i++)
    {
        EDGENODE_T head = ListGraph_GetEdgeHeadNode(LG_u, LG_u->vex_hash[i]->vex_name);
        EDGENODE_T  p = head;
        while (p != NULL)
        {
            //col1:编号
            ui->tableWidget->setItem(edge_cnt, 0, new QTableWidgetItem(QString::number(edge_cnt)));

            //col2:起点名
            ui->tableWidget->setItem(edge_cnt,1,new QTableWidgetItem( QString::fromStdString(LG_u->vex_hash[i]->vex_name)));

            //col3:终点名
            ui->tableWidget->setItem(edge_cnt,2,new QTableWidgetItem( QString::fromStdString(ListGraph_GetNameByVexIndex(LG_u, p->vex_index))));

            p = p->next;
            edge_cnt++;
        }
    }

    /*动态设置combobox中的数据内容*/
    for(int i = 0; i < LG_u->vex_num ; i++){
        ui->comboBox->addItem(QString::fromStdString(LG_u->vex_hash[i]->vex_name));
        ui->comboBox_2->addItem(QString::fromStdString(LG_u->vex_hash[i]->vex_name));
    }

}

Dialog_DeleteArc::~Dialog_DeleteArc()
{
    delete ui;
}

void Dialog_DeleteArc::on_buttonBox_accepted()
{
    dialog_failalert = new Dialog_FailAlert(this);
    dialog_successalert = new Dialog_SuccessAlert(this);

    /*所选择的边*/
    string startStr = ui->comboBox->currentText().toStdString();
    string endStr = ui->comboBox_2->currentText().toStdString();

    if(false == ListGraph_DeleteOneArc(LG_u, startStr, endStr)){
        /*删除失败*/
        dialog_failalert->show();
        return;
    }else{
        /*删除成功*/
        dialog_successalert->show();
        return;
    }
}
