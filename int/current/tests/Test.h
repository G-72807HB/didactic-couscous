#ifndef Test_h
#define Test_h

void makeTree(vector<struct node *> &leaf) {
  struct node *root;

  int i = 3;
  while(i--) {
    root = newNode(0);
  	leaf.front()->child.push_back(root);
  	leaf.push_back(root);
  }

  leaf.erase(leaf.begin());
}

void selectCase(int testCase)
{

  if (testCase == 1)
  {
		// Create Tree
		struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 1;
    while(i--) root->child.push_back(newNode(0));

		// Check if the result is True
		assert(vCover(root) == 1);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 2)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 10;
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    assert(vCover(root) == 1);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 3)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 100;
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    assert(vCover(root) == 1);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 4)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 1000;
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    assert(vCover(root) == 1);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 5)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 10000;
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    assert(vCover(root) == 1);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 6)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = 100000;
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    assert(vCover(root) == 1);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 7)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 1;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

		// Check if the result is True
		assert(vCover(root) == 1);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 8)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 10;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

		// Check if the result is True
		assert(vCover(root) == 5);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 9)
  {
    // Create Tree
    struct node *root = newNode(0);

    int i = 100;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

    // Check if the result is True
    assert(vCover(root) == 50);

    // Output result
    // printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 10)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 1000;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

		// Check if the result is True
		assert(vCover(root) == 500);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 11)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 10000;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

		// Check if the result is True
		assert(vCover(root) == 5000);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 12)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 100000;
    auto leaf = root;
    while(i--) {
      leaf->child.push_back(newNode(i));
      leaf = leaf->child[0];
    }

		// Check if the result is True
		assert(vCover(root) == 50000);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 13)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 1;
    vector<struct node *> leaf;
    leaf.reserve(100000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 1);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 14)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 10;
    vector<struct node *> leaf;
    leaf.reserve(100000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 8);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 15)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 100;
    vector<struct node *> leaf;
    leaf.reserve(100000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 76);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 16)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 1000;
    vector<struct node *> leaf;
    leaf.reserve(100000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 752);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 17)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 10000;
    vector<struct node *> leaf;
    leaf.reserve(100000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 7501);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 18)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = 100000;
    vector<struct node *> leaf;
    leaf.reserve(500000);
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		assert(vCover(root) == 75002);

		// Output result
		// printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
}

#endif
