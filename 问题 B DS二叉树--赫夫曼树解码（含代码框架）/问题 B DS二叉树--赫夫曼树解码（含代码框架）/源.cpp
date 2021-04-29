#include<iostream>
using namespace std;
const int MaxW = 9999999;  // ������Ȩֵ������9999999
// ����huffman�������
class HuffNode
{
public:
    int weight;     // Ȩֵ
    char ch;        //Ȩֵ��Ӧ���ַ�
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
    void MakeTree(int n, int *wt,char *ch); // ���к�������������main����
    void Coding();  // ���к�������������main����
    void Destroy();
    void Decode(const string codestr);
};
// ����huffman��
void HuffMan::MakeTree(int n, int *wt,char *ch)
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
    {
        huffTree[i].weight = wt[i - 1]; // ��0�Ų��ã���1��ʼ���
        huffTree[i].ch = ch[i - 1];
    }
    for (i = 1; i <= len; i++)
    {
        if (i > n)
        {
            huffTree[i].weight = 0;  // ǰn�������Ҷ�ӣ��Ѿ�����
            huffTree[i].ch = '0';
        }
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
        huffTree[i].rightchild = s2;
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
//�շ�������
void HuffMan::Decode(const string codestr)
{
    string txtstr;
    int c = len;
    char error_recode = '0';
    txtstr = "";
    for (int i = 0; i < codestr.length(); i++)
    {
        if (codestr[i] == '0')
        {
            c = huffTree[c].leftchild;
            //cout << "test1" << endl;
        }
        else if (codestr[i] == '1')
        {
            c = huffTree[c].rightchild;
            //cout << "test2" << endl;
        }
        else
        {
            cout << "error" << endl;
            return;
        }
        if (huffTree[c].ch == '0')
        {
            error_recode = '0';
            //cout << "test3" << endl;
            //cout << "c=" << c << endl;
            //cout << huffTree[c].ch << endl;
        }
        else
        {
            txtstr += huffTree[c].ch;
            error_recode = huffTree[c].ch;
            c = len;
            //cout << "test4" << endl;
        }
    }
    if (error_recode == '0')
        cout << "error" << endl;
    else
        cout << txtstr << endl;
    return;
}
int main()
{
	int t;
	cin >> t;
	int n;
	int k;
	while (t--)
	{
		cin >> n;
        int* wt = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}
        char* ch = new char[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        HuffMan myHuff;
        myHuff.MakeTree(n, wt, ch);
		cin >> k;
        string* codestr = new string[k];
		for (int i = 0; i < k; i++)
		{
			cin >> codestr[i];
		}
        for (int i = 0; i < k; i++)
        {
            myHuff.Decode(codestr[i]);
        }
	}
    return 0;
}
/*
//�շ�������
int HuffMan::Decode(const string codestr,char txtstr[])
{//���봮��codestr������������txtstr��
 //����0��ʾ�������ƶ�������1��ʾ���Һ����ƶ�
	int i, k, c;
	char ch; 
	c=len;//c��ʾ���������±�
	//������ǽ����������һ����㣬����cһ��ʼָ������

	k=0; //txtstr��ָ�� 
	for (1=0; i<codestr.length();i++) 
	{
	//������������
		//ȡ���봮�ĵ�i���ַ��������ch
		//���ch���ַ�0����ʾ�������ƶ�����c��ת������
		//���ch���ַ�1����ʾ���Һ����ƶ�����c��ת���Һ���
		//���ch��0��1����ʾ���봮�д��󣬷���error��ʾ����ʧ��
		//���cָ��Ľ���Ƿ���Ҷ��
			//���봮txtstr�ĵ�kλ�ñ�����c�ڵ��ַ�
			//k++
			//c���ظ��ڵ�
		//����
			//ch='\0';	//����cliֵ�����ڼ�鲻��������ı���
	} 
	if (ch=='\0') return error;
	else txtstr[k]=='\0';	//����ɹ��������ַ���������
	return ok;
}
*/