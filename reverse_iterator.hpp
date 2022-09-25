/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:48:34 by misaev            #+#    #+#             */
/*   Updated: 2022/09/26 00:12:40 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

// #include "random_access_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            
            reverse_iterator(): data(){}
            
            reverse_iterator (iterator_type it)
            {
                data = Iterator(it);
            }
            reverse_iterator operator=(reverse_iterator it)
            {
               this->data = it.data;
               return *this;
            }
            template<class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->base() = rev_it.base();
            }
            /*OVERLOADS*/
            iterator_type base() const
            {
                return data;            
            }
            reference operator*()
            {
                return *(--data);
            }
            reverse_iterator operator+ (difference_type n)
            {
                data - n;
                return *this;
            }
            reverse_iterator& operator++()
            {
                --data;
                return *this;
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp(*this);
                operator--();
                return tmp;
            }
            reverse_iterator& operator+= (difference_type n)
            {
                data -= n;
                return *this;
            }
            reverse_iterator operator- (difference_type n)
            {
                data + n;
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++data;
                return *this;
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp(*this);
                operator++();
                return tmp;   
            }
            reverse_iterator& operator-= (difference_type n)
            {
                data += n;
                return *this;
            }
            pointer operator->() const
            {
                return &(*(--data));
            }
            reference operator[] (difference_type n) const
            {
                return data[n];
            }
        private:
            Iterator data;
    };
    template <class Iterator>  
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();   
    }
    template <class Iterator>  
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() != rhs.base();   
    }
    template <class Iterator>  
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator>  
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() >= rhs.base();      
    }
    template <class Iterator>  
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() < rhs.base();  
    }
    template <class Iterator>  
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() <= rhs.base();      
    }
    template <class Iterator>  
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return n - rev_it.base(); 
    }
    template <class Iterator>  
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() - rhs.base();
    }
}
#endif
