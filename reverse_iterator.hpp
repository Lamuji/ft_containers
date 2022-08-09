/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:42:04 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/09 17:22:54 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include <iterator>

namespace ft{
template<typename _Iterator>

class reverse_iterator : : public iterator<typename iterator_traits<_Iterator>::iterator_category,
        					typename iterator_traits<_Iterator>::value_type,
       						typename iterator_traits<_Iterator>::difference_type,
       						typename iterator_traits<_Iterator>::pointer,
       						typename iterator_traits<_Iterator>::reference>
{
protected:
	_Iterator							current;
	typedef iterator_traits<_Iterator>	__traits_type;

public:

	typedef _Iterator                 					iterator_type;
    typedef typename __traits_type::difference_type   	difference_type;
    typedef typename __traits_type::pointer       		pointer;
    typedef typename __traits_type::reference     		reference;

	reverse_iterator() : current(){ }

	reverse_iterator (iterator_type __x) : current(__x){ }
 
 	reverse_iterator(const reverse_iterator &__x) : current(__x.current) { }
 
	template<typename _Iter>
 	reverse_iterator (const reverse_iterator< _Iter > &__x) : current(__x.base()) { }

	~reverse_iterator();

	iterator_type 	base () const {
		return current;
	}

	reference 	operator* () const {
		_Iterator __tmp = current;
		return *--__tmp;
	}
	
	reverse_iterator 	operator+(difference_type __n) const {
		return reverse_iterator(current - __n);
	}
	reverse_iterator & 	operator++() { 
		--current;
		return *this;
	}

	reverse_iterator 	operator++(int) {
		reverse_iterator __tmp = *this;
		--current;
		return __tmp;
	}
	reverse_iterator & 	operator+=(difference_type __n){
		current -= __n;
		return *this;
	}

	reverse_iterator 	operator-(difference_type __n) const {
		return reverse_iterator(current + __n);
	}

	reverse_iterator & 	operator--(){
		++current;
		return *this;
	}

	reverse_iterator 	operator--(int) {
		reverse_iterator __tmp = *this;
		current++;
		return __tmp;
	}

	reverse_iterator & 	operator-=(difference_type __n) {
		current += __n;
		return *this;
	}

	pointer 	operator->() const {
		return &(operator*());
	}
	reference 	operator[](difference_type __n) const {
		return *(*this + __n);
	}
};
	
}

#endif 