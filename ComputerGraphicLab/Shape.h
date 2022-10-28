#pragma once

#include "Matrix.h"
#include "BoundingBox.h"
#include <vector>           // 使用 vector 动态数组

class Shape
{
public:
    Shape();
    ~Shape();

    // 添加一个点
    void add(const Point& p);

    // 清空所有点
    void clear();

    // 设置形状颜色
    void setColor(COLORREF color);

    // 获取形状颜色
    COLORREF getColor()const;

    // 获取形状的包围矩形
    BoundingBox getBoundingBox()const;

    // 绘制
    void draw();

    //
    // 封装的矩阵变换
    //

    // 设置变换矩阵
    void setTransform(const Matrix& mat);

    // 获取当前旋转矩阵
    Matrix getTransform()const;

    // 移动
    void translate(float x, float y);

    // 旋转
    void rotate(float angle);

    // 缩放
    void scale(float x, float y);

protected:
    // 虚函数，绘制。点列表是经过变换的
    virtual void drawShape(const std::vector<Point>& points);

private:
    Matrix m_matrix;    // 形状的变换矩阵

    std::vector<Point> m_points;    // 绘制图形需要的点
    COLORREF m_color;               // 绘制颜色
    // ...其他通用属性
};

/*
m_matrix    2D 的矩阵，用来做移动、缩放、旋转的变换

m_points    保存形状原始的点，绘制的时候，全部变换之后再绘制

tempPoints = m_matrix * m_points;
draw(tempPoints);


*/