#ifndef GRAPH_H
#define GRAPH_H
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <string>

#include <vector>
#include <stack>
#include "Stack.h"


#include <iostream>
using namespace std;





//



struct ListGraph;
typedef struct ListGraph LISTGRAPH;
typedef struct ListGraph* LISTGRAPH_T;

struct VexNode;
typedef struct VexNode VEXNODE;
typedef struct VexNode* VEXNODE_T;

struct Edge_Node;
typedef struct Edge_Node EDGENODE;
typedef struct Edge_Node* EDGENODE_T;

#define MAXNUM_VEX 100

typedef void(*VisitFun)(char*);

const string DEFAULT_NAME_ARR[] = {
  "甲","乙","丙","丁","戊","己","庚","辛","壬","癸",
    "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥",
       "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
            "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
};

/***********对于图的基本构成接口************/

//插入相关

LISTGRAPH_T ListGraph_Init(LISTGRAPH_T LG);
bool ListGraph_InsertOneVex(LISTGRAPH_T LG, string vexname);
bool ListGraph_InsertOneEdge(LISTGRAPH_T LG, string start_vex, string end_vex, int arc_weight);

//辅助接口

int  ListGraph_GetIndexByVexName(LISTGRAPH_T LG, string vexname);
string  ListGraph_GetNameByVexIndex(LISTGRAPH_T LG, int vexindex);
EDGENODE_T ListGraph_GetEdgeHeadNode(LISTGRAPH_T LG, string vexname);

//删除相关

bool ListGraph_DeleteOneVex(LISTGRAPH_T LG, string vexname);
bool ListGraph_DeleteOneArc(LISTGRAPH_T LG, string start_vex, string end_vex);
void ListGraph_DeleteGraph(LISTGRAPH_T LG);

//打印显示相关

void ListGraph_Printf(LISTGRAPH_T LG);
void LIStGraph_PrintfVex(LISTGRAPH_T LG);
void ListGraph_PrintfEdge(LISTGRAPH_T LG);
void ListGraph_PrintfLinkedTable(LISTGRAPH_T LG);



//有向图的拓扑排序

void ListGraph_TopologySort(LISTGRAPH_T LG, string* vexnode);


//显示入度域的函数

void ListGraph_showRudu(LISTGRAPH_T LG, int Rudu[]);


//有向图的关键路径

bool TopologicalOrder(LISTGRAPH_T LG);
bool CriticalPath(LISTGRAPH_T LG, string& VE_VL_str, string& EE_EL_str, string& cp_str);
string* output_EE_EL(EDGENODE edge_node);
string* output_VE_VL(LISTGRAPH_T LG);


/***********图中关于链表部分的接口************/
bool EdgeList_IsEmpty(EDGENODE_T head);
EDGENODE_T EdgeList_InsertToHead(EDGENODE_T head, int index);
void Edge_DeleteAll(LISTGRAPH_T LG, EDGENODE_T head);






//实现文件中具体的结构体

/*结构体定义
名称：ListGraph
组成：当前顶点数，边数，还有一唯的顶点数组
功能说明：是图结构
        顶点数组存放顶点结构体变量（这个数组其实可以看成一个特殊的哈希表，只不过这里是顺序存储顶点）
*/
struct ListGraph
{
    int vex_num;
    int edge_num;
    VEXNODE_T vex_hash[MAXNUM_VEX];
    Stack ReverseTopoOrder;//逆拓扑排序
    vector<int> InDegree;//各个顶点的入度
    vector<int> ve;//各个顶点的最早发生时间向量
    vector<int> vl;//各个顶点的最晚发生时间向量
    vector<Edge_Node*> CP;//关键路径！存弧，即活动
};

/*结构体定义
名称：VexNode
组成：顶点的信息（名称等），表示边的及结构体（也就是第一个节点，边链表的第一个节点）
功能说明：是顶点的结构体
        插入方式采用头插法
*/
struct VexNode
{
    string vex_name;//节点的信息
    EDGENODE_T head;//头插法

};

/*结构体定义
名称：Edge_Node
组成：另一顶点在顶点数组的序号（位置）
功能说明：边的结构体
*/
struct Edge_Node
{
    int vex_index;
    int edge_weight;	//权重
    EDGENODE_T next;
    string start_name;
    string end_name;
    int ee;
    int el;
};





#endif // GRAPH_H
