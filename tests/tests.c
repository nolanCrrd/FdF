#include "../libs/MacroLibX-master/includes/mlx.h"
#include "../libs/MacroLibX-master/includes/mlx_extended.h"
#include "../includes/ft_printf.h"

// usefull struct
typedef struct
{
    mlx_context mlx;
    mlx_window win;
} mlx_t;

void update(void* param)
{
    static int i = 0;
    mlx_t* mlx = (mlx_t*)param;

    int color = 0;
    for(int j = 0; i < 400; j++)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, j, j, (mlx_color){ .rgba = 0xFF0000FF + (color << 8) });
        mlx_pixel_put(mlx->mlx, mlx->win, 399 - j, j, (mlx_color){ .rgba = 0xFF0000FF });
        color += (color < 255);
    }
    if(++i == 5000)
    {
        // here the rendering changes, the red put pixels
        // we made in the main loop are erased
        mlx_clear_window(mlx->mlx, mlx->win, (mlx_color){ .rgba = 0x000000FF });
    }
}

int main(void)
{
    mlx_t mlx;

    mlx.mlx = mlx_init();

    mlx_window_create_info info = { 0 };
    info.title = "Hello World!";
    info.width = 400;
    info.height = 400;
    mlx.win = mlx_new_window(mlx.mlx, &info);

    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            // this will be rendered until we call `mlx_clear_window`
            mlx_pixel_put(mlx.mlx, mlx.win, i, j, (mlx_color){ .rgba = 0xFF0000FF });
        }
    }

    mlx_add_loop_hook(mlx.mlx, update, &mlx);
    mlx_loop(mlx.mlx);

    mlx_destroy_window(mlx.mlx, mlx.win);
    mlx_destroy_context(mlx.mlx);
}

