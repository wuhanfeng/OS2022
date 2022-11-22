#include <game.h>

struct ball_ctr ball = {
	.x = 1,
	.y = 1,
	.dx = 1,
	.dy = 1
};

// Operating system is a C program!
int main(const char *args)
{
	ioe_init();

	puts("mainargs = \"");
	puts(args); // make run mainargs=xxx
	puts("\"\n");

	// splash();

	puts("Press any key to see its key code...\n");
	int next_frame = 0, key, FPS = 60;

	while (1)
	{
		while(uptime() < next_frame);
		while ( (key = read_key()) != AM_KEY_NONE )
		{
			if(key == AM_KEY_ESCAPE) halt(0);
			printf("%d\n", key);
			kbd_event(key); // 处理键盘事件
		}
		game_progress();
		screen_update();
		next_frame += 10000000 / FPS;
		// printf("key = %d, uptime() = %d, next_frame = %d\n", key, uptime(), next_frame);
	}
	return 0;
}


void kbd_event(int key)
{
	switch (key)
	{
	case AM_KEY_LEFT:
		ball.dx = -1;
		ball.dy = 0;
		break;
	case AM_KEY_RIGHT:
		ball.dx = 1;
		ball.dy = 0;
		break;
	case AM_KEY_UP:
		ball.dx = 0;
		ball.dy = 1;
		break;
	case AM_KEY_DOWN:
		ball.dx = 0;
		ball.dy = -1;
		printf("dx = %d, dy = %d\n", ball.dx, ball.dy);
		break;	
	default:
		break;
	}

}

void game_progress()
{
	printf("dx = %d, dy = %d\n", ball.dx, ball.dy);
	ball.x += ball.dx;
	ball.y += ball.dy;
}
