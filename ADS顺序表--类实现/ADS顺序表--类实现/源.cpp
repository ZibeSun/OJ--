#include<iostream>
#include<stdio.h>
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
	void list_del(int i);
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
	delete []list;
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
	int a1, a2, b1, b2, c1, c2;
	int item1, item2;
	cin >> a1 >> item1;
	s.list_insert(a1, item1);
	cin >> a2 >> item2;
	s.list_insert(a2, item2);
	cin >> b1;
	s.list_del(b1);
	cin >> b2;
	s.list_del(b2);
	cin >> c1;
	s.list_get(c1);
	cin >> c2;
	s.list_get(c2);
	return 0;
}
/*��Ŀ����
��C++���Ժ���ʵ��˳���

���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��

�������������������롢ɾ��������

�ඨ��ο�



����
��1��������n��ʾ��n�����ݣ���n��ʵ�ʳ��ȣ���������n������
��2������Ҫ�����λ�ú�������
��3������Ҫ�����λ�ú�������
��4������Ҫɾ����λ��
��5������Ҫɾ����λ��
��6������Ҫ���ҵ�λ��
��7������Ҫ���ҵ�λ��

���
����֮���ÿո����

��1������������˳������ݣ�����˳���ʵ�ʳ��Ⱥ�����

ÿ�ɹ�ִ��һ�β����������ɾ���������ִ�к��˳�������

ÿ�ɹ�ִ��һ�β��ң�������ҵ�������

���ִ�в���ʧ�ܣ��������롢ɾ�������ҵ�ʧ�ܣ�������ַ���error���������˳�������

��������
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5
�������
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
��ʾ
��i��λ�����߼������λ�ã���1��ʼ����ʵ�ʱ�������飬��0��ʼ����Ӧ����i-1λ��*/