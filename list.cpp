// Created by moroshma on 06.11.23.
#include "list.h"

using namespace std;

template <typename T>
class List {
public:
    List();
    ~List();
    void push_Back(T data);
    int push_index(T data, size_t index);
    void print_list();
    int pop_by_index(size_t index);
    int pop_last();

    int getSize() {return size;}

    //template <typename T>
    class Node {
    public:
        Node * pNode;
        T data;
         Node (T data = T(), Node * pNode = nullptr) {
            this -> data = data;
            this -> pNode = pNode;
        }
    };

    int size = 0;
    Node * head;
};

template <typename T>
List<T>::~List() {
    while (size) {
        pop_last();
    }

}
template<typename T>
int List<T>::pop_last() {
    if (this -> head != nullptr) {
        Node *current = this->head;
        Node * pref = this->head;
        while (current->pNode != nullptr) {
            pref = current;
            current = current->pNode;
        }
        delete (current);
        pref -> pNode = nullptr;
        size--;

    }
    return SUCCESS;
}

template <typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
int List<T>::pop_by_index(size_t index) {
    if (index > size || index < 0) {
        return INDEX_ERROR;
    } if (0 == index) {
        if(this -> head != nullptr) {
            Node * temp = this -> head -> pNode;
            delete(head);
            head = temp;
            size--;
        }
    } if (size == index){
        pop_last();
    }else {
        size_t indexCurElem = 0;
        Node * current = this -> head;

        while (indexCurElem != index - 1) {
            index++;
            current = current -> pNode;
        }
        if (current -> pNode -> pNode != nullptr) {
            Node *tmp = current->pNode->pNode;
            delete (current->pNode);
            current->pNode = tmp;
        } else {
            delete (current->pNode);
            current->pNode = nullptr;
        }

        size--;
    }
    return SUCCESS;

}



template<typename T>
void List<T>::print_list() {
    if (0 == size) {
        cout << "List is empty" << endl;
    } else {
        size_t   index = 0;
        Node * current = this -> head;
        while (current != nullptr) {
            cout << "index " << index << " element is: "  << current -> data << endl;
            index++;
            current = current -> pNode;
        }

    }
}


template<typename T>
void List<T>::push_Back(T data) {
    if (nullptr == head) {
        head = new Node(data);
    }  else {
       Node * current = this -> head;
        while (current -> pNode != nullptr) {
            current = current -> pNode;
        }
        current -> pNode = new Node(data);
    }
    size++;

}
template <typename T>
int List<T>::push_index(T data, size_t index) {
    if (index > size || index < 0) {
        return INDEX_ERROR;
    } if (0 == index) {
        this -> head = new Node(data, this -> head);
    } if (size == index){
        push_Back(data);
    }else {
        size_t indexCurElem = 0;
        Node * current = this -> head;

        while (indexCurElem != index - 1) {
            index++;
            current = current -> pNode;
        }
        Node * newMember = new Node(data, current -> pNode);
        current -> pNode = newMember;
        size++;
    }
    return SUCCESS;
}




int main() {
    List<int> lst;

    lst.push_Back(5);

    lst.push_Back(10);

    lst.push_index(15, 1);

    lst.push_Back(20);
    lst.pop_by_index(1);

    lst.print_list();

}



