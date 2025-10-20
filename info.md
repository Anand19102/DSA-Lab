1. Polynomial addition using arrays :- DONE USING STRUCTURES, ARRAY OF STRUCTURES AND 3 POINTERS/INDICES i,j,k.


(array of structures : every element in the array like arr[0] etc will be a structure, and each element will have multiple members)


2. Sparse matrix to triplet form :- each row is a structure, IMPLEMENTED USING ARRAY OF STRUCTURES (struct_name array_name[size])

3. Sparse matrix transpose : transpose matrix should be sorted row wise, so 
traverse through every column of the given sparse matrix and search if every non zero element is in the same column.
    
    // 'i' represents the column we are currently searching for.
    for (i = 0; i < sparse[0].col; i++) { 

        for (j = 1; j <= n; j++) {
            
            if (sparse[j].col == i) {
                transpose[k].row = sparse[j].col;
                transpose[k].col = sparse[j].row;
                transpose[k].value = sparse[j].value;
                k++; // Move to the next free slot in the transpose array.
            }

4. Sparse matrix addition : again needs 3 pointers i,j,k like poly addition

5. Stack infix to postfix : int precedence(char c) {} function and also using pointers/indices i and j for traversing through the infix and postfix expression respectively inside 
                    void infixToPostfix(char infix[]){} function and 
            for (i = 0; infix[i] != '\0'; i++) condition

6. Linear Queue : rear = rear+1 and front = front + 1
    bool isEmpty and bool isFull, 
        for dequeue :
            front = front + 1; // "Removes" an item by moving the front pointer up
            printf("\nElement deleted from queue is : %d\n", queue[front]);

        for display:
            // Loop from the actual front element to the actual rear element
            for (i = front + 1; i <= rear; i++)
            printf("%d ", queue[i]);
        
        for peek:
            return queue[front + 1]; (no need of front=front+1)
