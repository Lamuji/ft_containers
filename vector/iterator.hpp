/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:09:31 by rfkaier           #+#    #+#             */
/*   Updated: 2022/09/12 15:10:02 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR
# define RANDOM_ACCESS_ITERATOR


		template<class T>
		class iterator : public std::random_access_iterator_tag
		{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef std::ptrdiff_t difference_type;
				typedef ft::random_access_iterator_tag iterator_category;

				/* */
				iterator(): data() {}
				iterator(T* x) : data(x) {}
				iterator(const iterator& rhs) : data(rhs.data) {}
				iterator& operator=(const iterator& rhs) { data = rhs.data; return *this;}
				~iterator() {}
				/* */ 
				template <class It>
				bool	operator==(It const & rhs) const {return (data == rhs.data);}
				template <class It>
				bool	operator!=(It const & rhs) const {return (data != rhs.data);}
				template <class It>
				bool	operator>(It const & rhs) const {return (data > rhs.data);}
				template <class It>
				bool	operator<(It const & rhs) const {return (data < rhs.data);}
				template <class It>
				bool	operator>=(It const & rhs) const {return (data >= rhs.data);}
				template <class It>
				bool	operator<=(It const & rhs) const {return (data <= rhs.data);}				
				/* */
				iterator& operator++() {++data;return *this;}

				iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
				
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

		template<class T>
		class const_iterator : public std::random_access_iterator_tag
		{
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef std::ptrdiff_t difference_type;
				typedef ft::random_access_iterator_tag iterator_category;

				/* */
				const_iterator(): data() {}
				const_iterator(T* x) : data(x) {}
				const_iterator(const iterator& rhs) : data(rhs.data) {}
				const_iterator& operator=(const_iterator& rhs) { data = rhs.data; return *this;}
				~const_iterator() {}
				/* */ 
				template <class It>
				bool	operator==(It const & rhs) const {return (data == rhs.data);}
				template <class It>
				bool	operator!=(It const & rhs) const {return (data != rhs.data);}
				template <class It>
				bool	operator>(It const & rhs) const {return (data > rhs.data);}
				template <class It>
				bool	operator<(It const & rhs) const {return (data < rhs.data);}
				template <class It>
				bool	operator>=(It const & rhs) const {return (data >= rhs.data);}
				template <class It>
				bool	operator<=(It const & rhs) const {return (data <= rhs.data);}				
				/* */
				const_iterator& operator++() {++data;return *this;}

				const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
				
				const_iterator& operator--() {--data;return *this;}
				
				const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
				/* */
				T operator-(const iterator &rhs) const { return data - rhs.data; }
				const_iterator operator+(T i) const { return const_iterator(data + i); }
				const_iterator operator-(T i) const { return const_iterator(data - i); }
				const_iterator &operator+=(T i) { data += i; return *this; }
				const_iterator &operator-=(T i) { data -= i; return *this; }
				const_iterator operator[] (size_t i) {return data[i];}

				T& operator*() {return *data;}
			private:
				const T* data;
		};

#endif