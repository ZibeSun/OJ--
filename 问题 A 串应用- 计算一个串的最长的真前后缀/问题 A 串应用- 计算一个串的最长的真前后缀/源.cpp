#include<iostream>
using namespace std;
string matched_Prefix_Postfix(string str)
{
	string* f = new string[str.length() - 1];
	string* b = new string[str.length() - 1];
	for (int i = 0; i < str.length()-1; i++)
	{
		f[i] = str.substr(0, i + 1);
	}
	for (int i = str.length() - 1; i > 0; i--)
	{
		b[str.length() - i-1] = str.substr(i, str.length() - i);
	}
	string result;
	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int k = 0; k < str.length() - 1; k++)
		{
			if (f[i]==b[k])
			{
				if (result == "")
				{
					result = f[i];
				}
				else
				{
					if (f[i].length() > result.length())
					{
						result = f[i];
					}
				}
			}
		}
	}
	if (result == "")
	{
		return "empty";
	}
	else
	{
		return result;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		cout << matched_Prefix_Postfix(str) << endl;
	}
}
/*��Ŀ����

����һ��������ABCDAB���� ABCDAB����ǰ׺�У�{ A, AB,ABC, ABCD, ABCDA } ABCDAB�����׺�У�{ B, AB,DAB, CDAB, BCDAB } ��ˣ��ô�����ǰ׺�����׺�������ȴ�ΪAB�����ǳ�֮Ϊ�ô��ġ������ǰ��׺���� ��ʵ��һ������string matched_Prefix_Postfix(string str)���õ����봮str�������ǰ��׺���������������ǰ��׺�����empty
����

��1�У����ĸ��� n ��2�е���n+1�У�n���ַ���
���

n�������ǰ��׺���������������ǰ��׺�����empty��
��������

6
a
ab
abc
abcd
abcda
abcdab
�������

empty
empty
empty
empty
a
ab
��ʾ*/