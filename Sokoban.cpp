#include <iostream>
#include <string>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

#include "Sokoban.h"
//游戏地图
int MAP[MAP_LINE][MAP_COLUMN] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 4, 1, 1, 2, 1, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 2, 0, 1, 1, 1, 0},
	{0, 1, 1, 4, 1, 3, 1, 1, 0},
	{0, 1, 2, 1, 1, 4, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int init_x = 5;
int init_y = 5;
human_struct human = { init_x, init_y, man, map_floor };//初始人物一定站在地板上

// 初始化地图
void initMap();

// 游戏控制
void gameControl();

// 人物行走操作
void moveOperation(DIRECTION);

// 获取步数统计
char* getStep(int);

/// <summary>
/// 遍历地图，如果地图上面没有目标，也即目标被填充返回真。
/// </summary>
/// <returns></returns>
bool isGameOver() {
	for (int i = 0; i < MAP_LINE; i++) {
		for (int j = 0; j < MAP_COLUMN; j++) {
			if (MAP[i][j] == des) {
				return false;
			}
		}
	}
	return true;
}

/// <summary>
/// 游戏结束界面渲染
/// </summary>
void gameIsOver() {
	cleardevice();
	settextstyle(20, 0, "宋体");
	outtextxy(350, 250, "恭喜过关！");
}

/// <summary>
/// 检查一下人物脚下踩的东西
/// </summary>
void checkStatus()
{
	if (human.status == des) {
		putimage(RATIO * human.x, RATIO * human.y, &images[des]);
		MAP[human.x][human.y] = des;
		human.status = map_floor;//如果是目的地，则改变英雄
	}
	else {
		putimage(RATIO * human.x, RATIO * human.y, &images[map_floor]);
		MAP[human.x][human.y] = map_floor;
	}
}

int main() {
	initMap();

	gameControl();

	system("pause");
	closegraph();
	return 0;

}

void initMap() {
	IMAGE bg_image;

	loadimage(&bg_image, "./res/blackground.bmp", WINDOW_WIDTH, WINDOW_HEIGHT, true);
	loadimage(&images[wall], "./res/wall_right.bmp", RATIO, RATIO, true);
	loadimage(&images[map_floor], "./res/floor.bmp", RATIO, RATIO, true);
	loadimage(&images[des], "./res/des.bmp", RATIO, RATIO, true);
	loadimage(&images[man], "./res/man.bmp", RATIO, RATIO, true);
	loadimage(&images[box], "./res/box.bmp", RATIO, RATIO, true);

	if(debug)
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT,EW_SHOWCONSOLE);
	else
		initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	putimage(0, 0, &bg_image);

	for (int i = 0; i < MAP_LINE; i++) {
		for (int j = 0; j < MAP_COLUMN; j++) {
			putimage(RATIO * i, RATIO * j, &images[MAP[i][j]]);
		}
	}

	//设置计数板
	settextstyle(20, 0, "宋体");
	outtextxy(700, 80, "当前关卡：");
	outtextxy(700, 150, "当前步数：");
	outtextxy(850, 80, "1");
	outtextxy(850, 150, "0");
}

void gameControl() {

	bool gameOver = false;

	while (!gameOver) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case KEY_UP:
				moveOperation(UP);
				break;
			case KEY_DOWN:
				moveOperation(DOWN);
				break;
			case KEY_LEFT:
				moveOperation(LEFT);
				break;
			case KEY_RIGHT:
				moveOperation(RIGHT);
				break;
			case KEY_END:
				gameOver = true;
				cleardevice();
				exit(-1);
				break;
			default:
				break;
			}
			if (isGameOver()) {
				gameOver = true;
				gameIsOver();
			}
		}
		Sleep(100);
	}
}

void moveOperation(DIRECTION directory) {
	Pos humanOne = { 0,0 };//这个方向上的第一个位置
	Pos humanTwo = { 0,0 };//这个方向上的第二个位置
	int update = true;//只考虑不能更新的情况

	switch (directory) {
	case UP:
	case DOWN:
		humanOne = { human.x, human.y + directory };
		humanTwo = { human.x, human.y + 2 * directory };
		break;
	case LEFT:
	case RIGHT:
		humanOne = { human.x + directory/2, human.y };
		humanTwo = { human.x + directory, human.y };
		break;
	}

	if (MAP[humanOne.x][humanOne.y] == map_floor || MAP[humanOne.x][humanOne.y] == des) {
		checkStatus();
		human.status = (material)MAP[humanOne.x][humanOne.y];
	}
	else if (MAP[humanOne.x][humanOne.y] == box) {
		if (MAP[humanTwo.x][humanTwo.y] == map_floor || MAP[humanTwo.x][humanTwo.y] == des)
		{
			checkStatus();
			putimage(RATIO * humanTwo.x, RATIO * humanTwo.y, &images[box]);
			MAP[humanTwo.x][humanTwo.y] += 3;//变为box或者重叠
		}
		else{
			update = false;
		}
	}
	else if(MAP[humanOne.x][humanOne.y] == overlap){
		if (MAP[humanTwo.x][humanTwo.y] == map_floor){
			checkStatus();
			putimage(RATIO * humanTwo.x, RATIO * humanTwo.y, &images[box]);
			MAP[humanTwo.x][humanTwo.y] += 3;
			human.status = des;
		}
		else{
			update = false;//墙或者是人
		}
	}
	else{
		update = false;
	}
	
	if (update)
	{
		putimage(RATIO * humanOne.x, RATIO * humanOne.y, &images[man]);
		MAP[humanOne.x][humanOne.y] = man;
		human.stepCount++;
		human.x = humanOne.x;
		human.y = humanOne.y;
	}
	
	char* str = getStep(human.stepCount);
	outtextxy(850, 150, str);
	if (str) delete[] str;
}

char* getStep(int step) {
	int len = 0;
	int temp = step;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	char* p = new char[len + 1];
	p[len] = '\0';

	while (step) {
		len--;
		p[len] = step % 10 + '0';
		step /= 10;
	}

	return p;
}