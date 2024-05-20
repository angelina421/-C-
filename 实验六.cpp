//实验六：友元函数实验
//editor：Angelica
//part 1

//class,h
#ifndef CLASS_H_
#define CLASS_H_
class Date;
class Time
{
public:
	Time();
	Time(int, int, int);
	~Time();
	Time(const Time&);
	void show_time(const Date&);
private:
	int hour;
	int minute;
	int sec;
};
class Date
{
public:
	Date();
	Date(int, int, int);
	~Date();
	Date(const Date&);
	friend Time;
private:
	int year;
	int month;
	int day;
};
#endif // !CLASS_H_

//class.cpp
#include<iostream>

 using namespace std;

Time::Time():hour(0), minute(0), sec(0){}
Time::Time(int a, int b, int c) :hour(a), minute(b), sec(c) {}
Time::~Time(){}
Time::Time(const Time& c)
{
	this->hour = c.hour;
	this->minute = c.minute;
	this->sec = c.sec;
}
Date::Date():year(0),month(0),day(0){}
Date::Date(int a, int b, int c) :year(a), month(b), day(c) {}
Date::~Date(){}
Date::Date(const Date& c)
{
	this->year = c.year;
	this->month = c.month;
	this->day = c.day;
}
void Time::show_time(const Date& r) 
{
	cout << r.year << " " << r.month << " " << r.day 
	<< " " << hour << " " << minute << " " << sec << endl;
}

//main.cpp

int main(void)
{
	Date date1(2023,1,1);
	Time time1(12,0,0);
	time1.show_time(date1);
	return 0;
}
