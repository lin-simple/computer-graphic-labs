#include "Painting.h"
#include "Tinky.h"
#include "Dipsy.h"
#include "LaaLaa.h"
#include "Po.h"
#include "BezierCurve.h"

int main(int argc, char** argv)
{
	initgraph(WINDOW_LENGTH, WINDOW_WIDTH, EW_SHOWCONSOLE);
	
	while (1) {
		cout << "\n**************************" << endl
			<< "*    -----������-----    *" << endl
			<< "*                        *" << endl
			<< "* 1.ʵ����Ŀ             *" << endl
			<< "* 2.��ĩ��Ŀ             *" << endl
			<< "* 0.�˳�                 *" << endl
			<< "**************************" << endl;

		int CHOICE;
		cin >> CHOICE;
		switch (CHOICE)
		{
		case 1: {
			rectangle(500, 5, 615, 25);
			outtextxy(510, 7, L"�˳�����ͼ");
			while (1) {
				cout << "\n**************************" << endl
					<< "*   -----ʵ����Ŀ-----   *" << endl
					<< "*                        *" << endl
					<< "* A.ֱ�߶λ���           *" << endl
					<< "* B.Բ�λ���             *" << endl
					<< "* C.����λ���           *" << endl
					<< "* D.��ս���             *" << endl
					<< "* E.ͼ�α任             *" << endl
					<< "* F.n�� Bezier ���߻���  *" << endl
					<< "* M.����ͼ             *" << endl
					<< "* T.����                 *" << endl
					<< "* Q.������һ��           *" << endl
					<< "**************************" << endl;

				Painting paintingLine = Painting();		// ֱ��
				Painting paintingCircle = Painting();		// Բ
				Painting paintingMouse = Painting();		// ����ͼ
				Painting paintingPolygon = Painting();		// �����
				Painting paintingPolygon2 = Painting();
				Painting paintingBezierCurve = Painting();	// Bezier ����

				char choice;
				cout << "��ѡ����Ҫ���еĲ���[A-Q]: ";
				cin >> choice;

				switch (choice)
				{
				case 'A':
				case 'a': {	// ֱ�߶λ���
					while (1) {
						int x1, y1, x2, y2;
						string color;
						int lineType, weightType;

						char ch;
						cout << "�Ƿ��˳���(Y��N��";
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
							break;
						else if (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') continue;
						else {
							cout << "������ֱ�߶��������: ";
							cin >> x1 >> y1;
							cout << "������ֱ�߶��յ�����: ";
							cin >> x2 >> y2;
							cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
							cin >> lineType;
							cout << "�������߶ο��: ";
							cin >> weightType;
							cout << "�������߶���ɫ: ";
							cin >> color;
						}

						cout << "\n  1.�е��㷨����ֱ��" << endl
							<< "  2.Bresenhma�㷨�滭ֱ��" << endl;

						cin >> ch;

						// ��������
						paintingLine.setCoord(x1, y1, x2, y2);
						paintingLine.setWeightType(weightType);
						paintingLine.setLineType(lineType);
						paintingLine.setColor(translateColor(color));
						int h;
						int LINETYPE = paintingLine.getLineType();
						switch (ch)
						{
						case '1': {
							paintingLine.MidPointline();
							_getch();
							cout << "��ѡ���ܣ�" << endl;
							cout << " 1.Cohen-Sutherland�㷨����ֱ��" << endl
								<< " 2.�е�ָ�����㷨����ֱ��" << endl;
							cout << " 3.������" << endl;
							cin >> h;
							if (h == 1) {
								paintingLine.Cohen_Sutherland(x1, y1, x2, y2, LINETYPE);
								_getch();
								break;
							}
							else if (h == 2) {
								paintingLine.MidLineClip(x1, y1, x2, y2, LINETYPE);
								_getch();
								break;
							}
							else if (h == 3)  break;
							break;
						}
						case '2': {
							paintingLine.Bresenhamline();
							_getch();
							cout << "��ѡ���ܣ�" << endl;
							cout << " 1.Cohen-Sutherland�㷨����ֱ��" << endl
								<< " 2.�е�ָ�����㷨����ֱ��" << endl;
							cout << " 3.������" << endl;
							cin >> h;
							if (h == 1) {
								paintingLine.Cohen_Sutherland(x1, y1, x2, y2, LINETYPE);
								_getch();
								break;
							}

							else if (h == 2) {
								paintingLine.MidLineClip(x1, y1, x2, y2, LINETYPE);
								_getch();
								break;
							}
							else if (h == 3)break;
							break;
						}
						default:
							break;

						}

					}break;
				}

				case 'B':
				case 'b': {	// Բ�λ���
					while (1)
					{
						int x1, y1, r, weightType;
						string color;
						int lineType;
						char ch;
						cout << "��Y��N�˳���";
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
							break;

						cout << "������Բ���(Բ��)����: ";
						cin >> x1 >> y1;
						cout << "������Բ�뾶: ";
						cin >> r;
						cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
						cin >> lineType;
						cout << "�������߶ο��: ";
						cin >> weightType;
						cout << "�������߶���ɫ: ";
						cin >> color;

						// ��������
						paintingCircle.setWeightType(weightType);
						paintingCircle.setLineType(lineType);
						paintingCircle.setColor(translateColor(color));

						paintingCircle.MidPointCircle(x1, y1, r);
						_getch();

					}
					break;
				}

				case 'C':
				case 'c': {		// ����λ���
					int edges[NUMPOINT];  // = { 50,100,70,150,100,100,100,50,50,50,50,100 };
					int edges_num; // = 5;
					int k = 0;
					int max_y = -1;
					char choice;
					string fillColor, lineColor;
					int lineType, weightType;


					cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
					cin >> lineType;
					cout << "�������߶ο��: ";
					cin >> weightType;
					cout << "�������߶���ɫ: ";
					cin >> lineColor;

					// ��������
					paintingPolygon2.setWeightType(weightType);
					paintingPolygon2.setLineType(lineType);
					paintingPolygon2.setColor(translateColor(lineColor));

					cout << "��������������ζ�����: ";
					cin >> edges_num;

					cout << "����������ÿ����������(˳/��ʱ��)" << endl;
					for (int i = 0; i < edges_num; i++) {
						cout << "����" << i + 1 << ": ";
						int x, y;
						cin >> x >> y;
						edges[k++] = x;  edges[k++] = y;
					}
					edges[k] = edges[0]; edges[k + 1] = edges[1];

					for (int i = 1; i < 2 * (edges_num + 1); i += 2) {
						if (edges[i] > max_y)
							max_y = edges[i];
					}

					Edge* newEdges = paintingPolygon2.InitEdges(edges, edges_num);
					ET etable;
					paintingPolygon2.Init(etable, newEdges, edges_num); //��ʼ����߱�

					cout << "�Ƿ������ɫ���[Y/N]: ";
					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						cout << "��������Ҫ�����ɫ: ";
						cin >> fillColor;
						paintingPolygon2.myDrawPolygon(edges, edges_num);
						paintingPolygon2.myScanFill(etable, translateColor(fillColor), max_y);
					}
					else {
						paintingPolygon2.myDrawPolygon(edges, edges_num);
					}

					_getch();

					break;
				}

				case 'D':
				case 'd': {		// ��ս���
					setfillcolor(BLACK);
					solidrectangle(0, 0, WINDOW_LENGTH, WINDOW_WIDTH);
					rectangle(500, 5, 615, 25);
					outtextxy(510, 7, L"�˳�����ͼ");
					break;
				}

				case 'E':
				case 'e': {		// ͼ�α任
					// �����Ϣ
					MOUSEMSG msg;

					// ��������
					settextstyle(20, 0, TEXT("΢���ź�"));
					//settextcolor(WHITE);

					// ���屳��͸��
					setbkmode(TRANSPARENT);

					// �������������
					srand(GetTickCount());

					// ��ʼ��һЩֱ��
					for (int i = 0; i < 5; ++i) {
						LineShape* line = new LineShape();
						//line->setColor(random_color());
						//line->setColor(RGB(255, 0, 0));
						line->setColor(BLUE);
						line->setLine(random(WINDOW_LENGTH), random(WINDOW_WIDTH), random(WINDOW_LENGTH), random(WINDOW_WIDTH));

						shapes.push_back(line);
					}

					// ֡ʱ��
					int t = clock();
					while (running) {
						if (MouseHit()) {
							// ����������Ϣ������������
							msg = GetMouseMsg();
							switch (msg.uMsg) {
							case WM_LBUTTONDOWN:
								mouse_push(msg.x, msg.y, MK_LBUTTON);
								break;
							case WM_RBUTTONDOWN:
								mouse_push(msg.x, msg.y, MK_RBUTTON);
								break;
							case WM_LBUTTONUP:
								mouse_pop(msg.x, msg.y, MK_LBUTTON);
								break;
							case WM_RBUTTONUP:
								mouse_pop(msg.x, msg.y, MK_RBUTTON);
								break;
							case WM_MOUSEMOVE:
								mouse_move(msg.x, msg.y);
								break;
							}
						}
						else if (_kbhit()) {
							// ����м�����Ϣ������������
							key_event(_getch());
						}
						else {
							// ������Ϸ
							update(float(clock() - t) / 1000.0f);
							t = clock();

							// ������ͼ����ֹ��˸
							BeginBatchDraw();
							// ��ʾ����
							display();
							// ����������ͼ
							EndBatchDraw();

							// ��ʱ
							Sleep(20);
						}
					}

					break;
				}

				case 'F':
				case 'f': {		// n�� Bezier ���߻���
					//int lineType;
					int weightType;
					string color;
					Point point[NUMPOINT];
					int n, x, y;
					//cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
					//cin >> lineType;
					cout << "�������߶ο��: ";
					cin >> weightType;
					cout << "�������߶���ɫ: ";
					cin >> color;

					// ��������
					//paintingBezierCurve.setLineType(lineType);
					paintingBezierCurve.setWeightType(weightType);
					paintingBezierCurve.setColor(translateColor(color));

					cout << "��������Ƶ�����������߽���n: ";
					cin >> n;
					cout << "����������Ƶ�����\n" << endl;
					for (int i = 0; i < n; ++i)
					{
						cout << "���Ƶ�" << i + 1 << ": ";
						cin >> x >> y;
						point[i].setPoint(x, y);
					}

					paintingBezierCurve.drawBezierCurve(point, n);
					_getch();
					break;
				}

				case 'M':
				case 'm': {		// ����ͼ
					int weightType;
					string color;
					int lineType;
					int type;
					cout << "������滭ͼ������ [0.ֱ�ߡ�1.Բ��2.����Ρ�3.���߻���]: ";
					cin >> type;
					if (type == 3) {
						closegraph();
						drawCurve(argc, argv);
					}
					if (type != 2) {
						if (type != 3)
						{
							cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
							cin >> lineType;
							paintingMouse.setLineType(lineType);
						}
						cout << "�������߶ο��: ";
						cin >> weightType;
						cout << "�������߶���ɫ: ";
						cin >> color;
						// ��������
						paintingMouse.setWeightType(weightType);
						paintingMouse.setColor(translateColor(color));

						paintingMouse.MouseClick(paintingMouse, type);
					}
					else {
						cout << "��������ɫ: ";
						cin >> color;

						paintingMouse.setLineType(translateLineType("ʵ��"));
						paintingMouse.setWeightType(1);
						paintingMouse.setColor(translateColor(color));

						paintingMouse.MouseClick(paintingMouse, type);
					}

					_getch();
					cout << "\n���˳�����ͼ" << endl;
					break;
				}

				case 'T':
				case 't': {		// ����
					cout << "�˴�Ϊ���Բ���..." << endl;

					//setcolor(BLUE);
					////float S[6] = { 0 };
					//MyLine l1(80, 80, 280, 160);
					//MyLine l2(280, 160, 520, 0);
					//MyLine l3(520, 0, 520, 220);
					//MyLine l4(520, 220, 280, 400);
					//MyLine l5(280, 400, 80, 320);
					//MyLine l6(80, 320, 80, 80);
					//ScanLines(0, l1, l2, l3, l4, l5, l6);
					//PointFill(280, 200, RED);

					//_getch();
					//closegraph();

					//drawCurve(argc, argv);

					break;
				}

				case 'Q':
				case 'q':	// �˳�
				default:
					break;

				}	// ��һ�� Switch ����

				if (choice == 'Q' || choice == 'q')
					break;
			}

			break;
		}
		case 2: {
			setbkcolor(WHITE);
			cleardevice();

			Tinky tinky = Tinky();
			Dipsy dipsy = Dipsy();
			LaaLaa laalaa = LaaLaa();
			Po po = Po();

			rectangle(400, 5, 700, 25);
			outtextxy(420, 7, L"��ͯ�ꡪ�����߱��������ά����");
			

			break;
		}
		default:
			break;
		}

		if (CHOICE == 0)
			break;
	}
	
	
	_getch();
	closegraph();

	return 0;
}