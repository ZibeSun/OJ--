#include<iostream>
#include<stdio.h>
using namespace std;
class Matrix
{
protected:
	int m;
	int n;
	int** data;
	int** transdata;
public:
	Matrix(int x, int y)
	{
		m = x;
		n = y;
		data = new int * [m];			  //�ȴ���m��
		for (int i = 0; i < m; i++)
		{
			data[i] = new int[n];       //�ٴ���n��
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
		transdata = new int * [n];			  //�ȴ���m��
		for (int i = 0; i < n; i++)
		{
			transdata[i] = new int[m];       //�ٴ���n��
		}
	}
	~Matrix()
	{
		delete[] data;
	}
	void leftturn()     //������ת
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				transdata[i][j] = data[j][i];
		}
		for (int i = 0; i < (n/2); i++)
		{
			for (int j = 0; j < m; j++)
			{
				int p;
				p = transdata[i][j];
				transdata[i][j] = transdata[n - i-1][j];
				transdata[n - i-1][j] = p;
			}
		}
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << transdata[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Matrix a(2, 3);
		a.leftturn();
		a.show();
	}
}
/*��Ŀ����
����һ��2*3�ľ��󣬽��������������ת90�Ⱥ����

����������2*3���� ��

1 2 3

4 5 6 

������ת90�Ⱥ�ľ����Ϊ��

3 6

2 5

1 4

Ҫ�󣺳��˾��󴴽��������������ʹ������������±�ķ������������̶Ծ�����κη��ʶ�����ʹ��ָ��

��ʾ��m��n�еĶ�ά���󣬵�i�е�j�е�Ԫ������Ԫ�صľ���Ϊi*n+j����Ŵ�0��ʼ����

����
��һ������t��ʾ��t������ʵ��

������������һ��2*3�ľ��������

��������t��ʵ��

���
���������ת��ľ�����

�������ÿ���У�ÿ������֮�䶼�ÿո���������һ�����ݺ���Ҳ���пո�

��������
2
1 2 3
4 5 6
4 5 6
7 8 9
�������
3 6 
2 5 
1 4 
6 9 
5 8 
4 7 */