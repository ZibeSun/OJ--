#include<iostream>
using namespace std;
//��������������������
class BiTreeNode
{
public:
	char data;  //�������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode* Parent;      //˫��ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL),Parent(NULL) {}
	//~BiTreeNode();
};

//������������������
class BiTree
{
private:
	BiTreeNode* Root;   //���ڵ�ָ��
	int pos;
	int leaf_num;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t,int n);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LeafAndParent();  //�ҳ���������Ҷ�ӽ�㼰��˫�׽��
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
	leaf_num = 0;
}

//���������������
void BiTree::PreOrder() //���к���������ӿ�
{
	PreOrder(Root);
}
void BiTree::PreOrder(BiTreeNode* t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

//���������������
void BiTree::InOrder()  //���к���������ӿ�
{
	InOrder(Root,0);
}
void BiTree::InOrder(BiTreeNode* t,int n)
{
	if (t != NULL)
	{
		//n=0�����Ҷ�ӽ��
		if (n == 0)
		{
			InOrder(t->LeftChild,0);
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				cout << t->data << " ";
			}
			InOrder(t->RightChild,0);
		}
		//n=1�����Ҷ�ӽ���˫�׽��
		else if (n == 1)
		{
			InOrder(t->LeftChild, 1);
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				if (t->Parent == NULL)
					cout << t->data << " ";
				else
					cout << t->Parent->data << " ";
			}
			InOrder(t->RightChild, 1);
		}
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

void BiTree::LeafAndParent()
{
	InOrder(Root, 0);
	cout << endl;
	InOrder(Root, 1);
	cout << endl;
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
		if(T->LeftChild!=NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //����������
		if(T->RightChild!=NULL)
			T->RightChild->Parent = T;
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
		bt.LeafAndParent();
	}
}
/*
��Ŀ����
����һ�Ŷ��������߼��ṹ����ͼ������������Ľ�����������ַ���0����ʾ������AB0C00D00���������ö������Ķ�����ʽ�洢�ṹ��
��д�����������������Ҷ�ӽ������ǵĸ��׽��

����
��һ������һ������t����ʾ��t��������
�ڶ����𣬰�����Ŀ��ʾ�����뷽��������ÿ���������������������������t��
���
��һ�а���������������1��ʾ����Ҷ�ӽڵ�
�ڶ��������1��ʾ������Ҷ�����Ӧ�ĸ��׽ڵ�
�Դ������������ʾ���Ľ��

��������
4
AB0C00D00
AB00C00
ABCD0000EF000
A00
�������
C D
B A
B C
A A
D F
C E
A
A

*/