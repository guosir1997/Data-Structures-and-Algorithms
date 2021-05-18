#include<iostream>
#include<string>
using namespace std;

template<typename DataType>
struct DualNode{
    DataType data;
    DualNode<DataType> *prior, *next;
};

template<typename DataType>
class DualLinkList{
public:
    DualLinkList(){
        first = new DualNode<DataType>;
        first->next = nullptr;
    }
    //头插构造
    // DualLinkList(DataType a[], int n){
    //     first = new DualNode<DataType>;
    //     first->next = nullptr;
    //     DualNode<DataType> *s = nullptr;
    //     // n = 0
    //     s = new DualNode<DataType>;
    //     s->data = a[0];
    //     s->prior = first;
    //     first->next = s;
    //     s->next = nullptr;
    //     // n > 1
    //     for (int i = 1; i < n; i++){
    //         s = new DualNode<DataType>;
    //         s->data = a[i];
    //         s->next = first->next;
    //         first->next->prior = s;
    //         first->next = s;
    //     }
    //     s->prior = first;
    // }
    //尾插构建
    DualLinkList(DataType a[], int n){
        first = new DualNode<DataType>;
        first->next = nullptr;
        DualNode<DataType> *s = nullptr, *p = first;
        for(int i = 0; i< n; i++){
            s = new DualNode<DataType>;
            s->data = a[i];
            p->next = s;
            s->prior = p;
            p = s;
        }
        p->next = nullptr;
    }
    ~DualLinkList(){
        DualNode<DataType> *p = first->next;
        while(first->next != nullptr){
            p->next = first->next;
            delete p;
            p = first->next;
        } //清空
        delete first; //析构
    }
    // 求表长
    int Length(){ 
        DualNode<DataType> *p = first;
        int j = 0;
        while(first->next != nullptr){
            p = p->next;
            j++;
        }
        return j;
    }
    //按位查找
    DataType Get(int i){
        DualLinkList<DataType> *p = first->next;
        int j = 1;
        while(j < i && p != nullptr){
            p = p->next;
            j++;
        }
        if(i == j){
            return p->data;
        }
        else{  //if(p == nullptr)
            throw "查询异常";
        }
    }
    //按值查找
    int Locate(DataType x){
        DualNode<DataType> *p = first->next;
        int j = 1;
        while(p != nullptr){
            if(p->data == x){
                return j;
            }
            p = p->next;
            j++;
        }
        return 0;
    }
    //插值操作
    void Insert(DataType x, int i){
        DualNode<DataType> *pre = first, *p = nullptr;
        int j = 0;
        while(j < i - 1 && pre != nullptr){
            pre = pre->next;
            j++;
        }
        if(pre == nullptr){
            throw "插入异常";
        }
        else if ( pre->next == nullptr){ //末端插入
            p = new DualNode<DataType>;
            p->data = x;
            p = pre->next;
            p->prior = pre;
            p->next = nullptr;
        }
        else{
            p = new DualNode<DataType>;
            p->data = x;
            p = pre->next->prior;
            p->next = pre->next;
            p = p->next;
            p->prior = pre;
        }
    }
    // 删除操作
    void Delete(int i){
        DualNode<DataType> *pre, *p = first->next; //可以不用定义pre
        int j = 1;
        while(j < i && p != nullptr){
            p = p->next;
            j++;
        }
        if(p == nullptr){
            throw "删除异常";
        }
        else if(p->next = nullptr){
            pre = p->prior;
            pre->next = nullptr;
            delete p;
        }
        else{
            pre = p->prior;
            pre->next = p->next;
            p->next->prior = pre;
            delete p;
        }
    }
    //判空操作
    bool IsEmpty(){
        return first->next;
    }
    //遍历操作
    void PrintList(){
        DualLinkList<DataType> *p = first->next;
        while(p != nullptr){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
private:
    DualNode<DataType> *first;
};