#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;
struct Double_sp
{
	int zs;
	double xs;
};
char getnumber(int i)
{
	if (i == 0)
		return '0';
	else if (i == 1)
		return '1';
	else if (i == 2)
		return '2';
	else if (i == 3)
		return '3';
	else if (i == 4)
		return '4';
	else if (i == 5)
		return '5';
	else if (i == 6)
		return '6';
	else if (i == 7)
		return '7';
	else if (i == 8)
		return '8';
	else if (i == 9)
		return '9';
	else if (i == 10)
		return 'A';
	else if (i == 11)
		return 'B';
	else if (i == 12)
		return 'C';
	else if (i == 13)
		return 'D';
	else if (i == 14)
		return 'E';
	else if (i == 15)
		return 'F';
}
Double_sp double_separate(double d)
{
	Double_sp d_sp;
	d_sp.zs = 0;
	d_sp.xs = 0;
	while (d >= 1)
	{
		d--;
		d_sp.zs++;
	}
	d_sp.xs = d;
	return d_sp;
}
void Transform(double d,int k)
{
	Double_sp dd;
	dd = double_separate(d);

	stack<char> zs;
	queue<char> xs;
	do
	{
		int num;
		num = dd.zs % k;
		dd.zs = dd.zs / k;
		zs.push(getnumber(num));
	} while (dd.zs != 0);
	while (zs.empty() != true)
	{
		cout << zs.top();
		zs.pop();
	}
	cout << ".";
	for(int i=0;i<3;i++)
	{
		dd.xs = double_separate(dd.xs).xs * k;
		xs.push(getnumber(double_separate(dd.xs).zs));
	}
	while (xs.empty() != true)
	{
		cout << xs.front();
		xs.pop();
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double d;
		int k;
		cin >> d >> k;
		Transform(d, k);
	}
	return 0;
}
/*��Ŀ����
��������ʮ������ת��Ϊk���ƣ������������ֺ�С������ת�����������ֲ��ó�k���෨��С�����ֲ��ó�kȡ��������x=19.125����2����ת��

��������19��					С������0.125
19 / 2 = 9 �� 1					0.125 * 2 = 0.25 �� 0
9 / 2 = 4 �� 1					0.25 * 2 = 0.5   �� 0
4 / 2 = 2 �� 0 					0.5 * 2 = 1     �� 1
2 / 2 = 1 �� 0
1 / 2 = 0 �� 1
������������תΪ 10011��С������תΪ0.001��������Ϊ10011.001

��ʾ�������ֿ��ö�ջ��С�����ֿ��ö���ʵ��

ע�⣺���밴������������ʵ������ת������������0��

����
��һ������һ��t����ʾ���潫��t��������ݡ�

������ÿ�а�����������n��k��n��ʾҪת������ֵ�������Ƿ�������k��ʾҪת�������ƣ�1<k<=16

���
����ÿһ��������ݣ�ÿ�����ת����Ľ����������ȵ�С�����3λ

���С�����λ�Ĵ������£�

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double r = 123.56789;
  cout<<fixed<<setprecision(4)<<r<<endl;   //���С�����4

 return 0;
}

��������
2
19.125 2
15.125 16
�������
10011.001
F.200
��ʾ
 ���磺ʮ������254.3879ת��Ϊ6��������


��������254��

254 / 6 = 42 ... 2

42 / 6 = 7 ... 0

7 / 6 = 1 ... 1

1 / 6 = 0 ... 1


С������0.3879��	

0.3879 * 6 = 2.3274   ...  2

0.3274 * 6 = 1.9644 ... 1

0.9644 * 6 = 5.7864 ... 5

������������תΪ 1102��С������תΪ0.215��ת�����6������������Ϊ1102.215
*/