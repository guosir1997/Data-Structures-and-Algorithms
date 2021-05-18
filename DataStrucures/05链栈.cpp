template<typename DataType>
struct SingleNode{
    DataType data;
    SingleNode<DataType> *next;
};

template<typename DataType>
class LinkStack{
public:
    LinkStack(){
        top = new SingleNode<DataType>;
        top = nullptr;
    }
    ~LinkStack(){
        SingleNode<DataType> *p = top;
        while(top != nullptr){
            top = top->next;
            delete p;
            p = top;
        }
    }
    //入栈
    void Push(DataType x){
        SingleNode<DataType> *p = nullptr;
        p = new SingleNode<DataType>;
        p->data = x;
        p->next = top;
        top = p;
    }
    //出栈
    DataType Pop(){
        SingleNode<DataType> *p = top;
        DataType x = top->data;
        top = top->next;
        delete p;
        return x;
    }
    DataType GetTop(){
        return top->data;
    }
    bool IsEmpty(){
        return (top == nullptr);
    }
private:
    SingleNode<DataType> *top;
};