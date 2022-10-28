#include "Shape.h"



Shape::Shape()
{
    m_matrix.identity();
    m_color = RGB(0, 0, 0);
}


Shape::~Shape()
{
}

// 添加一个点
void Shape::add(const Point& p)
{
    m_points.push_back(p);
}

// 清空所有点
void Shape::clear()
{
    m_points.clear();
}

// 设置形状颜色
void Shape::setColor(COLORREF color)
{
    m_color = color;
}

// 获取形状颜色
COLORREF Shape::getColor()const
{
    return m_color;
}

// 设置变换矩阵
void Shape::setTransform(const Matrix& mat)
{
    m_matrix = mat;
}

// 获取当前旋转矩阵
Matrix Shape::getTransform()const
{
    return m_matrix;
}

// 移动
void Shape::translate(float x, float y)
{
    m_matrix.translate(x, y);
}

// 旋转
void Shape::rotate(float angle)
{
    m_matrix.rotate(angle);
}

// 缩放
void Shape::scale(float x, float y)
{
    m_matrix.scale(x, y);
}

// 获取形状的包围矩形
BoundingBox Shape::getBoundingBox()const
{
    BoundingBox box;
    for (size_t i = 0; i < m_points.size(); ++i) {
        // 把变换后的点，添加到包围盒里面处理
        Point p = m_matrix * m_points[i];
        box.setPoint(p);
    }
    return box;
}

// 绘制
void Shape::draw()
{
    // 变换所有的点到临时缓冲区
    std::vector<Point> temp;
    for (size_t i = 0; i < m_points.size(); ++i) {
        temp.push_back(m_matrix * m_points[i]);
    }

    // 调用虚函数绘制变换后的点
    this->drawShape(temp);
}

// 虚函数，绘制。点列表是经过变换的
// 默认的绘制函数，绘制出所有的点
void Shape::drawShape(const std::vector<Point>& points)
{
    setfillcolor(m_color);
    for (size_t i = 0; i < points.size(); ++i) {
        fillcircle((int)points[i].x, (int)points[i].y, 2);
    }
}

