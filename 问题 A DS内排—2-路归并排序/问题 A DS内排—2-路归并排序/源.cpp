#include<iostream>
#include<cmath>
using namespace std;
//2·�鲢����ѭ������
class MergeSort
{
private:
	string* item;
	int len;
	string* temp;
	//�鲢��������������
	void merge(int L1, int R1, int L2, int R2)
	{
		int i = L1;
		int j = L2;
		int t = 0;
		while (i <= R1 && j <= R2)
		{
			if (item[i].compare(item[j]) > 0)
				temp[t++] = item[i++];
			else
				temp[t++] = item[j++];
		}

		while (i <= R1)
		{
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= R2)
		{
			temp[t] = item[j];
			t++;
			j++;
		}

		for (int i = 0; i < t; i++)
			item[L1 + i] = temp[i];
	}
	void sort()
	{
		for (int step = 2; step / 2 <= len; step *= 2)
		{
			for (int i = 0; i <= len - 1; i += step)
			{
				int mid = i + step / 2 - 1;
				if (mid + 1 <= len - 1)
					merge(i, mid, mid + 1, min(i + step - 1, len - 1));
			}
			display();
		}
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
public:
	MergeSort(string* str, int n)
	{
		item = str;
		len = n;
		temp = new string[len];
		sort();
	}
};
int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		string* str = new string[n];
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		MergeSort ms(str, n);
		cout << endl;
	}
}
/*
��Ŀ����
����һ���ַ�������2-·�鲢�����ֵ�˳����н�������
����
 ���Դ���t
ÿ��������ݣ����ݸ���n�����n���ַ������ַ��������ո�
���
 ��ÿ��������ݣ����2-·�鲢�����ÿһ����������ÿ��������ݵ����֮����1���С�
��������
2
6 shenzhen beijing guangzhou futian nanshan baoan
10 apple pear peach grape cherry dew fig haw lemon marc


�������
shenzhen beijing guangzhou futian nanshan baoan
shenzhen guangzhou futian beijing nanshan baoan
shenzhen nanshan guangzhou futian beijing baoan

pear apple peach grape dew cherry haw fig marc lemon
pear peach grape apple haw fig dew cherry marc lemon
pear peach haw grape fig dew cherry apple marc lemon
pear peach marc lemon haw grape fig dew cherry apple
��ʾ

*/