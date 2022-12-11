#pragma once

#include <iostream>
#include "./algorithm.hpp"
#include <memory>

namespace ft {

	// template<class T>
	// using ft::Node<T>* _saver;
	// // static ft::Node<T>*	_saver;

	template<typename T>
	struct Node {
		T			value;
		Node		*right, *left, *parent;

		Node(T _value = T(), Node *_right = nullptr, Node *_left = nullptr, Node *_parent = nullptr)
			: value(_value), right(_right), left(_left), parent(_parent) {}
		Node(Node * obj){
			this->value = obj->value;
			this->right = obj->right;
			this->left = obj->left;
			this->parent = obj->parent;
		}
		Node(const Node& obj){ *this = obj; }
		Node& operator = (const Node& obj){
			this->value = obj.value;
			this->right = obj.right;
			this->left = obj.left;
			this->parent = obj.parent;
			return *this;
		}

		bool operator == (const Node& obj){
			return ((this->value == obj.value) && (this->right = obj.right)
				&& (this->left == obj.left) && (this->parent == obj.parent));
		}

		template<class T1>
		friend std::ostream & operator << (std::ostream &out, const Node<T> &obj);
	};

	template<class T>
	std::ostream	&operator << (std::ostream &out, const Node<T> &obj){
		out << obj.value;
		return out;
	}

	template<typename T, class Comp = ft::less<T> >
	class bst_iterator{
		public :
			
			typedef ft::Node<T> *														iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		public :

			iterator_type 	_node;
			iterator_type	_saver;

			iterator_type min_node(iterator_type node) {
				iterator_type current = node;
				while (current && current->left != nullptr)
					current = current->left;
				return current;
			}

			iterator_type max_node(iterator_type node) {
				iterator_type current = node;
				if (current->parent != nullptr)
					current = current->parent;
				while (current && current->right != nullptr)
					current = current->right;
				return current;
			}

			iterator_type base() { return _node; };

			bst_iterator() : _node(nullptr) {}

			bst_iterator(iterator_type node)
				: _node(node) {}

			bst_iterator(iterator_type node, iterator_type noode) : _node(node) { 
				if (noode != nullptr)
					_saver = noode;
			}

			bst_iterator(const bst_iterator& obj) { *this = obj; }

			bst_iterator& operator = (const bst_iterator& obj){
				this->_node = obj._node;
				this->_saver = obj._node;
				return *this;
			}

			~bst_iterator() {}

			bool operator == (const bst_iterator& obj) { return (_node == obj._node); }
			bool operator != (const bst_iterator& obj) { return !(*this == obj); }

