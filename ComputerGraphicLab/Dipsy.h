#pragma once
#include "Baby.h"

class Dipsy : public Baby		// 迪西  绿色  次高
{
public:
	Dipsy();
	Dipsy(int flag);
	~Dipsy(){}
	void sayHello();
	void Hello(IMAGE background);
	void RightHand();

};
Dipsy::Dipsy()
{
	string Name = "Dipsy";
	COLORREF Color = RGB(0, 255, 0);		// 绿色
	double TallRate = 1.1;
	Point PointOrigin = Point(585, 680);
}

Dipsy::Dipsy(int flag)
{
	string Name = "Dipsy";
	COLORREF Color = RGB(0, 255, 0);		// 绿色
	double TallRate = 1.1;
	Point PointOrigin = Point(585, 680);
	sameCreate(Name, Color, TallRate, PointOrigin, RGB(102, 87, 87));
	setorigin(585, 680);

	Painting paintDipsy = Painting();
	paintDipsy.setColor(Color);
	paintDipsy.Bresenhamline(-8, -410, -5, -490);
	paintDipsy.Bresenhamline(8, -410, 5, -490);
	setcolor(Color);
	arc(-5, -495, 5, -485, 0, PI);
}
void Dipsy::sayHello()
{
	
	
	string Name = "Dipsy";
	COLORREF Color = RGB(0, 255, 0);		// 绿色
	double TallRate = 1.1;
	Point PointOrigin = Point(585, 680);
	sayhello(Name, Color, TallRate, PointOrigin, RGB(102, 87, 87));
	setorigin(585, 680);

	Painting paintDipsy = Painting();
	paintDipsy.setColor(Color);
	paintDipsy.Bresenhamline(-8, -410, -5, -490);
	paintDipsy.Bresenhamline(8, -410, 5, -490);
	setcolor(Color);
	arc(-5, -495, 5, -485, 0, PI);

	//眼睛
	setcolor(BLACK);
	ellipse(9, -373, 25, -358); ellipse(-25, -373, -8, -358);
	//嘴巴
	paintDipsy.setColor(BLACK);
	paintDipsy.Bresenhamline(-17, -335, 17, -335); arc(-17, -345, 17, -320, PI, 2 * PI);

	
}
void Dipsy::Hello(IMAGE background)
{
	string Name = "Dipsy";
	COLORREF Color = RGB(0, 255, 0);		// 绿色
	double TallRate = 1.1;
	Point PointOrigin = Point(585, 680);
	SayHello(Name, Color, TallRate, PointOrigin, background);
}
void Dipsy::RightHand()
{
	string Name = "Dipsy";
	COLORREF Color = RGB(0, 255, 0);		// 绿色
	double TallRate = 1.1;
	Point PointOrigin = Point(585, 680);
	rightHand(Name, Color, TallRate, PointOrigin);
}