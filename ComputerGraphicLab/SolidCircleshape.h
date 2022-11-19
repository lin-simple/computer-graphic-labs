#pragma once
#include "Shape.h"

// ֱ�ߵ���״
class SolidCircleShape : public Shape
{
public:
    SolidCircleShape();
    ~SolidCircleShape();

    // ������
    void setCircle(const Point& p1, int r);
    void setCircle(int x1, int y1, int r);


private:
    // ���ػ��ƺ���
    void drawShape(const std::vector<Point>& points);
    int radius;
};