#include "SolidCircleshape.h"

SolidCircleShape::SolidCircleShape() : Shape()
{
    this->radius = 0;
}


SolidCircleShape::~SolidCircleShape()
{
}

// ������
void SolidCircleShape::setCircle(const Point& p1, int r)
{
    this->clear();
    this->add(p1);
    this->radius = r;
}

void SolidCircleShape::setCircle(int x1, int y1, int r)
{
    this->setCircle(Point(x1, y1), r);
}

// ���ػ��ƺ���
void SolidCircleShape::drawShape(const std::vector<Point>& points)
{
    if (points.size() == 1) {
        setfillcolor(this->getColor());

        solidcircle((int)points[0].x, (int)points[0].y, radius);
    }
}