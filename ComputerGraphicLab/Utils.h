#pragma once
#include "Painting.h"
#include "BoundingBox.h"
#include "Matrix.h"
#include "Shape.h"

#define WINDOW_LENGTH 1500	// 窗口大小
#define WINDOW_WIDTH 700


//
// 全局变量
//

// 标记程序是否正在运行
bool running = true;

// 鼠标当前位置
Point mouse;
Point lastpos;
int mousebutton = 0;   // 鼠标是否按下

// 屏幕上显示的图形
std::vector<Shape*> shapes;

// 当前鼠标选择的形状
Shape* selectShape = NULL;

// 自定义旋转原点
Point org = Point(WINDOW_LENGTH / 2, WINDOW_WIDTH / 2);

//
// Utils
//用于坐标转换的函数
//
bool isInArray(int* array, int e, int array_length);		// 判断一个整数是否在整数数组中
double graphx(double x, int rate, int relative_origin);		// 坐标上的点
double realx(double gx, int rate, int relative_origin);		// 真实界面上的点
int graphy(int y, int rate);
int realy(int gy, int rate);
bool isInArray(int* array, int e, int array_length);	//判断一个整数是否在整数数组中
int translateColor(string colorString);		// "翻译"颜色
int translateLineType(string lineTypeString);    // "翻译" 线型
int translateType(string typeString);		// "翻译图形"


// 随机函数，返回不大于 n 的随机数
int random(int n);
// 随机颜色
COLORREF random_color();

void mouse_push(int x, int y, int button);  // 鼠标按下消息
void mouse_pop(int x, int y, int button);   // 鼠标弹起消息
void mouse_move(int x, int y);              // 鼠标移动消息
void key_event(int key);                    // 按键处理函数
void update(float delay);                   // 游戏逻辑更新
void drawCross(int x, int y, int size);     // 绘制十字
void display();                             // 显示函数




//
//用于坐标转换的函数
//
double graphx(double x, int rate, int relative_origin) {
	return x * rate + relative_origin;
}

double realx(double gx, int rate, int relative_origin) {
	return (gx - relative_origin) * 1.0 / rate;
}

int graphy(int y, int rate) {
	return WINDOW_WIDTH - y * rate;
}

int realy(int gy, int rate) {
	return (WINDOW_WIDTH - gy) / rate;
}

//判断一个整数是否在整数数组中
bool isInArray(int* array, int e, int array_length)
{
	for (int i = 0; i < array_length; ++i)
	{
		if (array[i] == e)
		{
			return true;
		}
	}
	return false;
}

// "翻译"颜色
int translateColor(string colorString) {
	if (colorString == "red" || colorString == "RED" || colorString == "红色")
		return RED;
	else if (colorString == "blue" || colorString == "BLUE" || colorString == "蓝色")
		return BLUE;
	else if (colorString == "green" || colorString == "GREEN" || colorString == "绿色")
		return GREEN;
	else if (colorString == "yellow" || colorString == "YELLOW" || colorString == "黄色")
		return YELLOW;
	else
		return WHITE;
}

// "翻译" 线型
int translateLineType(string lineTypeString) {
	// 短线长线交替 虚线 点划线 实线
	if (lineTypeString == "点划线")
		return 1;
	else if (lineTypeString == "虚线")
		return 2;
	else if (lineTypeString == "长短线交替")
		return 3;
	else
		return 0;	// 默认实线
}

// "翻译图形"
int translateType(string typeString) {
	if (typeString == "直线")
		return 0;
	else if (typeString == "圆")
		return 1;
	else if (typeString == "多边形")
		return 2;
	else
		return 0;	// 默认实线
}

// 随机函数，返回不大于 n 的随机数
int random(int n)
{
	return rand() % n;
}

// 随机颜色
COLORREF random_color()
{
	//return RGB(random(256), random(256), random(256));
	return rand() % 0xFFFFFF;
}

// 鼠标按下消息
// button   MK_LBUTTON    左键
//          MK_RBUTTON    右键
void mouse_push(int x, int y, int button)
{
    lastpos = mouse;
    mousebutton = button;
    //printf("button = %d %d\n", button, mousebutton);

    // 鼠标点击的时候，选择当前形状
    if (button == MK_LBUTTON) {
        selectShape = NULL;
        for (size_t i = 0; i < shapes.size(); ++i) {
            BoundingBox box= shapes[i]->getBoundingBox();
            if (box.contaits(x, y)) {
                selectShape = shapes[i];
                break;
            }
        }
    }
    else if (mousebutton == MK_RBUTTON) {
        // 右键移动自定义原点位置
        org = mouse;
    }

}

