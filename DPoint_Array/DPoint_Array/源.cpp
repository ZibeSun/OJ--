#include<iostream>
#include<stdio.h>
#include <iomanip>
#include<math.h>
using namespace std;
class Point
{
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	~Point();
	double getX();
	double getY();
	void setXY(double x1, double y1);
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(Point& p);
	Point(Point& p);
};
Point::Point()
{
	x = 0;
	y = 0;
	cout << "Constructor." << endl;
}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
}
Point::~Point()
{
	cout << "Distructor." << endl;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setXY(double x1, double y1)
{
	x = x1;
	y = y1;
}
void Point::setX(double x_value)
{
	x = x_value;
}
void Point::setY(double y_value)
{
	y = y_value;
}
double Point::getDisTo(Point& p)
{
	double distance;
	distance = sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY()));
	return distance;
}
Point::Point(Point &p)
{
	x = p.getX();
	y = p.getY();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Point *p = new Point[n];
		double x_value, y_value;
		for (int i = 0; i < n; i++)
		{
			cin >> x_value >> y_value;
			p[i].setXY(x_value, y_value);
		}
		double maxdis = 0;
		int p1 = 0, p2 = 0;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				if (maxdis < p[k].getDisTo(p[i]))
				{
					maxdis = p[k].getDisTo(p[i]);
					p1 = k;
					p2 = i;
				}
			}
		}
		cout << fixed << setprecision(2) << "The longeset distance is " << maxdis <<
			",between p[" << p1 << "] and p[" << p2 << "]." << endl;
		delete[]p;
	}
}
/*��Ŀ����


����������������ϰ����һ��ϰ�⣬����ԭ������Ļ������������޸ģ�1��������д�Ŀ������캯����2��������д������������3����getDisTo�����Ĳ����޸�ΪgetDisTo(const Point &p)��4��������������������޸���Ӧ�Ĺ��캯����

Ȼ�����������и����û��������Ŀ����Point���飬��������ھ�������������֮��ľ���ֵ��

����
�������ݵ����� t

��һ���ĸ���

��һ����� x ����   y����

�ڶ������ x����  y����

............

���
�����һ����������������Լ������

...........

��C++�У����ָ�����ȵĲο��������£�

#include <iostream>

#include <iomanip> //����������ͷ�ļ�

using namespace std;

void main( )

{ double a =3.141596;

  cout<<fixed<<setprecision(3)<<a<<endl;  //���С�����3λ

��������
2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0
�������
Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.*/