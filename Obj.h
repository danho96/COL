#pragma once

#define GLUT_DISABLE_ATEXIT_HACK

#include "GL/glut.h"

#include "GL/GL.h"

#include "GL/GLU.h" 

const int LIMIT=100;

const GLfloat Brass [4] =
    {
        0.329412f, 0.223529f, 0.027451f, 1.000000f
    };


const GLfloat Bronze [4] =
    {
        0.212500f, 0.127500f, 0.054000f, 1.000000f
    };

const GLfloat Chrome [4] =
    {
        0.250000f, 0.250000f, 0.250000f, 1.000000f
    };

const GLfloat Gold [4] =
    {
        0.247250f, 0.224500f, 0.064500f, 1.000000f
    };
const GLfloat Silver [4] =
    {
        0.192250f, 0.192250f, 0.192250f, 1.000000f
    };
const GLfloat Emerald [4] =
    {
        0.021500f, 0.174500f, 0.021500f, 0.550000f
    };

const GLfloat Pearl [4] =
    {
        0.250000f, 0.207250f, 0.207250f, 0.922000f
    };

const GLfloat Ruby [4] =
    {
        0.174500f, 0.011750f, 0.011750f, 0.550000f
    };

const GLfloat Turquoise[4] =
    {
        0.100000f, 0.187250f, 0.174500f, 0.800000f
    };

const GLfloat Black [4] =
    {
        0.000000f, 0.000000f, 0.000000f, 1.000000f
    };


const GLfloat Red [4] =
    {
        1.000000f, 0.000000f, 0.000000f, 1.000000f
    };

const GLfloat Colors [11][4] = 
	{{ 0.329412f, 0.223529f, 0.027451f, 1.000000f},
	{
        0.212500f, 0.127500f, 0.054000f, 1.000000f
    },
	{
        0.250000f, 0.250000f, 0.250000f, 1.000000f
    },
	{
        0.247250f, 0.224500f, 0.064500f, 1.000000f
    },
	{
        0.192250f, 0.192250f, 0.192250f, 1.000000f
    },
	{
        0.021500f, 0.174500f, 0.021500f, 0.550000f
    },
	{
        0.250000f, 0.207250f, 0.207250f, 0.922000f
    },
	{
        0.174500f, 0.011750f, 0.011750f, 0.550000f
    },
	{
        0.100000f, 0.187250f, 0.174500f, 0.800000f
    },
	{
        0.000000f, 0.000000f, 0.000000f, 1.000000f
    },
	{
        1.000000f, 0.000000f, 0.000000f, 1.000000f
	}};

class Obj
{
protected:
	double posX;
	double posY;
	double posZ;

	GLfloat * col;

	bool direction[3];
public:
	double getPosX(){ return posX; }
	double getPosY(){ return posY; }
	double getPosZ(){ return posZ; }

	Obj(void);
	Obj(double posX,double posY,double posZ, GLfloat * col);
	virtual ~Obj(void);
	void setpos(double _posX,double _posY,double _posZ);
	void move(double dx,double dy,double dz);
	void set_color(GLfloat * col);
	GLfloat * get_color(){return col; }
	void change_direction();
	virtual void draw()=0;
	virtual bool collision(Obj * obj)=0;
};

