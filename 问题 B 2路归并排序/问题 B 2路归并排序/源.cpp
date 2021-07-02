#include<iostream>
#include<cmath>
using namespace std;
//2·�鲢���򣬵ݹ�����
class MergeSort
{
private:
	int* item;
	int* temp;
	int* item1;
	int len;
	int k;
	int p;
	void sort(int left, int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			sort(left, mid);//��߹鲢����ʹ��������������
			sort(mid + 1, right);//�ұ߹鲢����ʹ��������������
			merge(left, mid, right);
		}
		p++;
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
	void Display_Children()
	{
		for (int i = k; i > 0; i--)
		{
			display_children(0, len - 1, 1, i);
		}
	}
	void display_children(int left, int right, int pos, int j)
	{
		//cout << "pos=" << pos << endl;
		if (left < right)
		{
			int mid = (left + right) / 2;
			display_children(left, mid, pos * 2, j);
			display_children(mid + 1, right, pos * 2 + 1, j);
		}
		if ((int)(log2(pos) + 1) == j)
		{
			int num = right - left + 1;
			int* item2 = new int[num];
			for (int i = left; i <= right; i++)
			{
				item2[i-left] = item1[i];
			}
			SelectSort(item2, num);
			for (int i = 0; i < num; i++)
			{
				cout << item2[i] << " ";
			}
			cout << endl;
		}
	}
	void SelectSort(int* arr, int n)
	{
		int min;
		for (int i = 0; i < n; i++)
		{
			min = i;
			for (int k = i + 1; k < n; k++)
			{
				if (arr[k] < arr[min])
				{
					min = k;
				}
			}

			int m = arr[i];
			arr[i] = arr[min];
			arr[min] = m;
		}
	}
public:
	MergeSort(int* str, int n)
	{
		p = 0;
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
		cout << p << endl;
		Display_Children();
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
	cin >> n;
	int* str = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	MergeSort ms(str, n);
}
/*
��Ŀ����
����һ�����������У�ִ��2·�鲢�����㷨�õ���С��������С�Ҫ��2·�鲢�����������¶����������ҵĴ������ÿ������������С�
        [23 38 17 16 25]                        [16  17  23  25  38](9)
        /             \                         /                 \
    [23 38 17]       [16 25]                [17 23 38](7)         [16 25](8)
      /     \         /   \      =>           /     \             /   \
  [23 38]   [17]    [16] [25]            [23 38](3) [17](4)  [16](5) [25](6)
   /   \                                /      \
 [23] [38]                            [23](1) [38](2)
�Զ����½��У����ݹ���� MergeSort(left, mid)��MergeSort(mid, right)
����Լ����������Ϊ[1, n]�� mid = (left + right) / 2���ݹ�������Ϊ [left, mid]��[mid + 1, right]
����
��1�и����е�����������n
��2��n����������Ԫ��֮���ɿո�ֿ�
���
m: ��ʾ2·�鲢�������Ľ�����
m�У�ÿ���������������
��������
5
23 38 17 16 25
�������
9
23
38
23 38
17
16
25
17 23 38
16 25
16 17 23 25 38
��ʾ

*/