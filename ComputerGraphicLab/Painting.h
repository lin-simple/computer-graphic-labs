#pragma once
#pragma warning(disable : 4996)

#include <easyx.h>
#include <graphics.h>			// 引用图形库头文件
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include "SeqStack.h"
#include "Point.h"		// 点类  之前没太注意  添加之后方便程序维护
#include "Polygon.h"
#include "MyLine.h"
#include "Utils.h"
#include "Shape.h"
#include "LineShape.h"
#include "BoundingBox.h"
#include "Matrix.h"

#define _CRT_SECURE_NO_WARNINGS 1
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
#define NUMPOINT 50	// 允许最大的坐标数量
#define MAX_VOL 20
#define WINDOW_LENGTH 1500	// 窗口大小
#define WINDOW_WIDTH 700


using namespace std;

struct Seed {
	int x; int y;
};
TCHAR a[100];

class Painting {

private:
	int x1, y1, x2, y2;			// 绘画直线的两点坐标
	int lineType, weightType, color;		// 线型  线宽  颜色
	

public:
	Painting();
	Painting(int x1, int y1, int x2, int y2, int lineType, int weightType, int color);
	~Painting();

	// set get 方法
	void setX1(int x1) { this->x1 = x1; }	int getX1() { return this->x1; }
	void setY1(int y1) { this->y1 = y1; }	int getY1() { return this->y1; }
	void setX2(int x2) { this->x2 = x2; }	int getX2() { return this->x2; }
	void setY2(int y2) { this->y2 = y2; }	int getY2() { return this->y2; }
	void setLineType(int lineType) { this->lineType = lineType; }	int getLineType() { return this->lineType; }
	void setWeightType(int weightType) { this->weightType = weightType; }	int getWeightType() { return this->weightType; }
	void setColor(int color) { this->color = color; }	int getColor() { return this->color; }

	void setCoord(int x1, int y1, int x2, int y2);		// 两个坐标点

	/* 绘画控制 */ 
	int* LineType(int lineType);	// 线型
	vector<int> LineTypeVec(int lineType);	// 线性
	void LineWidth(int x, int y, int lineType, int color, int flag);	// 线宽
	// 1.1 直线绘画
	void MidPointline();		// 中点算法绘画直线
	void Bresenhamline();		// Bresenham算法绘画直线
	void Bresenhamline(int x1, int y1, int x2, int y2);		// 重载 Bresenham 算法绘画直线
	// 1.2 圆形绘画
	void CirclePoints(int x, int y, int dx, int dy, int color, int weightType);		// 八分对称性 画圆
	void MidPointCircle();				// 中点画圆算法
	void MidPointCircle(int x1, int y1, double r);	// 中点画圆算法2

	// 2 任意多边形的绘画、填充和裁剪
	void seedFillAlgorithm(int x[], int y[],int n,int newcolor,int x0,int y0);		 //种子填充法
	void Cohen_Sutherland(int x1, int y1, int x2, int y2,int LINETYPE);		//CS直线剪裁
	void MidLineClip(int x1, int y1, int x2, int y2,int LINETYPE);		//中点分割算法
	// 改进扫描线算法
	void Init(ET& T, Edge* edges, int edge_num);   //初始化活动边表结构体
	int TableItemCount(Edge* edges, int edge_num, int* ymins);   //返回 item_num 表项的个数
	Edge* InitEdges(int* edges, int edge_num);		// 初始化边
	void DeleteNode(ET& T, int curr_ymax);		//删除所有的小于ymax 的节点
	void AppendNode(ET& T, int place_y, Edge& e);	// 将新节点插入到对应表项的邻接链表的末尾
	void myScanFill(ET T, int color, int max_y);		//绘图的方法
	Edge* GetThisEdge(ET T, double x, int y_min, int y_max);	//返回某个边的指针
	Edge* GetCurrEdges(ET T, int curr_y, int& edge_num);	//获取当前的涉及的扫描线的边
	bool IsRightTo(Edge edge1, Edge edge2);		//判断edge1 是否在edge2 的右边的方法
	void myDrawPolygon(int edges[], int edge_num);		//绘制多边形  默认左下角为坐标原点
	void myDrawPolygonReal(int edges[], int edge_num);	// 绘制多边形  默认左上角为坐标原点
	

	// 4. 曲线绘画
	void drawBezierCurve(Point point[], int n);		// n 阶 bezier 曲线绘画
	void drawBezierCurve(vector<Point> P, int n);
																		
	// 鼠标作图
	void MouseClick(Painting painting, int type);		// 鼠标点击
};

// 无参构造函数
Painting::Painting() {
	this->x1 = 0; this->y1 = 0;
	this->x2 = -100; this->y2 = -100;
	this->lineType = 0;
	this->weightType = 1;
	this->color = WHITE;
}

// 构造函数
Painting::Painting(int x1, int y1, int x2, int y2, int lineType, int weightType, int color) {
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
	this->lineType = lineType;
	this->weightType = weightType;
	this->color = color;
}

Painting::~Painting() {};

// 设置坐标
void Painting::setCoord(int x1, int y1, int x2, int y2) {
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
}


// 线型
int* Painting::LineType(int lineType)
{
	int Mask[4][32] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		// 实线
						{1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},		// 点划线
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},		// 虚线
						{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0} };	// 短线长线交替
	int* mask;

	switch (lineType) {
	case 0:
		mask = Mask[0];
		break;
	case 1:
		mask = Mask[1];
		break;
	case 2:
		mask = Mask[2];
		break;
	case 3:
		mask = Mask[3];
		break;
	default:
		mask = Mask[0];
		break;
	}

	return mask;
}

