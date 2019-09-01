#include "dialog_addarc.h"
#include "ui_dialog_addarc.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

Dialog_AddArc::Dialog_AddArc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_AddArc)
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

Dialog_AddArc::~Dialog_AddArc()
{
    delete ui;
}

void Dialog_AddArc::on_buttonBox_accepted()
{
    dialog_failalert = new Dialog_FailAlert(this);
    dialog_successalert = new Dialog_SuccessAlert(this);

    /*所添加边的权值*/
    int weightValue = ui->lineEdit_3->text().toInt();

    /*所选择的边*/
    int startIndex = ui->comboBox->currentIndex();
    int endIndex = ui->comboBox_2->currentIndex();

    if(startIndex == endIndex || weightValue <= 0){
        /*两个顶点相同，失败*/
        dialog_failalert->show();
        return;
    }

    if(false == ListGraph_InsertOneEdge(LG_u,
                                        LG_u->vex_hash[startIndex]->vex_name,
                                        LG_u->vex_hash[endIndex]->vex_name,
                                        weightValue)){
        /*插入边失败*/
        dialog_failalert->show();
        return;
    }else{
        dialog_successalert->show();
        return;
    }
}
