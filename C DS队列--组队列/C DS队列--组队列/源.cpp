#include<iostream>
#include<queue>
using namespace std;
struct nums
{
	int len;
	int* p;
};
struct queue_num
{
	int number;
	int order;
};
int main()
{
	int t;
	cin >> t;
	nums* a = new nums[t];
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a[i].len = n;
		a[i].p = new int[n];
		for (int k = 0; k < a[i].len; k++)
		{
			cin >> a[i].p[k];
		}
	}
	string input;
	queue<queue_num> q[10];
	queue<queue_num> qq;
	for (int h = 0; h < 200; h++)
	{
		cin >> input;
		if (input == "ENQUEUE")
		{
			int x;
			cin >> x;
			queue_num y;
			for (int i = 0; i < t; i++)
			{
				for (int k = 0; k < a[i].len; k++)
				{
					if (x == a[i].p[k])
					{
						y.number = x;
						y.order = i;
					}
				}
			}
			if (q[0].empty() == true)
			{
				q[0].push(y);
			}
			else
			{
				int j = 0;
				for (int i = 0; i < 10; i++)
				{
					if (q[i].empty() != true)
					{
						if (q[i].front().order == y.order)
							q[i].push(y);
					}
					else if (q[i].empty() == true)
					{
						j = i;
						break;
					}
				}
				if (j != 0)
					q[j].push(y);
			}
		}
		else if (input == "DEQUEUE")
		{
			for (int i = 0; i < 10; i++)
			{
				if (q[i].empty() != true)
				{
					qq.push(q[i].front());
					q[i].pop();
					break;
				}
			}
		}
		else if (input == "STOP")
		{
			while (qq.empty() != true)
			{
				cout << qq.front().number << " ";
				qq.pop();
			}
			break;
		}
	}
	return 0;
}
/*��Ŀ����
������Ƕ��нṹ��һ�ֳ����Ķ��нṹ���ںܶ�ط����Ź㷺Ӧ�á����������ָ�����ڵ�Ԫ�ط���ۼ���һ������а����������

1�� ENQUEUE����ʾ�����µ�Ԫ�ؽ�����У����Ȼ�����Ƿ���ͬһ���Ԫ���Ѿ����ڣ�����У�����Ԫ������ͬ���������û����������ĩβ��

2�� DEQUEUE����ʾ����ͷԪ�س���

3�� STOP��ֹͣ����

����ʹ��C++�Դ��Ķ��ж���queue����̸�����

����
��1������һ��t(t<=10)����ʾ1���������ж��ٸ���

��2������һ����1���Ԫ�ظ�������ֵ

��3������һ����2���Ԫ�ظ�������ֵ

�Դ�����������t���Զ���ͬ��Ԫ��֮�󣬿�ʼ��������������(<200)���Կյ�����н��в�������������ENQUEUE 100����ʾ��Ԫ��100�������

���
DEQUEUE���ӵ�Ԫ��

��������
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
STOP
�������
101 102 103
��ʾ
 3 101 102 103
 3 201 202 203
 3 301 302 303 
 ENQUEUE 201  ==>>> | 201 |
 ENQUEUE 301  ==>>> | 201 | 301 |
 ENQUEUE 102  ==>>> | 201 | 301 | 102 |
 ENQUEUE 101  ==>>> | 201 | 301 | 102 101 |
 ENQUEUE 203  ==>>> | 201 203 | 301 | 102 101 |
 ENQUEUE 302  ==>>> | 201 203 | 301 302 | 102 101 |






���Կ������з��飬����ӵ����ڶ����п�ǰ������Ҳ��ǰ��



DEQUEUE ��� 201�����б�Ϊ | 203 | 301 302 | 102 101 | ��*/