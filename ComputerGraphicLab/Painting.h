#pragma once
#pragma warning(disable : 4996)

#include <easyx.h>
#include <graphics.h>			// ����ͼ�ο�ͷ�ļ�
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include "SeqStack.h"
#include "Point.h"		// ����  ֮ǰû̫ע��  ���֮�󷽱����ά��
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
#define NUMPOINT 50	// ����������������
#define MAX_VOL 20
#define WINDOW_LENGTH 1500	// ���ڴ�С
#define WINDOW_WIDTH 700


using namespace std;

struct Seed {
	int x; int y;
};
TCHAR a[100];

class Painting {

private:
	int x1, y1, x2, y2;			// �滭ֱ�ߵ���������
	int lineType, weightType, color;		// ����  �߿�  ��ɫ
	

public:
	Painting();
	Painting(int x1, int y1, int x2, int y2, int lineType, int weightType, int color);
	~Painting();

	// set get ����
	void setX1(int x1) { this->x1 = x1; }	int getX1() { return this->x1; }
	void setY1(int y1) { this->y1 = y1; }	int getY1() { return this->y1; }
	void setX2(int x2) { this->x2 = x2; }	int getX2() { return this->x2; }
	void setY2(int y2) { this->y2 = y2; }	int getY2() { return this->y2; }
	void setLineType(int lineType) { this->lineType = lineType; }	int getLineType() { return this->lineType; }
	void setWeightType(int weightType) { this->weightType = weightType; }	int getWeightType() { return this->weightType; }
	void setColor(int color) { this->color = color; }	int getColor() { return this->color; }

	void setCoord(int x1, int y1, int x2, int y2);		// ���������

	/* �滭���� */ 
	int* LineType(int lineType);	// ����
	vector<int> LineTypeVec(int lineType);	// ����
	void LineWidth(int x, int y, int lineType, int color, int flag);	// �߿�
	// 1.1 ֱ�߻滭
	void MidPointline();		// �е��㷨�滭ֱ��
	void Bresenhamline();		// Bresenham�㷨�滭ֱ��
	void Bresenhamline(int x1, int y1, int x2, int y2);		// ���� Bresenham �㷨�滭ֱ��
	// 1.2 Բ�λ滭
	void CirclePoints(int x, int y, int dx, int dy, int color, int weightType);		// �˷ֶԳ��� ��Բ
	void MidPointCircle();				// �е㻭Բ�㷨
	void MidPointCircle(int x1, int y1, double r);	// �е㻭Բ�㷨2

	// 2 �������εĻ滭�����Ͳü�
	void seedFillAlgorithm(int x[], int y[],int n,int newcolor,int x0,int y0);		 //������䷨
	void Cohen_Sutherland(int x1, int y1, int x2, int y2,int LINETYPE);		//CSֱ�߼���
	void MidLineClip(int x1, int y1, int x2, int y2,int LINETYPE);		//�е�ָ��㷨
	// �Ľ�ɨ�����㷨
	void Init(ET& T, Edge* edges, int edge_num);   //��ʼ����߱�ṹ��
	int TableItemCount(Edge* edges, int edge_num, int* ymins);   //���� item_num ����ĸ���
	Edge* InitEdges(int* edges, int edge_num);		// ��ʼ����
	void DeleteNode(ET& T, int curr_ymax);		//ɾ�����е�С��ymax �Ľڵ�
	void AppendNode(ET& T, int place_y, Edge& e);	// ���½ڵ���뵽��Ӧ������ڽ������ĩβ
	void myScanFill(ET T, int color, int max_y);		//��ͼ�ķ���
	Edge* GetThisEdge(ET T, double x, int y_min, int y_max);	//����ĳ���ߵ�ָ��
	Edge* GetCurrEdges(ET T, int curr_y, int& edge_num);	//��ȡ��ǰ���漰��ɨ���ߵı�
	bool IsRightTo(Edge edge1, Edge edge2);		//�ж�edge1 �Ƿ���edge2 ���ұߵķ���
	void myDrawPolygon(int edges[], int edge_num);		//���ƶ����  Ĭ�����½�Ϊ����ԭ��
	void myDrawPolygonReal(int edges[], int edge_num);	// ���ƶ����  Ĭ�����Ͻ�Ϊ����ԭ��
	

	// 4. ���߻滭
	void drawBezierCurve(Point point[], int n);		// n �� bezier ���߻滭
	void drawBezierCurve(vector<Point> P, int n);
																		
