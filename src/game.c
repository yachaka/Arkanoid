/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:34:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/03 23:30:22 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			should_load_next_level(t_game *game)
{
	int			i;
	int			should;

	i = -1;
	should = 1;
	while (++i < game->map->nb_bricks)
		if (game->map->bricks[i].destructed == 0
			&& game->map->bricks[i].type != BRICK_UNDESTRUCTIBLE)
			should = 0;
	if (should == 1)
	{
		game->level += 1;
		load_level(game);
	}
}

void			no_levels(void)
{
	ft_putendl("No levels supplied.");
	exit(EXIT_SUCCESS);
}

void			win_game(t_game *game)
{
	game->run = 0;
	ft_putendl("You won!");
	ft_putstr("Your score : ");
	ft_putnbr(game->score);
	ft_putchar('\n');
}

void			lose_game(t_game *game)
{
	game->run = 0;
	ft_putendl("You lose!");
	ft_putstr("Your score : ");
	ft_putnbr(game->score);
	ft_putchar('\n');
}

void			lose_life(t_game *game)
{
	game->lives -= 1;
	if (game->lives == 0)
		lose_game(game);
	else
	{
		center_bar(game);
		spawn_ball(game);
	}
}
