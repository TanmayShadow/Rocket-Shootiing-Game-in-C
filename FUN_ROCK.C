#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>

int ch,s=4,i;
//int sx1=50,sx2=60,sy1=0,sy2=10;
char arr[20],shot[20],starts,help,arr1[20],arr2[20];
int x1=200,y1=350,x2=200,y2=350,i,bc1=100,bc2=150;
int y=400,x3=180,y3=390,x4=220,y4=390,k=0,bh=100,bh2=50;
int min=100,max=330,min1=101,max1=331;
int incre=2,level=50,lev=1,move=7;

void start()
{               setbkcolor(BLACK);
		setcolor(BROWN);
		bh=100;
		bh2=50;
		incre=2;
		level=50;
		lev=1;
		move=7;
		k=0;
		s=4;
		settextstyle(0,0,5);       //10
		outtextxy(100,140,"ROCKET SHOT");

		settextstyle(3,0,2);
		outtextxy(200,190,"Press s to start");
		outtextxy(200,240,"Press h to help");
		outtextxy(200,290,"Press e to exit");
}
void ghelp()
{       cleardevice();
	setcolor(MAGENTA);
	settextstyle(3,0,2);
	outtextxy(0,120,"1.Press <- (left arrow key) for moving to the left side.");
	outtextxy(0,145,"2.Press -> (right arrow key) for moving to the right side.");
	outtextxy(0,170,"3.Press F key to fire on the space objects.");
	outtextxy(0,195,"4.SHOTS  :) Number of fire shot remaining.");
	outtextxy(0,220,"5.LEVEL  :) Difficuilty level.");
	outtextxy(0,245,"6.TARGET :) Your aim. You need to get minimum target score");
	outtextxy(90,270,"to completet the level");
	outtextxy(0,295,"7.SCORE  :) Your score. Hit the middle of the object to get");
	outtextxy(90,320," high schore.");
	setcolor(RED);
	outtextxy(0,345,"TIP:) Your movement speed and the object's falling speed");
	outtextxy(40,370,"increases when difficuilty level goes increased");
	getch();
}
void loading()
{
	cleardevice();
	outtextxy(200,120,"LOADING");
	for(i=150;i<350;i++)
	{
		putpixel(i,150,WHITE);
		delay(20);
	}
}

void rocket()
{
	setcolor(6);
	setfillstyle(SOLID_FILL,6);
	line(x1,y1,x3,y3);   //left
	line(x2,y2,x4,y4);   //right
	line(x3,y3,x4,y4);   //base
	floodfill(x1+1,y3-1,6);

	setcolor(62);
	setfillstyle(SOLID_FILL, 62);
	rectangle(x3,y3,x4,y4+40);
	floodfill(x3+1,y3+1,62);

	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	line(x3+5,y4+40,x4-5,y4+40);
	line(x3+5,y4+40,x3+5,y4+50);
	line(x4-5,y4+40,x4-5,y4+50);
	line(x3+5,y4+50,x3+10,y4+60);
	line(x4-5,y4+50,x4-10,y4+60);
	line(x3+10,y4+60,x3+10,y4+65);
	line(x4-10,y4+60,x4-10,y4+65);
	line(x3+10,y4+65,x3+20,y4+75);
	line(x4-10,y4+65,x4-20,y4+75);
	floodfill(x3+6,y4+41,RED);

	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	rectangle(x3-30,y3+10,x3,y3+30);
	floodfill(x3-29,y3+11, 8);

	setcolor(7);
	setfillstyle(SOLID_FILL, 7);
	rectangle(x3-25,y3+30,x3-5,y3+40);
	floodfill(x3-24,y3+31, 7);

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	line(x3-20,y3+40,x3-10,y3+40);
	line(x3-20,y3+40,x3-20,y3+50);
	line(x3-10,y3+40,x3-10,y3+50);
	line(x3-10,y3+50,x3-15,y3+55);
	line(x3-20,y3+50,x3-15,y3+55);
	floodfill(x3-19,y3+41,RED);

	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	rectangle(x4+30,y4+10,x4,y4+30);
	floodfill(x4+29,y4+11,8);

	setcolor(7);
	setfillstyle(SOLID_FILL,7);
	rectangle(x4+25,y4+30,x4+5,y4+40);
	floodfill(x4+6,y4+31,7);

	setcolor(RED);
	setfillstyle(SOLID_FILL,RED);
	line(x4+20,y4+40,x4+10,y4+40);
	line(x4+20,y4+40,x4+20,y4+50);
	line(x4+10,y4+40,x4+10,y4+50);
	line(x4+10,y4+50,x4+15,y4+55);
	line(x4+20,y4+50,x4+15,y4+55);
	floodfill(x4+11,y4+41,RED);
}

