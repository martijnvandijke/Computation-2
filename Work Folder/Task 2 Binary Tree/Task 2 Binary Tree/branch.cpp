////////////////////////////////////////////////////////////////
//
// Task Binary Tree
// File: branch.cpp
// Name: Martyn van Dijke
// Student number: 0887668
//
// Contents: Bodies of member functions of class 'branch'
//
// You'll need to implement member functions in this file.
// 
// Skeleton function by patrick@magma-da.com
////////////////////////////////////////////////////////////////
#include "tree.h"

#include <fstream>
#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

//
// Constructor of a branch tree element
// This will allocate memory to save the word.
// It sets the _word pointer, and copies the word into it.
// It also initializes the _left and _right
// pointers to nullptr (meaning the branch is a leaf).
//
branch::branch(string word)
{
    _word = word;
    _left = _right = nullptr;
}

//
// The destructor of a branch tree element.
// Frees the memory that was allocated to store the word.
// It does NOT delete the _left and _right child branches.
// Therefore this destructor is non-recursive.
//
branch::~branch()
{
    destroy();
}

//
// Destroys and deletes this branch of the tree and everything below it.
// This means that it recursively destroys the subtrees that _left
// and _right point to.
// Finally, it self-destructs this branch object by
// calling delete(this);
//
void branch::destroy()
{
    if (_left)
        delete _left;
    if (_right)
        delete _right;
}

//
// Adds a word to this tree element recursively.
//
// The tree is maintained such that the words are
// sorted alphabetically in case the tree is traversed in order.
// You can use the function str2->compare(str1). This function returns a
// number < 0 in case str1 is alphabetically before str2, and
// a number > 0 in case str2 is after str1 in the dictionary.
// In case str2->compare(str1) returns 0, the strings are equal.
// The main idea is to build the tree such that for each branch
// the _left child-tree contains words that are alphabetically to the
// left of the word, and the _right subtree the words that are
// alphabetically after the word of the branch.
//
// Your target: About 12 lines of code (and use recursion!)
//
void branch::add(string word)
{
    // Implement something along these lines:
    // compare word with _word using word->compare(_word->data());
    // if word is before _word then add word to left childtree
    // if word is after _word then add word to right childtree
    // if word is equal to _word then do nothing because the word
    //   already exists.

    // In case a subtree already exists, recursively call this
    // member function on the _left or _right subtree.
    // In case there is no such subtree, make a new leaf-branch.
	
	int i; 
	i = word.compare(_word);
	if (i < 0) {			//string should go left
		//cout << "I need to go left" << endl;
		
		if (	_left == nullptr) {	//there is no brach connected to this word
			_left = new branch(word);		
			cout	<< "Added the word " 
					<< word
					<< " to the tree"  << endl;
		}

		else {
			_left->add(word);
		}

	}
	if (i > 0) {			//string should go right
		//cout << "I need to go right" << endl;
		
		if (	_right == nullptr) {	//there is no brach connected to this word
			_right = new branch(word);
			cout << "Added the word "
				<< word
				<< " to the tree" << endl;
		}

		else {
			_right->add(word);
		}

	}
	//else {
		//cout << "Word "
			//<< word
			//<< " already in the database" << endl;
	//}

	//cout << i << endl;
    //cout << "The function branch::add is yet to be implemented!" << endl;
}

//
// Returns the length of the longest path from any
// branch to the root.
// This is a recursive routine as well.
//
// Your target: 8 lines of code.
//
int branch::height() const
{

	if ( _left == nullptr) {// if nothing is connected to the left

			if ( _right == nullptr) { //and nothing is connected to the right
				return  1; //then there is no deeper sub tree
			}

			else {	// if something is connected to the right 
				return _right->height() + 1;	
			}

	}

	else{
		if (_right == nullptr) { //if nothing is connected the the right
			return _left->height() +1 ;	
		}

		else{
			return max( _left->height(), _right->height()) + 1	;
		}
	}

}

//
// Count the number of words (branches) of the subtree.
//
int branch::count() const
{
	if (_left == nullptr) {// if nothing is connected to the left

		if (_right == nullptr) { //and nothing is connected to the right
			return  1; //then there is no deeper sub tree
		}

		else {	// if something is connected to the right 
			return _right->count() + 1;
		}

	}

	else {
		if (_right == nullptr) { //if nothing is connected the the right
			return _left->count() + 1;
		}

		else {
			return _left->count() + _right->height();
		}
	}

    //cout << "The function branch::height is yet to be implemented!" << endl;
    //return -1;
}

//
// Returns a pointer to the branch that contains the word
// Will return nullptr in case the word is not in this
// (sub-)tree.
//
// Target: some 15 lines (recursive)
//
branch* branch::find(string word)
{
    //
    // TO BE IMPLEMENTED BY YOU
    //

    cout << "The function branch::find is yet to be implemented!" << endl;
    return nullptr;
}

//
// Prints all words of the subtree of this branch in
// alphabetical order.
// Since we maintain the tree such that it is always
// alphabetically sorted, we only need to traverse the
// tree in-order (recursively) and print the elements.
//
void branch::print_words_alphabetically() const
{
    if (_left)
        _left->print_words_alphabetically();

    cout << _word << endl;

    if (_right)
        _right->print_words_alphabetically();

}

/////////////////////////////////////////////////////////////////
//
// Implementing the functions below is optional.
// Doing so will earn you kudos.
//
/////////////////////////////////////////////////////////////////

//
// Removes a word from the tree, and returns a
// pointer to the branch that contains the deleted word. It does
// not delete the branch itself.
// ptr_to_branch_ptr is the pointer of the parent branch that should be 
// modified to update the structure of the tree.
// Remember to maintain the relative ordering of the words in the tree!
// This can be quite tricky
//
branch* branch::remove(string word, branch** ptr_to_branch_ptr)
{
    //
    // TO BE IMPLEMENTED BY YOU (optionally)
    //

    cout << "The function branch::remove is yet to be implemented!" << endl;
    return 0;
}

//
// Help routine for branch::remove
// this recursive function finds the 'alphabetically largest'
// word in (sub-)tree and return a pointer to the branch that
// contains it.
//
branch* branch::find_branch_with_largest_word()
{
    if (_right)
        return _right->find_branch_with_largest_word();
    else
        return this;
}


