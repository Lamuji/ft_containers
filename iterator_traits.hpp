/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:09:31 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/10 12:53:17 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

#include <iterator>

namespace ft
{

	template<typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::iterator_category iterator_category;
		typedef typename _Iterator::value_type        value_type;
		typedef typename _Iterator::difference_type   difference_type;
		typedef typename _Iterator::pointer           pointer;
		typedef typename _Iterator::reference         reference;
	};


	/// Partial specialization for pointer types.
	template<typename _Tp>
	struct iterator_traits<_Tp*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef _Tp                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef _Tp*                        pointer;
		typedef _Tp&                        reference;
	};

	/// Partial specialization for const pointer types.
	template<typename _Tp>
	struct iterator_traits<const _Tp*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef _Tp                         value_type;
		typedef ptrdiff_t                   difference_type;
		typedef const _Tp*                  pointer;
		typedef const _Tp&                  reference;
		};

	/**
	 *  This function is not a part of the C++ standard but is syntactic
	 *  sugar for internal library use only.
	 */
	template<typename _Iter>
	inline typename iterator_traits<_Iter>::iterator_category
	__iterator_category(const _Iter&)
	{ return typename iterator_traits<_Iter>::iterator_category(); }

}

#endif