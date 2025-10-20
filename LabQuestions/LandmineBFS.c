#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 9999 // A large number to represent infinity

// Direction arrays to check neighbors (up, down, left, right)
int dirRow[] = {-1, 1, 0, 0};
int dirCol[] = {0, 0, -1, 1};

// A struct to store (x, y) coordinates
struct Node {
    int x, y;
};

// Queue implementation (array-based)
struct Node queue[MAX*MAX];
int front = 0, rear = -1;

// Enqueue: Add a coordinate to the back of the queue
void enqueue(int x, int y) {
    rear++;
    queue[rear].x = x;
    queue[rear].y = y;
}

// Dequeue: Remove and return a coordinate from the front
struct Node dequeue() {
    return queue[front++];
}

// Helper function to check if a cell is within the maze boundaries
int isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    int maze[MAX][MAX], dist[MAX][MAX];
    int n, m; // Maze dimensions
    
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);
    
    printf("Enter the maze (-1 for mine, 0 for path, # for wall as 999):\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d", &maze[i][j]);
    
    // --- Step 1: Initialize all distances to "infinity" ---
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            dist[i][j] = INF;
    
    // --- Step 2: Seed the BFS (Multi-Source) ---
    // Find all mines, add them to the queue, and set their distance to 0.
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (maze[i][j] == -1) { // -1 is a mine
                enqueue(i, j);
                dist[i][j] = 0; // Mine's distance to itself is 0
            }
        }
    
    // --- Step 3: Run the Multi-Source BFS ---
    while (front <= rear) { // While the queue is not empty
        // Dequeue the next cell to process
        struct Node temp = dequeue();
        int x = temp.x;
        int y = temp.y;
        
        // Loop through all 4 directions
        for (int k=0; k<4; k++) {
            int newX = x + dirRow[k];
            int newY = y + dirCol[k];
            
            // Check if the neighbor is valid, a path, and unvisited
            if (isValid(newX, newY, n, m) &&   // Is it on the board?
                maze[newX][newY] == 0 &&       // Is it a path (0)?
                dist[newX][newY] > dist[x][y] + 1) // Is this new path shorter?
            {
                // If yes, update its distance and add it to the queue
                dist[newX][newY] = dist[x][y] + 1;
                enqueue(newX, newY);
            }
        }
    }
    
    // --- Step 4: Print the resulting distance matrix ---
    printf("Shortest distance from land mines:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 999) printf("  # "); // Print wall
            else if (dist[i][j] == INF) printf(" INF "); // Print unreachable
            else printf("%3d ", dist[i][j]); // Print distance
        }
        printf("\n");
    }
    
    return 0;
}