#ifndef STACK_H
#define STACK_H

#pragma once
#define MAXSIZE 100
typedef int datatype;
typedef struct{
    datatype data[MAXSIZE];
    int top;      //记录当前栈顶位置
} Stack;

//置空栈
bool Empty_Stack(Stack &S);

//判断栈是否为空
bool IsNotNull(Stack S);

//进栈
bool PushStack(Stack &S, datatype a);

//出栈
bool PopStack(Stack &S);

//取栈顶元素，不改变栈本身
datatype Top_element(Stack S);

//显示整个栈
bool show(Stack S);





#endif // STACK_H
