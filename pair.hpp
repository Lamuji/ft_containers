/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:09:20 by misaev            #+#    #+#             */
/*   Updated: 2022/10/14 12:06:05 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "make_pair.hpp"

namespace ft
{    
    template<class T1,class T2> 
    struct pair
    {
        typename T1 first_type;
        typename T2 second_type;
        
        first_type x;
        seconde_type y;
            
        pair(){}
        pair( const T1& x, const T2& y ) : x(x), y(y) {}
        template< class U1, class U2 >
        pair( const pair<U1, U2>& p ) 
        {
            *this = p;
        }
        operator pair<const T1, T2>() const { pair<const T1, T2> tmp(this->first, this->second); return (tmp); }
        ~pair(){}
    };
    template< class T1, class T2 >
    bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs == rhs;
    }
    template< class T1, class T2 >
    bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs != rhs;
    }
    template< class T1, class T2 >
    bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs < rhs;
    }
    template< class T1, class T2 >
    bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs <= rhs;
    }
    template< class T1, class T2 >
    bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs > rhs;
    }
    template< class T1, class T2 >
    bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
    {
        return lhs >= rhs;
    }
    
    template <class T1,class T2>
    ft::pair<T1,T2>	ft::make_pair(T1 x, T2 y);
}
