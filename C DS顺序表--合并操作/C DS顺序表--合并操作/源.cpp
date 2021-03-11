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
	//~SeqList();
	void list_int(int n);
	void list_setsize(int n);
	void list_addlist(int n,int* item);
	void list_sort();
	int* list_getlist();
	int list_getsize();
	void list_insert(int i, int item);
	void list_multiinsert(int i, int n, int* item);
	void list_del(int i);
	void list_multidel(int i, int n);
	void list_get(int i);
	void list_display();
	SeqList list_combine(SeqList &a,SeqList &b);
};
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
/*SeqList::~SeqList()
{
	delete[]list;
}*/
void SeqList::list_int(int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	size = n;
}
void SeqList::list_setsize(int n)
{
	size = n;
}
void SeqList::list_addlist(int n,int* item)
{
	for (int i = 0; i < n; i++)
	{
		list[i] = item[i];
	}
	size = n;
}
void SeqList::list_sort()
{
	for (int i = 0; i < size-1; i++)
	{
		for (int i = 0; i < size-1; i++)
		{
			if (list[i] > list[i + 1])
			{
				int mid;
				mid = list[i];
				list[i] = list[i + 1];
				list[i + 1] = mid;
			}
		}
	}
}
int* SeqList::list_getlist()
{
	return list;
}
int SeqList::list_getsize()
{
	/*for (int i = 0; i < 1000; i++)
	{
		if (list[i] == '\0')
			size = i + 1;
	}*/
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
		//list_display();
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
SeqList SeqList::list_combine(SeqList& a, SeqList& b)
{
	SeqList sum;
	sum.list_addlist(a.list_getsize(), a.list_getlist());
	sum.list_multiinsert(1, b.list_getsize(), b.list_getlist());
	/*cout << endl;
	cout << sum.list_getsize();
	cout << endl;*/
	sum.list_sort();
	sum.list_display();
	return sum;
}
int main()
{
	int n, m;
	cin >> n;
	SeqList a;
	a.list_int(n);
	cin >> m;
	SeqList b;
	b.list_int(m);
	a.list_combine(a, b);
}
/*��Ŀ����
����˳�����࣬���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��

��֪�����������У����������е����ݺϲ���˳����У���ʹ��˳�������ݵ�������

����
��1��������n��ʾ��n�����ݣ���������n�����ݣ���ʾ��1�����У�Ҫ�����ݵ���������

��2��������m��ʾ��m�����ݣ���������m�����ݣ���ʾ��2�����У�Ҫ�����ݵ���������

���
˳������ݰ���˳����ʵ�ʳ��Ⱥ����ݣ�����֮���ÿո����

��1������������˳�������

��������
3 11 33 55
5 22 44 66 88 99
�������
8 11 22 33 44 55 66 88 99 */