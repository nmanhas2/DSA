#include <stdio.h>
#include <stdlib.h>

void Reverse();
void Insert(int data, int n);
void Print();

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void Insert(int data, int n)
{

    //Memory block created on the Heap w/ malloc
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if(n == 1)
    {
        temp1->next = head; //set temp1->next to be the current head's address
        head = temp1; //now set temp1 to be the new head
        return;
    }

    struct Node* temp2 = head;
    for(int i = 0; i < n-2; i++) //doing n-2 because we want to get the link at the n-1th position
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; //takes the number to the "left" of where we're inserting and gets the link to the next number
                               //since temp2 and the next number are next to each other at this point. this makes a link to the
                               //number on the "right"
    temp2->next = temp1;       //after that, we set temp2's link to be temp1, which lets temp1 get "sandwiched" between the "left"
                               //and the right numbers
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

void Reverse()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }

    head = prev;
}

int main()
{
    Insert(2,1);
    Insert(4, 2);
    Insert(6, 3);
    Insert(5, 4); 
    Print();
    Reverse();
    Print();
}

