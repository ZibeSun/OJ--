#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char x;
		int n;
		cin >> x;
		cin >> n;
		if (x == 'I')
		{
			int* p = new int[n];
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				sum += p[i];
			}
			cout << sum / n << endl;
		}
		else if (x == 'C')
		{
			char* p = new char[n];
			char max = 'A';
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				if (max < p[i])
					max = p[i];
			}
			cout << max << endl;
		}
		else if (x == 'F')
		{
			float* p = new float[n];
			float min = 99999;
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
				if (min > p[i])
					min = p[i];
			}
			cout << min << endl;
		}
	}
}
/*��Ŀ����
һ��ʼδ֪���鳤�ȣ�����Ҫ�󴴽���ͬ���͵�ָ�룬����ʹ��ָ�봴����Ӧ���ȵ����飬Ȼ������ɲ�ͬ��Ҫ��

��Ҫ�󴴽��������飬�����������������ݵ�ƽ��ֵ

��Ҫ�󴴽��ַ����飬�ҳ������ڵ������ĸ

��Ҫ�󴴽����������飬�ҳ��������Сֵ

Ҫ������������̲���ʹ�������±꣬�����鴴�������뵽�������Ƚϡ����㣬�����������ʹ��ָ��

��ʾ��ʹ��new�ؼ���

����
��һ������t��ʾ��t������ʵ��

�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�C��ʾ�ַ����ͣ�F��ʾ���������ͣ�Ȼ������n��ʾ���鳤�ȡ�

����������n������

��������t��ʵ��

���
ÿ�����ݲ�ͬ���������������Ӧ�Ľ��

��������
3
C 5
A D E B C
I 6
22 55 77 33 88 55
F 4
3.1 1.9 6.5 4.8
�������
E
55
1.9*/