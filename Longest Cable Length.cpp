#include <bits/stdc++.h> 
using namespace std; 
  

class node { 
public: 
    node* left; 
    node* right; // C++ program to find the longest cable length 
// between any two cities. 
#include<bits/stdc++.h> 
using namespace std; 

// visited[] array to make nodes visited 
// src is starting node for DFS traversal 
// prev_len is sum of cable length till current node 
// max_len is pointer which stores the maximum length 
// of cable value after DFS traversal 
void DFS(vector< pair<int,int> > graph[], int src, 
		int prev_len, int *max_len, 
		vector <bool> &visited) 
{ 
	// Mark the src node visited 
	visited[src] = 1; 

	// curr_len is for length of cable from src 
	// city to its adjacent city 
	int curr_len = 0; 

	// Adjacent is pair type which stores 
	// destination city and cable length 
	pair < int, int > adjacent; 

	// Traverse all adjacent 
	for (int i=0; i<graph[src].size(); i++) 
	{ 
		// Adjacent element 
		adjacent = graph[src][i]; 

		// If node or city is not visited 
		if (!visited[adjacent.first]) 
		{ 
			// Total length of cable from src city 
			// to its adjacent 
			curr_len = prev_len + adjacent.second; 

			// Call DFS for adjacent city 
			DFS(graph, adjacent.first, curr_len, 
				max_len, visited); 
		} 

		// If total cable length till now greater than 
		// previous length then update it 
		if ((*max_len) < curr_len) 
			*max_len = curr_len; 

		// make curr_len = 0 for next adjacent 
		curr_len = 0; 
	} 
} 

// n is number of cities or nodes in graph 
// cable_lines is total cable_lines among the cities 
// or edges in graph 
int longestCable(vector<pair<int,int> > graph[], 
										int n) 
{ 
	// maximum length of cable among the connected 
	// cities 
	int max_len = INT_MIN; 

	// call DFS for each city to find maximum 
	// length of cable 
	for (int i=1; i<=n; i++) 
	{ 
		// initialize visited array with 0 
		vector< bool > visited(n+1, false); 

		// Call DFS for src vertex i 
		DFS(graph, i, 0, &max_len, visited); 
	} 

	return max_len; 
} 

// driver program to test the input 
int main() 
{ 
	// n is number of cities 
	int n = 6; 

	vector< pair<int,int> > graph[n+1]; 

	// create undirected graph 
	// first edge 
	graph[1].push_back(make_pair(2, 3)); 
	graph[2].push_back(make_pair(1, 3)); 

	// second edge 
	graph[2].push_back(make_pair(3, 4)); 
	graph[3].push_back(make_pair(2, 4)); 

	// third edge 
	graph[2].push_back(make_pair(6, 2)); 
	graph[6].push_back(make_pair(2, 2)); 

	// fourth edge 
	graph[4].push_back(make_pair(6, 6)); 
	graph[6].push_back(make_pair(4, 6)); 

	// fifth edge 
	graph[5].push_back(make_pair(6, 5)); 
	graph[6].push_back(make_pair(5, 5)); 

	cout << "Maximum length of cable = "
		<< longestCable(graph, n); 

	return 0; 
} 

}; 
  

void insert(int x, node* head) 
{ 
    
    node* curr = head; 
  
    for (int i = 30; i >= 0; i--) { 
  
        // Find the i-th bit 
        int val = (x >> i) & 1; 
  
        if (val == 0) { 
  
            // If curr->left is NULL 
            if (!curr->left) 
                curr->left = new node(); 
  
            // Update curr to curr->left 
            curr = curr->left; 
        } 
        else { 
  
            // If curr->right is NULL 
            if (!curr->right) 
                curr->right = new node(); 
  
            // Update curr to curr->right 
            curr = curr->right; 
        } 
    } 
} 
  
 
int findMaximumXOR(int arr[], int n) 
{ 
    // head Node of Trie 
    node* head = new node(); 
  
    // Insert each element in trie 
    for (int i = 0; i < n; i++) { 
        insert(arr[i], head); 
    } 
  
    // Stores the maximum XOR value 
    int ans = 0; 
  
    // Traverse the given array 
    for (int i = 0; i < n; i++) { 
  
        // Stores the XOR with current 
        // value arr[i] 
        int curr_xor = 0; 
  
        int M = pow(2, 30); 
  
        node* curr = head; 
  
        for (int j = 30; j >= 0; j--) { 
  
            
            int val = (arr[i] >> j) & 1; 
  
            // Check if the bit is 0 
            if (val == 0) { 
  
                // If right node exists 
                if (curr->right) { 
  
                    // Update the currentXOR 
                    curr_xor += M; 
                    curr = curr->right; 
                } 
  
                else { 
                    curr = curr->left; 
                } 
            } 
  
            else { 
  
                if (curr->left) { 
  
                    
                    curr_xor += M; 
                    curr = curr->left; 
                } 
                else { 
                    curr = curr->right; 
                } 
            } 
  
            
            M /= 2; 
        } 
  
       
        ans = max(ans, curr_xor); 
    } 
  
   
    return ans; 
} 
  
// Driver Code 
int main() 
{ 
    // Given array arr[] 
    int arr[] = { 1, 2, 3, 4 }; 
  
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    // Function Call 
    cout << findMaximumXOR(arr, N); 
  
    return 0; 
} 
