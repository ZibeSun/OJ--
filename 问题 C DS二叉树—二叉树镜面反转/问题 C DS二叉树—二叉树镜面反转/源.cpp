#include<iostream>
using namespace std;
//�����������
class BiTreeNode
{
public:
	char data;  //�������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode* Parent;      //˫��ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), data(' '), Parent(NULL) {}
	//~BiTreeNode();
};

//��������
class BiTree
{
private:
	BiTreeNode* Root;   //���ڵ�ָ��
	int pos;
	string strTree;
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t);
	void PostOrder(BiTreeNode* t);
	void LevelOrder(BiTreeNode* t, int i);
	void MirrorTree(BiTreeNode* t);
	int LeafDepth(BiTreeNode* t);   //����Ҷ�ӽ������
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LevelOrder();  //��α���
	void MirrorTree();  //����������ת
	bool CheckTree();   //���������Ƿ�Ϊ��
};
BiTree::BiTree()
{
	pos = 0;
	strTree = "";
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
		cout << t->data << " ";
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
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
		cout << t->data << " ";
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
		cout << t->data << " ";
	}
	else
		return;
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
	if (c == '#')
		T = NULL;
	else
	{
		T = new BiTreeNode();
		T->data = c;    //���ɸ����
		T->LeftChild = CreateBiTree();    //����������
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //����������
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}

//��α�������
void BiTree::LevelOrder()    //���к���������ӿ�
{
	for (int i = 0; i < 10; i++)
	{
		LevelOrder(Root,i);
	}
}
void BiTree::LevelOrder(BiTreeNode* t,int i)
{
	if (t != NULL)
	{
		if (LeafDepth(t) == i)
		{
			cout << t->data << " ";
		}
		LevelOrder(t->LeftChild,i);
		LevelOrder(t->RightChild, i);
	}
	else
		return;
}

//����������ת
void BiTree::MirrorTree()    //���к���������ӿ�
{
	MirrorTree(Root);
}
void BiTree::MirrorTree(BiTreeNode* t)
{
	if (t != NULL)
	{
		BiTreeNode* p = t->LeftChild;
		t->LeftChild = t->RightChild;
		t->RightChild = p;
		MirrorTree(t->LeftChild);
		MirrorTree(t->RightChild);
	}
	else
		return;
}

//���������Ƿ�Ϊ��
bool BiTree::CheckTree()
{
	if (Root == NULL)
		return true;
	else
		return false;
}

//����Ҷ�ӽ������
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != NULL)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			return depth;
		}
	}
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
		if (bt.CheckTree())
		{
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
			cout << "NULL" << endl;
		}
		else
		{
			bt.MirrorTree();
			bt.PreOrder();
			cout << endl;
			bt.InOrder();
			cout << endl;
			bt.PostOrder();
			cout << endl;
			bt.LevelOrder();
			cout << endl;
		}
	}
}
/*
��Ŀ����
����������ö�������洢�����������н��������������������������У������ȴ������������������������淴ת���������ת��Ķ���������������������������������Ͳ�����������С���ν���淴ת����ָ�����з�Ҷ�������Һ��ӶԻ���
--����Ҫ��--
��ʹ��C++ֻ��includeһ��ͷ�ļ�iostream����ʹ��C����ֻ��includeһ��ͷ�ļ�stdio
��������include���һ��ͷ�ļ����������룬��0�ִ���
������ʹ�õ������������ʵ�ֱ����Ҫ��
����
���Դ���t
ÿ�����������һ��������������������У�#��ʾ����
���
��ÿ�ö�������������淴ת����������򡢺���Ͳ�α������С��������������ĸ�NULL�����治�ӿո񣩡����£�
NULL
NULL
NULL
NULL
��������
3
41#32###65##7##
AB#C##D##
AB##C##
�������
4 6 7 5 1 3 2
7 6 5 4 3 2 1
7 5 6 2 3 1 4
4 6 1 7 5 3 2
A D B C
D A C B
D C B A
A D B C
A C B
C A B
C B A
A C B
��ʾ

*/