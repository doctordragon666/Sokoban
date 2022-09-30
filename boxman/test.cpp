//#include <iostream>
//#include <Windows.h>
//#include <graphics.h>
//#include <stdlib.h>
//#include <string>
//#include <conio.h>
//
//using namespace std;
////realize_mobile();函数的宏条件
//#define   TIAOJIAN(X)  X.y>0 && X.y<HANG && X.x>0 && X.x<=LIE
///*******定义上下左右和退出按键宏**********/
//#define   up			'w'
//#define   down		's'
//#define   left			'a'
//#define   right			'd'
//#define   esc			'q'
//
////获取保存小人在地图数组的坐标
//struct  _reng {
//	int  x;
//	int  y;
//};
//struct  _reng  xiao;
//
////注明道具
//enum daoju{
//	QIANG,//墙
//	DIBANG,//地板
//	MDD,  //目的地
//	REN,	//人
//	XIANG, //箱子
//	DAODA//到达
//};
//
//
////存道具的数组
//IMAGE  tupian[6];
//
////道具的大小拉伸
//#define  CHANG  61
//#define  KUANG  61
//
////屏幕的大小
//#define  PING_KUANG  750
//#define  PING_CHANG  950
//
////墙: 0，地板: 1，箱子目的地: 2, 
////小人: 3, 箱子: 4, 箱子命中目标: 5
//
////数组布局的行和列
//#define  HANG   9
//#define  LIE      12
//
//int pai[HANG][LIE] = {
//0,0,0,0,0,0,0,0,0,0,0,0,
//0,1,0,1,1,1,1,1,1,1,0,0,
//0,1,4,1,0,2,1,0,2,1,0,0,
//0,1,0,1,0,1,0,0,1,1,1,0,
//0,1,0,2,0,1,1,4,1,1,1,0,
//0,1,1,1,0,3,1,1,1,4,1,0,
//0,1,2,1,1,4,1,1,1,1,1,0,
//0,1,0,0,1,0,1,1,0,0,1,0,
//0,0,0,0,0,0,0,0,0,0,0,0
//};
//
//void  huhuang(int h,int l,enum daoju p);
///**********实现玩家按键的全部函数************/
//
///**************别的道具从箱子目的地走过************
//*输入 ：目的地个数，目的地坐标结构体数组
//*输出 ：无
//*返回 ：无
//********************************************/
//void mdd(int g,struct  _reng *p) {
//	for (int i = 0;i<g;i++) {
//		if (pai[(p+i)->y][(p+i)->x] == REN ) {
//			pai[(p+i)->y ][(p+i)->x] = REN;
//			huhuang((p+i)->y ,(p+i)->x,REN);
//			return ;
//		}else if (pai[(p+i)->y][(p+i)->x] == XIANG){
//			pai[(p+i)->y ][(p+i)->x] = DAODA;
//			huhuang((p+i)->y ,(p+i)->x,DAODA);
//			return ;
//		}else{
//			if (pai[(p+i)->y][(p+i)->x] != DAODA) {
//				pai[(p+i)->y ][(p+i)->x] = MDD;
//				huhuang((p+i)->y ,(p+i)->x,MDD);
//			}
//		}
//	}
//	return ;
//}
//
///*******地图数组互换函数************
//*输入 ： 需要转换地图数组的行，需要转换的列，需要换进去的道具
//*输出 ：无
//*返回 ：无
//*******************************/
//void  huhuang(int h,int l,enum daoju p){
//		pai[h][l] = p;
//		putimage(100+l*CHANG,100+h*KUANG,&tupian[p]);	
//}
//
//
///***********实现道具互换实现***********
//realize_mobile()
//输人 ： 用户按了'w''s''a''d'哪个键,箱子目的地结构体坐标数组，目的地个数
//输出 ： 无
//返回 ： 无
//*********************************/
//void  realize_mobile(char a,struct  _reng md[],int g) {
//	struct  _reng s1 = xiao; //这个是在地板移动用的
//	struct  _reng s2 = xiao;//这个是推着箱子用的
//
//	switch (a) {
//		case 'w':
//			s1.y--;
//			s2.y-=2;
//			break;
//		case 's':
//			s1.y++;
//			s2.y+=2;
//			break;
//		case 'a':
//			s1.x--;
//			s2.x-=2;
//			break;
//		case 'd':
//			s1.x++;
//			s2.x+=2;
//			break;
//		default : 
//			break;
//	}
//
//	if (TIAOJIAN(s1) && pai[s1.y][s1.x]==DIBANG ||pai[s1.y][s1.x] == MDD ) {
//
//			huhuang(s1.y,s1.x,REN);
//			huhuang(xiao.y,xiao.x,DIBANG);
//		
//			xiao = s1;
//
//			mdd(g,md);
//
//	}else if (TIAOJIAN(s2) && pai[s1.y][s1.x]== XIANG  ) {
//		//cout<<"到我这里"<<endl;
//		if (pai[s2.y][s2.x] == DIBANG ||pai[s2.y][s2.x] == MDD) {
//			huhuang(s2.y,s2.x,XIANG);//地板变成箱子
//			huhuang(s1.y,s1.x,REN);//箱子变成人
//			huhuang(xiao.y,xiao.x,DIBANG);//人变成地板
//			xiao = s1;
//			mdd(g,md);
//		}
//	}
//
//}
//
///*void  mobile(char  fu)
//输入 ： 用户按了哪个键,几个箱子目的地，保存箱子目的地坐标的数组
//输出 ： 无
//返回 ： 无
//*******************************/
//void  mobile(char  fu,int g,struct  _reng d[]){
//	switch (fu){
//		case 'w':
//			realize_mobile('w',d,g);
//			break;
//		case 's':
//			realize_mobile('s',d,g);
//			break;
//		case 'a':
//			realize_mobile('a',d,g);
//			break;
//		case 'd':
//			realize_mobile('d',d,g);
//			break;
//		default : 
//			break;
//	}
//}
//
///*******************************
//tongguang()//判断地图数组是否还有箱子目的地的值存在，出现通关字样
//*输入 ：
//*输出 ：
//*返回 ：真与假
//********************************/
//bool tongguang() {
//	for (int i = 0; i<HANG;i++) {
//		for (int j = 0;j<LIE;j++) {
//			if (pai[i][j] == MDD ){
//				return true;
//			}
//		}
//	}
//	return false;
//}
//
///******************************/
//void gongxi() {
//	loadimage(0,_T("blackground.bmp"));
//	//设置字体和颜色
//	settextcolor(RGB(255,255,0));
//	settextstyle(20, 0, _T("宋体"));
//	//设置文字位置
//	RECT rec = {0, 0, PING_CHANG,PING_KUANG};
//	drawtext(_T("恭喜你已经通关，准备进入下一关"),&rec,DT_CENTER | DT_VCENTER | DT_VCENTER);
//
//}
//
//int	  main(void)	{
//	int  jishu = 0;
//	int  i = 0;//统计目的地的个数
//	struct  _reng md[4]; //保存箱子目的地坐标的数组
//	//初始化屏幕大小
//	initgraph(PING_CHANG,PING_KUANG);
//
//	//加载舞台背景
//	loadimage(0,_T("blackground.bmp"));
//
//	//准备好舞台道具
//	loadimage(&tupian[QIANG],_T("./res/wall_right.bmp"),CHANG,KUANG,true);//墙
//	loadimage(&tupian[DIBANG],_T("./res/floor.bmp"),CHANG,KUANG,true);//地板
//	loadimage(&tupian[MDD],_T("./res/des.bmp"),CHANG,KUANG,true);//箱子目的地
//	loadimage(&tupian[REN],_T("./res/man.bmp"),CHANG,KUANG,true);//人物
//	loadimage(&tupian[XIANG],_T("./res/box.bmp"),CHANG,KUANG,true);//箱子
//	loadimage(&tupian[DAODA],_T("./res/box.bmp"),CHANG,KUANG,true);//箱子到达目的地
//	//布置道具
//	for (int y = 0;y<HANG;y++) {
//		for (int x = 0; x<LIE;x++) {
//			//保存小人的坐标
//			if (pai[y][x] == 3) {
//				xiao.x = x;
//				xiao.y = y;
//			}
//			//保存箱子目的地的坐标
//			if (pai[y][x] == 2) {
//				md[i].x = x;
//				md[i].y = y;
//				i++;
//			}
//			//显示布置的道具
//			putimage(100+x*CHANG,100+y*KUANG,&tupian[pai[y][x]]);	
//		}
//	}
//	//pai[xiao.y][xiao.x] = 1;
//
//	//判断用户按键情况
//	bool  kaishi = true ;
//	do  {
//		//获取玩家按键信息判断是否按键
//	if (_kbhit()) {
//		char  ch = _getch();
//			if (ch == up) {			//上
//				//mobile(up);
//				mobile(ch,4,md);
//				jishu++;
//			}else if (ch == down) {  //下
//				//mobile(down);
//				mobile(down,4,md);
//				jishu++;
//			}else if (ch == left) {  //左
//				//mobile(left);
//				mobile(left,4,md);
//				jishu++;
//			}else if (ch == right) { //右
//				//mobile(right);
//				mobile(right,4,md);
//				jishu++;
//			}else if (ch == esc) { //退出
//				kaishi = false ;
//			}
//			kaishi = tongguang();
//	}
//	//cout<<"计数 = "<<jishu<<endl;
//	
//	Sleep(20);
//	}while (kaishi);
//	for (int i = 0; i<4;i++) {
//		printf("第%d个的值 = %d\n",i+1,pai[md[i].y][md[i].x]);
//	}
//	gongxi();
//
//	system("pause");
//	return 0;
//}