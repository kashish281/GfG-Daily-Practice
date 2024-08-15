//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
      Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move pointers one position ahead
            curr = next;
        }
        return prev;
    }
   Node* addOne(Node* head) {
        // Step 1: Reverse the linked list.
        head = reverseList(head);
        
        // Step 2: Add one to the reversed list.
        Node* curr = head;
        int carry = 1;
        Node* prev = NULL;
        
        while (curr != NULL) {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
        }
        
        // If carry is still left, add a new node.
        if (carry > 0) {
            prev->next = new Node(carry);
        }
        
        // Step 3: Reverse the list back to its original order.
        head = reverseList(head);
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends