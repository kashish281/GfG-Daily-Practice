/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int>res;
        for(int i =0; i<arr.size(); i++){
            Node *temp = arr[i];
            while(temp!=NULL){
                res.push_back(temp->data);
                temp = temp->next;
            }
            
        }
        sort(begin(res),end(res));
         
        Node *  head = new Node(res[0]);
        Node *curr = head;
            
        for(int i =1; i<res.size(); i++){
            curr->next = new Node(res[i]);
            curr = curr-> next;
        }
        return head;
    }
};