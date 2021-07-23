#ifndef TestNV_h
#define TestNV_h

// A naive recursive C implementation for vertex cover problem for a tree
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

using namespace std;

// A utility function to find min of two integers
int min(int x, int y) { return (x < y)? x: y; }

/* A binary tree node has data, pointer to left child and a pointer to
right child */
struct node
{
	int data;
	vector<struct node *> child;
};

// The function returns size of the minimum vertex cover
int vCover(struct node *root)
{
	// The size of minimum vertex cover is zero if tree is empty or there
	// is only one node
	if (root == NULL)
		return 0;
	if (root->child.size() == 0)
		return 0;

	// Calculate size of vertex cover when root is part of it
	int size_incl = 1;
	for (auto i = root->child.begin(); i != root->child.end(); ++i)
	{
		size_incl += vCover(*i);
	}

	// Calculate size of vertex cover when root is not part of it
	int size_excl = root->child.size();
	auto i = root->child.size();
	while(i--)
	{
		for (auto j = root->child[i]->child.begin(); j != root->child[i]->child.end(); ++j)
			size_excl += vCover(*j);
	}

	// Return the minimum of two sizes
	return min(size_incl, size_excl);
}

// A utility function to create a node
struct node* newNode( int data )
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );
	temp->data = data;
	temp->child.reserve(100000);
	return temp;
}

#endif
