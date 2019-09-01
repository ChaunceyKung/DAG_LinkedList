
#include "stack.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool Empty_Stack(Stack &S){
    S.top = -1;
    return true;
}

bool IsNotNull(Stack S){
    if (S.top >= 0){
        return true;
    }
    return false;
}

//进栈
bool PushStack(Stack &S, datatype a){
    if (S.top >= MAXSIZE - 1)    //溢出检查必不可少
    {
        cout << "Stack Overflow~" << endl;
        return false;
    }
    S.data[S.top + 1] = a;
    S.top += 1;
    return true;
}



//出栈
bool PopStack(Stack &S){
    if (S.top < 0){
        cout << "Stack Underflow~" << endl;
        return false;
    }
    S.top -= 1;
    return true;
}

//取栈顶元素，不改变栈本身
datatype Top_element(Stack S){
    if (IsNotNull(S)){
        return S.data[S.top];
    }
    else{
        cout << "Empty Stack~";
        return NULL;
    }
}

//显示整个栈

bool show(Stack S){
    if (IsNotNull(S))
    {
        for (int i = 0; i <= S.top; ++i)
        {
            cout << S.data[i] << " ";
        }
        return true;
    }
    else
    {
        cout << "Empty Stack~";
        return false;
    }
}






