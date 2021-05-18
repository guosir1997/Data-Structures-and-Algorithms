#include<iostream>
#include<string>
using namespace std;

const int StackSize = 10;

template<typename DataType>
class SeqStack{
public:
    SeqStack(){
        this->top = -1;
    }
    ~SeqStack(){}
    // 入栈操作
    void Push(DataType x){
        data[++top] = x;
    }
    // 出栈操作
    DataType Pop(){
        DataType x = data[top--];
        return x;
    }
    // 获取栈顶元素
    DataType GetTop(){
        return data[top];
    }
    //判空操作
    bool IsEmpty(){
        return (top == -1);
    }
private:
    DataType data[StackSize];
    int top;
};