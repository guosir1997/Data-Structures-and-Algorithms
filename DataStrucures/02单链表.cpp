#include<iostream>
using namespace std;

template<typename DataTytpe> //定义节点
struct SingleNode {
	DataTytpe data;
	SingleNode<DataTytpe> *next;
};

template<typename DataType>
class SingleLinkList {
public:
	//默认构造函数，建立空的顺序表
	SingleLinkList() {
		first = new SingleNode<DataType>;
		first->next = nullptr;
	}
	//有参构造函数
	//头插法
	SingleLinkList(DataType a[], int n) {  
		first = new SingleNode<DataType>;
		first->next = nullptr;
		for (int i = 0; i < n; i++) {
			SingleNode<DataType>*new_node = nullptr;
			new_node = new SingleNode<DataType>;
			new_node->data = a[i];
			new_node->next = first->next;
			first->next = new_node;
		}
	}
	// //尾插法
	// SingleLinkList(DataType a[], int n) {
	// 	first = new SingleNode<DataType>;
	// 	first->next = nullptr;
	// 	for (int i = 0; i < n; i++) {
	// 		SingleNode<DataType>*new_node = nullptr;
	// 		new_node = new SingleNode<DataType>;
	// 		new_node->data = a[i];
	// 		first->next = new_node;
	// 		first = first->next;
	// 	}
	// 	first->next = nullptr;
	// }

	// 析构函数
	~ SingleLinkList() {
		SingleNode<DataType>*p = nullptr;
		while (first->next != nullptr) {
			p = first->next;
			first->next = p->next;
			delete p;
		}
		delete first;
	}
	//求长度
	int Length() {  
		SingleNode<DataType>*p = first->next;
		int length = 0;
		while (p != nullptr) {
			p = p->next;
			length++;
		}
		return length;
	}
	//按位查找
	DataType Get(int i) {  
		SingleNode<DataType>*p = first->next;
		int j = 1;
		while (p != nullptr && j < i) {
			p = p->next;
			j++;
		}
		if (p == nullptr) {
			throw "查找错误";
		}	
		else {
			return p->data;
		}
	}
	//按值查找
	int Locate(DataType x) {  
		SingleNode<DataType>*p = first->next;
		int j = 1;
		while (p != nullptr) {
			if (p->data == x) {
				return j;
			}
			p = p->next;
			j++;
		}
		return 0;
	}
	//插值操作
	void Insert(int i, DataType x) {  
		SingleNode<DataType>*p = first->next;
		SingleNode<DataType>*pre = first;
		int j = 1;
		while (j < i && p != nullptr) {
			pre = p;
			p = p->next;
			j++;
		}
		if (j == i) {
			SingleNode<DataType>*new_node = nullptr;
			new_node = new SingleNode<DataType>;
			new_node->data = x;
			new_node->next = p;
			pre->next = new_node;
		}
		else {
			throw "插入异常";
		}
	}
	//删除操作
	DataType Delete(int i) {  
		// SingleNode<DataType>*p = first->next;
		// SingleNode<DataType>*pre = first;
		// int j = 1;
		// while (j < i && p != nullptr) {
		// 	pre = p;
		// 	p = p->next;
		// 	j++;
		// }
		// if (p != nullptr) {
		// 	DataType x = p->data;
		// 	pre->next == p->next;
		// 	delete p;
		// 	return x;
		// }
		// else {
		// 	throw "删除异常";
		// }
		DataType x;
		SingleNode<int> *p = first, *q = nullptr; //工作指针p指向头结点
		int count = 0;
		while (p != nullptr && count < i - 1) //查找第i-1个结点
		{
		p = p->next;
		count++;
		}
		if (p == nullptr || p->next == nullptr) //结点p不存在或p的后继结点不存在
		throw "位置";
		else {
		q = p->next; x = q->data; //暂存被删结点
		p->next = q->next; //摘链
		delete q;
		return x;
		}
	}
	//判空操作
	bool Empty() {  
		if (first->next == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	//遍历操作
	void PrintList() {  
		SingleNode<DataType>*p = first->next;
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
private:
	SingleNode<DataType> *first;
};

void test01() {
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SingleLinkList<int> L{ r, 5 };
	cout << "当前线性表的数据为：";
	L.PrintList(); //输出当前链表1 2 3 4 5
	cout << endl;
	try{
		L.Insert(2, 8); //在第2个位置插入值为8的结点
		cout << "执行插入操作后数据为：";
		L.PrintList(); //输出插入后链表1 8 2 3 4 5
		cout << endl;
	}catch (char* str) {
		cout << str << endl;
	}

	cout << "当前单链表的长度为：" << L.Length() << endl; //输出单链表长度6
	cout << "请输入查找的元素值：";
	cin >> x;
	i = L.Locate(x);
	if (1 <= i){
		cout << "元素" << x << "的元素位置为：" << i << endl;
	}
	else { 
		cout << "单链表中没有元素" << x << endl;
	}
	try{
		cout << "请输入要删除第几个元素：";
		cin >> i;
		x = L.Delete(i); //删除第i个元素
		cout << "删除的元素值是" << x << ", 执行删除操作后数据为：";
		L.PrintList(); //输出删除后链表
	}catch (char* str) {
		cout << str << endl;
	}
}

int main() {

	test01();

	system("pause");
	return 0;
}