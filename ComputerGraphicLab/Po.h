#pragma once
#include "Baby.h"
#include "Painting.h"

class Po : public Baby		// 小波  红色  最矮
{
public:
	Po();
	~Po(){}
private:

};

Po::Po()
{
	name = "Po";
	color = RGB(255, 0, 0);		// 红色
	tallRate = 0.8;
	pointOrigin = Point(1313, 680);

	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	int rectPo[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectPo = Painting();
	drawRectPo.myDrawPolygonReal(rectPo, 4);
}
