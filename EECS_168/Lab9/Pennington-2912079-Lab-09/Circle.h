#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

class Circle
{
	public:
		double diameter();
		double area();
		double circumference();
		double getRadius();
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
		double distanceToOrigin();
		bool intersect(const Circle& otherCircle);
		bool setRadius(double r);
		int intersectCount(const Circle& otherCircle); //169

	private:
		double radius;
		double xPos;
		double yPos;
};
#endif
