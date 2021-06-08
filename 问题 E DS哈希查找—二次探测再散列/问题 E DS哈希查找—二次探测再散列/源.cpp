#include<iostream>
using namespace std;
class hash_map
{
private:
	int* hashmap;
	int len;
	int pos;

	//��ϣ�����ͻʱ�ݹ�ɢ��
	//˽�к��������ڵ���
	void next_insert(int& key, int p)
	{
		int original_key = key;
		key += pos * pos;
		if (key >= len)
			key = key - len;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
		{
			key = key - pos * pos * 2;
			if (key < 0)
				key = key + len;
			if (hashmap[key] < 0)
				hashmap[key] = p;
			else
			{
				pos++;
				next_insert(original_key, p);
			}
		}
	}
	//��ϣ���ҳ�ͻʱ�ݹ�ɢ��
	//˽�к��������ڵ���
	int next_find(int& key, int target, int& num)
	{
		num++;
		int original_key = key;
		key += pos * pos;
		if (key >= len)
			key = key - len;
		if (hashmap[key] == target)
			return key + 1;
		else if (hashmap[key] < 0)
			return 0;
		else
		{
			num++;
			key = key - pos * pos * 2;
			if (key < 0)
				key = key + len;
			if (hashmap[key] == target)
				return key + 1;
			else if (hashmap[key] < 0)
				return 0;
			else
			{
				pos++;
				next_find(original_key, target, num);
			}
		}
	}
public:
	hash_map(int m)
	{
		len = m;
		hashmap = new int[m];
		pos = 1;
	}
	//��ϣ����չʾ����
	void hash_display()
	{
		for (int i = 0; i < len; i++)
		{
			if (hashmap[i] >= 0)
				cout << hashmap[i] << " ";
			else
			{
				cout << "NULL ";
				//cout << hashmap[i] << " ";
			}
		}
		cout << endl;
	}
	//��ϣ���뺯��
	void hash_insert(int p)
	{
		int key;
		key = p % 11;
		if (hashmap[key] < 0)
			hashmap[key] = p;
		else
		{
			pos = 1;
			next_insert(key, p);
		}
	}

	//��ϣ���Һ���
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		int num;  //���Ҵ���
		num = 1;
		if (hashmap[key] < 0)
		{
			cout << 0 << " ";
			cout << num << endl;
		}
		else if (hashmap[key] == target)
		{
			cout << 1 << " ";
			cout << num << " ";
			cout << key + 1 << endl;
		}
		else
		{
			pos = 1;
			int result = next_find(key, target, num);
			if (result != 0)
			{
				cout << 1 << " ";
				cout << num << " ";
				cout << result << endl;
			}
			else
			{
				cout << 0 << " ";
				cout << num << endl;
			}
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;   //��ϣ��m
		int n;   //�ؼ��ָ���n
		cin >> m >> n;

		hash_map h(m);

		int item;
		for (int i = 0; i < n; i++)
		{
			cin >> item;
			h.hash_insert(item);
		}

		h.hash_display();

		int k;   //���Ҵ���k
		cin >> k;
		int target;
		while (k--)
		{
			cin >> target;
			h.hash_find(target);
		}
	}
}
/*
��Ŀ����
�����ϣ����ΪH(key) = key%11������������ڡ�����11��������ؼ��ּ��ϣ��ö���̽����ɢ�й�����ϣ�������Ҹ����ؼ��֡�

����
���Դ���t

ÿ��������ݸ�ʽ���£�

��ϣ��m���ؼ��ָ���n

n���ؼ���

���Ҵ���k

k������ؼ���

���
��ÿ��������ݣ����������Ϣ��

����Ĺ�ϣ����Ϣ��������û�йؼ��ֵ�λ�����NULL

��k������ؼ��֣��ֱ������

0��1��0�����ɹ���1���ɹ������Ƚϴ��������ҳɹ���λ�ã���1��ʼ��

��������
1
12 10
22 19 21 8 9 30 33 4 41 13
4
22
15
30
41
�������
22 9 13 NULL 4 41 NULL 30 19 8 21 33
1 1 1
0 3
1 3 8
1 6 6
��ʾ
*/