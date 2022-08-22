/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:09:31 by rfkaier           #+#    #+#             */
/*   Updated: 2022/08/22 16:33:59 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR
# define RANDOM_ACCESS_ITERATOR

#include <iostream>
#include <iterator>

namespace ft
{
    template<typename T>
	class iterator
    {
        public:
            /* */
            iterator(T* x) :data(x) {}
            iterator(const iterator& rhs) : data(rhs.data) {}
            iterator& operator=(const iterator& rhs) { data(rhs.data); return *this;}
            ~iterator() {}
            /* */ 
            bool operator==(const iterator& rhs) const {return data==rhs.data;}
            bool operator!=(const iterator& rhs) const {return data!=rhs.data;}
            bool operator<(const iterator &rhs) const { return data < rhs.data; }
            bool operator>(const iterator &rhs) const { return data > rhs.data; }
            bool operator<=(const iterator &rhs) const { return data <= rhs.data; }
            bool operator>=(const iterator &rhs) const { return data >= rhs.data; }
            /* */
            iterator& operator++() {++data;return *this;}
            iterator operator++(int) {iterator tmp(*this); operator--(); return tmp;}
            iterator& operator--() {--data;return *this;}
            iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
            /* */
            T operator-(const iterator &rhs) const { return data - rhs.data; }
            iterator operator+(T i) const { return iterator(data + i); }
            iterator operator-(T i) const { return iterator(data - i); }
            iterator &operator+=(T i) { data += i; return *this; }
            iterator &operator-=(T i) { data -= i; return *this; }
            iterator operator[] (size_t i) {return data[i];}
            
            T& operator*() {return *data;}
        private:
            T* data;
    };
}

#endif