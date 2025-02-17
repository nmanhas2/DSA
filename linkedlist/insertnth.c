/*
    Inserting a Node at nth position
    Insert(data, n)

    Have to consider if n is an invalid position and if the head is null. Let's assume that the position we're
    receiving is valid however.

    To insert a Node at the nth position, we have to look at n-1th Node in order to send the "link" field of the new Node
    to be equal to the "link" field of the n-1th Node. Then we would set the "link" of the n-1th Node to be the address
    of the newly created Node

    Application's Memory:

    Heap (Free Store) //Not fixed, and we can request memory in run-time (ie. malloc)

    These are all fixed in sizes
    Stack //function call executions and stores the local variables
    Static/Global
    Code(Text)
*/

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data, int n);
void Print();

void Insert(int data, int n)
{

    //Memory block created on the Heap w/ malloc
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;
    for(int i = 0; i < n-2; i++) //doing n-2 because we want to get the link at the n-1th position
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    //Insert enters the stack
    Insert(2, 1); //List: 2
    Insert(3, 2);//List: 2,3
    Insert(4, 1);//List: 4, 2, 3
    Insert(5, 2);//List: 4,5,3,2
    
    Print();
}