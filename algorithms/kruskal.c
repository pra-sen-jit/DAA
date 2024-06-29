#include <stdio.h>

#define Max 7

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[Max];
  int n;
} edge_list;

edge_list elist;

//int Graph[Max][Max], n;
int n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();


void kruskalAlgo(int Graph[Max][Max])
{
  int belongs[Max], i, j, cno1, cno2;
  elist.n = 0;
  for(i = 1; i < n; i++)
    for(j = 0; j < i; j++) {
      if(Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }
  sort();
  for(i = 0; i < n; i++)
    belongs[i] = i;
  spanlist.n = 0;

  for(i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if(cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexNo)
{
  return belongs[vertexNo];
}

void applyUnion(int belongs[], int c1, int c2)
{
  int i;
  for(i = 0; i < n; i++)
    if(belongs[i] == c2)
      belongs[i] = c1;
}

void sort()
{
  int i, j;
  edge temp;
  
  for(i = 1; i < elist.n; i++)
    for(j = 0; j < elist.n - 1; j++)
      if(elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

void print()
{
  int i, cost = 0;
  for(i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }
  printf("\nSpanning tree cost: %d", cost);
}

int main()
{
  int i, j, total_cost;
  n = 7;
  int Graph[Max][Max] = {
    {0, 28, 0, 0, 0, 10, 0},
    {28, 0, 16, 0, 0, 0, 14},
    {0, 16, 0, 12, 0, 0, 0},
    {0, 0, 12, 0, 22, 0, 18},
    {0, 0, 0, 22, 0, 25, 24},
    {10, 0, 0, 0, 25, 0, 0},
    {0, 14, 0, 18, 24, 0, 0}
  };

  kruskalAlgo(Graph);
  print();
}