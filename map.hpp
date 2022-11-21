/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:34:05 by misaev            #+#    #+#             */
/*   Updated: 2022/11/21 21:27:10 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_tri.hpp"
#include <cstdlib>

namespace ft
{
    template<class T>
    class map
    {
        public:
            typedef typename ft::node<T>* node_type;
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
            void insert(T key)
            {
                if (_size <= 1)
                    this->_tree = insertNode(_tree, _tree, key);
                else
                    this->_tree = insertNode(_tree, _tree->parent, key);
            }
            void erase(T key)
            {
                _tree = ft::deleteNode(_tree, key);
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

            void	manager(void *ptr)
            {
                static t_node	*heap = NULL;
                t_node			*new;

                else
                {
                new = ft_lstnew(ptr);
                ft_lstadd_back(&heap, new);
                }
            }
            node_type _tree;
            size_t _size;
    };
}