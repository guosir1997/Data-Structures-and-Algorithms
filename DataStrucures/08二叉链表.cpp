#include<stack>
#include<queue>

template<typename DataType> //二叉节点
struct BiNode{  
    DataType data;
    BiNode<DataType> *lchild, *rchild;
};

template<typename DataType>
class BiTree{
public:
    BiTree(){
        root = Create();
    }
    ~BiTree(){
        Release(root);
    }
    //前序遍历  根左右
    //递归实现
    void PreOrder(BiNode<DataType> *root){
        if(root){ // != nullptr
            cout << root->data << " ";
            PreOrder(root->lchild);
            PreOrder(root->rchild);
        }
    }
    //循环实现
    void PreOrder(BiNode<DataType> *root){
        if(root){
            stack<BiNode<DataType>*> myStack;
            BiNode<DataType>* cur = root;
            while(cur || !myStack.empty()){
                while(cur){
                    myStack.pushback(cur);
                    cout << cur->data << " ";
                    cur = cur->lchild;
                }
                cur = myStack.top();
                cur = cur->rchild;
                myStack.pop();
            }
        }
    }

    //中序遍历 左根右
    //递归实现
    void InOrder(BiNode<DataType> *root){
        if(root){
            PreOrder(root->lchild);
            cout << "data = " << root->data << " ";
            PreOrder(root->rchild);
        }
    }
    //循环实现
    // void InOrder(BiNode<DataType> *root){
    //     if(root){
    //         stack<BiNode<DataType>*> myStack;
    //         BiNode<DataType>* cur = root;            
    //         while(cur || !myStack.empty()){
    //             while(cur){
    //                 myStack.pushback(cur);                    
    //                 cur = cur->lchild;                
    //             }                
    //             cur = myStack.top();
    //             cout << cur->data << " ";
    //             cur = cur->rchild;
    //             myStack.pop();               
    //         }
    //     }        
    // }

    //后序遍历 左右根
    //递归实现
    void PostOrder(BiNode<DataType> *root){
        if(root){
            PreOrder(root->lchild);
            PreOrder(root->rchild);
            cout << "data = " << root->data << " ";
        }
    }
    //循环实现
    // void PostOrder(BiNode<DataType> *root){       
    //     if(root){
    //         stack<BiNode<DataType>*> myStack;
    //         BiNode<DataType>* cur = root;  
    //         BiNode<DataType>* pre = nullptr; //历史访问点        
    //         while(cur || !myStack.empty()){
    //             while(cur){
    //                 myStack.pushback(cur);                    
    //                 cur = cur->lchild;                
    //             }
    //             cur = myStack.top();
    //             if(cur->rchild && cur->rchild != pre){
    //                 cur = cur->rchild;
    //                 myStack.pushback(cur);
    //                 cur->lchild;
    //             }
    //             else{
    //                 cout << cur->data << " ";
    //                 pre = cur;
    //                 cur = nullptr;
    //             }      
    //         }
    //     }
    // }    
    
    //层序遍历
    void LevelOrder(BiNode<DataType> *root){
        if(root){
            queue<BiNode<DataType>*> myQueue;
            myQueue.push_back(root);
            while(!myQueue.empty()){
                root = myQueue.top();
                cout << root->data << " ";
                myQueue.pop_front();
                if(root->lchild){
                    myQueue.push_back(root->lchild);
                }
                if(root->rchild){
                    myQueue.push_back(root->rchild);
                }
            }
        }
    }

private:
    BiNode<DataType>* Create(){  //前序遍历读取数据
        BiNode<DataType> *root;
        char ch;
        cin >> ch;
        if(ch == '#'){
            root = nullptr;
        }
        else{
            root = new BiNode<DataType>;
            root->data = ch;
            root->lchild = Create();
            root->rchild = Create();
        }
        return root;
    }
    void Release(BiNode<DataType> *root){
        if(root){
            Release(root->lchild);
            Release(root->rchild);
            delete root;
        }
    }
    BiNode<DataType> *root;
};


