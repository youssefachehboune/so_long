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
	void	*player_w_img;
	void	*player_a_img;
	void	*player_d_img;
	void	*player_s_img;
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
}	t_data;

char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*ft_strjoin(char *buffers, char *buff);
char	**ft_split(char	const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	**read_map(char *str);
int		check_map(t_data *var);
void	init(t_data *var);
void	map_set(t_data *var);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *cp);
void	ft_putstr(char *str, int *cp);
void	ft_pointer(unsigned long n, const char *base, int *cp);
void	ft_putnbr(int n, int *cp);
void	ft_putnbr_unsigned(unsigned int n, int *cp);
void	ft_print_hex(unsigned int n, const char *base, int *cp);
void	ft_helper(const char *str, va_list args, int i, int *cp);
void	game(t_data *var);
void	player_d(t_data *var);
void	player_a(t_data *var);
void	player_s(t_data *var);
void	player_w(t_data *var);
void	put_image(t_data *var, void *img_ptr, int x, int y);
#endif
