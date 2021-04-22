#include<iostream>
using namespace std;
//�����������
class BiTreeNode
{
public:
	char data;  //�������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL) {}
	//~BiTreeNode();
};

//��������
class BiTree
{
private:
	BiTreeNode* Root;   //���ڵ�ָ��
	int pos;
	int LeftLeaf_num;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t,int n);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	int LeftLeaf();  //���������������Ҷ������
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
	LeftLeaf_num = 0;
}

//���������������
void BiTree::PreOrder() //���к���������ӿ�
{
	PreOrder(Root,0);
}
void BiTree::PreOrder(BiTreeNode* t,int n)
{
	if (t != NULL)
	{
		if ((n == 0) || (n == 2))
		{
			PreOrder(t->LeftChild,1);
			PreOrder(t->RightChild,2);
		}
		if (n == 1)
		{
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				LeftLeaf_num++;
			}
			else
			{
				PreOrder(t->LeftChild, 1);
				PreOrder(t->RightChild, 2);
			}
		}
	}
	else
		return;
}

//���������������
void BiTree::InOrder()  //���к���������ӿ�
{
	InOrder(Root);
}
void BiTree::InOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		InOrder(t->LeftChild);
		cout << t->data;
		InOrder(t->RightChild);
	}
	else
		return;
}

//��������������
void BiTree::PostOrder()  //���к���������ӿ�
{
	PostOrder(Root);
}
void BiTree::PostOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout << t->data;
	}
	else
		return;
}

int BiTree::LeftLeaf()
{
	PreOrder(Root, 0);
	return LeftLeaf_num;
}

//�����������������������������
void BiTree::CreateTree(string TreeArray) //���к���������ӿ�
{
	pos = 0;
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
//�ݹ齨����˽�к���������ʵ��
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c;
	c = strTree[pos++];
	if (c == '0')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //���ɸ����
		T->LeftChild = CreateBiTree();    //����������
		T->RightChild = CreateBiTree();   //����������
	}
	return T;
}
int main()
{
	int t;
	cin >> t;
	string str;
	while (t--)
	{
		cin >> str;
		BiTree bt;
		bt.CreateTree(str);
		cout << bt.LeftLeaf() << endl;
	}
}
/*
��Ŀ����
����һ�Ŷ�����������Ҷ�ӽ��������
��Ҷ����ָ�������Һ���Ϊ�գ��������Ǹ��׵�����
��ʾ������������������Ҳ�����������㷨������������ж�
�����������á��������+������0��ʾ���ķ���
����
��һ������һ������t����ʾ��t����������
�ڶ����������������������Ľ�����������ַ���0����ʾ������t��
���
�������ÿ���������İ�������Ҷ������
��������
3
AB0C00D00
AB00C00
ABCD0000EF000

�������
0
1
2

*/