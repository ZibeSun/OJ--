#include<iostream>
using namespace std;
class SeqList
{
private:
	int* list;
	int maxsize;
	int size;
public:
	SeqList();
	~SeqList();
	void list_int(int n);
	int list_size();
	void list_insert(int i, int item);
	void list_multiinsert(int i, int n,int *item);
	void list_del(int i);
	void list_multidel(int i, int n);
	void list_get(int i);
	void list_display();
};
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
SeqList::~SeqList()
{
	delete[]list;
}
void SeqList::list_int(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	size = n;
}
int SeqList::list_size()
{
	for (int i = 0; i < 1000; i++)
	{
		if (list[i] == '\0')
			size = i + 1;
	}
	return size;
}
void SeqList::list_insert(int i, int item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size; k >= i; k--)
		{
			list[k] = list[k - 1];
		}
		list[i - 1] = item;
		size++;
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_multiinsert(int i, int n, int *item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size+n-1; k > i; k--)
		{
			list[k] = list[k - n];
		}
		for (int k = i - 1; k < i-1+n; k++)
		{
			list[k] = item[k - i + 1];
		}
		size += n;
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_del(int i)
{
	if ((i > 0) && (i <= size))
	{
		size--;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + 1];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_multidel(int i, int n)
{
	if ((i > 0) && (i <= size))
	{
		size -= n;
		for (int k = i - 1; k < size; k++)
		{
			list[k] = list[k + n];
		}
		list_display();
	}
	else
		cout << "error" << endl;
}
void SeqList::list_get(int i)
{
	if ((i > 0) && (i <= size))
		cout << list[i - 1] << endl;
	else
		cout << "error" << endl;
}
void SeqList::list_display()
{
	cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	SeqList s;
	s.list_int(n);
	s.list_display();
	int i1, n1, i2, n2;
	cin >> i1 >> n1;
	int* item = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		cin >> item[i];
	}
	s.list_multiinsert(i1, n1,item);
	cin >> i2 >> n2;
	s.list_multidel(i2, n2);
}
/*��Ŀ����
����˳�����࣬���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��

����������³�Ա������

���캯����ʵ��˳���ĳ�ʼ����

���������ݵ�multiinsert(int i, int n, int item[])������ʵ���ڵ�i��λ�ã�����������������item��n�����ݣ�����λ��i��ʼ���������ݡ�

ɾ��������ݵ�multidel(int i, int n)������ʵ�ִӵ�i��λ�ÿ�ʼ������ɾ��n�����ݣ�����λ��i��ʼɾ��������ݡ�

��дmain�������Ը�˳����ࡣ

����
��1��������n��ʾ��n�����ݣ���n��ʵ�ʳ��ȣ���������n������

��2��������i��ʾ���뿪ʼ��λ�ã�������k��ʾ��k���������ݣ���������k������

��3��������i��ʾɾ����ʼ��λ�ã�������k��ʾҪɾ��k������

���
˳������ݰ���˳����ʵ�ʳ��Ⱥ����ݣ�����֮���ÿո����

��1������������˳�������

��2�����ִ������������˳�������

��3�����ִ������ɾ�����˳�������

 

��������
6 11 22 33 44 55 66
2 3 99 88 77
4 5
�������
6 11 22 33 44 55 66 
9 11 99 88 77 22 33 44 55 66 
4 11 99 88 66 */