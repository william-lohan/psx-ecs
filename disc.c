#include <psxcd.h>
#include "disc.h"

// redo using https://github.com/ABelliqueux/nolibgs_hello_worlds/tree/main/hello_cdda example
// and https://github.com/ABelliqueux/nolibgs_hello_worlds/wiki/CDDA

void init_disc()
{
    // CdInit(); should be called directly?
}

void play_track(unsigned char track)
{
	// ready
	char mode = CdlModeDA | CdlModeAP;
	char result;
	CdControl(CdlSetmode, &mode, &result); // TODO check result
	printf( "%d error.", result );
	// play track
    char cmd = itob(track + 2);
	CdControlF(CdlPlay, &cmd);
}
