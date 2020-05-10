#pragma once
#include "obj.h"
class Cube :
	public Obj
{

	double sizex;
	double sizey;
	double sizez;

public:
	double getSizeX(){ return sizex; }
	double getSizeY(){ return sizey; }
	double getSizeZ(){ return sizez; }


	Cube(void);
	Cube(double posX,double posY,double posZ,double sizex,double sizey,double sizez,GLfloat *col);
	~Cube(void);

	void setpos(double posX,double posY,double posZ);
	void setsize(double sizex,double sizey,double sizez);

	
	void draw();

	bool collision(Obj * obj);
};

