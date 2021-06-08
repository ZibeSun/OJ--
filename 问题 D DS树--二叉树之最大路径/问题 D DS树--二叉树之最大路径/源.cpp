#include<iostream>
using namespace std;
//��������������������
class BiTreeNode
{
public:
	char data;  //�������
	int weight; //Ҷ�ӽ��Ȩֵ
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
	int weightsum;
	int pos;
	int wtpos;
	int leaf_num;
	string strTree;
	int* wt;            //Ҷ�ӽ��Ȩֵָ������
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
	void WeightSum(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray, int* iwt);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LeafAndParent();  //�ҳ���������Ҷ�ӽ�㼰��˫�׽��
	int LeafDepth(BiTreeNode* t);    //����Ҷ�ӽ������
	void WeightSum();  //���������������Ҷ�ӽ��Ȩֵ֮�Ͳ����
};
BiTree::BiTree()
{
	pos = 0;
	wtpos = 0;
	strTree = "";
	leaf_num = 0;
	weightsum = 0;
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

void BiTree::WeightSum()   //���к���������ӿ�
{
	WeightSum(Root);
	cout << weightsum << endl;
}
// ���������������Ҷ�ӽ��Ȩֵ֮�Ͳ����
void BiTree::WeightSum(BiTreeNode* t)
{
	if (t != NULL)
	{
		if (t->weight != 0)
		{
			weightsum += t->weight * LeafDepth(t);
		}
		WeightSum(t->LeftChild);
		WeightSum(t->RightChild);
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

//�����������������������������
void BiTree::CreateTree(string TreeArray, int* iwt) //���к���������ӿ�
{
	pos = 0;
	strTree.assign(TreeArray);
	wt = iwt;
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
		if ((c >= 'A') && (c <= 'Z'))
		{
			T->weight = wt[wtpos];
			wtpos++;
		}
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
	string str;
	int n;
	while (t--)
	{
		cin >> str;
		int n;
		cin >> n;
		int* wt = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}
		BiTree bt;
		bt.CreateTree(str, wt);
		
	}
}
/*
��Ŀ����
����һ�Ŷ��������߼��ṹ����������Ľ�����������ַ���0����ʾ������AB0C00D00���������ö������Ķ�����ʽ�洢�ṹ
��������ÿ����㶼��һ��Ȩֵ���Ӹ���㵽ÿ��Ҷ�ӽ�㽫�γ�һ��·����ÿ��·����Ȩֵ����·�������н���Ȩֵ�͡������������������·��Ȩֵ������ͼ��ʾ������4��Ҷ�Ӽ���4��·����
·��1Ȩֵ=5 + 4 + 11 + 7 = 27          ·��2Ȩֵ=5 + 4 + 11 + 2 = 22
·��3Ȩֵ=5 + 8 + 13 = 26                ·��4Ȩֵ=5 + 8 + 4 + 1 = 18
�ɼ�������·��Ȩֵ��27��
�������������������ΪABCD00E000FG00H0I00�������ȨֵΪ��
A-5��B-4��C-11��D-7��E-2��F-8��G-13��H-4��I-1

����
��һ������һ������t����ʾ��t����������
�ڶ�������һ�ö����������������ÿ���������ĸ��ʾ
������������n��ʾ�������Ľ��������Ȼ������ÿ������Ȩֵ��Ȩֵ˳����ǰ��������˳���Ӧ
�Դ�����������һ�ö�����
���
ÿ�����ÿ�ö����������·��Ȩֵ��������·��Ȩֵ���ظ���ֻ���1��
��������
2
AB0C00D00
4 5 3 2 6
ABCD00E000FG00H0I00
9 5 4 11 7 2 8 13 4 1
�������
11
27
��ʾ

*/