#pragma once
#include "Baby.h"

class Tinky : public Baby	// 丁丁 为紫色  身高最高
{
public:
	Tinky();
	~Tinky() {}

};

Tinky::Tinky()
{
	name = "Tinky";
	color = RGB(128, 0, 128);	// 紫色
	tallRate = 1.25;
	pointOrigin = Point(195, 680);

	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	int rectTinky[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectTinky = Painting();
	drawRectTinky.myDrawPolygonReal(rectTinky, 4);
}

