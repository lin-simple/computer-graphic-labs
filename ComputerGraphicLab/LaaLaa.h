#pragma once
#pragma warning(disable : 4996)
#define PI 3.1415926
#include "Baby.h"

class LaaLaa : public Baby		// 拉拉 黄色  次矮
{
public:
	LaaLaa();
	LaaLaa(int flag);
	~LaaLaa() { }
	void sayHello();
	void Hello(IMAGE background);
	void RightHand();

private:

};
LaaLaa::LaaLaa()
{
	string Name = "LaaLaa";
	COLORREF Color = RGB(255, 204, 0);		// 黄色
	double TallRate = 1;
	Point PointOrigin = Point(965, 680);
}

LaaLaa::LaaLaa(int flag)
{
	string Name = "LaaLaa";
	COLORREF Color = RGB(255, 204, 0);		// 黄色
	double TallRate = 1;
	Point PointOrigin = Point(965, 680);
	sameCreate(Name, Color, TallRate, PointOrigin, WHITE);
	setorigin(965, 680);

	Painting paintLaa = Painting();
	paintLaa.setColor(Color);
	Point pointLaa[] = { Point(-8, -410), Point(-20, -425), Point(0, -460), Point(16, -440), Point(8, -425) };
	paintLaa.drawBezierCurve(pointLaa, 5);
	paintLaa.Bresenhamline(8, -425, 4, -420);
	paintLaa.Bresenhamline(2, -410, 6, -430);

	Point pointLaa2[] = { Point(-15, -425), Point(-13, -410), Point(-30, -460), Point(0, -480), Point(10, -460) };
	paintLaa.drawBezierCurve(pointLaa2, 5);
	paintLaa.Bresenhamline(7, -460, -8, -430);


}
void LaaLaa::sayHello()
{
	
	string Name = "LaaLaa";
	COLORREF Color = RGB(255, 204, 0);		// 黄色
	double TallRate = 1;
	Point PointOrigin = Point(965, 680);
	sayhello(Name, Color, TallRate, PointOrigin, WHITE);
	setorigin(965, 680);

	Painting paintLaa = Painting();
	paintLaa.setColor(Color);
	Point pointLaa[] = { Point(-8, -410), Point(-20, -425), Point(0, -460), Point(16, -440), Point(8, -425) };
	paintLaa.drawBezierCurve(pointLaa, 5);
	paintLaa.Bresenhamline(8, -425, 4, -420);
	paintLaa.Bresenhamline(2, -410, 6, -430);

	Point pointLaa2[] = { Point(-15, -425), Point(-13, -410), Point(-30, -460), Point(0, -480), Point(10, -460) };
	paintLaa.drawBezierCurve(pointLaa2, 5);
	paintLaa.Bresenhamline(7, -460, -8, -430);

	//眼睛
	setcolor(BLACK);
	ellipse(9, -373, 25, -358); ellipse(-25, -373, -8, -358);
	//嘴巴
	paintLaa.setColor(BLACK);
	paintLaa.Bresenhamline(-17, -335, 17, -335); arc(-17, -345, 17, -320, PI, 2 * PI);
	
}
void LaaLaa::Hello(IMAGE background)
{
	string Name = "LaaLaa";
	COLORREF Color = RGB(255, 204, 0);		// 黄色
	double TallRate = 1;
	Point PointOrigin = Point(965, 680);
	SayHello(Name, Color, TallRate, PointOrigin, background);
}
void LaaLaa::RightHand()
{
	string Name = "LaaLaa";
	COLORREF Color = RGB(255, 204, 0);		// 黄色
	double TallRate = 1;
	Point PointOrigin = Point(965, 680);
	rightHand(Name, Color, TallRate, PointOrigin);
}