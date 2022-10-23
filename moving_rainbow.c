/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_rainbow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:43:18 by knikogho          #+#    #+#             */
/*   Updated: 2022/10/23 13:44:09 by knikogho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_list
{
	int *mlx;
	int *win;
	int y;
}				t_list;

int	render_next_frame(t_list *a)
{	
	int x;
	int y;
	int i;

	i = 0;
	y = a->y;
	while (i < 301)
	{
		x = 0;
		while (x < 901)
		{
			mlx_pixel_put ( a->mlx, a->win, x,  y % 900, 150 << 16 );
			mlx_pixel_put ( a->mlx, a->win, x,  (y + 300) % 900, 150 << 8 | 150 << 16);
			mlx_pixel_put ( a->mlx, a->win, x, (y + 600) % 900, 150 );
			x++;
		}
		y++;
		i++;
	}
	a->y += 10;	
	return 0;	
}

int	main(void)
{
	t_list a;
	a.y = 0;
	a.mlx = mlx_init();
	a.win = mlx_new_window (a.mlx, 900, 900, "Moving Rainbow");
	mlx_loop_hook(a.mlx, render_next_frame, &a);
	mlx_loop(a.mlx);
	return(0);
}