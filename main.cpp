#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int initialData)
    {
        data = initialData;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    virtual ~LinkedList()
    {
        Node *currentNode = head;
        while (currentNode)
        {
            Node *toBeDeleted = currentNode;
            currentNode = currentNode->next;
            delete toBeDeleted;
        }
    }

    void ReverseList()
    {
        Node *nextNode = nullptr;
        Node *prevNode = nullptr;

        while (head != nullptr)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        head = prevNode;
    }

    void Append(Node *newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Prepend(Node *newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    LinkedList AddListAtEnd(LinkedList &numList2)
    {
        LinkedList newList;
        Node *current = head;

        while (current != nullptr)
        {
            Node *newNode = new Node(current->data);
            newList.Append(newNode);
            current = current->next;
            
        }
        current = numList2.head;
        while (current != nullptr)
        {
            Node *newNode = new Node(current->data);
            newList.Append(newNode);
            current = current->next;
            
        }

        return newList;
    }

    void AddIfGreaterThan(LinkedList &numList2)
    {
        Node * current = head;
        Node * current2 = numList2.head;
        while(current != nullptr)
        {
            if(current->data < current2->data)
                current->data = current->data + current2->data;

            current = current->next;
            current2 = current2->next;
        }

    }

    void PrintList(std::ostream &printStream, const std::string &separator = ", ")
    {
        Node *currentNode = head;
        if (currentNode)
        {
            // Head node is not preceded by separator
            printStream << currentNode->data;
            currentNode = currentNode->next;
        }
        while (currentNode)
        {
            printStream << separator << currentNode->data;
            currentNode = currentNode->next;
        }
        printStream << std::endl;
    }

    void InsertAfter(Node *currentNode, Node *newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    Node *GetMiddleNode()
    {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void DeleteThirdNodes()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
            return;
        if (head->next->next == nullptr)
            return;

        Node *previousNode = head;
        Node *thirdNode = head->next->next;
        // cout << thirdNode->data;

        while (previousNode != nullptr && thirdNode != nullptr)
        {
            previousNode = previousNode->next;
            previousNode->next = thirdNode->next;
            cout << thirdNode->data;
            delete thirdNode;
            previousNode = previousNode->next;
            if (previousNode != nullptr)
            {
                thirdNode = previousNode->next->next;
            }
        }
    }

    void RemoveAfter(Node *currentNode)
    {
        if (currentNode == nullptr && head)
        {
            // Special case: remove head
            Node *nodeRemoved = head;
            head = head->next;
            delete nodeRemoved;

            if (head == nullptr)
            {
                // Last item was removed
                tail = nullptr;
            }
        }
        else if (currentNode->next)
        {
            Node *nodeRemoved = currentNode->next;
            Node *succNode = currentNode->next->next;
            currentNode->next = succNode;
            delete nodeRemoved;
            if (succNode == nullptr)
            {
                // Remove tail
                tail = currentNode;
            }
        }
    }
};

int main()
{
    LinkedList numList;
    LinkedList numList2;

    Node *nodeA = new Node(1);
    Node *nodeB = new Node(2);
    Node *nodeC = new Node(3);
    // Node *nodeD = new Node(4);
    // Node *nodeE = new Node(5);
    // Node *nodeF = new Node(6);
    // Node *nodeG = new Node(7);
    // Node *nodeH = new Node(8);
    Node *nodeI = new Node(5);
    Node *nodeJ = new Node(1);
    Node *nodeK = new Node(4);

    numList.Append(nodeA);
    numList.Append(nodeB);
    numList.Append(nodeC);
    // numList.Append(nodeD);
    // numList.Append(nodeE);
    // numList2.Append(nodeF);
    // numList2.Append(nodeG);
    // numList2.Append(nodeH);
    numList2.Append(nodeI);
    numList2.Append(nodeJ);
    numList2.Append(nodeK);

    // Output list
    cout << "Initial list: ";
    numList.PrintList(cout);
    cout << "Initial list2: ";
    numList2.PrintList(cout);

    numList.AddIfGreaterThan(numList2);
    numList.PrintList(cout);

    // cout << "Reversed list: ";
    // numList.ReverseList();
    // numList.PrintList(cout);

    // // numList.DeleteThirdNodes();

    // cout << "List after deleting third nodes: ";
    // numList.PrintList(cout);

    // Node *middleNode;
    // middleNode = numList.GetMiddleNode();
    // cout << "The middle node is: ";
    // cout << middleNode->data << "\n";

    // LinkedList newList = numList.AddListAtEnd(numList2);
    // newList.PrintList(cout);
}