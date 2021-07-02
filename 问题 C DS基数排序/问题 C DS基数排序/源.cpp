#include<iostream>
using namespace std;
class RadixSort
{
private:
	int* data;
	int len;
	//�����ݵ����λ��
	int maxbit()
	{
		int maxData = data[0];
		for (int i = 1; i < len; i++)
		{
			if (maxData < data[i])
				maxData = data[i];
		}
		int d = 1;
		while (maxData >= 10)
		{
			maxData /= 10;
			d++;
		}
		return d;
	}
	void Sort()
	{
		int d = maxbit();
		int* temp = new int[len];
		int* count = new int[10];//������
		int** arr = new int*[10];
		int radix = 1;
		int j, k, h;
		for (int i = 1; i <= d; i++)
		{
			for (j = 0; j < 10; j++)
				count[j] = 0;//ÿ�η���ǰ��ռ�����

			for (j = 0; j < 10; j++)
			{
				arr[j] = NULL;
			}

			for (j = 0; j < len; j++)
			{
				k = (data[j] / radix) % 10;   //ͳ��ÿ��Ͱ�еļ�¼��
				if(arr[k]==NULL)
					arr[k] = new int[len];
				arr[k][count[k]] = data[j];
				count[k]++;
			}

			for (j = 0; j < 10; j++)
			{
				cout << j << ":";
				if (arr[j] == NULL)
					cout << "NULL" << endl;
				else
				{
					cout << "->";
					for (h = 0; h < count[j]; h++)
						cout << arr[j][h] << "->";
					cout << "^" << endl;
				}
			}

			for (j = 1; j < 10; j++)
				count[j] = count[j - 1] + count[j];
			for (j = len - 1; j >= 0; j--)
			{
				k = (data[j] / radix) % 10;
				temp[count[k] - 1] = data[j];
				count[k]--;
			}
			for (j = 0; j < len; j++)
				data[j] = temp[j];
			radix *= 10;
			display();
		}
		delete[]temp;
		delete[]count;
	}
public:
	RadixSort(int* item,int n)
	{
		data = item;
		len = n;
		Sort();
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
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
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		RadixSort rs(item, n);
		cout << endl;
	}
}
/*
��Ŀ����
����һ�����ݣ�������л�����������
����
���Դ���t
ÿ���������һ�У����ָ���n�����n�����֣�������
���
��ÿ��������ݣ����ÿ�˷��䡢�ռ��Ľ�����������и�λû�����֣����NULL�����������ʽ��������ÿ��������ݼ��Կ��зָ���
��������
2
10 278 109 63 930 589 184 505 269 8 83
6 57 0 93 19 18 99
�������
0:->930->^
1:NULL
2:NULL
3:->63->83->^
4:->184->^
5:->505->^
6:NULL
7:NULL
8:->278->8->^
9:->109->589->269->^
930 63 83 184 505 278 8 109 589 269
0:->505->8->109->^
1:NULL
2:NULL
3:->930->^
4:NULL
5:NULL
6:->63->269->^
7:->278->^
8:->83->184->589->^
9:NULL
505 8 109 930 63 269 278 83 184 589
0:->8->63->83->^
1:->109->184->^
2:->269->278->^
3:NULL
4:NULL
5:->505->589->^
6:NULL
7:NULL
8:NULL
9:->930->^
8 63 83 109 184 269 278 505 589 930

0:->0->^
1:NULL
2:NULL
3:->93->^
4:NULL
5:NULL
6:NULL
7:->57->^
8:->18->^
9:->19->99->^
0 93 57 18 19 99
0:->0->^
1:->18->19->^
2:NULL
3:NULL
4:NULL
5:->57->^
6:NULL
7:NULL
8:NULL
9:->93->99->^
0 18 19 57 93 99
��ʾ

*/