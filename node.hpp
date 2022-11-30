/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:22 by misaev            #+#    #+#             */
/*   Updated: 2022/11/30 20:17:37 by misaev           ###   ########.fr       */
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

