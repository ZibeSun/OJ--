#include<iostream>
using namespace std;
int string_repeat(string str)
{
	string s;
	int result = -1;
	for (int i = 0; i < str.length(); i++)
	{
		for (int k = i+1; k < str.length(); k++)
		{
			s = str.substr(i, k);
			if (str.find(s, k) != -1)
			{
				if (result == -1)
				{
					result = s.length();
				}
				else
				{
					if (result < s.length())
					{
						result = s.length();
						/*cout << "i=" << i << "k=" << k << endl;
						cout << "str.find(s,i)=" << str.find(s, i) << endl;
						cout << s << endl;*/
					}
				}
			}
		}
	}
	return result;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		cout << string_repeat(str) << endl;
	}
}
/*��Ŀ����

�󴮵���ظ��Ӵ����ȣ��Ӵ����ص��������磺abcaefabcabc����ظ��Ӵ��Ǵ�abca������Ϊ4��

����

���Դ���t

t�����Դ�

���

��ÿ�����Դ��������ظ��Ӵ����ȣ���û���ظ��Ӵ������-1.

��������

3
abcaefabcabc
szu0123szu
szuabcefg
�������

4
3
-1
��ʾ*/