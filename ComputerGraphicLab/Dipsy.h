#pragma once
#include "Baby.h"

class Dipsy : public Baby		// 迪西  绿色  次高
{
public:
	Dipsy();
	~Dipsy(){}

};

Dipsy::Dipsy()
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