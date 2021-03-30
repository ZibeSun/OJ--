#include<iostream>
#include<stack>
using namespace std;
struct InPut
{
	int number;
	char op;
};
int getnumber(char c)
{
	if (c == '0')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
}
//�ж�������Ƿ�Ϊ����
bool JudgeNumber(char c)
{
	if ((c >= '0') && (c <= '9'))
		return true;
	else
		return false;
}
//�ж�������Ƿ�Ϊ�����
bool JudgeOP(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/')|| (c == '(') || (c == ')'))
		return true;
	else
		return false;
}
//�Ƚ�������������ȼ�
//�������c1�����ȼ��ϸ��򷵻�true�����򷵻�false
//������k��ʾҪ��������ת����������Ƚ�
//k=1������ʽת���Ƚ�
//k!=1���沨��ʽת���Ƚ�
bool CompareLevel(char c1,char c2,int k)
{
	if (c1 == '+')
	{
		if (c2 == '+')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '-')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
	else if (c1 == '-')
	{
		if (c2 == '+')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '-')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '*')
		{
			return false;
		}
		else if (c2 == '/')
		{
			return false;
		}
	}
	else if (c1 == '*')
	{
		if (c2 == '+')
		{
			return true;
		}
		else if (c2 == '-')
		{
			return true;
		}
		else if (c2 == '*')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '/')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
	}
	else if (c1 == '/')
	{
		if (c2 == '+')
		{
			return true;
		}
		else if (c2 == '-')
		{
			return true;
		}
		else if (c2 == '*')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
		else if (c2 == '/')
		{
			if (k == 1)
				return false;
			else
				return true;
		}
	}
}
//����ʽת��
void PNchange(InPut* input,int len)
{
	stack<InPut> output;
	stack<InPut> OPTR;
	//�Ӻ���ǰ��ʼɨ����ʽ
	for (int i = 0; i < len; i++)
	{
		//��ɨ�赽��input[i]�ǲ�����
		if ((input[i].number != -999) && (input[i].op == 'N'))
		{
			output.push(input[i]);
		}
		//��ɨ�赽��input[i]�Ǳ�����')'
		if ((input[i].number == -999) && (input[i].op == ')'))
		{
			OPTR.push(input[i]);
		}
		//��ɨ�赽��input[i]�������
		if ((input[i].number == -999) && (input[i].op != 'N') && (input[i].op != '(') && (input[i].op != ')'))
		{
			if (OPTR.empty() == true)
			{
				OPTR.push(input[i]);
			}
			else
			{
				if ((OPTR.top().op == ')') || (CompareLevel(OPTR.top().op, input[i].op,1) == false))
				{
					OPTR.push(input[i]);
				}
				else
				{
					output.push(OPTR.top());
					OPTR.pop();
					i--;
					continue;
				}
			}
		}
		//��ɨ�赽��input[i]�ǿ�����'('
		if ((input[i].number == -999) && (input[i].op == '('))
		{
			while (OPTR.top().op != ')')
			{
				output.push(OPTR.top());
				OPTR.pop();
				if (OPTR.empty() == true)
					break;
			}
			if (OPTR.empty() != true)
			{
				if(OPTR.top().op == ')')
					OPTR.pop();
			}
		}
	}
	//��ɨ������������ջ��Ϊ��
	if (OPTR.empty() != true)
	{
		while (OPTR.empty() != true)
		{
			output.push(OPTR.top());
			OPTR.pop();
		}
	}
	//������
	int k = 0;
	while (output.empty() != true)
	{
		if (k == 0)
		{
			if ((output.top().number != -999) && (output.top().op == 'N'))
				cout << output.top().number;
			else if ((output.top().number == -999) && (output.top().op != 'N'))
				cout << output.top().op;
			output.pop();
			k++;
		}
		else
		{
			if ((output.top().number != -999) && (output.top().op == 'N'))
				cout << " " << output.top().number;
			else if ((output.top().number == -999) && (output.top().op != 'N'))
				cout << " " << output.top().op;
			output.pop();
		}
	}
	cout << endl;
}
//�沨��ʽת��
void RPNchange(InPut* input, int len)
{
	stack<InPut> output;
	stack<InPut> OPTR;
	//��ǰ����ʼɨ����ʽ
	for (int i = len - 1; i >= 0; i--)
	{
		//��ɨ�赽��input[i]�ǲ�����
		if ((input[i].number != -999) && (input[i].op == 'N'))
		{
			output.push(input[i]);
		}
		//��ɨ�赽��input[i]�ǿ�����'('
		if ((input[i].number == -999) && (input[i].op == '('))
		{
			OPTR.push(input[i]);
		}
		//��ɨ�赽��input[i]�������
		if ((input[i].number == -999) && (input[i].op != 'N') && (input[i].op != '(') && (input[i].op != ')'))
		{
			if (OPTR.empty() == true)
			{
				OPTR.push(input[i]);
			}
			else
			{
				if ((OPTR.top().op == '(') || (CompareLevel(OPTR.top().op, input[i].op, 2) == false))
				{
					OPTR.push(input[i]);
				}
				else
				{
					output.push(OPTR.top());
					OPTR.pop();
					i++;
					continue;
				}
			}
		}
		//��ɨ�赽��input[i]�Ǳ�����')'
		if ((input[i].number == -999) && (input[i].op == ')'))
		{
			while (OPTR.top().op != '(')
			{
				output.push(OPTR.top());
				OPTR.pop();
				if (OPTR.empty() == true)
					break;
			}
			if(OPTR.empty() != true)
				OPTR.pop();
		}
	}
	//��ɨ������������ջ��Ϊ��
	if (OPTR.empty() != true)
	{
		while (OPTR.empty() != true)
		{
			output.push(OPTR.top());
			OPTR.pop();
		}
	}
	//������
	stack<InPut> output1;
	while (output.empty() != true)
	{
		output1.push(output.top());
		output.pop();
	}
	int k = 0;
	while (output1.empty() != true)
	{
		if (k == 0)
		{
			if ((output1.top().number != -999) && (output1.top().op == 'N'))
				cout << output1.top().number;
			else if ((output1.top().number == -999) && (output1.top().op != 'N'))
				cout << output1.top().op;
			output1.pop();
			k++;
		}
		else
		{
			if ((output1.top().number != -999) && (output1.top().op == 'N'))
				cout << " " << output1.top().number;
			else if ((output1.top().number == -999) && (output1.top().op != 'N'))
				cout << " " << output1.top().op;
			output1.pop();
		}
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		InPut* input = new InPut[100];
		string ip;
		cin >> ip;
		int n = 0;
		int k = 1;
		int j = 0;
		//�Ӻ���ǰ�����ʽipת����InPut�ṹ������
		for (int i = ip.length()-1; i >=0 ; i--)
		{
			n = 0;
			k = 1;
			while (JudgeNumber(ip[i]))
			{
				int sum = getnumber(ip[i]);
				for (int h = 1; h < k; h++)
					sum = sum * 10;
				n += sum;
				k++;
				if (i > 0)
					i--;
				else
					break;
			}
			if (k != 1)
			{
				input[j].number = n;
				input[j].op = 'N';
				j++;
			}
			if (JudgeOP(ip[i]))
			{
				input[j].op = ip[i];
				input[j].number = -999;
				j++;
			}
		}
		PNchange(input, j);
		RPNchange(input, j);
		cout << endl;
		delete[] input;
	}
}
/*��Ŀ����
       ���ʽ�����ֱ�ʾ�������ֱ�Ϊ��

    ǰ׺��ʾ(����ʽ)�������+������1+������2

    ��׺��ʾ��������1+�����+������2

    ��׺��ʾ(�沨��ʽ)��������1+������2+�����

    ���磺a +b * (c -d ) - e/f

    ����ʽ��-+a*b-cd/ef     ��������ڲ�������ǰ�棬�õݹ���㲨��ʽ��

    ��׺ʽ��a+b*c-d-e/f  

    �沨��ʽ��abcd-*+ef/   ��������ڲ������ĺ��棬��ջ�����沨��ʽ��

       ��׺��ʾ����ԭ���ʽȥ���ۺš�       

     ���ݱ��ʽ����ʽ���沨��ʽ���ǽ̲ĵ����±��ʽ��ֵ��˼�롣     

      ����ʽ����Ҫ������ջ(ע�ⲻ�Ǽ�������ջ���м���ʽ��ջ)�������ջ���������ڴӺ���ǰɨ����ʽ����(�� ����')','('���ɡ�)����ջ����������ȼ�>�¶�����������ȼ���ջ���̲ĵ����±�3.1�е���ͬ��������ȼ�>���������Ҽ��㣩��Ϊ<������ջ��Ϊ��+�����¶����Ϊ��+������ջ�����ȼ�<�¶�������ȼ���

     ���沨��ʽ��ֻ��Ҫ�����ջ��������ֱ�����������������3.1���ȼ�˳���ջ�������

       ������ʽ�����䲨��ʽ���沨��ʽ��

����
 ���Դ���

ÿ���������һ�У�һ���Ϸ����ʽ

���
 ��ÿ��������ݣ��������

��һ�У����ʽ�Ĳ�����ʾ

�ڶ��У����ʽ���沨����ʾ

��ͬ��������ݼ��Կ��зָ���

��������
2
4+2*3-10/5
12+3*5+(2+10)*5 
�������
- + 4 * 2 3 / 10 5
4 2 3 * + 10 5 / -

+ + 12 * 3 5 * + 2 10 5
12 3 5 * + 2 10 + 5 * +*/