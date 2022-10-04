/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:17:58 by misaev            #+#    #+#             */
/*   Updated: 2022/10/04 18:37:45 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

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
            stack() : c(Container()) { }
            stack( const Container& other )
            {
                c = other;
            }
            ~stack(){}
            /*=========================*/
            reference top()
            {
                return c.front();
            }
            const_reference top() const
            {
                return c.front();
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
        private:
            Container c;
        
    };

    template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs == rhs;
    }
    template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs != rhs;
    }
    template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs < rhs;
    }
    template< class T, class Container >
    bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs <= rhs;
    }
    template< class T, class Container >
    bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs <= rhs;
    }
    template< class T, class Container >
    bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs <= rhs;
    }
} // namespace ft



