// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    pair<Node*, Node*> getFlattenTree(Node* root){
        if(root == NULL){
            pair<Node*, Node*> ans;
            ans.first = NULL;
            ans.second = NULL;
            return ans;
        }
        pair<Node*, Node*> rightAns = getFlattenTree(root->right);
        pair<Node*, Node*> leftAns = getFlattenTree(root->left);
        pair<Node*, Node*> ans;
        ans.first = root;
        root->left = NULL;
        if(leftAns.first == NULL){
            root->right = rightAns.first;
            if(rightAns.second == NULL){
                ans.second = rightAns.first;
            }else{
                ans.second = rightAns.second;
            }
        }else if(leftAns.second == NULL){
            root->right = leftAns.first;
            leftAns.first->right = rightAns.first;
            if(rightAns.second == NULL){
                if(rightAns.first == NULL){
                    ans.second = leftAns.first;
                }else{
                    ans.second = rightAns.first;
                }
            }else{
                ans.second = rightAns.second;
            }
        }else{
            root->right = leftAns.first;
            leftAns.second->right = rightAns.first;
            if(rightAns.second == NULL){
                if(rightAns.first == NULL){
                    ans.second = leftAns.second;
                }else{
                    ans.second = rightAns.first;
                }
            }else{
                ans.second = rightAns.second;
            }
        }
        return ans;
    }
    
    public:
    void flatten(Node *root)
    {
        //code here
        
        // Using Morris Transversal TC=O(n) and SC=O(1)
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* pre = curr->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
        
        
        
        
        // First Try Using Recusion TC=O(n) and SC=O(n)
        // pair<Node*, Node*> temp = getFlattenTree(root);
    }
};

// { Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}
  // } Driver Code Ends