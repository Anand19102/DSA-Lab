1. Polynomial addition using arrays :- DONE USING STRUCTURES, ARRAY OF STRUCTURES AND 3 POINTERS/INDICES i,j,k.
variable declaration in main fn only, local var

(array of structures : every element in the array like arr[0] etc will be a structure, and each element will have multiple members) defined as struct_name array_name[size] and elements accessed as array_name[index].memberofstructure


2. Sparse matrix to triplet form :- each row is a structure, IMPLEMENTED USING ARRAY OF STRUCTURES (struct_name array_name[size])

3. Sparse matrix transpose : transpose matrix should be sorted row wise, so 
traverse through every column of the given sparse matrix and search if every non zero element is in the same column.
    
variable declaration in main fn only, local var

    // 'i' represents the column we are currently searching for.
    for (i = 0; i < sparse[0].col; i++) { 

        for (j = 1; j <= n; j++) {
            
            if (sparse[j].col == i) {
                transpose[k].row = sparse[j].col;
                transpose[k].col = sparse[j].row;
                transpose[k].value = sparse[j].value;
                k++; // Move to the next free slot in the transpose array.
            }
    one element in the sparse[] array means one row in the 3 tuple form table

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
            

one pointer is equal to another pointer means they point at the same location.
newNode->next = head means newNode->next also points at the same location where head points

in linked lists, if you need only one LL and are using global variables, you can have functions with void return type.

for bst, fn with return type struct Node* are used, and root is a local variable. and pointers like root will have to be passed as parameters to the functions 

temp->next->prev means exactly what you said: "access the prev pointer of the node that temp->next points to.

strcpy is to  be used only when we have an array of characters or string, if it is a single chara, we can substitute directly.



You're right, there are six parameters.
Technically, in C, **arrays are always passed by pointer**, and **`*nResult` is explicitly a pointer**.
So, the parameters that are "pass-by-reference" (passed by pointer) are:

1.  `struct Term poly1[]` (Used as **input**)
2.  `struct Term poly2[]` (Used as **input**)
3.  `struct Term polyResult[]` (Used as **output** to store the sum)
4.  `int *nResult` (Used as **output** to store the size of the sum)

The other two parameters, `int n1` and `int n2`, are passed by **value**. This means the function just gets a *copy* of their values, and any changes to `n1` or `n2` *inside* the function would not affect the variables back in `main`.

-----------------------------------------------------------
AIzaSyBv0ULYE507ajRfYTUKfaWrpfEj9V9yGFk : gemini key

**"NPX / No-Install" Plan**.
### Phase 1: In the Lab 
npx --version

**Step 2: Go "Incognito"**
To make sure your commands aren't saved, run this:

unset HISTFILE

**Step 3: Set Your API Key**

export GEMINI_API_KEY='AIzaSyBv0ULYE507ajRfYTUKfaWrpfEj9V9yGFk'

### Phase 2: In the Lab (How to Use the AI)
**Step 1: Start the AI Chat**
Run this command. It might take a moment as `npx` downloads the tool to a temp folder.

npx -p @google/gemini-cli gemini

**Step 2: Chat with Gemini**
This will start an **interactive chat** right in your terminal (e.g., `>>>`). You can now ask it for anything.

  * `>>> Write a C function to implement a stack using a linked list.`
  * `>>> I got this error: 'segmentation fault (core dumped)'. What are the common causes for this in C?`
  * `>>> [Paste your buggy code here] ... find the memory leak in this code.`

**Step 3: Quit the AI Chat**
When you're done getting help, just type:

/quit

### Phase 3: In the Lab (The Cleanup)

When your lab is over and you're ready to leave:

1.  **Delete Your Code (Optional but Safe):**
    If you `git clone`-d your code, you can delete the folder:
    `rm -rf .my-secret-dsa`

2.  **Clear the Session History:**
    history -c
    ```

3.  **Exit:**

    exit
-----------------------------------------------

Day 1 (One-Time Setup):

unset HISTFILE

curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash

source ~/.bashrc

nvm install node (You will never have to do these 4 steps again on this PC, unless the home directory is wiped)

Every Lab Day (Your Workflow):

unset HISTFILE

export GEMINI_API_KEY="YOUR_API_KEY"

npx -p @google/gemini-cli gemini

(Chat with the AI...)

/quit

history -c

exit

-----------------
You can disable the banner and other tips by creating a settings file. This is a one-time setup in the lab.

The first time you're in the lab, run this command to create the settings directory:

Bash

mkdir -p ~/.gemini
Then, create the settings file and add the "quiet" settings:

Bash

echo '{ "hideTips": true, "hideBanner": true }' > ~/.gemini/settings.json