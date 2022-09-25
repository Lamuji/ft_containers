/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:00:04 by misaev            #+#    #+#             */
/*   Updated: 2022/09/25 18:06:58 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
/* =========================DEBUT ITERATOR========================= */
	template< class T>
	class random_access_iterator
	{
		public:

			typedef typename ft::iterator_traits<T*>::value_type value_type;
			typedef typename ft::iterator_traits<T*>::pointer pointer;
			typedef typename ft::iterator_traits<T*>::reference reference;
			typedef typename std::random_access_iterator_tag iterator_category;
			typedef std::ptrdiff_t difference_type;

			/* */
			random_access_iterator(): data() {}
			random_access_iterator(T* x) : data(x) {}
			random_access_iterator(const random_access_iterator& rhs) : data(rhs.data) {}
			random_access_iterator& operator=(const random_access_iterator& rhs) { data = rhs.data; return *this;}
			operator random_access_iterator<const T>() const { return this->data;}			
			pointer base() const {return data;}
			~random_access_iterator() {}
			random_access_iterator& operator++() {++data;return *this;}

			random_access_iterator operator++(int) {random_access_iterator tmp(*this); operator++(); return tmp;}

			random_access_iterator& operator--() {--data;return *this;}

			random_access_iterator operator--(int) {random_access_iterator tmp(*this); operator--(); return tmp;}
			/* */
			pointer operator->() const {return data;}
			
			random_access_iterator operator+(const difference_type & i) const { return this->data + i; }
			difference_type operator+(const random_access_iterator &right) const {return this->data + right.data;}
			
			random_access_iterator operator-(const difference_type & i) const { return this->data - i; }
			difference_type operator-(const random_access_iterator & right) const {return this->data - right.data;}
			
			random_access_iterator &operator+=(difference_type i) { data += i; return *this; }
			random_access_iterator &operator-=(difference_type i) { data -= i; return *this; }
			reference operator[] (difference_type i) const {return data[i];}
			reference operator*() {return *data;}
		protected:
			pointer data;
	};
	/* */ 
	template <class T>
	bool	operator==(random_access_iterator<T> const & lhs, random_access_iterator<T> const & rhs)  {return (lhs.base() == rhs.base());}
	template <class A, class B>
	bool	operator==(random_access_iterator<A> const & lhs, random_access_iterator<B> const & rhs)  {return (lhs.base() == rhs.base());}
	template <class T>
	bool	operator!=(random_access_iterator<T> const & lhs,random_access_iterator<T> const & rhs)  {return (lhs.base() != rhs.base());}
	template <class A, class B>
	bool	operator!=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() != rhs.base());}
	template <class T>
	bool	operator>(random_access_iterator<T> const & lhs,random_access_iterator<T> const & rhs)  {return (lhs.base() > rhs.base());}
	template <class A, class B>
	bool	operator>(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() > rhs.base());}
	template <class T>
	bool	operator<(random_access_iterator<T> const & lhs,random_access_iterator<T> const & rhs)  {return (lhs.base() < rhs.base());}
	template <class A, class B>
	bool	operator<(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() < rhs.base());}
	template <class T>
	bool	operator>=(random_access_iterator<T> const & lhs,random_access_iterator<T> const & rhs)  {return (lhs.base() >= rhs.base());}
	template <class A, class B>
	bool	operator>=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() >= rhs.base());}
	template <class T>
	bool	operator<=(random_access_iterator<T> const & lhs,random_access_iterator<T> const & rhs)  {return (lhs.base() <= rhs.base());}				
	template <class A, class B>
	bool	operator<=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() <= rhs.base());}
	template <class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type const &lhs, random_access_iterator<T> const &rhs ) {return lhs + rhs.base();}
	template <class T>
	random_access_iterator<T> operator+(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs ) {return lhs.base() + rhs.base();}
	template <class T>
	random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type const &lhs, random_access_iterator<T> const &rhs ) {return lhs - rhs.base();}
	template <class T>
	random_access_iterator<T> operator-(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs ) {return lhs.base() - rhs.base();}
	/* =========================FIN ITERATOR========================= */
}