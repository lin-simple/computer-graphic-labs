#pragma once
#include "Baby.h"
#include "Painting.h"

class Po : public Baby		// 小波  红色  最矮
{
public:
	Po();
	Po(int flag);
	~Po(){}
	void sayHello();
	void Hello(IMAGE background);
	void RightHand();

};
Po::Po()
{
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// 红色
	double TallRate = 0.8;
	Point PointOrigin = Point(1313, 680);
}

Po::Po(int flag)
{
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// 红色
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
void Po::sayHello()
{
	
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// 红色
	double TallRate = 0.8;
	Point PointOrigin = Point(1313, 680);
	sayhello(Name, Color, TallRate, PointOrigin, WHITE);
	setorigin(1313, 680);

	Painting paintPo = Painting();
	paintPo.setColor(Color);
	paintPo.Bresenhamline(-5, -410, -5, -425);		// 5, 410
	paintPo.Bresenhamline(5, -410, 5, -425);
	setcolor(Color);
	circle(0, -440, 17);
	circle(0, -440, 10);

	//眼睛
	setcolor(BLACK);
	ellipse(9, -373, 25, -358); ellipse(-25, -373, -8, -358);
	//嘴巴
	paintPo.setColor(BLACK);
	paintPo.Bresenhamline(-17, -335, 17, -335); arc(-17, -345, 17, -320, PI, 2 * PI);
	
}
void Po::Hello(IMAGE background)
{
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// 红色
	double TallRate = 0.8;
	Point PointOrigin = Point(1313, 680);
	SayHello(Name, Color, TallRate, PointOrigin, background);
}
void Po::RightHand()
{
	string Name = "PoPo";
	COLORREF Color = RGB(255, 0, 0);		// 红色
	double TallRate = 0.8;
	Point PointOrigin = Point(1313, 680);
	rightHand(Name, Color, TallRate, PointOrigin);
}