#include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>

int zombieX = 0,zombieY = 0,zombieIndex = 0 ;				//zombie variable
int zzx=80,zzy=90;											//zombie hight width
char zombie[6][12]={"t-rex\\1.bmp","t-rex\\2.bmp","t-rex\\3.bmp","t-rex\\4.bmp","t-rex\\5.bmp","t-rex\\6.bmp"};
float s=3.5;
int jump=1;
bool zombieJump = false;
		
int tombR=5;													//tomb variable			
int tombX1=675,tombX2=900,tombX3=940;
int tombY = 51;
float tombtime=1.0;
int tx=50,ty=50;					//tomb's hight width

int score=0;										//score counting
char scoreT[100];

int over = 0;									//game up

int menu=0;

void iDraw()

{

//place your drawing codes here
	iClear();

	if(menu==0) {
		iShowBMP(0,0,"t-rex\\b.bmp");
		iShowBMP2(345,450,"t-rex\\name.bmp",0);
		iShowBMP2(350,100,"t-rex\\p.bmp",0);
		iText(300,70,"<<PRESS 'END' TO EXIT>>");

	}

	if(menu==1){
	
	iShowBMP(0,0,"t-rex\\yard.bmp");						//zombie move
		iShowBMP2(zombieX+200,zombieY+51,zombie[zombieIndex],0);
		if (zombieY + zzx + 200>= 400){
			score+=15;
			zombieJump = false;
			zombieY=0;
			
		}
	iShowBMP2(tombX1,tombY,"t-rex\\tomb.bmp",0);						//tomb moves horizontally
	iShowBMP2(tombX2,tombY,"t-rex\\tomb.bmp",0);
	iShowBMP2(tombX3,tombY,"t-rex\\tomb.bmp",0);	

	if(zombieX+200 == tombX1 && zombieY+51<=tombY) over=1;
	if(zombieX+200 == tombX2 && zombieY+51<=tombY) over=2;
	if(zombieX+200 == tombX3 && zombieY+51<=tombY) over=3;

	if(over == 1 ) iShowBMP(0,0,"t-rex\\gg.bmp");				//game over part
	if(over == 2) iShowBMP(0,0,"t-rex\\gg.bmp");
	if(over == 3) iShowBMP(0,0,"t-rex\\gg.bmp");
	

		iSetColor(0,0,90);
		iFilledRectangle(0,440,100,30);
		iSetColor(255,255,255);
		iText(10,450,"SCORE:");
		_itoa(score,scoreT,10);				//Convert integer to string
		iText(70,450,scoreT);
	}
}

void TOMB()								// animating tomb horizontally
{

	tombX1-=5;
	if(tombX1 == 0)
	{
		tombX1=800;
	}

	tombX2-=5;
	if(tombX2==0)
	{
		tombX2=800;
	}
	tombX3-=5;
	if(tombX3==0)
	{
		tombX3=800;
	}
}

void zombieMOVE()						//zombie walk
{
	zombieIndex++;
	if(zombieIndex >= 6)
	{
		zombieIndex = 0;
		
	}

	
}
void zombieUP()											//zombie jumpUP
{
	if(zombieJump)
	{
		zombieY+=s;
		jump=0;
	}

}	
void iMouseMove(int mx, int my)

{

//place your codes here

}

void iMouse(int button, int state, int mx, int my)

{

//place your codes here

}

void iKeyboard(unsigned char key)							//zombie control

{

//place your codes here
	if(key=='p') menu=1;
	
	if (key == ' '){
		zombieJump = true;
		
		}

}

void iSpecialKeyboard(unsigned char key)

{

//place your codes for other keys here
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	
}

int main()

{

//place your own initialization codes here.
	iSetTimer(100,zombieMOVE);
	iSetTimer(8,zombieUP);
	iSetTimer(tombtime,TOMB);
iInitialize(800, 600,"Zombie Jump");

return 0;

}