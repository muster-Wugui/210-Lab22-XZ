// COMSC-210 | Lab 22 | Xiao Zhang

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //inserts a value at the end of the list
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;  // Empty list case
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //inserts a value at the beginning of the list
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //removes the head node
    void pop_front() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    //removes the tail node
    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // removes the node containing the given value
    void delete_val(int value) {
        if (!head) return;

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;  // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;  // Deleting the tail
        }

        delete temp;
    }

    // deletes a node by position
    void delete_pos(int position) {
        if (position < 0 || !head) {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size." << endl;
            return;
        }

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;  // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;  // Deleting the tail
        }

        delete temp;
    }

    //prints the list from head to tail
    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // prints the list from tail to head
    void print_reverse() const {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR - MIN_NR + 1) + MIN_NR);

    cout << "Initial list (forward): ";
    list.print();

    cout << "Initial list (backward): ";
    list.print_reverse();

    // Test pop_front and pop_back
    list.pop_front();
    cout << "After pop_front (forward): ";
    list.print();

    list.pop_back();
    cout << "After pop_back (forward): ";
    list.print();

    // Test delete_pos
    list.delete_pos(2);  // Try deleting the node at index 2
    cout << "After delete_pos(2) (forward): ";
    list.print();

    // Test delete_val
    list.delete_val(list.tail->data);  // Deleting the tail value
    cout << "After delete_val() (forward): ";
    list.print();

    return 0;
}
