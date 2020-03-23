#include <iostream>
#include <math.h>
#include "Circle.h"

double Circle::diameter()
{
	return (2*radius);
}

double Circle::area()
{
	return((M_PI)*(pow(radius,2)));
}

double Circle::circumference()
{
	return(2*(M_PI)*(radius));
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getX()
{
	return xPos;
}

double Circle::getY()
{
	return yPos;
}

void Circle::setX(double x)
{
	xPos = x;
}

void Circle::setY(double y)
{
	yPos = y;
}

double Circle::distanceToOrigin()
{
	return (sqrt(pow(xPos,2) + pow(yPos,2)));
}

bool Circle::intersect(const Circle& otherCircle)
{
	Circle otherNewCircle = otherCircle;
	
	double x = this-> getX();
	double y = this -> getY();
	double r = this -> getRadius(); 

	if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) > (r + otherNewCircle.getRadius())) //0 intersections
	{
		return false;
	}
	else if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) == (r + otherNewCircle.getRadius())) //1 intersection
	{
		return true;
	}
	else if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) < (r + otherNewCircle.getRadius())) //2 intersections
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Circle::setRadius(double r)
{
	if(r<=0)
	{
		radius=0;
		return false;
	}
	else
	{
		radius = r;
		return true;
	}
}

int Circle::intersectCount(const Circle& otherCircle)
{
	Circle otherNewCircle = otherCircle;
	
	double x = this-> getX();
	double y = this -> getY();
	double r = this -> getRadius(); 

	if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) > (r + otherNewCircle.getRadius())) //0 intersections
	{
		return (0);
	}
	else if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) == (r + otherNewCircle.getRadius())) //1 intersection
	{
		return (1);
	}
	else if(sqrt(pow((x - otherNewCircle.getX()),2) + pow((y - otherNewCircle.getY()),2)) < (r + otherNewCircle.getRadius())) //2 intersections
	{
		return (2);
	}
	else
	{
		return (3);
	}
}


















