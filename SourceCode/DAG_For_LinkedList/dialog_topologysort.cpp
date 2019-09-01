#include "dialog_topologysort.h"
#include "ui_dialog_topologysort.h"

#include "graph.h"
extern LISTGRAPH_T LG_u;

#include <sstream>

#include <stdio.h>
#include <malloc.h>


struct QueueNode_s
{
        int vex_index;
        struct QueueNode_s* next;
};
typedef struct QueueNode_s QUEUENODE_s;
typedef struct QueueNode_s* QUEUENODE_T_s;

struct ListQueue_s
{
        struct QueueNode_s* front;
        struct QueueNode_s* rear;
};
typedef struct ListQueue_s LISTQUEUE_s;
typedef struct ListQueue_s* LISTQUEUE_T_s;

LISTQUEUE_T_s ListQueue_Init_s(LISTQUEUE_T_s LQ)
{
        LQ = (LISTQUEUE_T_s)malloc(sizeof(LISTQUEUE_s));
        if (LQ == NULL)
                return NULL;
        LQ->front = LQ->rear = (QUEUENODE_T_s)malloc(sizeof(QUEUENODE_s));
        if (LQ->front == NULL)
        {
                free(LQ);
                return NULL;
        }
        LQ->front->next = LQ->rear->next = NULL;
        return LQ;
}
bool ListQueue_IsEmpty_s(LISTQUEUE_T_s LQ)
{
        if (LQ != NULL)
                return LQ->front->next == NULL ? true : false;
        else
                return false;
}
bool ListQueue_EnQueue_s(LISTQUEUE_T_s LQ, int data)
{
        if (LQ == NULL)
                return false;
        QUEUENODE_T_s newnode = (QUEUENODE_T_s)malloc(sizeof(QUEUENODE_s));
        if (newnode == NULL)
                return false;
        newnode->next = NULL;
        newnode->vex_index = data;

        LQ->rear->next = newnode;
        LQ->rear = newnode;
        return true;
}
bool ListQueue_DeQueue_s(LISTQUEUE_T_s LQ, int* data)
{
        if (LQ == NULL || ListQueue_IsEmpty_s(LQ))
                return false;

        *data = LQ->front->next->vex_index;
        QUEUENODE_T_s tmp = LQ->front->next;
        LQ->front->next = tmp->next;

        free(tmp);
        tmp = NULL;
        if (ListQueue_IsEmpty_s(LQ))
        {
                LQ->rear = LQ->front;
        }
        return true;
}










Dialog_TopologySort::Dialog_TopologySort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_TopologySort)
{
    ui->setupUi(this);
    string vexnode[LG_u->vex_num];
    string outputStr;
    //outputStr = "入度域变化情况如下\n";

    /************************/
    /**辅助队列，压入入度为0的顶点*/
    LISTQUEUE_T_s  queue = NULL;
    queue =	ListQueue_Init_s(queue);

    int Rudu[MAXNUM_VEX] = { 0 };
    /**统计各个顶点的入度正确*/
    for (int i = 0; i < LG_u->vex_num; i++)
    {
        EDGENODE_T head = LG_u->vex_hash[i]->head;

        while (head != NULL)
        {
            Rudu[head->vex_index]++;
            head = head->next;
        }
    }
    outputStr = "完成初步统计后\n";
    outputStr += "当下入度域情况\n";
    for (int i = 0; i < LG_u->vex_num; i++) {
        stringstream ss;
        ss << Rudu[i];
        string s1 = ss.str();

        outputStr += LG_u->vex_hash[i]->vex_name + ":" + s1 + "; ";

        if ((i+1) % 5 == 0)
            outputStr += "\n";
    }

    int index = 0;
        int res_index = 0;
        char* result[MAXNUM_VEX] = { 0 };

        for (int i = 0; i < LG_u->vex_num; i++)
        {
            if (Rudu[i] == 0)
            {
                ListQueue_EnQueue_s(queue, i);
                while (!ListQueue_IsEmpty_s(queue))
                {

                    ListQueue_DeQueue_s(queue, &res_index);
                    vexnode[index++] = LG_u->vex_hash[res_index]->vex_name;
                    EDGENODE_T head = LG_u->vex_hash[res_index]->head;

                    while (head != NULL)
                    {
                        Rudu[head->vex_index]--;/**所有这个顶点相关的点入度都-1*/

                        if (Rudu[head->vex_index] != 0)
                        {
                            head = head->next;
                        }
                        else
                        {
                            ListQueue_EnQueue_s(queue, head->vex_index);
                        }
                    }

                    outputStr = "新一轮操作后，\n";
                    outputStr += "当下入度域情况\n";
                    for (int i = 0; i < LG_u->vex_num; i++) {
                        stringstream ss;
                        ss << Rudu[i];
                        string s1 = ss.str();

                        outputStr += LG_u->vex_hash[i]->vex_name + ":" + s1 + "; ";

                        if ((i+1) % 5 == 0)
                            outputStr += "\n";
                    }
                }
            }
        }
    /************************/

    ui->plainTextEdit->appendPlainText(QString::fromStdString(outputStr));
    //设为只读，用户不可改写
    ui->plainTextEdit->setReadOnly(true);


    /*展示排序结果*/
    string sortedResult;
    for (int j = 0; j < LG_u->vex_num; j++) {
        //cout << vexnode[j] << "->";
        sortedResult += vexnode[j] + "->";
        if ((j + 1) % 5 == 0){
            //cout << endl;
            sortedResult += "\n";
        }
    }

    ui->plainTextEdit_2->appendPlainText(QString::fromStdString(sortedResult));
    //设为只读，用户不可改写
    ui->plainTextEdit_2->setReadOnly(true);



}

Dialog_TopologySort::~Dialog_TopologySort()
{
    delete ui;
}