// 线型
vector<int> getMask(int Mask[][32], int col, int index)
{
	vector<int> mask(32);
	for (int i = 0; i < col; ++i) {
		mask[i] = Mask[index][i];
	}
	return mask;
}
vector<int> Painting::LineTypeVec(int lineType)
{
	int Mask[4][32] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		// 实线
						{1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},		// 点划线
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},		// 虚线
						{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0} };	// 短线长线交替
	vector<int> mask;

	switch (lineType) {
	case 0:
		mask = getMask(Mask, 32, 0);
		break;
	case 1:
		mask = getMask(Mask, 32, 1);
		break;
	case 2:
		mask = getMask(Mask, 32, 2);
		break;
	case 3:
		mask = getMask(Mask, 32, 3);
		break;
	default:
		mask = getMask(Mask, 32, 0);
		break;
	}

	return mask;
}


// 线宽
void Painting::LineWidth(int x, int y, int lineType, int color, int flag)   //flag=1水平刷，flag=0竖直刷
{
	for (int i = 0; i < lineType / 2; i++)
	{
		if (!flag)
		{
			putpixel(x + i, y, color);
			putpixel(x - i, y, color);
		}
		else
		{
			putpixel(x, y + i, color);
			putpixel(x, y - i, color);
		}
	}
}
//function1 快排
int Partition(int A[], int B[], int low, int high) {
	int pivot1 = A[low], pivot2 = B[low];//第一个元素作为基准
	while (low < high) {
		while (low < high && A[high] >= pivot1) high--;
		A[low] = A[high];
		B[low] = B[high];
		while (low < high && A[low] <= pivot1) low++;
		A[high] = A[low];
		B[high] = B[low];
	}
	A[low] = pivot1;
	B[low] = pivot2;
	return low;
}
void QuickSort(int A[], int B[], int low, int high) {
	if (low < high) {
		int pivotpos = Partition(A, B, low, high);
		QuickSort(A, B, low, pivotpos - 1);
		QuickSort(A, B, pivotpos + 1, high);
	}
}

//function2 判断多边形是否自相交
struct Line {
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int point = 0;
};
bool intersection(const Line& l1, const Line& l2)
{
	//快速排斥实验
	if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
		(l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
		(l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
		(l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2))
	{
		return 0;
	}
	//跨立实验
	if ((((l1.x1 - l2.x1) * (l2.y2 - l2.y1) - (l1.y1 - l2.y1) * (l2.x2 - l2.x1)) *
		((l1.x2 - l2.x1) * (l2.y2 - l2.y1) - (l1.y2 - l2.y1) * (l2.x2 - l2.x1))) > 0 ||
		(((l2.x1 - l1.x1) * (l1.y2 - l1.y1) - (l2.y1 - l1.y1) * (l1.x2 - l1.x1)) *
			((l2.x2 - l1.x1) * (l1.y2 - l1.y1) - (l2.y2 - l1.y1) * (l1.x2 - l1.x1))) > 0)
	{
		return 0;
	}
	return 1;
}
bool judgePol(int x[], int y[], int n)
{
	Line* l = new Line[n];
	for (int i = 0; i < n - 1; i++)
	{
		l[i].x1 = x[i]; l[i].y1 = y[i]; l[i].x2 = x[i + 1]; l[i].y2 = y[i + 1];
	}
	l[n - 1].x1 = x[n - 1]; l[n - 1].y1 = y[n - 1]; l[n - 1].x2 = x[0]; l[n - 1].y2 = y[0];
	int i, j, flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			int num = intersection(l[i], l[j]);
			l[i].point += num;
			l[j].point += num;
		}
		if (l[i].point > 2) {
			flag = 1; break;
		}
	}
	return flag;
}

/*
	* 板块1
	* 直线段绘制
*/
// 中点算法直线画法
void Painting::MidPointline()
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);		// 线型类型

	//先考虑斜率不存在的情况
	if (x1 == x2) {
		if (y1 <= y2) {
			for (int y = y1; y <= y2; y++) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
		else {
			for (int y = y1; y >= y2; y--) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
	}
	else
	{
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2; x2 = temp;
			temp = y1;
			y1 = y2; y2 = temp;
		}

		int a, b, x, y, d;
		a = y1 - y2; b = x2 - x1;
		x = x1; y = y1;

		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2; x2 = temp;
			temp = y1;
			y1 = y2; y2 = temp;
		}

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //这里判断斜率是不是>=0且<=1,后面的一样
			d = a + a + b;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				if (d >= 0) {
					x++;
					d = d + a + a;
				}
				else {
					x++;
					y++;
					d = d + a + a + b + b;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) <= (x2 - x1))		//k>-1,<0
		{
			d = a + a - b;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				if (d >= 0) {
					x++;
					y--;
					d = d + a + a - b - b;
				}
				else {
					x++;
					d = d + a + a;
				}
			}
		}
		else if (y2 >= y1 && (y2 - y1) > (x2 - x1))		//k>1
		{
			int d = a + b + b;
			while (y <= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				if (d >= 0) {
					x++;
					y++;
					d = d + a + a + b + b;
				}
				else {
					y++;
					d = d + b + b;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) >(x2 - x1))		//k<-1
		{
			int d = a - b - b;
			while (y >= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				if (d >= 0) {
					y--;
					d = d - b - b;
				}
				else {
					y--;
					x++;
					d = d - b - b + a + a;
				}
			}
		}
	}
}

