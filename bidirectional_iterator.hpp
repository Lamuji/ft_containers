/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:01:42 by misaev            #+#    #+#             */
/*   Updated: 2022/10/17 10:36:53 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template< class T>
    class bidirectional_iterator
    {
        public:
            typedef std::bidirectional_iterator_tag	iterator_category;
            typedef T	value_type;
            typedef ptrdiff_t	difference_type;
            typedef T	* pointer;
            typedef T	& reference;
            

            bidirectional_iterator(pointer data): data(data){}
			bidirectional_iterator(bidirectional_iterator const & rhs) { *this = rhs; }
            bidirectional_iterator(){} 
            /* OVERLOADS */ 
            bidirectional_iterator &operator=(bidirectional_iterator const & rhs){if (*this != rhs){this->data == rhs.data;}return (*this);}
            bidirectional_iterator & operator++() {data++;return *this;}
			bidirectional_iterator operator++(int) {bidirectional_iterator tmp = *this; ++this->data; return tmp;}
			bidirectional_iterator & operator--() {data--;return *this;}
			bidirectional_iterator operator--(int) {bidirectional_iterator tmp = *this; --this->data; return tmp;}
			pointer operator->() const {return data;}
			reference operator*() {return *data;}
            template <class A>
        	bool	operator==(bidirectional_iterator<A> const & lhs, bidirectional_iterator<A> const & rhs)  {return (lhs.base() == rhs.base());}
	        template <class A>
	        bool	operator!=(bidirectional_iterator<A> const & lhs,bidirectional_iterator<A> const & rhs)  {return (lhs.base() != rhs.base());}
            /**/

            ~bidirectional_iterator(){}
        private:
            pointer data;
    };
            
} // namespace ft

