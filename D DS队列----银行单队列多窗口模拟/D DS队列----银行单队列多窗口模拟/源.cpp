#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
struct customer
{
	int T;
	int P;
	double WT;
};
int main()
{
	int n;
	cin >> n;
	customer* c = new customer[n];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].T;
		cin >> c[i].P;
		c[i].WT = 999;
	}
	int k;
	cin >> k;
	int* w = new int[k];
	for (int j = 0; j < k; j++)
	{
		w[j] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (w[j] <= c[i].T)
			{
				if (w[j] == 0)
					w[j] += c[i].P + c[i].T;
				else
					w[j] = c[i].P + c[i].T;
				c[i].WT = 0;
				break;
			}
		}
		if (c[i].WT == 999)
		{
			int* nwt = new int[k];
			for (int j = 0; j < k; j++)
			{
				nwt[j] = w[j] - c[i].T;
			}
			int min;
			int h;
			min = nwt[0];
			h = 0;
			for (int j = 0; j < k; j++)
			{
				if (min > nwt[j])
				{
					min = nwt[j];
					h = j;
				}
			}
			c[i].WT = w[h] - c[i].T;
			w[h] += c[i].P;
		}
	}
	double sum = 0;
	int maxt = 0;
	for (int i = 0; i < n; i++)
	{
		sum += c[i].WT;
		if (maxt < c[i].WT)
			maxt = c[i].WT;
	}
	double at;
	at = sum / n;
	int finalt = 0;
	for (int j = 0; j < k; j++)
	{
		if (finalt < w[j])
			finalt = w[j];
	}
	cout << fixed << setprecision(1) << at << " ";
	cout << maxt << " " << finalt << endl;
}
/*��Ŀ����
����������K�������ṩ���񣬴���ǰ��һ�����ߣ����й˿Ͱ�����ʱ���ڻ��ߺ��ų�һ�����������д��ڿ���ʱ����һλ�˿ͼ�ȥ�ô��ڴ������񡣵��ж�����ڿ�ѡ��ʱ������˿�����ѡ������С�Ĵ��ڡ�

����Ҫ�����ǰ���ȴ������Nλ�˿͵�ƽ���ȴ�ʱ�䡢��ȴ�ʱ�䡢������ʱ�䡣

����
�����1�и���������N����1000����Ϊ�˿������������N�У�ÿ�и���һλ�˿͵ĵ���ʱ��T��������ʱ��P�����Ҽ������������Ѿ�������ʱ���Ⱥ��ź���˳�����һ�и���������K����10����Ϊ�����Ӫҵ��������

���
��һ�������ƽ���ȴ�ʱ�䣨�����С�����1λ������ȴ�ʱ�䡢������ʱ�䣬֮����1���ո�ָ�����ĩ�����ж���ո�

��������
9
0 20
1 15
1 61
2 10
10 5
10 3
30 18
31 25
31 2
3
�������
6.2 17 62*/