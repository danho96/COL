#include "Sphere.h"


Sphere::Sphere(void):radius(0)
{
}

Sphere::Sphere(double posX,double posY,double posZ,double radius,GLfloat * col):Obj(posX,posY,posZ,col),radius(radius)
{

}

Sphere::~Sphere(void)
{
}

void Sphere::draw()
{

	if(col!=NULL)
	{
		glMaterialf (GL_FRONT,GL_SHININESS,col[1]);
		glMaterialfv (GL_FRONT,GL_SPECULAR,col);
		glMaterialfv (GL_FRONT,GL_DIFFUSE,col);
		glMaterialfv (GL_FRONT,GL_AMBIENT,col);
	}

	glPushMatrix ();
		
	glTranslatef (posX, posY, posZ);


	glutSolidSphere(radius, 100, 100);

	glPopMatrix ();
	Cube_draw();
	
}


bool Sphere::collision(Obj * obj)
{
	Sphere * c=dynamic_cast<Sphere*>(obj);
	
	if(c==NULL) return false;

	//**********************************************************************************//
	//**********************************************************************************//
	//	LAB GK - COL
	//**********************************************************************************//
	bool Hojnca;
	if ((this->getMaxx() > c->getMinx()) && (this->getMinx() < c->getMaxx()))
	{
		if ((this->getMaxy() > c->getMiny()) && (this->getMiny() < c->getMaxy()))
		{
			if ((this->getMaxz() > c->getMinz()) && (this->getMinz() < c->getMaxz()))
			{
				Hojnca = true;

			}
			else Hojnca = false;
		}
		else Hojnca = false;
	}
	else Hojnca = false;
	
	
	
	
	//**********************************************************************************//
	//**********************************************************************************//
	
	return Hojnca;
}

void Sphere::Cube_draw()
{
	GLdouble x0 = posX - radius;
	GLdouble x1 = posX + radius;
	GLdouble y0 = posY - radius;
	GLdouble y1 = posY + radius; 
	GLdouble z0 = posZ - radius;
	GLdouble z1 = posZ + radius; 

//	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_LINE_STRIP);

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
