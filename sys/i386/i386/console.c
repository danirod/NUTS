#include <machine/platform.h>
#include <stdint.h>

#define VIDEO_BUFFER 0xb8000
#define VIDEO_COLS 80
#define VIDEO_LINES 25
#define VIDEO_SIZE (VIDEO_COLS * VIDEO_LINES)

static uint16_t *video_region = (uint16_t *) VIDEO_BUFFER;
static uint16_t video_pos = 0;

static void
consolePrintChar(char ch)
{
	// Print next character
	video_region[video_pos] = 0x0700 | ch;
	video_pos++;

	// TODO: Maybe scroll if end of screen
}

static void
consoleNextLine()
{
	video_pos = (video_pos + VIDEO_COLS) - (video_pos % VIDEO_COLS);
}

void
consolePrint(const char *str)
{
	char *ptr = (char *) str;
	while (ptr && *ptr) {
		switch (*ptr) {
		case '\n':
			consoleNextLine();
			break;
		default:
			consolePrintChar(*ptr);
			break;
		}
		ptr++;
	}
}

void
consoleClear()
{
	for (int i = 0; i < VIDEO_SIZE; i++) {
		video_region[i] = 0x0720;
	}
	video_pos = 0;
}
