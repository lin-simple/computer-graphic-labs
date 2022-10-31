#pragma once
#include "Baby.h"
#include "Painting.h"

class Po : public Baby		// С��  ��ɫ  �
{
public:
	Po();
	~Po(){}
private:

};

Po::Po()
{
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// ��ɫ
	double TallRate = 0.8;
	Point PointOrigin = Point(1313, 680);
	sameCreate(Name, Color, TallRate, PointOrigin, WHITE);
	setorigin(1313, 680);

	Painting paintPo = Painting();
	paintPo.setColor(Color);
	paintPo.Bresenhamline(-5, -410, -5, -425);		// 5, 410
	paintPo.Bresenhamline(5, -410, 5, -425);
	setcolor(Color);
	circle(0, -440, 17);
	circle(0, -440, 10);

}
