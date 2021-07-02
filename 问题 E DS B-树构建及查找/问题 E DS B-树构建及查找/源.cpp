#include <iostream>     
#include <queue> 
using namespace std;

int m;

class BTNode
{
public:
	int keyNum; // �ؼ��ָ��� 
	BTNode* parent; // ָ��˫�׽�� 
	int* keys; // �ؼ������� 
	BTNode** ptr; // ����ָ������ 
	BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}

	~BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}
};

class Result
{
public:
	BTNode* pt; // ָ���ҵ��Ľ��
	int i;
	int tag;
	Result(BTNode* p, int m, int t)
	{
		pt = p;
		i = m;
		tag = t;
	}

	~Result()
	{
		pt = NULL;
		i = 0;
		tag = 0;
	}
};

class BTree
{
private:
	BTNode* root;
	void insert(BTNode* t, int i, int k, BTNode* ap); // ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1] 
	int search(BTNode* t, int k); // ��p->key[1...keynum]�в��� k
	void split(BTNode* q, int s, BTNode*& ap); // ��q->key[s+1...m],q->ptr[s...m]�����½��ap 
	void newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap); // ���ɺ���Ϣ(t, x, ap)���¸����t*ap, ԭt�� apΪ����ָ��
	void insertBT(BTNode*& t, int k, BTNode* q, int i); // �ڽ��t���ӽ��q��key[i]��key[i+1]֮�����k 
	Result* searchBT(BTNode* t, int k); // �ڽ��t�в���k 
public:
	BTree();
	~BTree();
	void insertBT(int key); // B-��������� 
	void searchBT(int key); // B-�����Ҳ��� 
	void levelOrder(); // B-����α��� 
};

void BTree::insert(BTNode* t, int i, int k, BTNode* ap)
{
	// ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1]
}

int BTree::search(BTNode* t, int k)
{
	// ��p->key[1...keynum]�в��� k
}

void BTree::split(BTNode* q, int s, BTNode*& ap)
{
	// ��q->key[s+1...m],q->ptr[s...m]�����½��ap 
}

void BTree::newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap)
{
	// ���ɺ���Ϣ(t, x, ap)���¸����t, ԭt�� apΪ����ָ��
}

Result* BTree::searchBT(BTNode* t, int k)
{
	// �ο��α�240ҳ�㷨9.13
}

void BTree::insertBT(BTNode*& t, int k, BTNode* q, int i)
{
	// �ο��α�244ҳ�㷨9.14
}

// B����ʼ�� 
BTree::BTree()
{
	root = NULL;
}

BTree::~BTree()
{
	root = NULL;
}

// B-���������
void BTree::insertBT(int key)
{
	Result* r = searchBT(root, key);
	if (!r->tag)
	{
		insertBT(root, key, r->pt, r->i);
	}
	return;
}

// B-�����Ҳ���
void BTree::searchBT(int key)
{
	Result* r = searchBT(root, key);
	if (!r->tag)
	{
		cout << "-1" << endl;
	}
	else
	{
		BTNode* p = r->pt;
		cout << p->keys[1];
		for (int i = 2; i <= p->keyNum; i++)
		{
			cout << ':' << p->keys[i];
		}
		cout << ' ' << r->i << endl;
	}
	return;
}

