//实验八：虚基类实验
//editor：Angelica

//class.h
#include<iostream>
#include<string>

using namespace std;

#ifndef CLASS_H_
#define CLASS_H_
class Person
{
public:
	Person();
	~Person();
	Person(string,long long);
	Person(const Person&);
	void ShowInfo()const;
protected:
	string name;
	long long ID;
};

class Student:virtual public Person
{
public:
	Student();
	~Student();
	Student(string, long long,string);
	Student(const Student&);
	void ShowInfo()const;
protected:
	string profession;
};

class Teacher :virtual public Person
{
public:
	Teacher();
	~Teacher();
	Teacher(string, long long, string, string, int);
	Teacher(const Teacher&);
	void ShowInfo()const;
protected:
	string position;
	string work;
	int classnumber;
};
class TA :public Student,public Teacher
{
public:
	TA();
	~TA();
	TA(string,long long,string,string,string,int);
	TA(const TA&);
	void ShowInfo()const;
};
#endif // !CLASS_H_

//class.cpp
Person::Person():name("NULL"),ID(0) {}
Person::~Person(){}
Person::Person(string n,long long i):name(n), ID(i) {}
Person::Person(const Person& p)
{
	this->name = p.name;
	this->ID = p.ID;
}
void Person::ShowInfo()const
{
	cout << this->name <<endl
		<< this->ID << endl;
}

Student::Student() :Person(), profession("NULL") {}
Student::~Student() {}
Student::Student(string n, long long i, string p) :Person(n, i), profession(p) {}
Student::Student(const Student& p)
{
	this->name = p.name;
	this->ID = p.ID;
	this->profession = p.profession;
}
void Student::ShowInfo() const
{
	Person::ShowInfo();
	cout << this->profession << endl;
}

Teacher::Teacher() :Person(), position("NULL"),work("NULL"),classnumber(0) {}
Teacher::~Teacher() {}
Teacher::Teacher(string n, long long i, string p, string w, int c) :Person(n, i), position(p), work(w), classnumber(c) {}
Teacher::Teacher(const Teacher& p)
{
	this->name = p.name;
	this->ID = p.ID;
	this->position = p.position;
	this->work = p.work;
	this->classnumber = p.classnumber;
}
void Teacher::ShowInfo()const
{
	Person::ShowInfo();
	cout << this->position<<endl
		<<this->work<<endl
		<<this->classnumber<<endl;
}

TA::TA() :Student(), Teacher() {}
TA::~TA() {}
TA::TA(string n, long long i, string p,string po,string w,int c) :Person(n,i),Student(n,i,p), Teacher(n,i,po,w,c) {}
TA::TA(const TA& p)
{
	this->name = p.name;
	this->ID = p.ID;
	this->profession = p.profession;
	this->work = p.work;
	this->classnumber = p.classnumber;
}
void TA::ShowInfo()const
{
	cout << this->Student::name << endl
		<< this->Student::ID << endl
		<< this->profession << endl
		<< this->work << endl
		<< this->classnumber << endl;
}

//main.cpp
int main(void)
{
	TA TA1("lihua",2023001,"double E","TA","programer",10);
	TA1.ShowInfo();
	return 0;
}
 
