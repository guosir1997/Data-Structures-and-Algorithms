#include<iostream>
using namespace std;

const int MaxSize = 100; // 数组长度

template<typename DataType>
class SeqList {
public:
	SeqList(); //默认构造函数，建立空的顺序表

	SeqList(DataType A[], int n) {  //有参构造函数
		for (int i = 0; i < n; i++) {
			data[i] = A[i];
		}
		length = n;
	}

	~SeqList() {} //析构函数

	int Length() {  //求长度
		return this->length;
	}

	DataType Get(int i) {  //按位查找
		if (i<0 || i>length) {
			throw "查找位置非法";
		}
		else {
			return data[i-1];
		}
	}

	int Locate(DataType x) {  //按值查找
		for (int i = 0; i < length; i++) {
			if (data[i] == x) {
				return i + 1;
			}
		}
		return 0;
	}

	void Insert(int i, DataType x) {  //插值操作
		for (int j = length; j >= 1; j--) {
			data[j] = data[j - 1];
		}
		data[i - 1] = x;
		length++;
	}

	DataType Delete(int i) {  //删除操作
		DataType x;
		if (length == 0) {
			throw "下溢";
		}
		if (i<1 || i>length) {
			throw "删除位置有误";
		}
		x = data[i - 1];
		for (int j = i; i < length; i++) {
			data[j - 1] = data[j];
		}
		length--;
		return x;
	} 

	bool Empty() {  //判空操作
		if (length == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void PrintList() {  //遍历操作
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

private:
	DataType data[MaxSize];
	int length; //线性表长度 <= MaxSize
};

void test01() {
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList<int>L{ r, 5 }; //建立具有5个元素的顺序表
	cout << "当前线性表的数据为：";
	L.PrintList(); //输出当前线性表1 2 3 4 5
	try
	{
		L.Insert(2, 8); //在第2个位置插入值为8的元素
		cout << endl << "执行插入操作后数据为：";
		L.PrintList(); //输出插入后的线性表1 8 2 3 4 5
		cout << endl;
	}
	catch (char* str) {
		cout << str << "插入操作错误！" << endl;
	}

	cout << "当前线性表的长度为：" << L.Length(); //输出线性表的长度6
	cout << endl;
	cout << "请输入查找的元素值：";
	cin >> x;
	i = L.Locate(x);
	if (0 == i) cout << "查找失败" << endl;
	else cout << "元素" << x << "的位置为：" << i << endl;
	try
	{
		cout << "请输入查找第几个元素值：";
		cin >> i;
		cout << "第" << i << "个元素值是" << L.Get(i) << endl;
	}
	catch (char* str) {
		cout << "线性表中没有该元素" << endl;
	}
	try
	{
		cout << "请输入要删除第几个元素：";
		cin >> i;
		x = L.Delete(i); //删除第i个元素
		cout << "删除的元素是" << x << "，删除后数据为：";
		L.PrintList(); //输出删除后的线性表
	}
	catch (char* str) {
		cout << "删除错误！" << endl;
	}
}
int main() {

	test01();

	system("pause");
	return 0;
}