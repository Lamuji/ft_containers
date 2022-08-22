/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:46:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/22 23:24:45 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../enable_if.hpp"
#include "../is_integral.hpp"
//#include "../reverse_iterator.hpp"
#include <memory>
#include <stdexcept>
#include "../iterator_traits.hpp"
#include <stddef.h>

namespace ft
{
    template< class T,class Allocator = std::allocator<T> >
    class vector
    {
        public :
		class iterator
		{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef std::ptrdiff_t difference_type;

				/* */
				iterator(): data() {}
				iterator(T* x) : data(x) {}
				iterator(const iterator& rhs) : data(rhs.data) {}
				iterator& operator=(const iterator& rhs) { data = rhs.data; return *this;}
				~iterator() {}
				/* */ 
				bool operator==(const iterator& rhs) const {return data==rhs.data;}
				bool operator!=(const iterator& rhs) const {return data!=rhs.data;}
				bool operator<(const iterator &rhs) const { return data < rhs.data; }
				bool operator>(const iterator &rhs) const { return data > rhs.data; }
				bool operator<=(const iterator &rhs) const { return data <= rhs.data; }
				bool operator>=(const iterator &rhs) const { return data >= rhs.data; }
				/* */
				iterator& operator++() {++data;return *this;}
				iterator operator++(int) {iterator tmp(*this); operator--(); return tmp;}
				iterator& operator--() {--data;return *this;}
				iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
				/* */
				T operator-(const iterator &rhs) const { return data - rhs.data; }
				iterator operator+(T i) const { return iterator(data + i); }
				iterator operator-(T i) const { return iterator(data - i); }
				iterator &operator+=(T i) { data += i; return *this; }
				iterator &operator-=(T i) { data -= i; return *this; }
				iterator operator[] (size_t i) {return data[i];}
				
				T& operator*() {return *data;}
			private:
				T* data;
		};


            typedef T value_type;
            typedef Allocator allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::size_type size_type;
	
            /* CONSTRUCTORS */
            
            vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) {};
            
            vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc)
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
            	_data =	_alloc.allocate(n);
            	for (size_type i = 0; i < n; i++)
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

            iterator begin(){ return iterator(_data);}
            /* ELEMENT ACCESS */
			iterator end() { return iterator(_data + (_size - 1));}

            reference operator[] (size_type n)
			{
                if (n > _size)
                    throw std::out_of_range("Element is out of range\n");
                else
                    return this->_data[n];
            }
            
            reference front(){return *_data;}
            const_reference front() const{return *_data;}
			reference back() { return _data[_size - 1];}
			const_reference back() const { return _data[_size - 1];}

			reference at (size_type n)
			{
				if (n > _size)
                    throw std::out_of_range("Element is out of range\n");
                else
                    return this->_data[n];
			}

			const_reference at (size_type n) const
			{
				if (n > _size)
                    throw std::out_of_range("Element is out of range\n");
                else
                    return this->_data[n];
			}

			/* MODIFIERS */

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{
				size_type n = std::distance(first, last);
				if (_capacity < n){
					_alloc.deallocate(_data, _capacity);
					_data = _alloc.allocate(n);
					_capacity = n;
					_size = n;
					for(size_t i = 0; first != last; i++)
						_alloc.construct(_data + i, *first++);
				}
				else {
					for(size_t i = 0; first != last; i++)
						_alloc.destroy(_data + i);
					for(size_t i = 0; first != last; i++)
						_alloc.construct(_data + i, *first++);
					_size = n;
				}
			}

			void assign (size_type n, const value_type& val){
				if (n > _capacity){
					_alloc.deallocate(_data, _capacity);
					_data = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data + i, val);
					_capacity = n;
					_size = n;
				}
				else {
				    for (size_type i = 0 ;i < _size;i++)
                		_alloc.destroy(_data + i);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data + i, val);					
                    _size = n;
				}
			}

			void push_back (const value_type& val){
				if (_size + 1 > _capacity){
					pointer tmp = _alloc.allocate(_size + 1);
					size_type i = 0;
                    for (; i < _size; i++)
                        _alloc.construct(tmp + i, _data[i]);
                    _alloc.deallocate(_data, _capacity);
                   	_data = _alloc.allocate(_size + 1);
					for (size_type t = 0; t < _size ; t++)
                        _alloc.construct(_data + t, tmp[t]);
					_alloc.deallocate(tmp, _size + 1);
					_alloc.construct(_data + _size, val);
					_size += 1;
					_capacity += 1;
				}
				else {
					_alloc.construct(_data + _size, val);
					_size += 1;
				}
			}

			void pop_back() {
				_size -= 1;
				_alloc.destroy(_data + _size - 1);
			}

			void    insert(iterator position, size_type n, const T& x)
			{
				typename iterator::difference_type diff = position + begin();
				if (n == 0)
					return;
				if (_capacity < _size + n)
					realloc(_size + n);
				pointer tmp = _alloc.allocate(_size + n);
				for (iterator it = position; it != end(); it++){
					tmp = _alloc.construct(_data + it, _data[it]);
					_alloc.destroy(_data + it);
				}
				for (iterator it = position; it != end() + n, it++)
					_data = _alloc.construct(_data + it, x);
				for(iterator it = end(); it != end() + n, it++)
					_data = _alloc(_data + it, tmp[])
				
			}

			iterator    insert(iterator position, const T& x)
			{
				typename iterator::difference_type diff = position - begin();
				insert(begin() + diff, 1, x);
				return (begin() + diff);
			}

			template <class InputIterator>
			void    insert(iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type   pos = position - begin();
				size_type   added_size = last - first;

				if (added_size == 0)
					return;
				if (_capacity < _size + added_size)
					realloc(_size + added_size);
				for(size_type i = _size + added_size - 1; i != pos + added_size - 1; i--)
				{
					if (i < _size)
						_alloc.destroy(&(_data[i]));
					_alloc.construct(&(_data[i]), _data[i - added_size]);
				}
				for(size_type i = pos; i < pos + added_size; i++)
				{
					if (i < _size)
						_alloc.destroy(&(_data[i]));
					_alloc.construct(&(_data[i]), *(first++));
				}
				_size = _size + added_size;
			}

			iterator erase (iterator position)
			{
			
			}
			
			iterator erase (iterator first, iterator last);

        private:
            allocator_type _alloc;
            pointer _data;
            size_type _size;
            size_type _capacity;

			void	realloc(size_type n)
			{
					if ((n - _size) > _size)
					reserve(n);
				else
					reserve(_size + _size);
			}
	};
};
// template<typename T>
// std::ostream&	operator<<(std::ostream& o, ft::vector<T> const& rhs){
// }



#endif