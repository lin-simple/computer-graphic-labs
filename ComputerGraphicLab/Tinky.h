#pragma once
#include "Baby.h"

class Tinky : public Baby	// ���� Ϊ��ɫ  ������
{
public:
	Tinky();
	Tinky(int flag);
	~Tinky() {}
	void sayHello();
	void Hello(IMAGE background);
	void RightHand();
};

Tinky::Tinky()
{
	string Name = "Tinky";
	COLORREF Color = RGB(51, 0, 102);		// ��ɫ RGB(128, 0, 128)
	double TallRate = 1.25;
	Point PointOrigin = Point(195, 680);
}

Tinky::Tinky(int flag)
{
	string Name = "Tinky";
	COLORREF Color = RGB(51, 0, 102);		// ��ɫ RGB(128, 0, 128)
	double TallRate = 1.25;
	Point PointOrigin = Point(195, 680);
	sameCreate(Name, Color, TallRate, PointOrigin, WHITE);
	setorigin(195, 680);

	// ��Ȧ������
	Painting paintTinky = Painting();
	paintTinky.setColor(Color);
	int edges[] = { -8, -405, -8, -420, -50, -500, 50, -500, 8, -420, 8, -405, -8, -405 };
	paintTinky.myDrawPolygonReal(edges, 6);
	// ��Ȧ������
	int edges2[] = { 0, -430, -31, -490, 31, -490, 0, -430 };
	paintTinky.myDrawPolygonReal(edges2, 3);

}
void Tinky::sayHello()
{
	
	string Name = "Tinky";
	COLORREF Color = RGB(51, 0, 102);		// ��ɫ RGB
	double TallRate = 1.25;
	Point PointOrigin = Point(195, 680);
	sayhello(Name, Color, TallRate, PointOrigin, WHITE);

	setorigin(195, 680);

	// ��Ȧ������
	Painting paintTinky = Painting();
	paintTinky.setColor(Color);
	int edges[] = { -8, -405, -8, -420, -50, -500, 50, -500, 8, -420, 8, -405, -8, -405 };
	paintTinky.myDrawPolygonReal(edges, 6);
	// ��Ȧ������
	int edges2[] = { 0, -430, -31, -490, 31, -490, 0, -430 };
	paintTinky.myDrawPolygonReal(edges2, 3);

	//�۾�
	setcolor(BLACK);
	ellipse(9, -373, 25, -358); ellipse(-25, -373, -8, -358);
	//���
	paintTinky.setColor(BLACK);
	paintTinky.Bresenhamline(-17, -335, 17, -335); arc(-17, -345, 17, -320, PI, 2 * PI);
	
}
void Tinky::Hello(IMAGE background)
{
	string Name = "Tinky";
	COLORREF Color = RGB(51, 0, 102);		// ��ɫ RGB
	double TallRate = 1.25;
	Point PointOrigin = Point(195, 680);
	
	SayHello(Name, Color, TallRate, PointOrigin, background);
}

void Tinky::RightHand()
{
	string Name = "Tinky";
	COLORREF Color = RGB(51, 0, 102);		// ��ɫ RGB
	double TallRate = 1.25;
	Point PointOrigin = Point(195, 680);
	rightHand(Name, Color, TallRate, PointOrigin);
}