/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:40:15 by yachehbo          #+#    #+#             */
/*   Updated: 2022/02/20 17:03:03 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# define BUFFER_SIZE 10
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

typedef struct data
{
	char	**map;
	int		player;
	int		collect;
	int		exit;
	int		player_moves;
	int		win_h;
	int		win_w;
	void	*player_img;
	void	*floor_img;
	void	*coin_img;
	void	*wall_img;
	void	*door_img;
	void	*black_img;
	void	*mlx;
	int		img_w;
	int		img_h;
	void	*win;
	int		player_i;
	int		player_j;
	int		enemy;
	void	*enemy_img;
	int		count;
	char	derection;
	int		enemy_i;
	int		enemy_j;
	int		der;
}	t_data;
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strjoin(char *buffers, char *buff);
char	**ft_split(char	const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	**read_map(char *str);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *cp);
void	ft_putstr(char *str, int *cp);
void	ft_pointer(unsigned long n, const char *base, int *cp);
void	ft_putnbr(int n, int *cp);
void	ft_putnbr_unsigned(unsigned int n, int *cp);
void	ft_print_hex(unsigned int n, const char *base, int *cp);
void	ft_helper(const char *str, va_list args, int i, int *cp);
void	put_image(t_data *var, void *img_ptr, int x, int y);
void	game_bonus(t_data *var);
void	player_d_bonus(t_data *var);
void	player_a_bonus(t_data *var);
void	player_s_bonus(t_data *var);
void	player_w_bonus(t_data *var);
void	map_set_bonus(t_data *var, int i, int j);
int		check_map_bonus(t_data *var);
void	init_bonus(t_data *var);
char	*add_move(int k);
void	player_right_update(t_data *var);
void	player_left_update(t_data *var);
void	player_top_update(t_data *var);
void	player_bottom_update(t_data *var);
void	map_render(t_data *var, int i, int j);
int		key_hook(int code, t_data *var);
int		key_exit(void);
void	display_move(t_data *var);
void	enemy_move_l(t_data *var);
void	enemy_move_r(t_data *var);
void	enemy_update(t_data *var);
void	enemy_update_left(t_data *var);
#endif
