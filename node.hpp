/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:22 by misaev            #+#    #+#             */
/*   Updated: 2023/02/01 19:20:18 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class T>	
	struct Node
	{
		T	    * data;
		Node 	* parent;
		Node	* left;
		Node	* right;
		int	color;
	};
};

