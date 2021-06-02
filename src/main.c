/*
 *  main.c
 *  dsxtest
 *
 *  Created by Julius Parishy on 6/10/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
 
#include <dsx.h>
#include "psppower.h"
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspdisplay.h>
#include <stdio.h>
#include <pspmoduleinfo.h>
#include <psppower.h>
 
 PSP_MODULE_INFO("dsxtest", 0, 1, 1);
 
 int main()
 {
	dsxSystemInit();
	
	while(1)
	{
		dsxDrawingStart();
        unsigned short batteryLifeTime; 	   
        if (scePowerIsBatteryExist()) 
        batteryLifeTime = scePowerGetBatteryLifeTime();
        dsxDrawFontDefault(416, 18, GU_RGBA(255, 85, 85, 255),"%02dh%02dm" , batteryLifeTime/60, batteryLifeTime-(batteryLifeTime/60*60));

        unsigned short pw;
        if(scePowerIsBatteryExist())
		pw = scePowerGetBatteryLifePercent();
    	else pw = 0;
      	dsxDrawFontDefault(371, 18, GU_RGBA(255, 85, 85, 255), "%u%%", pw);
       	
   	    if(!scePowerIsBatteryExist())
		dsxDrawFontDefault(0, 15, GU_RGBA(255, 85, 85, 255), "X");
    	else
     	{
		if(scePowerIsBatteryCharging())
			dsxDrawFontDefault(0, 15, GU_RGBA(255, 85, 85, 255), "Charging");
		if(scePowerIsLowBattery())
			dsxDrawFontDefault(0, 15, GU_RGBA(255, 85, 85, 255), "Low Baterry!!!");
      	}
       	unsigned short cpu = scePowerGetCpuClockFrequency();
        	unsigned short bus = scePowerGetBusClockFrequency();
         	dsxDrawFontDefault(0, 0, GU_RGBA(255, 85, 85, 255), "%u/%u", cpu, bus);
     
     dsxDrawingEnd();    	
	}
	return 0;
}

