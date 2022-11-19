#pragma once
#include "Painting.h"
#include "Shape.h"

class Sun
{
private:
	//COLORREF color=0;
	COLORREF Color[11]={RGB(255,160,122),RGB(244,164,96),RGB(255,127,80),RGB(250,128,114),RGB(255,99,71),RGB(255,69,0),
						RGB(255,99,71),RGB(250,128,114),RGB(255,127,80),RGB(244,164,96),RGB(255,160,122)};
	IMAGE background[11];
public:
	Sun();
	void drawSun();
	~Sun();
	//COLORREF getColor() { return this->color; }			void setColor(COLORREF color) { this->color = color; }
};

Sun::Sun()
{
	/*setorigin(50, 250);
	setfillcolor(RED);
	solidcircle(0, 0, 30);
	setorigin(0, 0);*/

	/*loadimage(&background[0], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\7.png");
	loadimage(&background[1], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\8.png");
	loadimage(&background[2], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\9.png");
	loadimage(&background[3], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\10.png");
	loadimage(&background[4], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\11.png");
	loadimage(&background[5], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\12.png");
	loadimage(&background[6], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\13.png");
	loadimage(&background[7], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\14.png");
	loadimage(&background[8], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\15.png");
	loadimage(&background[9], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\16.png");
	loadimage(&background[10], L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\17.png");*/

	loadimage(&background[0], L"..\\7.png");
	loadimage(&background[1], L"..\\8.png");
	loadimage(&background[2], L"..\\9.png");
	loadimage(&background[3], L"..\\10.png");
	loadimage(&background[4], L"..\\11.png");
	loadimage(&background[5], L"..\\12.png");
	loadimage(&background[6], L"..\\13.png");
	loadimage(&background[7], L"..\\14.png");
	loadimage(&background[8], L"..\\15.png");
	loadimage(&background[9], L"..\\16.png");
	loadimage(&background[10], L"..\\17.png");
}
void Sun::drawSun()
{
	int r = 23;
	//IMAGE img;
	//setorigin(0, 0);
	//getimage(&img,0,0,1500,700);
	for (int i = 7; i <= 12; i++)
	{
		SolidCircleShape* Circle = new SolidCircleShape();
		Circle->setColor(Color[int(i-7)]);
		setorigin(750, 1200);
		r = r - 0.5;
		Circle->setCircle(-700, -955, r++);
		shapes.push_back(Circle);
		//Circle->translate(-94, 236);
		Circle->rotate(float(7.5 * (i - 7)));
		//Circle->translate(94, -236);
		setorigin(0, 0);
		putimage(0,0,&background[i-7]);
		setorigin(750, 1200);
		Circle->draw();
		Sleep(500);
		setorigin(0, 0);
		//i = i + 0.5;
	}
	for (int i = 13; i <= 17;i++ )
	{
		SolidCircleShape* Circle = new SolidCircleShape();
		Circle->setColor(Color[int(i - 7)]);
		setorigin(750, 1200);
		r = r - 0.5;
		Circle->setCircle(0, -1193, r++);
		shapes.push_back(Circle);
		//Circle->translate(-94, 236);
		Circle->rotate(float(7.5 * (i - 12)));
		//Circle->translate(94, -236);
		setorigin(0, 0);
		putimage(0, 0, &background[i-7]);
		setorigin(750, 1200);
		Circle->draw();
		Sleep(500);
		setorigin(0, 0);
		//i = i + 0.5;
	}
	putimage(0, 0, &background[10]);
}
Sun::~Sun()
{

}