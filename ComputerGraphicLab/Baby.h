#pragma once
#include "Painting.h"

#define PI 3.1415926

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

	void sameCreate(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color);

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

void Baby::sameCreate(string Name, COLORREF Color, double TallRate, Point PointOrigin, COLORREF face_color) {
	name = Name;
	color = Color;		// ��ɫ
	tallRate = TallRate;
	pointOrigin = PointOrigin;

	//setbkcolor(WHITE);
	int origin_x = pointOrigin.x, origin_y = pointOrigin.y;
	int height = 320, width = 140;
	setorigin(origin_x, origin_y);	// ��������ԭ��

	/*int rectLaa[] = { -width * tallRate, -height * tallRate,
					width * tallRate, -height * tallRate,
					width * tallRate, 0,
					-width * tallRate,0,
					-width * tallRate, -height * tallRate };
	Painting drawRectLaa = Painting();
	drawRectLaa.setColor(BLACK);
	drawRectLaa.myDrawPolygonReal(rectLaa, 4);*/

	// ��
	setfillcolor(color);
	// �ҽ�
	solidellipse(10, -35, 50, -5);
	// ���
	solidellipse(-50, -35, -10, -5);	// ��Բ 2a = 40  2b= 30


	Painting paint = Painting();
	paint.setColor(color);
	// ���ڲ�
	paint.Bresenhamline(0, -100, 15, -10);
	paint.Bresenhamline(0, -100, -15, -10);
	// ����� + ����
	Point point_right[] = { Point(50, -10), Point(5, -80), Point(130, -150), Point(50, -260) };
	paint.drawBezierCurve(point_right, 4);
	Point point_left[] = { Point(-50, -10), Point(-5, -80), Point(-130, -150), Point(-50, -260) };
	paint.drawBezierCurve(point_left, 4);

	//setfillcolor(RGB(7, 190, 234));	// ���������ɫ
	//floodfill(-35, -20, BLACK);

	// �ֱ�
	// ���ֱ�
	paint.Bresenhamline(45, -260, 90, -212);		// �� (50, -260, 120, -180)  k = 1.0666666666
	paint.Bresenhamline(55, -295, 120, -226);		// ��  (40, -310, 120, -224)
	solidcircle(110, -212, 20);
	// ���ֱ�
	paint.Bresenhamline(-45, -260, -90, -212);
	paint.Bresenhamline(-55, -295, -120, -226);
	solidcircle(-110, -212, 20);

	// ͷ��
	solidroundrect(-55, -410, 55, -300, 100, 100);
	// ��
	setfillcolor(face_color);
	solidroundrect(-45, -400, 45, -310, 95, 95);
	// �۾�
	setcolor(BLACK);
	circle(17, -365, 8);
	circle(-17, -365, 8);
	// ����
	setfillcolor(BLACK);
	solidcircle(17, -363, 4);
	solidcircle(-17, -363, 4);
	// ����ϸ��
	//setfillcolor(WHITE);
	//solidcircle(17, -362, 1);
	//solidcircle(-17, -362, 1);
	// ����
	setcolor(BLACK);
	ellipse(-7, -354, 7, -344);
	// ���
	paint.setColor(BLACK);
	paint.Bresenhamline(-17, -335, 17, -335);
	arc(-17, -345, 17, -325, PI, 2 * PI);
	// ����
	// �Ҷ�
	setfillcolor(color);
	solidellipse(50, -380, 80, -330);
	setfillcolor(RGB(250, 255, 240));		// ������
	solidellipse(60, -375, 75, -335);
	// ���
	setfillcolor(color);
	solidellipse(-50, -380, -80, -330);
	setfillcolor(RGB(250, 255, 240));		// ������
	solidellipse(-60, -375, -75, -335);
	setcolor(RGB(150, 155, 131));

	// ����
	setfillcolor(color);
	solidellipse(-55, -310, 55, -280);


	// �Ƕ�
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
	paint.Init(etable, newEdges, edges_num); //��ʼ����߱�
	paint.myScanFill(etable, RGB(185, 192, 160), max_y);
}