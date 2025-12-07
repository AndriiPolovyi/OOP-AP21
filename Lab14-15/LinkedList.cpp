#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::pushFront(const CoaxialCable& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    std::cout << ">>> Element dodano na pochatok.\n";
}

void LinkedList::pushBack(const CoaxialCable& data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    std::cout << ">>> Element dodano v kinetsj.\n";
}

void LinkedList::popFront() {
    if (isEmpty()) {
        std::cout << "[POMYLKA] Spysok porozhniy!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    std::cout << ">>> Pershyy element vydaleno.\n";
}

void LinkedList::popBack() {
    if (isEmpty()) {
        std::cout << "[POMYLKA] Spysok porozhniy!\n";
        return;
    }
    if (head->next == nullptr) { 
        delete head;
        head = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next->next != nullptr) { 
            temp = temp->next;
        }
        delete temp->next; 
        temp->next = nullptr;
    }
    std::cout << ">>> Ostanniy element vydaleno.\n";
}

void LinkedList::removeByValue(const CoaxialCable& val) {
    if (isEmpty()) return;

    if (head->data == val) {
        popFront();
        return;
    }

    Node* current = head;
    while (current->next != nullptr && !(current->next->data == val)) {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cout << "[INFO] Tyy element ne znaydeno.\n";
    }
    else {
        Node* toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
        std::cout << ">>> Element uspishno vydaleno.\n";
    }
}

void LinkedList::printList() const {
    if (isEmpty()) {
        std::cout << "(Spysok porozhniy)\n";
        return;
    }
    Node* temp = head;
    int i = 1;
    std::cout << "--- Vmist Spysku ---\n";
    while (temp != nullptr) {
        std::cout << i << ". " << temp->data << "\n";
        temp = temp->next;
        i++;
    }
    std::cout << "--------------------\n";
}

void LinkedList::clear() {
    while (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::sortByLength() {
    if (isEmpty() || head->next == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data.length > ptr1->next->data.length) {
                CoaxialCable temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    std::cout << ">>> Spysok vid-sortovano za dovzhynoyu.\n";
}