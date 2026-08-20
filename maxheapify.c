#include<stdio.h>
#include<stdlib.h>

# define MAX 500

int heap[MAX];
int size = 0;

void insert(int n)
{
    int i = size;
    heap[i] = n;
    size++;

    while(i > 0)
    {
        int parent = (i - 1) / 2;
        if(heap[parent] >= heap[i])
        {
            break;
        }
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int deleteMax()
{
    if(size == 0)
    {
        printf("Size is empty\n");
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    int i = 0;
    while(1)
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;
        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;
        if (largest == i)
            break;
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }

    return max;

}
void display()
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main()
{
    int n,i;
    int value;
    printf("Enter the number of elements for the tree: ");
    scanf("%d", &n);
    printf("\nEnter the Elements\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }
    printf("Max Heap: ");
    display();

    printf("Deleted: %d\n", deleteMax());

    printf("After deletion: ");
    display();

    return 0;
}
