/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:49:06 by misaev            #+#    #+#             */
/*   Updated: 2022/11/24 22:55:12 by rfkaier          ###   ########.fr       */
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
  ft::map<int, int> root; 
  root.insert(ft::make_pair(8, 8));
  root.insert(ft::make_pair(3, 3));
  root.insert(ft::make_pair(1, 1));
  root.insert(ft::make_pair(6, 6));
  root.insert(ft::make_pair(7, 7));
  root.insert(ft::make_pair(10, 10));
  root.insert(ft::make_pair(14, 14));
  root.insert(ft::make_pair(4, 4));
  root.insert(ft::make_pair(13, 13));
  root.insert(ft::make_pair(15, 15));


//   root.erase(8);
//   root.erase(3);
//   root.erase(1);
//   root.erase(6);
 // Il ya toujours des leaks meme apres avoir supprimer tout avec erase
  
  // TODO Faire une fonction qui supprime tous l arbre sans leaks.
   

  // root.clear();
  root.printNode();
  while(1);
}
