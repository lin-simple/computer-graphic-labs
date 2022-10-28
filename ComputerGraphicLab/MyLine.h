#pragma once

// É¨ÃèÏßÌî³äËã·¨

#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>


class MyLine 
{
public:
	MyLine(int x1, int y1, int x2, int y2) :Start_x(x1), Start_y(y1), End_x(x2), End_y(y2)
	{
		k = float(End_y - Start_y) / float(End_x - Start_x);
		moveto(x1, y1);
		lineto(x2, y2);
	}
	float getX(int y)
	{
		if (Start_y < End_y && (y<Start_y || y>End_y))
			return 0;
		else if (Start_y > End_y && (y > Start_y || y < End_y))
			return 0;
		float x = Start_x + float(y - Start_y) / k;
		return x;
	}
private:
	int Start_x;
	int Start_y;
	int End_x;
	int End_y;
	float k;
};

void PointFill(int x, int y, int newcolor)
{
	putpixel(x, y, newcolor);
}

void Sort(float S[], int y)
{
	int i, j, num = 0;
	for (i = 0; i < 6; i++)
	{
		if (S[i] != 0)
			num++;
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (S[j] < S[j + 1])
			{
				float temp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = temp;
			}
		}
	}
	if (num == 2)
	{
		int Ex = int(S[0]);
		int Sx = int(S[1]);
		for (int x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
	}
	else if (num == 3)
	{
		int Ex = int(S[0]);
		int Sx = int(S[2]);
		for (int x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
	}
	else if (num == 4)
	{
		int Ex, Sx, x;
		Ex = int(S[0]);
		Sx = int(S[1]);
		for (x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
		Ex = int(S[2]);
		Sx = int(S[3]);
		for (x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
	}
	else if (num == 6)
	{
		int Ex, Sx, x;
		Ex = int(S[0]);
		Sx = int(S[1]);
		for (x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
		Ex = int(S[2]);
		Sx = int(S[3]);
		for (x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
		Ex = int(S[4]);
		Sx = int(S[5]);
		for (x = Sx; x <= Ex; x++)
			PointFill(x, y, RED);
	}
}


void ScanLines(int y, MyLine l1, MyLine l2, MyLine l3, MyLine l4, MyLine l5, MyLine l6)
{
	float S[6] = { 0 };
	if (y < 400)
	{
		S[0] = l1.getX(y);
		S[1] = l2.getX(y);
		S[2] = l3.getX(y);
		S[3] = l4.getX(y);
		S[4] = l5.getX(y);
		S[5] = l6.getX(y);
		Sort(S, y);
		Sleep(10);
		ScanLines(y + 1, l1, l2, l3, l4, l5, l6);
	}
}

