#include <iostream>
#include <string>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

#include "Sokoban.h"

//游戏地图
int MAP[MAP_LINE][MAP_COLUMN] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
	{0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0},
	{0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

IMAGE images[MAP_IMAGES];
const unsigned init_x = 5;
const unsigned init_y = 5;
human_struct human = { init_x, init_y, man, 0 };


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

	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	putimage(0, 0, &bg_image);

	for (int i = 0; i < MAP_LINE; i++) {
		for (int j = 0; j < MAP_COLUMN; j++) {
			putimage(RATIO * j, RATIO * i, &images[MAP[i][j]]);
		}
	}

	//设置计数板
	settextstyle(20, 0, "宋体");
	outtextxy(750, 80, "当前关卡：");
	outtextxy(750, 150, "当前步数：");
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
	switch (directory) {
	case UP:
		if (MAP[human.x - 1][human.y] >= 4 && MAP[human.x - 2][human.y] >= 1) {

			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * human.y, RATIO * (human.x - 1), &images[human.status]);
			putimage(RATIO * human.y, RATIO * (human.x - 2), &images[box]);
			if (MAP[human.x - 1][human.y] == 5) {
				MAP[human.x - 1][human.y] = 2;
			}
			else {
				MAP[human.x - 1][human.y] = 1;
			}

			if (MAP[human.x - 2][human.y] == 2) {
				MAP[human.x - 2][human.y] = 5;
			}
			else {
				MAP[human.x - 2][human.y] = 4;
			}
			human.x--;
			human.stepCount++;
		}
		else if (MAP[human.x - 1][human.y] >= 1 && MAP[human.x - 1][human.y] < 4) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}

			putimage(RATIO * human.y, RATIO * (human.x - 1), &images[human.status]);
			human.x--;
			human.stepCount++;
		}

		break;
	case DOWN:
		if (MAP[human.x + 1][human.y] >= 4 && MAP[human.x + 2][human.y] >= 1) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * human.y, RATIO * (human.x + 1), &images[human.status]);
			putimage(RATIO * human.y, RATIO * (human.x + 2), &images[box]);
			if (MAP[human.x + 1][human.y] == 5) {
				MAP[human.x + 1][human.y] = 2;
			}
			else {
				MAP[human.x + 1][human.y] = 1;
			}
			if (MAP[human.x + 2][human.y] == 2) {
				MAP[human.x + 2][human.y] = 5;
			}
			else {
				MAP[human.x + 2][human.y] = 4;
			}
			human.x++;
			human.stepCount++;

		}
		else if (MAP[human.x + 1][human.y] >= 1 && MAP[human.x + 1][human.y] < 4) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * human.y, RATIO * (human.x + 1), &images[human.status]);
			human.x++;
			human.stepCount++;
		}
		break;
	case LEFT:
		if (MAP[human.x][human.y - 1] >= 4 && MAP[human.x][human.y - 2] >= 1) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * (human.y - 1), RATIO * human.x, &images[human.status]);
			putimage(RATIO * (human.y - 2), RATIO * human.x, &images[box]);
			if (MAP[human.x][human.y - 1] == 5) {
				MAP[human.x][human.y - 1] = 2;
			}
			else {
				MAP[human.x][human.y - 1] = 1;
			}

			if (MAP[human.x][human.y - 2] == 2) {
				MAP[human.x][human.y - 2] = 5;
			}
			else {
				MAP[human.x][human.y - 2] = 4;
			}
			human.y--;
			human.stepCount++;
		}
		else if (MAP[human.x][human.y - 1] >= 1 && MAP[human.x][human.y - 1] < 4) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * (human.y - 1), RATIO * human.x, &images[human.status]);
			human.y--;
			human.stepCount++;
		}
		break;
	case RIGHT:
		if (MAP[human.x][human.y + 1] >= 4 && MAP[human.x][human.y + 2] >= 1) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				int value = MAP[human.x][human.y];
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * (human.y + 1), RATIO * human.x, &images[human.status]);
			putimage(RATIO * (human.y + 2), RATIO * human.x, &images[box]);
			if (MAP[human.x][human.y + 1] == 5) {
				MAP[human.x][human.y + 1] = 2;
			}
			else {
				MAP[human.x][human.y + 1] = 1;
			}

			if (MAP[human.x][human.y + 2] == 2) {
				MAP[human.x][human.y + 2] = 5;
			}
			else {
				MAP[human.x][human.y + 2] = 4;
			}
			human.y++;
			human.stepCount++;
		}
		else if (MAP[human.x][human.y + 1] >= 1 && MAP[human.x][human.y + 1] < 4) {
			if (MAP[human.x][human.y] == 3) {
				putimage(RATIO * human.y, RATIO * human.x, &images[map_floor]);
			}
			else {
				putimage(RATIO * human.y, RATIO * human.x, &images[MAP[human.x][human.y]]);
			}
			putimage(RATIO * (human.y + 1), RATIO * human.x, &images[human.status]);
			human.y++;
			human.stepCount++;
		}
		break;
	default:
		break;
	}
	char* str = getStep(human.stepCount);
	outtextxy(850, 150, str);
	delete[] str;
}



char* getStep(int step) {
	if (!step) {
		return NULL;
	}

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
