#include<iostream>
#include<stack>
using namespace std;
void del(stack<char> &s)
{
	s.pop();
	int n = 1;
	if (s.empty() != true)
	{
		while (s.top() == '#')
		{
			n++;
			s.pop();
			if (s.empty() == true)
				break;
		}
		for (int i = 0; i < n; i++)
		{
			if (s.empty() != true)
			{
				if (s.top() == '#')
					del(s);
				else
					s.pop();
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		int len;
		cin >> str;
		len = str.length();
		stack<char> s;
		stack<char> ss;     //���ڴ洢��������������ַ���
		for (int i = 0; i < len; i++)
		{
			s.push(str[i]);
		}
		while (s.empty() != true)
		{
			if (s.top() == '#')
			{
				/*s.pop();
				int n = 1;
				while (s.top() == '#')
				{
					n++;
					s.pop();
					if (s.empty() == true)
						break;
				}
				for (int i = 0; i < n; i++)
				{
					if (s.empty() != true)
					{
						if (s.top() == '#')
						{
							s.pop();
							int n = 1;
							while (s.top() == '#')
							{
								n++;
								s.pop();
								if (s.empty() == true)
									break;
							}
							for (int i = 0; i < n; i++)
							{
								if (s.empty() != true)
									s.pop();
								else
									break;
							}
						}
						else
						{
							s.pop();
						}
					}
					else
						break;
				}*/
				del(s);
			}
			else
			{
				ss.push(s.top());
				s.pop();
			}
		}
		if (ss.empty() == true)
			cout << "NULL" << endl;
		else
		{
			while (ss.empty() != true)
			{
				cout << ss.top();
				ss.pop();
			}
			cout << endl;
		}
	}
	return 0;
}
/*��Ŀ����
ʹ��C++��STL��ջ���󣬱�д����ʵ���б༭���ܡ��б༭�����ǣ�������#�ַ�����ִ���˸������������ַ����˾Ͳ����������ᱨ��

������Ĭ�ϲ�����ʾ#�ַ�����������������#��ʾ����ִ�ж���˸����

ÿ����һ���ַ���س����ʾ�ַ�������

ע�⣺����ʹ�ö�ջʵ�֣����ҽ���������������

����
��һ������һ������t����ʾ��t���ַ���Ҫ����
�ڶ���������һ���ַ�����������t��

���
ÿ��������մ����Ľ�������һ��������ַ������������û���ַ��������ֱ�����NULL

��������
4
chinaa#
sb#zb#u
##shen###zhen###
chi##a#####
�������
china
szu
sz
NULL*/