// Bresenham直线算法
void Painting::Bresenhamline()
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);

	//先考虑斜率不存在的情况
	if (x1 == x2) {
		if (y1 <= y2) {
			for (int y = y1; y <= y2; y++) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
		else {
			for (int y = y1; y >= y2; y--) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
	}
	else
	{
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2; x2 = temp;
			temp = y1;
			y1 = y2; y2 = temp;
		}

		int e, dx, dy, x, y;
		dy = y2 - y1; dx = x2 - x1;
		x = x1; y = y1;

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //这里判断斜率是不是>=0且<=1,后面的一样
			e = -dx;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				x++;
				e = e + 2 * dy;
				if (e >= 0)
				{
					y++;
					e = e - 2 * dx;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) <= (x2 - x1))		//0~-1
		{
			e = dx;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				x++;
				e = e + 2 * dy;
				if (e <= 0)
				{
					y--;
					e = e + 2 * dx;
				}
			}
		}
		else if (y2 >= y1 && (y2 - y1) > (x2 - x1))		//1~无穷
		{
			e = -dy;
			while (y <= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				y++;
				e = e + 2 * dx;
				if (e >= 0)
				{
					x++;
					e = e - 2 * dy;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) >(x2 - x1))		//-1~-无穷
		{
			e = dy;
			while (y >= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				y--;
				e = e + 2 * dx;
				if (e >= 0)
				{
					x++;
					e = e + 2 * dy;
				}
			}
		}
	}
}

// 重载 Bresenham 算法
void Painting::Bresenhamline(int x1, int y1, int x2, int y2)
{
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);

	//先考虑斜率不存在的情况
	if (x1 == x2) {
		if (y1 <= y2) {
			for (int y = y1; y <= y2; y++) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
		else {
			for (int y = y1; y >= y2; y--) {
				if (mask[i % 32])
				{
					putpixel(x1, y, color);
					LineWidth(x1, y, weightType, color, 0);
				}
				i++;
			}
		}
	}
	else
	{
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2; x2 = temp;
			temp = y1;
			y1 = y2; y2 = temp;
		}

		int e, dx, dy, x, y;
		dy = y2 - y1; dx = x2 - x1;
		x = x1; y = y1;

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //这里判断斜率是不是>=0且<=1,后面的一样
			e = -dx;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				x++;
				e = e + 2 * dy;
				if (e >= 0)
				{
					y++;
					e = e - 2 * dx;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) <= (x2 - x1))		//0~-1
		{
			e = dx;
			while (x <= x2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 1);
				}
				i++;
				x++;
				e = e + 2 * dy;
				if (e <= 0)
				{
					y--;
					e = e + 2 * dx;
				}
			}
		}
		else if (y2 >= y1 && (y2 - y1) > (x2 - x1))		//1~无穷
		{
			e = -dy;
			while (y <= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				y++;
				e = e + 2 * dx;
				if (e >= 0)
				{
					x++;
					e = e - 2 * dy;
				}
			}
		}
		else if (y2 < y1 && (y1 - y2) >(x2 - x1))		//-1~-无穷
		{
			e = dy;
			while (y >= y2)
			{
				if (mask[i % 32])
				{
					putpixel(x, y, color);
					LineWidth(x, y, weightType, color, 0);
				}
				i++;
				y--;
				e = e + 2 * dx;
				if (e >= 0)
				{
					x++;
					e = e + 2 * dy;
				}
			}
		}
	}
}
/*
	* 板块2
	* 圆形绘制
*/
void Painting::CirclePoints(int x, int y, int dx, int dy, int color, int weightType)
{
	putpixel(x + dx, y + dy, color); LineWidth(x + dx, y + dy, weightType, color, 1);
	putpixel(y + dx, x + dy, color); LineWidth(y + dx, x + dy, weightType, color, 0);
	putpixel(-x + dx, y + dy, color); LineWidth(-x + dx, y + dy, weightType, color, 1);
	putpixel(y + dx, -x + dy, color); LineWidth(y + dx, -x + dy, weightType, color, 0);
	putpixel(x + dx, -y + dy, color); LineWidth(x + dx, -y + dy, weightType, color, 1);
	putpixel(-y + dx, x + dy, color); LineWidth(-y + dx, x + dy, weightType, color, 0);
	putpixel(-x + dx, -y + dy, color); LineWidth(-x + dx, -y + dy, weightType, color, 1);
	putpixel(-y + dx, -x + dy, color); LineWidth(-y + dx, -x + dy, weightType, color, 0);
}

// 中点算法画圆
void Painting::MidPointCircle ()//中点画圆算法
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;
	float x, y, e;
	float r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	x = 0;
	y = r;			//（x,y）用于确定第一个点
	e = 1 - r;		//取得初始e

	int* mask = LineType(lineType);
	while (x <= y) {
		if (mask[i % 32])
		{
			CirclePoints(x, y, x1, y1, color, weightType);	// 八分对称点
		}
		i++;
		if (e < 0) {
			x++;
			e = e + 2 * x + 3;
		}
		else {
			x++;
			y--;
			e = e + 2 * (x - y) + 5;
		}

	}
}

// 中点算法画圆2
void Painting::MidPointCircle(int x1, int y1, double r)
{
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;
	float x, y, e;
	x = 0;
	y = r;			//（x,y）用于确定第一个点
	e = 1 - r;		//取得初始e

	int* mask = LineType(lineType);
	while (x <= y) {
		if (mask[i % 32])
		{
			CirclePoints(x, y, x1, y1, color, weightType);	// 八分对称点
		}
		i++;
		if (e < 0) {
			x++;
			e = e + 2 * x + 3;
		}
		else {
			x++;
			y--;
			e = e + 2 * (x - y) + 5;
		}

	}
}

