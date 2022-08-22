/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:42:53 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/22 21:47:01 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


#include <cstddef> // ptrdiff_t


namespace ft {
	// Base iterator struct
	template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&> 
	struct iterator 
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};
	
	// Empty class to identify the category/tag of an iterator 
	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag : public input_iterator_tag {};
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// typedef std tag, using personnal/ft tag who are juste empty struct (like above),
	// don't allow to use std iterator in function like ditance, advance...
	// This permit to use range function like: constructor, insert.. with stl iterator.
	typedef struct std::input_iterator_tag input_iterator_tag;
	typedef struct std::output_iterator_tag output_iterator_tag;
	typedef struct std::forward_iterator_tag forward_iterator_tag;
	typedef struct std::bidirectional_iterator_tag bidirectional_iterator_tag;
	typedef struct std::random_access_iterator_tag random_access_iterator_tag;

  	// Generic iterator traits definition
	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type 			value_type;
		typedef typename iterator::pointer 				pointer;
		typedef typename iterator::reference 			reference;
		typedef typename iterator::iterator_category 	iterator_category;
	};

	// T* specialization (Partial specialization for pointer types.)
	// This specialization lets you use a pointer as a random access iterator.
	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};

	// const T* specialization (Partial specialization for const pointer types.)
	// This specialization lets you use a pointer as a random access iterator.
	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t 									difference_type;
		typedef T 											value_type;
		typedef const T*									pointer;
		typedef const T&									reference;
		typedef typename ft::random_access_iterator_tag 	iterator_category;
	};
}
#endif