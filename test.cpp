/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:49:06 by misaev            #+#    #+#             */
/*   Updated: 2022/10/17 17:47:46 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst_tri.hpp"
#include <iostream>

int main() {
  struct ft::node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  std::cout << "Inorder traversal: ";
  inorder(root);

  std::cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  std::cout << "Inorder traversal: ";
  inorder(root);
}