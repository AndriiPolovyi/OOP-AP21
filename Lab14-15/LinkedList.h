#pragma once
#include "CoaxialCable.h"

struct Node {
    CoaxialCable data;
    Node* next;

    Node(CoaxialCable d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; 

public:
    LinkedList();
    ~LinkedList();

    void pushFront(const CoaxialCable& data);       
    void pushBack(const CoaxialCable& data);        
    void popFront();                                
    void popBack();                                 
    void removeByValue(const CoaxialCable& data);   

    void printList() const;                         
    void clear();                                   
    bool isEmpty() const;                           

    void sortByLength();
};