#include <iostream>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* nextNode;

    ListNode(int val) {
        value = val;
        nextNode = nullptr;
    }

    void printList() {
        cout << "List Elements: ";
        ListNode* currentNode = this;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }

    int getSize() {
        ListNode* currentNode = this;
        int nodeCount = 0;
        while (currentNode != nullptr) {
            nodeCount++;
            currentNode = currentNode->nextNode;
        }
        return nodeCount;
    }

    void findValue(int val) {
        ListNode* currentNode = this;
        int position = 1;
        while (currentNode != nullptr) {
            if (currentNode->value == val) {
                cout << "Element found at position: " << position << "\n";
                return;
            }
            position++;
            currentNode = currentNode->nextNode;
        }
        cout << "not found\n";
    }

    void updateValue(int oldVal, int newVal) {
        ListNode* currentNode = this;
        while (currentNode != nullptr) {
            if (currentNode->value == oldVal) {
                currentNode->value = newVal;
                cout << "After update - \n";
                printList();
                return;
            }
            currentNode = currentNode->nextNode;
        }
        cout << " not found\n";
    }

    void insertNode(int val, int pos, ListNode*& head) {
        ListNode* newNode = new ListNode(val);

        if (pos == 1) {
            newNode->nextNode = head;
            head = newNode;
            cout << "After insertion - \n";
            head->printList();
            return;
        }

        ListNode* currentNode = head;
        int index = 1;
        while (index < pos - 1 && currentNode != nullptr) {
            currentNode = currentNode->nextNode;
            index++;
        }

        if (currentNode == nullptr) {
            cout << "not found\n";
            delete newNode;
            return;
        }

        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
        cout << "After insertion - \n";
        head->printList();
    }

    void deleteNode(int pos, ListNode*& head) {
        ListNode* currentNode = head;

        if (head->value == pos) {
            ListNode* newHead = head->nextNode;
            delete head;
            head = newHead;
            cout << "After deletion - \n";
            if (head != nullptr) {
                head->printList();
            } else {
                cout << "The list is now empty.\n";
            }
            return;
        }

        int index = 1;
        while (currentNode->nextNode != nullptr && index < pos - 1) {
            currentNode = currentNode->nextNode;
            index++;
        }

        if (currentNode->nextNode == nullptr) {
            cout << "not found\n";
            return;
        }

        ListNode* nodeToDelete = currentNode->nextNode;
        currentNode->nextNode = currentNode->nextNode->nextNode;
        delete nodeToDelete;
        cout << "After deletion - \n";
        head->printList();
    }
};

int main() {
    cout << "List created." << endl;
    int arr[] = {11,22,33,44};

    ListNode* head = new ListNode(arr[0]);
    ListNode* previousNode = head;

    for (int i = 1; i < 5; i++) {
        ListNode* tempNode = new ListNode(arr[i]);
        previousNode->nextNode = tempNode;
        previousNode = tempNode;
    }

    head->printList();

    cout << "\nSelect an option:"
         << "\n1 - Delete an element"
         << "\n2 - Search for an element"
         << "\n3 - Insert an element"
         << "\n4 - Display the list size"
         << "\n5 - Update an element\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "\nEnter the position of the element to be deleted: ";
        int pos;
        cin >> pos;
        head->deleteNode(pos, head);
    } 
    else if (choice == 2) {
        cout << "Enter the element to search: ";
        int value;
        cin >> value;
        head->findValue(value);
    } 
    else if (choice == 3) {
        cout << "Enter the element to insert: ";
        int insertValue;
        cin >> insertValue;
        cout << "\nEnter the position: ";
        int pos;
        cin >> pos;
        head->insertNode(insertValue, pos, head);
    } 
    else if (choice == 4) {
        cout << "Length of the list: " << head->getSize() << "\n";
    } 
    else if (choice == 5) {
        cout << "Enter the element to update: ";
        int oldValue;
        cin >> oldValue;
        cout << "\nEnter the new value: ";
        int newValue;
        cin >> newValue;
        head->updateValue(oldValue, newValue);
    } 
    else {
        cout << "\nInvalid option selected.\n";
    }

    while (head) {
        ListNode* temp = head;
        head = head->nextNode;
        delete temp;
    }

    return 0;
}
