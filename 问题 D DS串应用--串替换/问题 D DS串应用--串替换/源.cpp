#include<iostream>
using namespace std;
void get_next(string t, int* next)
{
	int i = 0, j = -1;
	next[i] = j;
	while (i < (int)t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int KMP(string s, string t)
{
	int i = 0, j = 0;
	int* next = new int[t.length() + 1];
	get_next(t, next);
	while (i < (int)s.length() && j < (int)t.length())
	{
		if (j == -1 || s[i] == t[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j == (int)t.length())
	{
		return i - j;
	}
	else
		return -1;
}
string string_replace(string str, string t, string rs)
{
	if (KMP(str, t) != -1)
	{
		str.replace(KMP(str, t), t.length(), rs);
	}
	return str;
}
/*
��ʹ��KMP����
string string_replace(string str, string t, string rs)
{
	if (str.find(t, 0) != -1)
	{
		str.replace(str.find(t, 0), t.length(), rs);
	}
	return str;
}
*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		string t;
		string rs;
		cin >> str >> t >> rs;
		cout << str << endl;
		cout << string_replace(str,t,rs) << endl;
	}
}
/*��Ŀ����

����������ģʽ�����滻������KMP�㷨�ҳ�ģʽ����������λ�ã�Ȼ�����滻�����ַ��滻��ģʽ��

����ֻ����һ���滻����������������������һЩ���ܹ�ʵ�ֶദ�滻��

������Ҫ����ģʽ�����滻�����Ȳ�һ�µ����

����

��һ������t����ʾ��t��ʵ��

�ڶ��������1��ʵ���������������������1��ʵ����ģʽ���������������1��ʵ�����滻��

�Դ�����

���

��һ�������1��ʵ��������

�ڶ��������1��ʵ���������滻���������û�з����滻���������ԭ�������ݡ�

�Դ�����

��������

3
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc
�������

aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
��ʾ*/