//实验二：指针与引用实验
//editor：Anglica
//part 1

#include<iostream>
using namespace std;

void mySortbypointer(const int size, float* a);
void mySortbyreference(const int size, float* & p);

int main()
{
	int size;
	cout << "分别输入数组的大小和元素" << endl;
	cin >> size;
	float* a = new float[size];
	for (int i = 0; i < size; i++)
		cin >> a[i];
	//mySortbypointer(size, a);
	mySortbyreference(size, a);
	for (int i = 0; i < size; i++)
		cout << a[i];
	delete[] a;
	return 0;
}

void mySortbypointer(const int size, float* a)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				float temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void mySortbyreference(const int size, float* & p)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				float temp = *(p + j + 1);
				*(p + j + 1) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}

part 2
#include <iostream>

using namespace std;

int myGCD(int, int);
int myLCM(int, int);

int main()
{
	int x, y;
	cout << "输入两个数求最大共约数，最小公倍数" << endl;
	cin >> x >> y;
	int(*p)(int, int);
	p = myGCD;
	cout << p(x, y) << endl;
	p = myLCM;
	cout << p(x, y) << endl;
	return 0;
}
int myGCD(const int x, const int y)
{
	int a = x > y ? x : y;
	int b = x < y ? x : y;
	int c = a % b;
	if (c == 0)
		return b;
	else
		return myGCD(b, c);
}
int myLCM(const int x, const int y)
{
	return x * y / myGCD(x, y);
}
