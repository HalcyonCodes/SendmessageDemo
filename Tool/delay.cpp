#include "pch.h"
#include "delay.h"

void  delay(int   time)//time*1000ÎªÃëÊý 
{
	clock_t   now = clock();
	while (clock() - now < time);
}