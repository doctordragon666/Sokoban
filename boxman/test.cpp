//#include <iostream>
//#include <Windows.h>
//#include <graphics.h>
//#include <stdlib.h>
//#include <string>
//#include <conio.h>
//
//using namespace std;
////realize_mobile();�����ĺ�����
//#define   TIAOJIAN(X)  X.y>0 && X.y<HANG && X.x>0 && X.x<=LIE
///*******�����������Һ��˳�������**********/
//#define   up			'w'
//#define   down		's'
//#define   left			'a'
//#define   right			'd'
//#define   esc			'q'
//
////��ȡ����С���ڵ�ͼ���������
//struct  _reng {
//	int  x;
//	int  y;
//};
//struct  _reng  xiao;
//
////ע������
//enum daoju{
//	QIANG,//ǽ
//	DIBANG,//�ذ�
//	MDD,  //Ŀ�ĵ�
//	REN,	//��
//	XIANG, //����
//	DAODA//����
//};
//
//
////����ߵ�����
//IMAGE  tupian[6];
//
////���ߵĴ�С����
//#define  CHANG  61
//#define  KUANG  61
//
////��Ļ�Ĵ�С
//#define  PING_KUANG  750
//#define  PING_CHANG  950
//
////ǽ: 0���ذ�: 1������Ŀ�ĵ�: 2, 
////С��: 3, ����: 4, ��������Ŀ��: 5
//
////���鲼�ֵ��к���
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
///**********ʵ����Ұ�����ȫ������************/
//
///**************��ĵ��ߴ�����Ŀ�ĵ��߹�************
//*���� ��Ŀ�ĵظ�����Ŀ�ĵ�����ṹ������
//*��� ����
//*���� ����
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
///*******��ͼ���黥������************
//*���� �� ��Ҫת����ͼ������У���Ҫת�����У���Ҫ����ȥ�ĵ���
//*��� ����
//*���� ����
//*******************************/
//void  huhuang(int h,int l,enum daoju p){
//		pai[h][l] = p;
//		putimage(100+l*CHANG,100+h*KUANG,&tupian[p]);	
//}
//
//
///***********ʵ�ֵ��߻���ʵ��***********
//realize_mobile()
//���� �� �û�����'w''s''a''d'�ĸ���,����Ŀ�ĵؽṹ���������飬Ŀ�ĵظ���
//��� �� ��
//���� �� ��
//*********************************/
//void  realize_mobile(char a,struct  _reng md[],int g) {
//	struct  _reng s1 = xiao; //������ڵذ��ƶ��õ�
//	struct  _reng s2 = xiao;//��������������õ�
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
//		//cout<<"��������"<<endl;
//		if (pai[s2.y][s2.x] == DIBANG ||pai[s2.y][s2.x] == MDD) {
//			huhuang(s2.y,s2.x,XIANG);//�ذ�������
//			huhuang(s1.y,s1.x,REN);//���ӱ����
//			huhuang(xiao.y,xiao.x,DIBANG);//�˱�ɵذ�
//			xiao = s1;
//			mdd(g,md);
//		}
//	}
//
//}
//
///*void  mobile(char  fu)
//���� �� �û������ĸ���,��������Ŀ�ĵأ���������Ŀ�ĵ����������
//��� �� ��
//���� �� ��
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
//tongguang()//�жϵ�ͼ�����Ƿ�������Ŀ�ĵص�ֵ���ڣ�����ͨ������
//*���� ��
//*��� ��
//*���� �������
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
//	//�����������ɫ
//	settextcolor(RGB(255,255,0));
//	settextstyle(20, 0, _T("����"));
//	//��������λ��
//	RECT rec = {0, 0, PING_CHANG,PING_KUANG};
//	drawtext(_T("��ϲ���Ѿ�ͨ�أ�׼��������һ��"),&rec,DT_CENTER | DT_VCENTER | DT_VCENTER);
//
//}
//
//int	  main(void)	{
//	int  jishu = 0;
//	int  i = 0;//ͳ��Ŀ�ĵصĸ���
//	struct  _reng md[4]; //��������Ŀ�ĵ����������
//	//��ʼ����Ļ��С
//	initgraph(PING_CHANG,PING_KUANG);
//
//	//������̨����
//	loadimage(0,_T("blackground.bmp"));
//
//	//׼������̨����
//	loadimage(&tupian[QIANG],_T("./res/wall_right.bmp"),CHANG,KUANG,true);//ǽ
//	loadimage(&tupian[DIBANG],_T("./res/floor.bmp"),CHANG,KUANG,true);//�ذ�
//	loadimage(&tupian[MDD],_T("./res/des.bmp"),CHANG,KUANG,true);//����Ŀ�ĵ�
//	loadimage(&tupian[REN],_T("./res/man.bmp"),CHANG,KUANG,true);//����
//	loadimage(&tupian[XIANG],_T("./res/box.bmp"),CHANG,KUANG,true);//����
//	loadimage(&tupian[DAODA],_T("./res/box.bmp"),CHANG,KUANG,true);//���ӵ���Ŀ�ĵ�
//	//���õ���
//	for (int y = 0;y<HANG;y++) {
//		for (int x = 0; x<LIE;x++) {
//			//����С�˵�����
//			if (pai[y][x] == 3) {
//				xiao.x = x;
//				xiao.y = y;
//			}
//			//��������Ŀ�ĵص�����
//			if (pai[y][x] == 2) {
//				md[i].x = x;
//				md[i].y = y;
//				i++;
//			}
//			//��ʾ���õĵ���
//			putimage(100+x*CHANG,100+y*KUANG,&tupian[pai[y][x]]);	
//		}
//	}
//	//pai[xiao.y][xiao.x] = 1;
//
//	//�ж��û��������
//	bool  kaishi = true ;
//	do  {
//		//��ȡ��Ұ�����Ϣ�ж��Ƿ񰴼�
//	if (_kbhit()) {
//		char  ch = _getch();
//			if (ch == up) {			//��
//				//mobile(up);
//				mobile(ch,4,md);
//				jishu++;
//			}else if (ch == down) {  //��
//				//mobile(down);
//				mobile(down,4,md);
//				jishu++;
//			}else if (ch == left) {  //��
//				//mobile(left);
//				mobile(left,4,md);
//				jishu++;
//			}else if (ch == right) { //��
//				//mobile(right);
//				mobile(right,4,md);
//				jishu++;
//			}else if (ch == esc) { //�˳�
//				kaishi = false ;
//			}
//			kaishi = tongguang();
//	}
//	//cout<<"���� = "<<jishu<<endl;
//	
//	Sleep(20);
//	}while (kaishi);
//	for (int i = 0; i<4;i++) {
//		printf("��%d����ֵ = %d\n",i+1,pai[md[i].y][md[i].x]);
//	}
//	gongxi();
//
//	system("pause");
//	return 0;
//}