void target(int bc1,int bh)
{       setcolor(3);
	setfillstyle(WIDE_DOT_FILL,3);
	circle(bc1,bh,20);      //200 200
	floodfill(bc1+1,bh+1,3);
	setcolor(WHITE);
	line(bc1+20,bh,bc1+35,bh);
	line(bc1-20,bh,bc1-35,bh);
	line(bc1,bh+20,bc1,bh+35);
	line(bc1,bh-20,bc1,bh-35);
}
void target2(int bc2,int bh2)
{       setcolor(10);
	setfillstyle(HATCH_FILL,10);
	circle(bc2,bh2,20);
	floodfill(bc2+1,bh2+1,10);

	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(bc2+25,bh2,5);
	floodfill(bc2+26,bh2+1,YELLOW);

	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(bc2-25,bh2,5);
	floodfill(bc2-24,bh2+1,YELLOW);

	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(bc2,bh2+25,5);
	floodfill(bc2+1,bh2+26,YELLOW);

	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(bc2,bh2-25,5);
	floodfill(bc2+1,bh2-24,YELLOW);
}
void crst(int xx1,int xx2,int yy1,int yy2)
{       setcolor(WHITE);
	line(xx1,yy1+5,xx2,yy1+5);//xx1=50,xx2=60,yy1=0,yy2=10
	line(xx1+5,yy1,xx1+5,yy2);
	line(xx1,yy1,xx2,yy2);
	line(xx2,yy1,xx1,yy2);
}
void stars()
{        int sx1=50,sx2=60,sy1=0,sy2=10;
	// xmin=50,	xmax=350
	//ymin=0,	ymax=400
	crst(sx1+10,sx2+10,sy1+10,sy2+10);
	crst(sx1+20,sx2+20,sy1+30,sy2+30);
	crst(sx1+30,sx2+30,sy1+40,sy2+40);
	crst(sx1+60,sx2+60,sy1+30,sy2+30);
	crst(sx1+250,sx2+250,sy1+30,sy2+30);
	crst(sx1+200,sx2+200,sy1+60,sy2+60);
	crst(sx1+230,sx2+230,sy1+200,sy2+200);
	crst(sx1+100,sx2+100,sy1+80,sy2+80);
	crst(sx1+20,sx2+20,sy1+330,sy2+330);
	crst(sx1+50,sx2+50,sy1+300,sy2+300);
	crst(sx1+20,sx2+20,sy1+200,sy2+200);
	crst(sx1+200,sx2+200,sy1+230,sy2+230);
	crst(sx1+150,sx2+150,sy1+180,sy2+180);
	crst(sx1+20,sx2+20,sy1+30,sy2+30);
	crst(sx1+100,sx2+100,sy1+120,sy2+120);
	crst(sx1+50,sx2+50,sy1+300,sy2+300);
	crst(sx1+70,sx2+70,sy1+340,sy2+340);
	crst(sx1+280,sx2+280,sy1+320,sy2+320);
	crst(sx1+250,sx2+250,sy1+380,sy2+380);
	crst(sx1+180,sx2+180,sy1+270,sy2+270);
}

