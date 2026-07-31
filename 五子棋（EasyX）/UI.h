#pragma once
#include<iostream>
#include<easyx.h>

#define WIDTH 600
#define HEIGHT 600

void UIstartBeforeGame()//游戏开始前UI
{
	closegraph();
	initgraph(WIDTH, HEIGHT);
	loadimage(NULL, _T("封面.jpeg"), 600, 600);
	fillrectangle(1, 1, 50, 50);//设置按钮
	outtextxy(10, 17, L"设置");
	settextstyle(130, 0, _T("Consolas"));
	outtextxy(300, 350, L"开始");//开始按钮
}

void UIstartAfterGame(bool &blackorwhitewin)//游戏结束后UI
{
	settextstyle(130, 0, _T("Consolas"));
	if (!blackorwhitewin)
	{
		outtextxy(0, 200, L"Black Win!");
	}
	else
	{
		outtextxy(0, 200, L"White Win!");
	}
	settextstyle(20, 0, _T("Consolas"));
	outtextxy(200, 310, L"Press Enter to leave");
	std::cin.get();
}

void UISet()
{
	closegraph();
	initgraph(WIDTH, HEIGHT);
	outtextxy(290, 20, L"设置");
	outtextxy(270, 50, L"敬请期待……");
}

void ShowChessBoard()
{
	closegraph();
	initgraph(WIDTH, HEIGHT);//显示棋盘
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	settextcolor(BLACK);
	fillrectangle(500, 10, 590, 40);
	outtextxy(525, 17, L"Menu");

	for (int i = 1; i <= 10; i++)
	{
		line(50, i * 50, 500, i * 50);//显示行
		outtextxy(520, i * 50, L'A' + (i - 1));
		line(i * 50, 50, i * 50, 500);//显示列
		outtextxy(i * 50, 520, L'A' + (i - 1));
	}
}