			bst_iterator& operator ++ (){
				if (_node == nullptr)
					return * this;
				if (_node->right != nullptr)
					_node = min_node(_node->right);
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			bst_iterator& operator -- (){
				if (_node == nullptr) {
					_node = max_node(_saver);
					return *this;
				}
				if (_node->left != nullptr){
					_node = _node->left;
					while (_node->right != nullptr)
						_node = _node->right;
				}
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			T	operator * () { return this->_node->value; }

			T*	operator -> () { return &this->_node->value; }

			bst_iterator operator ++ (int){
				bst_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bst_iterator operator -- (int){
				bst_iterator tmp = *this;
				--(*this);
				return tmp;
			}
	};

	template<typename T, class Comp = ft::less<T> >
	class bst_const_iterator{
		public :
			
			typedef ft::Node<T> *														iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		public :

			iterator_type 	_node;
			iterator_type	_saver;

			iterator_type min_node(iterator_type node) {
				iterator_type current = node;
				while (current && current->left != nullptr)
					current = current->left;
				return current;
			}

			iterator_type max_node(iterator_type node) {
				iterator_type current = node;
				if (current->parent != nullptr)
					current = current->parent;
				while (current && current->right != nullptr)
					current = current->right;
				return current;
			}

			iterator_type base() { return _node; };

			bst_const_iterator() : _node(nullptr) {}

			bst_const_iterator(iterator_type node)
				: _node(node) {}

			bst_const_iterator(iterator_type node, iterator_type noode) : _node(node) { 
				if (noode != nullptr)
					_saver = noode;
			}

			bst_const_iterator(const bst_const_iterator& obj) { *this = obj; }

			bst_const_iterator& operator = (const bst_const_iterator& obj){
				this->_node = obj._node;
				this->_saver = obj._node;
				return *this;
			}

			~bst_const_iterator() {}

			bool operator == (const bst_const_iterator& obj) { return (_node == obj._node); }
			bool operator != (const bst_const_iterator& obj) { return !(*this == obj); }

			bst_const_iterator& operator ++ (){
				if (_node == nullptr)
					return * this;
				if (_node->right != nullptr)
					_node = min_node(_node->right);
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			bst_const_iterator& operator -- (){
				if (_node == nullptr) {
					_node = max_node(_saver);
					return *this;
				}
				if (_node->left != nullptr){
					_node = _node->left;
					while (_node->right != nullptr)
						_node = _node->right;
				}
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			T	operator * () { return this->_node->value; }

			T*	operator -> () { return &this->_node->value; }

			bst_const_iterator operator ++ (int){
				bst_const_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bst_const_iterator operator -- (int){
				bst_const_iterator tmp = *this;
				--(*this);
				return tmp;
			}
	};

	template<typename T, class Comp = ft::less<T> >
	class bst_reverse_iterator{
		public :
			
			typedef ft::Node<T> *														iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		public :

			iterator_type 	_node;
			iterator_type	_saver;

			iterator_type min_node(iterator_type node) {
				iterator_type current = node;
				while (current && current->left != nullptr)
					current = current->left;
				return current;
			}

			iterator_type max_node(iterator_type node) {
				iterator_type current = node;
				if (current->parent != nullptr)
					current = current->parent;
				while (current && current->right != nullptr)
					current = current->right;
				return current;
			}

			iterator_type base() { return _node; };

			bst_reverse_iterator() : _node(nullptr) {}

			bst_reverse_iterator(iterator_type node)
				: _node(node) {}

			bst_reverse_iterator(iterator_type node, iterator_type noode) : _node(node) { 
				if (noode != nullptr)
					_saver = noode;
			}

			bst_reverse_iterator(const bst_reverse_iterator& obj) { *this = obj; }

			bst_reverse_iterator& operator = (const bst_reverse_iterator& obj){
				this->_node = obj._node;
				this->_saver = obj._node;
				return *this;
			}

			~bst_reverse_iterator() {}

			bool operator == (const bst_reverse_iterator& obj) { return (_node == obj._node); }
			bool operator != (const bst_reverse_iterator& obj) { return !(*this == obj); }

			bst_reverse_iterator& operator ++ (){

				if (_node == nullptr) {
					_node = max_node(_saver);
					return *this;
				}
				if (_node->left != nullptr){
					_node = _node->left;
					while (_node->right != nullptr)
						_node = _node->right;
				}
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			bst_reverse_iterator& operator -- (){
				if (_node == nullptr)
					return * this;
				if (_node->right != nullptr)
					_node = min_node(_node->right);
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			T	operator * () { return this->_node->value; }

			T*	operator -> () { return &this->_node->value; }

			bst_reverse_iterator operator ++ (int){
				bst_reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bst_reverse_iterator operator -- (int){
				bst_reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}
	};

	template<typename T, class Comp = ft::less<T> >
	class bst_const_reverse_iterator{
		public :
			
			typedef ft::Node<T> *														iterator_type;
			typedef typename ft::bidirectional_iterator_tag						 		iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		public :

			iterator_type 	_node;
			iterator_type	_saver;

			iterator_type min_node(iterator_type node) {
				iterator_type current = node;
				while (current && current->left != nullptr)
					current = current->left;
				return current;
			}

			iterator_type max_node(iterator_type node) {
				iterator_type current = node;
				if (current->parent != nullptr)
					current = current->parent;
				while (current && current->right != nullptr)
					current = current->right;
				return current;
			}

			iterator_type base() { return _node; };

			bst_const_reverse_iterator() : _node(nullptr) {}

			bst_const_reverse_iterator(iterator_type node)
				: _node(node) {}

			bst_const_reverse_iterator(iterator_type node, iterator_type noode) : _node(node) { 
				if (noode != nullptr)
					_saver = noode;
			}

			bst_const_reverse_iterator(const bst_const_reverse_iterator& obj) { *this = obj; }

			bst_const_reverse_iterator& operator = (const bst_const_reverse_iterator& obj){
				this->_node = obj._node;
				this->_saver = obj._node;
				return *this;
			}

			~bst_const_reverse_iterator() {}

			bool operator == (const bst_const_reverse_iterator& obj) { return (_node == obj._node); }
			bool operator != (const bst_const_reverse_iterator& obj) { return !(*this == obj); }

			bst_const_reverse_iterator& operator ++ (){

				if (_node == nullptr) {
					_node = max_node(_saver);
					return *this;
				}
				if (_node->left != nullptr){
					_node = _node->left;
					while (_node->right != nullptr)
						_node = _node->right;
				}
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->left) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			bst_const_reverse_iterator& operator -- (){
				if (_node == nullptr)
					return * this;
				if (_node->right != nullptr)
					_node = min_node(_node->right);
				else {
					iterator_type parent = _node->parent;
					while (parent != nullptr && _node == parent->right) {
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
				return (*this);
			}

			T	operator * () { return this->_node->value; }

			T*	operator -> () { return &this->_node->value; }

			bst_const_reverse_iterator operator ++ (int){
				bst_const_reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}

			bst_const_reverse_iterator operator -- (int){
				bst_const_reverse_iterator tmp = *this;
				--(*this);
				return tmp;
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
				if (value < node->value)
				{
					Node *lchild = insert(node->left, value);
					node->left  = lchild;
			
					// Set parent of root of left subtree
					lchild->parent = node;
				}
				else if (value > node->value)
				{
					Node *rchild = insert(node->right, value);
					node->right  = rchild;
			
					// Set parent of root of right subtree
					rchild->parent = node;
				}
			
				/* return the (unchanged) Node pointer */
				return node;
			}

			Node *min_node(Node *node) {
				Node *current = node;
				while (current && current->left != NULL)
					current = current->left;
				return current;
			}

			Node *max_node(Node *node) {
				Node *current = node;
				while (current && current->right != NULL)
					current = current->right;
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

			void delete_tree(Node* node){
				if (node == nullptr) return;
			
				delete_tree(node->left);
				delete_tree(node->right);

				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void inorder(Node *node) {
				if (node != NULL) {
					inorder(node->left);

					std::cout << node->value << " -> ";

					inorder(node->right);
				}
				// inorder(node->left);
				// std::cout << "Node : " << node->value << std::endl;
				// if (node->parent == NULL)
				// printf("Parent : NULL \n");
				// else
				// std::cout << "Parent :" << node->parent->value; << std::endl;
				// inorder(node->right);
			}

			Node *search(Node* node, value_type key){
				if (node == nullptr)
					return nullptr;
				if (node->data == key)
					return node;
				if (key < node->data) {
					search(node->left, key);
				} else {
					search(node->right, key);
				}
			}
	};
}