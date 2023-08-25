#include <stdio.h>
#include <stdlib.h>
int n,m;

typedef struct nodetype
{
    int key;
    struct nodetype *next;
} NodeT;

//1
NodeT *create(int givenkey)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->next=NULL;
    p->key=givenkey;
    return p;
}

//2
void insert( NodeT *hashmap[n],int h, int givenkey) //h=x, givenkey=y
{
    NodeT *p=create(givenkey);

    if(hashmap[h]==NULL)
        hashmap[h]=p;
    else
    {
        p->next=hashmap[h];
        hashmap[h]=p;
    }
}

//3
/*int stergere(int n, NodeT *hashmap[n],int givenkey)
{
    int h=hash(givenkey);
    NodeT *p=hashmap[h];
    NodeT *q=NULL;
    while(p!=NULL)
    {
        if(p->key==givenkey)
            break;
        q=p;
        p=p->next;
    }
    int val=p->key;
    if(q!=NULL)
    {
        q->next=p->next;
        free(p);
    }
    else
    {
        hashmap[h]=hashmap[h]->next;
        free(p);
    }
    return val;
}*/

//4
void afisare(NodeT *hashmap[n])
{
    for(int i=1; i<=n; i++)
    {
        NodeT *p=hashmap[i];

        while(p!=NULL)
        {
            printf("%d ",p->key);
            p=p->next;
        }
        printf("\n");
    }
}

int main()
{
    FILE* f = fopen("adiac.txt", "r");
    if(f==NULL)
    {
        return 0;
    }

    int x,y;

    fscanf(f, "%d ", &n); //linii = noduri
    fscanf(f, "%d ", &m); //muchii

    NodeT *list[10]= {NULL};

    for(int i=1; i<=m; i++)
    {
        fscanf(f, "%d-%d", &x, &y);
        insert(list,x, y);
    }
    fclose(f);
    afisare(list);
    return 0;
}
