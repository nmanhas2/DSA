/*
    To remove a node, we need to fix the links. We'll have to set the n-1th's link as the link of the nth node, which is the
    n+1th node

    If we want to remove the head, we'll have to point head to the second node, and then build the link between the second node
    and the third node.

    This isn't good enough however, since the nodes would still be taking up space in memory. This is because the node occupies
    space from dynamic memory (in the heap). So we have to free() it! 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int data, int n);
void Print();
void Delete(int n); //delete node at position n

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


void Delete(int n)
{
    struct Node* temp1 = head;
    int i = 0;

    if(n == 1)
    {
        head = temp1->next;
        free(temp1);
        return; 
    }

    for (i = 0; i < n-2; i++)
    {
        temp1 = temp1->next;
    }

    //temp1 now points to the (n-1)th node
    struct Node* temp2 = temp1->next; //temp2 = nth Node
    temp1->next = temp2->next; //creating a link between (n-1)th node and (n+1)th node 
    free(temp2); //we can get rid of the allocated memory for the nth node now
}   

int main()
{
    head = NULL;
    Insert(2,1);
    Insert(4, 1);
    Insert(6, 1);
    Insert(5, 1); //2,4,6,5
    Print();
    int n;
    printf("Enter a position: ");
    scanf("%d", &n);

    Delete(n);
    Print();

}