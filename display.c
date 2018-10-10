#include"reg52.h"
sbit DS=P0^0;//显示数据输出串口
sbit CLK=P0^1;//移位锁存时钟
sbit ST=P0^2;//锁存输出时钟
unsigned char drelay[14]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,
	0xee,0x3e,0x1a,0x7a};//段码，显示0~d的值
unsigned char wdrelay[4]={0x08,0x04,0x02,0x01};//位码
bit exch;
unsigned char bwdelay;
unsigned char wd;
unsigned char i1,i2,temp,wtemp;
	
void exchange(char source,char bwsource)
{
	unsigned char i3,i4;
	i3=8;
	while(i3>0)
	{
		bwsource<<1;
		DS=CY;//转串口输出
		i4=2;
		while(i4>0)
		{
			CLK=~CLK;//移位锁存时钟翻转
			i4--;
		}
			i3--;
	}
	i3=8;
	while(i3>0)
	{
		source<<1;
		DS=CY;//转串口输出
		i4=2;
		while(i4>0)
		{
			CLK=~CLK;//移位锁存时钟翻转
			i4--;
		}
		i3--;
	}
	ST=1;//触发显示
	i3=2;
	while(i3)
	{
		i3--;
	}
	ST=0;
}
unsigned char display(unsigned char a1,unsigned char a2,unsigned char a3,unsigned char a4)//传递预显示数
{
	unsigned char ssource[4];
	ssource[0]=a1;
	ssource[1]=a2;
	ssource[2]=a3;
	ssource[3]=a4;
	i1=10;
	while(i1>=0)
	{
		i2=4;
		while(i2>0)//逐位扫描
		{
			i2--;
			temp=drelay[ssource[i2]];
			wtemp=wdrelay[i2];
			exchange(temp,wtemp);
			i2--;
		}
	}

	return a1;
}
