#include<stdio.h>
#include<iostream>
using namespace std;
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode()
	{
		next = NULL;
		data = 0;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	~LinkList();
	void LL_add(int x);
	ListNode* LL_index(int i);
	void LL_get(int i);
	void LL_insert(int i, int item);
	void LL_del(int i);
	void LL_display();
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
LinkList::~LinkList()
{
	head = NULL;
}
void LinkList::LL_add(int x)
{
	ListNode* l = new ListNode();
	l->data = x;
	if (head->next == NULL)
	{
		head->next = l;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= len; k++)
		{
			p = p->next;
		}
		p->next = l;
	}
	len++;
}
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
		}
		return p;
	}
}
void LinkList::LL_get(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		int x;
		ListNode* p;
		p = head;
		for (int k = 1; k <= i; k++)
		{
			p = p->next;
			x = p->data;
		}
		cout << x << endl;
	}	
}
void LinkList::LL_insert(int i, int item)
{
	if ((i <= 0) || (i > len+1))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == len)
		{
			ListNode* l = new ListNode();
			l->data = i;
			ListNode* p;
			p = head;
			for (int k = 1; k <= len; k++)
			{
				p = p->next;
			}
			p->next = l;
			len++;
			LL_display();
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			ListNode* p;
			p = head;
			for (int k = 1; k <= i; k++)
			{
				p = p->next;
			}
			l->next = p;
			p = head;
			for (int k = 1; k <= i - 1; k++)
			{
				p = p->next;
			}
			p->next = l;
			len++;
			LL_display();
		}
	}
}
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == 1)
		{
			ListNode* p;
			p = head;
			for (int k = 1; k <= 2; k++)
			{
				p = p->next;
			}
			head->next = p;
		}
		else if (i == len)
		{
			ListNode* p;
			p = head;
			for (int k = 1; k <= i-1; k++)
			{
				p = p->next;
			}
			p->next = NULL;
		}
		else
		{
			ListNode* m;
			m = head;
			for (int k = 1; k <= i - 1; k++)
			{
				m = m->next;
			}
			ListNode* n;
			n = head;
			for (int k = 1; k <= i + 1; k++)
			{
				n = n->next;
			}
			m->next = n;
		}
		len--;
		LL_display();
	}
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	LinkList L;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		L.LL_add(p[i]);
	}
	L.LL_display();
	int i1, i2;
	int d1, d2;
	int g1, g2;
	int x1, x2;
	cin >> i1 >> x1;
	L.LL_insert(i1, x1);
	cin >> i2 >> x2;
	L.LL_insert(i2, x2);
	cin >> d1;
	L.LL_del(d1);
	cin >> d2;
	L.LL_del(d2);
	cin >> g1;
	L.LL_get(g1);
	cin >> g2;
	L.LL_get(g2);
	return 0;
}
/*��Ŀ����
��C++���Ժ���ʵ�ֵ�������ͷ���

���԰�����data������nextָ����

�������������롢ɾ��������

ע�⣺�����������飬����λ�ô�1��ʼ��Ӧ�׽�㣬ͷ��㲻������

�ඨ��ο�



����
n
��1��������n��ʾ��n�����ݣ���������n������
��2������Ҫ�����λ�ú�������
��3������Ҫ�����λ�ú�������
��4������Ҫɾ����λ��
��5������Ҫɾ����λ��
��6������Ҫ���ҵ�λ��
��7������Ҫ���ҵ�λ��
���
n
����֮���ÿո������

��1�����������ĵ����������

ÿ�ɹ�ִ��һ�β����������ɾ���������ִ�к�ĵ���������

ÿ�ɹ�ִ��һ�β��ң�������ҵ�������

���ִ�в���ʧ�ܣ��������롢ɾ�������ҵ�ʧ�ܣ�������ַ���error���������������

��������
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5
�������
11 22 33 44 55 66 
11 22 777 33 44 55 66 
888 11 22 777 33 44 55 66 
11 22 777 33 44 55 66 
error
error
44*/