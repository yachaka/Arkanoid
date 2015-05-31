/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 23:58:10 by ihermell          #+#    #+#             */
/*   Updated: 2015/01/21 23:58:11 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double			true_angle(double angle)
{
	if (angle < 0)
		return (true_angle(360.0 + angle));
	if (angle >= 360)
		return (true_angle(angle - 360.0));
	return (angle);
}
