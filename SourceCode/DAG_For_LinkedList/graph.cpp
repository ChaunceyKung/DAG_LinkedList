#include "Graph.h"
#include "Queue.h"

#include <sstream>

/*函数定义
名称：
传入参数：
返回类型：
功能说明：
*/

/*函数定义
名称：ListGraph_Init
传入参数：LISTGRAPH_T待初始化邻接链表
返回类型：LISTGRAPH_T完成初始化之后的邻接链表
功能说明：调用了new运算符与memset函数
        采用new申请空间
            注意用NULL判断申请是否成功
        采用memset完成申请到的空间的初始化
*/
LISTGRAPH_T ListGraph_Init(LISTGRAPH_T LG)
{
    LG = new LISTGRAPH;

    if (LG == NULL)
        return NULL;
    memset(LG, 0, sizeof(LISTGRAPH));

    return LG;
}


/*函数定义
名称：ListGraph_InsertOneVex
传入参数：LISTGRAPH_T邻接链表，string新加入的结点名（结点信息）
返回类型：bool:插入成功与否
功能说明：插入一个新的结点/顶点，
        失败可能有3大原因
        初始化操作包括：
            （1）对新生成的空间以Memset置0
            （2）对新空间写数据，注意头插法head处置为0
            （3）对邻接链表中的左侧（hash）数组进行添加
*/
bool ListGraph_InsertOneVex(LISTGRAPH_T LG, string vexname)
{
    VEXNODE_T newvnode = NULL;
    int m = LG->vex_num + 1;
    if (m == MAXNUM_VEX)
    {
        cout << "error1" << endl;
        return false;
    }
    m = ListGraph_GetIndexByVexName(LG, vexname);
    if (m != -1)
    {
        cout << "error2" << endl;
        return false;
    }
    //等于-1说明可以加入顶点
    newvnode = new VEXNODE;
    if (newvnode == NULL)
    {
        cout << "error3" << endl;
        return false;
    }
    //初始化的相关操作
    //memset(newvnode, 0, sizeof(VEXNODE));
    newvnode->vex_name = vexname;
    newvnode->head = NULL;	//跟弧的插入相关，此处置为NULL

    LG->vex_hash[LG->vex_num] = newvnode;
    LG->vex_num++;
    LG->InDegree.push_back(0);
    LG->ve.push_back(0);
    LG->vl.push_back(0);

    return true;
}


/*函数定义
名称：ListGraph_InsertOneEdge
传入参数：LISTGRAPH_T邻接链表的指针，string插入边的起始结点，string插入边的结束结点
返回类型：bool 插入边是否成功
功能说明：为图插入一条弧
        先找到起点的顶点的序号，找到对应链表，将包含终点位置信息的边结构体进行插入到链表中（头插）
        插入失败的2个可能条件：
            （1）邻接链表对应的图是无效的NULL；
            （2）待插入的弧的起始或者结束顶点在图中未找到；
调用函数：
        EdgeList_InsertToHead头插法插入弧（实则为结束点的坐标）
*/
bool ListGraph_InsertOneEdge(LISTGRAPH_T LG, string start_vex, string end_vex, int arc_weight)
{
    if (LG == NULL)
    {
        cout << "邻接链表对应的图是无效的NULL，插入弧失败" << endl;
        return false;
    }
    int start_index = ListGraph_GetIndexByVexName(LG, start_vex);
    int end_index = ListGraph_GetIndexByVexName(LG, end_vex);

    if (start_index == -1 || end_index == -1)
    {
        cout << "待插入的弧的起始或者结束顶点在图中未找到，插入失败" << endl;
        return false;
    }
    //获取弧线的链表头结点

    LG->vex_hash[start_index]->head = EdgeList_InsertToHead(LG->vex_hash[start_index]->head, end_index);
    LG->vex_hash[start_index]->head->edge_weight = arc_weight;
    LG->vex_hash[start_index]->head->start_name = start_vex;
    LG->vex_hash[start_index]->head->end_name = end_vex;
    LG->edge_num++;
    return true;
}


/*函数定义
名称：ListGraph_GetIndexByVexName
传入参数：LISTGRAPH_T图的邻接链表的指针，
        string结点的信息
返回类型：int结点的指数index
功能说明：根据结点信息返回该结点所对应的指数
        查找失败的两个可能条件：
            （1）无效图NULL；
            （2）没有匹配项
调用函数：
        strcmp:串匹配函数
*/
int  ListGraph_GetIndexByVexName(LISTGRAPH_T LG, string vexname)
{
    if (LG == NULL) {
        //cout << "无效图NULL，查找结点index失败" << endl;
        return -1;
    }
    int i = 0;
    for (i = 0; i < LG->vex_num; i++)
    {
        if (LG->vex_hash[i]->vex_name == vexname)
        {
            return i;
        }
    }
    //cout << "没有匹配项，查找结点index失败" << endl;
    return -1;
}