/*
	* 板块3
	* 多边形绘制
*/
// 填充算法 —— 扫描填充（用到栈）
void ScanFill4(int x, int y, int oldcolor, int newcolor)
{
	int xl, xr;
	bool spanNeedFill;
	Seed pt;
	SeqStack<Seed>* stack1 = new SeqStack<Seed>;
	stack1->Clear();
	pt.x = x;
	pt.y = y;
	stack1->Push(pt);    //将前面生成的区段压入堆栈
	while (!stack1->IsEmpty())
	{
		stack1->Pop(pt);
		y = pt.y;
		x = pt.x;
		while (getpixel(x, y) == oldcolor && getpixel(x, y) != newcolor)//向右填充
		{
			putpixel(x, y, newcolor);
			x++;
		}
		xr = x - 1;
		x = pt.x - 1;
		while (getpixel(x, y) == oldcolor && getpixel(x, y) != newcolor) //向左填充
		{
			putpixel(x, y, newcolor);
			x--;
		}
		xl = x + 1;


		//处理上一条扫描线
		x = xl;
		y = y + 1;
		while (x < xr)
		{
			spanNeedFill = false;
			while (getpixel(x, y) == oldcolor && getpixel(x, y) != newcolor)
			{
				spanNeedFill = true;
				x++;
			}
			if (spanNeedFill)
			{
				pt.x = x - 1;
				pt.y = y;
				stack1->Push(pt);
				spanNeedFill = false;
			}
			while (getpixel(x, y) != oldcolor && x < xr)
				x++;
		}
		//处理下一条扫描线，代码与处理上一条扫描线类似
		x = xl;
		y = y - 2;
		while (x < xr)
		{
			spanNeedFill = false;
			while (getpixel(x, y) == oldcolor)
			{
				spanNeedFill = true;
				x++;
			}
			if (spanNeedFill)
			{
				pt.x = x - 1;
				pt.y = y;
				stack1->Push(pt);
				spanNeedFill = false;
			}
			while (getpixel(x, y) != oldcolor && x < xr)
				x++;
		}
	}
}

// 种子填充算法
void Painting::seedFillAlgorithm(int x[], int y[], int n, int newcolor, int x0, int y0)
{
	int a = x[0], b = y[0];
	int flag = 0;
	int X[2] = { a + 1,a - 1 }, Y[2] = { b + 1,b - 1 };

	while (1)
	{ //找种子，判断 点集中间一点上下左右移1个单位像素之后的点是否可以作为种子点
		int i, j;
		bool c = 0;
		for (i = 0, j = n - 1; i < n; j = i++)
		{
			if ((((y[i] <= Y[0]) && (Y[0] < y[j])) ||
				((y[j] <= Y[0]) && (Y[0] < y[i]))) &&
				(X[0] < (x[j] - x[i]) * (Y[0] - y[i]) / (y[j] - y[i]) + x[i]))
				c = !c;
		}
		if (c == 1)
		{
			flag = 1;
			break;
		}
		for (i = 0, j = n - 1; i < n; j = i++)
		{
			if ((((y[i] <= Y[1]) && (Y[1] < y[j])) ||
				((y[j] <= Y[1]) && (Y[1] < y[i]))) &&
				(X[0] < (x[j] - x[i]) * (Y[1] - y[i]) / (y[j] - y[i]) + x[i]))
				c = !c;
		}
		if (c == 1)
		{
			flag = 2;
			break;
		}
		for (i = 0, j = n - 1; i < n; j = i++)
		{
			if ((((y[i] <= Y[1]) && (Y[1] < y[j])) ||
				((y[j] <= Y[1]) && (Y[1] < y[i]))) &&
				(X[1] < (x[j] - x[i]) * (Y[1] - y[i]) / (y[j] - y[i]) + x[i]))
				c = !c;
		}
		if (c == 1)
		{
			flag = 3;
			break;
		}
		for (i = 0, j = n - 1; i < n; j = i++)
		{
			if ((((y[i] <= Y[0]) && (Y[0] < y[j])) ||
				((y[j] <= Y[0]) && (Y[0] < y[i]))) &&
				(X[1] < (x[j] - x[i]) * (Y[0] - y[i]) / (y[j] - y[i]) + x[i]))
				c = !c;
		}
		if (c == 1)
		{
			flag = 4;
			break;
		}
		break;
	}
	//找到种子点就画，找不到就返回
	if (flag = 1)ScanFill4(X[0], Y[0], BLACK, newcolor);
	else if (flag = 2)ScanFill4(X[0], Y[1], BLACK, newcolor);
	else if (flag = 3)ScanFill4(X[1], Y[1], BLACK, newcolor);
	else if (flag = 4)ScanFill4(X[1], Y[0], BLACK, newcolor);
	else cout << "未找到种子点" << endl;


	ScanFill4(x0, y0, BLACK, color);
}


// 直线剪裁
// cohen-sutherland 裁剪算法
int encode(float x, float y, int XL, int XR, int YB, int YT)
{
	int code = 0;
	if (x < XL) code = code | LEFT;
	else if (x > XR) code = code | RIGHT;
	if (y < YB) code = code | BOTTOM;
	else if (y > YT) code = code | TOP;
	return code;
}
void Painting::Cohen_Sutherland(int x1, int y1, int x2, int y2, int LINETYPE)
{
	int code1, code2, code, XL, XR, YB, YT;
	float x, y;

	cout << "请输入保留的直线所在的矩形范围(依次为下边界 左边界 上边界 右边界)：";
	cin >> XL >> YB >> XR >> YT;
	code1 = encode(x1, y1, XL, XR, YB, YT);
	code2 = encode(x2, y2, XL, XR, YB, YT);
	while (code1 != 0 || code2 != 0)
	{
		if ((code1 & code2) != 0)
			return;
		code = code1;
		if (code1 == 0)
			code = code2;
		if ((LEFT & code) != 0)
		{
			x = XL;
			y = y1 + (y2 - y1) * (XL - x1) / (x2 - x1);
		}
		else if ((RIGHT & code) != 0)
		{
			x = XR;
			y = y1 + (y2 - y1) * (XR - x1) / (x2 - x1);
		}
		else if ((BOTTOM & code) != 0)
		{
			y = YB;
			x = x1 + (x2 - x1) * (YB - y1) / (y2 - y1);
		}
		else if ((TOP & code) != 0)
		{
			y = YT;
			x = x1 + (x2 - x1) * (YT - y1) / (y2 - y1);
		}
		if (code == code1)
		{
			x1 = x;
			y1 = y;
			code1 = encode(x, y, XL, XR, YB, YT);
		}
		else
		{
			x2 = x;
			y2 = y;
			code2 = encode(x, y, XL, XR, YB, YT);
		}
	}
	int COLOR = getColor();
	setColor(BLACK); setLineType(translateLineType("实线"));
	Bresenhamline();
	setColor(COLOR); setLineType(LINETYPE);
	setCoord(x1, y1, x2, y2);
	Bresenhamline();
}

