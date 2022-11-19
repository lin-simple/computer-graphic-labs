#pragma once
#include "Painting.h"
#include <conio.h>
#include <mmsyscom.h>
#pragma comment(lib,"Winmm.lib")

#define PI 3.1415926

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

	void sayhello(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color);	//不含右手
	void rightHand(string Name, COLORREF Color, double TallRate, Point PointOrigin);
	void SayHello(string Name, COLORREF Color, double TallRate, Point PointOrigin, IMAGE background);		//打招呼

	void sameCreate(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color);

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

void Baby::sameCreate(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color) {
	name = Name;
	color = Color;		// 黄色
	tallRate = TallRate;
	pointOrigin = PointOrigin;

	//setbkcolor(WHITE);
	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	/*int rectLaa[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectLaa = Painting();
	drawRectLaa.setColor(BLACK);
	drawRectLaa.myDrawPolygonReal(rectLaa, 4);*/

	// 脚
	setfillcolor(color);
	// 右脚
	solidellipse(10, -35, 50, -5);
	// 左脚
	solidellipse(-50, -35, -10, -5);	// 椭圆 2a = 40  2b= 30


	Painting paint = Painting();
	paint.setColor(color);
	// 腿内侧
	paint.Bresenhamline(0, -100, 15, -10);
	paint.Bresenhamline(0, -100, -15, -10);
	// 腿外侧 + 身体
	Point point_right[] = { Point(50, -10), Point(5, -80), Point(130, -150), Point(50, -260) };
	paint.drawBezierCurve(point_right, 4);
	Point point_left[] = { Point(-50, -10), Point(-5, -80), Point(-130, -150), Point(-50, -260) };
	paint.drawBezierCurve(point_left, 4);

	solidellipse(-80, -280, 80, -80);
	// 右边
	int k = 6, k2 = -4;
	int x = 15;
	int curve_x = 38;
	for (int y = -10; y >= -50; y--) {
		x = (y + 100) / k;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	for (int y = -50; y >= -115; y--) {
		x = (y + 100) / k;
		curve_x = (y + 180) / k2 + 70;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	curve_x = 40;
	for (int y = -80; y >= -130; y--) {
		curve_x = (y - 42) / (-2.5);
		paint.Bresenhamline(38, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}

	// 左边
	k = -6;
	k2 = 4;
	x = -15;
	curve_x = -38;
	for (int y = -10; y >= -50; y--) {
		x = (y + 100) / k;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	for (int y = -50; y >= -115; y--) {
		x = (y + 100) / k;
		curve_x = (y + 180) / k2 - 70;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	curve_x = -40;
	for (int y = -80; y >= -130; y--) {
		curve_x = (y - 42) / 2.5;
		paint.Bresenhamline(-38, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}

	//setfillcolor(RGB(7, 190, 234));	// 身体填充蓝色
	//floodfill(-35, -20, BLACK);

	// 手臂
	//右手臂
	paint.Bresenhamline(45, -260, 90, -212);		// 下 (50, -260, 120, -180)  k = 1.0666666666
	paint.Bresenhamline(55, -295, 120, -226);		// 上  (40, -310, 120, -224)
	solidcircle(110, -212, 20);

	// 左手臂
	paint.Bresenhamline(-45, -260, -90, -212);
	paint.Bresenhamline(-55, -295, -120, -226);
	solidcircle(-110, -212, 20);

	// 头部
	solidroundrect(-55, -410, 55, -300, 100, 100);
	// 脸
	setfillcolor(face_color);
	solidroundrect(-45, -400, 45, -310, 95, 95);
	// 眼睛
	setcolor(BLACK);
	circle(17, -365, 8);
	circle(-17, -365, 8);
	// 眼球
	setfillcolor(BLACK);
	solidcircle(17, -363, 4);
	solidcircle(-17, -363, 4);
	// 眼球细节
	//setfillcolor(WHITE);
	//solidcircle(17, -362, 1);
	//solidcircle(-17, -362, 1);
	// 鼻子
	setcolor(BLACK);
	ellipse(-7, -354, 7, -344);
	// 嘴巴
	paint.setColor(BLACK);
	paint.Bresenhamline(-17, -335, 17, -335);
	arc(-17, -345, 17, -325, PI, 2 * PI);
	// 耳朵
	// 右耳
	setfillcolor(color);
	solidellipse(50, -380, 80, -330);
	setfillcolor(RGB(250, 255, 240));		// 象牙白
	solidellipse(60, -375, 75, -335);
	// 左耳
	setfillcolor(color);
	solidellipse(-50, -380, -80, -330);
	setfillcolor(RGB(250, 255, 240));		// 象牙白
	solidellipse(-60, -375, -75, -335);
	setcolor(RGB(150, 155, 131));

	// 颈部
	setfillcolor(color);
	solidellipse(-55, -310, 55, -280);


	// 肚兜
	/*int edges_[] = { -40, -220, 40, -220, 40, -160, -40, -160, -40, -220 };
	paint.setColor(BLUE);
	paint.myDrawPolygonReal(edges_, 4);*/
	setorigin(0, 0);
	int realx1 = origin_x - 40, realy1 = origin_y - 220;
	int realx2 = origin_x + 40, realy2 = origin_y - 220;
	int realx3 = origin_x + 40, realy3 = origin_y - 160;
	int realx4 = origin_x - 40, realy4 = origin_y - 160;
	int edges[10] = { graphx(realx1, 1, 0), graphy(realy1, 1),
							graphx(realx2, 1, 0), graphy(realy2, 1),
							graphx(realx3, 1,0), graphy(realy3, 1),
							graphx(realx4, 1, 0), graphy(realy4, 1),
							graphx(realx1, 1, 0), graphy(realy1, 1) };		// = { 50,100,70,150,100,100,100,50,50,50,50,100 };
	int edges_num = 4;
	int max_y = -1;

	for (int i = 1; i < 2 * (edges_num + 1); i += 2) {
		if (edges[i] > max_y)
			max_y = edges[i];
	}

	Edge* newEdges = paint.InitEdges(edges, edges_num);
	ET etable;
	paint.Init(etable, newEdges, edges_num); //初始化活动边表
	paint.myScanFill(etable, RGB(185, 192, 160), max_y);
}
void Baby::sayhello(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color)
{
	name = Name;
	color = Color;		// 黄色
	tallRate = TallRate;
	pointOrigin = PointOrigin;
	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	// 脚
	setfillcolor(color);
	// 右脚
	solidellipse(10, -35, 50, -5);
	// 左脚
	solidellipse(-50, -35, -10, -5);	// 椭圆 2a = 40  2b= 30


	Painting paint = Painting();
	paint.setColor(color);
	// 腿内侧
	paint.Bresenhamline(0, -100, 15, -10);
	paint.Bresenhamline(0, -100, -15, -10);
	// 腿外侧 + 身体
	Point point_right[] = { Point(50, -10), Point(5, -80), Point(130, -150), Point(50, -260) };
	paint.drawBezierCurve(point_right, 4);
	Point point_left[] = { Point(-50, -10), Point(-5, -80), Point(-130, -150), Point(-50, -260) };
	paint.drawBezierCurve(point_left, 4);


	////
	solidellipse(-80, -280, 80, -80);
	// 右边
	int k = 6, k2 = -4;
	int x = 15;
	int curve_x = 38;
	for (int y = -10; y >= -50; y--) {
		x = (y + 100) / k;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	for (int y = -50; y >= -115; y--) {
		x = (y + 100) / k;
		curve_x = (y + 180) / k2 + 70;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	curve_x = 40;
	for (int y = -80; y >= -130; y--) {
		curve_x = (y - 42) / (-2.5);
		paint.Bresenhamline(38, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}

	// 左边
	k = -6;
	k2 = 4;
	x = -15;
	curve_x = -38;
	for (int y = -10; y >= -50; y--) {
		x = (y + 100) / k;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	for (int y = -50; y >= -115; y--) {
		x = (y + 100) / k;
		curve_x = (y + 180) / k2 - 70;
		paint.Bresenhamline(x, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	curve_x = -40;
	for (int y = -80; y >= -130; y--) {
		curve_x = (y - 42) / 2.5;
		paint.Bresenhamline(-38, y, curve_x, y);
		//line(x, y_, curve_x--, y_);
	}
	////

	// 手臂
	// 右手臂上半部分

	paint.Bresenhamline(45, -260, 88, -215);		// 下 (50, -260, 120, -180)  k = 1.0666666666
	paint.Bresenhamline(55, -295, 90, -258);		// 上  (40, -310, 120, -224)
	paint.ArcPaint(90, -219, 5, 60, 120);


	// 左手臂
	paint.Bresenhamline(-45, -260, -90, -212);
	paint.Bresenhamline(-55, -295, -120, -226);
	solidcircle(-110, -212, 20);

	// 头部
	solidroundrect(-55, -410, 55, -300, 100, 100);
	// 脸
	setfillcolor(face_color);
	solidroundrect(-45, -400, 45, -310, 95, 95);

	// 眼睛
	setcolor(BLACK);
	circle(17, -365, 8);
	circle(-17, -365, 8);
	// 眼球
	setfillcolor(BLACK);
	solidcircle(17, -363, 4);
	solidcircle(-17, -363, 4);
	// 鼻子
	setcolor(BLACK);
	ellipse(-7, -354, 7, -344);
	// 嘴巴
	paint.setColor(BLACK);
	paint.Bresenhamline(-17, -335, 17, -335);
	arc(-17, -345, 17, -325, PI, 2 * PI);
	// 耳朵
	// 右耳
	setfillcolor(color);
	solidellipse(50, -380, 80, -330);
	setfillcolor(RGB(250, 255, 240));		// 象牙白
	solidellipse(60, -375, 75, -335);
	// 左耳
	setfillcolor(color);
	solidellipse(-50, -380, -80, -330);
	setfillcolor(RGB(250, 255, 240));		// 象牙白
	solidellipse(-60, -375, -75, -335);
	setcolor(RGB(150, 155, 131));

	// 颈部
	setfillcolor(color);
	solidellipse(-55, -310, 55, -280);


	// 肚兜

	setorigin(0, 0);
	int realx1 = origin_x - 40, realy1 = origin_y - 220;
	int realx2 = origin_x + 40, realy2 = origin_y - 220;
	int realx3 = origin_x + 40, realy3 = origin_y - 160;
	int realx4 = origin_x - 40, realy4 = origin_y - 160;
	int edges[10] = { graphx(realx1, 1, 0), graphy(realy1, 1),
							graphx(realx2, 1, 0), graphy(realy2, 1),
							graphx(realx3, 1,0), graphy(realy3, 1),
							graphx(realx4, 1, 0), graphy(realy4, 1),
							graphx(realx1, 1, 0), graphy(realy1, 1) };		// = { 50,100,70,150,100,100,100,50,50,50,50,100 };
	int edges_num = 4;
	int max_y = -1;

	for (int i = 1; i < 2 * (edges_num + 1); i += 2) {
		if (edges[i] > max_y)
			max_y = edges[i];
	}

	Edge* newEdges = paint.InitEdges(edges, edges_num);
	ET etable;
	paint.Init(etable, newEdges, edges_num); //初始化活动边表
	paint.myScanFill(etable, RGB(185, 192, 160), max_y);
}

void Baby::SayHello(string Name, COLORREF Color, double TallRate, Point PointOrigin, IMAGE background)
{
	if (Name == "Dipsy")
	{
		//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\dipsy.mp3 alias m2", NULL, 0, NULL);
		mciSendString(L"open ..\\dipsy.mp3 alias m2", NULL, 0, NULL);
		mciSendString(L"play m2 repeat", NULL, 0, NULL);
	}
	else if (Name == "Tinky")
	{
		//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\tinkywinky.mp3 alias m1", NULL, 0, NULL);
		mciSendString(L"open ..\\tinkywinky.mp3 alias m1", NULL, 0, NULL);
		mciSendString(L"play m1 repeat", NULL, 0, NULL);
	}
	else if (Name == "LaaLaa")
	{
		//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\laalaa.mp3 alias m3", NULL, 0, NULL);
		mciSendString(L"open ..\\laalaa.mp3 alias m3", NULL, 0, NULL);
		mciSendString(L"play m3 repeat", NULL, 0, NULL);
	}
	else {
		//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\po.mp3 alias m4", NULL, 0, NULL);
		mciSendString(L"open ..\\po.mp3 alias m4", NULL, 0, NULL);
		mciSendString(L"play m4 repeat", NULL, 0, NULL);
	}
	name = Name;
	color = Color;
	tallRate = TallRate;
	pointOrigin = PointOrigin;
	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// 重置坐标原点

	LineShape* line1 = new LineShape();
	LineShape* line2 = new LineShape();
	SolidCircleShape* Circle = new SolidCircleShape();

	int i = -6;
	if (i == -6)
	{
		while (i <= 10)
		{
			setorigin(origin_x, origin_y);
			line1->setColor(color);
			line1->setLine(94, -216, 135, -293);
			shapes.push_back(line1);
			line1->translate(-94, 216);
			line1->rotate(float(i));
			line1->translate(94, -216);
			line1->draw();

			line2->setColor(color);
			line2->setLine(90, -258, 120, -308);
			shapes.push_back(line2);
			line2->translate(-90, 258);
			line2->rotate(float(i));
			line2->translate(90, -258);
			line2->draw();

			Circle->setColor(color);
			Circle->setCircle(128, -300, 18);
			shapes.push_back(Circle);
			Circle->translate(-94, 236);
			Circle->rotate(float(i));
			Circle->translate(94, -236);
			Circle->draw();
			EndBatchDraw();
			Sleep(100);
			i++;
			putimage(-150, -520, &background);
			setorigin(0, 0);
			BeginBatchDraw();
		}
	}
	if (i == 10)
	{
		while (i >= -6)
		{
			setorigin(origin_x, origin_y);
			EndBatchDraw();
			line1->setColor(color);
			line1->setLine(92, -220, 135, -293);
			shapes.push_back(line1);
			line1->translate(-92, 220);
			line1->rotate(float(i));
			line1->translate(92, -220);
			line1->draw();

			line2->setColor(color);
			line2->setLine(90, -258, 120, -308);
			shapes.push_back(line2);
			line2->translate(-90, 258);
			line2->rotate(float(i));
			line2->translate(90, -258);
			line2->draw();

			Circle->setColor(color);
			Circle->setCircle(128, -300, 18);
			shapes.push_back(Circle);
			Circle->translate(-90, 236);
			Circle->rotate(float(i));
			Circle->translate(90, -236);
			Circle->draw();
			Sleep(100);
			i++;
			putimage(-150, -520, &background);
			setorigin(0, 0);
			BeginBatchDraw();
		}
	}
	EndBatchDraw();
	if (Name == "Dipsy")
	{
		//Sleep(100);
		mciSendString(L"close m2", NULL, 0, NULL);
	}
	else if (Name == "Tinky")
	{
		//Sleep(100);
		mciSendString(L"close m1", NULL, 0, NULL);
	}
	else if (Name == "LaaLaa")
	{
		//Sleep(100);
		mciSendString(L"close m3", NULL, 0, NULL);
	}
	else {
		//Sleep(100);
		mciSendString(L"close m4", NULL, 0, NULL);
	}
}
void Baby::rightHand(string Name, COLORREF Color, double TallRate, Point PointOrigin)
{
	name = Name;
	color = Color;
	tallRate = TallRate;
	pointOrigin = PointOrigin;
	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);
	Painting paint = Painting();
	paint.setColor(color);

	//右手臂
	paint.Bresenhamline(45, -260, 90, -212);		// 下 (50, -260, 120, -180)  k = 1.0666666666
	paint.Bresenhamline(55, -295, 120, -226);		// 上  (40, -310, 120, -224)
	setfillcolor(color);
	solidcircle(110, -212, 20);

}