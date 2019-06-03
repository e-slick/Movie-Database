//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#pragma once
#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
	if (root != nullptr)
		freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//Student must fill in
	//if the root is the leaf, delete that leaf
	// otherwise if the leaf is not null
		//recursive call of the leaf's left
		//recursive call of the leaf's right
		//now delete the leaf
	if (Root() == leaf) {
		deleteNode(leaf);
	}
	else {

	}
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);

	}
	else
		addNode(key, Root(), data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {

		if (leaf->Key() >= key) {
			if (leaf->Left() == nullptr) {
				Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
				newNodePtr->setKey(key);
				newNodePtr->setData(data);
				newNodePtr->setParent(newNodePtr);
				leaf->setLeft(newNodePtr);
			}
			else {
					addNode(key, leaf->Left(), data);
			}
		}
		else {
			if (leaf->Right() == nullptr) {
				Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
				newNodePtr->setKey(key);
				newNodePtr->setData(data);
				newNodePtr->setParent(newNodePtr);
				leaf->setRight(newNodePtr);
			}
			else {
					addNode(key, leaf->Right(), data);
			}
		}
	}



template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}


// Find a node



template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	if (node == nullptr) {
		return node;
	}
	else {

		if (node->Key() == key) {
			return node;
		}
		else {
			if (node->Key() >= key) {
				findNode(key, node->Left());
			}
			else {
				findNode(key, node->Right());
			}
		}
	}



	
}


template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	if (node == nullptr) {
		cout << "Tree is empty." << endl;
	}
	else {

		if (node->Left() != nullptr) {
			printInorder(node->Left());
		}

		cout << node->Key() << endl;

		if (node->Right() != nullptr) {
			printInorder(node->Right());
		}
	}


}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

template<typename DATATYPE, typename KEYTYPE>
inline void BSTree<DATATYPE, KEYTYPE>::displayMenu()
{
	int menuChoice;
	cout << "Welcome to IMDB simulator, please enter a number from the Menu Options " << endl;
	cout << "1: Read in Actors/Actresses" << endl;
	cout << "2: Read in Movies" << endl;
	cout << "3: Add Movie/Actor" << endl;
	cout << "4: Search Movie/Actor" << endl;
	cout << "5: Search and Delete Movie/Actor" << endl;
	cout << "6: Sort Movie/Actor by Field" << endl;
	cout << "7: Complete Actor/Movie Search on Any Searchable Field" << endl;
	cout << "8: Partial Search on Actor/Movie Searchable Field" << endl;
	cout << "9: Print To File" << endl;
	cin >> menuChoice;

	switch (menuChoice) {
	case 1:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Place items in a Binary Search Tree (BST) from a csv file sorted by Name.";
		break;
	case 2:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Place movies in a BST from a csv file sorted by Name.";
		break;
	case 3:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Add EITHER a movie OR an actor to their respective BST";
		break;
	case 4:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Search the specified BST for user specified search value";
		break;
	case 5:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "1. Search for user specified Movie/Actor and delete that position from the BST" << endl;
		cout << "2. Make sure the BST functions correctly after deletion";
		break;
	case 6:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Sort Movie/Actor by any user defined value." << endl;
		break;
	case 7:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Perform a 'complete' search such that the user input is == to the found value.";
		break;
	case 8:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Allow the user to input a string and search the BST for any 'complete' matches of the partial search.";
		break;
	case 9:
		cout << "[INSTRUCTIONS]" << endl;
		cout << "Ask for user filename, print entire database to file.";
		break;
	default:
		cout << "Please enter a valid menu option: ";
		cin >> menuChoice;
	}

}


//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}