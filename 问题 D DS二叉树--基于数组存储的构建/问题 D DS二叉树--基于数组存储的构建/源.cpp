/*#include<iostream>
using namespace std;
//�ݹ��������˳������洢�Ķ�����
void PreOrder(int i, string str, int len)
{
	if (i < len)
	{
		if (str[i] != '0')
		{
			cout << str[i];
			PreOrder(2 * i + 1, str, len);
			PreOrder(2 * i + 2, str, len);
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
		cin >> str;
		PreOrder(0, str, str.length());
		cout << endl;
	}
	return 0;
}
/*
��Ŀ����
������������Ը�����ȫ���������ʱ�����һ�������С���֪������������洢���ó��򹹽��ö�������
��ʾ���õݹ鷽����ǵݹ鶼����
�ݹ鷽���Ĵ��������£�


����
��һ������һ������t����ʾ��t����������
�ڶ��������������������洢������������ַ���0����ʾ������t��
����������ɴ�д��ĸ��0��ʾ
���
�������ÿ����������������
��������
3
ABC0D
ABCDEF000G
ABEC0F0D0
�������
ABDC
ABDEGCF
ABCDEF

*/