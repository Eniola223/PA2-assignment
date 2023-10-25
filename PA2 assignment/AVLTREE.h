// AVLTREE.h : Include file for standard system include files or project specific include files.
// Project creator: Eniola Akinola
#pragma once

#include <iostream>
#include "AVLNode.h"

template <typename T>
class AVLTREE {
private:
	AVLNode<T>* root;
public: 
	AVLTREE(): root(nullptr){
	// creating a pointer to the root AVLNode
	}

	~AVLTREE() {
		destroy tree(root);
	}
	void destroyTree(AVLNode<T>* node) {
		if (node) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}
	int height() {
		return getheight(root);
}
	int getheight(AVLNode<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			int leftheight = getheight(node->left);
			int rightheight = getheight(node->right);
			return 1 + max(leftheight, rightheight);
				// return 1 is used to calcute the total height of the node from both the left height and rightheight
		}
	}

	void insert(T Value) {
		root = insertRec(root, value);
	}

	int contains(T value) {
		return containsRec(root, value);
	}

	int validate() {
		return validateRec(root);
	}
private:
	AVLNode<T>* insertRec(AVLNode<T>* root, T value) {
		if (!root) {
			//when the root is NULL
			return new AVLNode<T>(value);
		}
		if (value < root->data)
		{
			root->left = insert(root->left, value);
		}
		else if (value >root->data)
		{
			root->right = insert(root->right, value);
		}
		else
		{
			return root;
		}
		root->height = 1 max(getheight(root->left), getheight(root->right));

		int balance = getbalance(root);

		if (balance > 1) 
		{
			if (value > root->left->data) {
				return rightrotate(root);
			}
			else {
				root->left = leftrotate(root->left);
				return rightrotate(root);
			}
		} // if balance function

		if (balance < -1) 
		{
			if (value > root->right->data) {
				return leftrotate(root);
			}
			else {
				root->left = rightrotate(root->right);
				return leftrotate(root);
			}
		}
		return root;
	}// Insert private function

	int containsRec(AVLNode<T>* node, T value) {
		if (node == nullptr)
			return 0;
		if (node->data == value)
			return 1;
		if (value < node->data)
			return containsRec(node->left, value);
		else
			return containsRec(node->right, value);
	}
	bool validate(AVLNode<T>* root) {
		if (!root) {
			return true;
		}
		int balance = getBalance(root);
		if (balance > 1 || balance < -1) {
			return false;
		}
		return validate(root->left) && validate(root->right);
	}
	int getBalance(AVLNode<T>* node) {
		if (node == nullptr) {
			return 0;
		}
		int leftHeight;
		if (node->left) {
			leftHeight = node->left->height;
		}
		else {
			leftHeight = 0;
		}
		int rightHeight;
		if (node->right) {
			rightHeight = node->right->height;
		}
		else {
			rightHeight = 0;
		}
		return leftHeight - rightHeight;
	}//getBalance function
};
 