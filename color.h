#ifndef _COLOR_H
#define _COLOR_H

#define BLACK (Color) { 0, 0, 0 };
#define WHITE (Color) { 255, 255, 255 };
#define RED (Color) { 255, 0, 0 };
#define GREEN (Color) { 0, 255, 0 };
#define BLUE (Color) { 0, 0, 255 };
#define YELLOW (Color) { 255, 255, 0 };
#define MAGENTA (Color) { 255, 0, 255 };
#define CYAN (Color) { 0, 255, 255 };

typedef struct _color {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Color;

#endif // _COLOR_H