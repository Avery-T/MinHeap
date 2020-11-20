#include <iostream>
#include <fstream>
#define SIZE 10;

using namespace std;

void printLevel(int []);
void insert(int [],int,int);
void minCheckAndSwap(int [], int);

int main()
{
	ifstream in;
	int txtFileInput;
	int index=0;
	int minHeap[4];
	in.open
	("//Users//averytaylor//Desktop//School//cisp430//heap-min//input.txt");
	
	while (in >> txtFileInput)
	{
		insert(minHeap,txtFileInput,index);
		index++;
		cout << txtFileInput << endl;
	}
	cout << "helloworld" << endl;
	return 1;
}

void insert(int minHeap[], int data, int index)
{
	minHeap[index] = data;
	minCheckAndSwap(minHeap, index);
}

//this does not work
void minCheckAndSwap(int minHeap[], int i)
{
	while(i>0 &&
				minHeap[i] > minHeap[(i)/2])
	{
		int temp = minHeap[(i)/2];
		minHeap[(i)/2] = minHeap[i];
		minHeap[i] = temp;
		i--;
	}
}

