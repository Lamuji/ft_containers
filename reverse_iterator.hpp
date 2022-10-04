/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:48:34 by misaev            #+#    #+#             */
/*   Updated: 2022/10/04 11:07:15 by misaev           ###   ########.fr       */
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
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
                        
			reverse_iterator() {}
			reverse_iterator(iterator_type it) : data(it) {}
			reverse_iterator(reverse_iterator<Iterator> const & src) { *this = src; }
			reverse_iterator const & operator=(reverse_iterator<Iterator> const & rhs)
            { 
                this->data = rhs.data;
                return *this;
            }
			~reverse_iterator() {}
            iterator_type base() const
            {
                return this->data;            
            }
            
            /*OVERLOADS*/
            
            template < template < class > class It , class T>
            operator reverse_iterator< It<const T> >() const {reverse_iterator< It<const T> > temp(data); return (temp);}			
            
            reference operator*() const
            {
                Iterator tmp = data;
                return (*(--tmp));
            }
            pointer operator->() const
            {
                Iterator tmp = data;
                return (&(*(--tmp)));
            }
            reference operator[] (difference_type n)
            {
                return this->data[-n-1];
            }
            /*---------------------------------------------*/
            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp += n;
                return tmp;
            }
            reverse_iterator operator- (difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp -= n;
                return tmp;
            }
            reverse_iterator& operator+= (difference_type n)
            {
                data -= n;
                return *this;
            }
            reverse_iterator& operator-= (difference_type n)
            {
                data += n;
                return *this;
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                --this->data;
                return tmp;
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp = *this;
                ++this->data;
                return tmp;   
            }
            reverse_iterator& operator++()
            {
                --this->data;
                return *this;
            }
            reverse_iterator& operator--()
            {
                ++this->data;
                return *this;
            }
        private:
            Iterator data;
    };

    template <class A, class B>  
    bool operator==(const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() == rhs.base();  
    }
    template <class A, class B>  
    bool operator!=(const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() != rhs.base();   
    }
    template <class A, class B>  
    bool operator<(const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class A, class B>  
    bool operator>  (const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() < rhs.base();  
    }
    template <class A, class B>  
    bool operator<= (const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() >= rhs.base();      
    }
    template <class A, class B>  
    bool operator>= (const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() <= rhs.base();      
    }
    template <class Iterator>  
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it)
    {
        return (reverse_iterator<Iterator>(rev_it.base() - n));
    }
    template <class A, class B>  
    typename reverse_iterator<A>::difference_type operator- (const reverse_iterator<A>& lhs,const reverse_iterator<B>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}
#endif
