/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:30:50 by anurmach          #+#    #+#             */
/*   Updated: 2026/01/17 14:30:52 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WHITE 0xFFFFFF
# define ZOOM_FACTOR 20

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_pix
{
	int	x;
	int	y;
}	t_pix;

typedef struct s_couplepix
{
	t_pix	begin;
	t_pix	end;
	int		start_color;
	int		end_color;
}	t_couplepix;

typedef enum s_proj
{
	ISO,
	ORTHO,
	PERSPECTIVE
}	t_proj;

typedef struct s_data
{
	t_pix (*projection)(t_point);
	t_point	**array;
	t_proj	proj_type;
	int		view_type;
	size_t	size_x;
	size_t	size_y;
	char	*addr;
	void	*mlx;
	void	*win;
	void	*img;
	float	alpha;
	float	tetha;
	float	gamma;
	int		rot;
	int		last_rot_x;
	int		last_rot_y;
	int		bpp;
	int		line_len;
	int		endian;
	int		zoom;
	int		drag;
	int		last_x;
	int		last_y;
	int		shift_x;
	int		shift_y;
}	t_data;

typedef struct s_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_trgb;

typedef struct s_delta
{
	int				dx;
	int				dy;
	unsigned int	absdx;
	unsigned int	absdy;
	int				dir_y;
	int				dir_x;
	int				step;
}	t_delta;

/*ft_draw.c*/
void	ft_drawline(t_data	*param, t_couplepix	*couple);
void	my_pixel_put(t_data	*param, t_pix	*current,
			t_couplepix	*couple, t_delta	*d);

/*ft_initmap.c*/
char	*ft_readfile(int fd);
int		ft_checkmap(char	**array);
void	ft_initmap(t_data	*param, char	**array);

/*ft_helpers.c*/
void	ft_error(int n);
void	ft_freearray(char	**array);
void	ft_freemap(t_point	**array);
void	ft_end(t_point	**array, int n);

/**ft_helpers_extra.c*/
size_t	ft_count_x(char	*str);
size_t	ft_count_y(char	**array);
int		ft_closeprogram(t_data	*param);

/*ft_render.c*/
void	ft_initmlx(t_data	*param);
int		ft_render(t_data *param);

/*ft_events.c*/
int		key_press(int key, t_data	*param);

/*ft_mouse_events.c*/
int		mouse_drag(int x, int y, t_data	*param);
int		mouse_press(int button, int x, int y, t_data	*param);

/*ft_mouse_events_extra.c*/
int		mouse_release(int button, int x, int y, t_data	*param);
int		mouse_destroy(t_data	*param);

/*ft_projections.c*/
t_pix	ft_orthographic(t_point point);
t_pix	ft_isometric(t_point point);
t_pix	ft_perspective(t_point point);

/*ft_transform.c*/
void	ft_zoom(t_point	*point, t_data *param);
void	ft_centralize(t_pix	*pix, t_data *param);

/*ft_rotate.c*/
void	ft_rotate(t_point	*point, t_data *param);

/*ft_color.c*/
int		ft_createcolor(t_pix	*current, t_couplepix	*couple, t_delta	*d);
int		ft_setcolor(char	*str);

/*ft_extractcolor.c*/
int		get_transparent(int trgb);
int		get_red(int trgb);
int		get_green(int trgb);
int		get_blue(int trgb);

#endif