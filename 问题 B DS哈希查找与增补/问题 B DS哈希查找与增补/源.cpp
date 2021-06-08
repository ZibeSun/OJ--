#include<iostream>
using namespace std;
class hash_node
{
public:
	int data;   //�������
	int order;
	hash_node* next;
	hash_node()
	{
		data = 0;
		order = 1;
		next = NULL;
	}
};
//�����෨Ϊ��ϣ����
//��ϣ��ͻ������ַ��(��β����)
class hash_map
{
private:
	hash_node* hashmap;   //��ϣ�������
public:
	hash_map(hash_node* item)
	{
		hashmap = item;
	}
	//�ݹ���ҹ�ϣ��ͻ
	int find_next(hash_node* hash, int target)
	{
		if (hash != NULL)
		{
			if (hash->data != target)
				return find_next(hash->next, target);
			else
				return hash->order;
		}
		else
			return 0;
	}
	//��ϣ���Һ���
	void hash_find(int target)
	{
		int key;
		key = target % 11;
		if (hashmap[key].data != target)
		{
			if (find_next(hashmap[key].next, target) != 0)
			{
				cout << key << " " << find_next(hashmap[key].next, target) << endl;
			}
			else
			{
				//����ʧ�ܣ������ݲ��뵽��ϣ����
				hash_insert(&hashmap[key], target);
				cout << "error" << endl;
			}
		}
		else
		{
			cout << key << " " << hashmap[key].order << endl;
		}
	}
	//��ϣ���뺯��
	//������target���˵���ϣ���У���ϣ��ͻ������ַ��(��β����)
	void hash_insert(hash_node* hash, int target)
	{
		if (hash->data == 0)
		{
			hash->data = target;
			return;
		}
		else
		{
			if (hash->next != NULL)
				hash_insert(hash->next, target);
			else
			{
				hash_node* h = new hash_node();
				h->data = target;
				h->order = hash->order + 1;
				hash->next = h;
			}
		}
	}
};

int main()
{
	int n;
	cin >> n;
	hash_node* item = new hash_node[20];
	int a;
	int key;
	while (n--)
	{
		cin >> a;
		key = a % 11;
		item[key].data = a;
	}
	hash_map h(item);
	int t;
	cin >> t;
	int target;
	while (t--)
	{
		cin >> target;
		h.hash_find(target);
	}
}
/*
��Ŀ����
����һ���������У�������ϣ���������෨��Ϊ��ϣ������ģ��Ϊ11����ϣ��ͻ������ַ���ͱ�β����
����״β���ʧ�ܣ��Ͱ����ݲ��뵽��Ӧ��λ����
ʵ�ֹ�ϣ��������������
����
��һ������n����ʾ��n������
�ڶ�������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������t����ʾҪ����t������
�ӵ�������ÿ������һ��Ҫ���ҵ����ݣ�����������
���
ÿ�������Ӧ���ݵĲ��ҽ����ÿ�������ʾΪ��������λ��[0��11���Ͳ��Ҵ������м��ÿո�ֿ�
��������
6
11 23 39 48 75 62
6
39
52
52
63
63
52
�������
6 1
error
8 1
error
8 2
8 1

*/