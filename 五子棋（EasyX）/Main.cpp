#include<iostream>
#include<easyx.h>
#include"UI.h"

bool back = false;
bool win = false;
bool blackorwhite = true;//black == ture
bool leavegame = false;

class Player
{
public:
	int n = 0;
	bool Black = true;
	bool piecescolor[100];
	int x[100], y[100];

	Player()//init
	{
		for (int i = 0; i < 100; i++)
		{
			x[i] = 0;
			y[i] = 0;
			piecescolor[i] = 0;
		}
	}

public:

	void PutPieces()//下棋
	{
		ExMessage msg;
		outtextxy(20, 20, L"Next:");
		if (Black)
		{
			setfillcolor(BLACK);
			fillcircle(75, 28, 10);
			outtextxy(100, 20, L"Black ");
		}
		else
		{
			setfillcolor(WHITE);
			fillcircle(75, 28, 10);
			outtextxy(100, 20, L"White ");
		}

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x < 590 && 525 < msg.x && msg.y < 40 && 10 < msg.y)
				{
					win = true;
					back = true;
				}
				if (msg.x < 500 && msg.y < 500)//落子坐标处理
				{
					x[n] = ((msg.x - 25) / 50) * 50 + 50;
					y[n] = ((msg.y - 25) / 50) * 50 + 50;

					for (int i = 0; i < n; i++)
					{
						if (x[n] == x[i] && y[n] == y[i])
						{
							return;
						}
					}

					if (Black)
					{
						setfillcolor(BLACK);
						Black = false;
						piecescolor[n] = 0;
					}
					else
					{
						setfillcolor(WHITE);
						Black = true;
						piecescolor[n] = 1;
					}

					setlinecolor(BLACK);
					fillcircle(x[n], y[n], 10);
					//std::cout << x[n] << ":" << y[n] << ":" << piecescolor[n] << std::endl;//Text

					Win(x, y, piecescolor, n);
					n++;
				}
			default:
				break;
			}
		}
	}
	void Win(const int* x, const int* y, const bool* piecescolor, int &n)
	{
		int NumberOfConnectedPieces = 0;

		for (int v = 0; v < 5; v++)//X轴
		{
			for (int i = 0; i < n; i++)
			{
				if (x[n] + (v + 1) * 50 == x[i] && y[n] == y[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		for (int v = 0; v < 5; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if (x[n] - (v + 1) * 50 == x[i] && y[n] == y[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		if (NumberOfConnectedPieces >= 4)
		{
			blackorwhite = Black;
			win = true;
		}
		else
		{
			NumberOfConnectedPieces = 0;
		}



		for (int v = 0; v < 5; v++)//Y轴
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] + (v + 1) * 50 == y[i] && x[n] == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		for (int v = 0; v < 5; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] - (v + 1) * 50 == y[i] && x[n] == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		if (NumberOfConnectedPieces >= 4)
		{
			blackorwhite = Black;
			win = true;
		}
		else
		{
			NumberOfConnectedPieces = 0;
		}


		for (int v = 0; v < 5; v++)//二四象限角平分线
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] + (v + 1) * 50 == y[i] && x[n] + (v + 1) * 50 == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		for (int v = 0; v < 5; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] - (v + 1) * 50 == y[i] && x[n] - (v + 1) * 50 == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		if (NumberOfConnectedPieces >= 4)
		{
			blackorwhite = Black;
			win = true;
		}
		else
		{
			NumberOfConnectedPieces = 0;
		}


		for (int v = 0; v < 5; v++)//一三象限角平分线
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] + (v + 1) * 50 == y[i] && x[n] - (v + 1) * 50 == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		for (int v = 0; v < 5; v++)
		{
			for (int i = 0; i < n; i++)
			{
				if (y[n] - (v + 1) * 50 == y[i] && x[n] + (v + 1) * 50 == x[i] && piecescolor[n] == piecescolor[i])
				{
					NumberOfConnectedPieces++;
				}
			}

		}
		if (NumberOfConnectedPieces >= 4)
		{
			blackorwhite = Black;
			win = true;
		}
		else
		{
			NumberOfConnectedPieces = 0;
		}
	}
	//Judgment of Win
};



int main()
{
	Player player;
	ExMessage msg;
	IMAGE img;
	bool start = false;

	while (leavegame == false)
	{
		UIstartBeforeGame();//->UI.h
		while (!start)
		{	
			if (peekmessage(&msg, EX_MOUSE))
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					if (msg.x < 50 && 1 < msg.x && msg.y < 50 && 1 < msg.y)//进入设置界面
					{
						UISet();//->UI.h
					}
					if (msg.x < 540 && 300 < msg.x && msg.y < 475 && 350 < msg.y)//进入游戏
					{
						ShowChessBoard();
						start = true;

						while (win == false)
						{
							player.PutPieces();
						}
					}
				default:
					break;
				}
			}
		}
		if (back == false)
		{
			UIstartAfterGame(blackorwhite);//->UI.h
		}

		win = false;
		back = false;
		start = false;
		player.Black = true;
		player.n = 0;
	}
}