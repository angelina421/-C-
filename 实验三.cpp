//实验三：字符串实验
//editor：Angelica
//part 1

#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str1, str2;
	str1 = "fuck", str2 = "you";
	if (str1 < str2)
	{
		str1 = str1 + " " + str2;
	}
	cout << str1 <<endl;
	return 0;
}

//part 2
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str[5];
	cout << "please input 5 strings" << endl;
	for (int i = 0; i < 5; i++)
		cin >> str[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - i; j++)
		{
			if (str[j] > str[j + 1])
			{
				string temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	for (int i = 0; i < 5; i++)
		cout << str[i] << endl;
	return 0;
}
