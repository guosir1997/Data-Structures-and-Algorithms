template<typename DataType>
struct SingleNode{
    DataType data;
    SingleNode<DataType> *next;
};

template<typename DataType>
class LinkQueue{
public:
    LinkQueue(){
        SingleNode<DataType> *p = nullptr; 
        p = new SingleNode<DataType>; //头结点
        p->next = nullptr;
        rear = front = p;
    }
    ~LinkQueue(){
        SingleNode<DataType> *p = nullptr;
        while(front != rear){
            p = front->next;
            front->next = p->next;
            if(p->next){ //仅剩一个节点
                front = rear;
            }
            delete p;
        } // 清空
        delete front; //删除头结点
    }
    //入队
    void EnQueue(DataType x){
        SingleNode<DataType> *p = nullptr;
        p = new SingleNode<DataType>
        p->data = x;
        p->next = nullptr;
        rear->next = p;
        rear = p;
    }
    //出队
    DataType DeQueue(){
        if(front = rear){
            throw "下溢";
        }
        SingleNode<DataType> *p = nullptr;
        p = front->next;
        DataType x = p->data;
        front->next = p->next;
        if(p->next == nullptr){
            front = rear;
        }
        delete p;
        return x;
    }
    DataType GetHead(){
        if(front = rear){
            throw "下溢";
        }
        SingleNode<DataType> *p = nullptr;
        p = front->next;
        DataType x = p->data;
        return x;
    }
    bool IsEmpty(){
        return (front == rear);
    }

private:
    SingleNode<DataType> *rear, *front;
};