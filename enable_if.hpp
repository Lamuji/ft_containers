/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:00:11 by misaev            #+#    #+#             */
/*   Updated: 2022/09/20 14:01:54 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF


namespace ft
{
    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };
}

#endif 