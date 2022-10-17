/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:29 by misaev            #+#    #+#             */
/*   Updated: 2022/10/17 18:24:38 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"
#include "bidirectional_iterator.hpp"
#include "bst_tri.hpp"
#include "pair.hpp"

namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
    class map
    {
        public:
            typedef Key key_type;
            typedef T   mapped_type;
            typedef ptrdiff_t   difference_type;
            typedef Compare key_compare;
            typedef Allocator   allocator_type;
            
            typedef typename ft::pair<const Key, T> value_type;
            typedef typename allocator_type::size_type  size_type;
            
            typedef value_type& reference;
            typedef const value_type&   const_reference;
            
            typedef typename Allocator::pointer pointer;   
            typedef typename Allocator::const_pointer   const_pointer;

            typedef typename std::reverse_iterator<iterator>    reverse_iterator;
            typedef typename std::reverse_iterator<const_iterator>  const_reverse_iterator;
            
            typedef typename ft::bidirectional_iterator<value_type> iterator;
            typedef typename ft::bidirectional_iterator<const value_type>   const_iterator;
            typedef typename ft::node<value_type> Node;

            map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()){}
            
            template <class InputIterator>
            map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            {
                for (; first != last; first++)
                {
                    
                }
            }
            
            map (const map& x)
            {
                
            }
            ~map(){}
            
        private:
            key_compare _comp;
            size_t _size;
            allocator_type _alloc;
    };
        
}