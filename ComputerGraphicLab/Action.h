#pragma once
#include "Painting.h"
#include "Tinky.h"
#include "Dipsy.h"
#include "LaaLaa.h"
#include "Po.h"
#include"Baby.h"


class Action
{
private:
	IMAGE background[4];
	IMAGE Background;
	Tinky tinky;
	Dipsy dipsy;
	LaaLaa laalaa;
	Po po;
public:
	Action();
	void Init();
	void Hello();
	void Menu();
	void SetBackground();
	void GetBackground();
	void BackGround();
	void Mouseclick();

};
void Action::BackGround()
{

}
Action::Action()
{
	cleardevice();
}
void Action::Init()
{
	BeginBatchDraw();
	Tinky tinky = Tinky(1);
	Dipsy dipsy = Dipsy(1);
	LaaLaa laalaa = LaaLaa(1);
	Po po = Po(1);
	Menu();
	EndBatchDraw();

	Sleep(100);

	GetBackground();
}
/*

void Action::Hello()
{
	cleardevice();
	IMAGE bg;//定义一个图片名.
	loadimage(&bg, L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\7.png");//从图片文件获取图像
	setorigin(0, 0);
	putimage(0, 0, &bg);//绘制图像到屏幕，图片左上角坐标为(0,0)
	Menu();
	

	BeginBatchDraw();
	
	setorigin(0, 0);
	setcolor(RGB(51, 0, 102));
	outtextxy(140, 160, L"Hello,我是丁丁！");
	tinky.sayHello();
	

	setorigin(0, 0);
	setcolor(RGB(0, 255, 0));
	outtextxy(490, 160, L"Bup-a-tum,Bup-a-tum,我是迪西!");
	dipsy.sayHello();
	
	setorigin(0, 0);
	setcolor(RGB(255, 204, 0));
	outtextxy(880, 160, L"啦啦喂，啦啦喂,我是拉拉!");
	laalaa.sayHello();
	

	
	setorigin(0, 0);
	setcolor(RGB(255, 0, 0));
	outtextxy(1250, 160, L"斐点斐点,我是小波!");
	po.sayHello();
	
	EndBatchDraw();
	
	setorigin(195, 680);
	getimage(&(background[0]), -150, -520, 325, 520);
	setorigin(585, 680);
	getimage(&(background[1]), -150, -520, 325, 520);
	setorigin(965, 680);
	getimage(&(background[2]), -150, -520, 325, 520);
	setorigin(1313, 680);
	getimage(&(background[3]), -150, -520, 325, 520);

	SetBackground();
	tinky.Hello(background[0]);
	SetBackground();
	dipsy.Hello(background[1]);
	SetBackground();
	laalaa.Hello(background[2]);
	SetBackground();
	po.Hello(background[3]);
	SetBackground();

}
*/
void Action::Hello()
{
	cleardevice();
	IMAGE bg;//定义一个图片名.
	loadimage(&bg, L"..\\7.png");//从图片文件获取图像
	setorigin(0, 0);
	putimage(0, 0, &bg);//绘制图像到屏幕，图片左上角坐标为(0,0)
	Menu();


	BeginBatchDraw();

	setorigin(0, 0);
	setcolor(RGB(51, 0, 102));
	outtextxy(140, 160, L"Hello,我是丁丁！");
	tinky.sayHello();


	setorigin(0, 0);
	setcolor(RGB(0, 255, 0));
	outtextxy(490, 160, L"Bup-a-tum,Bup-a-tum,我是迪西!");
	dipsy.sayHello();

	setorigin(0, 0);
	setcolor(RGB(255, 204, 0));
	outtextxy(880, 160, L"啦啦喂，啦啦喂,我是拉拉!");
	laalaa.sayHello();



	setorigin(0, 0);
	setcolor(RGB(255, 0, 0));
	outtextxy(1250, 160, L"斐点斐点,我是小波!");
	po.sayHello();

	EndBatchDraw();

	setorigin(195, 680);
	getimage(&(background[0]), -150, -520, 325, 520);
	setorigin(585, 680);
	getimage(&(background[1]), -150, -520, 325, 520);
	setorigin(965, 680);
	getimage(&(background[2]), -150, -520, 325, 520);
	setorigin(1313, 680);
	getimage(&(background[3]), -150, -520, 325, 520);

	SetBackground();
	tinky.Hello(background[0]);
	SetBackground();
	dipsy.Hello(background[1]);
	SetBackground();
	laalaa.Hello(background[2]);
	SetBackground();
	po.Hello(background[3]);
	SetBackground();

}
void Action::GetBackground()
{
	setorigin(0, 0);
	getimage(&Background, 0, 0, WINDOW_LENGTH, WINDOW_WIDTH);
}
void Action::SetBackground()
{
	setorigin(0, 0);
	putimage(0, 0, &Background);
	Menu();
}
void Action::Mouseclick()
{
	MOUSEMSG m;
	m = GetMouseMsg();
	if (m.uMsg == WM_LBUTTONDOWN && m.x >= 250 && m.x <= 305 && m.y >= 55 && m.y <= 75)
	{
		setfillcolor(RED);
		solidrectangle(250, 55, 305, 75);
		setbkmode(TRANSPARENT);
		outtextxy(255, 57, L"打招呼");
		Sleep(100);
		setfillcolor(BLACK);
		rectangle(250, 55, 305, 75);
		setbkmode(TRANSPARENT);
		setfillcolor(BLACK);
		outtextxy(255, 57, L"打招呼");
		Hello();
	}
}
void Action::Menu()
{
	setorigin(0, 0);
	setcolor(BLACK);
	rectangle(500, 5, 780, 25);
	setcolor(BLACK);
	outtextxy(520, 7, L"致童年——天线宝宝主题二维动画");

	//rectangle(250, 55, 305, 75);
	//setbkmode(TRANSPARENT);
	//outtextxy(255, 57, L"打招呼");

	//rectangle(1250, 55, 1290, 75);
	//setbkmode(TRANSPARENT);
	//outtextxy(1255, 57, L"退出");
}