#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node *next;

        Node(T data)
            : data(data) , next(nullptr) {};
};

template <typename T>
class SinglyLinkedList {
    private:
        Node<T>* head;

    public:
        SinglyLinkedList()
            : head(nullptr){}

        void insertAtHead(T data) {
            Node<T> *temp = new Node<T>(data);

            // if head is not pointing to anything then simply point to new node
            if(this->head == nullptr) {
                this->head = temp;
                return;
            }

            // if head is already point at some node
            // first make new node points to head address
            temp->next = this->head;
            // change head point to new node
            this->head = temp;
        }

        T removeAtHead() {
            // if list is empty we can't remove node
            if(this->head == nullptr) {
                std::cout<<"List is Empty"<<std::endl;
                exit(1);
            }

            // save data of node where head is pointed
            T data = this->head->data;
            // save temp pointer to free the memory
            Node<T>* temp_ptr = this->head;
            this->head = this->head->next;

            // free memory
            delete temp_ptr;
            return data;
        }

        void printList() const {
            if(this->head == nullptr) {
                std::cout<<"List is Empty"<<std::endl;
            } else {
                Node<T> *itr = this->head;
                // iterate through list until itr reach to nullptr and print data
                while(itr != nullptr) {
                    std::cout<<itr->data<<" ";
                    itr = itr->next;
                }
                std::cout<<std::endl;
            }
        }
};

int main() {
    SinglyLinkedList<int> l;
    l.insertAtHead(1);
    l.insertAtHead(2);
    l.insertAtHead(3);
    l.removeAtHead();
    l.printList();
    return 0;
}
