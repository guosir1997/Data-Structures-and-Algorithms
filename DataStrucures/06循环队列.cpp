#include<iostream>
using namespace std;

const int QueueSize = 100;

template<typename DataType>
class CirQueue{
public:
    CirQueue(){
        rear = front = QueueSize;
    }
    ~CirQueue(){} //�Զ�����
    //���
    void EnQueue(DataType x){
        if((rear+1) % QueueSize == front){
            throw "����";
        }
        rear = (rear + 1) % QueueSize;
        data[rear] = x;
    }
    //����
    DataType DeQueue(){
        if(rear == front){
            throw "����";
        }
        front = (front + 1) % QueueSize;
        return data[front];
    }
    DataType GetHead(){
        if(rear == front){
            throw "����";
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