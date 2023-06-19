//
// Created by Tyler Plauche on 10/4/21.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& d, Node* n) : data(d), next(n) {}
        ~Node() = default;
    };
    Node* head;
public:
    LinkedList() : head(NULL) {}
    ~LinkedList() { clear(); }

    LinkedList(const LinkedList<T>& copyList) : head(NULL)
    {
        // Copy (append) copyList to *this
        Node* cptr = copyList.head;
        Node** nptr = &head;			// point to head
        while (cptr != NULL)
        {
            // append next node to end of copyList
            *nptr = new Node(cptr->data, NULL);
            // update pointer to next of appended node
            nptr = &((*nptr)->next);
            cptr = cptr->next;
        }
    }

    LinkedList& operator=(const LinkedList& copyList)
    {
        Node* cptr = copyList.head;
        Node** nptr = &head;			// point to head
        while (cptr != NULL)
        {
            // append next node to end of copyList
            *nptr = new Node(cptr->data, NULL);
            // update pointer to next of appended node
            nptr = &((*nptr)->next);
            cptr = cptr->next;
        }
        //LinkedList<string> temp(copyList);
        //swap(temp.head, copyList.head);
        return *this;
    }


    void clear()
    {
        Node* nptr = head;
        while (nptr != NULL)
        {
            Node* dptr = nptr;
            nptr = nptr->next;
            delete dptr;

        }
        head = NULL;
    }

    void push_front(const T& item)
    {
        head = new Node(item, head);
    }

    void pop_front()
    {
        if (head != NULL) {
            Node *temp;
            temp = head;
            head = temp->next;
            delete temp;
        }
        else {
            throw string(" Empty!");
        }
    }

    friend ostream& operator<<(ostream& os, LinkedList& ll)
    {
        Node* node_ptr = ll.head;
        while (node_ptr != NULL)
        {
            os << node_ptr->data << (node_ptr->next != NULL ? " " : "");
            node_ptr = node_ptr->next;
        }
        return os;
    }

    int size()
    {
        int count = 0; // Initialize count
        Node* current = head; // Initialize current
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    T& front()
    {
        Node* node_ptr = head;
        if (head != NULL) {
            return node_ptr->data;
        }
        else {
            throw string("Empty!");
        }
    }
    void remove(const T& item)
    {
        Node* temp = head;
        Node* prev = NULL;
        Node* tmp = head;
        int count = 0;

        for(int i = 0; i <size(); i++){
            if (tmp->data == item) {
                count++;
            }
            tmp = tmp->next;
        }


        for(int i = 0; i < count; i++) {
            if (head != NULL && head->data == item) {
                head = temp->next;
                tmp = temp;
                temp = head;
                delete tmp;
            } else {
                while (temp != NULL && temp->data != item) {
                    prev = temp;
                    temp = temp->next;

                }

                if (temp == NULL)
                    return;

                // Unlink the node from linked list
                prev->next = temp->next;

                tmp = temp;
                temp = head;
                delete tmp;
            }
        }

    }
    bool empty()
    {
        if(size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void reverse()
    {
        if (head != NULL) {
            Node *current = head;
            Node *prev = NULL, *next = NULL;

            while (current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        else {
            throw string(" Empty!");
        }
    }
};

#endif //LINKED_LIST_LINKED_LIST_H