// B-����α�������ؼ��� 
void BTree::levelOrder()
{
	queue<BTNode*> tq;
	BTNode* p = root;
	// �׽����� 
	if (p)
	{
		tq.push(p);
	}
	// ��α����� 
	while (!tq.empty())
	{
		p = tq.front();
		tq.pop();
		// ������p��key 
		cout << p->keys[1];
		for (int i = 2; i <= p->keyNum; i++)
		{
			cout << ':' << p->keys[i];
		}
		cout << ' ';
		// �Խ����ջ 
		for (int i = 0; i <= p->keyNum; i++)
		{
			if (!p->ptr[i])
			{
				break;
			}
			tq.push(p->ptr[i]);
		}
	}
	return;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> m;
		int n, k, key;
		// ����B-�� 
		cin >> n;
		BTree bTree;
		while (n--)
		{
			cin >> key;
			bTree.insertBT(key);
		}
		// ����α������B-�� 
		bTree.levelOrder();
		cout << endl;
		// ����B-����� 
		cin >> k;
		while (k--)
		{
			cin >> key;
			bTree.searchBT(key);
		}
	}
	return 0;
}
/*
��Ŀ����
�ڳ�ʼΪ�յ�m��B-�������β���n����㣬����α�������ؼ��֣�Ȼ���ٲ���m���ؼ��������ڽ��Ĺؼ����е�λ�á�
Ҫ��ʵ��B-����������ʹ�ø���⺯����
����ο�ģ�壺
#include <iostream>     #include <queue>
using namespace std;

int m;

class BTNode
{
	public:
		int keyNum; // �ؼ��ָ���
	BTNode *parent; // ָ��˫�׽��
	int *keys; // �ؼ�������
	BTNode **ptr; // ����ָ������
	BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}

	~BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}
};

class Result
{
	public:
		BTNode *pt; // ָ���ҵ��Ľ��
	int i;
	int tag;
	Result(BTNode *p, int m, int t)
	{
		pt = p;
		i = m;
		tag = t;
	 }

	~Result()
	{
		pt = NULL;
		i = 0;
		tag = 0;
	}
};

class BTree
{
	 private:
		 BTNode *root;
	 void insert(BTNode *t, int i, int k, BTNode *ap); // ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1]
	 int search(BTNode *t, int k); // ��p->key[1...keynum]�в��� k
	 void split(BTNode *q, int s, BTNode *&ap); // ��q->key[s+1...m],q->ptr[s...m]�����½��ap
	 void newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap); // ���ɺ���Ϣ(t, x, ap)���¸����t*ap, ԭt�� apΪ����ָ��
	 void insertBT(BTNode *&t, int k, BTNode *q, int i); // �ڽ��t���ӽ��q��key[i]��key[i+1]֮�����k
	 Result *searchBT(BTNode *t, int k); // �ڽ��t�в���k
	 public:
	 BTree();
	~BTree();
	 void insertBT(int key); // B-���������
	 void searchBT(int key); // B-�����Ҳ���
	 void levelOrder(); // B-����α���
};

void BTree::insert(BTNode *t, int i, int k, BTNode *ap)
{
	// ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1]
}

int BTree::search(BTNode *t, int k)
{
	// ��p->key[1...keynum]�в��� k
}

void BTree::split(BTNode *q, int s, BTNode *&ap)
{
	// ��q->key[s+1...m],q->ptr[s...m]�����½��ap 
}

void BTree::newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap)
{
	// ���ɺ���Ϣ(t, x, ap)���¸����t, ԭt�� apΪ����ָ��
}

Result *BTree::searchBT(BTNode *t, int k)
{
	// �ο��α�240ҳ�㷨9.13
}

void BTree::insertBT(BTNode *&t, int k, BTNode *q, int i)
{
	// �ο��α�244ҳ�㷨9.14
}

// B����ʼ��
BTree::BTree()
{
	 root = NULL;
}

BTree::~BTree()
{
	 root = NULL;
}

// B-���������
void BTree::insertBT(int key)
{
	 Result *r = searchBT(root, key);
	 if(!r->tag)
	 {
		  insertBT(root, key, r->pt, r->i);
	 }
	 return;
}

// B-�����Ҳ���
void BTree::searchBT(int key)
{
	Result *r = searchBT(root, key);
	if(!r->tag)
	{
		 cout << "-1" << endl;
	}
	 else
	{
		 BTNode *p = r->pt;
	 cout << p->keys[1];
	 for(int i = 2; i <= p->keyNum; i ++)
	{
		 cout << ':' << p->keys[i];
	 }
	 cout <<' '<< r->i << endl;
	}
	return;
}

// B-����α�������ؼ���
void BTree::levelOrder()
{
	 queue<BTNode *> tq;
	 BTNode *p = root;
	 // �׽�����
	 if(p)
	 {
		  tq.push(p);
	 }
	 // ��α�����
	 while(!tq.empty())
	 {
		  p = tq.front();
	  tq.pop();
	  // ������p��key
	  cout << p->keys[1];
	  for(int i = 2; i <= p->keyNum; i ++)
	  {
		   cout << ':' << p->keys[i];
	   }
		   cout << ' ';
	  // �Խ����ջ
		  for(int i = 0; i <= p->keyNum; i ++)
		  {
			   if(!p->ptr[i])
			   {
				break;
		}
			   tq.push(p->ptr[i]);
	  }
	 }
	 return;
}

int main(void)
{
	 int t;
	 cin >> t;
	 while(t --)
	 {
		  cin >> m;
	  int n, k, key;
	  // ����B-��
	  cin >> n;
	  BTree bTree;
	  while(n --)
	  {
		   cin >> key;
		   bTree.insertBT(key);
	  }
	 // ����α������B-��
	  bTree.levelOrder();
	  cout << endl;
	  // ����B-�����
	  cin >> k;
	  while(k --)
	 {
		  cin >> key;
		  bTree.searchBT(key);
	  }
	  }
	  return 0;
}
����
��һ������t����ʾ��t����������
�ڶ�������m, ��ʾҪ����m��B-��
����������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������k����ʾҪ����k������
�ӵ�����������k�У�ÿ��һ��Ҫ���ҵ����ݣ�������Ȼ��
�Դ�����������һ��ʾ��
���
��һ�����B-���Ĺؼ��֣�ͬһ�����Ĺؼ���֮����:�������ͬ���֮��Ĺؼ�����һ���ո������������в�α������Եõ���
�ӵڶ�����������ҽ����������ҳɹ���������ڽ��Ĺؼ��֣��ؼ���֮����:������������ڽ��ؼ����е�λ�ã��������ʧ�����-1��
�Դ����������һ��ʾ���Ľ��
��������
3
3
3
21 45 65
2
45
-10
3
7
21 45 65 25 31 52 55
2
55
35
4
6
45 24 53 90 46 47
4
46
45
90
20
�������
45 21 65
45 1
-1
45 25 55 21 31 52 65
55 1
-1
46:53 24:45 47 90
46:53 1
24:45 2
90 1
-1
��ʾ

*/
