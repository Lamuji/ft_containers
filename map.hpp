/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:34:05 by misaev            #+#    #+#             */
/*   Updated: 2022/11/24 22:59:36 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_tri.hpp"
#include <cstdlib>
#include <alloca.h>
#include <memory>
#include "bidirectional_iterator.hpp"
#include "pair.hpp"

namespace ft
{
    template<class Key,class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef typename ft::pair<const Key, T> 	value_type;
			typedef typename std::size_t				size_type;
			typedef typename std::ptrdiff_t				difference_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
            typedef typename ft::node<T>* 				node_type;	
			typedef bidirectional_iterator<T>			iterator;
			typedef bidirectional_iterator<const T>		const_iterator;
			// typedef reverse_iterator<iterator>			reverse_iterator;
			// typedef reverse_iterator<const_iterator>	const_reverse_iterator;
			
            map()
            {
                _tree = NULL;
                _size = 0;
            }
            map(T key)
            {
                _tree = NULL;
                _tree = insertNode(_tree, _tree, key);
                _size++;
            }
			iterator begin()
			{
				return iterator(_tree);
			}
			iterator end()
			{
				return iterator(_tree);
			}
			const_iterator begin() const
			{
				return const_iterator(_tree);
			}
			const_iterator end() const
			{
				return const_iterator(_tree);
			}
			// reverse_iterator rbegin()
			// {
			// 	return reverse_iterator(_tree);
			// }
			// reverse_iterator rend()
			// {
			// 	return reverse_iterator(_tree);
			// }
			// const_reverse_iterator rbegin() const
			// {
			// 	return const_reverse_iterator(_tree);
			// }
			// const_reverse_iterator rend() const
			// {
			// 	return const_reverse_iterator(_tree);
			// }
			bool empty() const
			{
				return (_size == 0);
			}
			size_type size() const
			{
				return _size;
			}
			size_type max_size() const
			{
				return std::numeric_limits<size_type>::max();
			}
			mapped_type& operator[](const key_type& k)
			{
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			}
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (_size <= 1)
					this->_tree = insertNode(_tree, _tree, val);
				else
					this->_tree = insertNode(_tree, _tree->parent, val);
				return ft::make_pair(iterator(_tree), true);
			}
			iterator insert (iterator position, const value_type& val)
			{
				if (_size <= 1)
					this->_tree = insertNode(_tree, _tree, val);
				else
					this->_tree = insertNode(_tree, _tree->parent, val);
				return iterator(_tree);
			}
			iterator erase (iterator position){
				_tree = deleteNode(_tree, position->first);
				return iterator(_tree);
			}
            void printNode()
            {
                ft::inorder(_tree);
            }
            void clear()
            {
                delete _tree->left;
            }
            ~map(){}
        private:
            /* INSERER UN NOUVEAU NOEUD */
            node_type insertNode(node_type node,node_type parent, T key)
            {
                if (node == NULL) 
                {
                    return newNode(key, parent);
                }
                if (key < node->key && findValue(node, key) == false)
                    node->left = insertNode(node->left, node, key);      
                else if (key > node->key && findValue(node, key) == false)
                    node->right = insertNode(node->right, node,  key);
                return node;
            }
            /**/
            /* CREE UN NOEUD */
            node_type newNode(T item, node_type parent) 
            {
                node_type temp = new ft::node<T>;
                temp->key = item;
                if (parent != NULL)
                {
                    temp->parent = parent;
                }
                else
                    temp->parent = NULL;
                    temp->left = temp->right = NULL;
                return temp;
            }
			/**/
            node_type _tree;
            size_t _size;
    };
}
