//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
/*
class Solution
{
    public:
    void sort(Node **head)
    {
         if((*head)->next == NULL) return;
         Node *header = (*head);
         Node *piche = NULL;
         Node *age = NULL;
         while(true){
            age = header->next->next;
            header->next->next = piche;
            if(age == NULL) return;
            piche = header->next;
            header->next = age;
            header = age;
            header.sort();
            if(header->next == NULL){
                header->next = piche;
                return;
            }
        }
    }
};*/


class Solution {
public:
    void sort(Node **head) {
        if ((*head) == NULL || (*head)->next == NULL)
            return;
        
        Node *current = (*head)->next;
        (*head)->next = NULL;  // Split the list into two parts: sorted and unsorted
        
        while (current != NULL) {
            Node *nextNode = current->next;
            insertNode(head, current);  // Insert current node into the sorted list
            current = nextNode;
        }
    }
    
private:
    void insertNode(Node **head, Node *newNode) {
        if (*head == NULL || newNode->data < (*head)->data) {
            newNode->next = *head;
            *head = newNode;
        } else {
            Node *current = *head;
            while (current->next != NULL && current->next->data < newNode->data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
};


//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends