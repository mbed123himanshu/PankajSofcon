#include<lpc21xx.h>
void lcd_data(unsigned char x);
void lcd_command(unsigned char x);
void delay()
{
int i=50000;
while(i--);
}
void main()
{
IODIR0=0x00000fff;
lcd_command(0x38);
lcd_command(0x06);
lcd_command(0x01);
lcd_command(0x0e);
lcd_command(0x80);
lcd_data('A');
while(1);
}
void lcd_data(unsigned char x)
{
IOSET0=x&0x000000ff;
IOSET0=0x00000500;
delay();
IOCLR0=0x00000400;
delay();
IOCLR0=0x00000fff;
}
void lcd_command(unsigned char x)
{
IOSET0=x&0x000000ff;
IOSET0=0x00000400;
delay();
IOCLR0=0x00000400;
delay();
IOCLR0=0x00000fff;
}