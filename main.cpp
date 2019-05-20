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
void taodo_de();
void menu();
void cuong();
void hinhchunhat(int x1, int y1, int x2, int y2);
void tamgiac(int x1, int y1, int x2, int y2, int x3, int y3);
void hinhthang(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void Elipse(int x_center,int y_center,int a,int b,int color);
void put5pixel(int x,int y);
void MidPoint(int x1,int y1,int x2,int y2);
void elipMidpoint(int xc,int yc, int a, int b); // elip midpoint
void KhungThanh();
void Mid_circle(int xc, int yc, int r);//duong tron midpoint
void drawCircleMidpoint(int xc, int yc, int r);
void Bresenham_Circle(int xc, int yc, int r);
void run();
void vetoado_hinhtron(int x,int y,int r);
void doixung_diem_tam(int &x1,int &y1);
void Xuat_toa_do_Penalty(int x,int y);
void put5pixel(int x,int y)
{
	int x1,x2,y1,y2;
	x1=(x/5)*5;y1=(y/5)*5;
	x2=x1+5;y2=y1+5;
	setfillstyle(1,0);				
	bar(x1,y1,x2,y2);
}
void doi_xung_tam_giac_qua_tam(int x1, int y1, int x2, int y2, int x3, int y3)
{
	doixung_diem_tam(x1,y1);
	doixung_diem_tam(x2,y2);
	doixung_diem_tam(x3,y3);
	tamgiac(x1,y1,x2,y2,x3,y3); 	
}
void ve_chong_chong()
{
	//ve tam giac 1,3
	tamgiac(945,340,945+100,340+100,945+200,340);
	doi_xung_tam_giac_qua_tam(945,340,945+100,340+100,945+200,340);
	//ve tam giac 2,4
	tamgiac(945,340,945+100,340-100,945,340-200);
	doi_xung_tam_giac_qua_tam(945,340,945+100,340-100,945,340-200);
}

int QUAY_diem(int x,int y,int A)
{
	double x1,y1;
	x1=x*cos(A)-y*sin(A);
	y1=x*sin(A)+y*cos(A);
	x=int(x1);
	y=int(y1);
	return 1;
}
void Xuat_toa_do_Penalty(int x,int y,int r)
{
	//rectangle();
	setcolor(0);
	int x1=(x-TD5pixel_X)/5;
	int y1=(TD5pixel_Y-y)/5;
//	if (y>TD5pixel_Y) y=(TD5pixel_Y-y)/5;
//	else y=(TD5pixel_Y-y)/5;
	char s2[3]={0};
	if(x>=1000) {
			char s[4]={0};
			itoa(x1,s,10);
			outtextxy(250,350,s);
	}
	else 
	{
		outtextxy(250,350,"    ");
		char s3[3]={};
		itoa(x1,s3,10);
		outtextxy(250,350,s3);
	}
	if(y>TD5pixel_Y)
	{
		char s1[3]={0};
		itoa(y1,s1,10);
		outtextxy(350,350,"   ");
		outtextxy(350,350,s1);
	}
	else
	{
		char s4[2]={};
		itoa(y1,s4,10);
		outtextxy(350,350,s4);
	}
	itoa(r,s2,10);
	outtextxy(10,300,"Qua bong:");
	outtextxy(160,300,"Ban kinh =");
	outtextxy(350,300,s2);
	outtextxy(30,350,"Toa do Tam:");
	outtextxy(215,350,"x=");
	outtextxy(310,350,"y=");
	delay(30);
	
}
void run(int x,int y)
{
	int x0=1027,y0=517,r=15;
	drawCircleMidpoint(x0,y0,r);
	setfillstyle(1,4);
	setcolor(4);
	pieslice(1027,517,0,360,10);
	int i;
	if(x-x0>=-r && x-x0<=r) // ve thang khung thanh
	{
		 for(i=y0;i>=y;i-=5)
    	{    		
			setfillstyle(1,15);
			setcolor(15);
			pieslice(x0,i,0,360,30);
			vetoado_hinhtron(x0,i,40);		
			setcolor(0);
			drawCircleMidpoint(x0,i,r);
			setfillstyle(1,4);
			setcolor(4);
			pieslice(x0,i,0,360,10);
			Xuat_toa_do_Penalty(x0,i,r);
			delay(30);
		}
		//xoa bong trong gon
				setfillstyle(1,15);
				setcolor(15);
				pieslice(x0,i,0,360,30);
				//delay(50);
				vetoado_hinhtron(x0,i,35);	
				drawCircleMidpoint(1027,517,15);
				Xuat_toa_do_Penalty(1027,517,15);		
	}
    else
    {
    	if(x-x0<-r)
    	{    		
    		for(i=y0;i>=y;i-=5)
    		{  
    		if(x>840){
    			if(x0<x) x0=x;
    	    	else x0-=3;  
                
                	setfillstyle(1,15);
			    	setcolor(15);
			    	pieslice(x0,i,0,360,33);
			    	vetoado_hinhtron(x0,i,40);		
			    	setcolor(0);
			    	drawCircleMidpoint(x0,i,r);
		    		setfillstyle(1,4);
		    		setcolor(4);
		    		pieslice(x0,i,0,360,10);
					Xuat_toa_do_Penalty(x0,i,r);	
		    	    delay(30);
			}
			else{
				if(x0<x) x0=x0;
    	    	else x0-=7;  
                
                	setfillstyle(1,15);
			    	setcolor(15);
			    	pieslice(x0,i,0,360,33);
			    	vetoado_hinhtron(x0,i,40);		
			    	setcolor(0);
			    	drawCircleMidpoint(x0,i,r);
		    		setfillstyle(1,4);
		    		setcolor(4);
		    		pieslice(x0,i,0,360,10);
					Xuat_toa_do_Penalty(x0,i,r);	
		    	    delay(30);
			}
								
			}
			//xoa bong trong gon
				setfillstyle(1,15);
				setcolor(15);
				pieslice(x0,i,0,360,30);
				delay(50);
				vetoado_hinhtron(x0,i,35);	
				drawCircleMidpoint(1027,517,15);
				Xuat_toa_do_Penalty(1027,517,15);	
		}
		else{
			for(i=y0;i>=y;i-=5)
    		{ 
    		    if(x>1210){
    		    	if(x0>x) x0=x0;
	    	    	else x0+=7;  		
			    	setfillstyle(1,15);
			    	setcolor(15);
		    		pieslice(x0,i,0,360,30);
	    			vetoado_hinhtron(x0,i,40);		
	    			setcolor(0);
    				drawCircleMidpoint(x0,i,r);
    				setfillstyle(1,4);
    				setcolor(4);
    				pieslice(x0,i,0,360,10);
    				Xuat_toa_do_Penalty(x0,i,r);
    				delay(30);
				}
				else{
					if(x0>x) x0=x;
	    	    	else x0+=3;  		
		    		setfillstyle(1,15);
	    			setcolor(15);
	    			pieslice(x0,i,0,360,30);
	     			vetoado_hinhtron(x0,i,40);		
	    			setcolor(0);
    				drawCircleMidpoint(x0,i,r);
    				setfillstyle(1,4);
    				setcolor(4);
    				pieslice(x0,i,0,360,10);
    				Xuat_toa_do_Penalty(x0,i,r);
    				delay(30);
				}
			}
			//xoa bong trong gon
				setfillstyle(1,15);
				setcolor(15);
				pieslice(x0,i,0,360,30);
			//	delay(50);
				vetoado_hinhtron(x0,i,40);
				drawCircleMidpoint(1027,517,15);
				Xuat_toa_do_Penalty(1027,517,15);	
					
		}
	}
    
	setcolor(12);
	line(TD5pixel_X,TDGOC_Y+1,TD5pixel_X,TDCUOI_Y-1);// ve truc Ox
	line(TDGOC_X+1,TD5pixel_Y,TDCUOI_X-1,TD5pixel_Y);// ve truc Oy
}
void KhungThanh()
{
	hinhchunhat(841,132,1212,139);//xa ngang
	hinhchunhat(841,132,849,263);// cot doc trai
	hinhchunhat(1207,131,1214,262);//cot doc phai
	MidPoint(841,132,873,162);
	MidPoint(873,162,872,258);
	MidPoint(1212,130,1183,163);
	MidPoint(1183,163,1182,257);
	
}
void tinhtien_diem(int x,int y,float a,float b)
{
	int x1,y1;
	x1=x+a;
	y1=y+b;
	put5pixel(x1,y1);
}
void doixungquatruc_OX(int &x, int &y){
   	y= TD5pixel_Y - (517-TD5pixel_Y)-1;
    x=1027;
    drawCircleMidpoint(x,y,15);
    setfillstyle(1,4);
	setcolor(4);
	pieslice(x,y,0,360,10);
}
void doixungquatruc_OY(int &x, int &y){
	x= TD5pixel_X - (1027-TD5pixel_X)-1;
    y=517;
    drawCircleMidpoint(x,y,15);
    setfillstyle(1,4);
	setcolor(4);
	pieslice(x,y,0,360,10);
}
void doixung_diem_tam(int &x,int &y)
{
	x=(TD5pixel_X-1027)+TD5pixel_X-1;
	y=(TD5pixel_Y-517)+TD5pixel_Y-1;
	drawCircleMidpoint(x,y,15);
    setfillstyle(1,4);
	setcolor(4);
	pieslice(x,y,0,360,10);
}
void cuong() {
	int x, y,diem=0;
	int start=0,kt=0;
//	ve_chong_chong();
	while (1) 
	{
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			cout << x << " " << y << endl;
			if(x>=300 && x<=3850 && y>=85 && y<=115)
				{
					// xoa nhung gi co tren do thi	
					cleardevice();
					menu();	
					kt=0;
					start=0;				
				}
			else{
				if(x>=TDGOC_X && y>=TDGOC_Y)
				{
					put5pixel(x,y);				
				}
				
				if(start==1)
				{					
						run(x,y);
						KhungThanh();
						drawCircleMidpoint(1027,517,15);
						setfillstyle(1,4);
						setcolor(4);
						pieslice(1027,517,0,360,10);
				}
				if(start==2){	
					doixungquatruc_OX(x,y);
				}
				if(start==3){
					doixungquatruc_OY(x,y);
				}
				if(start==4){
					doixung_diem_tam(x,y);
				}
				// nut pennaty
				if(x>=25 && x<=210 && y>=85 && y<=115)
					{
							KhungThanh();
							//Mid_circle(1028,517,15);
							drawCircleMidpoint(1027,517,15);
							setfillstyle(1,4);
							setcolor(4);
							pieslice(1027,517,0,360,10);
							kt=1;						
					}
				// nut doi xung OY
				if(x>=25 && x<=210 && y>=165 && y<=195){
					drawCircleMidpoint(1027,517,15);
					setfillstyle(1,4);
					setcolor(4);
					pieslice(1027,517,0,360,10);
				    kt=3;
				}
				// nut doi xung OX
				if(x>=25 && x<=210 && y>=125 && y<=155){
					drawCircleMidpoint(1027,517,15);
					setfillstyle(1,4);
					setcolor(4);
					pieslice(1027,517,0,360,10);
				    kt=2;
				}
				//nut doi xung tam O
				if(x>=25 && x<=210 && y>=205 && y<=235){
					drawCircleMidpoint(1027,517,15);
					setfillstyle(1,4);
					setcolor(4);
					pieslice(1027,517,0,360,10);
				    kt=4;
			    }
				if(x>=300 && x<=385 && y>=125 && y<=155) 
					{
						if(kt==1)
						{
							start=1;
						}
						if(kt==2){
							start=2;
						}
						if(kt==3){
							start=3;
						}
						if(kt==4){
							start=4;
						}
					}
						
			}			
					
		}
		delay(0.00001);
	}
	return;
}
void vetoado_hinhtron(int x,int y,int r)
{
		setcolor(3);
		x=(x/5)*5;
		y=(y/5)*5;
	// ve doc
	for(int i=x-r;i<x+r;i+=5)
	     	{
	    		line(i,y-r,i,y+r);
	    	}
	//ve ngang
	for(int i=y-r;i<y+r;i+=5)
		{
			line(x-r,i,x+r,i);
		}
}
// toa do khung ve

