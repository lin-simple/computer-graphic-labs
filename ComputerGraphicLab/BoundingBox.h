#pragma once

#include <graphics.h>
#include <stdio.h>
#include "Point.h"

// ���ΰ�Χ��

class BoundingBox : public RECT
{
public:
    BoundingBox()
    {
        reset();
    }

    BoundingBox(int left, int top, int right, int bottom)
    {
        RECT::left = left;
        RECT::top = top;
        RECT::right = right;
        RECT::bottom = bottom;
    }

    // ������Ч����
    void reset()
    {
        // ��ʼ��һ����Ч�ľ���
        left = top = INT_MAX;       // ���Ͻ����ֵ
        right = bottom = INT_MIN;   // ���½���Сֵ
    }

    // ���һ���㣬����չ��Χ����
    void setPoint(int x, int y)
    {
        if (x < left)left = x;
        if (x > right)right = x;
        if (y < top)top = y;
        if (y > bottom)bottom = y;
    }

    void setPoint(const Point& p)
    {
        this->setPoint(p.x, p.y);
    }

    int getWidth()const
    {
        return right - left;
    }

    int getHeight()const
    {
        return bottom - top;
    }

    // ��ȡ��Χ��������λ��
    Point getCenter()const
    {
        // ��Ч�ľ���
        if (left > right || bottom < top) {
            return Point();
        }


        //Point point = Point(left + (this->getWidth() / 2), top + (this->getHeight() / 2));
        Point point = Point();
        int xx = left + (this->getWidth() / 2), yy = top + (this->getHeight() / 2);
        point.setPoint(xx, yy);
        return point;
    }

    // �ж����������Ƿ��ཻ
    bool intersect(const BoundingBox& other)const
    {
        RECT temp;
        return IntersectRect(&temp, this, &other);
    }

    // �жϰ�Χ���Ƿ������
    bool contaits(int x, int y)
    {
        return x >= left && y >= top && x < right&& y < bottom;
    }

    bool contaits(const Point& p)
    {
        return this->contaits(p.x, p.y);
    }

    // ����
    void draw()
    {
        LINESTYLE style;
        getlinestyle(&style);
        setlinecolor(RGB(0, 0, 255));
        setlinestyle(PS_DASH, 1);
        rectangle(left, top, right, bottom);
        setlinestyle(&style);

        //TCHAR buf[100] = { 0 };
        //settextcolor(BLACK);
        //snprintf(buf, sizeof(buf), "%d, %d - %d, %d", left, top, right, bottom);
        //_stprintf(buf, _T("%d, %d - %d, %d"), left, top, right, bottom);
        //outtextxy(left, top - 20, buf);
    }
};
