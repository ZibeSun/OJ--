#include<iostream>
#include<cstring>
using namespace std;
int SpecialLanguage(string str, string str1)
{
	int num = 0;
	int len = str.length();
	int len1 = str1.length();
	for (int i = 0; i <= len-len1; i+=2)
	{
		if (str.substr(i, len1).compare(str1) == 0)
			num++;
	}
	return num;
}
int main()
{
	string str;
	string str1;
	while (cin >> str >> str1)
	{
		cout << SpecialLanguage(str, str1) << endl;
	}
}
/*
��Ŀ����
ĳ�ǰ�����ԣ�ÿ��������������ĸ���ɵġ�����ѧ�ҷ��ְ����ǵ��������ֻ�֮�󣬵��������ض��ľ���ʱ���ܻ�ƥ�䵽����ĵط���

����һ�������� aabcdaabcdef����Ҫ���� abcd��Ӧ���ѵ����� aabcda abcd ef ��ȴ��õ������һ���������ϸ������﷨�Ľ�� a abcd aabcdef����Ϊÿ�����������ַ���ɣ�����ƥ��Ͱ���ȷ�ġ��֡����ˣ���

�������ʵ����ȷ��ƥ���㷨��

����
ÿ���������У���һ��Ϊ�����Ե��������ڶ���Ϊģʽ�������ɴ�д��СдӢ����ĸ��ɣ����ȶ������� 10000����һ��Ϊż������

���
ÿ�����������ȷƥ��Ĵ���

��������
abcdaabbab
ab
AbdcAbdcAbqAbdcAbdcAbp
AbdcAb
�������
2
2
��ʾ

*/