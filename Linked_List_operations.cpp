/*A program to create a linked list & perform various operations such as-
 a) Insert b) Delete c) Update d) Reverse */
#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Node *createNode(int data) // A function to create individiual node...
{
    Node *n;
    n = (Node *)malloc(sizeof(class Node));
    n->data = data;
    n->next = NULL;
    return n;
}
void traversal(Node *ptr) // A function to traverse LL..
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
class Node *insert(struct Node *head, int data, int index) // A function to insert node in LL...
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    if (index == 0)
    {
        ptr->next = head;
        ptr->data = data;
        return ptr;
    }
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
class Node *Delete(Node *head, int index) // A function to delete any element with index no. in LL...
{
    Node *p = head;
    if (index == 0)
    {
        head = head->next;
        free(p);
        return (head);
    }
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
class Node *update(Node *head, int data, int index) // A function to update a given LL...
{
    Node *ptr = head;
    if (index == 0)
    {
        ptr->data = data;
        return ptr;
    }
    int i = 0;
    while (i < index)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->data = data;
    return head;
}
class Node *reverse(Node *head) // A function to reverse a given Linked List...
{
    Node *ptr;
    Node *s = NULL;
    while (head != NULL)
    {
        ptr = head->next;
        head->next = s;
        s = head;
        head = ptr;
    }
    head = s;
    return head;
}
int main(void)
{
    Node *head, *second, *third, *fourth, *fifth;
    // Creating individiual node..
    head = createNode(7);
    second = createNode(8);
    third = createNode(22);
    fourth = createNode(11);
    fifth = createNode(45);
    // Linking the nodes to make a linked list...
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    cout << "Linked List : \n";
    traversal(head);
    cout << "Insert 14 at index 4 : \n";
    traversal(insert(head, 14, 4));         // Insertion...
    cout << "Delete element at index 2 : \n";
    traversal(Delete(head, 2));             // Deletion...
    cout << "Update 72 at index 2 : \n";
    traversal(update(head, 72, 2));         // Update...
    cout << "Reversed Linked List : \n";
    traversal(reverse(head));               // Reverse...

    return 0;
}