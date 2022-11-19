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
			<< "*    -----主界面-----    *" << endl
			<< "*                        *" << endl
			<< "* 1.实验项目             *" << endl
			<< "* 2.期末项目             *" << endl
			<< "* 0.退出                 *" << endl
			<< "**************************" << endl;

		int CHOICE;
		cin >> CHOICE;
		switch (CHOICE)
		{
		case 1: {
			rectangle(500, 5, 615, 25);
			outtextxy(510, 7, L"退出鼠标绘图");
			while (1) {
				
				cout << "\n**************************" << endl
					<< "*   -----实验项目-----   *" << endl
					<< "*                        *" << endl
					<< "* A.直线段绘制           *" << endl
					<< "* B.圆形/圆弧绘制        *" << endl
					<< "* C.多边形绘制           *" << endl
					<< "* D.清空界面             *" << endl
					<< "* E.图形变换             *" << endl
					<< "* F.n阶 Bezier 曲线绘制  *" << endl
					<< "* M.鼠标绘图             *" << endl
					<< "* T.测试                 *" << endl
					<< "* Q.返回上一级           *" << endl
					<< "**************************" << endl;

				Painting paintingLine = Painting();		// 直线
				Painting paintingCircle = Painting();		// 圆
				Painting paintingMouse = Painting();		// 鼠标绘图
				Painting paintingPolygon = Painting();		// 多边形
				Painting paintingPolygon2 = Painting();
				Painting paintingBezierCurve = Painting();	// Bezier 曲线
				Painting paintingarc = Painting();      //圆弧

				char choice;
				cout << "请选择所要进行的操作[A-Q]: ";
				cin >> choice;

				switch (choice)
				{
				case 'A':
				case 'a': {	// 直线段绘制
					while (1) {
						int x1, y1, x2, y2;
						string color;
						int lineType, weightType;

						char ch;
						cout << "是否退出？(Y是N否）";
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
							break;
						else if (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') continue;
						else {
							cout << "请输入直线段起点坐标: ";
							cin >> x1 >> y1;
							cout << "请输入直线段终点坐标: ";
							cin >> x2 >> y2;
							cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
							cin >> lineType;
							cout << "请输入线段宽度: ";
							cin >> weightType;
							cout << "请输入线段颜色: ";
							cin >> color;
						}

						cout << "\n  1.中点算法绘制直线" << endl
							<< "  2.Bresenhma算法绘画直线" << endl;

						cin >> ch;

						// 设置属性
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
							cout << "请选择功能：" << endl;
							cout << " 1.Cohen-Sutherland算法剪裁直线" << endl
								<< " 2.中点分割剪裁算法剪裁直线" << endl;
							cout << " 3.不剪裁" << endl;
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
							cout << "请选择功能：" << endl;
							cout << " 1.Cohen-Sutherland算法剪裁直线" << endl
								<< " 2.中点分割剪裁算法剪裁直线" << endl;
							cout << " 3.不剪裁" << endl;
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
				case 'b': {	// 圆形绘制
					while (1)
					{
						int choice;
						cout << "请选择绘制圆或圆弧：1--圆，2--圆弧，0--退出" << endl;
						cin >> choice;
						switch (choice)
						{
						case 1:
						{
							// 圆形绘制
							while (1)
							{
								int x1, y1, x2, y2, weightType;
								string color;
								int lineType;
								char ch;
								cout << "是Y否N退出？";
								cin >> ch;
								if (ch == 'Y' || ch == 'y')
									break;

								cout << "请输入圆起点(圆心)坐标: ";
								cin >> x1 >> y1;
								cout << "请输入圆终点坐标: ";
								cin >> x2 >> y2;
								cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
								cin >> lineType;
								cout << "请输入线段宽度: ";
								cin >> weightType;
								cout << "请输入线段颜色: ";
								cin >> color;

								// 设置属性
								paintingCircle.setCoord(x1, y1, x2, y2);
								paintingCircle.setWeightType(weightType);
								paintingCircle.setLineType(lineType);
								paintingCircle.setColor(translateColor(color));

								paintingCircle.MidPointCircle();
								_getch();

							}
							break;
						}
						//圆弧绘制，输入原点、半径、起始角度、终止角度
						case 2:
						{
							int x, y, start_angle, end_angle;
							string color;
							double r;
							char choice1;
							int lineType, weightType;

							while (1)
							{
								cout << "输入原点、半径、起始角度、终止角度：" << endl;
								cin >> x;
								cin >> y;
								cin >> r;
								cin >> start_angle;
								cin >> end_angle;

								cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
								cin >> lineType;
								paintingMouse.setLineType(lineType);
								cout << "请输入线段宽度: ";
								cin >> weightType;

								cout << "请输入线段颜色: ";
								cin >> color;
								paintingarc.setLineType(lineType);
								paintingarc.setWeightType(weightType);
								paintingarc.setColor(translateColor(color));

								paintingarc.ArcPaint(x, y, r, start_angle, end_angle);

								cout << "是否继续？是--y，否--n" << endl;
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
				case 'c': {		// 多边形绘制
					int edges[NUMPOINT];  // = { 50,100,70,150,100,100,100,50,50,50,50,100 };
					int edges_num; // = 5;
					int k = 0;
					int max_y = -1;
					char choice;
					string fillColor, lineColor;
					int lineType, weightType;
					//IMAGE img1;
					//getimage(&img1, 0, 0, WINDOW_LENGTH, WINDOW_WIDTH);

					cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
					cin >> lineType;
					cout << "请输入线段宽度: ";
					cin >> weightType;
					cout << "请输入线段颜色: ";
					cin >> lineColor;

					// 设置属性
					paintingPolygon2.setWeightType(weightType);
					paintingPolygon2.setLineType(lineType);
					paintingPolygon2.setColor(translateColor(lineColor));

					cout << "请输入所画多边形顶点数: ";
					cin >> edges_num;

					cout << "请依次输入每个顶点坐标(顺/逆时针)" << endl;
					Xvec.clear(); Yvec.clear();
					for (int i = 0; i < edges_num; i++) {
						cout << "顶点" << i + 1 << ": ";
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
					paintingPolygon2.Init(etable, newEdges, edges_num); //初始化活动边表
					paintingPolygon2.Init(etable1, newEdges, edges_num);
					cout << "是否进行颜色填充[Y/N]: ";
					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						
						cout << "请输入所要填充颜色: ";
						cin >> fillColor;
						
						paintingPolygon2.myDrawPolygon(edges, edges_num);
						paintingPolygon2.myScanFill(etable1, translateColor(fillColor), max_y);
						_getch();

						cout << "请选择是否剪裁：" << endl;
						cout << " 1.剪裁" << endl;
						cout << " 2.不剪裁" << endl;
						int h;
						cin >> h;
						if (h == 1) {
							int wx1, wx2, wy1, wy2;
							cout << "请输入左边界、下边界、右边界、上边界：" << endl;
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
							paintingPolygon2.Init(Etable, newEdges, Xvec.size()); //初始化活动边表
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
						cout << "请选择是否剪裁：" << endl;
						cout << " 1.剪裁" << endl;
						cout << " 2.不剪裁" << endl;
						int h;
						cin >> h;
						if (h == 1) {
							int wx1, wx2, wy1, wy2;
							cout << "请输入左边界、下边界、右边界、上边界：" << endl;
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
							paintingPolygon2.Init(Etable, newEdges, Xvec.size()); //初始化活动边表
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
				case 'd': {		// 清空界面
					setfillcolor(BLACK);
					solidrectangle(0, 0, WINDOW_LENGTH, WINDOW_WIDTH);
					rectangle(500, 5, 615, 25);
					outtextxy(510, 7, L"退出鼠标绘图");
					break;
				}

				case 'E':
				case 'e': {		// 图形变换
					// 鼠标消息
					MOUSEMSG msg;

					// 设置字体
					settextstyle(20, 0, TEXT("微软雅黑"));
					//settextcolor(WHITE);

					// 字体背景透明
					setbkmode(TRANSPARENT);

					// 重置随机数种子
					srand(GetTickCount());

					// 初始化一些直线
					for (int i = 0; i < 5; ++i) {
						LineShape* line = new LineShape();
						//line->setColor(random_color());
						//line->setColor(RGB(255, 0, 0));
						line->setColor(BLUE);
						line->setLine(random(WINDOW_LENGTH), random(WINDOW_WIDTH), random(WINDOW_LENGTH), random(WINDOW_WIDTH));

						shapes.push_back(line);
					}

					// 帧时间
					int t = clock();
					while (running) {
						if (MouseHit()) {
							// 如果有鼠标消息，处理鼠标操作
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
							// 如果有键盘消息，处理按键操作
							key_event(_getch());
						}
						else {
							// 更新游戏
							update(float(clock() - t) / 1000.0f);
							t = clock();

							// 批量绘图，防止闪烁
							BeginBatchDraw();
							// 显示画面
							display();
							// 结束批量绘图
							EndBatchDraw();

							// 延时
							Sleep(20);
						}
					}

					break;
				}

				case 'F':
				case 'f': {		// n阶 Bezier 曲线绘制
					//int lineType;
					int weightType;
					string color;
					Point point[NUMPOINT];
					int n, x, y;
					//cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
					//cin >> lineType;
					cout << "请输入线段宽度: ";
					cin >> weightType;
					cout << "请输入线段颜色: ";
					cin >> color;

					// 设置属性
					//paintingBezierCurve.setLineType(lineType);
					paintingBezierCurve.setWeightType(weightType);
					paintingBezierCurve.setColor(translateColor(color));

					cout << "请输入控制点个数，即曲线阶数n: ";
					cin >> n;
					cout << "请输入各控制点坐标\n" << endl;
					for (int i = 0; i < n; ++i)
					{
						cout << "控制点" << i + 1 << ": ";
						cin >> x >> y;
						point[i].setPoint(x, y);
					}

					paintingBezierCurve.drawBezierCurve(point, n);
					_getch();
					break;
				}

				case 'M':
				case 'm': {		// 鼠标绘图
					int weightType;
					string color;
					int lineType;
					int type;
					cout << "请输入绘画图形类型 [0.直线、1.圆、2.多边形、3.曲线绘制]: ";
					cin >> type;
					if (type != 2) {
						if (type != 3)
						{
							cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
							cin >> lineType;
							paintingMouse.setLineType(lineType);
						}
						cout << "请输入线段宽度: ";
						cin >> weightType;
						cout << "请输入线段颜色: ";
						cin >> color;
						// 设置属性
						paintingMouse.setWeightType(weightType);
						paintingMouse.setColor(translateColor(color));

						paintingMouse.MouseClick(paintingMouse, type);
					}
					else {
						cout << "请输入颜色: ";
						cin >> color;

						paintingMouse.setLineType(translateLineType("实线"));
						paintingMouse.setWeightType(1);
						paintingMouse.setColor(translateColor(color));

						paintingMouse.MouseClick(paintingMouse, type);
					}

					_getch();
					cout << "\n已退出鼠标绘图" << endl;
					break;
				}

				case 'T':
				case 't': {		// 测试
					cout << "此处为测试部分..." << endl;

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
					//		_stprintf(control, _T("%d,%d"), m.x, m.y);        // 高版本 VC 推荐使用 _stprintf_s 函数
					//		outtextxy(m.x, m.y, control);                //输出鼠标位置
					//	default:
					//		break;
					//	}
					//}
					break;
				}

				case 'Q':
				case 'q':	// 退出
				default:
					break;

				}	// 第一个 Switch 结束

				if (choice == 'Q' || choice == 'q')
					break;
			}

			break;
		}
		case 2: {
			
			setbkcolor(WHITE);
			Action action = Action();
			char choice;
			IMAGE background;//定义一个图片名.
			//loadimage(&background, L"F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\7.png");//从图片文件获取图像
			loadimage(&background, L"..\\7.png");//从图片文件获取图像

			setorigin(0, 0);
			putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
			action.Init();
			//Sleep(100);
			//mciSendString(L"open F:\\vs_new\\computer-graphic-labs2.0\\computer-graphic-labs2.0\\bgm.mp3 alias bgm", NULL, 0, NULL);
			mciSendString(L"open ..\\bgm.mp3 alias bgm", NULL, 0, NULL);

			mciSendString(L"setaudio bgm volume to 50", 0, 0, 0);
			mciSendString(L"play bgm repeat", NULL, 0, NULL);
			while (1)
			{
				cout << "\n**************************" << endl
					   << "*    输入要进行的行为    *" << endl
					   << "*                        *" << endl
					   << "* A.打招呼               *" << endl
					   //<< "* B.跳舞                 *" << endl
					   << "* B.太阳东升西落         *" << endl
					   << "* Q.退出                 *" << endl
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