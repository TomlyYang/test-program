#include"reg52.h"
#include"stdio.h"
sbit DS=P0^0;//?????
sbit CLK=P0^1;//Input and RL clock
sbit ST=P0^2;//display clock
/*	TMOD=0x01;
	TH0=0xff;//timer 100us
	TL0=0xf6;
	IE=0x82;
	TR0=1;
*/

void main()
{
	DS=0;
  CLK=0;
  ST=0;
}
