/*
    The issue with an array is that if you want to add more, you may need to copy the elements and make a larger array
    in size. Another issue is that the memory is allocated in one block, ex: an int array with 4 elements would have 
    16 bytes of memory allocated to it. If we fill in 3 elements, this means that the rest of the memory could be wasted.

    In contrast, we could allocate memory as we add each element to the array one at a time, but the 
    downside is that the elements may not be adjacent within memory compared to an array. This means that they are 
    disjointed. Originally, we could take the starting address of the array and the position of the element in the array
    in order to calculate where it located in memory, since they were in one block of memory and adjacent to one another.

    As a result, we need more information to ensure that we indicate that the first element is in fact the first element
    of the array within memory. We can do this by storing the memory address of the NEXT block, so we
    could have a structure such that we have the data or element that is going into the array, and the memory address of
    where the next block would be located. The very last block can just have '0' as it the next block element, since that
    is invalid, which would indicate that there is no "node" to link to the last element beyond that.

    So far, we need to store the data and a pointer pointer value to the next block for the next node within the list.

    Ex:

    struct Node
    {
        int data; //4 bytes for an int for example
        Node* next; //4 bytes as well
    }

    The first node within the LinkedList is called the 'head' node, which gives us access to the complete list. Basically,
    to access an element within a LinkedList we must start at the head node, ask for the address of the next node, then
    ask the next node for the address of the next node, and so on, until you reach the element you want.

    If we want to insert, we simply create a separate node, take adjust the tail of the LinkedList such that the "next"
    part of the struct is allocated to the memory address of the node we want to insert, while making sure that the
    new node has it's "next" as 0 to indicate that it is now the new tail node.

    Accessing - not in constant time for a LinkedList! This is because we have to keep asking for the address
    of the next node to reach the element we want. It is O(n) time complexity for this reason, as it is proportional
    to the length of the list

    Insert - simply make a new node, and adjust the links accordingly. Also involves traversing through the list the 
    same way as accessing, so it is O(n) complexity. The benefit over a list is that we don't have to adjust the elements
    left or right to insert, we can just where an element is located in memory thanks to the links that we're keeping track
    of with "next".

    Remove - Same thing as insert basically -> O(n)
*/

/*
    Array vs. LinkedList.

    Cost of accessing an element: 
    
    -In an array it's constant time, since we use the base address of the array and if we
    want to find a particular element we would take the base address and add the index of that element mulitplied by
    the size. Ex: base = 200, Address of A[i] = 200 + i * 4 //assuming i is an integer (4 bytes). This means that the
    time complexity is O(1).  
    -As mentioned, accessing an element in a LinkedList is O(n) complexity

    Memory Requirements:

    -Arrays are fixed size, and could have unused memory that is allocated which would contain garbage values. Since memory
    is allocated for an array as a single block, there might be issues where there may not be memory available to create a
    single large block. Have to copy elements and make a larger array if we want to add beyond the fixed size allocated
    -For a LinkedList, we only ask for one node at a time hence there is no unused memory, but we do need to maintain
    extra memory in order to maintain the pointer variables for the "next". For this reason, if the data type takes less
    memory, a LinkedList would take up less space, but in some scenarios it will take up more space compared to an array.
    Another consideration is that memory may be available, but only in multiple small blocks

    Cost of inserting an element :
    
    a) at the beginning - O(n) for an array, O(1) for a LinkedList because we're simply taking the address of the head
    and giving that to the new node.

    b) at the end - O(1) for an array, if it's NOT full since we're just going one above the highest index of the array.
    If it's full, we'll have to make a new array and copy the elements from the previous array into it, hence making it
    O(n) complexity. For a LinkedList, it requires traversing the whole list until you get to the end and then adjusting
    the links ("next") as needed, hence making it O(n) complexity

    c) at i'th position - O(n) for an array on average. For a LinkedList it'll be O(n) as well, for similar reasons as 
    scenario b)

    Ease of Use:

    -Arrays are a lot easier to use obviously, while LinkedLists may be prone to seg faults so we have to be careful
*/

/*
    Basic LinkedList Implementation:

    struct Node
    {
        int data;
        Node* link;
    }

    Node* A;
    A = NULL; // empty initially

    Node* temp = (Node*)malloc(sizeof(Node)) //malloc returns a void*

    //(*temp).data = 2;
    //(*temp).link = NULL //since this is the only and last part of the list
    //Same thing as this:
    temp->data = 2;
    temp->link = NULL;

    A = temp;

    //new temp
    temp = (Node*)malloc(sizeof(Node));
    temp->data = 4;
    temp->link = NULL; 

    To traverse and insert the new "temp" at the end of the list:

    Node* temp1 = A;
    while(temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    temp1->link = temp; //this is simply adjusting the link now
*/

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void Insert(struct Node** pointerToHead, int x);
void Print(struct Node* head);

void Insert(struct Node** pointerToHead, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *pointerToHead;
    *pointerToHead = temp;
}

void Print(struct Node* head)
{
    printf("List is: ");
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    int n,i,x;
    struct Node* head = NULL; //empty list

    printf("How many numbers?\n");  
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the number: \n");
        scanf("%d", &x);

        Insert(&head, x);
        Print(head);
    }
}