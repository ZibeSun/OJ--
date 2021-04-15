#include<iostream>
using namespace std;
void get_next(string t, int *next) 
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
	int *next=new int[t.length() + 1];
	get_next(t, next);

	for (int i = 0; i < t.length(); i++)
		cout << next[i] << " ";
	cout << endl;

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
		return i - j + 1;
	}
	else
		return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		string t;
		cin >> str >> t;
		cout << KMP(str, t) << endl;
	}
}
/*��Ŀ����
ѧϰKMP�㷨������������ģʽ������ģʽ����������λ��

�㷨������£������ο�

#include <iostream>
#include <string>
using namespace std;
class myString
{
private:
	string mainstr;      //��
	int size;                 //������

	void GetHext(string p, int next[]);
	int KMPFind(string p, int pos, int next[]);
public:
	myString();                //���캯��
	~myString();             //��������
	void SetUal(string sp);                 //�趨�����ַ����ݺͳ���
	int KMPFindSubstr(string p, int pos);
};
myString::myString()
{
	size = 0;
mainstr = "";
}
myString::~myString()
{
	size = 0;
	mainstr = "";
}
void myString::SetUal(string sp)
{
	mainstr = "";
	mainstr.assign(sp);
	size = mainstr.length();
}

int wyString::KMPFindSubstr(string p, int pos)
//�����д�pos��ʼ�����Ӵ�p���ҵ�����p�������Ŀ�ʼλ�ã����򷵻�-1
{
	int i;
	int L = p.length();
	int *next = new int[L];
	Gettlext(p, next);
	for (i=0; i<L; i++)
		cout<<next[i]<<' ';
	cout<<endl;
	int v = -1;
	v = KMPFind(p, pos, next);

	delete []next;

	return v;
}

����
��һ������t����ʾ��t��ʵ��

�ڶ��������1��ʵ���������������������1��ʵ����ģʽ��

�Դ�����

���
��һ�������1��ʵ����ģʽ����nextֵ

�ڶ��������1��ʵ����ƥ��λ�ã�λ�ô�1��ʼ���㣬���ƥ��ɹ����λ�ã�ƥ��ʧ�����0

�Դ�����

��������
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac
�������
-1 0 0 
5
-1 0 1 
0
-1 0 0 1 
8
��ʾ
 Ϊʲônextֵ�Ϳα��Ĳ�һ��������*/