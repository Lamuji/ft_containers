/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:46:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/17 20:09:27 by misaev           ###   ########.fr       */
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
            
            vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) {};
            
            vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _data = _alloc.allocate(n);
                _size = n;
                _capacity = n;
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_data + i, val);
            }
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _alloc(alloc)
            {
                size_t n = std::distance(first, last);
                _size = n;
                _capacity = n;
                _data = _alloc.allocate(n);
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_data + i, *first++);
            }

            vector (const vector& x) 
            {
                _data = x._data;
                _alloc = x._alloc;
                _size = x._size;
                _capacity = x._capacity;
            }

            ~vector() { _alloc.deallocate(_data, _capacity);}

            /* CONSTRUCTORS */

            vector& operator= (const vector& x)
            {
                _data = x._data;
                _alloc = x._alloc;
                _size = x._size;
                _capacity = x._capacity;
                return *this;
            }

            size_type size() const {return _size;}

            size_type max_size() const{  return _alloc.max_size();}
            
            // _alloc.destroy et _alloc.construct modifie la _size
            // _alloc.allocate et _alloc.deallocate modifie la _capacity
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _size){
                    for (size_type i = n ;i < _size;i++)
                        _alloc.destroy(_data + i);
                    _size = n;
                }
                else if (n > _size){
                    pointer data_tmp = _alloc.allocate(n);
                    size_type i = 0;
                    for (; i < _size;i++)
                        _alloc.construct(data_tmp + i, _data[i]);
                    for (; i < n; ++i)
                        _alloc.construct(data_tmp + i, val);
                    _alloc.deallocate(_data, _capacity);
                    _data = _alloc.allocate(n);
                    for (size_type t = 0; t < n; t++)
                        _alloc.construct(_data + t, data_tmp[t]);
                    for (size_type t = 0; t < n; t++)
                        _alloc.destroy(data_tmp + t);
                    _alloc.deallocate(data_tmp, n);
                    _capacity = n;
                    _size = n;
                }
            }

            size_type capacity() const { return _capacity;}

            bool empty() const { return _size == 0? true : false;}

            void    reserve(size_type n)
            {
                if (n > _capacity){
                    pointer data_tmp = _alloc.allocate(n);
                    size_type i = 0;
                    for (; i < n; i++)
                        _alloc.construct(data_tmp + i, _data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = _alloc.allocate(n);
                    _data = data_tmp;
                    _alloc.deallocate(data_tmp, n);
                    _capacity = n;
                }
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
            size_type _size;
            size_type _capacity;
    };
}

