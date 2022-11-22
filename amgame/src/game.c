#include <game.h>

struct ball_ctr ball = {
	.x = 100,
	.y = 100
};

// Operating system is a C program!
int main(const char *args)
{
	ioe_init();

	puts("mainargs = \"");
	puts(args); // make run mainargs=xxx
	puts("\"\n");

	splash();

	puts("Press any key to see its key code...\n");
	int next_frame = 0, key, FPS = 60;

	while (1)
	{
		while(uptime() < next_frame);
		while ((key = read_key()) != AM_KEY_NONE)
		{
			if(key == AM_KEY_ESCAPE) halt(0);
			kbd_event(key); // 处理键盘事件
		}
		game_progress();
		screen_update();
		next_frame += 1000 / FPS;
	}
	return 0;
}

void game_progress()
{
	ball.x += 1;
	ball.y += 1;
}
