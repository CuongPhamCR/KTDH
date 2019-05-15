#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
//#include <winbgim.h> 
#include "mylib.h"
#include "data.h"
#include <graphics.h>
#define ROUND(a) (int)(a+0.5)
using namespace std;
void DDALine(int x1,int y1,int x2,int y2,int c); // ve doan thang
void vetoado();
void menu();
void cuong();
void hinhvuong(int x1, int y1, int x2, int y2);
void tamgiac(int x1, int y1, int x2, int y2, int x3, int y3);
void hinhthang(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void Elipse(int x_center,int y_center,int a,int b,int color);
void put5pixel(int x,int y);
void MidPoint(int x1,int y1,int x2,int y2);
void drawCircleMidpoint(int xc, int yc, int r); // duong tron midpoint
void elipMidpoint(int xc,int yc, int a, int b); // elip midpoint
void put5pixel(int x,int y)
{
	int x1,x2,y1,y2;
	x1=(x/5)*5;y1=(y/5)*5;
	x2=x1+5;y2=y1+5;
	setfillstyle(1,0);				
	bar(x1,y1,x2,y2);
}
void cuong() {
	int x, y,diem=0;
	int d1x,d1y,d2x,d2y,d3x,d3y;
	int x1,y1,x2,y2,kt=0;
//	elipMidpoint(700,300, 80, 50);	
	hinhthang(1025,505,1280,505,1185,575,1095,575);
	tamgiac(1055,505,1115,400,1120,490);
	tamgiac(1115,400,1200,505,1120,490);
	MidPoint(1120,505,1115,400);
	//while (1) 
	{
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			diem++;	
			if(x>=350 && x<=420 && y>=85 && y<=115)
				{
					// xoa nhung gi co tren do thi	
					cleardevice();
					menu();
				}
			else{
				
			/*	if(diem==1)
				{
					d1x=x;
					d1y=y;
				}
				cout << x << " " << y << endl;
	//			if (kt==0) drawCircleMidpoint(d1x,d1y,20);			
	//			kt=1;
				if(x>=TDGOC_X && y>=TDGOC_Y)
				{
					put5pixel(x,y);
				}
				//ve doan thang
				if(diem==2)
				{
					d2x=x;
					d2y=y;
	//				if(d1x>TDGOC_X && x>TDGOC_X)
	//				{
	//					//DDALine(d1x,d1y,x,y,3);
	//				//	drawCircleMidpoint(x,y,40);					
	//				//	MidPoint(d1x,d1y,x,y);
	//					//Elipse(d1x,d1y,x,y,3);
	//					
	//					hinhvuong(d1x,d1y,d2x,d2y);
	//					
	//				}
				//	diem=0;
				}
				
				if(diem==3){
					d3x=x;
					d3y=y;
				//	tamgiac(d1x,d1y,d2x,d2y,x,y);
				//	diem=0;
				}
				if(diem==4){
					hinhthang(d1x,d1y,d2x,d2y,d3x,d3y,x,y);
					diem=0;
				}				
			} */	
			
			}
		delay(0.00001);
		}
	}
	return;
}
// toa do khung ve

int c = 3;
void menu();
void vetoado()
{
	setcolor(3);
	// ve doc
	for(int i=TDGOC_X+5;i<TDCUOI_X;i+=5)
	     	{
	    		line(i,TDGOC_Y+1,i,TDCUOI_Y-1);
	    	}
	//ve ngang
	for(int i=TDGOC_Y+5;i<TDCUOI_Y;i+=5)
		{
			line(TDGOC_X+1,i,TDCUOI_X,i);
		}
	setcolor(12);
	line(TD5pixel_X,TDGOC_Y+1,TD5pixel_X,TDCUOI_Y-1);// ve truc Ox
	line(TDGOC_X+1,TD5pixel_Y,TDCUOI_X-1,TD5pixel_Y);// ve truc Oy
}
void draw8point(int x,int y,int x0,int y0){ //ve 8 diem doi xung
	putpixel(x0+x,y0+y,c);
	putpixel(x0-x,y0-y,c);
	putpixel(x0+x,y0-y,c);
	putpixel(x0-x,y0+y,c);
	putpixel(x0+y,y0+x,c);
	putpixel(x0-y,y0-x,c);
	putpixel(x0+y,y0-x,c);
	putpixel(x0-y,y0+x,c);
}
void circle_bresenham(int x0,int y0,int r){ //ve duong tron
	int c;
	int x=0, y=r;
	int p=3-2*r;
	for(x;x<=y;x++){
		if(p<0){
			p+=4*x+6;
		}
		else{
			p+=4*(x-y)+10;
			y--;
		}
		draw8point(x,y,x0,y0);
	}
}

//ve duong tron mid point
void put8pixel(int xc, int yc, int x, int y)
{
	// ve tam diem doi xung
    put5pixel(x + xc, y + yc);
    put5pixel(-x + xc, y + yc);
    put5pixel(x + xc, -y + yc);
    put5pixel(-x + xc, -y + yc);
    put5pixel( y + xc, x + yc);
    put5pixel(-y + xc, x + yc);
    put5pixel(y + xc, -x + yc);
    put5pixel(-y + xc, -x + yc);
}
void drawCircleMidpoint(int xc, int yc, int r)
{
    int x = 0; int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y);
    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y-=5;
            f += ((x - y) << 1) + 5;
        }
        x+=5;
        put8pixel(xc, yc, x, y);
    }
}

