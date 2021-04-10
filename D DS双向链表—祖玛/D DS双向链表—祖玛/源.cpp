#include<iostream>
using namespace std;
class ListNode
{
public:
	ListNode* front;
	char data;
	ListNode* next;
	ListNode()
	{
		front = this;
		next = this;
		data = 0;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	void LL_add(char x);
	ListNode* LL_index(int i);
	void LL_insert(int i, char item);
	void LL_del(int i);
	void zm_del(int i);
	void LL_display();
	void eliminate();
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
//��˫������ĩβ���һ�����
void LinkList::LL_add(char x)
{
	ListNode* l = new ListNode();
	l->data = x;
	l->next = head;
	if (head->next == head)
	{
		l->front = head;
		head->next = l;
		head->front = l;
	}
	else
	{
		l->front = LL_index(len);
		LL_index(len)->next = l;
		head->front = l;
	}
	len++;
}
//���ص�i�����
ListNode* LinkList::LL_index(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "index_error" << endl;
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
//ɾ��˫�������еĵ�i�����
void LinkList::LL_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "del_error" << endl;
	}
	else
	{
		if (i == 1)
		{
			if (len == 1)
			{
				head->next = head;
				head->front = head;
			}
			else
			{
				head->next = LL_index(2);
				LL_index(2)->front = head;
			}
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i)->front = LL_index(i - 1);
		}
		len--;
	}
}
void LinkList::zm_del(int i)
{
	if ((i <= 0) || (i > len))
	{
		cout << "error" << endl;
	}
	else
	{
		if (i == 1)
		{
			head->next = LL_index(2);
			LL_index(2)->front = head;
		}
		else if (i == len)
		{
			LL_index(i - 1)->next = head;
			head->front = LL_index(i - 1);
		}
		else
		{
			LL_index(i - 1)->next = LL_index(i + 1);
			LL_index(i + 1)->front = LL_index(i - 1);
		}
		len--;
	}
}
//��item����˫������ĵ�i�����
void LinkList::LL_insert(int i, char item)
{
	if (i == len)
	{
		LL_add(item);
	}
	else if (i == 1)
	{
		if (len == 0)
		{
			LL_add(item);
		}
		else
		{
			ListNode* l = new ListNode();
			l->data = item;
			l->front = head;
			l->next = LL_index(1);
			LL_index(1)->front = l;
			head->next = l;
			len++;
		}
	}
	else
	{
		ListNode* l = new ListNode();
		l->data = item;
		l->next = LL_index(i);
		LL_index(i)->front = l;
		LL_index(i - 1)->next = l;
		l->front = LL_index(i - 1);
		len++;
	}
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head;
	if (p->next == head)
	{
		cout << "-";
	}
	while (p->next != head)
	{
		p = p->next;
		cout << p->data;
	}
	cout << endl;
}
void LinkList::eliminate()
{
	if (len<3)
	{
		return;
	}
	else
	{
		ListNode* p;
		int k = 1;
		while (k != 0)
		{
			if (len < 3)
				break;
			for (int i = 2; i <= len - 1; i++)
			{
				k = 0;
				p = LL_index(i);
				//cout << p->front->data << " " << p->data << " " << p->next->data << endl;
				//LL_display();
				if ((p->front->data == p->data) && (p->next->data == p->data))
				{
					//LL_display();
					//cout << "i=" << i << endl;
					//cout << p->front->data << " " << p->data << " " << p->next->data << endl;
					if (p->next->next->data == p->data)
					{
						LL_del(i);
						if(p->next->next->next->data==p->data)
							LL_del(i);
					}
					LL_del(i);
					LL_del(i);
					LL_del(i - 1);
					k = 1;
					break;
				}
			}
		}
	}
}
int main()
{
	string z;
	cin >> z;
	LinkList p;
	for (int i = 0; i < z.length(); i++)
	{
		p.LL_add(z[i]);
	}
	int n;
	cin >> n;
	int m;
	char c;
	while (n--)
	{
		cin >> m >> c;
		p.LL_insert(m+1, c);
		p.eliminate();
		p.LL_display();
	}
}
/*��Ŀ����
������һ����������ȫ�����Ϸ�����淨�ǣ���һ������ϳ�ʼ���������ɸ���ɫ���ӣ����������������ڵ����Ӳ�����ȫͬɫ���˺�����Է������ӵ�����ϲ�����ԭ�������С�һ�������������ͬɫ�����ӱ�����ڣ����Ǿͻ�������ʧ����������������ܻ�����ʽ����������㽫��ʱ���ܷ������ӡ�
��������ϳ�ʼ���������У�Ȼ�������������һϵ�в�������������ǣ��ڸ��β���֮��ʱ������µ��������С�
����
��һ����һ���ɴ�д��ĸ'A'~'Z'��ɵ��ַ�������ʾ����ϳ�ʼ���������У���ͬ����ĸ��ʾ��ͬ����ɫ��

�ڶ�����һ������n����ʾ��ҹ���n�β�����

��������n�����ζ�Ӧ�ڸ��β�����ÿ�β�����һ������k��һ����д��ĸ�������Կո�ָ������У���д��ĸΪ�����ӵ���ɫ��������ǰ����m�����ӣ�λ��0��m-1����k �� [0, m]��ʾ������Ƕ���ڹ���ϵ�λ�á�

���
 �����n�У����θ������β������������漴��������������֮�����ϵ��������С�

����������û�����ӣ����ԡ�-����ʾ��

��������
ACCBA
5
1 B
0 A
2 B
4 C
0 A
�������
ABCCBA
AABCCBA
AABBCCBA
-
A*/