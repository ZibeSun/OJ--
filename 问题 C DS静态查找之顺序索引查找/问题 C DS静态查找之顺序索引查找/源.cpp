#include<iostream>
using namespace std;
class Sequential_Index_Search
{
private:
	int n;    //������
	int k;    //�����ֳ��Ŀ���
	int* item;//����
	int* maxkey_index;//���ؼ���������
	int* StartPosition_index;//���ؼ�����ʼλ��������
public:
	Sequential_Index_Search(int n1, int k1, int* item1, int* a)
	{
		n = n1;
		k = k1;
		item = item1;
		maxkey_index = a;
		StartPosition_index = new int[k];
		int p = 1;
		for (int i = 0; i < k; i++)
		{
			StartPosition_index[i] = p + i * (n / k);
		}
	}
	//˳����������
	int Search(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
						return j;
				}
				return 0;
			}
		}
		return 0;
	}
	//��������Ҵ�����˳����������
	void Search_times(int key)
	{
		for (int i = 0; i < k; i++)
		{
			if (maxkey_index[i] >= key)
			{
				int spi = StartPosition_index[i];
				for (int j = spi; j < spi + (n / k); j++)
				{
					if (item[j] == key)
					{
						//(j - spi + 1)��ʾ�ڿ��ڲ��ҵĴ���
						//(i + 1)��ʾ�ڿ����ҵĴ���
						cout << j << "-" << (j - spi + 1)+(i + 1) << endl;
						return;
					}
				}
				cout << "error" << endl;
				return;
			}
		}
		cout << "error" << endl;
	}
};
int main()
{
	int n;
	int k;
	int t;
	int key;
	cin >> n;
	int* item = new int[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}
	cin >> k;
	int* a = new int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	cin >> t;
	while (t--)
	{
		cin >> key;
		Sequential_Index_Search SIS(n, k, item, a);
		SIS.Search_times(key);
		/*
		int s = SIS.Search(key);
		if (s != 0)
			cout << s << endl;
		else
			cout << "error" << endl;
			*/
	}
}
/*
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ
Ҫ��ʹ��˳�����������㷨��������������ҺͿ��ڲ��Ҷ����ò����ڱ�����ͷ��ʼ��˳����ҷ�����
����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ��������������ÿո����
����������k����ʾ������Ϊk���飬kҲ��������ĳ���
����������k�����ݣ���ʾ��������ÿ��������ֵ
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��
���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�úͲ��Ҵ���������֮���ö̻��߸�����������Ҳ��ɹ�������ַ���error
��������
18 22 12 13 8 9 20 33 42 44 38 24 48 60 58 74 57 86 53 3 22 48 86 6 13 5 48 40 53 90
�������
3-4 error 12-8 error 18-9 error
��ʾ
 ��Ҫ������������ݴ������һ����Ƭ��ֵ��������������ϸ���������Ҫ��������ֵ����86����������ǲ��ҵ�ʱ����Ҫ���Ҵ���86�����

*/