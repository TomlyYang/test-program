#include"reg52.h"
unsigned char drelay[14]={0xfc,0x60,0xda,0xf2;0x66,0xb6,0xbe,0xe0,0xfe,0xf6,
	0xee,0x3e,0x1a,0x7a};//段码，显示0~d的值
unsigned char wdelay[4]={0x08;0x04;0x02;0x01};//位码
void exchange(unsigned char source,unsigned char bwsource)
{
	
}
unsigned char display(unsigned char a1,unsigned char a2,unsigned char a3,unsigned char a4)//传递预显示数
{
	
	TMOD=0x01;
	TH0=0xff;//timer 100us
	TL0=0xf6;
	IE=0x82;
	TR0=1;
bit exch;
unsigned char nexch,bwdelay,i;
i=8;
while(i--)
{
nexch=delay[a1];
bwdelay=wdelay[0];

}


	
}
