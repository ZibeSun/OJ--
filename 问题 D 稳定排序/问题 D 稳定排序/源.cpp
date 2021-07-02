#include<iostream>
using namespace std;
//ֱ�Ӳ�������
void StraightInsertSort(int** item, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0; k--)
		{
			if (item[k][0] < item[k - 1][0])
			{
				int* m = item[k];
				item[k] = item[k - 1];
				item[k - 1] = m;
			}
			else
				break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << item[i][0] << " " << item[i][1] << endl;
	}
}
//2·�鲢���򣬵ݹ�����
class MergeSort
{
private:
	int* item;
	int* temp;
	int* item1;
	int len;
	int k;
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//��߹鲢����ʹ��������������
			sort(mid + 1, right);//�ұ߹鲢����ʹ��������������
			merge(left, mid, right);
		}
	}
	//�鲢
	void merge(int left, int mid, int right)
	{
		int i = left;//������ָ��
		int j = mid + 1;//������ָ��
		int t = 0;//��ʱ����ָ��
		while (i <= mid && j <= right)
		{
			if (item[i] < item[j])
			{
				temp[t] = item[i];
				t++;
				i++;
			}
			else
			{
				temp[t] = item[j];
				t++;
				j++;
			}
		}
		while (i <= mid)
		{
			//����������ʣ��Ԫ������temp��
			temp[t] = item[i];
			t++;
			i++;
		}
		while (j <= right)
		{
			//����������ʣ��Ԫ������temp��
			temp[t] = item[j];
			t++;
			j++;
		}
		//��temp�е�Ԫ��ȫ��������ԭ������
		t = 0;
		while (left <= right)
		{
			item[left] = temp[t];
			t++;
			left++;
		}
	}
	bool IsInteger(double a)
	{
		if (a - (int)a == 0)
			return true;
		else
			return false;
	}
public:
	MergeSort(int* str, int n)
	{
		item = str;
		len = n;
		item1 = new int[len];
		for (int i = 0; i < len; i++)
		{
			item1[i] = str[i];
		}
		temp = new int[len];
		if (IsInteger(log2(len)))
			k = (int)log2(len) + 1;
		else
			k = (int)log2(len) + 2;
		sort(0, len - 1);
	}
	void display()
	{
		for (int i = 0; i < len; i++)
		{
			cout << item[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int n;
	while (cin >> n)
	{
		int** item = new int* [n];
		for (int i = 0; i < n; i++)
		{
			item[i] = new int[2];
			cin >> item[i][0] >> item[i][1];
		}
		//StraightInsertSort(item, n);
	}
}
/*
��Ŀ����
������Ԫ����a[MAXN][2]������һ���ؼ�ֵ��С��������������Ҫ���һ�ؼ�ֵ��ͬ����²��ı�ԭ�������

����
ÿ�����ݵ�һ��Ϊ����n��1 <= n <= 10 ^ 5��

������n��ÿ�����������ո������

���
�������������

��������
3
2 4
1 0
2 3
3
4 2
0 4
0 2
�������
1 0
2 4
2 3
0 4
0 2
4 2
��ʾ
*/