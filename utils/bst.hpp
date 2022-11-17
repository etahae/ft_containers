#pragma once

#include <iostream>
#include "./algorithm.hpp"
#include <memory>

namespace ft {

	template<typename T>
	class bst{

		public :

			struct node {
				T				key;
				struct node		*right, *left;
			};

			class bst_iterator{
				public :
					node	*it;

					bst_iterator() : it(NULL) {}
					bst_iterator(node *p) : it(p) {}
					bst_iterator(const bst_iterator& obj) { *this = obj; }
					bst_iterator& operator = (const bst_iterator& obj){
						this->it = obj.it;
						return *this;
					}
					bool operator == (const bst_iterator& obj) { return (it->key == obj.it->key); }
					bool operator != (const bst_iterator& obj) { return !(it = obj); }
					bst_iterator& operator ++ (){}
					bst_iterator& operator -- (){}
					T&	operator * () {}
			};

			node *newnode(T key) {
				node *node = new struct node();
				node->key = key;
				node->left = NULL;
				node->right = NULL;
				return (node);
			}

			void inorder(struct node *root) {
				if (root != NULL) {
					// Traverse left
					inorder(root->left);

					// Traverse root
					std::cout << root->key << " -> ";

					// Traverse right
					inorder(root->right);
				}
			}

			struct node *insert(struct node *node, T key) {
				if (node == NULL)
					return newnode(key);
				if (key < node->key)
					node->left = insert(node->left, key);
				else
					node->right = insert(node->right, key);
				return node;
			}

			struct node *minValuenode(struct node *node) {
				struct node *current = node;
				while (current && current->left != NULL)
					current = current->left;
				return current;
			}

			// Delete a node
			struct node *deletenode(struct node *root, T key) {
				if (root == NULL)
					return root;
				if (key < root->key)
					root->left = deletenode(root->left, key);
				else if (key > root->key)
					root->right = deletenode(root->right, key);
				else {
					// If the node is with only one child or no child
					if (root->left == NULL) {
						struct node *temp = root->right;
						free(root);
						return temp;
					}
					else if (root->right == NULL) {
						struct node *temp = root->left;
						free(root);
						return temp;
					}

					// If the node has two children
					struct node *temp = minValuenode(root->right);

					// Place the inorder successor in position of the node to be deleted
					root->key = temp->key;

					// Delete the inorder successor
					root->right = deletenode(root->right, temp->key);
				}
				return root;
			}
	};
}