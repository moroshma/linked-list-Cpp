// Created by moroshma on 06.11.23.
#include "list.h"

using namespace std;

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
         Node (T data = T(), Node * pNode = nullptr) {
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


template<typename T>
int List<T>::find(T data) {

    if (this -> head != nullptr) {
        int index = 0;
        Node *current = this->head;
        Node * pref = this->head;
        if (this->head -> data == data) {
            return 0;
        }

        while (current->pNode != nullptr) {
            index++;
            if (current -> pNode->data == data){
                return index;
            }
            current = current->pNode;
        }
        return -1;

    } else {
        return -1;
    }
}


template<typename T>
int List<T>::remove(T data) {
    return pop_by_index(find(data));
}

template<typename T>
int List<T>::pop_front() {
    return pop_by_index(0);
}

template<typename T>
int List<T>::push_front(T data) {
    return  insert(data, 0);
}

template <typename T>
List<T>::~List() {
    while (size) {
         pop_back();
    }

}
template<typename T>
int List<T>:: pop_back() {
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
    } else if (0 == index) {
        if(this -> head != nullptr) {
            Node * temp = this -> head -> pNode;
            delete(head);
            head = temp;
            size--;
        }
    } else if (size - 1  == index){
         pop_back();
    }else {
        size_t indexCurElem = 0;
        Node * current = this -> head;

        while (current -> pNode != nullptr && indexCurElem != index - 1) {
            index++;
            current = current -> pNode;
        }

        if (index == indexCurElem) {

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
void List<T>::push_back(T data) {
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
int List<T>:: insert(T data, size_t index) {
    if (index > size || index < 0) {
        return INDEX_ERROR;
    } if (0 == index) {
        this -> head = new Node(data, this -> head);
    } else if (size - 1 == index){
        push_back(data);
    }else {
        size_t indexCurElem = 0;
        Node * current = this -> head;

        while (current != nullptr && indexCurElem != index - 1) {
            index++;
            current = current -> pNode;
        }
        if (indexCurElem == index -1) {
            Node *newMember = new Node(data, current->pNode);
            current->pNode = newMember;
            size++;
        }

    }
    return SUCCESS;
}




int main() {
    List<int> lst;

    lst.push_back(5);

    lst.push_back(10);

    lst.insert(15, 2);

    lst.push_back(20);

    lst.pop_by_index(2);

   // lst.push_front(30);

    lst.print_list();

    return SUCCESS;
}