// 鼠标弹起消息
// button   MK_LBUTTON    左键
//          MK_RBUTTON    右键
void mouse_pop(int x, int y, int button)
{
    mousebutton = 0;
}

// 鼠标移动消息
void mouse_move(int x, int y)
{
    mouse.x = x;
    mouse.y = y;

    // 如果鼠标左键正在按下
    if (mousebutton == MK_LBUTTON) {
        // 如果有选择的形状，移动形状
        if (selectShape) {
            // 计算当前鼠标位置，和上次鼠标位置的差值
            int offsetX = mouse.x - lastpos.x;
            int offsetY = mouse.y - lastpos.y;

            selectShape->translate((float)offsetX, (float)offsetY);

            // 更新鼠标最后位置
            lastpos = mouse;
        }
    }
    else if (mousebutton == MK_RBUTTON) {
        // 右键移动自定义原点位置
        org = mouse;
    }
}

// 按键处理函数
void key_event(int key)
{
    // ESC = 27
    // cout << "key_event - key: " << key << "\t" << char(key) << endl;

    if (key == 27) {// 退出
        running = false;
        return;
    }

    if (!selectShape) {
        return;
    }

    // 获取形状的中心点
    // 以形状的中心为原点进行变换
    BoundingBox box = selectShape->getBoundingBox();
    Point center = box.getCenter();

    switch (key) {
    case 72://up        左右键用来缩放
        selectShape->translate(-center.x, -center.y);   // 当前变换原点移动到形状的中心位置，默认在屏幕左上角
        selectShape->scale(1.1f, 1.1f);                 // 缩放
        selectShape->translate(center.x, center.y);     // 再移回去，下面的操作类似
        cout << "放大" << endl;
        break;
    case 80://down
        selectShape->translate(-center.x, -center.y);
        selectShape->scale(0.9f, 0.9f);
        selectShape->translate(center.x, center.y);
        cout << "缩小" << endl;
        break;

    case 75://left      上下键用来旋转 75
        selectShape->translate(-center.x, -center.y);
        selectShape->rotate(-2.0f);
        selectShape->translate(center.x, center.y);
        cout << "左旋" << endl;
        break;
    case 77://right
        selectShape->translate(-center.x, -center.y);
        selectShape->rotate(2.0f);
        selectShape->translate(center.x, center.y);
        cout << "右旋" << endl;
        break;

    case 'a':
        selectShape->translate(-org.x, -org.y);
        selectShape->rotate(-2.0f);
        selectShape->translate(org.x, org.y);
        break;
    case 'd':
        selectShape->translate(-org.x, -org.y);
        selectShape->rotate(2.0f);
        selectShape->translate(org.x, org.y);
        break;
    case 'w':
        selectShape->translate(-org.x, -org.y);   // 当前变换原点移动到形状的中心位置，默认在屏幕左上角
        selectShape->scale(1.1f, 1.1f);                 // 缩放
        selectShape->translate(org.x, org.y);     // 再移回去，下面的操作类似
        break;
    case 's':
        selectShape->translate(-org.x, -org.y);
        selectShape->scale(0.9f, 0.9f);
        selectShape->translate(org.x, org.y);
        break;
    }

}

// 游戏逻辑更新
void update(float delay)
{

}

//  绘制十字
void drawCross(int x, int y, int size)
{
    line(x - size, y, x + size, y);
    line(x, y - size, x, y + size);
}

// 显示函数
void display()
{
    // 清屏
    //cleardevice();
    setfillcolor(BLACK);
    fillrectangle(0, 0, WINDOW_LENGTH, WINDOW_WIDTH);

    // 绘制所有形状
    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->draw();
    }

    // 绘制选择形状
    if (selectShape) {
        // 绘制包围盒
        BoundingBox box = selectShape->getBoundingBox();
        box.draw();

        // 中心点
        setcolor(RED);
        Point center = box.getCenter();
        drawCross((int)center.x, (int)center.y, 5);

    }

    // 自定义原点
    setcolor(RED);
    drawCross((int)org.x, (int)org.y, 10);


    // 显示鼠标位置
    TCHAR buf[256];
    settextcolor(BLACK);
    _sntprintf(buf, _countof(buf), TEXT("mouse = %d, %d"), mouse.x, mouse.y);
    outtextxy(0, 0, buf);
}