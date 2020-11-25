#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;
int** G;
int* dist;
int ver;

void BFS(int s, int rows) {
    int v;
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < rows; i++) {
            if (G[v][i] == 1 && dist[i] == -1) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int rows;
    int n = 0;
    int k = 0;
    system("cls");
    printf("rows:");
    scanf("%d", &rows);
    srand(time(NULL));
    G = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        G[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            G[i][j] = rand() % 2;
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    dist = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        dist[i] = -1;
    }
    printf("\n");
    printf("Start Vershina:");
    scanf("%d", &ver);
    printf("\n");
    BFS(ver, rows);
    for (int i = 0; i < rows; i++) {
        printf("%d ", dist[i]);
    }
    for (int i = 0; i < rows; i++)
        free(G[i]);
    free(G);
    getchar();
    return 0;
}

