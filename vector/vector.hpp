/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:46:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/16 16:19:33 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include "../enable_if.hpp"
#include "../is_integral.hpp"

namespace ft
{
    template< class T,class Allocator = std::allocator<T> >

    class vector
    {
        public :
            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::size_type size_type;
            
            /* CONSTRUCTORS */
            
            vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc) {};
            
            vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _data = _alloc.allocate(n);
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_data + i, val);
            }
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _alloc(alloc)
            {
                size_t n = std::distance(first, last);
                _data = _alloc.allocate(n);
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_data + i, *first++);
            }

            vector (const vector& x) 
            {
                _data = x._data;
                _alloc = x._alloc;
            }
            
            /* CONSTRUCTORS */

            vector& operator= (const vector& x)
            {
                _data = x._data;
                _alloc = x._alloc;
                return *this;
            }

            /* a supprimer */
            value_type* data()
            {
                return _data;
            }
            /* a supprimer */

            
            reference front()
            {
                return *_data;   
            }
            const_reference front() const
            {
                return *_data;
            }
                    
        private:
            allocator_type _alloc;
            pointer _data;
    };
}

