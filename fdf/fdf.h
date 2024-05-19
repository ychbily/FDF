/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 01:38:56 by ychbily           #+#    #+#             */
/*   Updated: 2024/03/16 22:35:27 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "includes/libft.h"
# include "includes/get_next_line.h"
# include "mlx.h"
# include "math.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_zcolor
{
	float	z;
	float	z1;
	int		color1;
	int		color2;
}	t_zcolor;

typedef struct s_dt
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_dt;

typedef struct s_dda
{
	float	dx;
	float	dy;
	int		steps;
	float	xinc;
	float	yinc;
}	t_dda;

typedef struct s_line
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
}	t_line;

typedef struct s_data
{
	int		rows;
	int		columns;
	int		**map;
	int		**color;

	double	x_teta;
	double	y_teta;
	double	z_teta;
	int		pressed;

	void	*mlx;
	void	*win;
	int		zoom;

	int		prev_mouse_x;
	int		prev_mouse_y;
	int		is_rotating;
	int		rot_x;
	int		rot_y;
	int		rot_z;
	float	**z_matrix;

	int		shift_x;
	int		shift_y;
	t_line	line;
	t_dt	img;
}	t_data;

typedef struct s_node
{
	char			*line;
	int				columns;
	struct s_node	*next;
}		t_node;

void			ft_checker(int fd, t_node *new_node,
					t_node **head, t_data *data);
void			list_init(int fd, t_node **head, t_data *data);
void			free_list(t_node *head);
void			map_handler(char *file, t_node **head, t_data *data);
void			map(t_data *data, char *file);
void			dda_algo(t_line *line, t_data *data);
void			dda_draw(t_data *data);
void			rot_x(float *y, float *z, double angle);
void			rot_y(float *x, float *z, double angle);
void			rot_z(float *x, float *y, double angle);
void			three_dim(float *x, float *y, float *z, t_data v);
float			v_abs(float a);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				closee(int keycode, t_data *data);
int				close2(t_data *data);
void			parralel_init(t_data *data);
void			close_final(t_data *data);
void			three_init(t_data *data);
int				move(int key, t_data *data);
int				mouse_press(int button, int x, int y, t_data *data);
void			render_image(t_data *data);
void			zoom_shift(t_data *data, t_line *line);
void			center_map(t_data *data);
unsigned int	get_cr(unsigned int color1, unsigned int color2, float t);
void			three_init(t_data *data);
void			parralel_init(t_data *data);
void			line_x(t_line *line, int i, int j);
void			line_y(t_line *line, int i, int j);
int				min_v(int a, int b);
void			menue(t_data *data);
void			check_file(char *file);
void			function_handler(t_data *data);
void			filling(char **tmp, int *color, int j);
void			fill_map(int *map, int *color, char *line, int columns);
void			allocate_map(t_data *data);
void			center_map1(t_data *data);
void			render_image1(t_data *data);
void			function_handler1(t_data *data);
void			three_init1(t_data *data);
void			check_file1(char *file);
void			free_mem(t_data *data);
void			draw_stars(t_data *data);
void			ft_error(char *s);
void			ft_putendl_fd(char *str, int fd);
void			mlx_handler(t_data *data);
int				handle_close(t_data *data);

#endif
