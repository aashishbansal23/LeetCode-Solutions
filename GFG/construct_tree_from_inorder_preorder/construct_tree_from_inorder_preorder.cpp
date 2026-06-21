// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node* buildTree_help(int in[], int pre[], int& preStart, int inStart, int inEnd, int n){
        if(preStart>=n || inStart>inEnd){
            return NULL;
        }
        int val = pre[preStart++];
        Node* newNode = new Node(val);
        int index = -1;
        for(int i=inStart; i<=inEnd; i++){
            if(in[i] == val){
                index = i;
                break;
            }
        }
        newNode->left = buildTree_help(in, pre, preStart, inStart, index-1, n);
        newNode->right = buildTree_help(in, pre, preStart, index+1, inEnd, n);
        return newNode;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int s = 0;
        return buildTree_help(in, pre, s, 0, n-1, n);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends