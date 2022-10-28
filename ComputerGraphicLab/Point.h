#pragma once

class Point
{
public:
	Point() : x(), y()
	{
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Point(float x, float y)
	{
		this->x = (int)x;
		this->y = (int)y;
	}

	Point& operator= (const Point& p)
	{
		if (this != &p)
		{
			this->x = p.x;
			this->y = p.y;
		}
		return *this;
	}
	~Point() {};

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setPoint(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }

	// µãµÄ¼Ó¼õ³Ë³ý
	Point operator+(const Point& p)
	{
		return Point(x + p.x, y + p.y);
	}

	Point operator-(const Point& p)
	{
		return Point(x - p.x, y - p.y);
	}

	Point operator*(const Point& p)
	{
		return Point(x * p.x, y * p.y);
	}

//private:
	int x;
	int y;
};
