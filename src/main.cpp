#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/power.h> 
#include <psp2/kernel/sysmem.h> 
#include <stdio.h>
#include "debugScreen.h"


#define printf psvDebugScreenPrintf

int main(int argc, char *argv[]) {
	
	PsvDebugScreenFont *psvDebugScreenFont_default_1x;
	PsvDebugScreenFont *psvDebugScreenFont_default_2x;
	PsvDebugScreenFont *psvDebugScreenFont_previous;
	PsvDebugScreenFont *psvDebugScreenFont_current;
		
	int batteryPercentage;
	int batteryTemp;
	int batteryCycles;
	int batteryHealth;
	
	int cpuFrequency;
	int gpuFrequency;
	
	// Debug screen init
	psvDebugScreenInit();
	psvDebugScreenFont_previous = psvDebugScreenFont_default_1x = psvDebugScreenGetFont();
	psvDebugScreenFont_default_2x = psvDebugScreenScaleFont2x(psvDebugScreenFont_default_1x);
	psvDebugScreenFont_current = psvDebugScreenSetFont(psvDebugScreenFont_default_2x);	
	
	// Fetching battery info
	batteryPercentage = scePowerGetBatteryLifePercent();
	batteryTemp = scePowerGetBatteryTemp();
	batteryCycles = scePowerGetBatteryCycleCount();
	batteryHealth = scePowerGetBatterySOH();
	
	// Fetching frequency info
	cpuFrequency = scePowerGetArmClockFrequency();
	gpuFrequency = scePowerGetGpuClockFrequency();
	
	printf("Battery level:\t %d%% \n", batteryPercentage);
	printf("Battery temp:\t %dC \n", batteryTemp / 100);
	printf("Battery cycles:\t %d \n", batteryCycles);
	printf("Battery health:\t %d%% \n", batteryHealth);
	printf("\n");
	printf("CPU frequency:\t %dMHz \n", cpuFrequency);
	printf("GPU frequency:\t %dMHz \n", gpuFrequency);


	
	return sceKernelDelayThread(~0);
}
