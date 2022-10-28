#pragma once

//多边形的边的数据结构
typedef struct Edge
{
	int y_max, y_min; //该有向边的y坐标的最大值与最小值
	double x, deltax; //该有向边的x的最小值以及x的变化的量（1/斜率）
	struct Edge* next; //指向下一条边的指针

}Edge;
//活动边表表项
typedef struct TableItem
{
	int curr_y;  //该表项的y坐标值 ymin
	Edge* firstNode; //该表项的首个节点，如果没有，NULL
	struct TableItem* next; //指向下一个活动边表表项的指针
}TableItem;
//活动边表结构体
typedef struct Table
{
	TableItem* itemHeader; //活动边表的表项header
	int item_count; //活动边表表项的个数
}ET;


class PolygonPoint
{
private:
	int x1, x2, y1, y2;
public:
	PolygonPoint(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}
	//返回两个点之中的ymax
	int YMax()
	{
		return (y1 > y2 ? y1 : y2);
	}
	//返回ymin
	int YMin()
	{
		return (y1 < y2 ? y1 : y2);
	}
	//返回ymin 端点的x 值
	int x()
	{
		return (y1 < y2 ? x1 : x2);
	}
	//返回直线的斜率,按照传入的参数的顺序
	double KOfLine()
	{
		return ((y2 - y1) * 1.0 / (x2 - x1));
	}
};