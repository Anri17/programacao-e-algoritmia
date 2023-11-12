#include "u_console.h"

#include <stdio.h>
#include <stdlib.h>

void console_pause()
{
	printf("Press <enter> to continue...");
	fflush(stdin);
	fgetc(stdin);
	fflush(stdin);
}

void console_clear()
{
	system("cls");
}
