#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};

struct Edge {
	int src, dest;
};

class graph
{
	Node* getadjnodes(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;

		newNode->next = head;

		return newNode;
	}

	int N;  

public:

	Node **head;

	graph(Edge edges[], int n, int N)
	{
		head = new Node*[N]();
		this->N = N;

		for (int i = 0; i < N; i++)
			head[i] = nullptr;

		for (unsigned i = 0; i < n; i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			Node* newNode = getadjnodes(dest, head[src]);

			head[src] = newNode;

			// Uncomment below lines for undirected graph

			/*
			newNode = getadjnodes(src, head[dest]);

			// change head pointer to point to the new node
			head[dest] = newNode;
			*/
		}
	}

	~graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];

		delete[] head;
	}
};

void printList(Node* ptr)
{
	while (ptr != nullptr)
	{
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

int main()
{
	Edge edges[] =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int N = 6;

	int n = sizeof(edges)/sizeof(edges[0]);

	graph graph(edges, n, N);

	for (int i = 0; i < N; i++)
	{
		cout << i << " --";

		printList(graph.head[i]);
	}

	return 0;
}