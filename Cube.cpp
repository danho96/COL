#include "Cube.h"
#include "Sphere.h"

Cube::Cube(void):sizex(0.0),sizey(0.0),sizez(0.0)
{
}

Cube::Cube(double posX,double posY,double posZ,double sizex,double sizey,double sizez,GLfloat *col):Obj(posX,posY,posZ,col),sizex(sizex),sizey(sizey),sizez(sizez)
{
}



Cube::~Cube(void)
{
}


void Cube::setsize(double _sizex,double _sizey,double _sizez)
{

	sizex=_sizex;
	sizey=_sizey;
	sizez=_sizez;
}


void Cube::draw()
{
	GLdouble x0 = posX - sizex / 2;
	GLdouble x1 = posX + sizex / 2;
	GLdouble y0 = posY - sizey / 2;
	GLdouble y1 = posY + sizey / 2; 
	GLdouble z0 = posZ - sizez / 2;
	GLdouble z1 = posZ + sizez / 2; 

	if(col!=NULL)
	{
		glMaterialf (GL_FRONT,GL_SHININESS,col[1]);
		glMaterialfv (GL_FRONT,GL_SPECULAR,col);
		glMaterialfv (GL_FRONT,GL_DIFFUSE,col);
		glMaterialfv (GL_FRONT,GL_AMBIENT,col);
	}

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_QUADS);

		//front wall
		glNormal3f(0.0f,0.0f,1.0f);
		glVertex3f(x0,y0,z1);
		glVertex3f(x1,y0,z1);
		glVertex3f(x1,y1,z1);
		glVertex3f(x0,y1,z1);

		//back wall
		glNormal3f(0.0f,0.0f,-1.0f);
		glVertex3f(x0,y1,z0);
		glVertex3f(x1,y1,z0);
		glVertex3f(x1,y0,z0);
		glVertex3f(x0,y0,z0);

		//left wall
		glNormal3f(-1.0f,0.0f,0.0f);
		glVertex3f(x0,y0,z0);
		glVertex3f(x0,y0,z1);
		glVertex3f(x0,y1,z1);
		glVertex3f(x0,y1,z0);

		//right wall
		glNormal3f(1.0f,0.0f,0.0f);
		glVertex3f(x1,y1,z0);
		glVertex3f(x1,y1,z1);
		glVertex3f(x1,y0,z1);
		glVertex3f(x1,y0,z0);

		//bottom wall
		glNormal3f(0.0f,-1.0f,0.0f);
		glVertex3f(x0,y0,z1);
		glVertex3f(x0,y0,z0);
		glVertex3f(x1,y0,z0);
		glVertex3f(x1,y0,z1);

		//upper walll
		glNormal3f(0.0f,1.0f,0.0f);
		glVertex3f(x1,y1,z1);
		glVertex3f(x1,y1,z0);
		glVertex3f(x0,y1,z0);
		glVertex3f(x0,y1,z1);

	glEnd();
}

bool Cube::collision(Obj * obj)
{
	if(obj==NULL) return false;
	bool Daniel = false;
	Cube * c=dynamic_cast<Cube*>(obj);
	
	Sphere * s=dynamic_cast<Sphere*>(obj);
	
	//**********************************************************************************//
	//**********************************************************************************//
	//	LAB GK - COL
	//**********************************************************************************//
	// Collision S-AABB & AABB-AABB
	

	if (c != NULL)
	{

	
	
	if (((this->getPosX() + (this->getSizeX())/2.0) > (obj->getPosX() - c->getSizeX() / 2.0)) && ((this->getPosX() - this->getSizeX() / 2.0) < (obj->getPosX() + c->getSizeX() / 2.0)))
	{
		if (((this->getPosZ() + (this->getSizeZ()) / 2.0) > (obj->getPosZ() - c->getSizeZ() / 2.0)) && ((this->getPosZ() - this->getSizeZ() / 2.0) < (obj->getPosZ() + c->getSizeZ() / 2.0)))
		{
			if (((this->getPosZ() + (this->getSizeZ()) / 2.0) > (obj->getPosZ() - c->getSizeZ() / 2.0)) && ((this->getPosZ() - this->getSizeZ() / 2.0) < (obj->getPosZ() + c->getSizeZ() / 2.0)))
			{
				c->set_color((GLfloat*)Colors[rand() % 10]);
				return true;

			}
			Daniel = false;
		}
		Daniel = false;
	}
	Daniel = false;
	
	}
	
	if (s != NULL)
	{


		bool Daniel;
		if ((this->getPosX() + (this->getSizeX()) / 2.0) > (s->getMinx()) && ((this->getPosX() - this->getSizeX() / 2.0) < (s->getMaxx())))
		{
			if ((this->getPosY() + (this->getSizeY()) / 2.0) > (s->getMiny()) && ((this->getPosY() - this->getSizeY() / 2.0) < (s->getMaxy())))
			{
				if ((this->getPosZ() + (this->getSizeZ()) / 2.0) > (s->getMinz()) && ((this->getPosZ() - this->getSizeZ() / 2.0) < (s->getMaxz())))
				{
					s->set_color((GLfloat*)Colors[rand() % 10]);
					return true;

				}
				Daniel = false;
			}
			Daniel = false;
		}
		Daniel = false;

	}
	
	
	
	//**********************************************************************************//
	//**********************************************************************************//

//	obj->set_color((GLfloat *) Colors[rand()%10]);
//	set_color((GLfloat *) Colors[rand()%10]);
	
	return Daniel;


}