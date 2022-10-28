#pragma once

#include "Matrix.h"
#include "BoundingBox.h"
#include <vector>           // ʹ�� vector ��̬����

class Shape
{
public:
    Shape();
    ~Shape();

    // ���һ����
    void add(const Point& p);

    // ������е�
    void clear();

    // ������״��ɫ
    void setColor(COLORREF color);

    // ��ȡ��״��ɫ
    COLORREF getColor()const;

    // ��ȡ��״�İ�Χ����
    BoundingBox getBoundingBox()const;

    // ����
    void draw();

    //
    // ��װ�ľ���任
    //

    // ���ñ任����
    void setTransform(const Matrix& mat);

    // ��ȡ��ǰ��ת����
    Matrix getTransform()const;

    // �ƶ�
    void translate(float x, float y);

    // ��ת
    void rotate(float angle);

    // ����
    void scale(float x, float y);

protected:
    // �麯�������ơ����б��Ǿ����任��
    virtual void drawShape(const std::vector<Point>& points);

private:
    Matrix m_matrix;    // ��״�ı任����

    std::vector<Point> m_points;    // ����ͼ����Ҫ�ĵ�
    COLORREF m_color;               // ������ɫ
    // ...����ͨ������
};

/*
m_matrix    2D �ľ����������ƶ������š���ת�ı任

m_points    ������״ԭʼ�ĵ㣬���Ƶ�ʱ��ȫ���任֮���ٻ���

tempPoints = m_matrix * m_points;
draw(tempPoints);


*/