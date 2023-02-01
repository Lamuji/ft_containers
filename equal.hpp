/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:45:06 by misaev            #+#    #+#             */
/*   Updated: 2023/02/01 19:19:56 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!(*first1 == *first2))
                return false;
        }
        return true;
    };
    template< class InputIt1, class InputIt2, class BinaryPredicate >
    bool equal( InputIt1 first1, InputIt1 last1,InputIt2 first2, BinaryPredicate p )
    {
        for (; first1 != last1; ++first1, ++first2) {
            if (!p(*first1, *first2)) 
            {
                return false;
            }
        }
        return true;
    };
}