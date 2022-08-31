#include <psxcd.h>
#include "disc.h"

void init_disc()
{
    // CdInit(); should be called directly?
}

void play_track(unsigned char track)
{
	// ready
	char mode = CdlModeDA | CdlModeAP;
	CdControl(CdlSetmode, &mode, 0); // TODO check result
	// play track
    char cmd = itob(track + 2);
	CdControlF(CdlPlay, &cmd);
}
