//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) 
{
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) 
    {
        tree->left = insert(tree->left, val);
    } 
    else if (val > tree->data) 
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void help(Node* root,int target,int a,int b,int &ans,bool found)
    {
        if(!root)return;
        if(root->data==target)found=true;
        if(found)
        {
            b+=root->data;
            help(root->left,target,a,b,ans,found);
            help(root->right,target,a,b,ans,found);
            if(!root->left and !root->right)
            {
                b-=target;
                ans=max(ans,a-b);
            }
        }
        else
        {
            a+=root->data;
            if(target<root->data)help(root->left,target,a,b,ans,found);
            else help(root->right,target,a,b,ans,found);
        }
    }
    
    int maxDifferenceBST(Node *root,int target)
    {
        // Code here
        int a=0,b=0,ans=INT_MIN;
        bool found=false;
        help(root,target,a,b,ans,found);
        if(ans==INT_MIN)return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends