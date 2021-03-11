#include<iostream>
using namespace std;
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
	void list_multiinsert(int i, int n, int* item);
	void list_del(int i);
	void list_multidel(int i, int n);
	void list_get(int i);
	void list_display();
	void list_move(int d,int n);
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
void SeqList::list_multiinsert(int i, int n, int* item)
{
	if ((i > 0) && (i <= (size + 1)))
	{
		for (int k = size + n - 1; k > i; k--)
		{
			list[k] = list[k - n];
		}
		for (int k = i - 1; k < i - 1 + n; k++)
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
	//cout << size << " ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
void SeqList::list_move(int d,int n)
{
	int* nlist = new int[size];
	if (d == 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i - n < 0)
			{
				nlist[i - n + size] = list[i];
			}
			else
			{
				nlist[i - n] = list[i];
			}
		}
	}
	else if (d == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (i + n > size-1)
			{
				nlist[i + n - size] = list[i];
			}
			else
			{
				nlist[i + n] = list[i];
			}
		}
	}
	list = nlist;
}
int main()
{
	int n;
	cin >> n;
	SeqList a;
	a.list_int(n);
	a.list_display();
	int d1, x1, d2, x2;
	cin >> d1 >> x1;
	a.list_move(d1, x1);
	a.list_display();
	cin >> d2 >> x2;
	a.list_move(d2, x2);
	a.list_display();
	return 0;
}
/*��Ŀ����
˳������λ��ѭ����λ������˳���1��2��3��4��5��6���������1λ����ԭ����ͷԪ���ƶ���ĩβ������Ԫ��������1λ�����2��3��4��5��6��1��ͬ���������1λ����ԭ����βԪ���ƶ���ͷ������Ԫ��������1λ�����6��1��2��3��4��5����������λ�Ķ�����ӣ�

ԭ���ݣ�1��2��3��4��5��6

����3λ��4��5��6��1��2��3����ԭ���ݶԱ�

����4λ��3��4��5��6��1��2����ԭ���ݶԱ�

���д����ʵ��˳����ѭ����λ����

����
��1������n��ʾ˳�������ġ�n������

��2������n�����ݣ�������С��100��������

��3�������ƶ�������ƶ���λ�������Ʒ���Ϊ0�����Ʒ���Ϊ1

��4�������ƶ�������ƶ���λ�������Ʒ���Ϊ0�����Ʒ���Ϊ1

ע�⣺�ƶ������������һ���ƶ���Ľ�����е�

���
��һ�����������˳����ڵ��������ݣ�����֮���ÿո����

�ڶ��������һ����λ������˳����ڵ��������ݣ�����֮���ÿո����

����������ڶ�����λ������˳����ڵ��������ݣ�����֮���ÿո����

��������
5
11 22 33 44 55
0 2
1 4
�������
11 22 33 44 55 
33 44 55 11 22 
44 55 11 22 33 */