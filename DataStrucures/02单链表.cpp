#include<iostream>
using namespace std;

template<typename DataTytpe> //����ڵ�
struct SingleNode {
	DataTytpe data;
	SingleNode<DataTytpe> *next;
};

template<typename DataType>
class SingleLinkList {
public:
	//Ĭ�Ϲ��캯���������յ�˳���
	SingleLinkList() {
		first = new SingleNode<DataType>;
		first->next = nullptr;
	}
	//�вι��캯��
	//ͷ�巨
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
	// //β�巨
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

	// ��������
	~ SingleLinkList() {
		SingleNode<DataType>*p = nullptr;
		while (first->next != nullptr) {
			p = first->next;
			first->next = p->next;
			delete p;
		}
		delete first;
	}
	//�󳤶�
	int Length() {  
		SingleNode<DataType>*p = first->next;
		int length = 0;
		while (p != nullptr) {
			p = p->next;
			length++;
		}
		return length;
	}
	//��λ����
	DataType Get(int i) {  
		SingleNode<DataType>*p = first->next;
		int j = 1;
		while (p != nullptr && j < i) {
			p = p->next;
			j++;
		}
		if (p == nullptr) {
			throw "���Ҵ���";
		}	
		else {
			return p->data;
		}
	}
	//��ֵ����
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
	//��ֵ����
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
			throw "�����쳣";
		}
	}
	//ɾ������
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
		// 	throw "ɾ���쳣";
		// }
		DataType x;
		SingleNode<int> *p = first, *q = nullptr; //����ָ��pָ��ͷ���
		int count = 0;
		while (p != nullptr && count < i - 1) //���ҵ�i-1�����
		{
		p = p->next;
		count++;
		}
		if (p == nullptr || p->next == nullptr) //���p�����ڻ�p�ĺ�̽�㲻����
		throw "λ��";
		else {
		q = p->next; x = q->data; //�ݴ汻ɾ���
		p->next = q->next; //ժ��
		delete q;
		return x;
		}
	}
	//�пղ���
	bool Empty() {  
		if (first->next == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	//��������
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
	cout << "��ǰ���Ա������Ϊ��";
	L.PrintList(); //�����ǰ����1 2 3 4 5
	cout << endl;
	try{
		L.Insert(2, 8); //�ڵ�2��λ�ò���ֵΪ8�Ľ��
		cout << "ִ�в������������Ϊ��";
		L.PrintList(); //������������1 8 2 3 4 5
		cout << endl;
	}catch (char* str) {
		cout << str << endl;
	}

	cout << "��ǰ������ĳ���Ϊ��" << L.Length() << endl; //�����������6
	cout << "��������ҵ�Ԫ��ֵ��";
	cin >> x;
	i = L.Locate(x);
	if (1 <= i){
		cout << "Ԫ��" << x << "��Ԫ��λ��Ϊ��" << i << endl;
	}
	else { 
		cout << "��������û��Ԫ��" << x << endl;
	}
	try{
		cout << "������Ҫɾ���ڼ���Ԫ�أ�";
		cin >> i;
		x = L.Delete(i); //ɾ����i��Ԫ��
		cout << "ɾ����Ԫ��ֵ��" << x << ", ִ��ɾ������������Ϊ��";
		L.PrintList(); //���ɾ��������
	}catch (char* str) {
		cout << str << endl;
	}
}

int main() {

	test01();

	system("pause");
	return 0;
}