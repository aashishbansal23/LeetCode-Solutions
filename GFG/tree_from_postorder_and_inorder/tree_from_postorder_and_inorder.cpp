// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* buildTree_help(int in[], int post[], int& index, int inStart, int inEnd){
    if(index<0 || inStart>inEnd){
        return NULL;
    }
    int val = post[index--];
    Node* newNode = new Node(val);
    int pos = -1;
    for(int i=inStart; i<=inEnd; i++){
        if(in[i] == val){
            pos = i;
            break;
        }
    }
    newNode->right = buildTree_help(in, post, index, pos+1, inEnd);
    newNode->left = buildTree_help(in, post, index, inStart, pos-1);
    return newNode;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int inStart = 0;
    int index = n-1;
    return buildTree_help(in, post, index, inStart, n-1);
}
