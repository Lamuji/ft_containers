/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:49:06 by misaev            #+#    #+#             */
/*   Updated: 2022/11/07 13:59:43 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <iostream>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


int main()
{
  ft::map<char,int> first;

  first['a'] = 10;
  first['b'] = 30;
  first['c'] = 50;
  first['d'] = 70;

  ft::map<char,int> second (first.begin(),first.end());

  ft::map<char,int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  return 0;
}

// int main() {
//   ft::node<int> *root = NULL;
//   ft::node<int> *tmp = NULL;
//   root = insertNode(root,tmp, 8);
//   root = insertNode(root,root->parent, 3);
//   root = insertNode(root,root->parent, 1);
//   root = insertNode(root,root->parent, 6);
//   root = insertNode(root,root->parent, 7);
//   root = insertNode(root,root->parent, 10);
//   root = insertNode(root,root->parent, 14);
//   root = insertNode(root,root->parent, 4);

//   inorder(root);
// }

