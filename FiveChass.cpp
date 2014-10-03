// five3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

void save(int a[19][19])
{
		FILE* f=fopen("Five.txt","w");//寫入Five.txt到預設資料夾
		for(int j=0;j<19;j++)
		{
			for(int i=0;i<19;i++)
				fprintf(f,"%d ",a[j][i]);//輸入陣列資料
			fprintf(f,"\n");
		}
		fclose(f);
		system("cls");
}

void load(int a[19][19])
{
		FILE* f=fopen("Five.txt","r");//讀取Five.txt從預設資料夾
		for(int j=0;j<19;j++)
		{
			for(int i=0;i<19;i++)
				fscanf(f,"%d ",&a[j][i]);//讀取陣列資料
		}
		fclose(f);
		system("cls");
}

void random(int &ran)
{
	srand(time(NULL));
	int a=rand()%3;//亂數輸出用
	switch(a)
	{
		case 0:
			ran=0;
			break;
		case 1:
			ran=1;
			break;
		case 2:
			ran=7;
			break;
	}
}

void random2(int &ran)
{
	srand(time(NULL));
	int a=rand()%5;//亂數輸出用
	switch(a)
	{
		case 0:
			ran=0;
			break;
		case 1:
			ran=1;
			break;
		case 2:
			ran=2;
			break;
		case 3:
			ran=3;
			break;
		case 4:
			ran=7;
			break;
	}
}

void random3(int &ran)
{
	srand(time(NULL));
	int a=rand()%5;//亂數輸出用
	switch(a)
	{
		case 0:
			ran=5;
			break;
		case 1:
			ran=6;
			break;
		case 2:
			ran=7;
			break;
		case 3:
			ran=0;
			break;
		case 4:
			ran=1;
			break;
	}
}

void print(int a[19][19])
{
	cout << "  ";  //座標對齊用
	cout <<"０１２３４５６７８９101112131415161718";
	cout << endl;
	for(int j=0;j<19;j++)//印出縱坐標
		{
		if(j<10)
		cout << "0"<<j;//個位數對齊用
		else
		cout << j;
			for(int i=0;i<19;i++)
			{
			if(a[j][i]==0)
			{
			if(j==0&&i==0&&a[j][i]==0)
			cout << "╔";
			else if(j==0&&i==18&&a[j][i]==0)
			cout << "╗";
			else if(j==18&&i==0&&a[j][i]==0)
			cout << "╚";
			else if(j==18&&i==18&&a[j][i]==0)
			cout << "╝";
			else if(j==0&&i<18&&i>0&&a[j][i]==0)
			cout << "╦";
			else if(i==0&&j<18&&j>0&&a[j][i]==0)
			cout << "╠";
			else if(i==18&&j<18&&j>0&&a[j][i]==0)
			cout << "╣";
			else if(j==18&&i<18&&i>0&&a[j][i]==0)
			cout << "╩";
			else if(a[j][i]==0)
			cout << "╬";
			}
			if(a[j][i]==2)//如果值是2  輸出黑子圖案
			cout << "□";
			else if(a[j][i]==1)//如果值是1  輸出白子圖案
			cout << "■";
			}
		cout << endl;
		}
	cout << endl;

}

void menu(int a[19][19])
{
	int b;
	system("cls");
	print(a);//目前棋盤狀況
	cout << "載入【1】，儲存【2】，離開選單【3】:";
	cin >> b;
	if(b==1)
	{
		load(a);
		cout << "載入完畢！"<<endl;
	}
	else if(b==2)
	{
		save(a);
		cout << "儲存完畢！"<<endl;
	}
	else if(b==3)
		system("cls");//清除離開
}

