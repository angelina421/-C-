//实验五：静态成员实验
//editor：Angelica
//part 1
//student.h
#include<string>
#include<iostream>

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_
class Student
{
public:
	Student();
	Student(long long, string, float);
	~Student();
	Student(const Student&);
	void ChangeScore(float);
	static float GetAverage();
private:
	long long ID;
	string name;
	float score;
	static float total;
	static int count;
};
#endif // !STUDENT_H_

//student.cpp

float Student::total = 0;
int Student::count =0;
float Student::GetAverage() 
{
	return total / count;
}
Student::Student():ID(2023000),name("empty"),score(0)
{
	total += this->score;
	count++;
}
Student::Student(long long ID,string name,float score):ID(ID),name(name),score(score)
{
	total += this->score;
	count++;
}
Student::~Student(){}
Student::Student(const Student& c)
{
	this->ID = c.ID;
	this->name = c.name;
	this->score = c.score;
	total += this->score;
	count++;
}
void Student::ChangeScore(float changescore) 
{
	total += changescore - this->score;
	this->score = changescore;
}


//main.cpp
#include<iostream>

using namespace std;

int main(void) 
{
	Student stu[5] = {
		Student(2023001,"lihua",65),
		Student(2003002,"zhangqiang",78),
		Student(2023003,"heqian",98),
		Student(2023004,"wangli",66),
	};
	stu[2].ChangeScore(0);
	cout << "all of students' averagr score is " << Student::GetAverage() << endl;
	return 0;
}
