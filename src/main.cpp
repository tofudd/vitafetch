#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>

#include "debugScreen.h"


#define printf psvDebugScreenPrintf

int main(int argc, char *argv[]) {
	PsvDebugScreenFont *psvDebugScreenFont_default_1x;
	PsvDebugScreenFont *psvDebugScreenFont_default_2x;
	PsvDebugScreenFont *psvDebugScreenFont_previous;
	PsvDebugScreenFont *psvDebugScreenFont_current;

	psvDebugScreenInit();
	psvDebugScreenFont_previous = psvDebugScreenFont_default_1x = psvDebugScreenGetFont();
	psvDebugScreenFont_default_2x = psvDebugScreenScaleFont2x(psvDebugScreenFont_default_1x);
	psvDebugScreenFont_current = psvDebugScreenSetFont(psvDebugScreenFont_default_2x);

	printf("VitaFetch");
	sceKernelDelayThread(3*1000000);
	sceKernelExitProcess(0);
	return 0;
}