/*函数定义
名称：ListGraph_GetNameByVexIndex
传入参数：LISTGRAPH_T图的邻接链表的指针，
        int结点的index
返回类型：string结点的信息
功能说明：根据结点的指数返回该结点所对应的信息
调用函数：
*/
string  ListGraph_GetNameByVexIndex(LISTGRAPH_T LG, int vexindex)
{
    if (LG == NULL)
    {
        cout << "图是无效的NULL，查找结点信息失败" << endl;
        return NULL;
    }
    return LG->vex_hash[vexindex]->vex_name;
}


/*函数定义
名称：ListGraph_GetEdgeHeadNode
传入参数：LISTGRAPH_T图的邻接链表的指针，
        string结点的信息
返回类型：string结点的信息
功能说明：返回顶点所对应链表的头结点（第一个弧的endpoint）
调用函数：
        ListGraph_GetIndexByVexName
*/
EDGENODE_T ListGraph_GetEdgeHeadNode(LISTGRAPH_T LG, string vexname)
{
    if (LG == NULL)
    {
        cout << "图是无效的NULL，获取头结点失败" << endl;
        return NULL;
    }
    int index = ListGraph_GetIndexByVexName(LG, vexname);
    return LG->vex_hash[index]->head;
}


/*函数定义
名称：ListGraph_DeleteOneVex
传入参数：LISTGRAPH_T图的邻接链表的指针，
        string结点的信息
返回类型：bool
功能说明：根据顶点名称删除顶点
        找到对应顶点的序号index，删除顶点对应的链表（他的为起点的边都要删除），然后将index后面的顶点往移动；
        最后去删除以该顶点为终点的边，在寻找时要注意所有终点的位置（边结构体中的顶点序号）大于index都要减1。
调用函数：
        ListGraph_GetIndexByVexName
        Edge_DeleteAll
*/
bool ListGraph_DeleteOneVex(LISTGRAPH_T LG, string vexname)
{
    if (LG == NULL)
    {
        cout << "图是无效的NULL，删除顶点失败" << endl;
        return false;
    }

    int i = ListGraph_GetIndexByVexName(LG, vexname);
    if (i == -1)
    {
        cout << "没有对应的顶点，删除顶点失败" << endl;
        return false;
    }
    //删除顶点带的链表
    Edge_DeleteAll(LG, LG->vex_hash[i]->head);
    /**接着要将顶点往前移动*/
    int j = i;
    for (; j < LG->vex_num - 1; j++)
    {
        LG->vex_hash[j] = LG->vex_hash[j + 1];
    }
    LG->vex_hash[j + 1] = NULL;

    LG->vex_num--;

    /**************************删除弧线*******************************************/
    for (int k = 0; k < LG->vex_num; k++)
    {
        EDGENODE_T head = LG->vex_hash[k]->head;
        EDGENODE_T prenode = head;/**为了好删除，每次要保留上次的节点*/

        while (head != NULL)//有弧
        {
            if (head->vex_index == i)//是以待删除的顶点为入度
            {
                if (head == LG->vex_hash[k]->head)//节点是第一个节点
                {
                    LG->vex_hash[k]->head = head->next;
                    free(head);
                    head = NULL;
                    LG->edge_num--;
                    break;
                }
                else
                {
                    prenode->next = head->next;
                    free(head);
                    head = NULL;
                    LG->edge_num--;
                    break;
                }
            }
            else//注意要将顶点的位置改变下
            {
                if (head->vex_index > i)
                    head->vex_index--;
                prenode = head;/**保留本次*/
                head = head->next;
            }
        }
    }

    return true;
}


