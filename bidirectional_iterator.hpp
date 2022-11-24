/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:01:42 by misaev            #+#    #+#             */
/*   Updated: 2022/11/24 22:39:45 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"
#include "node.hpp"

namespace ft
{
    template< class T>
    class bidirectional_iterator
    {
        public:
            typedef T	value_type;
            typedef ptrdiff_t	difference_type;
            typedef T	* pointer;
            typedef T	& reference;
            typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef	ft::node<value_type> *	NodePtr;
            

            bidirectional_iterator(){}
            bidirectional_iterator(T* data): _data(data){}
			bidirectional_iterator(bidirectional_iterator const & rhs) { *this = rhs; }
            pointer base() const {return _data;}
            /* OVERLOADS */ 
            operator bidirectional_iterator<const T>() const {bidirectional_iterator<const T> temp(this->data); return (temp);}			
            bidirectional_iterator &operator=(bidirectional_iterator const & rhs){if (*this != rhs){this->_data = rhs._data;}return (*this);}
            bidirectional_iterator & operator++() {_data++;return *this;}
			bidirectional_iterator operator++(int) {bidirectional_iterator tmp = *this; ++this->_data; return tmp;}
			bidirectional_iterator & operator--() {_data--;return *this;}
			bidirectional_iterator operator--(int) {bidirectional_iterator tmp = *this; --this->_data; return tmp;}
			template <class It>
			bool	operator==(It const & rhs) const {return (_data == &(*rhs));}
			template <class It>
			bool	operator!=(It const & rhs) const {return (_data != &(*rhs));}
			pointer operator->() const {return _data;}
			reference operator*() {return *_data;}
            /**/
            ~bidirectional_iterator(){}
        private:
            pointer _data;
    };
            
} // namespace ft

