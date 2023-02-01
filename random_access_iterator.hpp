/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:00:04 by misaev            #+#    #+#             */
/*   Updated: 2023/02/01 19:20:25 by ramzi            ###   ########.fr       */
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

			typedef T	value_type;
			typedef ptrdiff_t	difference_type;
			typedef T	* pointer;
			typedef T	& reference;
			typedef std::random_access_iterator_tag	iterator_category;

			/* */
			random_access_iterator(): data(NULL) {}
			random_access_iterator(T* x) : data(x) {}
			random_access_iterator(random_access_iterator const & rhs) { *this = rhs; }
			virtual ~random_access_iterator() {}

			pointer base() const {return data;}
			random_access_iterator const & operator=(random_access_iterator const & rhs) {if (this != &rhs){data = rhs.data;} return (*this);}
			
			operator random_access_iterator<const T>() const {random_access_iterator<const T> temp(this->data); return (temp);}			
			
			random_access_iterator & operator++() {data++;return *this;}
			random_access_iterator operator++(int) {random_access_iterator tmp = *this; ++this->data; return tmp;}
			random_access_iterator & operator--() {data--;return *this;}
			random_access_iterator operator--(int) {random_access_iterator tmp = *this; --this->data; return tmp;}


			/* */
			pointer operator->() const {return data;}
			reference operator*() const {return *data;}
			reference operator[] (difference_type i) const {return data[i];}
			
			random_access_iterator operator+(const difference_type & i) const { return random_access_iterator(this->data + i); }
			difference_type operator+(const random_access_iterator &right) const {return this->data + right.data;}
			random_access_iterator operator-(const difference_type & i) const { return random_access_iterator(this->data - i); }
			difference_type operator-(const random_access_iterator & right) const {return this->data - right.data;}
			random_access_iterator &operator+=(difference_type i) { data += i; return *this; }
			random_access_iterator &operator-=(difference_type i) { data -= i; return *this; }

		protected:
			pointer data;
	};
	/* */ 
	template <class A, class B>
	bool	operator==(random_access_iterator<A> const & lhs, random_access_iterator<B> const & rhs)  {return (lhs.base() == rhs.base());}
	template <class A, class B>
	bool	operator!=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() != rhs.base());}
	template <class A, class B>
	bool	operator>(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() > rhs.base());}
	template <class A, class B>
	bool	operator<(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() < rhs.base());}
	template <class A, class B>
	bool	operator>=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() >= rhs.base());}
	template <class A, class B>
	bool	operator<=(random_access_iterator<A> const & lhs,random_access_iterator<B> const & rhs)  {return (lhs.base() <= rhs.base());}
	template <typename L, typename R>
 	typename random_access_iterator<L>::difference_type operator-(const random_access_iterator<L> lhs, const random_access_iterator<R> rhs)
	{ return (&(*lhs) - &(*rhs)); }
	template <class T>
	random_access_iterator<T>	operator+(typename random_access_iterator<T>::difference_type lhs, random_access_iterator<T> const & rhs)
	{return (random_access_iterator<T>(lhs + &(*rhs)));}	
	/* =========================FIN ITERATOR========================= */
}