/*函数定义
名称：ListGraph_DeleteOneArc
传入参数：LISTGRAPH_T图的邻接链表的指针，
        string弧线起始结点的信息
        string弧线结束结点的信息
返回类型：bool
功能说明：根据前后顶点名称删除弧线
调用函数：
        ListGraph_GetIndexByVexName
*/
bool ListGraph_DeleteOneArc(LISTGRAPH_T LG, string start_vex, string end_vex)
{
    if (LG == NULL)
    {
        cout << "图是无效的NULL，删除弧线失败" << endl;
        return false;
    }
    int start_index = ListGraph_GetIndexByVexName(LG, start_vex);
    int end_index = ListGraph_GetIndexByVexName(LG, end_vex);

    if (start_index == -1 || end_index == -1) {
        cout << "结点不存在，删除弧线失败" << endl;
        return false;
    }

    EDGENODE_T head = LG->vex_hash[start_index]->head;
    EDGENODE_T prenode = head;
    while (head != NULL)
    {
        if (head->vex_index == end_index)
        {
            if (head == LG->vex_hash[start_index]->head)
            {
                LG->vex_hash[start_index]->head = head->next;
                free(head);
                head = NULL;
                LG->edge_num--;
                break;
            }
            else
            {
                prenode->next = head->next;
                free(head);
                head = NULL;
                LG->edge_num--;
                break;
            }
        }
        else
        {
            prenode = head;
            head = head->next;
        }
    }
    return true;
}


/*函数定义
名称：LIStGraph_PrintfVex
传入参数：LISTGRAPH_T图的邻接链表的指针，
返回类型：void
功能说明：将图中的顶点打印显示
调用函数：
*/
void LIStGraph_PrintfVex(LISTGRAPH_T LG)
{
    cout << "图中现总顶点数" << LG->vex_num << endl;
    for (int i = 0; i < LG->vex_num; i++)
    {
        cout << "第" << i << "号顶点：" << LG->vex_hash[i]->vex_name << '\t';
    }
    cout << endl;
}


/*函数定义
名称：ListGraph_PrintfEdge
传入参数：LISTGRAPH_T图的邻接链表的指针，
返回类型：void
功能说明：将图中的边打印显示
调用函数：
        ListGraph_GetEdgeHeadNode
        ListGraph_GetNameByVexIndex
*/
void ListGraph_PrintfEdge(LISTGRAPH_T LG)
{
    cout << "图中现总边数" << LG->edge_num << endl;
    for (int i = 0; i < LG->vex_num; i++)
    {
        EDGENODE_T head = ListGraph_GetEdgeHeadNode(LG, LG->vex_hash[i]->vex_name);
        EDGENODE_T  p = head;
        while (p != NULL)
        {
            cout << LG->vex_hash[i]->vex_name << " " << ListGraph_GetNameByVexIndex(LG, p->vex_index) << '\t';
            p = p->next;
        }
    }
    cout << endl;
}


/*函数定义
名称：ListGraph_Printf
传入参数：LISTGRAPH_T图的邻接链表的指针，
返回类型：void
功能说明：将图中的点和边分别打印显示
调用函数：
        LIStGraph_PrintfVex
        ListGraph_PrintfEdge
*/
void ListGraph_Printf(LISTGRAPH_T LG)
{
    LIStGraph_PrintfVex(LG);
    ListGraph_PrintfEdge(LG);
}


/*函数定义
名称：ListGraph_PrintfLinkedTable
传入参数：LISTGRAPH_T图的邻接链表的指针，
返回类型：void
功能说明：显示并打印图的邻接链表于控制台上
调用函数：
        LIStGraph_PrintfVex
        ListGraph_PrintfEdge
*/
void ListGraph_PrintfLinkedTable(LISTGRAPH_T LG) {
    cout << "邻接链表显示如下" << endl;
    for (int i = 0; i < LG->vex_num; i++) {
        cout << " 顶点 " << LG->vex_hash[i]->vex_name << ":";
        EDGENODE_T head = ListGraph_GetEdgeHeadNode(LG, LG->vex_hash[i]->vex_name);
        EDGENODE_T  p = head;
        while (p != NULL)
        {
            cout <<"connected to " << ListGraph_GetNameByVexIndex(LG, p->vex_index) <<"("<<p->edge_weight << "); ";
            p = p->next;
        }
        cout << "."<< endl;
    }
}


/*函数定义
名称：ListGraph_DeleteGraph
传入参数：LISTGRAPH_T图的邻接链表的指针，
返回类型：void
功能说明：将图中的点和边分别打印显示
调用函数：
        Edge_DeleteAll
        free
*/
void ListGraph_DeleteGraph(LISTGRAPH_T LG)
{
    if (LG == NULL)
    {
        cout << "图是无效的NULL" << endl;
        return;
    }
    int n = LG->vex_num;
    for (int i = 0; i < n; i++)
    {
        Edge_DeleteAll(LG, LG->vex_hash[i]->head);
        LG->vex_hash[i]->head = NULL;
    }
    free(LG->vex_hash);
    free(LG);
}



