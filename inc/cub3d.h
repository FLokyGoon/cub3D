/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:42:19 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:34:07 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>

# define BUFFER_SIZE 1
# define SIZE 64
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define M_PI 3.14159265358979323846
# define CHAR_SEP "01NSWE \n\0"

typedef enum e_state
{
	espace,
	mur,
	sol
}	t_state;

typedef struct s_config
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
}				t_config;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		wid;
	int		hei;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	delta_x;
	double	delta_y;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	ray_num;
	double	planex;
	double	planey;
}			t_ray;

typedef struct s_game
{
	double	angle_dir_x;
	double	angle_dir_y;
	t_img	*wall_texture_n;
	t_img	*wall_texture_s;
	t_img	*wall_texture_e;
	t_img	*wall_texture_w;
	t_img	*current_texture;
	void	*floor_texture;
	int		y_start;
	int		y_end;
	double	player_angle;
	double	planx;
	double	plany;
	char	*key;
	int		height;
	int		width;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**map;
	char	**copy_map;
	double	player_x;
	double	player_y;
	double	player_direction;
	int		len_collect;
	int		x_init;
	int		y_init;
	int		i;
	int		j;
	int		check_collect;
	int		state;
	int		init_pos;
	t_img	*img;
	t_ray	ray;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int		*floor_color;
	int		*ceiling_color;
	char	**fl_color;
	char	**ce_color;
	double	step;
	int		floor_final;
	int		ceiling_final;
	double	correct_wall_dst;
	int		file_lines_count;
	int		start_map_line;
	char	**file_copy;
	char	*f_line;
	char	*c_line;
	double	tex_pos;
	int		tex_y;
	int		tex_x;
	int		color;
}		t_game;

//---------------------------parsing-------------------------//
void	ft_check_element(t_game *game, int i, int j);
void	ft_state(t_game *game, int i, int j);
void	ft_check_map(t_game *game);
void	count_file_lines(char *fd_name, t_game *game);
void	get_file_data(char *fd_name, t_game *game);

//-----------------------parsing-1--------------------------//
void	find_map_start(t_game *game);
void	find_flags(t_game *game);
void	check_counters(int counter1, int counter2);
void	check_incs2(t_game *game);
void	check_incs1(t_game *game);

//-----------------------parsing-2--------------------------//
void	get_textures1(t_game *game);
void	get_textures2(t_game *game);
void	check_end_line(char *str);
void	remove_trailing_spaces(char *str);
void	remove_char(char *str, char target);

//-----------------------parsing-3--------------------------//
void	check_paths(t_game *game);
void	check_textures_res(t_game *game);
void	check_column(char *line, int *index, int *cols);
void	check_cols(int *cols);
void	check_col_part2_helper(char *line, int *index, int *count, int *cols);

//-----------------------parsing-4--------------------------//
void	check_col_part2(char *line);
void	check_col(t_game *game);
void	find_colors(t_game *game);
void	make_colors(t_game *game);
void	create_colors(t_game *game);

//-----------------------parsing-5--------------------------//
void	fill_colors(t_game *game);
void	check_pos(int i, int j, t_game *game);
void	check_n(t_game *game);
int		ft_get_data_map(char **argv, t_game *game);
void	ft_init_pos(t_game *game);

//-------------------------parsing_utils--------------------//
int		ft_check_name_fd(char **argv);
int		ft_check_error(int height, int width, char **map);
void	ft_check_border_map(int height, int width, char **map);
int		ft_cmp(char s1, char *s2);
void	ft_void(void);
int		ft_atoi(const char *str);
void	check_end_line(char *str);
void	move_player(t_game *game);
void	move_player_follow(t_game *game, double move_speed);
void	check_paths(t_game *game);

//----------------------------init--------------------------//
void	init_game(t_game *game);
int		ft_init(t_game *game, char **argv);
int		check_element_follow(t_game *game, int i, int j, int count);
void	check_element(t_game *game);

//---------------------------game_run------------------------//
int		run(t_game *game);
int		run_wall(t_game *game, int x, int y, double wallX);
int		run_ceiling_floor(t_game *game, int x, int y, double wallx);

//--------------------ma-------event---------------------------//
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);

//--------------------------ray_casting----------------------//
void	init_ray_casting(t_game *game);
void	first_case(t_game *game);
void	send_one_ray(t_game *game);
void	calculate_wall_height(t_game *game);

//-----------------------------sprite------------------------//
void	*ft_img(t_game *game, char *name, t_img *texture);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
int		get_texture_color(t_img *texture, int x, int y);

//-------------------------------move------------------------//
void	rotate_camera(t_game *game);
void	rotate_camera_follow(t_game *game, double old_dir_x, \
		double old_plane_x, double rot_speed);
void	move_player(t_game *game);
void	move_player_follow(t_game *game, double move_speed);
void	check_collision(t_game *game, double new_x, double new_y);

//----------------------------exit---------------------------//
int		ft_exit(t_game *game);
void	ft_exit_fail(char c);

//----------------------------cub3d--------------------------//
int		ft_height(char *fd_name, t_game *game);
int		ft_width(char *fd_name, t_game *game);
char	**ft_copy_map(char *fd_name, int height, int width, t_game *game);
char	*ft_strdup(char *s1);
void	ft_void(void);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		open_and_skip_initial_lines(char *fd_name, t_game *game);

//------------------get_next_line--------------------------//
char	*get_next_line(int fd);
int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2, int i);
char	*ft_strchr(char *s, int c);
char	*ft_bzero(char *s, size_t n);
char	*ft_deletetab(char *str);
char	*ft_save_next_line(char *str, int i);
void	*ft_calloc(size_t count, size_t size);
char	*ft_read_next_line(int fd, char *lest_str);

#endif