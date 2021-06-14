#include <stdio.h>
#include <assert.h>
#define NDEBUG
#include <stdbool.h>


int main(int argc, char const *argv[])
{
	int x = 10;
	float y = 12.01;
	bool z = true;
	assert(x < y);
	assert(z == false);
	return 0;
}