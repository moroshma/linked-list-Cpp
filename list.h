// Created by moroshma on 06.11.23.
#ifndef LINKED_LIST_CPP_LIST_H
#define LINKED_LIST_CPP_LIST_H
#include <iostream>
using namespace std;
enum ERRORS {
    SUCCESS = 0,
    INDEX_ERROR = 1
};

template <typename T>
class List {
public:
    List();
    ~List();
    void push_back(T data);
    int push_front(T data);
    int  insert(T data, size_t index);
    int  pop_back();
    int  pop_front();
    int remove(T data);
    int find(T data);
    void print_list();
    int pop_by_index(size_t index);
    int getSize() {return size;}

    class Node {
    public:
        Node * pNode;
        T data;
        explicit Node (T data = T(), Node * pNode = nullptr) {
            this -> data = data;
            this -> pNode = pNode;
        }
    };

    int size = 0;
    Node * head;

    Node * front() {return this -> head;};

    Node * back(){
        Node *current = this->head;
        while (current->pNode != nullptr) {
            current = current->pNode;
        }
        return current;
    };
    bool empty() {
        if(  size == 0) {
            return true;
        }
        else{
            return false;
        }
    }
};



template <typename T>
class DoubleList {
public:
    DoubleList();
    ~DoubleList();
    void push_back(T data);
    int push_front(T data);
    int  insert(T data, size_t index);
    int  pop_back();
    int  pop_front();
    int remove(T data);
    int find(T data);
    void print_list();
    int pop_by_index(size_t index);
    int getSize() {return size;}

private:
    class NodeD {
    public:
        NodeD * prefNode;
        NodeD * nextNode;
        T data;
        NodeD (T data = T(), NodeD * prefNode = nullptr, NodeD * nextNode = nullptr) {
            this -> data = data;
            this -> prefNode = prefNode;
            this -> nextNode = nextNode;
        }

    };

    int size = 0;
    NodeD * head;

public:

    NodeD * front() {return this -> head;};

    NodeD * back(){
        NodeD *current = this->head;
        while (current->nextNode != nullptr) {
            current = current->nextNode;
        }
        return current;
    };

    bool empty() {
        if(  size == 0) {
            return true;
        }
        else{
            return false;
        }
    }
};

template<typename T>
int DoubleList<T>::pop_by_index(size_t index) {
    if (index > size || index < 0) {
        return INDEX_ERROR;
    } else if (0 == index) {
        if(this -> head != nullptr) {
            NodeD * temp = this -> head -> nextNode;
            delete(head);
            head = temp;
            size--;
        }
    } else if (size - 1  == index){
        pop_back();
    }else {
        size_t indexCurElem = 0;
        NodeD * current = this -> head;

        while (current -> nextNode != nullptr && indexCurElem != index - 1) {
            index++;
            current = current -> nextNode;
        }

        if (index - 1 == indexCurElem) {
            if (current -> nextNode -> nextNode != nullptr) {
                NodeD *tmp = current->nextNode->nextNode;
                delete (current->nextNode);
                current->nextNode = tmp;
                current -> nextNode -> prefNode = current;
            } else {
                delete (current->nextNode);
                current->nextNode = nullptr;
            }
            size--;
        }
    }
    return SUCCESS;
}

template<typename T>
int DoubleList<T>::remove(T data) {
    return pop_by_index(find(data));
}

template<typename T>
int DoubleList<T>::find(T data) {

    if (this -> head != nullptr) {
        int index = 0;
        NodeD *current = this->head;
        NodeD * pref = this->head;
        if (this->head -> data == data) {
            return 0;
        }
        while (current-> nextNode != nullptr) {
            index++;
            if (current -> nextNode->data == data){
                return index;
            }
            current = current->nextNode;
        }
        return -1;

    } else {
        return -1;
    }
}

template<typename T>
int DoubleList<T>::pop_front() {
    return pop_by_index(0);
}

template<typename T>
int DoubleList<T>::insert(T data, size_t index) {

    if (index > size || index < 0) {
        return INDEX_ERROR;
    } if (0 == index) {
        this -> head = new NodeD(data, nullptr, this -> head);
    } else if (size - 1 == index){
        push_back(data);
    }else {
        size_t indexCurElem = 0;
        NodeD * current = this -> head;
        while (current != nullptr && indexCurElem != index - 1) {
            index++;
            current = current -> nextNode;
        }
        if (indexCurElem == index -1) {
            auto *newMember = new NodeD(data, current, current->nextNode);
            current->nextNode = newMember;
            current->nextNode ->nextNode -> prefNode = current->nextNode;
            size++;
        }


    }
    return SUCCESS;
}

template<typename T>
int DoubleList<T>::push_front(T data) {

    return 0;
}


template<typename T>
DoubleList<T>::~DoubleList() {
    while (size) {
        pop_back();
    }
}

template<typename T>
void DoubleList<T>::print_list() {
    if (0 == size) {
        cout << "List is empty" << endl;
    } else {
        size_t   index = 0;
        NodeD * current = this -> head;
        while (current != nullptr) {
            cout << "index " << index << " element is: "  << current -> data << endl;
            index++;
            current = current -> nextNode;
        }

    }

}


template<typename T>
int DoubleList<T>::pop_back() {
    if (this -> head != nullptr && size != 0) {
        NodeD *current = this->head;
        NodeD * pref = this->head;
        while (current-> nextNode != nullptr) {
            pref = current;
            current = current-> nextNode;
        }
        delete (current);
        pref -> nextNode = nullptr;
        size--;
    }
    return SUCCESS;
}



template<typename T>
void DoubleList<T>::push_back(T data) {
    if (nullptr == head) {
        head = new NodeD(data);
    }  else {
        NodeD * current = this -> head;
        while (current -> nextNode != nullptr) {
            current = current -> nextNode;
        }
        current -> nextNode = new NodeD(data, current);
    }
    size++;
}

template<typename T>
DoubleList<T>::DoubleList() {
    size = 0;
    head = nullptr;
}


#endif //LINKED_LIST_CPP_LIST_H
