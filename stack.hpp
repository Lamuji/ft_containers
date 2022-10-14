/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:17:58 by misaev            #+#    #+#             */
/*   Updated: 2022/10/13 17:00:32 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#pragma once

namespace ft
{
    template< class T,class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container container_type;
            typedef typename Container::value_type value_type;
            typedef typename Container::size_type size_type;
            typedef typename Container::reference reference;
            typedef typename Container::const_reference const_reference;
            /*=========================*/
           stack( const Container& cont = Container() )
           {
               c = cont;
           }
           stack( const stack& other )
           {
               c = other.c;
           }
           ~stack(){}
            /*=========================*/
            reference top()
            {
                return c.back();
            }
            const_reference top() const
            {
                return c.back();
            }
            bool empty() const
            {
                return c.empty();
            }
            size_type size() const
            {
                return c.size();
            }
            void pop()
            {
                c.pop_back();
            }
            void push(const value_type & value)
            {
                c.push_back(value);
            }
        protected:
            Container c;
            template< class A, class B >
            friend bool operator==( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
            template< class A, class B >
            friend bool operator!=( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
            template< class A, class B >
            friend bool operator<( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
            template< class A, class B >
            friend bool operator<=( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
            template< class A, class B >
            friend bool operator>( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
            template< class A, class B >
            friend bool operator>=( const ft::stack<A,B>& lhs, const ft::stack<A,B>& rhs );
    };
    template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c == rhs.c;
    }
    template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c != rhs.c;
    }
    template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c < rhs.c;
    }
    template< class T, class Container >
    bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c <= rhs.c;
    }
    template< class T, class Container >
    bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c > rhs.c;
    }
    template< class T, class Container >
    bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c >= rhs.c;
    }
} // namespace ft