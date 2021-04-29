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
	BiTreeNode() :LeftChild(NULL), RightChild(NULL), Parent(NULL){}
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
	void PreOrder(BiTreeNode* t,int c,int* s, char* l);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LeafAndParent();  //�ҳ���������Ҷ�ӽ�㼰��˫�׽��
	int LeafDepth(BiTreeNode* t);    //����Ҷ�ӽ������
	int subtree_LeafMaxDistance(BiTreeNode* t, char* l1, char* l2);   //������t���Ϊ�������������������������������֮���������
	void LeafMaxDistance();    //�������������������
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
	//PreOrder(Root,0);
}
//c�Ǹ��Ӳ�������s�ǵ�ַ���ݵ�������
void BiTree::PreOrder(BiTreeNode* t,int c,int* s,char *l)
{
	if (t != NULL)
	{
		//c=0����ʾ��ͨ�������
		if (c == 0)
		{
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild,0,s,l);
			PreOrder(t->RightChild,0,s,l);
		}
		//c=1����ʾ�������t�µ�������
		else if (c == 1)
		{
			if (*s == -1)
			{
				if (t->LeftChild == NULL)
				{
					*s = 0;
					return;
				}
				else
					t = t->LeftChild;
			}
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild, 0, s, l);
			PreOrder(t->RightChild, 0, s, l);
		}
		//c=2����ʾ�������t�µ�������
		else if (c == 2)
		{
			if (*s == -1)
			{
				if (t->RightChild == NULL)
				{
					*s = 0;
					return;
				}
				else
					t = t->RightChild;
			}
			if (*s < LeafDepth(t))
			{
				*s = LeafDepth(t);
				*l = t->data;
			}
			PreOrder(t->LeftChild, 0, s, l);
			PreOrder(t->RightChild, 0, s, l);
		}
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

//����Ҷ�ӽ������ڸ��������
int BiTree::LeafDepth(BiTreeNode* t)
{
	int depth = 0;
	BiTreeNode* T = t;
	while (1)
	{
		if (T == Root)
		{
			return depth;
		}
		else
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
}

//������t���Ϊ�������������������������������֮���������
//���t���޸��������Ӻ��Һ���
int BiTree::subtree_LeafMaxDistance(BiTreeNode* t,char *l1,char *l2)
{
	int sl, sr;
	sl = -1;
	sr = -1;
	*l1 = '#';
	*l2 = '#';
	PreOrder(t, 1, &sl,l1);
	PreOrder(t, 2, &sr,l2);
	//cout << "sl=" << sl << "sr=" << sr << endl;
	return sl + sr;
}

//�������������������
void BiTree::LeafMaxDistance()
{
	int MaxD;
	char l1, l2, l3, l4, l5, l6;
	char leaf1, leaf2;
	int A = subtree_LeafMaxDistance(Root,&l1,&l2);
	int l = subtree_LeafMaxDistance(Root->LeftChild, &l3, &l4) - 2;
	int r = subtree_LeafMaxDistance(Root->RightChild, &l5, &l6) - 2;
	//cout << "l=" << l << "r=" << r << endl;
	int B = l > r ? l : r;
	//cout << "A=" << A << endl;
	//cout << "B=" << B << endl;
	if (A > B)
	{
		MaxD = A;
		leaf1 = l1;
		leaf2 = l2;
	}
	else
	{
		MaxD = B;
		if (B == l)
		{
			leaf1 = l3;
			leaf2 = l4;
		}
		else if (B == r)
		{
			leaf1 = l5;
			leaf2 = l6;
		}
	}
	cout << MaxD << ":";
	if (MaxD != 0)
		cout << leaf1 << " " << leaf2 << endl;
	else
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
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		BiTree bt;
		bt.CreateTree(str);
		bt.LeafMaxDistance();
	}
}
/*
��Ŀ����
	�������������ľ�����һ����㾭��˫�׽�㣬���Ƚ����м��㵽����һ����㾭���ķ�֧����
���������������������н����������ֵ�����磬��ͼ��ʾ�����������������3��C��D�ľ��롣
	���������������˳�򴴽���#��ʾ������
���������������������������������(�����������ȡ��������������Ψһ����

����
���Դ���T
��2��֮���T�У�ÿ��Ϊһ�ö�����������������#��ʾ������
���
��ÿ�ö�������������Ľ���������������Ľ�㣬�����ʽ��������

��������
3
A##
ABC##EF#G###D##
ABEH###F#K###
�������
0:
5:G D
4:H K

*/