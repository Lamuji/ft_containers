/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:48:34 by misaev            #+#    #+#             */
/*   Updated: 2022/09/23 18:00:10 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typename iterator_type Iterator;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            
            reverse_iterator(): data();
            
            reverse_iterator (iterator_type it)
            {
                data = Iterator(it);
            }

            template <class Iter>  
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                data = rev_it;
            }
            
            iterator_type base() const
            {
                return Iterator(data - 1);            
            }
            
        private:
            Iterator data;
    };

}


#endif
