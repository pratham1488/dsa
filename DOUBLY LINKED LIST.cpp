#include <iostream>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int val, ListNode* previous) {
        value = val;
        prev = previous;
        next = nullptr;
    }

    void printList() {
        cout << "List Elements: ";
        ListNode* currentNode = this;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    int getListSize() {
        ListNode* currentNode = this;
        int count = 0;
        while (currentNode != nullptr) {
            count++;
            currentNode = currentNode->next;
        }
        return count;
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
            currentNode = currentNode->next;
        }
        cout << "not found \n";
    }

    void deleteNode(int delVal) {
        ListNode* currentNode = this;
        if (this->value == delVal) {
            if (this->next) {
                ListNode* newHead = this->next;
                newHead->prev = nullptr;
                delete this;
                newHead->printList();
                return;
            } else {
                cout << "List is now empty after deletion.\n";
                delete this;
                return;
            }
        }

        while (currentNode->next) {
            if (currentNode->value == delVal) {
                if (currentNode->next) {
                    currentNode->prev->next = currentNode->next;
                    currentNode->next->prev = currentNode->prev;
                } else {
                    currentNode->prev->next = nullptr;
                }
                cout << "After deletion - \n";
                printList();
                delete currentNode;
                return;
            } else {
                currentNode = currentNode->next;
            }
        }
        cout << "not found\n";
    }

    void insertNode(int val, int pos) {
        ListNode* currentNode = this;
        ListNode* newNode = new ListNode(val, nullptr);

        if (pos == 1) {
            newNode->next = this;
            this->prev = newNode;
            cout << "After insertion - \n";
            newNode->printList();
            return;
        }

        for (int i = 1; i < pos && currentNode; i++) {
            currentNode = currentNode->next;
        }

        if (!currentNode) {
            cout << "not found" << endl;
            delete newNode;
            return;
        }

        newNode->next = currentNode;
        newNode->prev = currentNode->prev;
        if (currentNode->prev) {
            currentNode->prev->next = newNode;
        }
        currentNode->prev = newNode;
        cout << "After insertion - \n";
        printList();
    }

    void updateNode(int oldVal, int newVal) {
        ListNode* currentNode = this;
        while (currentNode) {
            if (currentNode->value == oldVal) {
                currentNode->value = newVal;
                cout << "After update - \n";
                printList();
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "not found\n";
    }
};

int main() {
    cout << "Linked List" << endl;
    int arr[] = {44,55,66,77};
    ListNode* head = new ListNode(arr[0], nullptr);
    ListNode* prev = head;

    for (int i = 1; i < 5; i++) {
        ListNode* temp = new ListNode(arr[i], prev);
        prev->next = temp;
        prev = temp;
    }
    head->printList();

    cout << "\nChoose an option:"
         << "\n1 - Insert an element"
         << "\n2 - Find an element"
         << "\n3 - Delete an element"
         << "\n4 - Display list size"
         << "\n5 - Update an element\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the element to insert: ";
        int value;
        cin >> value;
        cout << "\nEnter the position: ";
        int pos;
        cin >> pos;
        head->insertNode(value, pos);
    } 
    else if (choice == 2) {
        cout << "Enter the element to search: ";
        int searchVal;
        cin >> searchVal;
        head->findValue(searchVal);
    } 
    else if (choice == 3) {
        cout << "Enter the element to delete: ";
        int deleteVal;
        cin >> deleteVal;
        head->deleteNode(deleteVal);
    } 
    else if (choice == 4) {
        cout << "List size: " << head->getListSize() << "\tTime Complexity: O(n)\n";
    } 
    else if (choice == 5) {
        cout << "Enter the element to update: ";
        int oldVal;
        cin >> oldVal;
        cout << "\nEnter the new value: ";
        int newVal;
        cin >> newVal;
        head->updateNode(oldVal, newVal);
    } 
    else {
        cout << "Invalid option\n";
    }

    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
