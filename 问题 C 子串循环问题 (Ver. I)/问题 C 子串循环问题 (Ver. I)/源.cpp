#include<iostream>
using namespace std;
int string_loop(string str)
{
	string loop;
	for (int i = 1; i < str.length(); i++)
	{
		//����������һ�������ַ���ͬ���ַ�ʱ
		if (str[i] == str[0])
		{
			//�����ַ����������ַ��ܷ񹹳���ǰ��һ�����ַ���
			loop = str.substr(0, i);
			//ѭ��������޷�����ѭ���Ӵ�Ϊֹ
			while (1)
			{
				if (str.find(loop, i) == -1)
				{
					int j;
					if (str.length() - i < loop.length())
					{
						for (j=i; j < str.length(); j++)
						{
							if (str[j] != loop[j - i])
							{
								break;
							}
						}
						if (j == str.length())
						{
							return loop.length() - str.length() + i;
						}
						else
						{
							loop = "";
							break;
						}
					}
					else
					{
						loop = "";
						break;
					}
				}
				else if (str.find(loop, i) != i)
				{
					break;
				}
				else
				{
					if (i == str.length() - loop.length())
					{
						return 0;
					}
					else
					{
						i += loop.length();
					}
				}
			}
		}
	}
	if (loop == "")
		return str.length();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		cout << string_loop(str) << endl;
	}
}
/*��Ŀ����

����һ���ַ���������Ҫ������ټ����ַ����ַ���ĩβ����ʹ�������ַ�������ĳһ����Ϊ������Ӵ�ѭ�����ɣ�
��"abca"�����"bc"�󹹳�"abcabc"�������Ӵ�"abc"ѭ������;Ҳ�������"abca"�󹹳�"abcaabca"�������Ӵ�"abca"ѭ�����ɣ����֮��"bc"ֻ��2���ַ�����ӵ��ַ������١�

����

��һ�а���һ������T(1 <= T <= 100)�������������

ÿ��������ݰ���һ���ַ������䳤�ȷ�ΧΪ [3, 104]

���

����ÿ���������

���һ������N��������ӵ���С�ַ�����

��������

5
aaa
abca
abcdefg
abcabcabca
qweaqwec
�������

0
2
7
2
8*/