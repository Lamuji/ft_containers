/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:34:05 by misaev            #+#    #+#             */
/*   Updated: 2022/11/28 20:09:45 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_tri.hpp"
#include <cstdlib>
#include <alloca.h>
#include "BSTIterator.hpp"
#include "iterator_traits.hpp"
#include <memory>
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
            typedef typename ft::node<T>* 		node_type;
            typedef typename ft::node<const T>* 		const_node_type;
            typedef ft::BSTIterator<T> iterator;
            typedef ft::BSTIterator<T> const_iterator;
            /*===================================*/
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
			iterator	begin() 
            { 
                return (iterator(_tree, _tree, NULL)); 
            }

			bool empty() const
			{
				return (_size == 0);
			}
			void insert (key_t key)
			{
				if (_size <= 1)
					this->_tree = insertNode(_tree, _tree, key);
				else
					this->_tree = insertNode(_tree, _tree->parent, key);
			}
            void printNode()
            {
                ft::inorder(_tree);	
            }
			void predecessor(node_type node) // pour le teste
			{
				ft::predecessor(node);
			}
            void clear()
            {
                delete _tree->left;
            }
            // node_type _tree; // Pour le teste
            ~map(){}
        private:
            /* INSERER UN NOUVEAU NOEUD */
            node_type insertNode(node_type node,node_type parent, T key)
            {
                if (node == NULL) 
                {
                    return newNode(key, parent);
                }
                if (&key < node->key && findValue(node, key) == false)
                    node->left = insertNode(node->left, node, key);      
                else if (&key > node->key && findValue(node, key) == false)
                    node->right = insertNode(node->right, node,  key);
                return node;
            }
            /**/
            /* CREE UN NOEUD */
            node_type newNode(T item, node_type parent) 
            {
                node_type temp = new ft::node<T>;
                temp->key = &item;
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
            node_type	minimum(node_type node) const
			{
				if (!_size)
					return (NULL);
				while (node->left != NULL)
					node = node->left;
				return (node);
			}

			node_type	maximum(node_type node) const
			{
				if (!_size)
					return (NULL);
				while (node->right != NULL)
					node = node->right;
				return (node);
			}
            key_compare	compare;
			allocator_type	alloc;
            node_type _tree;
            size_t _size;
    };
}
