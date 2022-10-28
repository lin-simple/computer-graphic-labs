#pragma once
#include "Painting.h"

class Baby
{
public:
	Baby();
	~Baby();

	// set get 方法
	string getName() { return this->name; }				void setName(string name) { this->name = name; }
	COLORREF getColor() { return this->color; }			void setColor(COLORREF color) { this->color = color; }
	double getTallRate() { return this->tallRate; }		void setTallRate(double tallRate) { this->tallRate = tallRate; }
	Point getPointOrigin() { return this->pointOrigin; }void setPointOrigin(int x, int y) { this->pointOrigin.x = x; this->pointOrigin.y = y; }

protected:
	string name;		// 角色姓名
	COLORREF color;		// 主导色
	double tallRate;	// 身高（以比例作为身高标准，拉拉为 1）
	Point pointOrigin;	// 重心（重置原点）
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