/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:46:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/09/07 15:36:51 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../enable_if.hpp"
#include "../is_integral.hpp"
#include "../iterator.hpp"
#include "../iterator_traits.hpp"
#include <memory>
#include <stdexcept>

namespace ft
{
    template< class T,class Allocator = std::allocator<T> >
    class vector
    {
        public :
		class iterator : public std::random_access_iterator_tag
		{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef std::ptrdiff_t difference_type;
				typedef ft::random_access_iterator_tag iterator_category;

				/* */
				iterator(): data() {}
				iterator(T* x) : data(x) {}
				iterator(const iterator& rhs) : data(rhs.data) {}
				iterator& operator=(const iterator& rhs) { data = rhs.data; return *this;}
				~iterator() {}
				/* */ 
				template <class It>
				bool	operator==(It const & rhs) const {return (data == rhs.data);}
				template <class It>
				bool	operator!=(It const & rhs) const {return (data != rhs.data);}
				template <class It>
				bool	operator>(It const & rhs) const {return (data > rhs.data);}
				template <class It>
				bool	operator<(It const & rhs) const {return (data < rhs.data);}
				template <class It>
				bool	operator>=(It const & rhs) const {return (data >= rhs.data);}
				template <class It>
				bool	operator<=(It const & rhs) const {return (data <= rhs.data);}				
				/* */
				iterator& operator++() {++data;return *this;}

				iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
				
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
					if (n > max_size())
						throw	std::length_error("vector");
                    pointer data_tmp = _alloc.allocate(n);
                    for (size_type i = 0; i < n; i++)
                        _alloc.construct(data_tmp + i, _data[i]);
                    _alloc.deallocate(_data, _capacity);
                    _data = _alloc.allocate(n);
                    _data = data_tmp;
                    _capacity = n;
                }
            }

            iterator begin(){ return iterator(_data);}
            /* ELEMENT ACCESS */
			iterator end() { return iterator(_data + (_size));}

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

			void clear() 
			{
				for (size_type i = 0; i < _size; i++){
					_alloc.destroy(_data + i);
				}
				_size = 0;
			}

			
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

			void assign (size_type n, const value_type& val)
			{
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

			void    insert(iterator position, size_type count, const T& x)
			{
				int index = position - begin();
				size_t max_size = _size + count;

				if (count >= _capacity) {
					reserve(_capacity + count);
					_size = max_size;
				} else {
					while (_size != max_size) {
						if (_size == _capacity)
							reserve(_capacity * 2);
						_size++;
					}
				}
				for (int i = _size; i >= 0; --i) {
					if (i == index + count-1) {
						for (; count > 0; --count, --i) {
							_data[i] = x;
						}
               			 return;
          	 		}
				_data[i] = _data[i - count];
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type i = std::distance(begin(), position);
				insert(position, 1, val);

				return begin() + i;
			}

			void insert(iterator first, iterator last, const value_type& val)
			{
				
			}

			iterator erase (iterator position)
			{
				size_type t = 0;
				iterator a = begin();
				for(; a != end(); a++)
				{
					if (a == position)
						break;
					t++;
				}
				for(; t < _size; t++)
				{
					if (t == _size)
					{
						_alloc.destroy(_data + t);
						break;
					}
					_alloc.construct(_data + t, _data[t + 1]);
				}
				_size -= 1;
				return begin();
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_type i = std::distance(first, last);
				size_type t = 0;
				iterator a = begin();
				for(; a != first; a++)
				{
				}
				for(; a != last; t++)
				{
					_alloc.construct(_data + t, _data[t + 1]);
				}
				for(; t < _size; t++)
				{
					if (t == _size)
					{
						_alloc.destroy(_data + t);
						break;
					}
					_alloc.construct(_data + t, _data[t + 1]);
				}
				return begin();
			}

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
}

#endif