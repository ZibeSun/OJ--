#include<iostream>
#include<stack>
using namespace std;
//�Թ���
class Matrix
{
public:
	int m;
	int n;
	int** data;
public:
	Matrix(int x, int y)
	{
		m = x;
		n = y;
		data = new int* [m];			  //�ȴ���m��
		for (int i = 0; i < m; i++)
		{
			data[i] = new int[n];       //�ٴ���n��
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
	}
};
//���ڴ洢ͨ·����Ľṹ
struct cpos
{
	int x;
	int y;
	int z;    //��¼·���иø����һ���ڸø����ڵ��л��Ǹø������е���һ��
			  //z=0����ʾ�ø����һ���ڸø����ڵ���
			  //z=1����ʾ�ø����һ���ڸø������е���һ��
};
//�Թ���⺯��
void FindPath(Matrix& MiGong, stack<cpos>& path)
{
	if (MiGong.data[0][0] == 1)
	{
		cout << "no path" << endl;
		return;
	}
	else
	{
		cpos p;
		//����ڿ�ʼ�������ҵر����Թ���
		int i = 0;
		for (int j = 0; j <= MiGong.n; j++)
		{
			//����ø��ͨ�Ҳ����ڣ���ѹ��path��
			if ((MiGong.data[i][j] == 0) && (j != MiGong.n))
			{
				if ((path.empty() != true) && (path.top().x != i))
				{
					p.x = i;
					p.y = j;
					p.z = 1;
					path.push(p);
				}
				else
				{
					p.x = i;
					p.y = j;
					p.z = 0;
					path.push(p);
				}
				if ((i == MiGong.n - 1) && (j == MiGong.n - 1))
					break;
			}
			else if ((MiGong.data[i][j] == 1) || (j == MiGong.n))
			{
				//����ѵ�������һ�У����Թ��޽�
				if (i + 1 == MiGong.n)
				{
					cout << "no path" << endl;
					//cout << "test1" << endl;
					return;
				}
				else
				{
					//����ø񱻶�ס�������ڣ����ø�����һ���ͨ���������ߣ�
					if (MiGong.data[i + 1][j - 1] == 0)
					{
						i++;
						j -= 2;
					}
					// ����ø񱻶�ס�������ڣ��Ҹø�����һ�񱻶�ס���������˸�
					else if (MiGong.data[i + 1][j - 1] == 1)
					{
						int k = 0;
						//�����˸�ֱ��ĳһ�������һ���ͨ�У��������ߣ�
						//cout<<"test"<<endl;

						//����һ���ڵ�ǰ��һ��ʱ
						if (path.top().z == 0)
						{
							for (j -= 2; j >= 0; j--)
							{
								//cout<<"test1"<<endl;
								path.pop();
								if (MiGong.data[i][j] == 0)
								{
									if (MiGong.data[i + 1][j] == 0)
									{
										i++;
										j--;
										k++;
										break;
									}
									if (path.top().z == 1)
									{
										for (j -= 1; j >= 0; j--)
										{
											if (MiGong.data[i][j] == 0)
											{
												p.x = i;
												p.y = j;
												path.push(p);
												if (MiGong.data[i + 1][j] == 0)
												{
													i++;
													j--;
													k++;
													break;
												}
											}
											//�����˸�ʱ����ס
											else if (MiGong.data[i][j] == 1)
											{
												cout << "no path" << endl;
												//cout << "test2" << endl;
												return;
											}
										}
									}
								}
								//�����˸�ʱ����ס
								else if (MiGong.data[i][j] == 1)
								{
									cout << "no path" << endl;
									//cout << "test3" << endl;
									return;
								}
							}
						}
						//����һ��������һ��ʱ
						else if (path.top().z == 1)
						{
							for (j -= 2; j >= 0; j--)
							{
								//cout<<"test2"<<endl;
								if (MiGong.data[i][j] == 0)
								{
									p.x = i;
									p.y = j;
									path.push(p);
									if (MiGong.data[i + 1][j] == 0)
									{
										i++;
										j--;
										k++;
										break;
									}
								}
								//�����˸�ʱ����ס
								else if (MiGong.data[i][j] == 1)
								{
									cout << "no path" << endl;
									//cout << "test4" << endl;
									return;
								}
							}
						}
						//������������·���ˣ�Ҳ�޷�������ʱ�����Թ��޽⣻
						if (k == 0)
						{
							cout << "no path" << endl;
							//cout << "i=" << i << "j=" << j << endl;
							//cout << "test5" << endl;
							return;
						}
					}
				}
			}
		}
	}
	//��·��ѹ��peth1��ת�������
	stack<cpos> path1;
	while (path.empty() != true)
	{
		path1.push(path.top());
		path.pop();
	}
	//��·���������
	int i = 0;
	while (path1.empty() != true)
	{
		cpos c = path1.top();
		if ((++i) % 4 == 0)
			cout << "[" << c.x << "," << c.y << "]" << "--" << endl;
		else
			cout << "[" << c.x << "," << c.y << "]" << "--";
		path1.pop();
	}
	cout << "END" << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Matrix MiGong(n, n);
		stack<cpos> path;
		FindPath(MiGong, path);
	}
	return 0;
}
/*
��Ŀ����
����һ��N*N���Թ�����ʾ��ͼ�������[0,0]������Ѱ��·�������յ�[N-1, N-1]

Ҫ��ʹ�ö�ջ������ʵ�֣������㷨�ο��α�3.2.4��51ҳ

����
��һ������t����ʾ��t���Թ�

�ڶ�������n����ʾ��һ���Թ���n��n��

�������������Թ�ÿһ�е�ÿ�������״̬��0��ʾ��ͨ����1��ʾ����ͨ��

����n��

�Դ�����������һ���Թ�

���
�������Թ���·��

����Թ�������·���������no path���س�

����Թ�����·������·����ÿ�������x��y�������������㵽�յ㣬ÿ����ĸ�����ͻ��У������Ե���END��β�������ʽ�ο�ʾ������

����Ĵ���ο����£�

//path�Ǳ���·���Ķ�ջ����ջ��ÿ��Ԫ�ض�����x�����y���꣬������xp��yp��ʾ

//path1��һ����ʱ��ջ����path�����ݵ��������path1��ʹ��·�����������

	if (!path.empty())	//�ҵ�·��

	{	//......���ɴ��룬ʵ��path�����ݵ���path1

		i=0;  //���������·���Ĵ���

		while (!path1.empty())

		{	cpos = path1.top();

			if ( (++i)%4 == 0 )

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;

			else

				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";

			path1.pop();

		}

		cout<<"END"<<endl;

	}

	else

		cout<<"no path"<<endl; //�Ҳ���·�����no path

��������
2
8
0 0 0 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1
0 0 1 1 0 1 1 0
0 0 0 0 0 0 1 1
1 1 1 1 1 0 0 1
0 0 0 0 1 0 0 0
7
0 0 0 1 1 1 1
1 0 0 1 0 0 1
1 0 0 1 0 0 0
1 1 0 0 0 0 1
0 0 1 1 0 1 0
1 0 0 0 0 1 0
0 0 0 0 1 1 0
�������
[0,0]--[0,1]--[0,2]--[1,2]--
[1,3]--[2,3]--[3,3]--[3,4]--
[4,4]--[5,4]--[5,5]--[6,5]--
[6,6]--[7,6]--[7,7]--END
no path
*/