/**用于有向图的拓扑排序*/
void ListGraph_TopologySort(LISTGRAPH_T LG, string* vexnode)
{   /**辅助队列，压入入度为0的顶点*/
    LISTQUEUE_T queue = NULL;
    queue =	ListQueue_Init(queue);

    int Rudu[MAXNUM_VEX] = { 0 };
    /**统计各个顶点的入度正确*/
    for (int i = 0; i < LG->vex_num; i++)
    {
        EDGENODE_T head = LG->vex_hash[i]->head;

        while (head != NULL)
        {
            Rudu[head->vex_index]++;
            head = head->next;
        }
    }

    cout << "完成统计后，";
    ListGraph_showRudu(LG, Rudu);

    printf("\n");
    int index = 0;
    int res_index = 0;
    char* result[MAXNUM_VEX] = { 0 };

    for (int i = 0; i < LG->vex_num; i++)
    {
        if (Rudu[i] == 0)
        {
            ListQueue_EnQueue(queue, i);
            while (!ListQueue_IsEmpty(queue))
            {

                ListQueue_DeQueue(queue, &res_index);
                vexnode[index++] = LG->vex_hash[res_index]->vex_name;
                EDGENODE_T head = LG->vex_hash[res_index]->head;

                while (head != NULL)
                {
                    Rudu[head->vex_index]--;/**所有这个顶点相关的点入度都-1*/

                    if (Rudu[head->vex_index] != 0)
                    {
                        head = head->next;
                    }
                    else
                    {
                        ListQueue_EnQueue(queue, head->vex_index);
                    }
                }

                cout << "新一轮操作后，";
                ListGraph_showRudu(LG, Rudu);

            }
        }
    }

    /*展示拓扑排序的结果*/
    cout << "排序结果" << endl;
    for (int j = 0; j < LG->vex_num; j++) {
        cout << vexnode[j] << "->";
        if ((j + 1) % 5 == 0)
            cout << endl;
    }
}



void ListGraph_showRudu(LISTGRAPH_T LG, int Rudu[]) {
    cout << "当下入度域情况" << endl;
    for (int i = 0; i < LG->vex_num; i++) {
        cout << LG->vex_hash[i]->vex_name << ":" << Rudu[i] << "; ";
        if ((i+1) % 5 == 0)
            cout << endl;
    }
    cout << endl;
}




/***********图中关于链表部分的接口************/
bool EdgeList_IsEmpty(EDGENODE_T head)
{
    if (head == NULL)
        return true;
    return false;
}
EDGENODE_T EdgeList_InsertToHead(EDGENODE_T head, int index)
{

    EDGENODE_T newedgenode = new EDGENODE;
    if (newedgenode == NULL)
        return NULL;
    //memset(newedgenode, 0, sizeof(EDGENODE));
    newedgenode->vex_index = index;
    newedgenode->next = NULL;

    if (EdgeList_IsEmpty(head))
    {
        head = newedgenode;
        return head;
    }
    //EDGENODE_T tmp = head;
    newedgenode->next = head;
    head = newedgenode;
    //head->next = newedgenode;
    return head;
}
void Edge_DeleteAll(LISTGRAPH_T LG, EDGENODE_T head)
{
    EDGENODE_T p = head;
    while (p != NULL)
    {
        EDGENODE_T tmp = p->next;
        free(p);
        LG->edge_num--;
        p = tmp;
    }
}



/********************关键路径***********************/


bool TopologicalOrder(LISTGRAPH_T LG)
{
    /*重新开始计算入度*/
    /**统计各个顶点的入度正确*/
    for (int i = 0; i < LG->vex_num; i++) {
        LG->InDegree[i] = 0;
    }// end of for i
    for (int i = 0; i < LG->vex_num; i++)
    {
        EDGENODE_T head = LG->vex_hash[i]->head;
        while (head != NULL)
        {
            LG->InDegree[head->vex_index]++;
            head = head->next;
        }// end of  while
    }// end of for i

    /*重置逆拓扑排序stack*/
    Empty_Stack(LG->ReverseTopoOrder);


    int count = 0;
    stack<int> _0InDegreeStack;
    for (int i = 0; i < LG->vex_num; i++)
    {
        if (LG->InDegree[i] == 0)
        {
            _0InDegreeStack.push(i);
        }
    }

    while (!_0InDegreeStack.empty())
    {
        int j = (_0InDegreeStack.top());
        _0InDegreeStack.pop();
        PushStack(LG->ReverseTopoOrder, j);//j号顶点入逆拓扑排序栈！
        count++;
        EDGENODE_T head = LG->vex_hash[j]->head;
        while (head != NULL) {
            //遍历j号顶点的所有邻接点k
            int k = head->vex_index;
            if (--(LG->InDegree[k]) == 0) {
                //对j号顶点的每一个邻接顶点的入度-1，若入度为0则入0入度栈
                _0InDegreeStack.push(k);
            }
            if (LG->ve[j] + head->edge_weight > LG->ve[k]) {
                LG->ve[k] = LG->ve[j] + head->edge_weight;
            }
            head = head->next;
        }
    }

    if (count < LG->vex_num) {
        return false;
    }
    else {
        cout << "整个逆序栈" << endl;
        show(LG->ReverseTopoOrder);
        cout << endl;
        cout << "计算各个顶点事件的最早发生时间之后：" << endl;
        output_VE_VL(LG);
        return true;
    }
}



