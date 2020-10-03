#include <iostream>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
	int val;
	Node* next;
};

// Data structure to store graph edges
struct Edge {
	int src, dest;
};





class Graph
{
	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;

		// point new node to current head
		newNode->next = head;

		return newNode;
	}

	int N;  // number of nodes in the graph

public:

	// An array of pointers to Node to represent
	// adjacency list
	Node **head;

	// Constructor
	Graph(Edge edges[], int n, int N)
	{
		// allocate memory
		head = new Node*[N]();
		this->N = N;

		// initialize head pointer for all vertices
		for (int i = 0; i < N; i++)
			head[i] = nullptr;

		// add edges to the directed graph
		for (unsigned i = 0; i < n; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			// insert in the beginning
			Node* newNode = getAdjListNode(dest, head[src]);

			// point head pointer to new node
			head[src] = newNode;

			// Uncomment below lines for undirected graph

			/*
			newNode = getAdjListNode(src, head[dest]);

			// change head pointer to point to the new node
			head[dest] = newNode;
			*/
		}
	}

	// Destructor
	~Graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];

		delete[] head;
	}
};

// print all neighboring vertices of given vertex
void printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// Graph Implementation in C++ without using STL
int main()
{
	// array of graph edges as per above diagram.
	int N;
	cin>>N;
	printf("No of Nodes/vertexes in  your graph:");


	Edge edges[10000] ;
	int e=0;
	printf("No of Edges in your graph :");
	cin>>e;
	printf("\t\t\t\tNow enter source and destination for each edges.\n\n");
	int ir=0;
	while(ir<e)
	{int s,d;
			printf("Please Enter Src and Dst index:");
			cin>>s>>d;
			edges[ir].src=s;
			edges[ir].dest=d;
		ir++;
	}

	// Number of vertices in the graph
	






	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph
	Graph graph(edges, n, N);

	// print adjacency list representation of graph
	for (int i = 0; i < N; i++)
	{
		// print given vertex
		cout << i << " --";

		// print all its neighboring vertices
		printList(graph.head[i]);
	}

	return 0;
}