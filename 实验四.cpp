//实验四：类与对象实验
//editor：Angelica
//part 1
//student.h
#include<string>

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_
class student
{
public:
	student();
	student(long long, string, float);
	~student();
	student(const student&);
	void setMessage();
	void showMessage()const;
private:
	long long ID;
	string name;
	float score;
};
#endif // !STUDENT_H_


//student.cpp
#include<iostream>
#include<string>

using namespace std;

student::student() :ID(20230000), name("某某"), score(0) {}
student::student(long long a, string b, float c) : ID(a), name(b), score(c) {}
student::~student() {}
student::student(const student& c)
{
	this->ID = c.ID;
	this->name = c.name;
	this->score = c.score;
}
void student::setMessage()
{
	cout << "Input your ID ,name ,score one by one" << endl;
	cin >> ID;
	cin >> name;
	cin >> score;
}
void student::showMessage() const
{
	cout << ID << ":" << name << ":" << score << endl;
}

//main.cpp
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	const student stu1(2023001, "张三", 99);
	student stu2(2023002, "李四", 88);
	stu1.showMessage();
	stu2.setMessage();
	stu2.showMessage();
	return 0;
}

//part 2

//time.h
#ifndef TIME_H_
#define TIME_H_
class Time
{
public:
	Time();
	Time(int, int, int);
	~Time();
	Time(const Time&);
	void setTime();
	void showTime()const;
private:
	int hour;
	int minute;
	int sec;
};
#endif // !TIME_H_


//time.cpp
#include<iostream>

using namespace std;

Time::Time():hour(0),minute(0),sec(0){}
Time::Time(int a, int b, int c): hour(a), minute(b), sec(c){}
Time::~Time(){}
Time::Time(const Time& c) 
{
	this->hour = c.hour;
	this->minute = c.minute;
	this->sec = c.sec;
}
void Time::setTime()
{
	cout << "Input hour minute second one by one" << endl;
	cin >> hour;
	cin >> minute;
	cin >> sec;
}
void Time::showTime() const
{
	cout << hour << ":" << minute << ":" << sec << endl;
}

//main.cpp
#include<iostream>
#include"time.h"
using namespace std;

int main(void)
{
	const Time time1(6, 6, 6);
	Time time2(8, 8, 8);
	const Time* p1 = &time1;
	Time* const p2 = &time2;
	p1->showTime();
	p2->setTime();
	p2->showTime();
	return 0;
}
