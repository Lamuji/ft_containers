/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_tri.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:49:10 by misaev            #+#    #+#             */
/*   Updated: 2022/11/06 18:57:18 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Binary Search Tree operations in C++

#include <iostream>
#include "node.hpp"

namespace ft
{
  /*----------------------*/
  template<class T>
  ft::node<T> *newNode(int item, ft::node<T> *parent) 
  {
    ft::node<T> *temp = new ft::node<T>;
    temp->key = item;
    if (parent != NULL)
    {
      temp->parent = new ft::node<T>;
      temp->parent = parent;
    }
    else
      temp->parent = NULL;
    temp->left = temp->right = NULL;
    return temp;
  }
  /*----------------------*/
  template<class T>
  ft::node<T> *insertNode(ft::node<T> *node,ft::node<T> *parent,  int key) 
  {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode<T>(key, parent);

    // Traverse to the right place and insertNode the node
    if (key < node->key)
      node->left = insertNode(node->left, node, key);      
    else
      node->right = insertNode(node->right, node,  key);
    return node;
  }
  /*----------------------*/
  template<class T>
  void inorder(ft::node<T> *root) {
    if (root != NULL) {
      // Traverse left
      inorder(root->left);

      // Traverse root
      std::cout << root->key << " -> ";
      if (root->parent == NULL)
        std::cout << " [ NULL ] "  << std::endl;
      else
        std::cout << " [ " << root->parent->key << " ] "  << std::endl;
      // Traverse right
      inorder(root->right);
    }
  }
  template<class T>
  ft::node<T> *predecessor(ft::node<T> *node)
  {
    ft::node<T> *temp = node;
      /* code */
      if (node != NULL)
      {
        std::cout << temp->key;
        temp = temp->left;
        std::cout << temp->key;
        temp = temp->right;      
      }
    return temp;
  }
  
  /*----------------------*/
  template<class T>
  ft::node<T> *minValueNode(ft::node<T> *node) {
    ft::node<T> *current = node;
  
    // Find the leftmost leaf
    while (current && current->left != NULL)
      current = current->left;

    return current;
  }
  /*----------------------*/
  template<class T>
  ft::node<T> *maxValueNode(ft::node<T> *node) {
    ft::node<T> *current = node;

    // Find the leftmost leaf
    while (current && current->right != NULL)
      current = current->right;

    return current;
  }
  /*----------------------*/
  template<class T>
  ft::node<T> *findValue(ft::node<T> *node, T key) 
  {
    ft::node<T> *temp = node;
   
    while (key != temp->key)
    {
      if (temp == NULL || (temp->right == NULL && temp->left == NULL))
        break;
      if (key > temp->key)
        temp = temp->right;
      else if (key < temp->key)
        temp = temp->left;
      if (key == temp->key)
        return temp;
    }
    return nullptr;
  }
  /*----------------------*/
  template<class T>
  ft::node<T> *deleteNode(ft::node<T> *root, int key) {
    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (key < root->key)
      root->left = deleteNode(root->left, key);
    else if (key > root->key)
      root->right = deleteNode(root->right, key);
    else {
      // If the node is with only one child or no child
      if (root->left == NULL) {
        ft::node<T> *temp = root->right;
        free(root);
        return temp;
      } else if (root->right == NULL) {
        ft::node<T> *temp = root->left;
        free(root);
        return temp;
      }
      // If the node has two children
      ft::node<T> *temp = minValueNode(root->right);
      // Place the inorder successor in position of the node to be deleted
      root->key = temp->key;
      // Delete the inorder successor
      root->right = deleteNode(root->right, temp->key);
    }
    return root;
  }
  /*----------------------*/
}