// Ve duong thang midpoint
void MidPoint(int x1, int y1, int x2, int y2){
	int x, y, dX, dY, p1, p2, absdX, absdY, xE, yE;
	dX = x2 - x1;				//denta x
	dY = y2 - y1;				//denta y
	absdX = fabs(double(dX));	//lay tri tuyet doi denta x
	absdY = fabs(double(dY));	//lay tri tuyet doi denta y
	p1 = 2*absdY - absdX;
	p2 = 2*absdX - absdY;

	int xUnit, yUnit;
	float m = float(dY) / dX;

	if (m < 0) xUnit = yUnit = -1;
	else xUnit = yUnit = 1;

	if (absdY <= absdX){	//ung voi moi gia tri cua x tinh gia tri y
		if (dX >= 0) {	//diem dau(x1,y1) nam ben trai diem cuoi(x2,y2)
			x = x1;		//gan diem dau la diem nam ben trai(x1,y1)
			y = y1;
			xE = x2;	//diem cuoi la diem nam ben phai(x2,y2)
		}
		else {			//diem dau nam ben phai diem cuoi
			x = x2;		//gan diem dau la diem nam ban phai
			y = y2;
			xE = x1;
		}
		put5pixel(x,y);
		for (x; x < xE; x++) {
			if (p1 <= 0) p1 += 2*absdY;
			else {
				y += yUnit;
				p1 += (2*absdY - 2*absdX);
			}
			put5pixel(x,y);
			delay(10);
		}
	}
	else{			
		if (dY >= 0) {
			x = x1;
			y = y1;
			yE = y2;
		}
		else {
			x = x2;
			y = y2;
			yE = y1;
		}
		put5pixel(x,y);
		for (y; y < yE; y++) {
			if (p2 <= 0)	p2 += 2*absdX;
			else{
				x += xUnit;
				p2 += (2*absdX - 2*absdY);
			}
			put5pixel(x,y);
			delay(10);
		}
	}
} 

// ve hinh vuong
void hinhvuong(int x1, int y1, int x2, int y2){
	MidPoint(x1,y1,x2,y1);
	MidPoint(x1,y1,x1,y2);
	MidPoint(x2,y2,x2,y1);
	MidPoint(x2,y2,x1,y2);
}
// ve tam giac
void tamgiac(int x1, int y1, int x2, int y2, int x3, int y3){
	MidPoint(x1,y1,x2,y2);
	MidPoint(x1,y1,x3,y3);
	MidPoint(x2,y2,x3,y3);
}
// hinhthang
void hinhthang(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	MidPoint(x1,y1,x2,y2);
	MidPoint(x1,y1,x4,y4);
	MidPoint(x2,y2,x3,y3);
	MidPoint(x3,y3,x4,y4);
}
//ve elip midpoint
void plot(int xc, int yc, int x, int y)
{
    put5pixel(xc+x, yc+y);
    put5pixel(xc-x, yc+y);
    put5pixel(xc+x, yc-y);
    put5pixel(xc-x, yc-y);
}

void elipMidpoint(int xc,int yc, int a, int b)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    plot(xc, yc, x, y);
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        delay(10);
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        plot(xc, yc, x, y);
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    //
    while(y>0)
    {
        y--;
        fy -= 2*a2;
        delay(10);
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plot(xc, yc, x, y);
    }
}

void menu()
{
	setcolor(0);
	rectangle(1,0,450,685);
	rectangle(560,0,1335,685);
	settextstyle(0,0,1);
	setcolor(3);
	int k=10;
	for(int i=0;i<5;i++)
	{
		k+=20;
		outtextxy(455,k,"<<<<(())>>>>");
	}
	
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(490,170,"KY");
	outtextxy(465,270,"THUAT");
	outtextxy(490,370,"DO");
	outtextxy(480,470,"HOA");
	
	settextstyle(0,0,1);
	setcolor(3);
	k=510;
	for(int i=0;i<5;i++)
	{
		k+=20;
		outtextxy(455,k,"<<<<(())>>>>");
	}
	// tab 2D
	settextstyle(0,0,2);	
	setfillstyle(1,7);
	bar(70,10,200,60);
	outtextxy(87,25,"-+2D+-");
	//tab 3D
	settextstyle(0,0,2);	
	setfillstyle(1,7);
	bar(250,10,380,60);
	outtextxy(267,25,"-+3D+-");
	setcolor(0);
	line(2,70,450,70);
	//nut xoa
	settextstyle(0,0,2);
	setcolor(0);
	rectangle(300,85,385,115);
	setcolor(4);
	outtextxy(320,92,"Xoa");
	// toa do 2D (560,0,1339,685);
		// Hinh dieu
	settextstyle(0,0,2);
	setcolor(0);
	rectangle(25,85,210,115);
	setcolor(4);
	outtextxy(45,92,"Hinh Dieu");
		// Hinh thuyen
	setcolor(0);
	rectangle(25,125,210,155);
	setcolor(4);
	outtextxy(30,130,"Hinh Thuyen");
		//nut start
	setcolor(0);
	rectangle(300,125,385,155);
	setcolor(4);
	outtextxy(302,130,"Start");
	setcolor(0);
	line(1,250,450,250);
	line(1,280,450,280);
	outtextxy(100,255,"Toa do cac vat");
	vetoado();

}

int main(){	
//Hieu	
	initwindow(1350,700);
	setbkcolor(15);
	cleardevice();
	setcolor(3);
	menu();
	cuong();
	getch();
}

