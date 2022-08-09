/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:46:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/09 16:12:29 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft
{
    template< class T,class Allocator = std::allocator<T> >

    class vector
    {
            typedef _GLIBCXX_STD_C::vector<_Tp, _Allocator> _Base;        
            typedef typename _Base::iterator _Base_iterator;
            typedef typename _Base::const_iterator _Base_const_iterator;
		public:
            typedef _GLIBCXX_STD_C::vector<_Tp, _Allocator> _Base;
        
            typedef typename _Base::iterator _Base_iterator;
            typedef typename _Base::const_iterator _Base_const_iterator;
            typedef typename _Base::reference             reference;
            typedef typename _Base::const_reference       const_reference;

            typedef typename _Base::size_type             size_type;
            typedef typename _Base::difference_type       difference_type;

            typedef _Tp                   value_type;
            typedef _Allocator                allocator_type;
            typedef typename _Base::pointer               pointer;
            typedef typename _Base::const_pointer         const_pointer;
            typedef std::reverse_iterator<iterator>       reverse_iterator;
            typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

            vector (const allocator_type& alloc = _Allocator()) : _Base(alloc), _M_guaranteed_capacity(0) { };
        
            vector (size_type n, const value_type& val = _Tp(),
                 const allocator_type& alloc = _Allocator()) 
                 : _Base(n, val, alloc), _M_guaranteed_capacity(n) {};
        
            // template <class InputIterator>
            // vector (InputIterator first, InputIterator last,
            //      const allocator_type& alloc = allocator_type());
        
            vector (const vector& x);
        
            ~vector();
        private:
            /* data */
            size_type _M_guaranteed_capacity;
    };
}

