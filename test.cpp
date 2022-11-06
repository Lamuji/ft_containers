/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:49:06 by misaev            #+#    #+#             */
/*   Updated: 2022/11/06 16:52:13 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "map.hpp"
#include "bst_tri.hpp"
#include <iostream>

// Binary Search Tree operations in C++
// Driver code
int main() {
  ft::node<int> *root = NULL;
  ft::node<int> *tmp = NULL;

  root = insertNode(root,tmp, 8);
  root = insertNode(root,tmp, 3);
  root = insertNode(root,tmp, 1);
  root = insertNode(root,tmp, 6);
  root = insertNode(root,tmp, 7);
  root = insertNode(root,tmp, 10);
  root = insertNode(root,tmp, 14);
  root = insertNode(root,tmp, 4);

//   std::cout << "Inorder traversal: ";
  // inorder(root);
//   std::cout << "\nAfter deleting 10\n";
//   root = deleteNode(root, 6);
//   std::cout << "Inorder traversal: ";
  inorder(root);
  // std::cout << predecessor(root)->key;

}