void main()
{
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\Turboc3\\BGI");
	detectgraph(&gd,&gm);
	bc1=(rand()%(max-min+1))+min;
	bc2=(rand()%(max1-min1+1))+min1;
	do
	{
	cleardevice();
	start();
	starts=getch();
	if(starts=='e')
		exit(0);
	else if(starts=='s')
	{
	loading();
	settextstyle(1,0,3);
	while(1)
	{       cleardevice();
		stars();
		setcolor(WHITE);
	   /*	line(50,20,50,400);
		line(350,20,350,400);   */
		line(50,0,50,400);
		line(350,0,350,400);


		setcolor(52);
		setfillstyle(SOLID_FILL,BLACK);
		rectangle(50,0,350,470);
		rectangle(350,0,650,470);
		floodfill(51,351,52);//52

		sprintf(arr2,"LEVEL = %d",lev);
		outtextxy(450,60,arr2);
		sprintf(arr,"SCORE = %d",k);
		outtextxy(450,100,arr);
		sprintf(shot,"SHOTS = %d",s);
		outtextxy(450,120,shot);
		sprintf(arr1,"TARGET = %d",level);
		outtextxy(450,80,arr1);
		rocket();
		y=y1;
		target(bc1,bh);
		target2(bc2,bh2);
	if(kbhit())
	{
		ch=getch();
		if(ch=='e')
			break;
		else if(ch=='f')
			{ s--;
			  if(s>=0)
			  {
				for(i=0;i<100;i=i+10)
				{ cleardevice();

				  target(bc1,bh);
				  target2(bc2,bh2);
				  rocket();

				  line(x1,y,x2,y-20);//bullet x=200,y=390
				// cleardevice();

				y=y-20;

				delay(100);
				}
				if(x1>bc1-30&&x1<bc1+30)
				{

					cleardevice();
					if(x1>=bc1-30&&x1<=bc1-20||x1<=bc1+30&&x1>=bc1+20)
					{	k=k+5;
						outtextxy(300,200,"5 points");
					}
					else if(x1>=bc1-20&&x1<=bc1-10||x1<=bc1+20&&x1>=bc1+10)
					{	k=k+10;
						outtextxy(300,200,"10 points");
					}
					else if(x1>bc1-10&&x1<bc1||x1>bc1&&x1<bc1+10||x1==bc1)
					{	k=k+20;
						outtextxy(300,200,"15 points");
					}
					delay(30);
					goto label;

				}
				else if(x1>bc2-20&&x1<bc2+20)
				{       	cleardevice();
					if(x1>=bc2-30&&x1<=bc2-20||x1<=bc2+30&&x1>=bc2+20)
					{k=k+5;
					outtextxy(300,200,"5 points");
					}
					else if(x1>=bc2-20&&x1<=bc2-10||x1<=bc2+20&&x1>=bc2+10)
					{	k=k+10;
						outtextxy(300,200,"10 points");
					}
					else if(x1>bc2-10&&x1<bc2||x1>bc2&&x1<bc2+10||x1==bc2)
					{	k=k+20;
						outtextxy(300,200,"15 points");
					}
					delay(100);
					goto key;
				}

			  }
			  else if(s<0)
				{outtextxy(200,200,"no more shots remaining");
					if(k>=level)
					{       cleardevice();
						s=5;
						incre=incre+3;
						level=level+10;
						k=0;
						lev++;
						outtextxy(300,300,"LEVEL INCREASED");
					       //	outtextxy(280,320,"FOR CONTIUNE PRESS ANY KEY");
						//getch();
						if(k>level+20)
						{
						    move=move+2;
						}
						delay(200);
					}
					else if(k<level)
					{       cleardevice();

						outtextxy(300,300,arr2);
						getch();
						delay(200);
						break;
					}


				}
			}
		else if(ch==77)       //right
		{
			if(x4>=340)
			{
				x1=x1+0;
				x2=x2+0;
				x3=x3+0;
				x4=x4+0;
			}
			else
			{
				x1=x1+move;
				x2=x2+move;
				x3=x3+move;
				x4=x4+move;
			}
		}
		else if(ch==75)		//left
		{
			if(x3<=50)
			{
				x1=x1-0;
				x2=x2-0;
				x3=x3-0;
				x4=x4-0;
			}
			else
			{
				x1=x1-move;
				x2=x2-move;
				x3=x3-move;
				x4=x4-move;
			}
		}
		else if(ch=='e')
			break;


		delay(10);
	}
		if(bh<=400||bh2<=400)
		{
			bh=bh+incre;
			bh2=bh2+incre+1;
		}
		else if(bh>400||bh2>400)
		{
			if(k>=50)
			{
				cleardevice();
				outtextxy(200,200,"YOU WIN");

				delay(50);
				break;
			}
			else if(k<50)
			{
				cleardevice();
				outtextxy(200,200,"YOU LOST");

				delay(50);
				break;
			}
		}
		else
		{       label:
			srand(time(NULL));
			bc1=(rand()%(max-min+1))+min;
			key:
			bc2=(rand()%(max1-min1+1))+min1;
			bh=100;
			bh2=50;
		}

	delay(100);
	}
	}
	else if(starts=='h'||starts=='H')
		ghelp();
	}while(starts!='e'||starts!='E');
	getch();
	closegraph();

}