#ifndef BOX_MAN_H
#define BOX_MAN_H

#define WINDOW_WIDTH  883		// 游戏屏幕宽度 - 像素
#define WINDOW_HEIGHT 550		// 游戏屏幕高度 - 像素

#define MAP_LINE	9			// 游戏地图数组行数
#define MAP_COLUMN	12			// 游戏地图数组列数
#define MAP_IMAGES	6			// 游戏地图图片道具个数
#define RATIO		61			// 道具尺寸 - 像素

#define KEY_UP		'w'			// 游戏热键控制 上键
#define KEY_DOWN	's'			// 游戏热键控制 下键
#define KEY_LEFT	'a'			// 游戏热键控制 左键
#define KEY_RIGHT	'd'			// 游戏热键控制 右键
#define KEY_END		'q'			// 游戏热键控制 退出键


// 道具枚举定义
// wall  墙壁0
// map_floor  地板1
// des 目的地2
// man 人物3
// box 箱子4
enum material {
	wall,
	map_floor,
	des,
	man,
	box
};

// 人物行走方向枚举定义
// 上、下、左、右
enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

/// <summary>
/// 人物结构体
/// x,y坐标
/// 道具状态
/// 步数统计
/// </summary>
struct human_struct {
	int x;
	int y;
	material status;
	int stepCount;
};

const unsigned short COUNT = 4;  // 统计步数所使用的内存空间

#endif // !BOX_MAN_H