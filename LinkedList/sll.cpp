#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode (int value) {
            val = value;
            next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        ListNode* head;
        int count;
        SinglyLinkedList() {
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
            newNode->next = current->next;
            current->next = newNode;
            count++;

        }
        
        void deleteAtIndex(int index) {
            if (index > count || index < 0) 
                return;

            if (index == 0) {
                ListNode* delNode = head->next;
                head = head->next;
                delete delNode;
            } else {
                ListNode* current = head;
                for(int i=0; i < index-1; ++i)
                    current = current->next;

                ListNode* delNode = current->next;
                current->next = delNode->next;
                delete delNode;
            }

            count--;
        }

        void traverse(ListNode* head) {
            ListNode* current = head;
            while(current) {
                cout << current->val << " ";
                current = current->next;
            }
            cout << endl;
        }

        bool hasCycle(ListNode *head) {
            // checks if cycle exists or not
            if (!head || !head->next) return false;
            
            ListNode* slow = head;
            ListNode* fast = head;
            
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;    
                
                if (fast == slow) return true;
            }
            // unordered_map<ListNode*, ListNode*> hashmap;

            // while (current && current->next) {
            //     if(hashmap.count(current) <= 0) {
            //         hashmap[current] = current->next;
            //         current = current->next;
            //     } else {
            //         return true;
            //     }
            // }
            return false;
        }

        ListNode *detectCycle(ListNode *head) {
            // checks if cycle exists  and return that node
            if (!head || !head->next) return nullptr;
            
            ListNode* slow = head;
            ListNode* fast = head;
            
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;    
                
                if (fast == slow) break;
            }
            
            if (!(fast && fast->next)) return nullptr;
            
            while (head != slow) {
                head = head->next;
                slow = slow->next;
            }
            
            return head;
        }

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            // unordered_map<ListNode*, int> hashmap;
            ListNode* currentA = headA;
            ListNode* currentB = headB;
            
            // while(currentA || currentB) {
            //     if(hashmap.count(currentA) > 0) 
            //         return currentA;
            //     else if (currentA)
            //         hashmap[currentA]++;
                
            //     if(hashmap.count(currentB) > 0) 
            //         return currentB;
            //     else if (currentB)
            //         hashmap[currentB]++;
                
            //     currentA = currentA ? currentA->next : nullptr;
            //     currentB = currentB ? currentB->next : nullptr;
            // }
            while (currentA != currentB){
                currentA = currentA ? currentA->next : headB;
                currentB = currentB ? currentB->next : headA;
            }
            return currentA;
        }

        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* del;

            for (int i=0; i<n; ++i) {
                fast = fast->next;
            }
            if(!fast) {
                del = head;
                head = head->next;
                delete(del);
                return head;
            }

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            del = slow->next;
            slow->next = slow->next->next; 

            delete(del);

            return head;
        }

        ListNode* reverseList(ListNode* head) {
            if(!head) return nullptr;
            
            ListNode* current = head;
            
            while(current && current->next) {
                ListNode* move = current->next;
                current->next = move->next;
                move->next = head;
                head = move;
            }   
            return head;
        }

        ListNode* removeElements(ListNode* head, int val) {
            while (head && head->val == val) {
                head = head->next;
            }
            
            ListNode* current = head;
            ListNode* prev = nullptr;
            
            while (current) {
                if (current->val == val && prev) {
                    prev->next = current->next;            
                } else {
                    prev = current;
                }
                
                current = current->next;
            }

            return head;
        }
     
        ListNode* oddEvenList(ListNode* head) {
            if(!head) return nullptr;
            
            ListNode* currentOdd = head;
            ListNode* currentEven = head->next;
            ListNode* firstEven = currentEven;
            
            while(currentEven && currentEven->next) {
                ListNode* move = currentEven->next;
                currentEven->next = move->next;
                move->next = firstEven;
                currentOdd->next = move;
                currentOdd = currentOdd->next;
                currentEven = currentEven->next;
            }   
            return head;
        }

        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;

            // Find the middle of the linked list
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Reverse the second half of the linked list
            ListNode* prev = nullptr;
            ListNode* current = slow->next;
            while (current) {
                ListNode* move = current->next;
                current->next = prev;
                prev = current;
                current = move;
            }

            // Compare the first half with the reversed second half
            ListNode* current1 = head;
            ListNode* current2 = prev;
            while (current1 && current2) {
                if (current1->val != current2->val) return false;
                current1 = current1->next;
                current2 = current2->next;
            }

            // Restore the original linked list (reversing the reversed second half back)
            prev = nullptr;
            current = prev;
            while (current) {
                ListNode* move = current->next;
                current->next = prev;
                prev = current;
                current = move;
            }
            slow->next = prev;

            return true;
        }

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* result = new ListNode(0);
            ListNode* current = result;

            while (list1 && list2) {
                if (list1->val < list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }

            if (list1)
                current->next = list1;
            else
                current->next = list2;

            return result->next;
        }

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry = 0;
            ListNode* result = new ListNode(0);
            ListNode* curr = result;
            
            while (l1 || l2 || carry) {
                int answer = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + carry;
                carry = answer / 10;
                curr->next = new ListNode(answer % 10);
                curr = curr->next;
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
            }
            return result->next;
        }

        void reorderList(ListNode* head) {
            if (!head || !head->next) return;

            // traverse(head);

            // Find the middle of the linked list
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            // Reverse the second half of the linked list
            ListNode* prev = nullptr;
            ListNode* current = slow->next;
            while (current) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            // traverse(head);
            slow->next = nullptr; // break the link between first and second half
            // traverse(head);
            // traverse(prev);

            // Merge the first half and the reversed second half alternately
            ListNode* first = head;
            while (first && prev) {
                ListNode* temp1 = first->next;
                ListNode* temp2 = prev->next;
                first->next = prev;
                prev->next = temp1;
                first = temp1;
                prev = temp2;
            }
            // traverse(head);
        }

};

int main()
{
    SinglyLinkedList* obj = new SinglyLinkedList();
    obj->addAtHead(5);
    obj->addAtHead(4);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(1);

    obj->reorderList(obj->head);
    // obj->addAtTail(12);
    // int param_1 = obj->get(1);
    // obj->addAtTail(13);
    // obj->addAtTail(14);
    // int param_3 = obj->get(3);
    // obj->addAtIndex(2,15);
    // obj->addAtIndex(4,16);
    // obj->traverse();
    // obj->deleteAtIndex(0);
    // obj->traverse();

    // cout << param_1 << " " << param_3 << endl;
    return 0;
}