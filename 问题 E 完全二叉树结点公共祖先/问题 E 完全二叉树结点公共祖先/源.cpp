#include<iostream>
#include<cmath>
using namespace std;
//Ѱ��˳��洢����ȫ�����������������������
int LCA(int a,int b)
{
	//�������������
	int ka = (int)log2(a) + 1;
	int kb = (int)log2(b) + 1;
	
	if (ka == kb)//�������ͬһ��
	{
		int pa = a;
		int pb = b;
		while (pa!=pb)
		{
			pa = pa / 2;
			pb = pb / 2;
		}
		return pa;
	}
	else//������ڲ�ͬ��
	{
		int pa = a;
		int pb = b;
		if (ka > kb)
		{
			for (int i = 0; i < ka - kb; i++)
			{
				pa = pa / 2;
			}

			if (pa == pb)
				return pa;

			while (pa != pb)
			{
				pa = pa / 2;
				pb = pb / 2;
			}
			return pa;
		}
		else if (ka < kb)
		{
			for (int i = 0; i < kb - ka; i++)
			{
				pb = pb / 2;
			}

			if (pa == pb)
				return pa;

			while (pa != pb)
			{
				pa = pa / 2;
				pb = pb / 2;
			}
			return pa;
		}
	}
}
int main()
{
	int i;
	int j;
	while (cin >> i >> j)
	{
		cout << LCA(i, j) << endl;
	}
}
/*
��Ŀ����
һ��˳��洢����ȫ��������

������������ı�ţ������������Ĺ������ȡ�
����
ÿ������һ�У�Ϊ�ո������������i��j����Ϊ32λ�з���������
���
ÿ�����ݶ�Ӧһ�У�Ϊ������������������������ȵı��
��������
4 5
4 7
�������
2
1
��ʾ

*/