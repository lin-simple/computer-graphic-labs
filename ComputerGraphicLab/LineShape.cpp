#include "LineShape.h"

LineShape::LineShape() : Shape()
{
}


LineShape::~LineShape()
{
}

// ������
void LineShape::setLine(const Point& p1, const Point& p2)
{
    this->clear();
    this->add(p1);
    this->add(p2);
}

void LineShape::setLine(int x1, int y1, int x2, int y2)
{
    this->setLine(Point(x1, y1), Point(x2, y2));
}

// ���ػ��ƺ���
void LineShape::drawShape(const std::vector<Point>& points)
{
    // ֱ��������Ҫ��������
    if (points.size() == 2) {
        setcolor(this->getColor());

        // ��ͼ��Ļ��ߺ�����������Ըĳ��Լ�д��
        line((int)points[0].x, (int)points[0].y, (int)points[1].x, (int)points[1].y);
    }
}