// 中点分割算法
void Painting::MidLineClip(int x1, int y1, int x2, int y2, int LINETYPE)
{
	int code1, code2, code3, XL, XR, YB, YT;
	cout << "请输入保留的直线所在的矩形范围(依次为下边界 左边界 上边界 右边界)：";
	cin >> XL >> YB >> XR >> YT;

	float x, y, d;
	int x3, x4 = x2, y3, y4 = y2;
	code1 = encode(x1, y1, XL, XR, YB, YT);
	code2 = encode(x2, y2, XL, XR, YB, YT);
	if ((code1 & code2) != 0)
	{
		return;
	}
	while (1)//在线段与窗口有交的情况中，求出离P0最近的可见点
	{
		x = (x1 + x2) / 2.0;
		y = (y1 + y2) / 2.0;
		d = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
		if (d <= 1)//精度为1个像素
		{
			x1 = x; y1 = y; break;
		}
		code3 = encode(x, y, XL, XR, YB, YT);
		if ((code1 & code3) != 0)
		{
			x1 = x; y1 = y; code1 = encode(x1, y1, XL, XR, YB, YT);
		}
		else
		{
			x2 = x; y2 = y;
		}
	}
	x3 = x1; y3 = y1;//保存求出的交点坐标
	x2 = x4; y2 = y4;//恢复P1的初值
	while (1) //在线段与窗口有交的情况中，求出离P1最近的可见点
	{
		x = (x1 + x2) / 2.0;
		y = (y1 + y2) / 2.0;
		d = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
		if (d <= 1)
		{
			x2 = x; y2 = y; break;
		}
		code3 = encode(x, y, XL, XR, YB, YT);
		if ((code2 & code3) != 0)
		{
			x2 = x; y2 = y; code2 = encode(x2, y2, XL, XR, YB, YT);
		}
		else
		{
			x1 = x; y1 = y;
		}
	}
	x1 = x3; y1 = y3;

	int a, b, d1, d2, dd, xx, yy;
	a = y1 - y2;
	b = x2 - x1;
	int k = -(a / b);
	dd = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	xx = x1;
	yy = y1;
	int COLOR = getColor();
	setColor(BLACK); setLineType(translateLineType("实线"));
	MidPointline();
	setColor(COLOR); setLineType(LINETYPE);
	setCoord(xx, yy, x2, y2);
	MidPointline();
}

/*
	* 板块4
	* 曲线绘制
*/
void Painting::drawBezierCurve(Point P[], int n)
{
	int lineType = getLineType();
	int weightType = getWeightType();
	int color = getColor();
	double t;
	Point tmpPoint[NUMPOINT];
	Point P0;

	vector<int> mask = LineTypeVec(lineType);
	int i = 0;

	for (int i = 0; i < n; ++i)
	{
		tmpPoint[i] = P[i];
	}

	for (t = 0; t < 1; t += 0.00001)
	{
		//每一次运算都要重新赋一次初始值
		for (int i = 0; i < n; ++i)
		{
			P[i] = tmpPoint[i];
		}
		//参照n的值，一直赋初始值到P[n-1]

		int tmp_n = n;
		while (1)
		{
			if (tmp_n == 1)
				break;
			for (int i = 0; i < tmp_n - 1; i++)
			{
				P0.setX((1 - t) * P[i].getX() + t * P[i + 1].getX());
				P0.setY((1 - t) * P[i].getY() + t * P[i + 1].getY());
				P[i] = P0;
			}
			tmp_n--;
		}
		int x = P[0].getX();
		int y = P[0].getY();

		if (mask[i % 32])		// 有待改进
		{
			putpixel(x, y, color);				//计算出比例系数为t时对应的Bezier曲线上的点，画出该点。
			LineWidth(x, y, weightType, color, 1);
			LineWidth(x, y, weightType, color, 0);
		}
		++i;
	}
}

void Painting::drawBezierCurve(vector<Point> P, int n)
{
	int lineType = getLineType();
	int weightType = getWeightType();
	int color = getColor();
	double t;
	Point tmpPoint[NUMPOINT];
	Point P0;

	int* mask = LineType(lineType);
	int i = 0;

	for (int i = 0; i < n; ++i)
	{
		tmpPoint[i] = P[i];
	}

	for (t = 0; t < 1; t += 0.00001)
	{
		//每一次运算都要重新赋一次初始值
		for (int i = 0; i < n; ++i)
		{
			P[i] = tmpPoint[i];
		}
		//参照n的值，一直赋初始值到P[n-1]

		int tmp_n = n;
		while (1)
		{
			if (tmp_n == 1)
				break;
			for (int i = 0; i < tmp_n - 1; i++)
			{
				P0.setX((1 - t) * P[i].getX() + t * P[i + 1].getX());
				P0.setY((1 - t) * P[i].getY() + t * P[i + 1].getY());
				P[i] = P0;
			}
			tmp_n--;
		}
		int x = P[0].getX();
		int y = P[0].getY();
		if (mask[i % 32])		// 有待改进
		{
			putpixel(x, y, color);				//计算出比例系数为t时对应的Bezier曲线上的点，画出该点。
			LineWidth(x, y, weightType, color, 1);
			LineWidth(x, y, weightType, color, 0);
		}
		++i;

	}
}

