#pragma once
#include "Baby.h"

class LaaLaa : public Baby		// 拉拉 黄色  次矮
{
public:
	LaaLaa();
	~LaaLaa(){ }

private:

};

LaaLaa::LaaLaa()
{
	name = "LaaLaa";
	color = RGB(255, 255, 0);		// 黄色
	tallRate = 1;
	pointOrigin = Point(965, 680);

	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	int rectLaa[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectLaa = Painting();
	drawRectLaa.myDrawPolygonReal(rectLaa, 4);

}

