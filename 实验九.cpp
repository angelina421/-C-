//实验九：组合类实验
//editor：Angelica
//part 1

//class.h
#include<iostream>
#include<string>
#ifndef CLASS_H_
#define CLASS_H_
using namespace std;
class Student
{
public:
	Student();
	Student(int,string,float);
	Student(const Student&);
	~Student();
	float Getscore()
	{
		return score;
	}
private:
	long long id;
	string name;
	float score;
};
class Lesson
{
public:
	Lesson();
	Lesson(int, string, string);
	Lesson(const Lesson&);
	~Lesson();
	void AddStudent(int,string,float);
	float GetPassRate();
	void ShowInfo();
private:
	int id;
	string name;
	string teacher;
	int num;
	Student s[100];
};
#endif // !CLASS_H_
//class.cpp

Student::Student():id(0),name("NULL"),score(0) {}
Student::Student(int i,string n,float s) :id(i), name(n), score(s){}
Student::Student(const Student& rs)
{
	this->id = rs.id;
	this->name = rs.name;
	this->score = rs.score;
}
Student::~Student(){}
Lesson::Lesson() :id(0), name("NULL"), teacher("NULL"), num(0) {}
Lesson::Lesson(int i,string n,string t) :id(i), name(n),teacher(t),num(0) {}
Lesson::Lesson(const Lesson& rl)
{
	this->id = rl.id;
	this->name = rl.name;
	this->teacher = rl.teacher;
	this->num = rl.num;
	for (int i = 0; i < num; ++i) 
	{
		s[i] = rl.s[i];
	}
}
Lesson::~Lesson(){}
void Lesson::AddStudent(int id, string name, float score)
{
	s[num] = Student(id, name, score);
	(this->num)++;
}
float Lesson::GetPassRate()
{
	int cnt = 0;
	for (int i = 0; i < num + 1; i++)
	{
		if ((s+i)->Getscore() >= 60)
			cnt++;
	}
	return (float)cnt / (float)num;
}
void Lesson::ShowInfo()
{
	cout << "id:" << id << endl
		<< "name:" << name << endl
		<< "teacher:" << teacher << endl;
	for (int i = 0; i < num; ++i) 
		cout << "Student " << i + 1 << ": " << s[i].Getscore() << endl;
	
}
//main.cpp
int main()
{
	Lesson program(6, "C++", "somebody");
	program.AddStudent(1, "lili", 10);
	program.AddStudent(2, "wangming", 20);
	program.AddStudent(3, "liulili", 70);
	cout << "PassRate" << program.GetPassRate() << endl;
	program.ShowInfo();
	return 0;
}
