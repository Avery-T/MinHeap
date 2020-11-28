#include <iostream>
#include <fstream>

#define SIZE 10;

using namespace std;

void printByLevel(int[],int);
void insert(int[],int,int);
void percolateUp(int[],int);

void remove(int[],int);
void percolateDown(int[],int);

int main()
{
	ifstream in;
	int txtFileInput;
	int index=0;
	int minHeap[10];
	in.open
	("//Users//averytaylor//Desktop//School//cisp430//heap-min//input.txt");
	
	//inserting loop
	while (in >> txtFileInput)
	{
		insert(minHeap,txtFileInput,index);
		index++;
		cout << txtFileInput << endl;
	}
	printByLevel(minHeap,index);
	//delete and display loop
	for(int i =0; i<5; i++)
	{
		remove(minHeap, index);
		index--;
		cout << "---------New Array After Delete--------\n";
		printByLevel(minHeap,index);
	}
	return 1;
}

void insert(int minHeap[], int data, int index)
{
	minHeap[index] = data;
	percolateUp(minHeap, index);
}

void remove(int minHeap[], int nodes)
{
	nodes--;
	minHeap[0] = minHeap[nodes];
	percolateDown(minHeap, nodes);
}

void percolateDown(int minHeap[], int nodes)
{
	int childIndex = 1;
	int maxIndex, maxValue;
	int nodeIndex = 0;
	int value = minHeap[0];
	while(childIndex < nodes)
	{
		maxValue = value;
		for(int i= 0; i < 2 && i + childIndex < nodes;  i++)
		{
			if (minHeap[i + childIndex] > maxValue)
			{
				maxValue = minHeap[i + childIndex];
				maxIndex = i + childIndex;
			}
		}
	}
	if (maxValue == value)
		return;
	else
	{
		int temp = 	minHeap[maxIndex];
		minHeap[maxIndex] = minHeap[nodeIndex];
		minHeap[nodeIndex] = temp;
		nodeIndex = maxIndex;
		childIndex = 2 * nodeIndex + 1;
	}
}

void percolateUp(int minHeap[], int i)
{
	while(i>=0 && minHeap[i] > minHeap[(i-1)/2])
	{
		int temp = minHeap[(i-1)/2];
		minHeap[(i-1)/2] = minHeap[i];
		minHeap[i] = temp;
		i = (i-1)/2;
	}
}

void printByLevel(int minHeap[], int nodes)
{
	for(int i = nodes-1; i>=0; i--)
	{
		cout << minHeap[i] << ", ";
	}
	cout << "\n";
}

