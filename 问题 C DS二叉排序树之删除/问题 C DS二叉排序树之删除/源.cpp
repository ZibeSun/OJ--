#include<iostream>
using namespace std;
//���������������
class BSTNode
{
public:
	int key;           //���ؼ���
	BSTNode* Parent;   //�����
	BSTNode* Lchild;   //����
	BSTNode* Rchild;   //�Һ���
	BSTNode() :key(0), Parent(NULL),Lchild(NULL), Rchild(NULL) {}
};
//������������
class BSTree
{
private:
	BSTNode* Root;  //�����ָ��
	void InOrder(BSTNode* t,int n);
	BSTNode* Search_BST(BSTNode* T, int key);
	BSTNode* Insert_BST(BSTNode* T, int key);
public:
	int search_times;   //ÿ�β��Ҵ���
	BSTree();  //���캯��
	void InOrder();     //�������
	BSTNode* Search_BST(int key);        //�����������ĵݹ����
	void Insert_BST(int key);            //�����������ĵݹ����
	void Delete_BST(int key);            //�����������ĵݹ�ɾ��
	void Create_BST(int* item, int n);   //��������������
};
BSTree::BSTree()
{
	Root = NULL;
	search_times = 0;
}
//���������������
void BSTree::InOrder()  //���к���������ӿ�
{
	InOrder(Root,1);
}
void BSTree::InOrder(BSTNode* t,int n)
{
	if (n == 1)
	{
		if (t != NULL)
		{
			InOrder(t->Lchild,1);
			cout << t->key << " ";
			InOrder(t->Rchild,1);
		}
		else
			return;
	}
	else if (n == 2)
	{
		if (t != NULL)
		{
			InOrder(t->Lchild, 2);
			if (t->Lchild != NULL)
				t->Lchild->Parent = t;
			if (t->Rchild != NULL)
				t->Rchild->Parent = t;
			InOrder(t->Rchild, 2);
		}
		else
			return;
	}
}
//��������������ĵݹ���Һ���
BSTNode* BSTree::Search_BST(int key)  //���к���������ӿ�
{
	search_times = 0;   //���Ҵ�������
	return Search_BST(Root, key);
}
BSTNode* BSTree::Search_BST(BSTNode* T, int key)
{
	if (T == NULL)
		return NULL;  //����ʧ���򷵻�NULL
	else
	{
		if (T->key == key)
		{
			search_times++;
			return T;         //�����ɹ��򷵻ؽ��ָ��
		}
		else if (T->key > key)
		{
			search_times++;
			Search_BST(T->Lchild, key);
		}
		else
		{
			search_times++;
			Search_BST(T->Rchild, key);
		}
	}
}
//��������������ĵݹ���뺯��
void BSTree::Insert_BST(int key)  //���к���������ӿ�
{
	Root = Insert_BST(Root, key);
}
BSTNode* BSTree::Insert_BST(BSTNode* T, int key)
{
	if (T == NULL)
	{
		T = new BSTNode;
		T->key = key;
		return T;
	}
	else
	{
		if (T->key == key)
			return NULL;
		else if (T->key > key)
			T->Lchild = Insert_BST(T->Lchild, key);
		else
			T->Rchild = Insert_BST(T->Rchild, key);
		return T;
	}
}
//��������������ĵݹ�ɾ������
void BSTree::Delete_BST(int key)
{
	BSTNode* T = Search_BST(key);
	if (T == NULL)
	{
		return;   //��Ҫɾ�������ݲ��ڶ������У���ִ�в���
	}
	if ((T->Lchild == NULL) && (T->Rchild == NULL))
	{//���һ:�ý����Ҷ�ӽ��
		if (T->Parent->Lchild == T)
			T->Parent->Lchild = NULL;
		else if (T->Parent->Rchild == T)
			T->Parent->Rchild = NULL;
	}
	else if ((T->Lchild != NULL) && (T->Rchild != NULL))
	{//�����:�ý��ͬʱ����������
		BSTNode* t = T->Rchild;
		while (t->Lchild != NULL)
			t = t->Lchild;
		T->key = t->key;

		if (t->Rchild != NULL)
			*t = *t->Rchild;
		else
		{
			if (t->Parent->Lchild == t)
				t->Parent->Lchild = NULL;
			else if (t->Parent->Rchild == t)
				t->Parent->Rchild = NULL;
		}
	}
	else
	{//�����:�ý��ֻ����������������
		if (T->Lchild != NULL)
		{
			*T = *T->Lchild;
		}
		else if (T->Rchild != NULL)
		{
			*T = *T->Rchild;
		}
	}
}
//��������������
void BSTree::Create_BST(int* item, int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert_BST(item[i]);
	}
	InOrder(Root, 2);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int* item = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> item[i];
		}
		BSTree BST;
		BST.Create_BST(item, n);
		BST.InOrder();
		cout << endl;
		int m;
		cin >> m;
		int key;
		while (m--)
		{
			cin >> key;
			BST.Delete_BST(key);
			BST.InOrder();
			cout << endl;
		}
	}
}
/*
��Ŀ����
����һ���������У�������������������ʵ��ɾ������
�Զ�������������������������Եõ��������������
����
��һ������t����ʾ��t����������
�ڶ�������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������m����ʾҪɾ��m������
�ӵ�����������m�У�ÿ��һ��Ҫɾ�������ݣ�������Ȼ��
�Դ�����������һ��ʾ��
���
��һ�����������������У��Զ�����������������������Եõ�
�ӵڶ��������ɾ����m�����ݺ���������У����m��
�Դ����������һ��ʾ���Ľ��
��������
1
6
22 33 55 66 11 44
3
66
22
77
�������
11 22 33 44 55 66
11 22 33 44 55
11 33 44 55
11 33 44 55
��ʾ
��ɾ�����ݲ��������У���ôɾ���������ڲ�ִ�У�����������в��仯

*/