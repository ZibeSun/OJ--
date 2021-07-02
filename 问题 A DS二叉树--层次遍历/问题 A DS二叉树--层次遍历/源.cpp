#include<iostream>
#include<queue>
using namespace std;
//�����������
class BiTreeNode
{
public:
	char data;  //�������
	BiTreeNode* LeftChild;   //������ָ��
	BiTreeNode* RightChild;  //������ָ��
	BiTreeNode() :LeftChild(NULL), RightChild(NULL),data(' ') {}
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
	void LevelOrder(BiTreeNode* t);
public:
	BiTree();
	//~BiTree();
	void CreateTree(string TreeArray);    //������������������������
	void PreOrder();    //ǰ�����
	void InOrder();     //�������
	void PostOrder();   //�������
	void LevelOrder();  //��α���
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

//��α�������
void BiTree::LevelOrder()    //���к���������ӿ�
{
	LevelOrder(Root);
}
void BiTree::LevelOrder(BiTreeNode* t)
{//�ö���ʵ��
	queue<BiTreeNode*> tq;
	BiTreeNode* p = t;
	if (p != NULL)
	{
		tq.push(p);
	}
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		if (p != NULL)
		{
			cout << p->data;
			tq.push(p->LeftChild);
			tq.push(p->RightChild);
		}
	}
	/*
	
	��p��ָ��ǰ����ָ����������p���գ���p��ӣ�Ȼ��ִ������ѭ����
	�����в��գ�
	1������Ԫ�س��ӵ�p��ע������Ĵ��벻ֻ1��
	2�����p�����ݣ���ʾ���p�ѱ���
	3����p�������ӽ���������

	��Ҫʹ�ö��ж���ķ���������
	��ӣ�tq.push(x)
	���ӣ�tq.pop()
	ȡ���ף�tq.front()
	�ж��пգ�tq.empty()

	*/
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
		bt.LevelOrder();
		cout << endl;
	}
}
/*
��Ŀ����
��α������������ǴӸ���㿪ʼ����������δ������϶��£��������ҡ��������еĸ���㡣
�����������á��������+������0��ʾ���ķ���
Ҫ�󣺲��ö��ж���ʵ�֣�����������£�

����
��һ������һ������t����ʾ��t����������
�ڶ����������������������Ľ�����������ַ���0����ʾ������t��
���
�������ÿ���������Ĳ�α������
��������
2
AB0C00D00
ABCD00E000FG00H0I00
�������
ABDC
ABFCGHDEI

*/