#include "dialog_showadjacentlist.h"
#include "ui_dialog_showadjacentlist.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

#include <sstream>

Dialog_ShowAdjacentList::Dialog_ShowAdjacentList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ShowAdjacentList)
{
    ui->setupUi(this);

    string outputStr;
    outputStr = "邻接表显示如下\n";
    for (int i = 0; i < LG_u->vex_num; i++) {
        outputStr += " 顶点 " + LG_u->vex_hash[i]->vex_name + ":";
        EDGENODE_T head = ListGraph_GetEdgeHeadNode(LG_u, LG_u->vex_hash[i]->vex_name);
        EDGENODE_T  p = head;
        while (p != NULL)
        {
            //把int转换为string
            stringstream ss;
            ss << p->edge_weight;
            string s1 = ss.str();

            outputStr += "connected to " + ListGraph_GetNameByVexIndex(LG_u, p->vex_index)
                    + "(" + s1 + "); ";

            p = p->next;
        }
        outputStr += ".\n";
    }

    ui->plainTextEdit->appendPlainText(QString::fromStdString(outputStr));
    //设为只读，用户不可改写
    ui->plainTextEdit->setReadOnly(true);
}

Dialog_ShowAdjacentList::~Dialog_ShowAdjacentList()
{
    delete ui;
}
