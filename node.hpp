/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:16:22 by misaev            #+#    #+#             */
/*   Updated: 2022/11/28 16:50:03 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template<class T>
    struct node
    {
        T *key;
        node *parent, *left, *right;
    };
    template<class T>
    struct s_node
    {
        node<T> *addr;
        struct s_node *next;
    };// namespace ft
} // namespace ft

