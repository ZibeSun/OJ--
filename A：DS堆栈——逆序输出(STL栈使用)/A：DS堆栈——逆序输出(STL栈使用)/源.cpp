#include<iostream>
#include<stack>
using namespace std;
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
		char c1;
		for (int i = 0; i < len; i++)
		{
			c1 = str[i];
			s.push(c1);
		}
		char c2;
		while (s.empty() != true)
		{
			c2 = s.top();
			cout << c2;
			s.pop();
		}
		cout << endl;
	}
	return 0;
}
/*��Ŀ����
C++���Ѿ��Դ���ջ����stack�������д��ջ�����ľ���ʵ�ִ��롣

����Ŀ��Ҫ���������Ϥstack�����ʹ�ã�Ȼ��ʵ���ַ������������

����һ���ַ��������ַ�������˳��ѹ���ջ��Ȼ����ݶ�ջ����ȳ����ص㣬���������

stack��ʹ�õĲο�����

n����ͷ�ļ�<stack>  ��  #include <stack>

n����һ����ջ����s��ע��stack��ģ���ࣩ��stack <char>  s; //��ջ�������������ַ���
n��һ���ַ�ctѹ���ջ�� s.push(ct);
n��ջ��Ԫ�ص�����s.pop();
n��ȡջ��Ԫ�أ��������c2�� c2 = s.top();
n�ж϶�ջ�Ƿ�գ� s.empty()�����Ϊ����������true����������򷵻�false
����
��һ������t����ʾ��t������ʵ��
�ڶ���ÿһ������һ���ַ�����ע���ַ�����Ҫ�����ո�

�ַ�����������Կ���һ�´��룺

#include <string>

int main()

{ string str;

  Int len;

  cin>>str; //��������ַ��������ڱ���str��

  len = str.length()  //��ȡ�����ַ����ĳ���

}

���
ÿ���������ÿһ���ַ���

��������
2
abcdef
aabbcc
�������
fedcba
ccbbaa*/