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
	name = "Dipsy";
	color = RGB(0, 128, 0);		// 绿色
	tallRate = 1.1;
	pointOrigin = Point(585, 680);

	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	int rectDipsy[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectDipsy = Painting();
	drawRectDipsy.myDrawPolygonReal(rectDipsy, 4);
}