/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:09:20 by misaev            #+#    #+#             */
/*   Updated: 2022/12/01 08:16:59 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{    
    template<class T1,class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        
        pair(){}
        
        pair( const T1& x, const T2& y ) : first(x), second(y) {}

        template< class U1, class U2 >
        pair( const pair<U1, U2>& p ) 
        {
            *this = p;
        }
        
        // pair & operator=( const pair& other )
        // {
        //     if (this != &other)
        //     {
        //         this->first = other.first;
        //         this->second = other.second;
        //     }
        //     return *this;
        // }
        
        // Operator de conversion
        operator pair<const T1, T2>() const 
        { 
            pair<const T1, T2> tmp(this->first, this->second); return (tmp); 
        }

        first_type first;
        second_type second;
            
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }

    template< class T1, class T2 >
    ft::pair<T1, T2> make_pair( T1 first, T2 second )
    {
        return (ft::pair<T1,T2>(first,second));
    }
}
