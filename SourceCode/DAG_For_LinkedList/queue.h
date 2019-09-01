#ifndef QUEUE_H
#define QUEUE_H
#pragma once
#include <stdio.h>
#include <malloc.h>


struct QueueNode
{
        int vex_index;
        struct QueueNode* next;
};
typedef struct QueueNode QUEUENODE;
typedef struct QueueNode* QUEUENODE_T;

struct ListQueue
{
        struct QueueNode* front;
        struct QueueNode* rear;
};
typedef struct ListQueue LISTQUEUE;
typedef struct ListQueue* LISTQUEUE_T;

LISTQUEUE_T ListQueue_Init(LISTQUEUE_T LQ)
{
        LQ = (LISTQUEUE_T)malloc(sizeof(LISTQUEUE));
        if (LQ == NULL)
                return NULL;
        LQ->front = LQ->rear = (QUEUENODE_T)malloc(sizeof(QUEUENODE));
        if (LQ->front == NULL)
        {
                free(LQ);
                return NULL;
        }
        LQ->front->next = LQ->rear->next = NULL;
        return LQ;
}
bool ListQueue_IsEmpty(LISTQUEUE_T LQ)
{
        if (LQ != NULL)
                return LQ->front->next == NULL ? true : false;
        else
                return false;
}
bool ListQueue_EnQueue(LISTQUEUE_T LQ, int data)
{
        if (LQ == NULL)
                return false;
        QUEUENODE_T newnode = (QUEUENODE_T)malloc(sizeof(QUEUENODE));
        if (newnode == NULL)
                return false;
        newnode->next = NULL;
        newnode->vex_index = data;

        LQ->rear->next = newnode;
        LQ->rear = newnode;
        return true;
}
bool ListQueue_DeQueue(LISTQUEUE_T LQ, int* data)
{
        if (LQ == NULL || ListQueue_IsEmpty(LQ))
                return false;

        *data = LQ->front->next->vex_index;
        QUEUENODE_T tmp = LQ->front->next;
        LQ->front->next = tmp->next;

        free(tmp);
        tmp = NULL;
        if (ListQueue_IsEmpty(LQ))
        {
                LQ->rear = LQ->front;
        }
        return true;
}







#endif // QUEUE_H
