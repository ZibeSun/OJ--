#include<iostream>
using namespace std;
const int MaxW = 9999999;  // ������Ȩֵ������9999999
// ����huffman�������
class HuffNode
{
public:
    int weight;     // Ȩֵ
    int parent;     // ������±�
    int leftchild;  // �����±�
    int rightchild; // �Һ����±�
};
// ����շ�������
class HuffMan
{
private:
    void MakeTree();    // ������˽�к����������к�������
    void SelectMin(int pos, int* s1, int* s2);  // �� 1 �� pos ��λ���ҳ�Ȩֵ��С��������㣬�ѽ���±���� s1 �� s2 ��
public:
    int len;    // �������
    int lnum;   // Ҷ������
    int f;
    HuffNode* huffTree; // �շ��������������ʾ
    string* huffCode;   // ÿ���ַ���Ӧ�ĺշ�������
    void MakeTree(int n, int wt[]); // ���к�������������main����
    void Coding();  // ���к�������������main����
    void Destroy();
};
// ����huffman��
void HuffMan::MakeTree(int n, int wt[])
{
    // ������Ҷ�ӽ��������Ҷ��Ȩֵ
    // ���к���������ӿ�
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1];    // λ�ô� 1 ��ʼ����
    // huffCodeʵ���Ǹ���ά�ַ����飬�� i �б�ʾ�� i ���ַ���Ӧ�ı���
    // �շ�����huffTree��ʼ��
    for (i = 1; i <= n; i++)
        huffTree[i].weight = wt[i - 1]; // ��0�Ų��ã���1��ʼ���
    for (i = 1; i <= len; i++)
    {
        if (i > n) huffTree[i].weight = 0;  // ǰn�������Ҷ�ӣ��Ѿ�����
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // ����˽�к�������
    f = 0;
    for (int i = 0; i < n; i++)
    {
        f += wt[i];
    }
}
void HuffMan::SelectMin(int pos, int* s1, int* s2)
{
    // �ҳ���С������Ȩֵ���±�
    // �������õ�ַ���ݵķ������ҳ������±걣���� s1 �� s2 ��
    int w1, w2, i;
    w1 = w2 = MaxW;  // ��ʼ��w1��w2Ϊ���ֵ���ڱȽ��лᱻʵ�ʵ�Ȩֵ�滻
    *s1 = *s2 = 0;
    for (i = 1; i <= pos; i++)
    {
        // �ȽϹ������£�
        // ����� i ������ȨֵС�� w1���ҵ� i �������δѡ��Ľ�㣬��ʾ������� i ���δѡ��������Ϊ 0
        // �ѵ� w1 �� s1 ���浽 w2 �� s2����ԭ���ĵ�һ��Сֵ��ɵڶ���Сֵ
        // �ѵ� i ����Ȩֵ���±걣�浽 w1 �� s1����Ϊ��һ��Сֵ
        // ��������� i ����ȨֵС�� w2���ҵ� i �����δѡ��Ľ��
        // �ѵ� i ����Ȩֵ���±걣�浽 w2 �� s2����Ϊ�ڶ���Сֵ
        if ((huffTree[i].weight < w1) && (huffTree[i].parent == 0))
        {
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else if ((huffTree[i].weight < w2) && (huffTree[i].parent == 0))
        {
            w2 = huffTree[i].weight;
            *s2 = i;
        }
    }
}
void HuffMan::MakeTree()
{
    // ˽�к����������к�������
    int i, s1, s2;
    for (i = lnum + 1; i <= len; i++)
    {
        SelectMin(i - 1, &s1, &s2);  // �ҳ�������СȨֵ���±���� s1 �� s2 ��
        // ���ҳ�������Ȩֵ��С�������ϲ�Ϊһ�����������̰���
        // ��� s1 �ͽ�� s2 �ĸ�����Ϊ i
        // ��� i �����Һ��ӷֱ���Ϊ s1 �� s2
        // ��� i ��Ȩֵ���� s1 �� s2 ��Ȩֵ��
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild= s2;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}
// ���ٺշ�����
void HuffMan::Destroy()
{
    len = 0;
    lnum = 0;
    delete[]huffTree;
    delete[]huffCode;
}
// �շ�������
void HuffMan::Coding()
{
    string code; // �洢���ŵĲ����������Ʊ���
    int i, j, k, parent;
    for (i = 1; i <= lnum; i++)
    { // ��Ҷ�ӽ�����
        j = i;
        code = ""; // ��ʼ��Ϊ��
        while (huffTree[j].parent != 0) { // �����ҵ������
            parent = huffTree[j].parent; // �����
            if (j == huffTree[parent].leftchild) // ��������ӣ����Ϊ0
                code += "0";
            else // �Һ��ӣ���Ϊ1
                code += "1";
            j = parent; // ���Ƶ������
        }
        // ����Ҫ����������Ϊ�Ǵ�Ҷ�������ߵ�������������Ҫ�Ӹ��ߵ�Ҷ�ӽ��
        for (k = (int)code.size() - 1; k >= 0; k--)
            huffCode[i] += code[k]; // �������
    }
}
// ������
int main()
{
    int t, n, i;
    int wt[800];
    HuffMan myHuff;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        myHuff.MakeTree(n, wt);
        myHuff.Coding();
        for (i = 1; i <= n; i++)
        {
            cout << myHuff.huffTree[i].weight << '-';   // �����Ȩֵ
            cout << myHuff.huffCode[i] << endl; // ���������
        }
        myHuff.Destroy();
    }
    return 0;
}
/*
��Ŀ����
����n��Ȩֵ��������ЩȨֵ����huffman����������huffman����
�ο��α��㷨��ע����������Ǵ�λ��1��ʼ
Ҫ�󣺺շ����Ĺ����У�Ĭ������Ȩֵ�������Һ���Ȩֵ
�����ܲο����£�
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MaxW = 9999999;  // ������Ȩֵ������9999999
// ����huffman�������
class HuffNode
{
public:
    int weight;     // Ȩֵ
    int parent;     // ������±�
    int leftchild;  // �����±�
    int rightchild; // �Һ����±�
};
// ����շ�������
class HuffMan
{
private:
    void MakeTree();    // ������˽�к����������к�������
    void SelectMin(int pos, int *s1, int*s2);  // �� 1 �� pos ��λ���ҳ�Ȩֵ��С��������㣬�ѽ���±���� s1 �� s2 ��
public:
    int len;    // �������
    int lnum;   // Ҷ������
    HuffNode *huffTree; // �շ��������������ʾ
    string *huffCode;   // ÿ���ַ���Ӧ�ĺշ�������
    void MakeTree(int n, int wt[]); // ���к�������������main����
    void Coding();  // ���к�������������main����
    void Destroy();
};
// ����huffman��
void HuffMan::MakeTree(int n, int wt[])
{
    // ������Ҷ�ӽ��������Ҷ��Ȩֵ
    // ���к���������ӿ�
    int i;
    lnum = n;
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];
    huffCode = new string[lnum + 1];    // λ�ô� 1 ��ʼ����
    // huffCodeʵ���Ǹ���ά�ַ����飬�� i �б�ʾ�� i ���ַ���Ӧ�ı���
    // �շ�����huffTree��ʼ��
    for(i = 1; i <= n; i ++)
        huffTree[i].weight = wt[i - 1]; // ��0�Ų��ã���1��ʼ���
    for(i = 1; i <= len; i ++)
    {
        if(i > n) huffTree[i].weight = 0;  // ǰn�������Ҷ�ӣ��Ѿ�����
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();  // ����˽�к�������
}
void HuffMan::SelectMin(int pos, int *s1, int *s2)
{
    // �ҳ���С������Ȩֵ���±�
    // �������õ�ַ���ݵķ������ҳ������±걣���� s1 �� s2 ��
    int w1, w2, i;
    w1 = w2 = MaxW;  // ��ʼ��w1��w2Ϊ���ֵ���ڱȽ��лᱻʵ�ʵ�Ȩֵ�滻
    *s1 = *s2 = 0;
    for(i = 1; i <= pos; i ++)
    {
        // �ȽϹ������£�
        // ����� i ������ȨֵС�� w1���ҵ� i �������δѡ��Ľ�㣬��ʾ������� i ���δѡ��������Ϊ 0
        // �ѵ� w1 �� s1 ���浽 w2 �� s2����ԭ���ĵ�һ��Сֵ��ɵڶ���Сֵ
        // �ѵ� i ����Ȩֵ���±걣�浽 w1 �� s1����Ϊ��һ��Сֵ
        // ��������� i ����ȨֵС�� w2���ҵ� i �����δѡ��Ľ��
        // �ѵ� i ����Ȩֵ���±걣�浽 w2 �� s2����Ϊ�ڶ���Сֵ
    }
}
void HuffMan::MakeTree()
{
    // ˽�к����������к�������
    int i, s1, s2;
    for(i = lnum + 1; i <= len; i ++)
    {
        SelectMin(i - 1, &s1, &s2);  // �ҳ�������СȨֵ���±���� s1 �� s2 ��
        // ���ҳ�������Ȩֵ��С�������ϲ�Ϊһ�����������̰���
        // ��� s1 �ͽ�� s2 �ĸ�����Ϊ i
        // ��� i �����Һ��ӷֱ���Ϊ s1 �� s2
        // ��� i ��Ȩֵ���� s1 �� s2 ��Ȩֵ��
    }
}
// ���ٺշ�����
void HuffMan::Destroy()
{
    len  = 0;
    lnum = 0;
    delete []huffTree;
    delete []huffCode;
}
// �շ�������
void HuffMan::Coding()
{
    char *cd;
    int i, c, f, start;
    // �� n �����ĺշ�������
    cd = new char[lnum];    // ���������Ĺ����ռ�
    cd[lnum - 1] = '\0';    // ���������
    for(i = 1; i <= lnum; ++ i)
    {
        // ����ַ���շ�������
        start = lnum - 1;   // ���������λ��
        // �ο��α�P147�㷨6.12 HuffmanCoding����
        huffCode[i].assign(&cd[start]); // ��cd�д�start��ĩβ�ı��븴�Ƶ�huffCode��
    }
    delete []cd;    // �ͷŹ����ռ�
}
// ������
int main()
{
    int t, n, i, j;
    int wt[800];
    HuffMan myHuff;
    cin >> t;
    for(i = 0; i < t; i ++)
    {
        cin >> n;
        for(j = 0; j < n; j ++)
        {
            cout << myHuff.huffTree[j].weight << '-';   // �����Ȩֵ
            cout << myHuff.huffCode[j] << endl; // ���������
        }
        myHuff.Destroy();
    }
    return 0;
}
����
��һ������t����ʾ��t������ʵ��
�ڶ���������n����ʾ��1��ʵ����n��Ȩֵ����������n��Ȩֵ��Ȩֵȫ��С��1���������
��������
���
�������ÿ��Ȩֵ��Ӧ�ı��룬��ʽ���£�Ȩֵ-����
��ÿ�������1��Ȩֵ�������һ���̻��ߣ��������Ӧ���룬������һ��������һ��Ȩֵ�ͱ��롣
�Դ�����
��������
1
5 15 4 4 3 2
�������
15-1
4-010
4-011
3-001
2-000

*/