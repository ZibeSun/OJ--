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
	int* wt;    //Ҷ�ӽ��Ȩֵָ������
	BiTreeNode* CreateBiTree();
	void PreOrder(BiTreeNode* t);
	void InOrder(BiTreeNode* t, int n);
	void PostOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray,int *iwt);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LeafAndParent();  //�ҳ���������Ҷ�ӽ�㼰��˫�׽��
	int LeafDepth(BiTreeNode *t);    //����Ҷ�ӽ������
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
		if (t->weight != 0)
		{
			weightsum += t->weight * LeafDepth(t);
		}
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
	else
		return;
}

void BiTree::WeightSum()
{
	PreOrder();
	cout << weightsum << endl;
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
void BiTree::CreateTree(string TreeArray,int *iwt) //���к���������ӿ�
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
		bt.CreateTree(str,wt);
		bt.WeightSum();
	}
}
/*
��Ŀ����
����һ�ö������Ĵ�Ȩ·���ܺͣ�����շ������Ĵ�Ȩ·���͡�
��֪һ�ö�������Ҷ��Ȩֵ���ö������Ĵ�Ȩ��·����APL����Ҷ��Ȩֵ���ڸ��ڵ㵽Ҷ�ӵķ�֧����Ȼ�����ܺ͡�����ͼ�У�Ҷ�Ӷ��ô�д��ĸ��ʾ��Ȩֵ��ӦΪ��A-7��B-6��C-2��D-3
���Ĵ�Ȩ·���� = 7*1 + 6*2 + 2*3 + 3*3 = 34

����������Ĵ����ο�ǰ��ķ���
����
��һ������һ������t����ʾ��t��������
�ڶ�������һ�ö��������������������������ַ���0����ʾ��ע������ȫ��Ӣ����ĸ��0�����д�д��ĸ��ʾҶ��
������������n��ʾ��n��Ҷ�ӣ���������n�����ݱ�ʾn��Ҷ�ӵ�Ȩֵ��Ȩֵ��˳���ǰ������Ĵ�д��ĸ˳���Ӧ
�Դ�����������һ�ö�����
���
���ÿһ�ö������Ĵ�Ȩ·����
��������
2
xA00tB00zC00D00
4 7 6 2 3
ab0C00D00
2 10 20
�������
34
40

*/