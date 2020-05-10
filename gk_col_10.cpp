#include <iostream>

#include "Cube.h" 
#include "Sphere.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;



typedef struct{
  int m_width;
  int m_height;
  int m_mouseX;
  int m_mouseY;
  float m_tiltAngle;
  float m_twistAngle;
  float m_distance;
  float m_distance_height;
  float m_distance_width;
  bool m_bLeftMouseButtonDown;
  bool m_bRightMouseButtonDown;
 }viewerParam;


Obj**tab;
const int TAB_SIZE = 30;
viewerParam vpar;


void Cube_draw(double posX,double posY,double posZ,double sizex,double sizey,double sizez)
{
	GLdouble x0 = posX - sizex / 2;
	GLdouble x1 = posX + sizex / 2;
	GLdouble y0 = posY - sizey / 2;
	GLdouble y1 = posY + sizey / 2; 
	GLdouble z0 = posZ - sizez / 2;
	GLdouble z1 = posZ + sizez / 2; 

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


void generateObj()
{
	tab= new Obj*[TAB_SIZE];

	for(int i=0; i<TAB_SIZE;++i)
	{
		int r = rand() % 100;
		if(r<80)
		{
			tab[i]= new Sphere((rand() % LIMIT*2) -LIMIT,(rand() % LIMIT*2) -LIMIT,(rand() % LIMIT*2) -LIMIT,(rand() % 20) +10,(GLfloat *)Colors[rand()%10]);
		}
		else
		{
			tab[i]= new Cube((rand() % LIMIT*2) -LIMIT,(rand() % LIMIT*2) -LIMIT,(rand() % LIMIT*2) -LIMIT,(rand() % 20) +10,(rand() % 20) +10, (rand() % 20) +10,(GLfloat *) Colors[rand()%10]);
		
		}

	}

}


// Drawing (display) routine.
void drawScene(void)
{
	glEnable (GL_LIGHTING);
 
	glClearColor(1.0f, 1.0f, 1.0f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);	

	glEnable (GL_LIGHT0);

	glShadeModel(GL_SMOOTH);
	
	glEnable (GL_NORMALIZE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective(45.0f, (GLdouble)vpar.m_width / (GLdouble)vpar.m_height, 10.0, 1000.0);
	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-vpar.m_distance_width, -vpar.m_distance_height, -vpar.m_distance);
	glRotatef(vpar.m_tiltAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(-(vpar.m_twistAngle-180), 0.0f, 0.0f, 1.0f);

   Cube_draw(0,0,0,LIMIT*2,LIMIT*2,LIMIT*2);

	for(int i=0;i<TAB_SIZE;++i)
		if(tab[i]!=NULL)
		tab[i]->draw();
   
   glFlush(); 
  glutSwapBuffers();
}



// Initialization routine.
void setup(void) 
{
	

  vpar.m_width = 800;
  vpar.m_height = 600;
  vpar.m_mouseX = 0;
  vpar.m_mouseY = 0;
  vpar.m_tiltAngle = -70.0f;//-99.0f;
  vpar.m_twistAngle = -45.0f;//236.0f;
  vpar.m_distance = 400.0f;//270.0f;
  vpar.m_distance_width=0.f;
  vpar.m_distance_height=0.f;
  vpar.m_bLeftMouseButtonDown = false;
  vpar.m_bRightMouseButtonDown = false;


}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   // Set viewport size to be entire OpenGL window.
	vpar.m_width = w;
	vpar.m_height = h;
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  
   // Set matrix mode to projection.
   glMatrixMode(GL_PROJECTION);

   // Clear current projection matrix to identity.
   glLoadIdentity();

   // Specify the orthographic (or perpendicular) projection, 
   // i.e., define the viewing box.
  glOrtho(0, (GLdouble)vpar.m_width, 0, (GLdouble)vpar.m_height, -1.0f, 1.0f);
  //glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 100.0); 

   // Set matrix mode to modelview.
   glMatrixMode(GL_MODELVIEW);

   // Clear current modelview matrix to identity.
   glLoadIdentity();
}

void animate(int value) {
	


		for(int i=0; i<TAB_SIZE;++i)
		{
			for(int j=0; j<TAB_SIZE;++j)
			{
				if(i!=j)
				{
					if(tab[i]!=NULL)
						if(tab[i]->collision(tab[j]))
						{
							delete tab[i];
							tab[i]=NULL;
						}
				}
			}
		}
	

	for(int i=0; i<TAB_SIZE;++i)
		if(tab[i]!=NULL)
			tab[i]->move(2,2,2);
	

   glutTimerFunc(100, animate, 1);
   glutPostRedisplay();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
  /* dx *= 1.1;
   dy *= 1.1;
   cout << dx <<" "<<dy<<endl;*/
}

// Mouse callback routine.
void mouseControl(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{

		// update mouse button states
		if(button == GLUT_LEFT_BUTTON)
		{
			vpar.m_bLeftMouseButtonDown = true;
		}

		if(button == GLUT_RIGHT_BUTTON)
		{
			vpar.m_bRightMouseButtonDown = true;
		}

		// update internal mouse position
		vpar.m_mouseX = x;
		vpar.m_mouseY = y;
		
		glutPostRedisplay();
	}
	else if(state == GLUT_UP)
	{
		
		// update mouse button states
			if(button == GLUT_LEFT_BUTTON)
			{
				vpar.m_bLeftMouseButtonDown = false;
			}

			if(button == GLUT_RIGHT_BUTTON)
			{
				vpar.m_bRightMouseButtonDown = false;
			}

			// update internal mouse position
			vpar.m_mouseX = x;
			vpar.m_mouseY = y;
		glutPostRedisplay();
	}

}

/*!
*	\brief Called when mouse was moved
*/
void motionFunc(int x, int y)
{
	y=vpar.m_height -y-1;

	if(vpar.m_bLeftMouseButtonDown)
	{
		// calculate new angles
		vpar.m_twistAngle += (float)(vpar.m_mouseX-x);
		vpar.m_tiltAngle -= (float)(y - vpar.m_mouseY);
	}

	// update distance
	if(vpar.m_bRightMouseButtonDown)
	{
			vpar.m_distance -= (float)(y - vpar.m_mouseY) / 3.0f;
			if(vpar.m_distance < 0.0f) vpar.m_distance = 0.0f;
	
		vpar.m_distance_width-= (float)(x - vpar.m_mouseX) / 3.0f;
   }

	// update internal mouse position
	vpar.m_mouseX = x;
	 vpar.m_mouseY = y;
	glutPostRedisplay();
  
}

// Main routine: defines window properties, creates window,
// registers callback routines and begins processing.
int main(int argc, char **argv) 
{  
	srand (time(NULL));

	generateObj();
   // Initialize GLUT.
   glutInit(&argc, argv);
 
   // Set display mode as single-buffered and RGB color.
  // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

   // inicjalizacja bufora ramki
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   
   // Set OpenGL window size.
   glutInitWindowSize(800, 600);

   // Set position of OpenGL window upper-left corner.
   glutInitWindowPosition(100, 100); 
   
   // Create OpenGL window with title.
   glutCreateWindow("Laboratorium GK: 04_COL");
   
   // Initialize.
   setup(); 
   
   // Register display routine.
   glutDisplayFunc(drawScene); 
   
   // Register reshape routine.
   glutReshapeFunc(resize);  
   

   // Register the mouse and keyboard callback function. 
   glutMouseFunc(mouseControl); 
   glutMotionFunc(motionFunc);
   glutKeyboardFunc(keyInput);

   glutTimerFunc(5, animate, 1);
   
   // Begin processing.
   glutMainLoop(); 

   
   return 0;  
}