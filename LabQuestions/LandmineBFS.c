#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 9999

int dirRow[] = {-1, 1, 0, 0};
int dirCol[] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

struct Node queue[MAX*MAX];
int front = 0, rear = -1;

void enqueue(int x, int y) {
    rear++;
    queue[rear].x = x;
    queue[rear].y = y;
}

struct Node dequeue() {
    return queue[front++];
}

int isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    int maze[MAX][MAX], dist[MAX][MAX];
    int n, m;
    
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &n, &m);
    
    printf("Enter the maze (-1 for mine, 0 for path, # for wall as 999):\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d", &maze[i][j]);

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            dist[i][j] = INF;
 
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (maze[i][j] == -1) {
                enqueue(i, j);
                dist[i][j] = 0;
            }
        }
    
    while (front <= rear) {
        struct Node temp = dequeue();
        int x = temp.x;
        int y = temp.y;
        
        for (int k=0; k<4; k++) {
            int newX = x + dirRow[k];
            int newY = y + dirCol[k];
            
            if (isValid(newX, newY, n, m) && maze[newX][newY] == 0 && dist[newX][newY] > dist[x][y] + 1) {
                dist[newX][newY] = dist[x][y] + 1;
                enqueue(newX, newY);
            }
        }
    }
    
    printf("Shortest distance from land mines:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (maze[i][j] == 999) printf("  # ");
            else if (dist[i][j] == INF) printf(" INF ");
            else printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
