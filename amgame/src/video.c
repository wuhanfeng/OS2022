#include <game.h>

#define SIDE 16
static int w, h;
extern struct ball_ctr ball;
static void init()
{
	AM_GPU_CONFIG_T info = {0};
	ioe_read(AM_GPU_CONFIG, &info);
	w = info.width;
	h = info.height;
}

static void draw_tile(int x, int y, int w, int h, uint32_t color)
{
	uint32_t pixels[w * h]; // WARNING: large stack-allocated memory
	AM_GPU_FBDRAW_T event = {
		.x = x,
		.y = y,
		.w = w,
		.h = h,
		.sync = 1,
		.pixels = pixels,
	};
	for (int i = 0; i < w * h; i++)
	{
		pixels[i] = color;
	}
	ioe_write(AM_GPU_FBDRAW, &event);
}

static void draw_ball(int x, int y, uint32_t color)
{
	uint32_t pixels[16 * 16]; // WARNING: large stack-allocated memory
	AM_GPU_FBDRAW_T event = {
		.x = x,
		.y = y,
		.w = 16,
		.h = 16,
		.sync = 1,
		.pixels = pixels,
	};
	memset(pixels, 0, 16*16*sizeof(int));
	for (int i = 0; i < 16 ; i ++)
	{
		for(int j = 0; j < 16; j ++)
			if( (i-8)*(i-8) + (j-8)*(j-8) < 64 )
				pixels[i*16+j] = color;
			else
				pixels[i*16+j] = 0;
	}
	ioe_write(AM_GPU_FBDRAW, &event);
}



// void splash()
// {
// 	init();
// 	printf("w = %d, h = %d\n", w, h);	
// 	for (int x = 0; x * SIDE <= 16; x++)
// 	{
// 		for (int y = 0; y * SIDE <= 16; y++)
// 		{
// 			if ((x & 1) ^ (y & 1))
// 			{
// 				// draw_tile(x * SIDE, y * SIDE, SIDE, SIDE, 0xffffff); // white
// 				draw_ball( x * SIDE, y * SIDE);
// 			}
// 		}
// 	}
// }


void screen_clear()
{
	for (int x = 0; x * SIDE <= w; x++)
	{
		for (int y = 0; y * SIDE <= h; y++)
		{
			// if ((x & 1) ^ (y & 1))
			{
				draw_tile(x * SIDE, y * SIDE, SIDE, SIDE, 0); // white
				// draw_ball( x * SIDE, y * SIDE);
			}
		}
	}
}

void screen_update()
{
	init();

	// screen_clear();
	draw_ball( ball.x-ball.dx, ball.y-ball.dy, 0 );
	draw_ball( ball.x, ball.y, 0xFFFFFF );

	// printf("screen_update\n");
	// for (int x = 0; x  <= w; x++)
	// {
	// 	for (int y = 0; y <= h; y++)
	// 	{
	// 		if (x == ball.x && y == ball.y)
	// 			// draw_tile(x * SIDE, y * SIDE, SIDE, SIDE, 0xffffff); // white
	// 			draw_ball( x, y, 0xFFFFFF );
	// 		// else
	// 			// draw_ball( x, y, 0);
	// 	}
	// }
	
}


