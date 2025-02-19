/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabesan <irabesan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:18:22 by irabesan          #+#    #+#             */
/*   Updated: 2025/02/18 13:43:00 by irabesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pxp(t_data *rt, int x, int y, int color)
{
	char	*addr;

	if ((x >= 0 && x <= rt->width) && (y >= 0 && y <= rt->height))
	{
		rt->img_data = mlx_get_data_addr(rt->img_ptr, &rt->bpp, &rt->size_line,
				&rt->endian);
		addr = rt->img_data + (y * rt->size_line + x * rt->bpp / 8);
		*(unsigned int *)addr = color;
	}
}

void	init_graph(t_data *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, rt->width, rt->height, "miniRT");
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, rt->width, rt->height);
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->near_moove);
	free_all(data);
	exit(0);
}

void	free_disk(t_plane *disk)
{
	if (disk->coord)
		free(disk->coord);
	if (disk->vector)
		free(disk->vector);
	if (disk)
		free(disk);
}
