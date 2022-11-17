#pragma once

#include <iostream>
#include "./algorithm.hpp"
#include <memory>

namespace ft {

	template<typename T>
	struct Node {
		T			value;
		Node		*parent, *right, *left;

		Node() : value(), parent(nullptr), right(nullptr), left(nullptr) {}
		Node(Node *_parent, Node *_right, Node *_left)
			: parent(_parent), right(_right), left(_left) {}
		Node(T _value, Node *_parent, Node *_right, Node *_left)
			: value(_value), parent(_parent), right(_right), left(_left) {}
		Node(const Node& obj){ *this = obj; }
		Node& operator = (const Node& obj){
			this->value = obj.value;
			this->parent = obj.parent;
			this->right = obj.right;
			this->left = obj.left;
			return *this;
		}
	};

	template<typename T, typename Compare>
	class bst_iterator{
		public :
			
			typedef T*																	iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		protected :

			iterator_type 	_node;
			iterator_type 	_last_node;
			Compare			_comp;

		public :

			iterator_type base() { return _node; };

			bst_iterator() : _node(nullptr) {}

			bst_iterator(iterator_type node, iterator_type last_node, const Compare& comp = Compare())
				: _node(node) , _last_node(last_node) , _comp(comp) {}

			bst_iterator(const bst_iterator& obj) { *this = obj; }

			bst_iterator& operator = (const bst_iterator& obj){
				this->_node = obj._node;
				this->_last_node = obj._last_node;
				this->_comp = obj._comp;
				return *this;
			}

			~bst_iterator() {}

			bool operator == (const bst_iterator& obj) { return (_node->key == obj._node->key); }
			bool operator != (const bst_iterator& obj) { return !(_node = obj); }

			bst_iterator& operator ++ (){
				iterator_type cursor = _node;

				if (_node->right == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& _comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->right;
					if (cursor == _last_node->parent
						&& cursor->right == _last_node)
						_node = cursor;
					else
					{
						while (cursor->left != _last_node)
							cursor = cursor->left;
					}
					_node = cursor;
				}
				return (*this);
			}
			bst_iterator& operator -- (){
				T* cursor = _node;

				if (_node->left == _last_node)
				{
					cursor = _node->parent;
					while (cursor != _last_node
						&& !_comp(cursor->value.first, _node->value.first))
						cursor = cursor->parent;
					_node = cursor;
				}
				else if (cursor == _last_node)
					_node = _last_node->right;
				else
				{
					cursor = _node->left;
					if (cursor == _last_node->parent
						&& cursor->left == _last_node)
						_node = cursor;
					else
					{
						while (cursor->right != _last_node)
							cursor = cursor->right;
					}
					_node = cursor;
				}
				return (*this);
			}

			reference	operator * () { return this->_node->value; }

			pointer		operator -> () { return &this->_node->value; }

			bst_iterator& operator ++ (int){
				bst_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			bst_iterator& operator -- (int){
				bst_iterator tmp(*this);
				operator--();
				return (tmp);
			}
	};

	template <class T, class _Compare, class _Allocator = std::allocator<T>, class Node = ft::Node<T> >
	class bst{

		public :

			typedef T				value_type;
			typedef _Allocator 		alloc_type;
			typedef ft::Node<T> 	node;

			

			// node *newnode(T key) {
			// 	node *node = new node();
			// 	node->key = key;
			// 	node->left = NULL;
			// 	node->right = NULL;
			// 	return (node);
			// }

			// void inorder(node *root) {
			// 	if (root != NULL) {
			// 		// Traverse left
			// 		inorder(root->left);

			// 		// Traverse root
			// 		std::cout << root->key << " -> ";

			// 		// Traverse right
			// 		inorder(root->right);
			// 	}
			// }

			// node *insert(node *node, T key) {
			// 	if (node == NULL)
			// 		return newnode(key);
			// 	if (key < node->key)
			// 		node->left = insert(node->left, key);
			// 	else
			// 		node->right = insert(node->right, key);
			// 	return node;
			// }

			// node *minValuenode(node *node) {
			// 	node *current = node;
			// 	while (current && current->left != NULL)
			// 		current = current->left;
			// 	return current;
			// }

			// // Delete a node
			// node *deletenode(node *root, T key) {
			// 	if (root == NULL)
			// 		return root;
			// 	if (key < root->key)
			// 		root->left = deletenode(root->left, key);
			// 	else if (key > root->key)
			// 		root->right = deletenode(root->right, key);
			// 	else {
			// 		// If the node is with only one child or no child
			// 		if (root->left == NULL) {
			// 			node *temp = root->right;
			// 			free(root);
			// 			return temp;
			// 		}
			// 		else if (root->right == NULL) {
			// 			node *temp = root->left;
			// 			free(root);
			// 			return temp;
			// 		}

			// 		// If the node has two children
			// 		node *temp = minValuenode(root->right);

			// 		// Place the inorder successor in position of the node to be deleted
			// 		root->key = temp->key;

			// 		// Delete the inorder successor
			// 		root->right = deletenode(root->right, temp->key);
			// 	}
			// 	return root;
			// }
	};
}