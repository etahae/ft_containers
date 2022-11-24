#pragma once

#include <iostream>
#include "./algorithm.hpp"
#include <memory>

namespace ft {

	template<typename T>
	struct Node {
		T			value;
		Node		*right, *left;

		Node() : value(), right(nullptr), left(nullptr) {}
		Node(T _value)
			: value(_value), right(nullptr), left(nullptr) {}
		Node(Node *_right, Node *_left)
			: right(_right), left(_left) {}
		Node(T _value, Node *_right, Node *_left)
			: value(_value), right(_right), left(_left) {}
		Node(const Node& obj){ *this = obj; }
		Node& operator = (const Node& obj){
			this->value = obj.value;
			this->right = obj.right;
			this->left = obj.left;
			return *this;
		}
	};

	template<typename T>
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

		public :

			iterator_type base() { return _node; };

			bst_iterator() : _node(nullptr) {}

			bst_iterator(iterator_type node)
				: _node(node) {}

			bst_iterator(const bst_iterator& obj) { *this = obj; }

			bst_iterator& operator = (const bst_iterator& obj){
				this->_node = obj._node;
				return *this;
			}

			~bst_iterator() {}

			bool operator == (const bst_iterator& obj) { return (_node->key == obj._node->key); }
			bool operator != (const bst_iterator& obj) { return !(_node = obj); }

			bst_iterator& operator ++ (){
				return (*this);
			}
			bst_iterator& operator -- (){
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

	template<typename T>
	class bst_const_iterator{
		public :
			
			typedef T*																	iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		protected :

			iterator_type 	_node;

		public :

			iterator_type base() { return _node; };

			bst_const_iterator() : _node(nullptr) {}

			bst_const_iterator(iterator_type node)
				: _node(node) {}

			bst_const_iterator(const bst_const_iterator& obj) { *this = obj; }

			bst_const_iterator& operator = (const bst_const_iterator& obj){
				this->_node = obj._node;
				return *this;
			}

			~bst_const_iterator() {}

			bool operator == (const bst_const_iterator& obj) { return (_node->key == obj._node->key); }
			bool operator != (const bst_const_iterator& obj) { return !(_node = obj); }

			bst_const_iterator& operator ++ (){
				return (*this);
			}
			bst_const_iterator& operator -- (){
				return (*this);
			}

			reference	operator * () { return this->_node->value; }

			pointer		operator -> () { return &this->_node->value; }

			bst_const_iterator& operator ++ (int){
				bst_const_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			bst_const_iterator& operator -- (int){
				bst_const_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template <class T, class Compare = ft::less<T>, class Type_Alloc = std::allocator<T>,
		class Node = ft::Node<T>, class Node_Alloc = std::allocator<Node> >
	class bst
	{
		public :
	
		 	typedef T   							value_type;
		 	typedef Node_Alloc  					node_alloc;
		 	typedef size_t 							size_type;

		 	typedef ft::bst_iterator<Node> 			iterator;
		 	typedef ft::bst_const_iterator<Node> 	const_iterator;

			Node*			_node;
			node_alloc		_node_alloc;

			bst(){_node = nullptr;}

			bst(const bst& obj){ this = obj; }

			bst& operator = (const bst& obj){
				this->_node = obj._node;
				this->_node_alloc = obj._node_alloc;
			}

			~bst(){
				_node_alloc.destroy(_node);
				_node_alloc.deallocate(_node, 1);	
			}

			Node*	insert(Node* node, T value) {
				if (node == nullptr){
					node = _node_alloc.allocate(1);
					_node_alloc.construct(node, Node(value));
				}
				else if (value < node->value)
				 	node->left = insert(node->left, value);
				else
				 	node->right = insert(node->right, value);
				return node;
			}

			Node *min_node(Node *node) {
				Node *current = node;
				while (current && current->left != NULL)
					current = current->left;
				return current;
			}

			Node *delete_node(Node *node, T value) {
				// Return if the tree is empty
				if (node == NULL) return node;

				// Find the Node to be deleted
				if (value < node->value)
					node->left = delete_node(node->left, value);
				else if (value > node->value)
					node->right = delete_node(node->right, value);
				else {
					// If the Node is with only one child or no child
					if (node->left == NULL) {
						Node *temp = node->right;
						_node_alloc.destroy(node);
						_node_alloc.deallocate(node, 1);
						return temp;
					}
					else if (node->right == NULL) {
						Node *temp = node->left;
						_node_alloc.destroy(node);
						_node_alloc.deallocate(node, 1);
						return temp;
					}
					Node *temp = min_node(node->right);

					// Place the inorder successor in position of the node to be deleted
					node->value = temp->value;

					// Delete the inorder successor
					node->right = delete_node(node->right, temp->value);
				}
				return node;
			}
	};
}