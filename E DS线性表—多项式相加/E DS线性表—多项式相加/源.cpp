#include<iostream>
using namespace std;
class ListNode
{
public:
	int xishu;
	int zhishu;
	ListNode* next;
	ListNode()
	{
		xishu = 0;
		zhishu = 0;
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode* head;
	int len;
	LinkList();
	~LinkList();
	void display();
	ListNode* index(int i);
	void add_Node(int xs, int zs);
	void swap(int pa, int pb);
	void range();
	void del(int i);
	void clear();
	LinkList multinomial_add(LinkList& a,LinkList &b);
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
void LinkList::display()
{
	//clear();
	ListNode* p;
	p = head;
	for (int i = 1; i <= len; i++)
	{
		p = p->next;
		if (i == 1)
		{
			if (p->xishu != 0)
			{
				if (p->xishu < 0)
					cout << "(" << p->xishu << ")";
				else
					cout << p->xishu;
				if (p->zhishu != 0)
				{
					if (p->zhishu < 0)
						cout << "x^" << "(" << p->zhishu << ")";
					else
						cout << "x^" << p->zhishu;
				}
			}
		}
		else
		{
			if (p->xishu != 0)
			{
				if (p->xishu < 0)
					cout << " + " << "(" << p->xishu << ")";
				else
					cout << " + " << p->xishu;
				if (p->zhishu != 0)
				{
					if (p->zhishu < 0)
						cout << "x^" << "(" << p->zhishu << ")";
					else
						cout << "x^" << p->zhishu;
				}
			}
		}
	}
	cout << endl;
}
ListNode* LinkList::index(int i)
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
void LinkList::add_Node(int xs, int zs)
{
	ListNode* p = new ListNode();
	p->xishu = xs;
	p->zhishu = zs;
	if (head->next == NULL)
	{
		head->next = p;
	}
	else
	{
		index(len)->next = p;
	}
	len++;
	range();
}
void LinkList::swap(int pa, int pb)
{
	if ((((pa - pb) * (pa - pb)) > 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = index(pa);

		ListNode* q;
		q = index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
		}

		p_before->next = q;
		q->next = p_after;

		q_before->next = p;
		p->next = q_after;
	}
	else if ((((pa - pb) * (pa - pb)) == 1) &&
		(pa > 0) && (pa <= len) && (pb > 0) && (pb <= len))
	{
		ListNode* p;
		p = index(pa);

		ListNode* q;
		q = index(pb);

		ListNode* p_before;
		if (pa == 1)
		{
			p_before = head;
		}
		else
		{
			p_before = index(pa - 1);
		}

		ListNode* p_after;
		if (pa == len)
		{
			p_after = NULL;
		}
		else
		{
			p_after = index(pa + 1);
		}

		ListNode* q_before;
		if (pb == 1)
		{
			q_before = head;
		}
		else
		{
			q_before = index(pb - 1);
		}

		ListNode* q_after;
		if (pb == len)
		{
			q_after = NULL;
		}
		else
		{
			q_after = index(pb + 1);
		}

		p_before->next = q;
		q->next = p;
		p->next = q_after;
	}
	else
	{
		cout << "error" << endl;
	}
}
void LinkList::range()
{
	for (int i = 1; i <= len; i++)
	{
		for (int k = i; k <= len; k++)
		{
			if (index(i)->zhishu > index(k)->zhishu)
			{
				swap(i, k);
			}
		}
	}
}
void LinkList::del(int i)
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
	}
}
void LinkList::clear()
{
	int LLen = len;
	while (LLen--)
	{
		for (int i = 1; i <= len; i++)
		{
			if (index(i)->xishu == 0)
			{
				del(i);
				break;
			}
		}
	}
}
LinkList LinkList::multinomial_add(LinkList& a, LinkList& b)
{
	LinkList sum;
	ListNode* pa;
	ListNode* pb;
	pa = a.head;
	for (int i = 1; i <= a.len; i++)
	{
		pa = pa->next;
		pb = b.head;
		for (int k = 1; k <= b.len; k++)
		{
			pb = pb->next;
			if (pa->zhishu == pb->zhishu)
			{
				int xs, zs;
				xs = pa->xishu + pb->xishu;
				zs = pa->zhishu;
				sum.add_Node(xs, zs);
			}
		}
	}
	ListNode* ps;
	pa = a.head;
	for (int i = 1; i <= a.len; i++)
	{
		pa = pa->next;
		ps = sum.head;
		int xh = 0;
		for (int k = 1; k <= sum.len; k++)
		{
			ps = ps->next;
			if (pa->zhishu == ps->zhishu)
			{
				xh = 1;
				break;
			}
		}
		if (xh == 0)
			sum.add_Node(pa->xishu, pa->zhishu);
	}

	pb = b.head;
	for (int i = 1; i <= b.len; i++)
	{
		pb = pb->next;
		ps = sum.head;
		int xh = 0;
		for (int k = 1; k <= sum.len; k++)
		{
			ps = ps->next;
			if (pb->zhishu == ps->zhishu)
			{
				xh = 1;
				break;
			}
		}
		if (xh == 0)
			sum.add_Node(pb->xishu, pb->zhishu);
	}
	sum.clear();
	return sum;
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		LinkList a;
		for (int i = 0; i < n; i++)
		{
			int xs, zs;
			cin >> xs >> zs;
			a.add_Node(xs, zs);
		}
		a.display();

		int m;
		cin >> m;
		LinkList b;
		for (int i = 0; i < m; i++)
		{
			int xs, zs;
			cin >> xs >> zs;
			b.add_Node(xs, zs);
		}
		b.display();

		a.multinomial_add(a, b).display();
	}
	return 0;
}/*��Ŀ����
����һԪ����ʽ  p(x)=p0+p1x+p2x2+ �� +pnxn  ��ÿ�����ϵ����ָ�������֣�����p2x2��ϵ��Ϊp2,ָ��Ϊ2��

���ʵ����������ʽ����ӡ�

����5+x+2x2+3x3��-5-x+6x2+4x4��������ӽ����8x2+3x3+4x4

����ϵ��5��-5����x��0�η���ϵ������Ӻ�Ϊ0�����Բ���ʾ��x��1�η�ͬ����ʾ��

����˳��������ʵ�֡�

����
��1�У�����t��ʾ��t���������

��2�У�����n��ʾ�е�1��ĵ�1������ʽ����n����

��3�У������һ���ϵ����ָ�����Դ���������n��

��������m��ʾ��1��ĵ�2������ʽ����m��

ͬ�������2������ʽ��m�����ϵ����ָ��

�ο����������2�����ݣ��Դ���������t��

�����������ݶ�������

���
����ÿ1�����ݣ����������������ԭ���Ķ���ʽ������һ����������������ؿ��ǽ��ȫΪ0�����


�����ʽ�ο��������ݣ���ʽҪ�������

1.���ָ����ϵ���Ǹ�������С������������

2.���ϵ��Ϊ0�������������

3.���ָ����Ϊ0�����÷���^��ʾ������x��3�η�����ʾΪx^3��

4.����ʽ��ÿ����֮���÷���+���ӣ�ÿ��+���߼�1���ո������

��������
2
4
5 0
1 1
2 2
3 3
4
-5 0
-1 1
6 2
4 4
3
-3 0
-5 1
2 2
4
9 -1
2 0
3 1
-2 2
�������
5 + 1x^1 + 2x^2 + 3x^3
(-5) + (-1)x^1 + 6x^2 + 4x^4
8x^2 + 3x^3 + 4x^4
(-3) + (-5)x^1 + 2x^2
9x^(-1) + 2 + 3x^1 + (-2)x^2
9x^(-1) + (-1) + (-2)x^1
*/