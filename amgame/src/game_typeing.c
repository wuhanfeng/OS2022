#include <game.h>

// int main()
// {
// 	ioe_init();
// 	video_init();

// 	panic_on(!io_read(AM_TIMER_CONFIG).present, "requires timer");
// 	panic_on(!io_read(AM_INPUT_CONFIG).present, "requires keyboard");

// 	printf("Type 'ESC' to exit\n");

// 	int current = 0, rendered = 0;
// 	while (1)
// 	{
// 		int frames = io_read(AM_TIMER_UPTIME).us / (1000000 / FPS);

// 		for (; current < frames; current++)
// 		{
// 			game_logic_update(current);
// 		}

// 		while (1)
// 		{
// 			AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
// 			if (ev.keycode == AM_KEY_NONE)
// 				break;
// 			if (ev.keydown && ev.keycode == AM_KEY_ESCAPE)
// 				halt(0);
// 			if (ev.keydown && lut[ev.keycode])
// 			{
// 				check_hit(lut[ev.keycode]);
// 			}
// 		};

// 		if (current > rendered)
// 		{
// 			render();
// 			rendered = current;
// 		}
// 	}
// }
