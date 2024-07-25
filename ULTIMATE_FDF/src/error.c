/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:58:53 by lumaret           #+#    #+#             */
/*   Updated: 2024/07/22 00:04:02 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	isometric(&dot1.x, &dot1.y, dot1.z);
	isometric(&dot2.x, &dot2.y, dot2.z);
	//////////////////////////////////////////////// PARAMETERS /////////////////////////////////////////
	dot1.x *= data->zoom;
	dot1.y *= data->zoom;
	dot2.x *= data->zoom;
	dot2.y *= data->zoom;
	dot1.x += 250;
	dot1.y += 200;
	dot2.x += 250;
	dot2.y += 200;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	data->color = dot2.z ? 0xFFFFFF : 0xFFF000;
	//printf("\ndot1.x = %d, dot1.y = %d, dot2.x = %d, dot2.y = %d, ex = %d, ey = %d, dx = %d, dy = %d\n", dot1.x, dot1.y, dot2.x, dot2.y, ex, ey, dx, dy);
	// set_params(dot1, dot2, data); // function to set a zoom 
	//printf("\nproj-dot1.x = %d, proj-dot1.y = %d, proj-dot2.x = %d, proj-dot2.y = %d\n\n", dot1.x, dot1.y, dot2.x, dot2.y);