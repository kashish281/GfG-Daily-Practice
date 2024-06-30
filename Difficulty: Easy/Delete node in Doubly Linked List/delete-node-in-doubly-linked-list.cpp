//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/
class Solution {
  public:
  
  // delete Head Node
  Node *deleteHead(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        Node *prev = head;
        head = head->next;
        head->prev = nullptr;
        prev->next = nullptr;
    
        delete prev;
        return head;
    }
    
    // delete Tail Node
    Node *deleteTail(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        Node *newtail = tail->prev;
        tail->prev = nullptr;
        newtail->next = nullptr;
        delete tail;
    
        return head;
    }
    Node* deleteNode(Node* head, int x) {
        // Your code here
        
        if(head == NULL) {
            return head;
        }
        
        
        int count = 0;
        Node* temp = head;
        
        while(temp) {
            
            count++;
            
            if(count == x) {
                break;
            }
            temp = temp->next;
        }
        
        Node* prev = temp->prev;
        Node* front = temp->next;
        
        if (prev == NULL && front == NULL)
        {
            return NULL;
        }
        else if (prev == NULL)
        {
            return deleteHead(head);
        }
        else if (front == NULL)
        {
            return deleteTail(head);
        }
        prev->next = front;
        front->prev = prev;
        temp->next = nullptr;
        temp->prev = nullptr;
    
        delete temp;
        return head;
        
    }
};


//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends