#include "CircleDriver.h"
#include "Circle.h"
#include <iostream>
#include <fstream>
#include <math.h>

void CircleDriver::obtainCircles()
{
	double xposition;
	double yposition;
	double radius;

	std::cout<<"Information for Circle 1\n";

	std::cout<<"Input x position for Circle 1: ";
	std::cin>>xposition;
	circ1.setX(xposition);
	
	std::cout<<"Input y position for Cricle 1: ";
	std::cin>>yposition;
	circ1.setY(yposition);

	std::cout<<"Input radius for Circle 1: ";
	std::cin>>radius;
	circ1.setRadius(radius);
	while(circ1.setRadius(radius) == false)
	{
		std::cout<<"Please input a positive value for the radius\n";
		std::cout<<"Input radius for Circle 1: ";
		std::cin>>radius;
		circ1.setRadius(radius);
	}
	std::cout<<'\n';

	std::cout<<"Information for Circle 2\n";

	std::cout<<"Input x position for Circle 2: ";
	std::cin>>xposition;
	circ2.setX(xposition);
	
	std::cout<<"Input y position for Circle 2: ";
	std::cin>>yposition;
	circ2.setY(yposition);

	std::cout<<"Input radius for Circle 2: ";
	std::cin>>radius;
	circ2.setRadius(radius);
	while(circ2.setRadius(radius) == false)
	{
		std::cout<<"Please input a positive value for the radius\n";
		std::cout<<"Input radius for Circle 2: ";
		std::cin>>radius;
		circ2.setRadius(radius);
	}
	std::cout<<'\n';
}
		

void CircleDriver::printCircleInfo()
{

	std::cout<<"Information for Circle 1:\n";
	std::cout<<"Location: ("<<circ1.getX()<<", "<<circ1.getY()<<")\n";
	std::cout<<"Diameter: "<<circ1.diameter()<<'\n';
	std::cout<<"Area: "<<circ1.area()<<'\n';
	std::cout<<"Circumference: "<<circ1.circumference()<<'\n';
	std::cout<<"Distance from origin: "<<circ1.distanceToOrigin()<<'\n';
	
	std::cout<<'\n';

	std::cout<<"Information for Circle 2:\n";
	std::cout<<"Location: ("<<circ2.getX()<<", "<<circ2.getY()<<")\n";
	std::cout<<"Diameter: "<<circ2.diameter()<<'\n';
	std::cout<<"Area: "<<circ2.area()<<'\n';
	std::cout<<"Circumference: "<<circ2.circumference()<<'\n';
	std::cout<<"Distance from origin: "<<circ2.distanceToOrigin()<<'\n';

	std::cout<<'\n';

	if(circ1.intersect(circ2) == false)
	{
		std::cout<<"The circles do not intersect.\n";
	}
	else if(circ1.intersect(circ2) == true)
	{
		std::cout<<"The circles intersect.\n";
	}

	if(circ1.intersectCount(circ2) == 0)
	{
		std::cout<<"The circles intersected 0 times. This means they are too far away to intersect.\n";
	}
	else if(circ1.intersectCount(circ2) == 1)
	{
		std::cout<<"The circles intersected 1 time. This means that they intersect tangentially.\n";
	}
	else if(circ1.intersectCount(circ2) == 2)
	{
		std::cout<<"The circles intersected 2 times. This means that they intersect in two places.\n";
	}

}
	

void CircleDriver::run()
{
	obtainCircles();
	printCircleInfo();
}


































