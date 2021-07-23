#ifndef Test_h
#define Test_h

void selectCase(int testCase)
{

  // Max = base * 100000;
  int base = 100;

  // For Case 13-18
  int ary = 3;

  if (testCase == 1)
  {
		// Create Tree
		struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 1;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

		// Check if the result is True
		// assert(vCover(root) == 1);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 2)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 10;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    // assert(vCover(root) == 1);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 3)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 100;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    // assert(vCover(root) == 1);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
	else if (testCase == 4)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 1000;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    // assert(vCover(root) == 1);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 5)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 10000;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    // assert(vCover(root) == 1);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 6)
  {
    // Create Tree
    struct node *root = newNode(0);
    // root->child.push_back(newNode(1));
    // root->child.push_back(newNode(2));

    int i = base * 100000;
    root->child.reserve(i+1);
    while(i--) root->child.push_back(newNode(0));

    // Check if the result is True
    // assert(vCover(root) == 1);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 7)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = base * 1;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

		// Check if the result is True
		// assert(vCover(root) == (base/10) * 5);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 8)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = base * 10;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

		// Check if the result is True
		// assert(vCover(root) == base * 5);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 9)
  {
    // Create Tree
    struct node *root = newNode(0);

    int i = base * 100;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

    // Check if the result is True
    // assert(vCover(root) == base * 50);

    // Output result
    printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 10)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = base * 1000;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

		// Check if the result is True
		// assert(vCover(root) == base * 500);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 11)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = base * 10000;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

		// Check if the result is True
		// assert(vCover(root) == base * 5000);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 12)
  {
    // Create Tree
		struct node *root = newNode(0);

    int i = base * 100000;
    auto leaf = root;
    while(i--) {
      leaf->child.resize(1);
      leaf->child.shrink_to_fit();
      leaf = leaf->child[0] = newNode(0);
    }

		// Check if the result is True
		// assert(vCover(root) == base * 50000);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 13)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 1;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 1);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 14)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 10;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 8);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 15)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 100;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 76);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 16)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 1000;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 752);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 17)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 10000;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 7501);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
  else if (testCase == 18)
  {
    // Create Tree
		struct node *root = newNode(0);
    root->child.shrink_to_fit();
		root->child.reserve(ary);

    int i = base * 100000;
    vector<struct node *> leaf;
    leaf.reserve(i*(ary));
    leaf.push_back(root);

    while(i--) makeTree(leaf);

		// Check if the result is True
		// assert(vCover(root) == 75002);

		// Output result
		printf ("Size of the smallest vertex cover is %d \n", vCover(root));
  }
}

#endif
