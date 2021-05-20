#include<iostream>
using namespace std;
//��������������������
class BiTreeNode
{
public:
	char data;  //�������
	int balance;  //���ƽ������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode* Parent;      //˫��ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL) {}
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
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
	BiTreeNode* Create_PreOrder(int i, string str);
	int LeafDepth(BiTreeNode* t, BiTreeNode* t_root);
	void Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h);
	void Balance_calculate(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LeafAndParent();  //�ҳ���������Ҷ�ӽ�㼰��˫�׽��
	void CreatePreOrder(int i, string str);
	int HeightSubtree(BiTreeNode* t);   //���������߶�
	void Balance_calculate();  //������ƽ������
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
	InOrder(Root, 0);
}
void BiTree::InOrder(BiTreeNode* t, int n)
{
	if (t != NULL)
	{
		//n=0�����Ҷ�ӽ��
		if (n == 0)
		{
			InOrder(t->LeftChild, 0);
			if ((t->LeftChild == NULL) && (t->RightChild == NULL))
			{
				cout << t->data << " ";
			}
			InOrder(t->RightChild, 0);
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
		cout << t->data << " " << t->balance << endl;
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
		if (T->LeftChild != NULL)
			T->LeftChild->Parent = T;
		T->RightChild = CreateBiTree();   //����������
		if (T->RightChild != NULL)
			T->RightChild->Parent = T;
	}
	return T;
}
//�ݹ��������˳������洢�Ķ�����
void BiTree::CreatePreOrder(int i, string str)
{
	Root=Create_PreOrder(i, str);
}
BiTreeNode* BiTree::Create_PreOrder(int i, string str)
{
	BiTreeNode* T;
	if (i < str.length())
	{
		if (str[i] != '0')
		{
			T = new BiTreeNode;
			T->data = str[i];
			T->LeftChild=Create_PreOrder(2 * i + 1, str);
			if (T->LeftChild != NULL)
				T->LeftChild->Parent = T;
			T->RightChild=Create_PreOrder(2 * i + 2, str);
			if (T->RightChild != NULL)
				T->RightChild->Parent = T;
		}
		else
		{
			T = NULL;
		}
	}
	else
	{
		T = NULL;
	}
	return T;
}
//����Ҷ�ӽ��t�����t_root�������
int BiTree::LeafDepth(BiTreeNode* t, BiTreeNode* t_root)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T->Parent != t_root->Parent)
		{
			T = T->Parent;
			depth++;
		}
		else
		{
			depth++;
			return depth;
		}
	}
}
//���������߶�
int BiTree::HeightSubtree(BiTreeNode* t)
{
	int h = 0;
	if (t != NULL)
	{
		BiTreeNode* t_root = t;
		Height_Subtree(t_root, t, h);
	}
	return h;
}
void BiTree::Height_Subtree(BiTreeNode* t_root, BiTreeNode* t, int& h)
{
	if (t != NULL)
	{
		Height_Subtree(t_root, t->LeftChild, h);
		Height_Subtree(t_root, t->RightChild, h);
		if (LeafDepth(t, t_root) >= h)
			h = LeafDepth(t, t_root);
	}
	else
		return;
}
//������ƽ������
void BiTree::Balance_calculate()  //���к���������ӿ�
{
	Balance_calculate(Root);
}
void BiTree::Balance_calculate(BiTreeNode* t)
{
	if (t != NULL)
	{
		Balance_calculate(t->LeftChild);
		Balance_calculate(t->RightChild);
		t->balance = HeightSubtree(t->LeftChild) - HeightSubtree(t->RightChild);
	}
	else
		return;
}
int main()
{
	int t;
	cin >> t;
	string str;
	int n;
	while (t--)
	{
		cin >> n;
		cin >> str;
		BiTree bt;
		bt.CreatePreOrder(0,str);
		bt.Balance_calculate();
		bt.PostOrder();
	}
}
/*
��Ŀ����
������������洢�����������Ľ�������������϶���,�������Ҵ洢�������У�һ�����������ȫ�������Աȣ�����ȫ������ȱ�ٵĽ������������0����ʾ��
���������ÿ������ƽ�����ӣ��������������˳���������ƽ�����ӡ�
--����Ҫ��--
��ʹ��C++ֻ��includeһ��ͷ�ļ�iostream����ʹ��C����ֻ��includeһ��ͷ�ļ�stdio
��������include���һ��ͷ�ļ����������룬��0�ִ���
������ʹ�õ������������ʵ�ֱ����Ҫ��
����
���Դ���t
ÿ���������һ�У�����Ԫ�ظ���n�����n���ַ���������������洢��
���
��ÿ��������ݣ������������˳��������н���ƽ�����ӣ���������û�п�����
��������
2
6 ABC00D
24 ABCD0EF0000H00000000000I


�������
B 0
D 0
C 1
A -1
D 0
B 1
I 0
H 1
E 2
F 0
C 2
A -2

*/