//实验七：继承与派生实验
//editor：Angelica
//class.h
#include<string>
#include<iostream>

using namespace std;

#ifndef CLASS_H_
#define CLASS_H_
class Undergraduate
{
public:
	Undergraduate();
	~Undergraduate();
	Undergraduate(long long, string, string);
	Undergraduate(const Undergraduate&);
protected:
	long long ID;
	string name;
	string profession;
};
class Graduate:public Undergraduate
{
public:
	Graduate();
	~Graduate();
	Graduate(long long,string,string,string,int);
	Graduate(const Graduate&);
	void showInfo(void);
private:
	string tutor;
	int paper_posting;
};
#endif // !CLASS_H_

//class.cpp
Undergraduate::Undergraduate():ID(2003001),name("lihua"),profession("electrical engineer"){}

Undergraduate::~Undergraduate(){}

Undergraduate::Undergraduate(long long i, string n, string p):ID(i),name(n),profession(p){}

Undergraduate::Undergraduate(const Undergraduate& c)
{
	this->ID = c.ID;
	this->name = c.name;
	this->profession = c.profession;
}

Graduate::Graduate():Undergraduate(), tutor("lili"), paper_posting(0) {}

Graduate::~Graduate(){}

Graduate::Graduate(long long i, string n, string p, string t, int num):Undergraduate(i,n,p),tutor(t),paper_posting(num){}

Graduate::Graduate(const Graduate& c)
{
	this->ID = c.ID;
	this->name = c.name;
	this->profession = c.profession;
	this->tutor = c.tutor;
	this->paper_posting = c.paper_posting;
}
void Graduate::showInfo(void) 
{
	cout << "ID:" << this->ID << endl;
	cout << "name:" << this->name << endl;
	cout << "profession:" << this->profession << endl;
	cout << "tutor:" << this->tutor << endl;
	cout <<"paper_posting number:" << this->paper_posting << endl;
}

//main.cpp
int main(void)
{
	Graduate stu1(2023007,"liming","scientist","laowang",10);
	stu1.showInfo();
  return 0;
}
