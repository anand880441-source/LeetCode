class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index)
                return temp->data;

            temp = temp->next;
            count++;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = temp;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;
        int count = 0;

        while (curr != nullptr && count < index - 1) {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr)
            return;

        Node* temp = new Node(val);
        temp->next = curr->next;
        curr->next = temp;
    }

    void deleteAtIndex(int index) {

        if (head == nullptr)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        int count = 0;

        while (curr->next != nullptr && count < index - 1) {
            curr = curr->next;
            count++;
        }

        if (curr->next == nullptr)
            return;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */