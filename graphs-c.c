// Adjacency list representation of a graph -- Chirag
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This can be changed
#define NUM_OF_NODES 20
#define MAX_SIZE_RECO 100
struct Element
{
	int id;
	int no_of_neighbours;
	struct Element *next[NUM_OF_NODES];
};

 struct Element *nodes[NUM_OF_NODES];

 int database[NUM_OF_NODES][NUM_OF_NODES];

 // Adds a new node
void addElement(int id)
{
	struct Element *temp = (struct Element*)malloc(sizeof(Element));
	temp->id = id;
	temp->no_of_neighbours =0;
	for(int i=0;i<NUM_OF_NODES;i++)
	{
		temp->next[i]=NULL;
	}
	nodes[id] = temp;
}

bool isNeighbour(int source, int destination)
{
	int count = nodes[source]->no_of_neighbours;

	for(int i=0; i< count; i++)
	{
		// Implies that the link already exists
		if(nodes[source]->next[i] == nodes[destination])
		{
			return true;	
		}
	}
	return false;
}

void addLink(int source, int destination)
{

	if(isNeighbour(source,destination))
	{
		printf("Already a link. Can't add duplicates.\n");
		return;
	}

	nodes[source]->next[nodes[source]->no_of_neighbours] = nodes[destination];
	nodes[source]->no_of_neighbours++;
}

void removeLink(int source, int destination)
{
	int count = nodes[source]->no_of_neighbours;

	for(int i=0; i< count; i++)
	{
		// Implies that the correct neighbour is found
		if(nodes[source]->next[i] == nodes[destination])
		{
			nodes[source]->next[i] = NULL;
			return;	
		}
	}
	printf("Neighbour doesn't exist.\n");
}


void addToReco(int source,int val)
{
	
	database[source][val] = 1;
}

bool isAlreadyInReco(int source, int val)
{
	if(database[source][val]==1)
	{
		return true;
	}
	else
	{
		return false;
	}

}


char* recommendationsForDemo(int source, int destination)
{

	int count_source = nodes[source]->no_of_neighbours;
	int count_destination = nodes[destination]->no_of_neighbours;
	
	char *return_value = (char*)malloc(MAX_SIZE_RECO);

	strcpy(return_value,"\0");

	if(count_destination==0)
	{
		strcpy(return_value,"");
		return return_value;
	}

	int temp_neighbours_source[count_source];
	int temp_neighbours_destination[count_destination];


	for(int i=0; i< count_source; i++)
	{
		temp_neighbours_source[i] = nodes[source]->next[i]->id; 	
	}

	for(int i=0; i< count_destination; i++)
	{
		temp_neighbours_destination[i] = nodes[destination]->next[i]->id;
		
		if(isNeighbour(source, temp_neighbours_destination[i]) == false && source!= temp_neighbours_destination[i] && !isAlreadyInReco(source,temp_neighbours_destination[i]))
		{
			char temp_buffer[10];
			sprintf(temp_buffer,"%d ",temp_neighbours_destination[i]);
			strcat(return_value, temp_buffer);
			addToReco(source,temp_neighbours_destination[i]);
		} 	
	}

	return return_value;

}


void recommendationsFor(int source)
{

	int count_source = nodes[source]->no_of_neighbours;

	if(count_source == 0)
	{
		printf("No recommendations. Get a few friends for recommendations.\n");
	}

	char* result = (char*)malloc(MAX_SIZE_RECO*NUM_OF_NODES);

	strcpy(result,"\0");

	for(int i=0; i< count_source; i++)
	{
		strcat(result,recommendationsForDemo(source,nodes[source]->next[i]->id)); 	
	}

	printf("Recommendations for %d are %s.\n", source,result );
	free(result);

}

void printNeighbours(int id)
{

	int count = nodes[id]->no_of_neighbours;
	printf("Neighbours of %d are\n", id);
	
	if(count==0)
	{
		printf("NONE\n");
		return;
	}

	
	while(count!=0)
	{
		printf("%d\n", nodes[id]->next[count-1]->id);
		count--;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	addElement(1);
	addElement(2);
	addElement(3);
	addElement(4);
	addElement(5);
	addElement(6);
	addElement(7);
	addElement(8);
	addElement(9);
	addElement(10);
	addElement(11);
	addElement(12);
	addElement(13);
	
	addLink(1,4);
	addLink(1,2);
	addLink(2,1);
	addLink(2,2);
	addLink(2,3);
	addLink(2,4);
	addLink(2,5);
	addLink(2,6);
	addLink(3,5);
	addLink(3,6);
	addLink(3,11);
	addLink(3,12);

	printNeighbours(1);
	printNeighbours(2);
	printNeighbours(3);
	printNeighbours(4);
	
	recommendationsFor(1);

	return 0;
}
 