// 鼠标绘图
void Painting::MouseClick(Painting painting, int type)		//鼠标点击
{
	MOUSEMSG m;
	// m = GetMouseMsg();
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int i = 0;
	int x[NUMPOINT], y[NUMPOINT];
	int nn;

	int edges[NUMPOINT], edge_index = 0;
	int max_y = -1;
	Edge* newEdges = NULL;
	ET etable;

	int numButtonDown = 1;		// 点击次数/插入的控制点下标-1
	vector<Point> controlPoint;	// 存储控制点
	int n_controlPoint = 2;	// 控制点数量
	int pos = 1;	// 新增控制点位置

	while (1) {
		m = GetMouseMsg();

		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 615 && m.y >= 5 && m.y <= 25)//判断是否点击退出鼠标绘图按钮
		{
			setfillcolor(RED);
			solidrectangle(500, 5, 615, 25);
			setbkmode(TRANSPARENT);
			outtextxy(510, 7, L"退出鼠标绘图");
			Sleep(100);
			setfillcolor(BLACK);
			solidrectangle(500, 5, 615, 25);
			rectangle(500, 5, 615, 25);
			outtextxy(510, 7, L"退出鼠标绘图");
			break;
		}
		else {
			if (type == 0) {
				if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标是否按下
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//判断鼠标是否弹起
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						painting.setCoord(x1, y1, x2, y2);	// 拾取并获取坐标
						painting.MidPointline();
						flag = 0;
					}
				}
			}
			else if (type == 1) {
				if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标是否按下
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//判断鼠标是否弹起
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						painting.setCoord(x1, y1, x2, y2);	// 拾取并获取坐标
						painting.MidPointCircle();
						flag = 0;
					}
				}
			}
			else if (type == 2)	// 画多边形
			{
				//TCHAR control[10];	// 动态取点用
				if (flag == 0)
				{
					cout << "请输入多边形的边数(边数 >= 3  否则退出)：";
					cin >> nn;
					if (nn < 3) {
						cout << "非法数，退出..." << endl;
						break;
					}
					flag = 1;
				}
				else if (flag == 1)
				{
					if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标是否按下
					{
						x[i] = m.x;
						y[i] = m.y;

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
						//outtextxy(m.x, m.y, control);                //输出鼠标位置
					}
					if (m.uMsg == WM_LBUTTONUP)
					{
						if (i >= 1 && i <= nn)
						{
							//_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
							//outtextxy(m.x, m.y, control);                //输出鼠标位置

							painting.setCoord(x[i], y[i], x[i - 1], y[i - 1]);	// 拾取并获取坐标

							edges[edge_index++] = graphx(x[i], 1, 0); edges[edge_index++] = graphy(y[i], 1);
							Sleep(10);
							painting.MidPointline();
						}
						i++;
						if (i >= nn)
						{
							flag = 2;
							painting.setCoord(x[0], y[0], x[nn - 1], y[nn - 1]);	// 拾取并获取坐标

							edges[edge_index++] = graphx(x[0], 1, 0); edges[edge_index++] = graphy(y[0], 1);
							edges[edge_index++] = graphx(x[1], 1, 0); edges[edge_index++] = graphy(y[1], 1);
							Sleep(10);
							painting.MidPointline();
						}
					}
				}
				else if (flag == 2)
				{
					Sleep(10);
					int x0, y0;
					string fillColor;
					/*cout << "请输入想要填充的颜色: ";
					cin >> fillColor;*/
					if (m.uMsg == WM_LBUTTONDOWN)
					{
						x0 = m.x;
						y0 = m.y;
						//circle(x1, y1, 1);
						//seedFillAlgorithm(x, y, nn, color, x0, y0);	// 保留
						/*lineScanAlgorithm(x, y, nn);*/

						for (int i = 1; i < 2 * (nn + 1); i += 2) {
							if (edges[i] > max_y)
								max_y = edges[i];
						}

						newEdges = painting.InitEdges(edges, nn);

						painting.Init(etable, newEdges, nn); //初始化活动边表
						painting.myScanFill(etable, BLUE/*translateColor(fillColor)*/, max_y);

						newEdges = NULL;
						max_y = -1;
						edge_index = 0;
						flag = 0;
						i = 0;
					}
				}
			}
			else if (type == 3)			// 画曲线
			{
				//TCHAR control[10];
				if (m.uMsg == WM_LBUTTONDOWN && numButtonDown == 1)//判断鼠标是否按下
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;

						numButtonDown++;
						controlPoint.push_back(Point(x1, y1));

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
						//outtextxy(m.x, m.y, control);                //输出鼠标位置
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//判断鼠标是否弹起
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						flag = 0;

						controlPoint.push_back(Point(x2, y2));

						//painting.setCoord(x1, y1, x2, y2);	// 拾取并获取坐标
						//painting.MidPointline();
						painting.drawBezierCurve(controlPoint, n_controlPoint);

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
						//outtextxy(m.x, m.y, control);                //输出鼠标位置
					}
				}
				else if (m.uMsg == WM_LBUTTONDOWN && numButtonDown > 1)
				{
					cout << "新增控制点: " << m.x << " " << m.y << endl;

					controlPoint.insert(controlPoint.begin() + pos, Point(m.x, m.y));
					n_controlPoint++;
					numButtonDown++;
					pos++;
					painting.drawBezierCurve(controlPoint, n_controlPoint);		// 绘画曲线

					//_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
					//outtextxy(m.x, m.y, control);                //输出鼠标位置
				}
			}
		}
	}
}

