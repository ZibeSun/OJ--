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
	void swap(int pa, int pb);
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
	if ((i <= 0) || (i > len + 1))
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
			for (int k = 1; k <= i - 1; k++)
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
void LinkList::swap(int pa, int pb)
{
	if ((pa != pb) && (pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = LL_index(pa);

		ListNode* q;
		q = LL_index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = LL_index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = LL_index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = LL_index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = LL_index(pa + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
		LL_display();
	}
	else
	{
		cout << "error" << endl;
	}
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
	int spa1, spb1, spa2, spb2;
	cin >> spa1 >> spb1;
	L.swap(spa1, spb1);
	cin >> spa2 >> spb2;
	L.swap(spa2, spb2);
	return 0;
}
/*��Ŀ����
��C++ʵ�ֺ�ͷ���ĵ�����Ȼ��ʵ�ֵ������������㽻��λ�á�

ע�ⲻ�ܼ򵥽����������������ݣ�����ͨ���޸�ָ����ʵ����������λ�ý���

��������������Բο���

swap��int  pa, int pb)  //pa��pb��ʾ��������ڵ������λ�����

swap (ListNode * p, ListNode * q)  //p��q��ʾָ����������ָ��

����
��1��������n��ʾ��n�����ݣ���������n������

��2������Ҫ�������������λ��

��3������Ҫ�������������λ��

���
��һ�����������������������ݣ�����֮���ÿո����

�ڶ������ִ�е�1�ν���������ĵ��������ݣ�����֮���ÿո����

���������ִ�е�2�ν���������ĵ��������ݣ�����֮���ÿո����

�����������λ�ò��Ϸ�������ַ���error���������������

��������
5 11 22 33 44 55
1 4
2 6
�������
11 22 33 44 55 
44 22 33 11 55 
error
��ʾ
ע��Ҫ������ʵ��Ŷ��*/