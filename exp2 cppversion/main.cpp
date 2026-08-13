#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node *next;
};

Node *head = NULL;


void insertEnd(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertBeginning(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteByValue(int value) {
    Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        cout << value << " deleted" << endl;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << value << " not found in list" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << value << " deleted" << endl;
}


void traverse() {
    Node *temp = head;
    if (temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void search(int value) {
    Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << value << " not found in list" << endl;
}


int main() {
    int choice, value, pos;

    while (1) {
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Beginning" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete by Value" << endl;
        cout << "5. Traverse" << endl;
        cout << "6. Search" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(value, pos);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(value);
                break;
            case 5:
                traverse();
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
