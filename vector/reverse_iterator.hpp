/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:42:04 by rfkaier           #+#    #+#             */
/*   Updated: 2022/09/14 18:44:29 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include "iterator_traits.hpp"

namespace ft{

	template <class Iterator> 
	
	class reverse_iterator
	{
		
		public:
			/* ===MEMBER TYPES=== */
			typename Iterator iterator_type;
			typename iterator_traits<Iterator>::iterator_category iterator_category;
			typename iterator_traits<Iterator>::value_type	value_type;
			typename iterator_traits<Iterator>::difference_type	difference_type;
			typename iterator_traits<Iterator>::pointer	pointer;
			typename iterator_traits<Iterator>::reference reference;
			/* ===FIN MEMBER TYPES=== */

			/* ===CONSTRUCTOR=== */ 
			reverse_iterator() {};
			
			reverse_iterator (iterator_type it) : _it(it) {};

			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) {*this = rev_it;};

			~reverse_iterator() {}
			/* ===FIN CONSTRUCTOR=== */ 
			
			/* ===OVERLOAD=== */
			

			
		
		private:
			Iterator _it;
	}

}

#endif 