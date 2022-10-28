#pragma once

//����εıߵ����ݽṹ
typedef struct Edge
{
	int y_max, y_min; //������ߵ�y��������ֵ����Сֵ
	double x, deltax; //������ߵ�x����Сֵ�Լ�x�ı仯������1/б�ʣ�
	struct Edge* next; //ָ����һ���ߵ�ָ��

}Edge;
//��߱����
typedef struct TableItem
{
	int curr_y;  //�ñ����y����ֵ ymin
	Edge* firstNode; //�ñ�����׸��ڵ㣬���û�У�NULL
	struct TableItem* next; //ָ����һ����߱�����ָ��
}TableItem;
//��߱�ṹ��
typedef struct Table
{
	TableItem* itemHeader; //��߱�ı���header
	int item_count; //��߱����ĸ���
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
	//����������֮�е�ymax
	int YMax()
	{
		return (y1 > y2 ? y1 : y2);
	}
	//����ymin
	int YMin()
	{
		return (y1 < y2 ? y1 : y2);
	}
	//����ymin �˵��x ֵ
	int x()
	{
		return (y1 < y2 ? x1 : x2);
	}
	//����ֱ�ߵ�б��,���մ���Ĳ�����˳��
	double KOfLine()
	{
		return ((y2 - y1) * 1.0 / (x2 - x1));
	}
};