#include "LineShape.h"

LineShape::LineShape() : Shape()
{
}


LineShape::~LineShape()
{
}

// 设置线
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

// 重载绘制函数
void LineShape::drawShape(const std::vector<Point>& points)
{
    // 直线至少需要两个顶点
    if (points.size() == 2) {
        setcolor(this->getColor());

        // 绘图库的画线函数，这里可以改成自己写的
        line((int)points[0].x, (int)points[0].y, (int)points[1].x, (int)points[1].y);
    }
}