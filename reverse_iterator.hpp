/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:48:34 by misaev            #+#    #+#             */
/*   Updated: 2022/09/30 18:52:49 by misaev           ###   ########.fr       */
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
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            
            reverse_iterator(): data(){}
            
            reverse_iterator (iterator_type it)
            {
                Iterator toto = it;
                data = it;
            }
            reverse_iterator &operator=(const reverse_iterator<Iterator> &it)
            {
               this->data = it.base();
               return *this;
            }
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->base() = rev_it.base();
            }
            
			template < class It , class T>
			operator reverse_iterator<const T>() const 
            {
                reverse_iterator<const T > temp(data); 
                return (temp);
            }
			

            /*OVERLOADS*/
            iterator_type base() const
            {
                return data;            
            }
            reference operator*() const
            {
                Iterator tmp = data;
                return *(--tmp);
            }
            reverse_iterator operator+ (difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp += n;
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
            reverse_iterator operator- (difference_type n) const
            {
                reverse_iterator tmp = *this;
                tmp -= n;
                return tmp;
            }
            reverse_iterator& operator++()
            {
                --this->data;
                return *this;
            }
            reverse_iterator  operator++(int)
            {
                reverse_iterator tmp = *this;
                --this->data;
                return tmp;
            }
            reverse_iterator& operator--()
            {
                ++this->data;
                return *this;
            }
            reverse_iterator  operator--(int)
            {
                reverse_iterator tmp = *this;
                ++this->data;
                return tmp;   
            }
            pointer operator->()
            {
                Iterator tmp = data;
                return &(*(--data));
            }
            reference operator[] (difference_type n) const
            {
                return this->data[-n-1];
            }
            template < template < class > class It , class T>
			operator reverse_iterator< It<const T> >() const 
            {
                reverse_iterator< It<const T> > temp(data);
                return (temp);
                
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
    bool operator<= (const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() >= rhs.base();      
    }
    template <class A, class B>  
    bool operator>  (const reverse_iterator<A>& lhs, const reverse_iterator<B>& rhs)
    {
        return lhs.base() < rhs.base();  
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
