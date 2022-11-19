#pragma once
#include "Shape.h"

// 直线的形状
class SolidCircleShape : public Shape
{
public:
    SolidCircleShape();
    ~SolidCircleShape();

    // 设置线
    void setCircle(const Point& p1, int r);
    void setCircle(int x1, int y1, int r);


private:
    // 重载绘制函数
    void drawShape(const std::vector<Point>& points);
    int radius;
};