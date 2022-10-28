#pragma once

#include <math.h>
#include <string.h>
#include "Point.h"

#ifndef M_RD
#define M_RD        0.01745329251994329576923690768489
#define M_INV_RD    57.295779513082320876798154814092
#endif

class Matrix
{
private:
    float m[3][2];      // 2x3 ����

public:
    Matrix()
    {

    }

    Matrix(
        float m00, float m01,
        float m10, float m11,
        float m20, float m21)
    {
        m[0][0] = m00; m[0][1] = m01;
        m[1][0] = m10; m[1][1] = m11;
        m[2][0] = m20; m[2][1] = m21;
    }

    // ��ʼ����λ����
    Matrix& identity()
    {
        return this->operator=(makeIdentity());
    }

    // �ƶ�����
    Matrix& translate(float x, float y)
    {
        Matrix mat = makeTranslate(x, y);
        multiply(m, mat.m, m);
        return *this;
    }

    // ��ת����
    Matrix& rotate(double angle)
    {
        Matrix mat = makeRotate(angle);
        multiply(m, mat.m, m);
        return *this;
    }

    // ���ž���
    Matrix& scale(float x, float y)
    {
        Matrix mat = makeScale(x, y);
        multiply(m, mat.m, m);
        return *this;
    }

    // ����ȡֵ
    float* operator[](int i)
    {
        return m[i];
    }

    const float* operator[](int i)const
    {
        return m[i];
    }

    // �˷�
    Matrix operator*(const Matrix& other)
    {
        Matrix temp;
        multiply(m, other.m, temp.m);
        return temp;
    }

    // �˵���
    Matrix& operator*=(const Matrix& other)
    {
        multiply(m, other.m, m);
        return *this;
    }

    //
    // ��̬����
    //

    // ���ɵ�λ����
    static Matrix makeIdentity()
    {
        return Matrix(
            1.0f, 0.0f,
            0.0f, 1.0f,
            0.0f, 0.0f
        );
    }

    // �����ƶ�����
    static Matrix makeTranslate(float x, float y)
    {
        return Matrix(
            1.0f, 0.0f,
            0.0f, 1.0f,
            x, y
        );
    }

    // ������ת����
    static Matrix makeRotate(double angle)
    {
        angle *= M_RD;
        float cosine = (float)cos(angle);
        float sine = (float)sin(angle);

        return Matrix(
            cosine, sine,
            -sine, cosine,
            0.0f, 0.0f
        );
    }

    // �������ž���
    static Matrix makeScale(float x, float y)
    {
        return Matrix(
            x, 0.0f,
            0.0f, y,
            0.0f, 0.0f
        );
    }

    // ����˷�
    static void multiply(const float m1[3][2], const float m2[3][2], float out[3][2])
    {
        float product[3][2] = { 0.0f };

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                product[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j];
            }
        }

        product[2][0] += m2[2][0];
        product[2][1] += m2[2][1];

        memcpy(out, product, sizeof(product));
    }
};

// ����͵����
inline Point operator*(const Matrix& m, const Point& p)
{
    float x = p.x * m[0][0] + p.y * m[1][0] + m[2][0];
    float y = p.x * m[0][1] + p.y * m[1][1] + m[2][1];
    return Point(x, y);
}