void Player(int &ccolor,int x,int y,int &turn,int a[19][19])
{
		if(ccolor==1)
		cout << "(白子)請下棋！』"<<endl;
		else if(ccolor==2)
		cout << "(黑子)請下棋！)』"<<endl;
		cout <<"進入選單請輸入【99】"<<endl;
		cout << "請輸入y座標:";
		cin >> y;
		if(y==99)
		{
		menu(a);
		goto here;//跳過判斷X或Y避免錯誤
		}
		cout << "請輸入x座標:";
		cin >> x;
		if(x<19&&y<19&&x>=0&&y>=0)//如果範圍介於正確值之間
		{
			if(a[y][x]==0)
			{
				a[y][x]=ccolor;//空白換成白棋
				turn=2;
				system("cls");
			}
			else
			{
				system("cls");
				cout << "『該位置已被下過』"<<endl;
				turn=1;
			}
		}
		else
		{
			system("cls");
			cout << "『X和Y的值應該介於0~18』"<<endl;
			turn=1;
		}here:;
}

void fwin(int a[19][19],int &end)
{
		for(int j=0;j<19;j++)
		{
		for(int i=0;i<19;i++)
		{
			if((a[j][i]==1&&a[j][i+1]==1&&a[j][i+2]==1&&a[j][i+3]==1&&a[j][i+4]==1
			||a[j][i]==2&&a[j][i+1]==2&&a[j][i+2]==2&&a[j][i+3]==2&&a[j][i+4]==2)//橫的五連子
			||
			(a[j][i]==1&&a[j+1][i]==1&&a[j+2][i]==1&&a[j+3][i]==1&&a[j+4][i]==1
			||a[j][i]==2&&a[j+1][i]==2&&a[j+2][i]==2&&a[j+3][i]==2&&a[j+4][i]==2)//直的五連子
			||
			(a[j][i]==1&&a[j+1][i+1]==1&&a[j+2][i+2]==1&&a[j+3][i+3]==1&&a[j+4][i+4]==1
			||a[j][i]==2&&a[j+1][i+1]==2&&a[j+2][i+2]==2&&a[j+3][i+3]==2&&a[j+4][i+4]==2)//右斜的五連子
			||
			(a[j][i+4]==1&&a[j+1][i+3]==1&&a[j+2][i+2]==1&&a[j+3][i+1]==1&&a[j+4][i]==1
			||a[j][i+4]==2&&a[j+1][i+3]==2&&a[j+2][i+2]==2&&a[j+3][i+1]==2&&a[j+4][i]==2))//左斜的五連子
			{
			end=1;//勝利值代入1
			break;
			}
		}
		}
}

