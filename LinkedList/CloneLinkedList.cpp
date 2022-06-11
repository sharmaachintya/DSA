class Solution {
    private:
        void insertAtTail(Node* &head, Node* &tail, int d)
        {
            Node* newNode = new Node(d);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                return;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }

    public:
        Node* copyList(Node* head)
        {
            // Step 1 : Create a clone list using the next pointer of original list
            Node* cloneHead = NULL;
            Node* cloneTail = NULL;

            Node* temp = head;
            while (temp != NULL)
            {
                insertAtTail(cloneHead, cloneTail, temp->data);
                temp = temp->next;
            }

            // Step 2 : Create a Map

            unordered_map<Node*, Node*> oldToNewNode;

            Node* OriginalNode = head;
            Node* CloneNode = cloneHead;
            while (OriginalNode != NULL && CloneNode != NULL)
            {
                oldToNewNode[OriginalNode] = CloneNode;
                OriginalNode = originalNoe->next;
                CloneNode = CloneNode->next;
            }
            OriginalNode = head;
            CloneNode = CloneHead;

            while (OriginalNode != NULL)
            {
                CloneNode->random = oldToNewNode[OriginalNode->random];
                OriginalNode = OriginalNode->next;
                CloneNode = CloneNode->next;
            }
            return cloneHead;
        }
};