/*
  * 扫描算法
 */
 //根据多边形初始化活动表
 //参数 T 活动边表
 //参数edges 用于初始化的边数组
 //参数 edge_num 用于初始化的边的个数
void Painting::Init(ET& T, Edge* edges, int edge_num)   //初始化活动边表结构体
{
	T.item_count = 0;
	T.itemHeader = NULL;
	int ymins[20]; //存储ymin ,决定活动边表的个数以及表项的内容

	T.item_count = TableItemCount(edges, edge_num, ymins);
	T.itemHeader = (TableItem*)malloc(sizeof(TableItem));
	T.itemHeader->curr_y = ymins[0];
	T.itemHeader->firstNode = NULL;
	T.itemHeader->next = NULL;
	TableItem* p = T.itemHeader; //指向头结点
	for (int i = 1; i < T.item_count; ++i)
	{
		//依次创建活动边表的各个表项，并连接在一起
		TableItem* e = (TableItem*)malloc(sizeof(TableItem));
		e->curr_y = ymins[i];
		e->firstNode = NULL;
		e->next = NULL;
		p->next = e;
		p = e;
	}

	//按照用于初始化的边数组初始化活动边表
	p = T.itemHeader;
	for (int j = 0; j < edge_num; ++j) {
		this->AppendNode(T, edges[j].y_min, edges[j]);
	}
}

//用于根据边数组计算需要多少个表项
//表项的个数取决于边的ymin的个数
//返回值 ymin 数组
//返回 item_num 表项的个数
int Painting::TableItemCount(Edge* edges, int edge_num, int* ymins)
{
	int count = 0;
	for (int i = 0; i < edge_num; ++i)
	{
		if (!isInArray(ymins, edges[i].y_min, count))
		{
			ymins[count++] = edges[i].y_min;
		}
	}
	//将ymin 升序排序
	for (int j = 0; j < count - 1; ++j)
	{
		for (int k = j + 1; k < count; ++k)
		{
			if (ymins[k] < ymins[j])
			{
				int tmp = ymins[k];
				ymins[k] = ymins[j];
				ymins[j] = tmp;
			}
		}
	}
	return count;
}

//传入edges数组，初始化，返回Edge 结构体数组
//因为需要是封闭图形，所以，在边数组中，最后的点的坐标设为起始点的坐标，传入的edge_num 不变
Edge* Painting::InitEdges(int* edges, int edge_num)
{
	Edge* newEdges = (Edge*)malloc(sizeof(Edge) * edge_num);
	int j = 0;
	for (int i = 0; i < edge_num; ++i)
	{
		PolygonPoint point(edges[2 * i], edges[2 * i + 1], edges[2 * (i + 1)], edges[2 * (i + 1) + 1]);
		Edge* newEdge = (Edge*)malloc(sizeof(Edge));
		newEdge->x = (double)point.x();
		newEdge->y_max = point.YMax();
		newEdge->y_min = point.YMin();
		newEdge->deltax = 1.0 / point.KOfLine(); // 斜率分之一
		newEdge->next = NULL;
		newEdges[j++] = *(newEdge);
	}
	return newEdges;
}

//删除所有的小于ymax 的节点
//参数 curr_ymax 当前扫描线的y值
void Painting::DeleteNode(ET& T, int curr_ymax)
{
	TableItem* p = T.itemHeader; //指向表项的指针
	while (p != NULL) {
		Edge* item = p->firstNode; //指向表项的邻接链表的指针
		Edge* itempre = p->firstNode;   //指向前一个边结点的指针
		while (item != NULL) {
			if (item->y_max <= curr_ymax) { //删除该结点
				T.item_count--; //当前活动边表中的边的个数-1
				//判断该结点是否是该链表的头结点
				if (item == p->firstNode) {
					p->firstNode = (Edge*)malloc(sizeof(Edge));
					p->firstNode = item->next;
					free(item);  //释放该结点
					item = p->firstNode; //重新指向firstnode结点
					itempre = p->firstNode;
				}
				else {
					itempre->next = item->next; //修改前一个结点的next的值
					free(item);   //删除该指针
					item = itempre->next; //继续向后遍历
				}
			}//if (item->y_max < curr_ymax)
			else {
				itempre = item;
				item = item->next;
			}
		}//while (item != NULL)
		p = p->next;
	}//while (p != NULL)
}

//将指定y值的节点添加到该表项, 该方法插入的顺序取决于调用该方法传入参数的顺序
	//该方法将新节点插入到对应表项的邻接链表的末尾
void Painting::AppendNode(ET& T, int place_y, Edge& e)
{
	TableItem* p = T.itemHeader; //指向活动边表的头结点
	//将边e插入到对应的表项
	//之后在该表项中按照x的大小确定插入的位置
	for (int i = 0; i < T.item_count; ++i) {
		if (p->curr_y == e.y_min)
			break;
		p = p->next;
	}
	//将边插入到该表项的邻接链表中
	Edge* egp = p->firstNode; //egp 指向该表项的首个邻接节点
	if (egp == NULL) { //如果该表项还没有节点，直接插入
		egp = (Edge*)malloc(sizeof(Edge));
		*(egp) = e;
		egp->next = NULL;
		p->firstNode = egp;
	}
	else {
		Edge* pre = egp;
		while (egp != NULL) {
			pre = egp;
			egp = egp->next;
		}
		Edge* newedge = (Edge*)malloc(sizeof(Edge));
		*(newedge) = e;
		pre->next = newedge;
		newedge->next = NULL;
	}
}

