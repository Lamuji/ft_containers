/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:29 by misaev            #+#    #+#             */
/*   Updated: 2022/11/03 17:58:24 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "bst_tri.hpp"
#include "node.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include <functional>
#include "pair.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map 
    {
        public:
            typedef Key key_type;
            typedef T   mapped_type;
            typedef ptrdiff_t   difference_type;
            typedef Compare key_compare;
            typedef Allocator   allocator_type;
            typedef typename ft::pair<const Key, T> value_type;
            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            typedef typename allocator_type::size_type  size_type;
            
            typedef value_type& reference;
            typedef const value_type&   const_reference;
            
            typedef typename Allocator::pointer pointer;   
            typedef typename Allocator::const_pointer   const_pointer;
            
            typedef typename ft::bidirectional_iterator<value_type> iterator;
            typedef typename ft::bidirectional_iterator<const value_type>   const_iterator;

            typedef typename ft::reverse_iterator<iterator>    reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;
            typedef typename ft::node<T> Node;

            map (const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type()) : root(nullptr), _comp(compare), _size(0), _alloc(alloc) {}
            
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type(), 
            typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _comp(compare), _alloc(alloc)
            {
                insert(first,last);
            }
            map (const map& x)
            {
                this->_alloc = x._alloc;
                this->_comp = x._comp;
                this->_size = x._size;
                this->root = x.root;
            }
            map& operator= (const map& x)
            {
                this->_alloc = x._alloc;
                this->_comp = x._comp;
                this->_size = x._size;
                this->root = x.root;
                return *this;
            }
            iterator begin()
            {
                return iterator(minValueNode(root));
            }
            const_iterator begin() const
            {
                return const_iterator(minValueNode(root));
            }
            iterator end()
            {
                return iterator(maxValueNode(root));   
            }
            const_iterator end() const
            {
                return const_iterator(maxValueNode(root));
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(maxValueNode(root)); 
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(maxValueNode(root));
            }
            reverse_iterator rend()
            {
                return reverse_iterator(minValueNode(root));
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(minValueNode(root));   
            }
            bool empty() const
            {
                if (this->_size == 0)
                    return true;
                else
                    return false;
            }
            size_type size() const
            {
                return this->_size;
            }
            size_type max_size() const
            {
                return this->_alloc.max_size(root);
            }
            mapped_type& operator[] (const key_type& k)
            {
                return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
            }
            iterator find (const key_type& k)
            {
                if (findValue(root, k) != NULL)
                    return iterator(findValue(root, k));
                else
                    return iterator(NULL);
            }
            const_iterator find (const key_type& k) const            
            {
                if (findValue(root, k) != NULL)
                    return const_iterator(findValue(root, k));
                else
                    return const_iterator(NULL);
            }
            Node *minValueNode(Node *node) 
            {
                Node *current = node;
                // Find the leftmost leaf
                while (current && current->left != nullptr)
                    current = current->left;
                return current;
            }
            Node *maxValueNode(Node *node) 
            {
                Node *current = node;
                // Find the leftmost leaf
                while (current && current->right != nullptr)
                    current = current->right;
                return current;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                insert(val);
            }

            ft::pair<iterator,bool> insert (const value_type& val)
            {
                // Return a new node if the tree is empty
                if (root == nullptr) 
                    return newNode(val);
                if (find(val.first) != nullptr)
                    return ft::make_pair<iterator(root), false>;
                // Traverse to the right place and insert the node
                if (val.first < root->key)
                {
                    root->left = insert(root->left, val);
                    this->_size++;
                }
                else
                {
                    root->right = insert(root->right, val);
                    this->_size++;
                }
                return ft::make_pair<iterator(root), true>;
            }
            
            void erase (iterator position)
            {
                erase(*position);
            }
            size_type erase (const key_type& k)
            {
                // Return if the tree is empty
                if (root == nullptr) 
                    return 0;
                if(find(k) == nullptr)
                    return 0;
                // Find the node to be deleted
                if (k < root->key)
                    root->left = deleteNode(root->left, k);
                else if (k > root->key)
                    root->right = deleteNode(root->right, k);
                else {
                    // If the node is with only one child or no child
                    if (root->left == nullptr) 
                    {
                        Node *temp = root->right;
                        free(root);
                        return 1;
                    } 
                    else if (root->right == nullptr) 
                    {
                        Node *temp = root->left;
                        free(root);
                        return 1;
                    }
                    // If the node has two children
                    Node *temp = minValueNode(root->right);

                    // Place the inorder successor in position of the node to be deleted
                    root->key = temp->key;

                    // Delete the inorder successor
                    root->right = deleteNode(root->right, temp->key);
                }
                return 1;
            }
            void erase (iterator first, iterator last)
            {
                while (first != last)
                    erase(*first++);
            }
            size_type count (const key_type& k) const
            {
                if (find(k) != nullptr)
                    return 1;
                else
                    return 0;
            }
            void swap (map& x)
            {
                Node    tmp_root = x.root;
                key_compare tmp_comp = x._comp;
                size_t tmp_size = x._size;
                allocator_type tmp_alloc = x._alloc;
            
                x.root = this->root;
                x._comp = this->_comp;
                x._size = this->_size;
                x._alloc = this->_alloc;
            
                this->_alloc = tmp_root;
                this->_comp = tmp_comp;
                this->_size = tmp_size;
                this->root = tmp_alloc;
            }
            void clear()
            {
                iterator it = begin();
                iterator last = end();
                while (it != last)
                    deleteNode(*it);
                _size = 0;
            }
            value_compare value_comp() const
            {
                return value_compare(key_compare());
            }
            key_compare key_comp() const
            {
                return key_compare();
            }
            iterator lower_bound (const key_type& k)
            {
                iterator	it;

				for (it = begin(); it != end(); it++)
					if (!_comp(it->first, k))
						return (it);
				return (it);
            }
            const_iterator lower_bound (const key_type& k) const
            {
                iterator	it;

				for (it = begin(); it != end(); it++)
					if (!_comp(it->first, k))
						return (it);
				return (it);
            }
            iterator upper_bound (const key_type& k)
            {
                iterator	it;

				for (it = begin(); it != end(); it++)
					if (compare(k, it->first))
						return (it);
				return (it);
            }
            const_iterator upper_bound (const key_type& k) const
            {
                iterator	it;

				for (it = begin(); it != end(); it++)
					if (compare(k, it->first))
						return (it);
				return (it);
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
            }
            pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
            }
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            ~map(){}
        private:
            Node    root;
            key_compare _comp;
            size_t _size;
            allocator_type _alloc;
    };
    	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return (!(lhs == rhs)); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return (!(rhs < lhs)); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return (rhs < lhs); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) 	
		{ return (!(lhs < rhs)); }
}