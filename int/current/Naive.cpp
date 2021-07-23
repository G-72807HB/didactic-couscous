#include "tests/TestNV.h"
#include "tests/Test.h"

// Driver program to test above functions
int main(int argc, char* argv[])
{
	// Let us construct the tree given in the above diagram
	for (int i = 1; i < argc; i++)
	{
		printf("NV #%d\n", atoi(argv[i]));
		selectCase(atoi(argv[i]));
	}

	return 0;
}
