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
					<< "* B.圆形绘制             *" << endl
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
						int x1, y1, r, weightType;
						string color;
						int lineType;
						char ch;
						cout << "是Y否N退出？";
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
							break;

						cout << "请输入圆起点(圆心)坐标: ";
						cin >> x1 >> y1;
						cout << "请输入圆半径: ";
						cin >> r;
						cout << "请输入线段类型 [0.实线、1.点划线、2.虚线、3.长短线交替]: ";
						cin >> lineType;
						cout << "请输入线段宽度: ";
						cin >> weightType;
						cout << "请输入线段颜色: ";
						cin >> color;

						// 设置属性
						paintingCircle.setWeightType(weightType);
						paintingCircle.setLineType(lineType);
						paintingCircle.setColor(translateColor(color));

						paintingCircle.MidPointCircle(x1, y1, r);
						_getch();

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
					for (int i = 0; i < edges_num; i++) {
						cout << "顶点" << i + 1 << ": ";
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
					paintingPolygon2.Init(etable, newEdges, edges_num); //初始化活动边表

					cout << "是否进行颜色填充[Y/N]: ";
					cin >> choice;
					if (choice == 'Y' || choice == 'y') {
						cout << "请输入所要填充颜色: ";
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
					if (type == 3) {
						closegraph();
						drawCurve(argc, argv);
					}
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
					//closegraph();

					//drawCurve(argc, argv);

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
			cleardevice();

			Tinky tinky = Tinky();
			Dipsy dipsy = Dipsy();
			LaaLaa laalaa = LaaLaa();
			Po po = Po();

			rectangle(400, 5, 700, 25);
			outtextxy(420, 7, L"致童年——天线宝宝主题二维动画");
			

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