int c = 3;
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

/***** VE DUONG TRON ****/
void put8pixel(int xc, int yc, int x, int y)
{
	setcolor(9);
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
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y);
    }
}

// ham pc
void pc(int xc,int yc, int x, int y){
 put5pixel(xc + x, yc + y);
 put5pixel(xc - x, yc - y);
 put5pixel(xc -y, yc +x);
 put5pixel(xc +y, yc -x);
}

// Ve duong tron voi Bresenham
void Bresenham_Circle(int xc, int yc, int r)
{
  int x, y, p;
  x = 0;
  y = r;
  p = 3 - 2 * r;
  pc(xc,yc, r,0); //ve 4 diem dac biet
  while (x < y){
   if (p < 0)
     p += 4 * x + 6;
   else{
     p += 4 * (x-y) + 10;
     y--;
   }
   x++;
   pc(xc,yc, x,y);
   pc(xc,yc, y,x);
 }
 pc(xc,yc, y,y); // ve 4 diem phan giac x=y
}

// Ve duong tron voi MidPoint
void Mid_circle(int xc, int yc, int r)
{
  int x, y, d;
  x = 0;
  y = r;
  d = 1- r;
  pc(xc,yc, r,0); //ve 4 diem dac biet
  while (x <= y)
  {
    pc(xc,yc, x,y);
    pc(xc,yc, y,x);
    if (d< 0)
       d +=2 * x + 3;
    else
   {
      d += 2 * (x-y) + 5;
      y--;
   }
   x++;
 }
 pc(xc,yc, y,y); // ve 4 diem phan giac x=y
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
			//delay(1);
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
			//delay(1);
		}
	}
} 

// ve hinh vuong
void hinhchunhat(int x1, int y1, int x2, int y2){
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
	settextstyle(0,0,2);
	setcolor(0);
	rectangle(25,85,210,115);
	setcolor(4);
	outtextxy(45,92,"Penalty");
	
	setcolor(0);
	rectangle(25,125,210,155);
	setcolor(4);
	outtextxy(30,130,"Doi Xung OX");
	
	setcolor(0);
	rectangle(25,165,210,195);
	setcolor(4);
	outtextxy(28,170,"Doi Xung OY");
	
	setcolor(0);
	rectangle(25,205,210,235);
	setcolor(4);
	outtextxy(28,210,"Doi Xung O");
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

	initwindow(1350,700);
	setbkcolor(15);
	cleardevice();
	setcolor(3);
	menu();
	cuong();
    vetoado();
	getch();
}

