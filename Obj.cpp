#include "Obj.h"


Obj::Obj(void):posX(0.0),posY(0.0),posZ(0.0),col(NULL)
{
	int r= rand()%100;
	if(r>50) direction[0]=true;
	else direction[0]=false;
	
	r= rand()%100;
	if(r>50) direction[1]=true;
	else direction[1]=false;

	r= rand()%100;
	if(r>50) direction[2]=true;
	else direction[2]=false;
}

Obj::Obj(double posX,double posY,double posZ,GLfloat * col):posX(posX),posY(posY),posZ(posZ),col(col)
{
	int r= rand()%100;
	if(r>50) direction[0]=true;
	else direction[0]=false;
	
	r= rand()%100;
	if(r>50) direction[1]=true;
	else direction[1]=false;

	r= rand()%100;
	if(r>50) direction[2]=true;
	else direction[2]=false;
}



Obj::~Obj(void)
{
}

void Obj::setpos(double _posX,double _posY,double _posZ)
{
	posX=_posX;
	posY=_posY;
	posZ=_posZ;
}

void Obj::move(double dx,double dy,double dz)
{
	if(direction[0])
		posX+=dx;
	else
		posX-=dx;

	if(posX>LIMIT || posX<-LIMIT)
		direction[0]=!direction[0];

	if(direction[1])
		posY+=dy;
	else
		posY-=dy;

	if(posY>LIMIT || posY<-LIMIT)
		direction[1]=!direction[1];
	
	if(direction[2])
		posZ+=dz;
	else
		posZ-=dz;

	if(posZ>LIMIT || posZ<-LIMIT)
		direction[2]=!direction[2];


}


void Obj::change_direction()
{
	direction[0]=!direction[0];
	direction[1]=!direction[1];
	direction[2]=!direction[2];

}

void Obj::set_color(GLfloat * _col)
{
	col=_col;
}