//绘图的方法
void Painting::myScanFill(ET T, int color, int max_y)
{
	//首先取出ymin 值小于当前扫描线y 的边
	//按照顺序配对
	int rate = 1, relative_origin = 0;
	int curr_y = 0, curr_edge_num = 0, curr_gy = graphy(curr_y, rate); //图形坐标的扫描线的y坐标

	Edge* currEdges = (Edge*)malloc(sizeof(Edge) * 20); //用于存放指针的数组
	//将每条边的记录的 x 化为图形上的坐标
	TableItem* p = T.itemHeader;
	while (p != NULL) {
		Edge* q = p->firstNode;
		while (q != NULL) {
			q->x = graphx(q->x, rate, relative_origin);
			q = q->next;
		}
		p = p->next;
	}

	for (; curr_y < max_y; curr_gy--, curr_y = realy(curr_gy, rate)) {
		//cout << "curr_y: " << curr_y << endl;
		//cout << "curr_gy: " << curr_gy << endl;
		this->DeleteNode(T, curr_y); //删除当前扫描过的边（ymax 小于 curr_y）
		currEdges = this->GetCurrEdges(T, curr_y, curr_edge_num); //获取当前与扫描线相交的边
		//对获取到的边进行排序、配对
		for (int i = 0; i < curr_edge_num - 1; ++i) {
			for (int j = i + 1; j < curr_edge_num; ++j) {
				if (this->IsRightTo(currEdges[i], currEdges[j])) {
					Edge tmp = currEdges[i];
					currEdges[i] = currEdges[j];
					currEdges[j] = tmp;
				}
			}

		}

		setcolor(color);	// 设置前景色
		for (int j = 0; j < curr_edge_num / 2; ++j) {
			line((int)currEdges[2 * j].x, curr_gy, (int)currEdges[2 * j + 1].x, curr_gy);
			//cout << "**curr_gy**: " << curr_gy << endl;
			Edge* curr_edge1 = this->GetThisEdge(T, currEdges[2 * j].x, currEdges[2 * j].y_min,
				currEdges[2 * j].y_max); //获取当前边的指针，修改x值，保存修改
			curr_edge1->x += curr_edge1->deltax;
			Edge* curr_edge2 = this->GetThisEdge(T, currEdges[2 * j + 1].x, currEdges[2 * j + 1].y_min,
				currEdges[2 * j + 1].y_max);
			curr_edge2->x += curr_edge2->deltax;
		}
	}
}

//返回某个边的指针
//可通过此指针修改原结构体中边的x的值
Edge* Painting::GetThisEdge(ET T, double x, int y_min, int y_max)
{
	TableItem* p = T.itemHeader;
	while (p != NULL) {
		Edge* q = p->firstNode;
		while (q != NULL) {
			if ((q->x == x) && (q->y_max == y_max) && (q->y_min == y_min)) {
				return q;
			}
			q = q->next;
		}
		p = p->next;
	}

	return NULL;
}

//获取当前的涉及的扫描线的边
//即取出当前ymin 小于curr_y的边
//通过参数返回取出的边的个数
Edge* Painting::GetCurrEdges(ET T, int curr_y, int& edge_num) {
	Edge* currEdges = (Edge*)malloc(sizeof(Edge) * 20); //分配最大容量
	int i = 0;
	TableItem* p = T.itemHeader;
	while (p != NULL) {
		Edge* q = p->firstNode;
		while (q != NULL) {
			if (q->y_min <= curr_y) { //等于号很重要，否则会在图形中出现空白区
				currEdges[i++] = *q; //将当前边的值取出（不改变原活动表）
			}
			q = q->next;
		}
		p = p->next;
	}
	edge_num = i; //保存取出的边的个数
	return currEdges;
}

//判断edge1 是否在edge2 的右边的方法
bool Painting::IsRightTo(Edge edge1, Edge edge2) {
	if (edge1.x > edge2.x) //如果edge1最低点的x坐标小于edge2的最低点的x的坐标，则edge1在edge2的右边
		return true;
	else {
		if (edge1.x < edge2.x)
			return false;
		double x_max1 = (edge1.y_max - (edge1.y_min - 1.0 / edge1.deltax * edge1.x)) * edge1.deltax;
		double x_max2 = (edge2.y_max - (edge2.y_min - 1.0 / edge2.deltax * edge2.x)) * edge2.deltax;
		if (x_max1 > x_max2)
			return true;
	}
	return false;
}


//绘制多边形
void Painting::myDrawPolygon(int edges[], int edge_num) {
	int rate = 1;			// rate = 10
	int relative_origin = 0;	// 相对原点坐标

	//绘制原多边形
	for (int k = 0; k < edge_num; ++k) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		x1 = edges[2 * k] * rate + relative_origin;
		y1 = WINDOW_WIDTH - edges[2 * k + 1] * rate;
		x2 = edges[2 * (k + 1)] * rate + relative_origin;
		y2 = WINDOW_WIDTH - edges[2 * (k + 1) + 1] * rate;
		Bresenhamline(x1, y1, x2, y2);
		//line(x1, y1, x2, y2);
	}
}

void Painting::myDrawPolygonReal(int edges[], int edge_num)
{
	//绘制原多边形
	for (int k = 0; k < edge_num; ++k) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		x1 = edges[2 * k];
		y1 = edges[2 * k + 1];
		x2 = edges[2 * (k + 1)];
		y2 = edges[2 * (k + 1) + 1];
		Bresenhamline(x1, y1, x2, y2);
		//line(x1, y1, x2, y2);
	}
}
