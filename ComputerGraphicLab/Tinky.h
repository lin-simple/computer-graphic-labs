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

