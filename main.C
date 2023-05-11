// @File		MAIN.C		 		
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
#include <REG51.H>               
#include <stdio.h>
#include "max7221.h"

void main (void) 
{
		P0 = 0x00;
		P1 = 0x00;
		P2 = 0x00;
	
		MAX7221_init();
	
		MAX7221_cmd(1, MAX7221_font[0]);
		MAX7221_cmd(2, MAX7221_font[1]);
		MAX7221_cmd(3, MAX7221_font[2]);
		MAX7221_cmd(4, MAX7221_font[3]);
	
		while(1)
		{
			
		}
	
}


