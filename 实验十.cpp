//实验十：虚函数多态性实验
//editor：Angelica
//part 1
#include<iostream>
#include<string>
#define PI 3.1415926

using namespace std;

#ifndef CLASS_H_
#define CLASS_H_

class Cshape
{
public:
	virtual ~Cshape();
	virtual void DispAttr() = 0;
	virtual float Sarea() = 0;
	virtual float Volume() = 0;
};

class Sphere:public Cshape
{
public:
	Sphere();
	Sphere(float);
	Sphere(const Sphere&);
	virtual ~Sphere();
	virtual void DispAttr();
	virtual float Sarea();
	virtual float Volume();
private:
	float r;
};

class Cube:public Cshape
{
public:
	Cube();
	Cube(float);
	Cube(const Cube&);
	virtual ~Cube();
	virtual void DispAttr();
	virtual float Sarea();
	virtual float Volume();
private:
	float side;
};

class Cuboid:public Cshape
{
public:
	 Cuboid();
	 Cuboid( float,float,float );
	 Cuboid(const Cuboid &);
	virtual ~Cuboid();
	virtual void DispAttr();
	virtual float Sarea();
	virtual float Volume();
private:
	float length;
	float width;
	float heigh;
};

class Cylinder:public Cshape 
{
public:
	Cylinder();
	Cylinder(float,float);
	Cylinder(const Cylinder&);
	virtual ~Cylinder();
	virtual void DispAttr();
	virtual float Sarea();
	virtual float Volume();
private:
	float r;
	float heigh;
};

#endif // !CLASS_H_

Cshape::~Cshape(){}

Sphere::Sphere():r(0){}
Sphere::Sphere(float r):r(r) {}
Sphere::Sphere(const Sphere& rs) 
{
	this->r = rs.r;
}
Sphere::~Sphere(){}
void Sphere::DispAttr()
{
	cout << "this is a sphere" << endl;
	cout << "r=" << r << endl;
}
float Sphere::Sarea()
{
	return 4 * PI * r * r;
}
float Sphere::Volume()
{
	return 4 * PI * r * r * r / 3;
}

Cube::Cube():side(0){}
Cube::Cube(float s) :side(s) {}
Cube::Cube(const Cube& rc)
{
	this->side = rc.side;
}
Cube::~Cube(){}
void Cube::DispAttr()
{
	cout << "this is a cube" << endl;
	cout << "s=" << side << endl;
}
float Cube::Sarea()
{
	return 6 * side * side;
}
float Cube::Volume()
{
	return side * side * side;
}

 Cuboid::Cuboid():length(0),width(0),heigh(0){}
 Cuboid::Cuboid(float l,float w,float h) :length(l), width(w), heigh(h) {}
 Cuboid::Cuboid(const Cuboid& rc)
 {
	 this->length = rc.length;
	 this->width = rc.width;
	 this->heigh = rc.heigh;
 }
 Cuboid::~Cuboid(){}
 void Cuboid::DispAttr()
 {
	 cout << "this is a cuboid" << endl;
	 cout << "length=" << length << endl
		 << "width=" << width << endl
		 << "heigh=" << heigh << endl;
 }
 float Cuboid::Sarea()
 {
	 return 2*length*width+ 2*length*heigh +2* width*heigh;
 }
 float Cuboid::Volume()
 {
	 return length*width*heigh;
 }

Cylinder::Cylinder():r(0),heigh(0){}
Cylinder::Cylinder(float r,float h) :r(r), heigh(h) {}
Cylinder::Cylinder(const Cylinder& rc)
{
	this->r = rc.r;
	this->heigh = rc.heigh;
}
Cylinder::~Cylinder(){}
void Cylinder::DispAttr()
{
	cout << "this is a cylinder" << endl;
	cout << "r=" << r << endl
		<< "heigh=" << heigh << endl;
}
float Cylinder::Sarea()
{
	return  2 * PI * r * r + 2 * PI * r * heigh;
}
float Cylinder::Volume()
{
	return PI * r * r * heigh;
}

int main(void)
{
	Sphere s1(2);
	Cube c1(2);
	Cuboid c2(1, 2, 3);
	Cylinder cy1(1, 3);
	Cshape* pt;
	pt = &s1;
	pt->DispAttr();
	cout << "S=" << pt->Sarea() << endl
		<< "V=" << pt->Volume() << endl;

	pt = &c1;
	pt->DispAttr();
	cout << "S=" << pt->Sarea() << endl
		<< "V=" << pt->Volume() << endl;

	pt = &c2;
	pt->DispAttr();
	cout << "S=" << pt->Sarea() << endl
		<< "V=" << pt->Volume() << endl;

	pt = &cy1;
	pt->DispAttr();
	cout << "S=" << pt->Sarea() << endl
		<< "V=" << pt->Volume() << endl;
	return 0;
}
