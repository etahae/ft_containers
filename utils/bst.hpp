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

	template<typename T, typename Compare>
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

	template <class T, class Compare = ft::less<T>, class Node = ft::Node<T>,
			class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class bst
	{
		public :
	
		 	typedef T   value_type;

		 	typedef Node node_type;

		 	typedef Node_Alloc  node_alloc;

		 	typedef ft::bst_iterator<Node, Compare> iterator;

		 	typedef ft::bst_const_iterator<Node, Compare> const_iterator;

		 	typedef size_t size_type;

			bst(const node_alloc& node_alloc_init = node_alloc()) : _node_alloc(node_alloc_init){
				_last_node = _node_alloc.allocate(1);
				_node_alloc.construct(_last_node, Node(_last_node, _last_node, _last_node));
			}

			~bst(){
				_node_alloc.destroy(_last_node);
				_node_alloc.deallocate(_last_node, 1);	
			}

		// 	ft::pair<iterator, bool> insertPair(value_type to_insert)
		// 	{
		// 		Node * new_node = _node_alloc.allocate(1);
		// 		Node * prev_node = _last_node;
		// 		Node * start_node = _last_node->parent;

		// 		// side == false = left; side == true = right;
		// 		bool side = true;

		// 		while (start_node != _last_node)
		// 		{
		// 			int curkey = start_node->value.first;
		// 			if (curkey == to_insert.first)
		// 				return (ft::make_pair(iterator(start_node, _last_node), false));
		// 			prev_node = start_node;
		// 			if (to_insert.first > curkey)
		// 			{
		// 				side = true;
		// 				start_node = start_node->right;
		// 			}
		// 			else
		// 			{
		// 				side = false;
		// 				start_node = start_node->left;
		// 			}
		// 		}
		// 		_node_alloc.construct(new_node, Node(to_insert, prev_node, _last_node, _last_node));
				
		// 		if (prev_node == _last_node)
		// 			_last_node->parent = new_node;
		// 		else if (side == true)
		// 			prev_node->right = new_node;
		// 		else
		// 			prev_node->left = new_node;
				
		// 		_last_node->left = _BST_get_lower_node(_last_node->parent);
		// 		_last_node->right = _BST_get_higher_node(_last_node->parent);
		// 		_last_node->value.first += 1;
		// 		return (ft::make_pair(iterator(new_node, _last_node), true));
		// 	}

		// 	/*
		// 	** @brief need a pair create like : make_pair(key, mapped_type())
		// 	*/
			void removeByKey(value_type to_remove)
			{ _removeByKey(_last_node->parent, to_remove); }

			node_type* searchByKey(value_type to_remove){
				node_pointer node = _last_node->parent;

				while (node != _last_node){
					if (node->value.first == to_remove.first)
						return (node);
					if (node->value.first > to_remove.first)
						node = node->left;
					else
						node = node->right;
				}
				return (node);
			}

		// 	/*
		// 	** @brief Swap this elements with "x" elements
		// 	*/
		// 	void swap(self& x)
		// 	{
		// 		if (&x == this)
		// 			return ;
				
		// 		node_pointer save = this->_last_node;
		// 		this->_last_node = x._last_node;
		// 		x._last_node = save;
		// 	}

		// 	/*
		// 	** @brief return max_size of allocator.
		// 	*/
		// 	size_type max_size() const
		// 	{ return (node_alloc().max_size()); }

		// 	// last_node parent = root of tree, last_node right = last node, last_node left = first node
		// 	node_pointer    _last_node;
		// 	node_alloc      _node_alloc;

		private :

		// 	/*
		// 	** @brief Give node pointer on lower key.
		// 	*/
			node_type* _BST_get_lower_node(node_pointer root)
			{
				while (root != _last_node && root->left != _last_node)
					root = root->left;
				return (root);
			}

		// 	/*
		// 	** @brief Give node pointer on higher key.
		// 	*/
			node_type* _BST_get_higher_node(node_pointer root)
			{
				while (root != _last_node && root->right != _last_node)
					root = root->right;
				return (root);
			}

		// 	/*
		// 	** @brief Used to re set link between node is necessary, and
		// 	** delete node.
		// 	*/
			void _replaceNodeInParent(node_pointer node, node_pointer new_node)
			{
				if (node->parent != _last_node)
				{
					if (_last_node->parent == node)
						_last_node->parent = new_node;

					if (node == node->parent->left)
						node->parent->left = new_node;
					else
						node->parent->right = new_node;
				}
				else
					_last_node->parent = new_node;

				_last_node->left = _BST_get_lower_node(_last_node->parent);
				_last_node->right = _BST_get_higher_node(_last_node->parent);
				_last_node->value.first -= 1;
				
				new_node->parent = node->parent;
				
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

		// 	/*
		// 	** @brief used to move replacer node and re set all link between
		// 	** node where it's necessary and delete to_remove.
		// 	*/
		// 	void _replaceDoubleChildren(node_pointer& to_remove, node_pointer new_node)
		// 	{
		// 		if (new_node->parent != _last_node)
		// 		{
		// 			if (new_node->parent != to_remove)
		// 				new_node->parent->left = new_node->right;
		// 		}
				
		// 		new_node->parent = to_remove->parent;
		// 		if (to_remove->left != new_node)
		// 			new_node->left = to_remove->left;
		// 		if (to_remove->right != new_node)
		// 			new_node->right = to_remove->right;

		// 		if (to_remove->parent != _last_node)
		// 		{
		// 			if (to_remove->parent->left == to_remove)
		// 				to_remove->parent->left = new_node;
		// 			else if (to_remove->parent->right == to_remove)
		// 				to_remove->parent->right = new_node;
		// 		}
		// 		else
		// 			_last_node->parent = new_node;
					
		// 		if (to_remove->left != _last_node && to_remove->left != new_node)
		// 			to_remove->left->parent = new_node;
		// 		if (to_remove->right != _last_node && to_remove->right != new_node)
		// 			to_remove->right->parent = new_node;

		// 		if (to_remove->parent != _last_node)
		// 		{
		// 			to_remove->left = _last_node;
		// 			to_remove->right = _last_node;
		// 			to_remove->parent = new_node;
		// 		}

		// 		_last_node->left = _BST_get_lower_node(_last_node->parent);
		// 		_last_node->right = _BST_get_higher_node(_last_node->parent);
		// 		_last_node->value.first -= 1;

		// 		_node_alloc.destroy(to_remove);
		// 		_node_alloc.deallocate(to_remove, 1);
		// 	}

		// 	/*
		// 	** @brief need a pair create like : make_pair(key, mapped_type())
		// 	*/
			void _removeByKey(node_pointer node, value_type to_remove)
			{
				if (to_remove.first < node->value.first)
				{
					_removeByKey(node->left, to_remove);
					return ;
				}

				if (to_remove.first > node->value.first)
				{
					_removeByKey(node->right, to_remove);
					return ;
				}

				if (node->left != _last_node && node->right != _last_node)
				{
					node_pointer successor = _BST_get_lower_node(node->right);
					_replaceDoubleChildren(node, successor);
					return ;
				}
				else if (node->left != _last_node)
					_replaceNodeInParent(node, node->left);
				else if (node->right != _last_node)
					_replaceNodeInParent(node, node->right);
				else
					_replaceNodeInParent(node, _last_node);
			}
	};
}