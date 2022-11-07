#pragma once

#include <iostream>
#include "./algorithm.hpp"

namespace ft {

	template<typename T>
	class avl{

		public :

			T		value;
			avl		*right, *left;
			int		height;

		public :

			avl() : value(T()), right(nullptr), left(nullptr), height(1) {}

			avl(T value) : value(value), right(nullptr), left(nullptr), height(1) {}
			
			~avl(){}

			void print_avl(avl *root, std::string indent, bool last) {
				if (root != nullptr) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}
					std::cout << root->value << std::endl;
					print_avl(root->left, indent, false);
					print_avl(root->right, indent, true);
				}
			}

			avl insertNode(avl *node, T value) {
				// Find the correct postion and insert the node
				if (node == NULL)
					return (avl(value));
				if (value < node->value)
					node->left = insertNode(node->left, value);
				else if (value > node->value)
					node->right = insertNode(node->right, value);
				else
					return node;

				// Update the balance factor of each node and
				// balance the tree
				// node->height = 1 + max(height(node->left),
				// 			height(node->right));
				// int balanceFactor = getBalanceFactor(node);
				// if (balanceFactor > 1) {
				// 	if (value < node->left->value) {
				// 	return rightRotate(node);
				// 	} else if (value > node->left->value) {
				// 	node->left = leftRotate(node->left);
				// 	return rightRotate(node);
				// 	}
				// }
				// if (balanceFactor < -1) {
				// 	if (value > node->right->value) {
				// 	return leftRotate(node);
				// 	} else if (value < node->right->value) {
				// 	node->right = rightRotate(node->right);
				// 	return leftRotate(node);
				// 	}
				// }
				// return node;
			}
	};
}