bool CriticalPath(LISTGRAPH_T LG, string& VE_VL_str, string& EE_EL_str, string& cp_str) {
    if (!TopologicalOrder(LG)) {
        return false;
    }

    for (int i = 0; i < LG->vex_num; i++) {
        //初始化各个顶点事件的最迟发生时间！
        LG->vl[i] = LG->ve[LG->vex_num - 1];
    }

    cout << "初始化各个顶点事件的最迟发生时间之后：" << endl;
    VE_VL_str = "初始化各个顶点事件的最迟发生时间之后：\n";
    VE_VL_str += *(output_VE_VL(LG));
    show(LG->ReverseTopoOrder);
    cout << endl;
    while (IsNotNull(LG->ReverseTopoOrder)) {//按拓扑逆序求各个顶点的vl值
        int j = Top_element(LG->ReverseTopoOrder);
        PopStack(LG->ReverseTopoOrder);
        EDGENODE_T head = LG->vex_hash[j]->head;
        while (head != NULL) {
            //遍历j号顶点的所有邻接点k
            int k = head->vex_index;
            int dut = head->edge_weight;
            if (LG->vl[k] - dut < LG->vl[j]) {
                LG->vl[j] = LG->vl[k] - dut;
            }
            head = head->next;
        }//while
    }//while
    cout << "更新各个顶点事件的最迟发生时间之后：" << endl;
    VE_VL_str += "更新各个顶点事件的最迟发生时间之后：\n";
    VE_VL_str += *(output_VE_VL(LG));

    for (int j = 0; j < LG->vex_num; j++) {
        //求没一条弧的最早开始时间ee(i)和最晚开始时间el(i),若ee=el则为关键活动！将关键活动的这条弧的指针存入CP向量
        EDGENODE_T head = LG->vex_hash[j]->head;
        while (head != NULL) {
            int k = head->vex_index;
            int dut = head->edge_weight;
            head->ee = LG->ve[j];
            head->el = LG->vl[k] - dut;
            if (head->ee == head->el) {
                LG->CP.push_back(head);
            }
            EE_EL_str += *output_EE_EL(*head);
            head = head->next;
        }
    }

    //输出关键活动弧
    cout << "关键活动弧：" << endl;
    cp_str += "关键活动弧：\n";
    for (int i = 0; i < LG->CP.size(); i++)
    {
        stringstream ss1;
        ss1 << LG->CP[i]->edge_weight;
        string s1 = ss1.str();

        cp_str += LG->CP[i]->start_name + "->" + LG->CP[i]->end_name + ",weight=" + s1 + "\n";

        cout << LG->CP[i]->start_name << "->" << LG->CP[i]->end_name << ",weight=" << LG->CP[i]->edge_weight << endl;
    }
    return true;
}


string* output_EE_EL(EDGENODE edge_node) {
    stringstream ss1, ss2;
    ss1 << edge_node.ee;
    ss2 << edge_node.el;
    string s1 = ss1.str();
    string s2 = ss2.str();

    string* resStr = new string;
    *resStr = edge_node.start_name + "->" + edge_node.end_name
            + ":ee=" + s1
            + ", el=" + s2 + "\n";

    return resStr;
}

string* output_VE_VL(LISTGRAPH_T LG) {
    string* resStr = new string;

    for (int i = 0; i < LG->vex_num; i++) {
        stringstream ss1, ss2;
        ss1 << LG->ve[i];
        ss2 << LG->vl[i];
        string s1 = ss1.str();
        string s2 = ss2.str();

        *resStr += LG->vex_hash[i]->vex_name
                + ":ve=" + s1
                + ", vl=" + s1 + "\n";
    }
    return resStr;
}
