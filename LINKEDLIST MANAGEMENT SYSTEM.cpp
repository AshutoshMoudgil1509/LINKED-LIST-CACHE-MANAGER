#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node *prev;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the linked list
    void insertNode(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully.\n";
    }

    // Function to display the linked list
    void displayList() {
        if(detectCycle()){
            cout<< "List contains an cycle.";
            return;
        }
        if (head == nullptr) {
            cout << "List is empty.\n";
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }

    void reverseTheList(){
        Node *prev = NULL;
        Node *next = NULL;
        Node *current = head;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to make the linked list cyclic by connecting the last node to the specified node
    void makeCyclic(int position) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* cyclicNode = nullptr;
        int count = 1;
        while (temp->next != nullptr) {
            if (count == position) {
                cyclicNode = temp;
            }
            temp = temp->next;
            count++;
        }

        if (cyclicNode != nullptr) {
            temp->next = cyclicNode;
            cout << "List has been made cyclic.\n";
        } else {
            cout << "Invalid position. Unable to make the list cyclic.\n";
        }
    }

    // Function to detect and check if the linked list contains a cycle
    bool detectCycle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    }

    void removeCycle() {   // remove cycle
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, remove the cycle
                slow = head;
                Node* prev = nullptr;
                while (slow != fast) {
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
                prev->next = nullptr;
                cout << "Cycle removed successfully.\n";
                return;
            }
        }

        cout << "No cycle found in the list.\n";
    }

    void findSum() {
        int sum = 0;
        Node* current = head;
        if (head == nullptr) {
            cout << "List is empty...\n";
        } else {
            while (current != nullptr) {
                sum += current->data;
                current = current->next;
            }
            cout << "Sum is: " << sum << "\n";
        }
    }

    void updateNode(int oldData, int newData) {
        if (head == nullptr) {
            cout << "List is empty.\n";
        } else {
            Node* current = head;
            while (current != nullptr) {
                if (current->data == oldData) {
                    current->data = newData;
                    cout << "\nNode updated successfully.\n";
                    return;
                }
                current = current->next;
            }
            cout << "Node not found.\n";
        }
    }

    void deleteMidNode() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // If there's only one node
        if (prev == nullptr) {
            head = head->next;
            delete slow;
            cout << "Deleted mid node successfully.\n";
            return;
        }

        prev->next = slow->next;
        delete slow;
        cout << "Deleted mid node successfully.\n";
    }
    
    void deleteKthNode(int k){
        Node *temp = head;
        Node *current = NULL;
        
        for(int i = 1 ;i < k-1;i++){
            temp = temp->next;
        }
        current = temp->next;
        temp->next = current->next;
        delete current;
        
        temp = NULL;
        delete temp;
        cout<<"Kth Node Deleted Successfully.\n";
    }
    
    void appendKthNode(int k,int data){
            Node *current = head;
            Node *temp = NULL;
            Node *newNode = new Node(data);
            // if Kth node is less than 1 
            if(k <= 1){
                cout<<"Invalid Node Input."<<endl;
                return ;
            }
            // Append Kth Node at Head
            if(k==1){
                newNode->next = head;
                head = newNode;
                cout<<"Node Append at Head."<<endl;
                return ;
            }
            else{
            for(int i = 1; i <k-1; i++){
                current = current->next;
            }
            temp = current->next;
           
            current->next = newNode;
            newNode->next = temp;
        }
        if(temp == NULL){
            cout<<"Node  entered length is greater than original length."<<endl;
            return ;
        }
    }
    int lengthOfTheNode(){
        Node *current = head;
        int length = 0;
            while(current != NULL){
                length++;
                current = current->next;
            }

        if(length==0){
            cout<<"List is empty";
        }
        return length;  
    }
    bool searchNode(int key){
        Node *current = head;
        if(head == NULL){
            cout<<"List is empty2.\n";
        }
        else{
            while(current != NULL){
                if(current->data == key){
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    }
    void insertAtTail(int val){
        if(head==NULL){
            insertNode(val);
            return ;
        }
        Node *n = new Node(val);
        Node *current = head;
        Node *prev = NULL;
        if(head == NULL){
            cout<<"List is empty.\n ";
        }
        else{
            while(current->next != NULL){
                current = current->next; 
            }
            current->next = n;
            n->prev = current;
            cout<<"Node Inserted Successfully.\n";
            return ;
        }
    }
    
};

int main() 
{
    LinkedList list;
    int choice,newData,oldData,data,k,key,position,val;

    do{
        cout << "\n.... Linked List Management System....\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Make Cycle\n";
        cout << "4. Remove Cycle\n";
        cout << "5. Find Sum of Nodes\n";
        cout << "6. Delete Mid Node\n";
        cout << "7. Delete kth Node\n";
        cout << "8. Append kth Node\n";
        cout << "9. Reverse the List\n";
        cout << "10. Get Length of the List\n";
        cout << "11. Search Node\n";
        cout << "12. Insert Node at Tail\n";
        cout<<  "13.EXIT.\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Enter the value to be Inserted.\n";
                cin>>data;
                list.insertNode(data);
                break;
            case 2:
                list.displayList();
                break;
            case 3:
                cout<<"Enter the position from which cycle must be created.\n";
                cin>>position;
                list.makeCyclic(position);
                break;
            case 4:
                if (list.detectCycle()) {
                    list.removeCycle();
                    cout << "Loop detected and removed.\n";
                } else
                {
                    cout << "No loop detected.\n";
                }
                break;
            case 5:
                list.findSum();
                break;
            case 6:
                list.deleteMidNode();
                break;
            case 7:
                cout<<"Input kth Node You want To Delete.\n";
                cin>>k;
                list.deleteKthNode(k);
                break;
            case 8:
                cout<<"Enter the Position to append the Node:\n";
                cin>>k;
                cout<<"Enter the value to append:\n";
                cin>>data;
                list.appendKthNode(k,data);
                break;
            case 9:
                cout<<"Reversed list.\n";
                list.reverseTheList();
                list.displayList();
                break;
            case 10:
                cout<<"Length of the List.\n"<<list.lengthOfTheNode()<<"\n";
                break;
            case 11:
                cout<<"Enter the Node want to Searched.\n";
                cin>>key;
                if(list.searchNode(key)){
                cout<<"Node found\n";
                }
                else{
                cout<<"Node is not found.\n";
                }
                break;
            case 12:
                cout<<"Enter the Value.\n";
                cin>>val;
                list.insertAtTail(val);
                break;
            case 13:
                cout<<"Exiting Program.\n";
            default:
                cout<<"Invalid Choice.Please try Again\n";
        }
    } while(choice != 13);
    return 0;
}
