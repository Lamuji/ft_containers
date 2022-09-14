/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:42:04 by rfkaier           #+#    #+#             */
/*   Updated: 2022/09/15 00:46:58 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include <iterator>

namespace ft{

template < class Iterator >

class reverse_iterator: public iterator<
				typename iterator_traits<Iterator>::iterator_category,
				typename iterator_traits<Iterator>::value_type,
				typename iterator_traits<Iterator>::difference_type,
				typename iterator_traits<Iterator>::pointer,
				typename iterator_traits<Iterator>::reference
				>
{
protected:
	Iterator _current;
public:
	typedef Iterator											iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename iterator_traits<Iterator>::value_type		value_type;
	typedef typename iterator_traits<Iterator>::reference		reference;
	typedef typename iterator_traits<Iterator>::pointer			pointer;


	reverse_iterator(): _current() {};
	reverse_iterator(value_type* p) { _current = Iterator(p); }
	reverse_iterator(const Iterator& x) { _current = x; }
	template < template < class > class It , class T>
	operator reverse_iterator< It<const T> >() const {reverse_iterator< It<const T> > temp(_current); return (temp);}			
	Iterator base() const {return Iterator(_current);}
	Iterator getCurrent() const {return _current;}

	template< class U >
	reverse_iterator( const reverse_iterator<U>& other ) { *this = other; }

	template< class U >
	reverse_iterator& operator=( const reverse_iterator<U>& other ) {
		_current = other.getCurrent();
		return *this;
	}

	value_type& operator*() {
		Iterator tmp = _current;
		return *--tmp;
	}
	const value_type& operator*() const {
		Iterator tmp = _current;
		return *--tmp;
	}
	value_type* operator->() { 
		Iterator tmp = _current;
		--tmp;
		return tmp.operator->();
	}
	const value_type* operator->() const {
		Iterator tmp = _current;
		--tmp;
		return tmp.operator->();
	}

	reference operator[](difference_type n) const { return *(*this + n); }

	reverse_iterator& operator++() {
		--_current;
		return  *this;
	}
	reverse_iterator& operator--() {
		++_current;
		return *this;
	}
	reverse_iterator operator++( int ) {
		reverse_iterator tmp = *this;
		--_current;
		return  tmp;
	}
	reverse_iterator operator--( int ) {
		reverse_iterator tmp = *this;
		++_current;
		return tmp;
	}
	reverse_iterator operator+( difference_type n ) const {
		return reverse_iterator(this->_current - n);
	}
	reverse_iterator operator-( difference_type n ) const {
		return reverse_iterator(_current + n);
	}
	reverse_iterator& operator+=( difference_type n ) {
		_current -= n;
		return *this;
	}
	difference_type operator+(const reverse_iterator &right) const {return this->data - right.data;}
	difference_type operator-(const reverse_iterator & right) const {return this->data - right.data;}
	reverse_iterator& operator-=( difference_type n ) {
		_current += n;
		return *this;
	}
};


template<class Iterator>
class const_reverse_iterator: public iterator<
				typename iterator_traits<Iterator>::iterator_category,
				typename iterator_traits<Iterator>::value_type,
				typename iterator_traits<Iterator>::difference_type,
				typename iterator_traits<Iterator>::pointer,
				typename iterator_traits<Iterator>::reference
				>
{
protected:
	Iterator _current;
public:
	typedef Iterator											iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename iterator_traits<Iterator>::value_type		value_type;
	typedef typename iterator_traits<Iterator>::reference		reference;
	typedef typename iterator_traits<Iterator>::pointer			pointer;


	const_reverse_iterator(): _current() {};
	const_reverse_iterator(value_type* p) { _current = Iterator(p); }
	const_reverse_iterator(const Iterator& x) { _current = x; }

	Iterator base() const {return Iterator(_current);}
	Iterator getCurrent() const {return _current;}

	template< class U >
	const_reverse_iterator( const const_reverse_iterator<U>& other ) { *this = other; }
	template< class U >
	const_reverse_iterator( const reverse_iterator<U>& other ) { *this = other;}

	template< class U >
	const_reverse_iterator& operator=( const const_reverse_iterator<U>& other ) {
		_current = other.getCurrent();
		return *this;
	}
	template< class U >
	const_reverse_iterator& operator=( const reverse_iterator<U>& other ) {
		_current = other.getCurrent();
		return *this;
	}
	
	const value_type& operator*() const {
		Iterator tmp = _current;
		return *--tmp;
	}
	
	const value_type* operator->() const {
		Iterator tmp = _current;
		--tmp;
		return tmp.operator->();
	}

	reference operator[](difference_type n) const { return *(*this + n); }

	const_reverse_iterator& operator++() {
		--_current;
		return  *this;
	}
	const_reverse_iterator& operator--() {
		++_current;
		return *this;
	}
	const_reverse_iterator operator++( int ) {
		const_reverse_iterator tmp = *this;
		--_current;
		return  tmp;
	}
	const_reverse_iterator operator--( int ) {
		const_reverse_iterator tmp = *this;
		++_current;
		return tmp;
	}
	const_reverse_iterator operator+( difference_type n ) const {
		return const_reverse_iterator(_current - (n));
	}
	const_reverse_iterator operator-( difference_type n ) const {
		return const_reverse_iterator(_current + (n));
	}
	const_reverse_iterator& operator+=( difference_type n ) {
		_current -= (n);
		return *this;
	}
	const_reverse_iterator& operator-=( difference_type n ) {
		_current += (n);
		return *this;
	}
};

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() == rhs.base());
				};
template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs == rhs);
				}
template< class Iterator1, class Iterator2 >
bool operator<( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() > rhs.base());
				}

template< class T >
reverse_iterator<T> operator+(
	typename reverse_iterator<T>::difference_type n,
	const reverse_iterator<T>& it ) {
				return (it + n);
			}

template< class T >
reverse_iterator<T> operator-(
	typename reverse_iterator<T>::difference_type n,
	const reverse_iterator<T>& it ) {
				return (it - n);
			}
template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-(
	const reverse_iterator<Iterator>& lhs,
	const reverse_iterator<Iterator>& rhs ) {
				return (rhs.base() - lhs.base());
			}

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() == rhs.base());
				};
template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs == rhs);
				}
template< class Iterator1, class Iterator2 >
bool operator<( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator==( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() == rhs.base());
				};
template< class Iterator1, class Iterator2 >
bool operator!=( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs == rhs);
				}
template< class Iterator1, class Iterator2 >
bool operator<( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator<=( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>=( const const_reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator==( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() == rhs.base());
				};
template< class Iterator1, class Iterator2 >
bool operator!=( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs == rhs);
				}
template< class Iterator1, class Iterator2 >
bool operator<( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() > rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator<=( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return (lhs.base() < rhs.base());
				}
template< class Iterator1, class Iterator2 >
bool operator>=( const const_reverse_iterator<Iterator1>& lhs,
				const const_reverse_iterator<Iterator2>& rhs ) {
					return !(lhs.base() > rhs.base());
				}

// template< class Iterator >
// const_reverse_iterator<Iterator> operator+(
// 	typename reverse_iterator<Iterator>::difference_type n,
// 	const const_reverse_iterator<Iterator>& it ) {
// 				return (it + n);
// 			}
template< class Iterator >
const_reverse_iterator<Iterator> operator-(
	typename reverse_iterator<Iterator>::difference_type n,
	const const_reverse_iterator<Iterator>& it ) {
				return (it - n);
			}
template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-(
	const reverse_iterator<Iterator>& lhs,
	const const_reverse_iterator<Iterator>& rhs ) {
				return rhs.base() - lhs.base();
			}
template< class T, class U >
typename reverse_iterator<T>::difference_type operator-(
	const const_reverse_iterator<U>& lhs,
	const reverse_iterator<T>& rhs ) {
				return rhs.base() - lhs.base();
			}
}

#endif