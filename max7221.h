// @File		MAX7221.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		11/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef MAX7221_H
#define MAX7221_H

#include <REG51.H>               
#include <stdio.h>             

sbit MAX7221_DIN = P1^0;
sbit MAX7221_CS = P1^1;
sbit MAX7221_CLK = P1^2;

#define MAX7221_DECODEMODE 0x09
#define MAX7221_INTENSITY 0x0A
#define MAX7221_SCANLIMIT 0x0B
#define MAX7221_SHUTDOWN 0x0C
#define MAX7221_DISPLAYTEST 0x0F

static const unsigned char MAX7221_font[] =
{
	0x7e, // 0
	0x30, // 1
	0x6d, // 2
	0x79, // 3
	0x33, // 4
	0x5b, // 5
	0x5f, // 6
	0x70, // 7
	0x7f, // 8
	0x7b, // 9
	0x80, // DP
};

void MAX7221_write(unsigned char byte)
{
	unsigned char mask = 0;
	
	for(mask=0x80; mask; mask >>=1)
	{
		MAX7221_CLK = 0;
		if(byte  & mask) MAX7221_DIN = 1;  
		else MAX7221_DIN = 0;	
		MAX7221_CLK = 1;
	}
}

void MAX7221_cmd(unsigned char cmd, unsigned char value)
{
	MAX7221_CS = 0;
	MAX7221_write(cmd);
	MAX7221_write(value);	
	MAX7221_CS = 1;
}

void MAX7221_init(void)
{	
	MAX7221_CS = 1;

	MAX7221_cmd(MAX7221_SHUTDOWN, 0x01); 
	MAX7221_cmd(MAX7221_INTENSITY, 0x07);	
	MAX7221_cmd(MAX7221_DISPLAYTEST, 0x00);	
	MAX7221_cmd(MAX7221_SCANLIMIT, 0x03);
}

#endif // MAX7221_H
