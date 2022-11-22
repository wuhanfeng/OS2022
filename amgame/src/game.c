#include <game.h>

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

}
