#pragma once
#include "Baby.h"

class Tinky : public Baby	// ���� Ϊ��ɫ  ������
{
public:
	Tinky();
	~Tinky() {}

};

Tinky::Tinky()
{
	name = "Tinky";
	color = RGB(128, 0, 128);	// ��ɫ
	tallRate = 1.25;
	pointOrigin = Point(195, 680);

	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// ��������ԭ��

	int rectTinky[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectTinky = Painting();
	drawRectTinky.myDrawPolygonReal(rectTinky, 4);
}

