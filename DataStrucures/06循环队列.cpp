#include<iostream>
using namespace std;

const int QueueSize = 100;

template<typename DataType>
class CirQueue{
public:
    CirQueue(){
        rear = front = QueueSize;
    }
    ~CirQueue(){} //自动销毁
    //入队
    void EnQueue(DataType x){
        if((rear+1) % QueueSize == front){
            throw "上溢";
        }
        rear = (rear + 1) % QueueSize;
        data[rear] = x;
    }
    //出队
    DataType DeQueue(){
        if(rear == front){
            throw "下溢";
        }
        front = (front + 1) % QueueSize;
        return data[front];
    }
    DataType GetHead(){
        if(rear == front){
            throw "下溢";
        }
        return data[(front + 1) % QueueSize];
    }
    bool IsEmpty(){
        return (rear == front);
    } 
private:
    DataType data[QueueSize];
    int front;
    int rear;
};