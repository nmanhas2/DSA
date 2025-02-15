/*
    Lists:

    -empty list has size 0
    -insert
    -remove
    -count
    -read/modify element at a position
    -specify data-type

    You can implement a list as an array, with some added functionality
    Ex: an int list - 

    int A[MAX_SIZE] 

    int end = -1 //this implies that the list is empty, because 0 is the lowest index
    insert(2) //inserts at the 'tail' or end of the list, pos = 0
    insert(4) //pos = 1
    insert(6) //2
    insert(7) //3
    insert(9) //4
    insert(5, 2) //inserting at a specified position, youd would have to push all the other elements to the right
                 //pos = 2

    remove(0) //removing would mean to shift all elements to the left pos = 4

    What's the issue with this? There is a max size, there is no way to simply keep adding to an array in C,
    so when the array is FULL we need to create a larger array, copy the previous array into the new array, and
    free the memory for the previous array

    What size should  the new array be? It's good practice to make it double the initial array's size

    Now lets think about the time cost:

    Access - Read/Write element at an index -> this is a constant time because we simply use memory and the index  of 
    the array to access an element. Thus, it is O(1) time complexity.

    Insert - If we're only using insert(i), then it's a constant time because we're only inserting at the end of the
    array. If we're inserting at a specific index, ie. insert(i, x), then the time complexity is directly proportional
    to the length of the list. This means o(n) complexity. //costly

    Remove - Also o(n), for the same reasons as insert //costly

    Add - Constant time, but we have to remember that we must create a new array of double size when it gets full, so
    it's o(n) time complexity. //costly

    LinkedLists are more efficient in terms of memory for this reason!!!!
*/