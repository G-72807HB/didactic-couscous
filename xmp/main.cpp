/* Dynamic programming based program for Vertex Cover problem for
a Binary Tree */
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
	int vc;
	vector<struct node *> child;
};

// A memoization based function that returns size of the minimum vertex cover.
int vCover(struct node *root)
{
	// The size of minimum vertex cover is zero if tree is empty or there
	// is only one node
	if (root == NULL)
		return 0;
	if (root->child.size() == 0)
		return 0;

	// If vertex cover for this node is already evaluated, then return it
	// to save recomputation of same subproblem again.
	if (root->vc != 0)
		return root->vc;

	int size_incl = 1;
	int size_excl = root->child.size();
	#pragma omp parallel
	{
		#pragma omp sections
		{
			// Calculate size of vertex cover when root is part of it
			// int size_incl = 1 + vCover(root->left) + vCover(root->right);
			#pragma omp section
			{
				for(auto i = root->child.size()-root->child.size(); i < root->child.size(); i++)
					size_incl += vCover(root->child[i]);
			}

			// Calculate size of vertex cover when root is not part of it
			#pragma omp section
			{
				for(auto i = root->child.size()-root->child.size(); i < root->child.size(); i++)
				{
					for (auto j = root->child[i]->child.begin(); j != root->child[i]->child.end(); ++j)
						size_excl += vCover(*j);
				}
			}
		}
	}
	// Minimum of two values is vertex cover, store it before returning
	root->vc = min(size_incl, size_excl);

	return root->vc;
}

// A utility function to create a node
struct node* newNode( int data )
{
	struct node* temp = (struct node *) malloc( sizeof(struct node) );
	temp->data = data;
	// temp->child.reserve(1000000);
	temp->vc = 0; // Set the vertex cover as 0
	return temp;
}

// Used to create I-ary tree
void makeTree(vector<struct node *> &leaf) {
  struct node *root;

  int i = 3;
  while(i--) {
		root = newNode(0);
		root->child.shrink_to_fit();
		root->child.reserve(i);
  	leaf.front()->child.push_back(root);
  	leaf.push_back(root);
  }

  leaf.erase(leaf.begin());
}

#include "tests/tests.h"

// Driver program to test above functions
int main(int argc, char* argv[])
{
	// Let us construct the tree given in the above diagram
	for (int i = 1; i < argc; i++)
	{
		printf("#%d\n", atoi(argv[i]));
		selectCase(atoi(argv[i]));
	}

	return 0;
}
