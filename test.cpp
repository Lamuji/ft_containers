/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:49:06 by misaev            #+#    #+#             */
/*   Updated: 2022/11/21 19:03:47 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

// int main() 
// {
//   ft::node<int> *root = NULL;
//   root = insertNode(root,root, 8);
//   root = insertNode(root,root->parent, 3);
//   root = insertNode(root,root->parent, 1);
//   root = insertNode(root,root->parent, 6);
//   root = insertNode(root,root->parent, 7);
//   root = insertNode(root,root->parent, 10);
//   root = insertNode(root,root->parent, 14);

//   ft::inorder(root);

//   // root = ft::deleteNode(root, 10);
//   // ft::inorder(root);
// }

int main()
{
  ft::map<int> root; 
  root.insert(8);
  root.insert(3);
  root.insert(1);
  root.insert(6);
  root.insert(7);
  root.insert(10);
  root.insert(14);
  root.insert(4);
  root.erase(8);
  root.erase(3);
  root.erase(1);
  root.erase(6);
 // Il ya toujours des leaks meme apres avoir supprimer tout avec erase
  
  // TODO Faire une fonction qui supprime tous l arbre sans leaks.
   

  // root.clear();
  root.printNode();
  while(1);
}
