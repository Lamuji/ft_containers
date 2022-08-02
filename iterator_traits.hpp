/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:09:31 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/02 19:53:57 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

#include <iterator>

namespace ft
{

template <class Iterator>
struct iterator_traits
{
   typedef typename Iterator::value_type value_type;
   typedef typename Iterator::difference_type
                              difference_type;
   typedef typename Iterator::pointer pointer;
   typedef typename Iterator::reference reference;
   typedef typename Iterator::iterator_category
                              iterator_category;
};

// Specialization
template <class T>
struct iterator_traits<T*>
{
   typedef T value_type;
   typedef ptrdiff_t difference_type;
   typedef T* pointer;
   typedef T& reference;
   typedef random_access_iterator_tag iterator_category;
};

}

#endif