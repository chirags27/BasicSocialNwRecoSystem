
// struct Element
// {
// 	int id;
// 	int no_of_neighbours;
// 	struct Element *next[NUM_OF_NODES];
// };



// //typedef struct Element Element;

 struct Element *nodes[NUM_OF_NODES];


void addElement(int);
int addLink(int,int);
void printNeighbours(int);