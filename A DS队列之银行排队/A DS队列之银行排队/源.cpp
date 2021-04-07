#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n;
	cin >> n;
	queue<char> myQE;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		myQE.push(c);
	}
	int A_averange = 0;
	int B_averange = 0;
	int C_averange = 0;
	int A_number = 0;
	int B_number = 0;
	int C_number = 0;
	int itemp;
	for (int i = 0; i < n; i++)
	{
		cin >> itemp;
		if (myQE.front() == 'A')
		{
			A_averange += itemp;
			A_number++;
			myQE.pop();
		}
		else if (myQE.front() == 'B')
		{
			B_averange += itemp;
			B_number++;
			myQE.pop();
		}
		else if (myQE.front() == 'C')
		{
			C_averange += itemp;
			C_number++;
			myQE.pop();
		}
	}
	A_averange /= A_number;
	B_averange /= B_number;
	C_averange /= C_number;
	cout << A_averange << endl;
	cout << B_averange << endl;
	cout << C_averange << endl;
	return 0;
}/*��Ŀ����
������Ӫҵ����������3�ֿͻ�������ΪA\B\C�������ֱ�������3�����ڷֱ�������ֿͻ�����ÿ������ֻ����һ�ֿͻ�������һ���ͻ������а���ҵ��ÿ���ͻ��������ͺͰ���ҵ��ʱ�䡣ÿ�����ڰ��տͻ�������˳����з���

���ʵ�����ǵİ������̣���ʹ��C++�Դ���queue����ʹ�ö���ʵ�֣���������0�֣�

����queue���÷����£�

1.����ͷ�ļ���#include <queue>

2.����һ���������ж���queue<int>  myQe;

3.����һ���������ж������飺queue<int>  myQA[10]; 

4.��Ӳ�����myQe.push(itemp); //������itemp�������

5.���Ӳ�����myQe.pop();  //�Ѷ�ͷԪ�ص������У�ע�Ȿ��������ȡ��ͷԪ��

6.��ȡ��ͷԪ�أ� itemp = myQe.front(); // �Ѷ�ͷԪ�ط���itemp�У�ע�Ȿ����������Ԫ��

7.�ж϶����Ƿ�Ϊ�գ�myQe.empty();//���п��򷵻�true�������򷵻�false

����
��һ������������n��ʾ�ͻ�����

�ڶ�������ÿ���ͻ������ͣ�����֮�����ÿո����

����������ÿ���ͻ��İ���ʱ�䣬����֮�����ÿո����

���
��һ�����A��ͻ���ƽ������ʱ��

�ڶ������B��ͻ���ƽ������ʱ��

���������C��ͻ���ƽ������ʱ��



��������
8
A B C B C A A A
10 20 30 40 50 60 70 80
�������
55
30
40*/