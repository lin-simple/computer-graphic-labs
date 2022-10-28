#include "Shape.h"



Shape::Shape()
{
    m_matrix.identity();
    m_color = RGB(0, 0, 0);
}


Shape::~Shape()
{
}

// ���һ����
void Shape::add(const Point& p)
{
    m_points.push_back(p);
}

// ������е�
void Shape::clear()
{
    m_points.clear();
}

// ������״��ɫ
void Shape::setColor(COLORREF color)
{
    m_color = color;
}

// ��ȡ��״��ɫ
COLORREF Shape::getColor()const
{
    return m_color;
}

// ���ñ任����
void Shape::setTransform(const Matrix& mat)
{
    m_matrix = mat;
}

// ��ȡ��ǰ��ת����
Matrix Shape::getTransform()const
{
    return m_matrix;
}

// �ƶ�
void Shape::translate(float x, float y)
{
    m_matrix.translate(x, y);
}

// ��ת
void Shape::rotate(float angle)
{
    m_matrix.rotate(angle);
}

// ����
void Shape::scale(float x, float y)
{
    m_matrix.scale(x, y);
}

// ��ȡ��״�İ�Χ����
BoundingBox Shape::getBoundingBox()const
{
    BoundingBox box;
    for (size_t i = 0; i < m_points.size(); ++i) {
        // �ѱ任��ĵ㣬��ӵ���Χ�����洦��
        Point p = m_matrix * m_points[i];
        box.setPoint(p);
    }
    return box;
}

// ����
void Shape::draw()
{
    // �任���еĵ㵽��ʱ������
    std::vector<Point> temp;
    for (size_t i = 0; i < m_points.size(); ++i) {
        temp.push_back(m_matrix * m_points[i]);
    }

    // �����麯�����Ʊ任��ĵ�
    this->drawShape(temp);
}

// �麯�������ơ����б��Ǿ����任��
// Ĭ�ϵĻ��ƺ��������Ƴ����еĵ�
void Shape::drawShape(const std::vector<Point>& points)
{
    setfillcolor(m_color);
    for (size_t i = 0; i < points.size(); ++i) {
        fillcircle((int)points[i].x, (int)points[i].y, 2);
    }
}

