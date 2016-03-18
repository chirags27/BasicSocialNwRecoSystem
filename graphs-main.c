#include "graphs-c.h"

int main(int argc, char const *argv[])
{

	/* code */
	addElement(1);
	addElement(3);
	addElement(4);
	addElement(5);
	addElement(6);
	addElement(2);
	addLink(1,3);
	addLink(1,4);
	addLink(1,5);
	addLink(1,6);
	addLink(3,2);
	addLink(3,1);
	printNeighbours(1);
	printNeighbours(3);
	return 0;
}