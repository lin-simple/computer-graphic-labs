#include "Painting.h"
#include "Tinky.h"
#include "Dipsy.h"
#include "LaaLaa.h"
#include "Po.h"
#include "Action.h"
#include "Sun.h"


int main()
{
	initgraph(WINDOW_LENGTH, WINDOW_WIDTH, EW_SHOWCONSOLE);

	/**/
	
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
					<< "* B.Բ��/Բ������        *" << endl
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
				Painting paintingarc = Painting();      //Բ��

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
						int choice;
						cout << "��ѡ�����Բ��Բ����1--Բ��2--Բ����0--�˳�" << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:
						{
							// Բ�λ���
							while (1)
							{
								int x1, y1, x2, y2, weightType;
								string color;
								int lineType;
								char ch;
								cout << "��Y��N�˳���";
								cin >> ch;
								if (ch == 'Y' || ch == 'y')
									break;

								cout << "������Բ���(Բ��)����: ";
								cin >> x1 >> y1;
								cout << "������Բ�յ�����: ";
								cin >> x2 >> y2;
								cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
								cin >> lineType;
								cout << "�������߶ο��: ";
								cin >> weightType;
								cout << "�������߶���ɫ: ";
								cin >> color;

								// ��������
								paintingCircle.setCoord(x1, y1, x2, y2);
								paintingCircle.setWeightType(weightType);
								paintingCircle.setLineType(lineType);
								paintingCircle.setColor(translateColor(color));

								paintingCircle.MidPointCircle();
								_getch();

							}
							break;
						}
						//Բ�����ƣ�����ԭ�㡢�뾶����ʼ�Ƕȡ���ֹ�Ƕ�
						case 2:
						{
							int x, y, start_angle, end_angle;
							string color;
							double r;
							char choice1;
							int lineType, weightType;

							while (1)
							{
								cout << "����ԭ�㡢�뾶����ʼ�Ƕȡ���ֹ�Ƕȣ�" << endl;
								cin >> x;
								cin >> y;
								cin >> r;
								cin >> start_angle;
								cin >> end_angle;

								cout << "�������߶����� [0.ʵ�ߡ�1.�㻮�ߡ�2.���ߡ�3.�����߽���]: ";
								cin >> lineType;
								paintingMouse.setLineType(lineType);
								cout << "�������߶ο��: ";
								cin >> weightType;

								cout << "�������߶���ɫ: ";
								cin >> color;
								paintingarc.setLineType(lineType);
								paintingarc.setWeightType(weightType);
								paintingarc.setColor(translateColor(color));

								paintingarc.ArcPaint(x, y, r, start_angle, end_angle);

								cout << "�Ƿ��������--y����--n" << endl;
								cin >> choice1;
								if (choice1 == 'n')
									break;
							}
							break;
						}
						default:
							break;
						}
						if (choice == 0)
							break;
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
					//IMAGE img1;
					//getimage(&img1, 0, 0, WINDOW_LENGTH, WINDOW_WIDTH);

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
					Xvec.clear(); Yvec.clear();
					for (int i = 0; i < edges_num; i++) {
						cout << "����" << i + 1 << ": ";
						int x, y;
						cin >> x >> y;
						Xvec.push_back(x); Yvec.push_back(y);
						edges[k++] = x;  edges[k++] = y;
					}
					edges[k] = edges[0]; edges[k + 1] = edges[1];

					for (int i = 1; i < 2 * (edges_num + 1); i += 2) {
						if (edges[i] > max_y)
							max_y = edges[i];
					}

					Edge* newEdges = paintingPolygon2.InitEdges(edges, edges_num);
					ET etable,etable1;
					paintingPolygon2.Init(etable, newEdges, edges_num); //��ʼ����߱�
					paintingPolygon2.Init(etable1, newEdges, edges_num);
					cout << "�Ƿ������ɫ���[Y/N]: ";
					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						
						cout << "��������Ҫ�����ɫ: ";
						cin >> fillColor;
						
						paintingPolygon2.myDrawPolygon(edges, edges_num);
						paintingPolygon2.myScanFill(etable1, translateColor(fillColor), max_y);
						_getch();

						cout << "��ѡ���Ƿ���ã�" << endl;
						cout << " 1.����" << endl;
						cout << " 2.������" << endl;
						int h;
						cin >> h;
						if (h == 1) {
							int wx1, wx2, wy1, wy2;
							cout << "��������߽硢�±߽硢�ұ߽硢�ϱ߽磺" << endl;
							cin >> wx1 >> wy1 >> wx2 >> wy2;
							paintingPolygon2.setColor(BLACK);
							paintingPolygon2.myDrawPolygon(edges, edges_num);
							paintingPolygon2.myScanFill(etable,BLACK, max_y);
							//_getch();

							for (int i = 0; i < edges_num; i++) {
								edges[k++] = 0;  edges[k++] = 0;
							}
							edges[k] = edges[0]; edges[k + 1] = edges[1];

							
							paintingPolygon2.SutherlandHodgmanClip( wx1, wx2, wy1, wy2);
							int k = 0;
							for (int i = 0; i < Xvec.size(); i++) {
								edges[k++] = Xvec[i];  edges[k++] = Yvec[i];
							}
							edges[k] = edges[0]; edges[k + 1] = edges[1];
							max_y = -1;
							for (int i = 1; i < 2 * (Xvec.size() + 1); i += 2) {
								if (edges[i] > max_y)
									max_y = edges[i];
							}

							Edge* newEdges = paintingPolygon2.InitEdges(edges, Xvec.size());
							ET Etable;
							paintingPolygon2.Init(Etable, newEdges, Xvec.size()); //��ʼ����߱�
							paintingPolygon2.myDrawPolygon(edges, Xvec.size());
							//cleardevice();
							//putimage(WINDOW_LENGTH, WINDOW_WIDTH, &img1); 
							//Sleep(50);
						    paintingPolygon2.myScanFill(Etable, translateColor(fillColor), max_y);
							//paintingPolygon2.myScanFill(Etable, GREEN, max_y);
							_getch();
							break;
						}
						else if (h == 2)   break;
						break;
					}
					else {
						paintingPolygon2.myDrawPolygon(edges, edges_num);
						cout << "��ѡ���Ƿ���ã�" << endl;
						cout << " 1.����" << endl;
						cout << " 2.������" << endl;
						int h;
						cin >> h;
						if (h == 1) {
							int wx1, wx2, wy1, wy2;
							cout << "��������߽硢�±߽硢�ұ߽硢�ϱ߽磺" << endl;
							cin >> wx1 >> wy1 >> wx2 >> wy2;
							paintingPolygon2.setColor(BLACK);
							paintingPolygon2.myDrawPolygon(edges, edges_num);
							paintingPolygon2.myScanFill(etable, BLACK, max_y);
							//_getch();

							for (int i = 0; i < edges_num; i++) {
								edges[k++] = 0;  edges[k++] = 0;
							}
							edges[k] = edges[0]; edges[k + 1] = edges[1];


							paintingPolygon2.SutherlandHodgmanClip(wx1, wx2, wy1, wy2);
							int k = 0;
							for (int i = 0; i < Xvec.size(); i++) {
								edges[k++] = Xvec[i];  edges[k++] = Yvec[i];
							}
							edges[k] = edges[0]; edges[k + 1] = edges[1];
							max_y = -1;
							for (int i = 1; i < 2 * (Xvec.size() + 1); i += 2) {
								if (edges[i] > max_y)
									max_y = edges[i];
							}

							Edge* newEdges = paintingPolygon2.InitEdges(edges, Xvec.size());
							ET Etable;
							paintingPolygon2.Init(Etable, newEdges, Xvec.size()); //��ʼ����߱�
							paintingPolygon2.setColor(translateColor(lineColor));
							paintingPolygon2.myDrawPolygon(edges, Xvec.size());
							//cleardevice();
							//putimage(WINDOW_LENGTH, WINDOW_WIDTH, &img1); 
							//Sleep(50);
							//paintingPolygon2.myScanFill(Etable, translateColor(fillColor), max_y);
							//paintingPolygon2.myScanFill(Etable, GREEN, max_y);
							_getch();
							break;
						}
						else if (h == 2)   break;
						_getch();
					}

					
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


					//while (1) {
					//	MOUSEMSG m = GetMouseMsg();
					//	TCHAR control[10];
					//	switch (m.uMsg)
					//	{
					//	case WM_LBUTTONDOWN:
					//		_stprintf(control, _T("%d,%d"), m.x, m.y);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
					//		outtextxy(m.x, m.y, control);                //������λ��
					//	default:
					//		break;
					//	}
					//}
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
			Action action = Action();
			char choice;
			IMAGE background;//����һ��ͼƬ��.
			//loadimage(&background, L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\7.png");//��ͼƬ�ļ���ȡͼ��
			loadimage(&background, L"..\\7.png");//��ͼƬ�ļ���ȡͼ��

			setorigin(0, 0);
			putimage(0, 0, &background);//����ͼ����Ļ��ͼƬ���Ͻ�����Ϊ(0,0)
			action.Init();
			//Sleep(100);
			//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\bgm.mp3 alias bgm", NULL, 0, NULL);
			mciSendString(L"open ..\\bgm.mp3 alias bgm", NULL, 0, NULL);

			mciSendString(L"setaudio bgm volume to 50", 0, 0, 0);
			mciSendString(L"play bgm repeat", NULL, 0, NULL);
			while (1)
			{
				cout << "\n**************************" << endl
					   << "*    ����Ҫ���е���Ϊ    *" << endl
					   << "*                        *" << endl
					   << "* A.���к�               *" << endl
					   //<< "* B.����                 *" << endl
					   << "* B.̫����������         *" << endl
					   << "* Q.�˳�                 *" << endl
					   << "**************************" << endl;
				cin >> choice;
				switch (choice)
				{
				case 'A':
				case 'a':
				{
					mciSendString(L"stop bgm", NULL, 0, NULL);
					action.Hello();
					mciSendString(L"resume bgm", NULL, 0, NULL);
				break; 
				}
				/*case 'B':
				case 'b':
					break;*/
				case 'B':
				case 'b':
				{
					Sun s = Sun();
					s.drawSun();
				break; }
				case  'Q':
				case  'q':
					break;
				default:
					break;
				}
				if (choice == 'Q' || choice == 'q')
				{
					break;
				}
			}
			break;
		}
		default:
			break;
		}
		if (CHOICE == 0)
			break;
	}
	
	_getch();
	mciSendString(L"close bgm", NULL, 0, NULL);
	closegraph();

	return 0;
}