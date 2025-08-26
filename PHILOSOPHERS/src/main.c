/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 00:03:30 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 00:00:58 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	if (data == NULL)
		return (EXIT_FAILURE);
	if (start_sim(data) == FAIL)
		return (EXIT_FAILURE);
	end_sim(data);
	return (EXIT_SUCCESS);
}
