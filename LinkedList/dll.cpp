#include <iostream>
#include <stack>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode* child;
        ListNode (int value) {
            val = value;
            prev = nullptr;
            next = nullptr;
            child = nullptr;
        }
};

class DoublyLinkedList {
    public:
        ListNode* head;
        int count;
        DoublyLinkedList() {
            head = nullptr;
            count = 0;
        }
        
        int get(int index) {
            if (index >= count || index < 0) 
                return -1;
            ListNode* current = head;
            for (int i=0; i<index; ++i) {
                current = current->next;
            }

            return current->val;
        }
        
        void addAtHead(int val) {
            ListNode* newNode = new ListNode(val);
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
            count++;
        }
        
        void addAtTail(int val) {
            if(count == 0) {
                addAtHead(val);
                return;
            }
            ListNode* current = head;
            while(current->next)
                current = current->next;
            
            ListNode* newNode = new ListNode(val);
            newNode->prev = current;
            current->next = newNode;
            count++;
        }
        
        void addAtIndex(int index, int val) {
            if (index > count || index < 0) 
                return;
            if (index == 0) {
                addAtHead(val);
                return;
            }
            if (index == count) {
                addAtTail(val);
                return;
            }

            ListNode* current = head;
            for(int i=0; i < index-1; ++i)
                current = current->next;
            
            ListNode* newNode = new ListNode(val);
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            count++;

        }
        
        void deleteAtIndex(int index) {
            if (index >= count || index < 0) 
                return;

            if (index == 0) {
                ListNode* delNode = head;
                head = head->next;
                if (head) head->prev = nullptr;
                delete delNode;
            } else {
                ListNode* current = head;
                for(int i=0; i < index-1; ++i)
                    current = current->next;

                ListNode* delNode = current->next;
                current->next = delNode->next;
                if (current->next) 
                    delNode->next->prev = current;
                delete delNode;
            }

            count--;
        }

        void traverseForward() {
            ListNode* current = head;
            while(current) {
                cout << current->val << " ";
                current = current->next;
            }
            cout << endl;
        }
        void traverseBackward() {
            ListNode* current = head;
            while(current->next) {
                // cout << current->val << " ";
                current = current->next;
            }
            while(current) {
                cout << current->val << " ";
                current = current->prev;
            }
            cout << endl;
        }

        ListNode* flatten(ListNode* head) {
        if(!head) return head;
        ListNode* current = head;
        
        // vector<Node*> prevParents;
        
        // while(true) {
        //     while(current && current->next) {
        //         if(current->child) { 
        //             prevParents.push_back(current);
        //             current = current->child;
        //         } else
        //             current = current->next;
        //     }
        //     Node* last = current;
        //     while(current && current->prev) {
        //         current = current->prev;
        //     }
        //     if(prevParents.size() <= 0) break;
        //     Node* prevParent = prevParents[prevParents.size()-1];
        //     current->prev = prevParent;
        //     last->next = prevParent->next;
        //     prevParent->next->prev = last;
        //     prevParent->next = current;
        //     prevParent->child = nullptr;
        //     prevParents.pop_back();
        //     current = last->next;
        // }
        stack<ListNode*> stack;

        while (current) {
            if (current->child) {
                if (current->next) {
                    stack.push(current->next);
                }
                current->next = current->child;
                current->next->prev = current;
                current->child = nullptr;
            }

            if (!current->next && !stack.empty()) {
                ListNode* nextNode = stack.top();
                stack.pop();
                current->next = nextNode;
                if (nextNode) {
                    nextNode->prev = current;
                }
            }

            current = current->next;
        }
        
        return head;
    }


};

int main()
{
    DoublyLinkedList* obj = new DoublyLinkedList();
    obj->addAtHead(2);
    obj->traverseForward();
    obj->deleteAtIndex(1);
    obj->traverseForward();
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);
    cout << obj->get(5) << endl;
    obj->traverseForward();
    obj->deleteAtIndex(6);
    obj->deleteAtIndex(4);
    obj->traverseForward();
    // obj->addAtTail(14);
    // obj->addAtIndex(2, 23);
    // obj->addAtIndex(4, 24);

    obj->traverseBackward();
    

    // cout << param_1 << " " << param_3 << endl;
    return 0;
}