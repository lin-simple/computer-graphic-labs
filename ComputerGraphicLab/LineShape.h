#pragma once

#include "Shape.h"

// ֱ�ߵ���״
class LineShape : public Shape
{
public:
    LineShape();
    ~LineShape();

    // ������
    void setLine(const Point& p1, const Point& p2);
    void setLine(int x1, int y1, int x2, int y2);


private:
    // ���ػ��ƺ���
    void drawShape(const std::vector<Point>& points);
};

