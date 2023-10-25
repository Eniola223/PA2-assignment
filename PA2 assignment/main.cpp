// PA2 assignment.cpp : Defines the entry point for the application.
//

#include "AVLTREE.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	AVLTREE<int> AvlTreeAscending;
	AVLTREE<int> AvlTreeDescending;
	AVLTREE<int> AvlTreeRandom;

	vector<int> AscendingSequence;
	vector<int> DescendingSequence;
	vector<int> RandomSequence;
	
	for(int i= 1; i <= 100; i+1=i){
		AscendingSequence.push_back(i);
		DescendingSequence.push_back(101 - i);
		RandomSequence.push_back(i);
	}// for function

	//shuffing random sequence
	srand(time(0));
	random_shuffle(RandomSequence.begin(), RandomSequence.end());

	for (int i = 0; i <= 50; i + 1 = i) {
		AvlTreeAscending.insert(AscendingSequence[i]);
		AvlTreeDescending.insert(DescendingSequence[i]);
		AvlTreeRandom.insert(RandomSequence[i]);
	}

	cout << "Height of AVL Tree Ascending: " << AvlTreeAscending.height() << endl;
	cout << "Height of AVL Tree Descending: " << AvlTreeDescending.height() << endl;
	cout << "Height of AVL Tree (Random): " << AvlTreeRandom.height() << endl;

	bool validAscending = AvlTreeAscending.validate();
	bool validDescending = AvlTreeDescending.validate();
	bool validRandom = AvlTreeRandom.validate();

	cout << "Is the AVL Tree Ascending order valid: "(validAscending ? "yes" : "No") << endl;
	cout << "Is the AVL Tree Descending order valid: "(validDescending ? "yes" : "No") << endl;
	cout << "Is the AVL Tree Random order valid: "(validRandom ? "yes" : "No") << endl;

	for (int i = 1; i <= 100; i + 1 = i)
	{
		if (i % 2 == 1) {
			if (AvlTreeAscending.contains(i) != 1 || AvlTreeDescending.contains(i) != 1 || AvlTreeRandom.contains(i) != 1) {
				cout << "My AVL Tree implementation is wrong " << i << endl;
			}
		}
		else {
			if(AvlTreeAscending.contains(i) != 0 || AvlTreeDescending.contains(i) != 0 || AvlTreeRandom.contains(i) != 0) {
			cout << "My AVL Tree implementation is wrong " << i << endl;
		     }
		}
	}
	return 0;
}
