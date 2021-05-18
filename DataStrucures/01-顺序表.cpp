#include<iostream>
using namespace std;

const int MaxSize = 100; // ���鳤��

template<typename DataType>
class SeqList {
public:
	SeqList(); //Ĭ�Ϲ��캯���������յ�˳���

	SeqList(DataType A[], int n) {  //�вι��캯��
		for (int i = 0; i < n; i++) {
			data[i] = A[i];
		}
		length = n;
	}

	~SeqList() {} //��������

	int Length() {  //�󳤶�
		return this->length;
	}

	DataType Get(int i) {  //��λ����
		if (i<0 || i>length) {
			throw "����λ�÷Ƿ�";
		}
		else {
			return data[i-1];
		}
	}

	int Locate(DataType x) {  //��ֵ����
		for (int i = 0; i < length; i++) {
			if (data[i] == x) {
				return i + 1;
			}
		}
		return 0;
	}

	void Insert(int i, DataType x) {  //��ֵ����
		for (int j = length; j >= 1; j--) {
			data[j] = data[j - 1];
		}
		data[i - 1] = x;
		length++;
	}

	DataType Delete(int i) {  //ɾ������
		DataType x;
		if (length == 0) {
			throw "����";
		}
		if (i<1 || i>length) {
			throw "ɾ��λ������";
		}
		x = data[i - 1];
		for (int j = i; i < length; i++) {
			data[j - 1] = data[j];
		}
		length--;
		return x;
	} 

	bool Empty() {  //�пղ���
		if (length == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void PrintList() {  //��������
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

private:
	DataType data[MaxSize];
	int length; //���Ա��� <= MaxSize
};

void test01() {
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList<int>L{ r, 5 }; //��������5��Ԫ�ص�˳���
	cout << "��ǰ���Ա������Ϊ��";
	L.PrintList(); //�����ǰ���Ա�1 2 3 4 5
	try
	{
		L.Insert(2, 8); //�ڵ�2��λ�ò���ֵΪ8��Ԫ��
		cout << endl << "ִ�в������������Ϊ��";
		L.PrintList(); //������������Ա�1 8 2 3 4 5
		cout << endl;
	}
	catch (char* str) {
		cout << str << "�����������" << endl;
	}

	cout << "��ǰ���Ա�ĳ���Ϊ��" << L.Length(); //������Ա�ĳ���6
	cout << endl;
	cout << "��������ҵ�Ԫ��ֵ��";
	cin >> x;
	i = L.Locate(x);
	if (0 == i) cout << "����ʧ��" << endl;
	else cout << "Ԫ��" << x << "��λ��Ϊ��" << i << endl;
	try
	{
		cout << "��������ҵڼ���Ԫ��ֵ��";
		cin >> i;
		cout << "��" << i << "��Ԫ��ֵ��" << L.Get(i) << endl;
	}
	catch (char* str) {
		cout << "���Ա���û�и�Ԫ��" << endl;
	}
	try
	{
		cout << "������Ҫɾ���ڼ���Ԫ�أ�";
		cin >> i;
		x = L.Delete(i); //ɾ����i��Ԫ��
		cout << "ɾ����Ԫ����" << x << "��ɾ��������Ϊ��";
		L.PrintList(); //���ɾ��������Ա�
	}
	catch (char* str) {
		cout << "ɾ������" << endl;
	}
}
int main() {

	test01();

	system("pause");
	return 0;
}