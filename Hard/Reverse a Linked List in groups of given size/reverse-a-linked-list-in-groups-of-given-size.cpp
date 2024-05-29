//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
          node *first = new node(0);    //creating a dummy node
        first->next = head;
        head = first;
        int x;
        node *second, *prev, *curr, *front;
        
        while(first->next)           //until last node is reversed
        {
            x = k;                   //length of block
            second = first->next;    //points to 1st node of block
            prev = first;            //points 1 node behind the block to be reversed
            curr = first->next;      //points to 1st node 1st node of block it will traverse the bloc
            
            while(x && curr)         //till block exists or the list exists
            {
                front = curr->next;     //stores next element
                curr->next = prev;      //links current node to previous node i.e. reverses link
                prev = curr;            //moves prev to next node
                curr = front;           //moves curr to next node
                x--;                    //reduces no. of nodes to reverse in that block
            }  
            
            first->next = prev;       //links last node of reveresed block to 1st node of next block
            second->next = curr;      //links 1st node of reversed block to last node of next block
            first = second;           //moves first to last node of reversed block to reverse next block
        }
        
        first = head;
        head = head->next;            //shift the head to next node
        delete first;                 //delete the dummy node
        
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends