#pragma once
#include "Painting.h"
#include "BoundingBox.h"
#include "Matrix.h"
#include "Shape.h"

#define WINDOW_LENGTH 1500	// ���ڴ�С
#define WINDOW_WIDTH 700


//
// ȫ�ֱ���
//

// ��ǳ����Ƿ���������
bool running = true;

// ��굱ǰλ��
Point mouse;
Point lastpos;
int mousebutton = 0;   // ����Ƿ���

// ��Ļ����ʾ��ͼ��
std::vector<Shape*> shapes;

// ��ǰ���ѡ�����״
Shape* selectShape = NULL;

// �Զ�����תԭ��
Point org = Point(WINDOW_LENGTH / 2, WINDOW_WIDTH / 2);

//
// Utils
//��������ת���ĺ���
//
bool isInArray(int* array, int e, int array_length);		// �ж�һ�������Ƿ�������������
double graphx(double x, int rate, int relative_origin);		// �����ϵĵ�
double realx(double gx, int rate, int relative_origin);		// ��ʵ�����ϵĵ�
int graphy(int y, int rate);
int realy(int gy, int rate);
bool isInArray(int* array, int e, int array_length);	//�ж�һ�������Ƿ�������������
int translateColor(string colorString);		// "����"��ɫ
int translateLineType(string lineTypeString);    // "����" ����
int translateType(string typeString);		// "����ͼ��"


// ������������ز����� n �������
int random(int n);
// �����ɫ
COLORREF random_color();

void mouse_push(int x, int y, int button);  // ��갴����Ϣ
void mouse_pop(int x, int y, int button);   // ��굯����Ϣ
void mouse_move(int x, int y);              // ����ƶ���Ϣ
void key_event(int key);                    // ����������
void update(float delay);                   // ��Ϸ�߼�����
void drawCross(int x, int y, int size);     // ����ʮ��
void display();                             // ��ʾ����




//
//��������ת���ĺ���
//
double graphx(double x, int rate, int relative_origin) {
	return x * rate + relative_origin;
}

double realx(double gx, int rate, int relative_origin) {
	return (gx - relative_origin) * 1.0 / rate;
}

int graphy(int y, int rate) {
	return WINDOW_WIDTH - y * rate;
}

int realy(int gy, int rate) {
	return (WINDOW_WIDTH - gy) / rate;
}

//�ж�һ�������Ƿ�������������
bool isInArray(int* array, int e, int array_length)
{
	for (int i = 0; i < array_length; ++i)
	{
		if (array[i] == e)
		{
			return true;
		}
	}
	return false;
}

// "����"��ɫ
int translateColor(string colorString) {
	if (colorString == "red" || colorString == "RED" || colorString == "��ɫ")
		return RED;
	else if (colorString == "blue" || colorString == "BLUE" || colorString == "��ɫ")
		return BLUE;
	else if (colorString == "green" || colorString == "GREEN" || colorString == "��ɫ")
		return GREEN;
	else if (colorString == "yellow" || colorString == "YELLOW" || colorString == "��ɫ")
		return YELLOW;
	else
		return WHITE;
}

// "����" ����
int translateLineType(string lineTypeString) {
	// ���߳��߽��� ���� �㻮�� ʵ��
	if (lineTypeString == "�㻮��")
		return 1;
	else if (lineTypeString == "����")
		return 2;
	else if (lineTypeString == "�����߽���")
		return 3;
	else
		return 0;	// Ĭ��ʵ��
}

// "����ͼ��"
int translateType(string typeString) {
	if (typeString == "ֱ��")
		return 0;
	else if (typeString == "Բ")
		return 1;
	else if (typeString == "�����")
		return 2;
	else
		return 0;	// Ĭ��ʵ��
}

// ������������ز����� n �������
int random(int n)
{
	return rand() % n;
}

// �����ɫ
COLORREF random_color()
{
	//return RGB(random(256), random(256), random(256));
	return rand() % 0xFFFFFF;
}

// ��갴����Ϣ
// button   MK_LBUTTON    ���
//          MK_RBUTTON    �Ҽ�
void mouse_push(int x, int y, int button)
{
    lastpos = mouse;
    mousebutton = button;
    //printf("button = %d %d\n", button, mousebutton);

    // �������ʱ��ѡ��ǰ��״
    if (button == MK_LBUTTON) {
        selectShape = NULL;
        for (size_t i = 0; i < shapes.size(); ++i) {
            BoundingBox box= shapes[i]->getBoundingBox();
            if (box.contaits(x, y)) {
                selectShape = shapes[i];
                break;
            }
        }
    }
    else if (mousebutton == MK_RBUTTON) {
        // �Ҽ��ƶ��Զ���ԭ��λ��
        org = mouse;
    }

}

// ��굯����Ϣ
// button   MK_LBUTTON    ���
//          MK_RBUTTON    �Ҽ�
void mouse_pop(int x, int y, int button)
{
    mousebutton = 0;
}

// ����ƶ���Ϣ
void mouse_move(int x, int y)
{
    mouse.x = x;
    mouse.y = y;

    // ������������ڰ���
    if (mousebutton == MK_LBUTTON) {
        // �����ѡ�����״���ƶ���״
        if (selectShape) {
            // ���㵱ǰ���λ�ã����ϴ����λ�õĲ�ֵ
            int offsetX = mouse.x - lastpos.x;
            int offsetY = mouse.y - lastpos.y;

            selectShape->translate((float)offsetX, (float)offsetY);

            // ����������λ��
            lastpos = mouse;
        }
    }
    else if (mousebutton == MK_RBUTTON) {
        // �Ҽ��ƶ��Զ���ԭ��λ��
        org = mouse;
    }
}

// ����������
void key_event(int key)
{
    // ESC = 27
    // cout << "key_event - key: " << key << "\t" << char(key) << endl;

    if (key == 27) {// �˳�
        running = false;
        return;
    }

    if (!selectShape) {
        return;
    }

    // ��ȡ��״�����ĵ�
    // ����״������Ϊԭ����б任
    BoundingBox box = selectShape->getBoundingBox();
    Point center = box.getCenter();

    switch (key) {
    case 72://up        ���Ҽ���������
        selectShape->translate(-center.x, -center.y);   // ��ǰ�任ԭ���ƶ�����״������λ�ã�Ĭ������Ļ���Ͻ�
        selectShape->scale(1.1f, 1.1f);                 // ����
        selectShape->translate(center.x, center.y);     // ���ƻ�ȥ������Ĳ�������
        cout << "�Ŵ�" << endl;
        break;
    case 80://down
        selectShape->translate(-center.x, -center.y);
        selectShape->scale(0.9f, 0.9f);
        selectShape->translate(center.x, center.y);
        cout << "��С" << endl;
        break;

    case 75://left      ���¼�������ת 75
        selectShape->translate(-center.x, -center.y);
        selectShape->rotate(-2.0f);
        selectShape->translate(center.x, center.y);
        cout << "����" << endl;
        break;
    case 77://right
        selectShape->translate(-center.x, -center.y);
        selectShape->rotate(2.0f);
        selectShape->translate(center.x, center.y);
        cout << "����" << endl;
        break;

    case 'a':
        selectShape->translate(-org.x, -org.y);
        selectShape->rotate(-2.0f);
        selectShape->translate(org.x, org.y);
        break;
    case 'd':
        selectShape->translate(-org.x, -org.y);
        selectShape->rotate(2.0f);
        selectShape->translate(org.x, org.y);
        break;
    case 'w':
        selectShape->translate(-org.x, -org.y);   // ��ǰ�任ԭ���ƶ�����״������λ�ã�Ĭ������Ļ���Ͻ�
        selectShape->scale(1.1f, 1.1f);                 // ����
        selectShape->translate(org.x, org.y);     // ���ƻ�ȥ������Ĳ�������
        break;
    case 's':
        selectShape->translate(-org.x, -org.y);
        selectShape->scale(0.9f, 0.9f);
        selectShape->translate(org.x, org.y);
        break;
    }

}

// ��Ϸ�߼�����
void update(float delay)
{

}

//  ����ʮ��
void drawCross(int x, int y, int size)
{
    line(x - size, y, x + size, y);
    line(x, y - size, x, y + size);
}

// ��ʾ����
void display()
{
    // ����
    //cleardevice();
    setfillcolor(BLACK);
    fillrectangle(0, 0, WINDOW_LENGTH, WINDOW_WIDTH);

    // ����������״
    for (size_t i = 0; i < shapes.size(); ++i) {
        shapes[i]->draw();
    }

    // ����ѡ����״
    if (selectShape) {
        // ���ư�Χ��
        BoundingBox box = selectShape->getBoundingBox();
        box.draw();

        // ���ĵ�
        setcolor(RED);
        Point center = box.getCenter();
        drawCross((int)center.x, (int)center.y, 5);

    }

    // �Զ���ԭ��
    setcolor(RED);
    drawCross((int)org.x, (int)org.y, 10);


    // ��ʾ���λ��
    TCHAR buf[256];
    settextcolor(BLACK);
    _sntprintf(buf, _countof(buf), TEXT("mouse = %d, %d"), mouse.x, mouse.y);
    outtextxy(0, 0, buf);
}