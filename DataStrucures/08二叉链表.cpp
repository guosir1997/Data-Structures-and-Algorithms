#include<stack>
#include<queue>

template<typename DataType> //����ڵ�
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
    //ǰ�����  ������
    //�ݹ�ʵ��
    void PreOrder(BiNode<DataType> *root){
        if(root){ // != nullptr
            cout << root->data << " ";
            PreOrder(root->lchild);
            PreOrder(root->rchild);
        }
    }
    //ѭ��ʵ��
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

    //������� �����
    //�ݹ�ʵ��
    void InOrder(BiNode<DataType> *root){
        if(root){
            PreOrder(root->lchild);
            cout << "data = " << root->data << " ";
            PreOrder(root->rchild);
        }
    }
    //ѭ��ʵ��
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

    //������� ���Ҹ�
    //�ݹ�ʵ��
    void PostOrder(BiNode<DataType> *root){
        if(root){
            PreOrder(root->lchild);
            PreOrder(root->rchild);
            cout << "data = " << root->data << " ";
        }
    }
    //ѭ��ʵ��
    // void PostOrder(BiNode<DataType> *root){       
    //     if(root){
    //         stack<BiNode<DataType>*> myStack;
    //         BiNode<DataType>* cur = root;  
    //         BiNode<DataType>* pre = nullptr; //��ʷ���ʵ�        
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
    
    //�������
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
    BiNode<DataType>* Create(){  //ǰ�������ȡ����
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


