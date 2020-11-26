#include<iostream>
#include<graphics.h>
void displayMan(int x,int y)
{
    circle(x,y,10);         //face
    line(x,y+10,x,y+30);        //neck
    line(x,y+30,x-20,y+40);    //left hand
    line(x,y+30,x+20,y+40);    //right hand
    line(x+20,y+40,x+30,y+30);
    line(x,y+30,x,y+70);        //body
    line(x+30,y+30,x+30,y-100);  //umbrella
    pieslice(x+30,y-30,0,180,55);       

}

void drawCloud1(int z,int y)
{
		int r=50;

		arc(z,y,45,135,r);
		arc(z+50,y,45,135,r);
		arc(z+100,y,45,135,r);
		arc(z,y,135,225,r);
		arc(z+50,y,135+90,225+90,r);
		arc(z,y,135+90,225+90,r);
		arc(z+100,y,135+90,225+90,r);
		arc(z+100,y,315,45,r);
}

void drawCloud2(int z,int y)
{
		int r=60;

		arc(z,y,45,135,r);
		arc(z+50,y,45,135,r);
		arc(z+100,y,45,135,r);
		arc(z,y,135,225,r);
		arc(z+50,y,135+90,225+90,r);
		arc(z,y,135+90,225+90,r);
		arc(z+100,y,135+90,225+90,r);
		arc(z+100,y,315,45,r);
}
void drawCloud3(int z,int y)
{
		int r=50;

		arc(z,y,45,135,r);
		arc(z+50,y,45,135,r);
		arc(z+100,y,45,135,r);
		arc(z,y,135,225,r);
		arc(z+50,y,135+90,225+90,r);
		arc(z,y,135+90,225+90,r);
		arc(z+100,y,135+90,225+90,r);
		arc(z+100,y,315,45,r);
}


int main()
{
    int gd=DETECT, gm,i,d=0,x=50,y=340,z=50,shouldMove=1;
    int rx,ry;
    initgraph(&gd,&gm," ");
    while(true)
    {
	cleardevice();
	displayMan(x,540);

	drawCloud1(z+100,70);
	drawCloud2(z+700,150);
	drawCloud3(z+1100,100);
	
	line(0,630,10000,630);

for(i=0;i<500;i++)
        {
            rx=rand()%1550;
            ry=rand()%600;
            if(rx>=(x-40)&&rx<=(x+110))
                if(ry>=(y+60)&&ry<=600)
                    continue;
            line(rx-10,ry+10,rx,ry);
        }
 
        //legs
        //d is distance between legs
        if(shouldMove)
        {
            if(d<20)
                d+=4;
            else
                shouldMove=0;
            line(x,y+270,x-d,y+290);
            line(x,y+270,x+d,y+290);
        }
        else
        {
            if(d>0)
                d-=4;
            else
                shouldMove=1;
            line(x,y+270,x-d,y+290);
            line(x,y+270,x+d,y+290);
        }
        delay(200);
        x=(x+10)%1550;
    }
    
}