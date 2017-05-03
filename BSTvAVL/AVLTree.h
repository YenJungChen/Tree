/**
* Models an AVL tree
* @author William Duncan
* @since 99-99-9999
*/

#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <queue>
#include<cstdlib>

#ifndef AVLTREE_H
#define AVLTREE_H

using namespace std;

/* exception class*/
class AVLTreeException
{
private:
	string message;
public:
	/**
	* Constructs an instance of <code>AVLTreeException</code> with the
	* specified detail message.
	* @param msg the detail message.
	*/
	AVLTreeException(const string& aMessage)
	{
		message = aMessage;
	}
	/**
	* Returns a message
	* @return a message
	*/
	string what() const
	{
		return message;
	}
};



template <typename E>
class AVLTree
{
private:
	typedef enum _BalancedFactor { LH = -1, EH, RH } BalancedFactor;
	typedef void(*FuncType)(const E& item);
	class Node
	{
	public:
		/**
		Constructs a node with a given data value.
		@param s the data to store in this node
		*/
		Node(E s);
	private:
		/**
		* the data in this node
		*/
		E data;
		/**
		* the left child
		*/
		Node * left;
		/**
		* the right child
		*/
		Node * right;
		/**
		* the balanced factor of this node
		*/
		BalancedFactor bal;
		friend class AVLTree<E>;
	};
	/**
	* An auxiliary function that recursively free the memory
	* allocated for the nodes of this tree.
	* @param subtreeRoot a root of this subtree
	*/
	void recDestroy(Node* subtreeRoot);
	/**
	* An auxiliary method that inserts a new node in the tree or
	* updates a node if the data is already in the tree.
	* @param curRoot a root of a subtree
	* @param newNode the new node to be inserted
	* @param taller indicates whether the subtree becomes
	* taller after the insertion
	* @return a reference to the new node
	*/
	Node* insert(Node* curRoot, Node* newNode, bool& taller);

	/**
	* An auxiliary method that left-balances the specified node
	* @param curRoot the node to be left-balanced
	* @param taller indicates whether the tree becomes taller
	* @return the root of the subtree after left-balancing
	*/
	Node* leftBalance(Node* curRoot, bool& taller);

	/**
	* An auxiliary method that right-balances the specified node
	* @param curRoot the node to be right-balanced
	* @param taller indicates whether the tree becomes taller
	* @return the root of the subtree after right-balancing
	*/
	Node* rightBalance(Node* curRoot, bool& taller);
	/**
	* An auxiliary method that Left-rotates the subtree at this node
	* @param node the node at which the left-rotation occurs.
	* @return the new node of the subtree after the left-rotation
	*/
	Node* rotateLeft(Node* node);

	/**
	* An auxiliary method that right-rotates the subtree at this node
	* @param node the node at which the right-rotation occurs.
	* @return the new node of the subtree after the right-rotation
	*/
	Node* rotateRight(Node* node);

	/**
	* An auxiliary method that in-order traverses the subtree at the specified node
	* @param node the root of a subtree
	* @param func the function to be applied to the data in each node
	*/
	void traverse(Node* node, FuncType func);

	/**
	* An auxiliary method that deletes the specified node from this tree
	* @param node the node to be deleted
	* @param key the item stored in this node
	* @param shorter indicates whether the subtree becomes shorter
	* @param success indicates whether the node was successfully deleted
	* @return a reference to the deleted node
	*/
	Node* remove(Node* node, const E& key, bool& shorter, bool& success);
	/**
	* An auxiliary method that right-balances this subtree after a deletion
	* @param node the node to be right-balanced
	* @param shorter indicates whether the subtree becomes shorter
	* @return a reference to the root of the subtree after right-balancing.
	*/
	Node* deleteRightBalance(Node* node, bool& shorter);
	/**
	* An auxiliary method that left-balances this subtree after a deletion
	* @param node the node to be left-balanced
	* @param shorter indicates whether the subtree becomes shorter
	* @return a reference to the root of the subtree after left-balancing.
	*/
	Node* deleteLeftBalance(Node* node, bool& shorter);

	/**
	* An auxiliary method to determine the height of the subtree rooted at
	* the specified node
	* @param node the root of a subtree
	* @return the height of the subtree rooted at the specified node
	*/
	int height(Node* node) const;
	/**
	* the root of this tree
	*/
	Node* root;
	/**
	* the size of this tree
	*/
	int count;
public:
	/**
	* Constructs an empty AVL tree;
	*/
	AVLTree();

	/**
	* destructor - returns the AVL tree memory to the system;
	*/
	~AVLTree();

	/**
	* Determines whether the tree is empty.
	* @return true if the tree is empty;  otherwise, false
	*/
	bool isEmpty() const;

	/**
	Inserts an item into the tree.
	@param obj the value to be inserted.
	*/
	void insert(const E& obj);

	/**
	* Determine whether an item is in the tree.
	* @param item item with a specified search key.
	* @return true on success; false on failure.
	*/
	bool inTree(const E& item) const;

	/**
	* Delete an item from the tree.
	* @param item item with a specified search key.
	*/
	void remove(const E& item);

	/**
	* returns the item with the given search key.
	* @param key the key of the item to be retrieved
	* @return the item with the specified key
	* @throws AVLTreeException when no such element exists
	*/
	const E& retrieve(const E& key) const throw (AVLTreeException);

	/**
	* This function traverses the tree in in-order
	* and calls the function Visit once for each node.
	* @param func the function to apply to the data in each node
	*/
	void traverse(FuncType func);

	/**
	* Returns the number of nodes in this tree.
	* @return the size of this tree.
	*/
	int size() const;

	/**
	* Computes the depth  of the specified search key in this tree.
	* @param item the search key
	* @return the depth of the specified search key if it is in the.
	* this tree. If it is not, -1-d, where d is the depth at which
	* it would have been found it inserted in the current tree.
	*/
	int depth(const E& item) const;
	/**
	* Gives the height of this tree.
	* @return the height of this tree
	*/
	int height() const;

	/**
	* This function traverses the tree in level-order
	* and calls the function func once for each node.
	* @param func the function to apply to the data in each node
	*/
	void levelTraverse(FuncType func);
};
//AVLTREE_H
#endif
