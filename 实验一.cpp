//实验一：函数重载实验
//editor：Angelica
//part 1
#include<iostream>

using namespace std;

int my_max(int x, int y);
float my_max(float x, float y, float z);

int main()
{
  cout << my_max(9, 1) << endl;
  cout << my_max(1.1, 3.3, 2.2) << endl;
  return 0;
}

int my_max(int a, int b)
{
	return a > b ? a : b;
}

float my_max(float a, float b, float c)
{
	float result = a > b ? a : b;
	return result > c ? result : c;
}


//part 2
#include<iostream>

using namespace std;

void my_sort(int&, int&);
void my_sort(float&, float&, float&);

int main()
{
	int a = 90, b = 20;
	float c = 9.1, d = 2.2, e = 3.3;
	my_sort(a, b);
	cout << a << ' ' << b << endl;
	my_sort(c, d, e);
	cout << c << ' ' << d << ' ' << e << endl;;
	return 0;
}
void my_sort(int& a, int& b)
{
	if (a > b)
	{
		int temp = a;
		a = b; 
		b = temp;
	}
}
void my_sort(float& a, float& b, float& c)
{
	float min,max;
	min = a < b ? a : b;
	min = min < c ? min : c;
	max = a > b ? a : b;
	max = max > c ? max : c;
	b = a + b + c - min - max;
	a = min;
	c = max;
}