	// �����ͼ
	void MouseClick(Painting painting, int type);		// �����
};

// �޲ι��캯��
Painting::Painting() {
	this->x1 = 0; this->y1 = 0;
	this->x2 = -100; this->y2 = -100;
	this->lineType = 0;
	this->weightType = 1;
	this->color = WHITE;
}

// ���캯��
Painting::Painting(int x1, int y1, int x2, int y2, int lineType, int weightType, int color) {
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
	this->lineType = lineType;
	this->weightType = weightType;
	this->color = color;
}

Painting::~Painting() {};

// ��������
void Painting::setCoord(int x1, int y1, int x2, int y2) {
	this->x1 = x1; this->y1 = y1;
	this->x2 = x2; this->y2 = y2;
}


// ����
int* Painting::LineType(int lineType)
{
	int Mask[4][32] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		// ʵ��
						{1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},		// �㻮��
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},		// ����
						{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0} };	// ���߳��߽���
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

// ����
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
	int Mask[4][32] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},		// ʵ��
						{1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},		// �㻮��
						{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},		// ����
						{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0} };	// ���߳��߽���
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


// �߿�
void Painting::LineWidth(int x, int y, int lineType, int color, int flag)   //flag=1ˮƽˢ��flag=0��ֱˢ
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
//function1 ����
int Partition(int A[], int B[], int low, int high) {
	int pivot1 = A[low], pivot2 = B[low];//��һ��Ԫ����Ϊ��׼
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

//function2 �ж϶�����Ƿ����ཻ
struct Line {
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int point = 0;
};
bool intersection(const Line& l1, const Line& l2)
{
	//�����ų�ʵ��
	if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
		(l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
		(l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
		(l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2))
	{
		return 0;
	}
	//����ʵ��
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
	* ���1
	* ֱ�߶λ���
*/
// �е��㷨ֱ�߻���
void Painting::MidPointline()
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);		// ��������

	//�ȿ���б�ʲ����ڵ����
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

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //�����ж�б���ǲ���>=0��<=1,�����һ��
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

// Bresenhamֱ���㷨
void Painting::Bresenhamline()
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);

	//�ȿ���б�ʲ����ڵ����
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

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //�����ж�б���ǲ���>=0��<=1,�����һ��
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
		else if (y2 >= y1 && (y2 - y1) > (x2 - x1))		//1~����
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
		else if (y2 < y1 && (y1 - y2) >(x2 - x1))		//-1~-����
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

// ���� Bresenham �㷨
void Painting::Bresenhamline(int x1, int y1, int x2, int y2)
{
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;

	int* mask = LineType(lineType);

	//�ȿ���б�ʲ����ڵ����
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

		if (y2 >= y1 && (y2 - y1) <= (x2 - x1)) {       //�����ж�б���ǲ���>=0��<=1,�����һ��
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
		else if (y2 >= y1 && (y2 - y1) > (x2 - x1))		//1~����
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
		else if (y2 < y1 && (y1 - y2) >(x2 - x1))		//-1~-����
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
	* ���2
	* Բ�λ���
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

// �е��㷨��Բ
void Painting::MidPointCircle ()//�е㻭Բ�㷨
{
	int x1 = getX1(), y1 = getY1();
	int x2 = getX2(), y2 = getY2();
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;
	float x, y, e;
	float r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	x = 0;
	y = r;			//��x,y������ȷ����һ����
	e = 1 - r;		//ȡ�ó�ʼe

	int* mask = LineType(lineType);
	while (x <= y) {
		if (mask[i % 32])
		{
			CirclePoints(x, y, x1, y1, color, weightType);	// �˷ֶԳƵ�
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

// �е��㷨��Բ2
void Painting::MidPointCircle(int x1, int y1, double r)
{
	int lineType = getLineType(), weightType = getWeightType();
	int color = getColor();
	int i = 0;
	float x, y, e;
	x = 0;
	y = r;			//��x,y������ȷ����һ����
	e = 1 - r;		//ȡ�ó�ʼe

	int* mask = LineType(lineType);
	while (x <= y) {
		if (mask[i % 32])
		{
			CirclePoints(x, y, x1, y1, color, weightType);	// �˷ֶԳƵ�
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
	* ���3
	* ����λ���
*/
// ����㷨 ���� ɨ����䣨�õ�ջ��
void ScanFill4(int x, int y, int oldcolor, int newcolor)
{
	int xl, xr;
	bool spanNeedFill;
	Seed pt;
	SeqStack<Seed>* stack1 = new SeqStack<Seed>;
	stack1->Clear();
	pt.x = x;
	pt.y = y;
	stack1->Push(pt);    //��ǰ�����ɵ�����ѹ���ջ
	while (!stack1->IsEmpty())
	{
		stack1->Pop(pt);
		y = pt.y;
		x = pt.x;
		while (getpixel(x, y) == oldcolor && getpixel(x, y) != newcolor)//�������
		{
			putpixel(x, y, newcolor);
			x++;
		}
		xr = x - 1;
		x = pt.x - 1;
		while (getpixel(x, y) == oldcolor && getpixel(x, y) != newcolor) //�������
		{
			putpixel(x, y, newcolor);
			x--;
		}
		xl = x + 1;


		//������һ��ɨ����
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
		//������һ��ɨ���ߣ������봦����һ��ɨ��������
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

// ��������㷨
void Painting::seedFillAlgorithm(int x[], int y[], int n, int newcolor, int x0, int y0)
{
	int a = x[0], b = y[0];
	int flag = 0;
	int X[2] = { a + 1,a - 1 }, Y[2] = { b + 1,b - 1 };

	while (1)
	{ //�����ӣ��ж� �㼯�м�һ������������1����λ����֮��ĵ��Ƿ������Ϊ���ӵ�
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
	//�ҵ����ӵ�ͻ����Ҳ����ͷ���
	if (flag = 1)ScanFill4(X[0], Y[0], BLACK, newcolor);
	else if (flag = 2)ScanFill4(X[0], Y[1], BLACK, newcolor);
	else if (flag = 3)ScanFill4(X[1], Y[1], BLACK, newcolor);
	else if (flag = 4)ScanFill4(X[1], Y[0], BLACK, newcolor);
	else cout << "δ�ҵ����ӵ�" << endl;


	ScanFill4(x0, y0, BLACK, color);
}


// ֱ�߼���
// cohen-sutherland �ü��㷨
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

	cout << "�����뱣����ֱ�����ڵľ��η�Χ(����Ϊ�±߽� ��߽� �ϱ߽� �ұ߽�)��";
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
	setColor(BLACK); setLineType(translateLineType("ʵ��"));
	Bresenhamline();
	setColor(COLOR); setLineType(LINETYPE);
	setCoord(x1, y1, x2, y2);
	Bresenhamline();
}

// �е�ָ��㷨
void Painting::MidLineClip(int x1, int y1, int x2, int y2, int LINETYPE)
{
	int code1, code2, code3, XL, XR, YB, YT;
	cout << "�����뱣����ֱ�����ڵľ��η�Χ(����Ϊ�±߽� ��߽� �ϱ߽� �ұ߽�)��";
	cin >> XL >> YB >> XR >> YT;

	float x, y, d;
	int x3, x4 = x2, y3, y4 = y2;
	code1 = encode(x1, y1, XL, XR, YB, YT);
	code2 = encode(x2, y2, XL, XR, YB, YT);
	if ((code1 & code2) != 0)
	{
		return;
	}
	while (1)//���߶��봰���н�������У������P0����Ŀɼ���
	{
		x = (x1 + x2) / 2.0;
		y = (y1 + y2) / 2.0;
		d = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
		if (d <= 1)//����Ϊ1������
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
	x3 = x1; y3 = y1;//��������Ľ�������
	x2 = x4; y2 = y4;//�ָ�P1�ĳ�ֵ
	while (1) //���߶��봰���н�������У������P1����Ŀɼ���
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
	setColor(BLACK); setLineType(translateLineType("ʵ��"));
	MidPointline();
	setColor(COLOR); setLineType(LINETYPE);
	setCoord(xx, yy, x2, y2);
	MidPointline();
}

/*
	* ���4
	* ���߻���
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
		//ÿһ�����㶼Ҫ���¸�һ�γ�ʼֵ
		for (int i = 0; i < n; ++i)
		{
			P[i] = tmpPoint[i];
		}
		//����n��ֵ��һֱ����ʼֵ��P[n-1]

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

		if (mask[i % 32])		// �д��Ľ�
		{
			putpixel(x, y, color);				//���������ϵ��Ϊtʱ��Ӧ��Bezier�����ϵĵ㣬�����õ㡣
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
		//ÿһ�����㶼Ҫ���¸�һ�γ�ʼֵ
		for (int i = 0; i < n; ++i)
		{
			P[i] = tmpPoint[i];
		}
		//����n��ֵ��һֱ����ʼֵ��P[n-1]

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
		if (mask[i % 32])		// �д��Ľ�
		{
			putpixel(x, y, color);				//���������ϵ��Ϊtʱ��Ӧ��Bezier�����ϵĵ㣬�����õ㡣
			LineWidth(x, y, weightType, color, 1);
			LineWidth(x, y, weightType, color, 0);
		}
		++i;

	}
}

// ����ͼ
void Painting::MouseClick(Painting painting, int type)		//�����
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

	int numButtonDown = 1;		// �������/����Ŀ��Ƶ��±�-1
	vector<Point> controlPoint;	// �洢���Ƶ�
	int n_controlPoint = 2;	// ���Ƶ�����
	int pos = 1;	// �������Ƶ�λ��

	while (1) {
		m = GetMouseMsg();

		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 500 && m.x <= 615 && m.y >= 5 && m.y <= 25)//�ж��Ƿ����˳�����ͼ��ť
		{
			setfillcolor(RED);
			solidrectangle(500, 5, 615, 25);
			setbkmode(TRANSPARENT);
			outtextxy(510, 7, L"�˳�����ͼ");
			Sleep(100);
			setfillcolor(BLACK);
			solidrectangle(500, 5, 615, 25);
			rectangle(500, 5, 615, 25);
			outtextxy(510, 7, L"�˳�����ͼ");
			break;
		}
		else {
			if (type == 0) {
				if (m.uMsg == WM_LBUTTONDOWN)//�ж�����Ƿ���
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						painting.setCoord(x1, y1, x2, y2);	// ʰȡ����ȡ����
						painting.MidPointline();
						flag = 0;
					}
				}
			}
			else if (type == 1) {
				if (m.uMsg == WM_LBUTTONDOWN)//�ж�����Ƿ���
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						painting.setCoord(x1, y1, x2, y2);	// ʰȡ����ȡ����
						painting.MidPointCircle();
						flag = 0;
					}
				}
			}
			else if (type == 2)	// �������
			{
				//TCHAR control[10];	// ��̬ȡ����
				if (flag == 0)
				{
					cout << "���������εı���(���� >= 3  �����˳�)��";
					cin >> nn;
					if (nn < 3) {
						cout << "�Ƿ������˳�..." << endl;
						break;
					}
					flag = 1;
				}
				else if (flag == 1)
				{
					if (m.uMsg == WM_LBUTTONDOWN)//�ж�����Ƿ���
					{
						x[i] = m.x;
						y[i] = m.y;

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
						//outtextxy(m.x, m.y, control);                //������λ��
					}
					if (m.uMsg == WM_LBUTTONUP)
					{
						if (i >= 1 && i <= nn)
						{
							//_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
							//outtextxy(m.x, m.y, control);                //������λ��

							painting.setCoord(x[i], y[i], x[i - 1], y[i - 1]);	// ʰȡ����ȡ����

							edges[edge_index++] = graphx(x[i], 1, 0); edges[edge_index++] = graphy(y[i], 1);
							Sleep(10);
							painting.MidPointline();
						}
						i++;
						if (i >= nn)
						{
							flag = 2;
							painting.setCoord(x[0], y[0], x[nn - 1], y[nn - 1]);	// ʰȡ����ȡ����

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
					/*cout << "��������Ҫ������ɫ: ";
					cin >> fillColor;*/
					if (m.uMsg == WM_LBUTTONDOWN)
					{
						x0 = m.x;
						y0 = m.y;
						//circle(x1, y1, 1);
						//seedFillAlgorithm(x, y, nn, color, x0, y0);	// ����
						/*lineScanAlgorithm(x, y, nn);*/

						for (int i = 1; i < 2 * (nn + 1); i += 2) {
							if (edges[i] > max_y)
								max_y = edges[i];
						}

						newEdges = painting.InitEdges(edges, nn);

						painting.Init(etable, newEdges, nn); //��ʼ����߱�
						painting.myScanFill(etable, BLUE/*translateColor(fillColor)*/, max_y);

						newEdges = NULL;
						max_y = -1;
						edge_index = 0;
						flag = 0;
						i = 0;
					}
				}
			}
			else if (type == 3)			// ������
			{
				//TCHAR control[10];
				if (m.uMsg == WM_LBUTTONDOWN && numButtonDown == 1)//�ж�����Ƿ���
				{
					if (flag == 0)
					{
						x1 = m.x;
						y1 = m.y;
						flag = 1;

						numButtonDown++;
						controlPoint.push_back(Point(x1, y1));

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
						//outtextxy(m.x, m.y, control);                //������λ��
					}
				}
				else if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
				{
					if (flag == 1)
					{
						x2 = m.x;
						y2 = m.y;
						flag = 0;

						controlPoint.push_back(Point(x2, y2));

						//painting.setCoord(x1, y1, x2, y2);	// ʰȡ����ȡ����
						//painting.MidPointline();
						painting.drawBezierCurve(controlPoint, n_controlPoint);

						//_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
						//outtextxy(m.x, m.y, control);                //������λ��
					}
				}
				else if (m.uMsg == WM_LBUTTONDOWN && numButtonDown > 1)
				{
					cout << "�������Ƶ�: " << m.x << " " << m.y << endl;

					controlPoint.insert(controlPoint.begin() + pos, Point(m.x, m.y));
					n_controlPoint++;
					numButtonDown++;
					pos++;
					painting.drawBezierCurve(controlPoint, n_controlPoint);		// �滭����

					//_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
					//outtextxy(m.x, m.y, control);                //������λ��
				}
			}
		}
	}
}

/*
  * ɨ���㷨
 */
 //���ݶ���γ�ʼ�����
 //���� T ��߱�
 //����edges ���ڳ�ʼ���ı�����
 //���� edge_num ���ڳ�ʼ���ıߵĸ���
void Painting::Init(ET& T, Edge* edges, int edge_num)   //��ʼ����߱�ṹ��
{
	T.item_count = 0;
	T.itemHeader = NULL;
	int ymins[20]; //�洢ymin ,������߱�ĸ����Լ����������

	T.item_count = TableItemCount(edges, edge_num, ymins);
	T.itemHeader = (TableItem*)malloc(sizeof(TableItem));
	T.itemHeader->curr_y = ymins[0];
	T.itemHeader->firstNode = NULL;
	T.itemHeader->next = NULL;
	TableItem* p = T.itemHeader; //ָ��ͷ���
	for (int i = 1; i < T.item_count; ++i)
	{
		//���δ�����߱�ĸ��������������һ��
		TableItem* e = (TableItem*)malloc(sizeof(TableItem));
		e->curr_y = ymins[i];
		e->firstNode = NULL;
		e->next = NULL;
		p->next = e;
		p = e;
	}

	//�������ڳ�ʼ���ı������ʼ����߱�
	p = T.itemHeader;
	for (int j = 0; j < edge_num; ++j) {
		this->AppendNode(T, edges[j].y_min, edges[j]);
	}
}

//���ڸ��ݱ����������Ҫ���ٸ�����
//����ĸ���ȡ���ڱߵ�ymin�ĸ���
//����ֵ ymin ����
//���� item_num ����ĸ���
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
	//��ymin ��������
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

//����edges���飬��ʼ��������Edge �ṹ������
//��Ϊ��Ҫ�Ƿ��ͼ�Σ����ԣ��ڱ������У����ĵ��������Ϊ��ʼ������꣬�����edge_num ����
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
		newEdge->deltax = 1.0 / point.KOfLine(); // б�ʷ�֮һ
		newEdge->next = NULL;
		newEdges[j++] = *(newEdge);
	}
	return newEdges;
}

//ɾ�����е�С��ymax �Ľڵ�
//���� curr_ymax ��ǰɨ���ߵ�yֵ
void Painting::DeleteNode(ET& T, int curr_ymax)
{
	TableItem* p = T.itemHeader; //ָ������ָ��
	while (p != NULL) {
		Edge* item = p->firstNode; //ָ�������ڽ������ָ��
		Edge* itempre = p->firstNode;   //ָ��ǰһ���߽���ָ��
		while (item != NULL) {
			if (item->y_max <= curr_ymax) { //ɾ���ý��
				T.item_count--; //��ǰ��߱��еıߵĸ���-1
				//�жϸý���Ƿ��Ǹ������ͷ���
				if (item == p->firstNode) {
					p->firstNode = (Edge*)malloc(sizeof(Edge));
					p->firstNode = item->next;
					free(item);  //�ͷŸý��
					item = p->firstNode; //����ָ��firstnode���
					itempre = p->firstNode;
				}
				else {
					itempre->next = item->next; //�޸�ǰһ������next��ֵ
					free(item);   //ɾ����ָ��
					item = itempre->next; //����������
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

//��ָ��yֵ�Ľڵ���ӵ��ñ���, �÷��������˳��ȡ���ڵ��ø÷������������˳��
	//�÷������½ڵ���뵽��Ӧ������ڽ������ĩβ
void Painting::AppendNode(ET& T, int place_y, Edge& e)
{
	TableItem* p = T.itemHeader; //ָ���߱��ͷ���
	//����e���뵽��Ӧ�ı���
	//֮���ڸñ����а���x�Ĵ�Сȷ�������λ��
	for (int i = 0; i < T.item_count; ++i) {
		if (p->curr_y == e.y_min)
			break;
		p = p->next;
	}
	//���߲��뵽�ñ�����ڽ�������
	Edge* egp = p->firstNode; //egp ָ��ñ�����׸��ڽӽڵ�
	if (egp == NULL) { //����ñ��û�нڵ㣬ֱ�Ӳ���
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

//��ͼ�ķ���
void Painting::myScanFill(ET T, int color, int max_y)
{
	//����ȡ��ymin ֵС�ڵ�ǰɨ����y �ı�
	//����˳�����
	int rate = 1, relative_origin = 0;
	int curr_y = 0, curr_edge_num = 0, curr_gy = graphy(curr_y, rate); //ͼ�������ɨ���ߵ�y����

	Edge* currEdges = (Edge*)malloc(sizeof(Edge) * 20); //���ڴ��ָ�������
	//��ÿ���ߵļ�¼�� x ��Ϊͼ���ϵ�����
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
		this->DeleteNode(T, curr_y); //ɾ����ǰɨ����ıߣ�ymax С�� curr_y��
		currEdges = this->GetCurrEdges(T, curr_y, curr_edge_num); //��ȡ��ǰ��ɨ�����ཻ�ı�
		//�Ի�ȡ���ı߽����������
		for (int i = 0; i < curr_edge_num - 1; ++i) {
			for (int j = i + 1; j < curr_edge_num; ++j) {
				if (this->IsRightTo(currEdges[i], currEdges[j])) {
					Edge tmp = currEdges[i];
					currEdges[i] = currEdges[j];
					currEdges[j] = tmp;
				}
			}

		}

		setcolor(color);	// ����ǰ��ɫ
		for (int j = 0; j < curr_edge_num / 2; ++j) {
			line((int)currEdges[2 * j].x, curr_gy, (int)currEdges[2 * j + 1].x, curr_gy);
			//cout << "**curr_gy**: " << curr_gy << endl;
			Edge* curr_edge1 = this->GetThisEdge(T, currEdges[2 * j].x, currEdges[2 * j].y_min,
				currEdges[2 * j].y_max); //��ȡ��ǰ�ߵ�ָ�룬�޸�xֵ�������޸�
			curr_edge1->x += curr_edge1->deltax;
			Edge* curr_edge2 = this->GetThisEdge(T, currEdges[2 * j + 1].x, currEdges[2 * j + 1].y_min,
				currEdges[2 * j + 1].y_max);
			curr_edge2->x += curr_edge2->deltax;
		}
	}
}

//����ĳ���ߵ�ָ��
//��ͨ����ָ���޸�ԭ�ṹ���бߵ�x��ֵ
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

//��ȡ��ǰ���漰��ɨ���ߵı�
//��ȡ����ǰymin С��curr_y�ı�
//ͨ����������ȡ���ıߵĸ���
Edge* Painting::GetCurrEdges(ET T, int curr_y, int& edge_num) {
	Edge* currEdges = (Edge*)malloc(sizeof(Edge) * 20); //�����������
	int i = 0;
	TableItem* p = T.itemHeader;
	while (p != NULL) {
		Edge* q = p->firstNode;
		while (q != NULL) {
			if (q->y_min <= curr_y) { //���ںź���Ҫ���������ͼ���г��ֿհ���
				currEdges[i++] = *q; //����ǰ�ߵ�ֵȡ�������ı�ԭ���
			}
			q = q->next;
		}
		p = p->next;
	}
	edge_num = i; //����ȡ���ıߵĸ���
	return currEdges;
}

//�ж�edge1 �Ƿ���edge2 ���ұߵķ���
bool Painting::IsRightTo(Edge edge1, Edge edge2) {
	if (edge1.x > edge2.x) //���edge1��͵��x����С��edge2����͵��x�����꣬��edge1��edge2���ұ�
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


//���ƶ����
void Painting::myDrawPolygon(int edges[], int edge_num) {
	int rate = 1;			// rate = 10
	int relative_origin = 0;	// ���ԭ������

	//����ԭ�����
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
	//����ԭ�����
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
