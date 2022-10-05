/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:48:10 by misaev            #+#    #+#             */
/*   Updated: 2022/10/05 15:24:57 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

#include <memory>
#include <stdexcept>
#include <iterator>

namespace ft
{
    template< class T,class Allocator = std::allocator<T> >
    class vector
    {
        public :
		/* =========================DEBUT VECTOR========================= */
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::size_type size_type;
			typedef typename ft::random_access_iterator<value_type> iterator;
			typedef typename ft::random_access_iterator<const value_type> const_iterator;
			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;


			
            /* ======CONSTRUCTORS====== */
            
            vector (const allocator_type& alloc = allocator_type()) : _data(NULL), _alloc(alloc), _size(0), _capacity(0) {};

            vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0)
            {
        		assign(n, val);
            }

        	template <class InputIterator>
        	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _data(NULL) ,_alloc(alloc), _size(0), _capacity(0)
            {
   				assign(first, last);
            }

			vector (const vector& x)
			 {
				 this->_size = x._size;
                this->_capacity = x._capacity;
                this->_data = _alloc.allocate(x._capacity);
			    for (size_type i = 0; i < x.size(); i++)
				    _data[i] = x._data[i];
			 }
            vector& operator= (const vector& x)
            {
                _data = x._data;
                _alloc = x._alloc;
                _size = x._size;
                _capacity = x._capacity;
                return *this;
            }
            ~vector() {}


			/* ======END CONSTRUCTORS====== */
			
			/* ======DEBUT OPERATOR====== */
			bool operator== (const vector<T,allocator_type>& rhs) {return (_data == rhs._data);};
			bool operator!= (const vector<T,allocator_type>& rhs) {return (_data != rhs._data);};
			bool operator<  (const vector<T,allocator_type>& rhs) {return (_data < rhs._data);};
			bool operator<= (const vector<T,allocator_type>& rhs) {return (_data <= rhs._data);};
			bool operator>  (const vector<T,allocator_type>& rhs) {return (_data > rhs._data);};
			bool operator>= (const vector<T,allocator_type>& rhs) {return (_data >= rhs._data);};
			/* ======FIN OPERATOR====== */

			template<class InputIterator>  
			typename ft::iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
			{
				size_type n = 0;
				for (; first != last; first++){
					n++;
				};
				return n;
			}

            size_type size() const {return _size;}

            size_type max_size() const{  return _alloc.max_size();}

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
				if (n > _capacity)
				{
					if (n > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(n); 
					for(size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, _data[i]);
						_alloc.destroy(_data + i);
					}
					// _alloc.deallocate(_data, _capacity);	
					_capacity = n;
					_data = tmp;
				}
            }

            /* ELEMENT ACCESS */
            iterator begin(){ return iterator(_data);}
			iterator end() { return iterator(_data + _size);}

			const_iterator begin() const { return const_iterator(_data);}
			const_iterator end() const { return const_iterator(_data + _size);}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

            reference operator[] (size_type n) {return this->_data[n];}
			const_reference	operator[](size_type n) const { return(_data[n]); }

            
            reference front(){return *_data;}
            const_reference front() const{return *_data;}
			reference back() { return _data[_size - 1];}
			const_reference back() const { return _data[_size - 1];}

			reference at (size_type n)
			{
				if (n >= _size)
                    throw std::out_of_range("Element is out of range\n");
                return _data[n];
			}

			const_reference at (size_type n) const
			{
				if (n >= _size)
                    throw std::out_of_range("Element is out of range\n");
                return _data[n];
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
				size_type	n = 0;
				n = std::distance(first, last);

				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), *first++);
			}

			void assign (size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), val);
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

			void	insert(iterator position, size_type n, value_type const & val)
			{
					size_type	rsize = _capacity * 2;
					if (rsize < (_size + n))
						rsize = (_size + n);
					if (rsize > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(rsize); 
					iterator	it;
					size_type i = 0;
					for (it = begin(); it != position; it++)
						_alloc.construct(tmp + i++, *it);
					for (size_type j = 0; j < n; j++)
						_alloc.construct(tmp + i++, val);
					while (it != end())
						_alloc.construct(tmp + i++, *it++);
					for (i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_alloc.deallocate(_data, _capacity);
					_capacity = rsize;
					_size += n;
					_data = tmp;
			}

			iterator	insert(iterator position, value_type const & val)
			{
				size_type	i = 0;
				i = std::distance(begin(), position);

				insert(position, 1, val);
				return (begin() + i);

			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{
				size_type	n = std::distance(first, last);
				size_type	rsize = _capacity * 2;
				if (rsize < (_size + n))
					rsize = (_size + n);
				if (rsize > max_size())
					throw	std::length_error("vector");
				pointer	tmp = _alloc.allocate(rsize); 
				iterator	it;
				size_type i = 0;
				for (it = begin(); it != position; it++)
					_alloc.construct(tmp + i++, *it);
				while (first != last)
					_alloc.construct(tmp + i++, *first++);
				while (it != end())
					_alloc.construct(tmp + i++, *it++);
				for (i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_capacity = rsize;
				_size += n;
				_data = tmp;
			}

			iterator	erase (iterator position) { return (erase(position, position + 1)); }

			iterator	erase (iterator first, iterator last)
			{
				size_type	n = std::distance(first, last);
				iterator	it;
				for(it = first; it != last; it++)
					_alloc.destroy(&(*it));
				for(it = last; it != end(); it++)
				{
					_alloc.construct(&(*(it - n)), *it);  
					_alloc.destroy(&(*it));
				}
				_size -= n;
				return (first);
			}
			
			void swap (vector& x){

				T* tmp_data = this->_data;
				Allocator tmp_alloc = this->_alloc;
				size_type tmp_capacity = this->_capacity;
				size_type tmp_size = this->_size;

				_data = x._data;
				_alloc = x._alloc;
				_capacity = x._capacity;
				_size = x._size;

				x._data = tmp_data;
				x._alloc = tmp_alloc;
				x._capacity = tmp_capacity;
				x._size = tmp_size;
			}

			allocator_type get_allocator() const
			{
				return allocator_type();
			}
			value_type* data()
			{
				return this->_data;
			}
			const value_type* data() const
			{
				return this->_data;
			}

        private:
            pointer _data;
            allocator_type _alloc;
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

	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
	}
	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) 
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ 
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) 
	{ 
		return (rhs < lhs); 
	}
	template <class T, class Alloc>
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) 
	{ 
		return (!(lhs < rhs)); 
	}
}

#endif