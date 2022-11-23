#include <am.h>
#include <amdev.h>
#include <klib.h>
#include <klib-macros.h>

void splash();
void print_key();
int read_key();
int uptime();
void kbd_event();
void game_progress();
void screen_update();
void back_ground();

struct ball_ctr
{
	int x;
	int y;
	int dx;
	int dy;
};


static inline void puts(const char *s)
{
	for (; *s; s++)
		putch(*s);
}