void single(int a[19][19],int ran,int ccolor,int j,int i)
{
						if(j==0&&i==0)//避免左上溢出
						ran=rand()%3+3;
						else if(j==0&&i==18)//避免右上溢出
						ran=rand()%3+5;
						else if(j==18&&i==0)//避免左下溢出
						ran=rand()%3+1;
						else if(j==18&&i==18)//避免右下溢出
						random(ran);
						else if(j==0&&i<18&&i>0)//避免上排溢出
						ran=rand()%5+3;
						else if(i==0&&j<18&&j>0)//避免左排溢出
						ran=rand()%5+1;
						else if(i==18&&j<18&&j>0)//避免右排溢出
						random3(ran);
						else if(j==18&&i<18&&i>0)//避免下排溢出
						random2(ran);
						else
						start:ran=rand()%8;
						switch(ran)//八方亂數下棋
						{
							case 0:
								if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
								{
								a[j-1][i-1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 1:
								if(a[j-1][i]==0&&j-1>=0)
								{
								a[j-1][i]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 2:
								if(a[j-1][i+1]==0&&j-1>=0&&i+1<19)
								{
								a[j-1][i+1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 3:
								if(a[j][i+1]==0&&i+1<19)
								{
								a[j][i+1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 4:
								if(a[j+1][i+1]==0&&j+1<19&&i+1<19)
								{
								a[j+1][i+1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 5:
								if(a[j+1][i]==0&&j+1<19)
								{
								a[j+1][i]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 6:
								if(a[j+1][i-1]==0&&j+1<19&&i-1>=0)
								{
								a[j+1][i-1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
							case 7:
								if(a[j][i-1]==0&&i-1>=0)
								{
								a[j][i-1]=3-ccolor;
								j=-1;
								}
								else
								goto start;
								break;
						break;
					}
}

void first(int a[19][19],int ccolor,int &turn,int ran)
{
	ran=rand()%11+5;//去掉四周兩排亂數下棋
	if(a[ran][ran]==0)
	{
		a[ran][ran]=3-ccolor;
		turn=1;
		system("cls");
	}
	else//如果已下過重新一遍
	{
		turn=2;
		system("cls");
	}
}

void AI(int &turn,int a[19][19],int &ccolor,int ran)
{
	system("cls");
	for(int b=21;b>=0;b--)//權重代數
	{
	for(int j=0;j<19;j++)
		{
			for(int i=0;i<19;i++)
				{
					switch(b)//從最重要開始跑
					{
					case 21:
					if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==0&&a[j][i+3]==3-ccolor&&a[j][i+4]==3-ccolor)//攻擊缺空五連子1
					{

							a[j][i+2]=3-ccolor;
							b=-1;//跳出迴圈用
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==0&&a[j+3][i]==3-ccolor&&a[j+4][i]==3-ccolor)
					{
							a[j+2][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==0&&a[j+3][i+3]==3-ccolor&&a[j+4][i+4]==3-ccolor)
					{
							a[j+2][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==3-ccolor&&a[j+2][i+1]==0&&a[j+3][i]==3-ccolor&&a[j+4][i-1]==3-ccolor)
					{
							a[j+2][i+1]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 20:
					if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==3-ccolor&&a[j][i+3]==0&&a[j][i+4]==3-ccolor)//攻擊缺空五連子2
					{

							a[j][i+3]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==3-ccolor&&a[j+3][i]==0&&a[j+4][i]==3-ccolor)
					{
							a[j+3][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==3-ccolor&&a[j+3][i+3]==0&&a[j+4][i+4]==3-ccolor)
					{
							a[j+3][i+3]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==3-ccolor&&a[j+2][i+1]==3-ccolor&&a[j+3][i]==0&&a[j+4][i-1]==3-ccolor)
					{
							a[j+3][i]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 19:
					if(a[j][i]==3-ccolor&&a[j][i+1]==0&&a[j][i+2]==3-ccolor&&a[j][i+3]==3-ccolor&&a[j][i+4]==3-ccolor)//攻擊缺空五連子3
					{

							a[j][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==0&&a[j+2][i]==3-ccolor&&a[j+3][i]==3-ccolor&&a[j+4][i]==3-ccolor)
					{
							a[j+1][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==3-ccolor&&a[j+3][i+3]==3-ccolor&&a[j+4][i+4]==3-ccolor)
					{
							a[j+1][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==0&&a[j+2][i+1]==3-ccolor&&a[j+3][i]==3-ccolor&&a[j+4][i-1]==3-ccolor)
					{
							a[j+1][i+2]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 18:
					if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==0&&a[j][i+3]==ccolor&&a[j][i+4]==ccolor)//防守缺空五連子1
					{

							a[j][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==0&&a[j+3][i]==ccolor&&a[j+4][i]==ccolor)
					{
							a[j+2][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==0&&a[j+3][i+3]==ccolor&&a[j+4][i+4]==ccolor)
					{
							a[j+2][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==ccolor&&a[j+2][i+1]==0&&a[j+3][i]==ccolor&&a[j+4][i-1]==ccolor)
					{
							a[j+2][i+1]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 17:
					if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==ccolor&&a[j][i+3]==0&&a[j][i+4]==ccolor)//防守缺空五連子2
					{

							a[j][i+3]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==ccolor&&a[j+3][i]==0&&a[j+4][i]==ccolor)
					{
							a[j+3][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==0&&a[j+4][i+4]==ccolor)
					{
							a[j+3][i+3]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==ccolor&&a[j+2][i+1]==ccolor&&a[j+3][i]==0&&a[j+4][i-1]==ccolor)
					{
							a[j+3][i]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 16:
					if(a[j][i]==ccolor&&a[j][i+1]==0&&a[j][i+2]==ccolor&&a[j][i+3]==ccolor&&a[j][i+4]==ccolor)//防守缺空五連子3
					{

							a[j][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==0&&a[j+2][i]==ccolor&&a[j+3][i]==ccolor&&a[j+4][i]==ccolor)
					{
							a[j+1][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==ccolor&&a[j+4][i+4]==ccolor)
					{
							a[j+1][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==0&&a[j+2][i+1]==ccolor&&a[j+3][i]==ccolor&&a[j+4][i-1]==ccolor)
					{
							a[j+1][i+2]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 15:
					if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==3-ccolor&&a[j][i+3]==3-ccolor)//攻擊四連子
					{
						if(a[j][i+4]==0&&j+4<19)
						{
							a[j][i+4]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j][i-1]==0&&i-1>=0)
						{
							a[j][j-1]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==3-ccolor&&a[j+3][i]==3-ccolor)
					{
						if(a[j+4][i]==0&&j+4<19)
						{
							a[j+4][i]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i]==0&&j-1>=0)
						{
							a[j-1][i]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==3-ccolor&&a[j+3][i+3]==3-ccolor)
					{
						if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
						{
							a[j-1][i-1]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j+4][i+4]==0&&j+4<19&&i+4<19)
						{
							a[j+4][i+4]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==3-ccolor&&a[j+2][i+1]==3-ccolor&&a[j+3][i]==3-ccolor)
					{
						if(a[j+4][i-1]==0&&j+4<19&&i-1>=0)
						{
							a[j+4][i-1]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i+4]==0&&j-1>=0&&i+4<19)
						{
							a[j-1][i+4]=3-ccolor;
							b=-1;
							break;
						}
					}
					break;
					case 14:
					if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==ccolor&&a[j][i+3]==ccolor)//防守四連子
					{
						if(a[j][i+4]==0&&i+4<19)
						{
							a[j][i+4]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j][i-1]==0&&i-1>=0)
						{
							a[j][i-1]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==ccolor&&a[j+3][i]==ccolor)
					{
						if(a[j+4][i]==0&&j+4<19)
						{
							a[j+4][i]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i]==0&&j-1>=0)
						{
							a[j-1][i]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==ccolor)
					{
						if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
						{
							a[j-1][i-1]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j+4][i+4]==0&&j+4<19&&i+4<19)
						{
							a[j+4][i+4]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==ccolor&&a[j+2][i+1]==ccolor&&a[j+3][i]==ccolor)
					{
						if(a[j+4][i-1]==0&&j+4<19&&i-1>=0)
						{
							a[j+4][i-1]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i+4]==0&&j-1>=0&&i+4<19)
						{
							a[j-1][i+4]=3-ccolor;
							b=-1;
							break;
						}
					}
					break;
					case 13:
					if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==0&&a[j][i+3]==3-ccolor&&a[j][i+4]==0&&a[j][i-1]==0)//攻擊缺空活四連子1
					{

							a[j][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==0&&a[j+3][i]==3-ccolor&&a[j+4][i]==0&&a[j-1][i]==0)
					{
							a[j+2][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==0&&a[j+3][i+3]==3-ccolor&&a[j+4][i+4]==0&&a[j-1][i-1]==0)
					{
							a[j+2][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==3-ccolor&&a[j+2][i+1]==0&&a[j+3][i]==3-ccolor&&a[j+4][i-1]==0&&a[j-1][i+4]==0)
					{
							a[j+2][i+1]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 12:
					if(a[j][i]==3-ccolor&&a[j][i+1]==0&&a[j][i+2]==3-ccolor&&a[j][i+3]==3-ccolor&&a[j][i+4]==0&&a[j][i-1]==0)//攻擊缺空活四連子2
					{
							a[j][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==0&&a[j+2][i]==3-ccolor&&a[j+3][i]==3-ccolor&&a[j+4][i]==0&&a[j-1][i]==0)
					{
							a[j+1][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==3-ccolor&&a[j+3][i+3]==3-ccolor&&a[j+4][i+4]==0&&a[j-1][i-1]==0)
					{
							a[j+1][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==3-ccolor&&a[j+1][i+2]==0&&a[j+2][i+1]==3-ccolor&&a[j+3][i]==3-ccolor&&a[j+4][i-1]==0&&a[j-1][i+4]==0)
					{
							a[j+1][i+2]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 11:
					if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==0&&a[j][i+3]==ccolor&&a[j][i+4]==0&&a[j][i-1]==0)//防守缺空活四連子1
					{

							a[j][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==0&&a[j+3][i]==ccolor&&a[j+4][i]==0&&a[j-1][i]==0)
					{
							a[j+2][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==0&&a[j+3][i+3]==ccolor&&a[j+4][i+4]==0&&a[j-1][i-1]==0)
					{
							a[j+2][i+2]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==ccolor&&a[j+2][i+1]==0&&a[j+3][i]==ccolor&&a[j+4][i-1]==0&&a[j-1][i+4]==0)
					{
							a[j+2][i+1]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 10:
					if(a[j][i]==ccolor&&a[j][i+1]==0&&a[j][i+2]==ccolor&&a[j][i+3]==ccolor&&a[j][i+4]==0&&a[j][i-1]==0)//防守缺空活四連子2
					{
							a[j][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i]==0&&a[j+2][i]==ccolor&&a[j+3][i]==ccolor&&a[j+4][i]==0&&a[j-1][i]==0)
					{
							a[j+1][i]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i]==ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==ccolor&&a[j+4][i+4]==0&&a[j-1][i-1]==0)
					{
							a[j+1][i+1]=3-ccolor;
							b=-1;
							break;
					}
					else if(a[j][i+3]==ccolor&&a[j+1][i+2]==0&&a[j+2][i+1]==ccolor&&a[j+3][i]==ccolor&&a[j+4][i-1]==0&&a[j-1][i+4]==0)
					{
							a[j+1][i+2]=3-ccolor;
							b=-1;
							break;
					}
					break;
					case 9:
					if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==3-ccolor&&a[j][i+3]==0&&a[j][i-1]==0)//攻擊活三連子
					{
						if(a[j][i+3]==0&&j+3<19)
						{
							a[j][i+3]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j][i-1]==0&&i-1>=0)
						{
							a[j][i-1]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==3-ccolor&&a[j+3][i]==0&&a[j-1][i]==0)
					{
						if(a[j+3][i]==0&&j+3<19)
						{
							a[j+3][i]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i]==0&&j-1>=0)
						{
							a[j-1][i]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==3-ccolor&&a[j+3][i+3]==0&&a[j-1][i-1]==0)
					{
						if(a[j+3][i+3]==0&&j+3<19&&i+3<19)
						{
							a[j+3][i+3]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
						{
							a[j-1][i-1]=3-ccolor;
							b=-1;
							break;
						}
					}
					else if(a[j][i+2]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i]==3-ccolor&&a[j+3][i-1]==0&&a[j-1][i+3]==0)
					{	
						if(a[j+3][i-1]==0&&j+3<19&&i-1>=0)
						{
							a[j+3][i-1]=3-ccolor;
							b=-1;
							break;
						}
						else if(a[j-1][i+3]==0&&j-1<19&&i+3<19)
						{
							a[j-1][i+3]=3-ccolor;
							b=-1;
							break;
						}
					}
					break;
		case 8:
		if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==ccolor&&a[j][i+3]==0&&a[j][i-1]==0)//防守活三連子
		{
			if(a[j][i+3]==0&&i+3<19)
			{
			a[j][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j][i-1]==0&&i-1>=0)
			{
			a[j][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==ccolor&&a[j+3][i]==0&&a[j-1][i]==0)
		{
			if(a[j+3][i]==0&&j+3<19)
			{
			a[j+3][i]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i]==0&&j-1>=0)
			{
			a[j-1][i]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==0&&a[j-1][i-1]==0)
		{
			if(a[j+3][i+3]==0&&j+3<19&&i+3<19)
			{
			a[j+3][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
			{
			a[j-1][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i+2]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i]==ccolor&&a[j+3][i-1]==0&&a[j-1][i+3]==0)
		{	
			if(a[j+3][i-1]==0&&j+3<19&&i-1>=0)
			{
			a[j+3][i-1]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i+3]==0&&j-1>=0&&i+3<19)
			{
			a[j-1][i+3]=3-ccolor;
			b=-1;
			break;
			}
		}
		break;
		case 7:
		if(a[j][i]==3-ccolor&&a[j][i+1]==0&&a[j][i+2]==3-ccolor&&a[j][i+3]==0&&a[j][i-1]==0)//攻擊缺口活三連子
		{
			a[j][i+1]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i]==0&&a[j+2][i]==3-ccolor&&a[j+3][i]==0&&a[j-1][i]==0)
		{
			a[j+1][i]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==0&&a[j-1][i-1]==0)
		{
			a[j+1][i+1]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i+2]==3-ccolor&&a[j+1][i+1]==0&&a[j+2][i]==3-ccolor&&a[j+3][i-1]==0&&a[j-1][i+3]==0)
		{
			a[j+1][i+1]=3-ccolor;
			b=-1;
			break;
		}
		break;
		case 6:
		if(a[j][i]==ccolor&&a[j][i+1]==0&&a[j][i+2]==ccolor&&a[j][i+3]==0&&a[j][i-1]==0)//防守缺口活三連子
		{
			a[j][i+1]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i]==ccolor&&a[j+1][i]==0&&a[j+2][i]==ccolor&&a[j+3][i]==0&&a[j-1][i]==0)
		{
			a[j+1][i]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i]==ccolor&&a[j+1][i+1]==0&&a[j+2][i+2]==ccolor&&a[j+3][i+3]==0&&a[j-1][i-1]==0)
		{
			a[j+1][i+1]=3-ccolor;
			b=-1;
			break;
		}
		else if(a[j][i+2]==ccolor&&a[j+1][i+1]==0&&a[j+2][i]==ccolor&&a[j+3][i-1]==0&&a[j-1][i+3]==0)
		{
			a[j+1][i+1]=3-ccolor;
			b=-1;
			break;
		}
		break;
		case 5:
		if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor&&a[j][i+2]==3-ccolor)//攻擊三連子
		{
			if(a[j][i+3]==0&&i+3<19)
			{
			a[j][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j][i-1]==0&&i-1>=0)
			{
			a[j][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor&&a[j+2][i]==3-ccolor)
		{
			if(a[j+3][i]==0&&j+3<19)
			{
			a[j+3][i]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i]==0&&j-1>=0)
			{
			a[j-1][i]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i+2]==3-ccolor)
		{
			if(a[j+3][i+3]==0&&j+3<19&&i+3<19)
			{
			a[j+3][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
			{
			a[j-1][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i+2]==3-ccolor&&a[j+1][i+1]==3-ccolor&&a[j+2][i]==3-ccolor)
		{	
			if(a[j+3][i-1]==0&&j+3<19&&i-1>=0)
			{
			a[j+3][i-1]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i+3]==0&&j-1>=0&&i+3<19)
			{
			a[j-1][i+3]=3-ccolor;
			b=-1;
			break;
			}
		}
		break;
		case 4:
		if(a[j][i]==ccolor&&a[j][i+1]==ccolor&&a[j][i+2]==ccolor)//防守三連子
		{
			if(a[j][i+3]==0&&i+3<19)
			{
			a[j][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j][i-1]==0&&i-1>=0)
			{
			a[j][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i]==ccolor&&a[j+2][i]==ccolor)
		{
			if(a[j+3][i]==0&&j+3<19)
			{
			a[j+3][i]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i]==0&&j-1>=0)
			{
			a[j-1][i]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i+2]==ccolor)
		{
			if(a[j+3][i+3]==0&&j+3<19&&i+3<19)
			{
			a[j+3][i+3]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
			{
			a[j-1][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i+2]==ccolor&&a[j+1][i+1]==ccolor&&a[j+2][i]==ccolor)
		{	
			if(a[j+3][i-1]==0&&j+3<19&&i-1>=0)
			{
			a[j+3][i-1]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i+3]==0&&j-1>=0&&i+3<19)
			{
			a[j-1][i+3]=3-ccolor;
			b=-1;
			break;
			}
		}
		break;
		case 3:
		if(a[j][i]==3-ccolor&&a[j][i+1]==3-ccolor)//攻擊二連子
		{
			if(a[j][i+2]==0&&i+2<19)
			{
			a[j][i+2]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j][i-1]==0&&i-1>=0)
			{
			a[j][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i]==3-ccolor)
		{
			if(a[j+2][i]==0&&j+2<19)
			{
			a[j+2][i]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i]==0&&j-1>=0)
			{
			a[j-1][i]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==3-ccolor&&a[j+1][i+1]==3-ccolor)
		{
			if(a[j+2][i+2]==0&&j+2<19&&i+2<19)
			{
			a[j+2][i+2]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i-1]==0&&j-1>=0&&j-1>=0)
			{
			a[j-1][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i+1]==3-ccolor&&a[j+1][i]==3-ccolor)
		{
			if(a[j+2][i-1]==0&&j+2<19&&i-1>=0)
			{
			a[j+2][i-1]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i+2]==0&&j-1>=0&&i+2<19)
			{
			a[j-1][i+2]=3-ccolor;
			b=-1;
			break;
			}
		}
		break;
		case 2:
		if(a[j][i]==ccolor&&a[j][i+1]==ccolor)//防守二連子
		{
			if(a[j][i+2]==0&&i+2<19)
			{
			a[j][i+2]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j][i-1]==0&&i-1>=0)
			{
			a[j][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i]==ccolor)
		{
			if(a[j+2][i]==0&&j+2<19)
			{
			a[j+2][i]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i]==0&&j-1>=0)
			{
			a[j-1][i]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i]==ccolor&&a[j+1][i+1]==ccolor)
		{
			if(a[j+2][i+2]==0&&j+2<19&&i+2<19)
			{
			a[j+2][i+2]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i-1]==0&&j-1>=0&&i-1>=0)
			{
			a[j-1][i-1]=3-ccolor;
			b=-1;
			break;
			}
		}
		else if(a[j][i+1]==ccolor&&a[j+1][i]==ccolor)
		{
			if(a[j+2][i-1]==0&&j+2<19&&i-1>=0)
			{
			a[j+2][i-1]=3-ccolor;
			b=-1;
			break;
			}
			else if(a[j-1][i+2]==0&&j-1>=0&&i+2<19)
			{
			a[j-1][i+2]=3-ccolor;
			b=-1;
			break;
			}
		}
		break;
		case 1:
		if(a[j][i]==3-ccolor)//如果都沒以上 先攻
		{
		single(a,ran,ccolor,j,i);
		b=-1;
		break;
		}
		break;
		case 0:
		if(a[j][i]==ccolor)//如果都沒以上 先守
		{
		single(a,ran,ccolor,j,i);
		b=-1;
		break;
		}
		break;
		}
		}
		}
	}
turn=1;
}

int main()
{
	int a[19][19]={0};//預設棋盤是空的
	int x=0,y=0,c,turn,end=0,ccolor=0,f=0,ran;
	srand(time(NULL));//亂數用
	while(ccolor!=1&&ccolor!=2)//用來跑輸入失敗的回圈
		{
		cout << "玩家先下請輸入【1】，電腦先【2】:";
		cin >> turn;
		if(turn==1 || turn==2)//如果輸入正確繼續
		{
			cout <<"『玩家』要白棋子請請輸入【1】，黑棋子【2】:";
			cin >> ccolor;
			if(ccolor!=1 && ccolor!=2)//如果輸入錯誤
			cout << "『輸入錯誤！』"<<endl;
		}
		else
			cout << "『輸入錯誤！』"<<endl;
		}
		system("cls");
		for(;end==0;)//當勝利值為0繼續
		{
			ran=rand()%8;
			print(a);//印出棋盤
			switch(turn)//判斷輪誰進入該函式
			{
				case 1:
				cout <<"『玩家";
				Player(ccolor,x,y,turn,a);//玩家函式
				f=1;//判斷已經不是電腦第一步
				break;
				case 2:
				if(f==0)
				{
					first(a,ccolor,turn,ran);//電腦第一步函式
					f=1;//判斷已經不是電腦第一步
				}
				else
				AI(turn,a,ccolor,ran);//電腦函式
				break;
			}
			fwin(a,end);//尋找有沒有已經五連子
		}
	print(a);
	cout <<"遊戲結束，勝利者是";
	if(turn==2)//如果跳出迴圈且下一個輪到玩家二 就代表玩家一已勝利
		cout <<"玩家！！"<<endl;
	else if(turn==1)//如果跳出迴圈且下一個輪到玩家一 就代表玩家二已勝利
		cout <<"電腦！！"<<endl;
	system("pause");
	return 0;
}

