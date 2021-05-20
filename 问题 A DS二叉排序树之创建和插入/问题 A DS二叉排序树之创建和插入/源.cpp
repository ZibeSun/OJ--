#include<iostream>
using namespace std;
//���������������
class BSTNode
{
public:
	int key;           //���ؼ���
	BSTNode* Lchild;   //����
	BSTNode* Rchild;   //�Һ���
	BSTNode() :key(0), Lchild(NULL), Rchild(NULL) {}
};
//������������
class BSTree
{
private:
	BSTNode* Root;  //�����ָ��
	void InOrder(BSTNode* t);
	BSTNode* Search_BST(BSTNode* T, int key);
	BSTNode* Insert_BST(BSTNode* T, int key);
public:
	BSTree();  //���캯��
	void InOrder();     //�������
	BSTNode* Search_BST(int key);  //�����������ĵݹ����
	void Insert_BST(int key);  //�����������ĵݹ����
	void Create_BST(int* item, int n);   //��������������

};
BSTree::BSTree()
{
	Root = NULL;
}
//���������������
void BSTree::InOrder()  //���к���������ӿ�
{
	InOrder(Root);
}
void BSTree::InOrder(BSTNode* t)
{
	if (t != NULL)
	{
		InOrder(t->Lchild);
		cout << t->key << " ";
		InOrder(t->Rchild);
	}
	else
		return;
}
//��������������ĵݹ���Һ���
BSTNode* BSTree::Search_BST(int key)  //���к���������ӿ�
{
	return Search_BST(Root, key);
}
BSTNode* BSTree::Search_BST(BSTNode* T, int key)
{
	if (T == NULL)
		return NULL;
	else
	{
		if (T->key == key)
			return T;
		else if (T->key > key)
			Search_BST(T->Lchild, key);
		else
			Search_BST(T->Rchild, key);
	}
}
//��������������ĵݹ���뺯��
void BSTree::Insert_BST(int key)  //���к���������ӿ�
{
	Root=Insert_BST(Root, key);
}
BSTNode* BSTree::Insert_BST(BSTNode* T, int key)
{
	if (T == NULL)
	{
		T = new BSTNode;
		T->key = key;
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
//��������������
void BSTree::Create_BST(int* item,int n)
{
	for (int i = 0; i < n; i++)
	{
		Insert_BST(item[i]);
	}
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
			BST.Insert_BST(key);
			BST.InOrder();
			cout << endl;
		}
	}

}
/*
��Ŀ����
����һ���������У�������������������ʵ�ֲ��빦��
�Զ�������������������������Եõ��������������
����
��һ������t����ʾ��t����������
�ڶ�������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������m����ʾҪ����m������
�ӵ�����������m�У�ÿ��һ��Ҫ��������ݣ�������Ȼ���Һ�ǰ������ݲ���
�Դ�����������һ��ʾ��
���
��һ�����������������У��Զ�����������������������Եõ�
�ӵڶ�������������m�����ݺ���������У����m��
�Դ����������һ��ʾ���Ľ��

��������
1
6
22 33 55 66 11 44
3
77
50
10
�������
11 22 33 44 55 66
11 22 33 44 55 66 77
11 22 33 44 50 55 66 77
10 11 22 33 44 50 55 66 77
��ʾ

*/