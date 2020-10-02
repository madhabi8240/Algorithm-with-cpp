#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		
		int data;
		Node* lchild;
		Node* rchild;
		Node(int d){
			data=d;
			lchild=NULL;
			rchild=NULL;
		}
};
void bfsTraversalMethod2(Node* root){
	queue<pair<Node*,int> > q;
	q.push(make_pair(root,1));
	int level=1;
	
	while(!q.empty()){
		pair<Node*, int> p=q.front();
		q.pop();
		Node* n=p.first;
		int l=p.second;
		
		if(l!=level){
			cout<<endl;
			level=l;
		}
		cout<<n->data<<" ";
		
		if(n->lchild)
			q.push(make_pair(n->lchild,l+1));
		if(n->rchild)
			q.push(make_pair(n->rchild,l+1));
		
		
	}
}

Node* InputTree(){
	int d;
	cin>>d;
	
	if(d==-1)
		return NULL;
		
	Node* newNode= new Node(d);
	newNode->lchild=InputTree();
	newNode->rchild=InputTree();
		
	
	return newNode;
}


void rightView(Node* root,int level){
	static int maxlevel=-1 ;//will act as global variable and will not make a for every fn call
	if(root==NULL)
		return;
	if(level>maxlevel){
		cout<<root->data<<"\n";
		maxlevel=level;
	}
	
	//calling rchild first to print only rightmost node of every level
	rightView(root->rchild,level+1);
	rightView(root->lchild,level+1);
	
	
}

int main(){
	
	Node* root=InputTree(); //Sample Input of Tree: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	cout<<"\nTree: \n";
	bfsTraversalMethod2(root);
	cout<<endl<<endl<<"  Right View: \n";
	rightView(root,0);
	
	return 0;
}
