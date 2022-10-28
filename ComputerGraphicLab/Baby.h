#pragma once
#include "Painting.h"

class Baby
{
public:
	Baby();
	~Baby();

	// set get ����
	string getName() { return this->name; }				void setName(string name) { this->name = name; }
	COLORREF getColor() { return this->color; }			void setColor(COLORREF color) { this->color = color; }
	double getTallRate() { return this->tallRate; }		void setTallRate(double tallRate) { this->tallRate = tallRate; }
	Point getPointOrigin() { return this->pointOrigin; }void setPointOrigin(int x, int y) { this->pointOrigin.x = x; this->pointOrigin.y = y; }

protected:
	string name;		// ��ɫ����
	COLORREF color;		// ����ɫ
	double tallRate;	// ��ߣ��Ա�����Ϊ��߱�׼������Ϊ 1��
	Point pointOrigin;	// ���ģ�����ԭ�㣩
};

Baby::Baby()
{
	name = "";
	color = BLACK;
	tallRate = 1;
	pointOrigin = Point(0, 0);
}

Baby::~Baby()
{
}