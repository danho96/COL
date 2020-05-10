#pragma once
#include "obj.h"
class Sphere :
	public Obj
{
	double radius;
public:

	Sphere(void);
	Sphere(double posX,double posY,double posZ,double radius,GLfloat * col);
	~Sphere(void);

	void draw();

	bool collision(Obj * obj);

	double getRadius(){ return radius; }

	double getMinx(){
		return posX-radius;
	}
	double getMaxx(){
		return posX+radius;
	}
	double getMiny(){
		return posY-radius;
	}
	double getMaxy(){
		return posY+radius;
	}
	double getMinz(){
		return posZ-radius;
	}
	double getMaxz(){
		return posZ+radius;
	}

	void Sphere::Cube_draw();
		
};

