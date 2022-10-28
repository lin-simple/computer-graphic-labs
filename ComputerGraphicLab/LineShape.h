#pragma once

#include "Shape.h"

// 直线的形状
class LineShape : public Shape
{
public:
    LineShape();
    ~LineShape();

    // 设置线
    void setLine(const Point& p1, const Point& p2);
    void setLine(int x1, int y1, int x2, int y2);


private:
    // 重载绘制函数
    void drawShape(const std::vector<Point>& points);
};

