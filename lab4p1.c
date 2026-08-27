#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person *people = NULL;
struct person *minHeap = NULL;
struct person *maxHeap = NULL;
int n = 0;
int minSize = 0;
int maxSize = 0;

void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyUp(int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (minHeap[parent].age <= minHeap[i].age)
            break;

        swap(&minHeap[parent], &minHeap[i]);
        i = parent;
    }
}

void minHeapifyDown(int i)
{
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minSize && minHeap[left].age < minHeap[smallest].age)
            smallest = left;

        if (right < minSize && minHeap[right].age < minHeap[smallest].age)
            smallest = right;

        if (smallest == i)
            break;

        swap(&minHeap[i], &minHeap[smallest]);
        i = smallest;
    }
}

void maxHeapifyUp(int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (maxHeap[parent].weight >= maxHeap[i].weight)
            break;

        swap(&maxHeap[parent], &maxHeap[i]);
        i = parent;
    }
}

void maxHeapifyDown(int i)
{
    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxSize && maxHeap[left].weight > maxHeap[largest].weight)
            largest = left;

        if (right < maxSize && maxHeap[right].weight > maxHeap[largest].weight)
            largest = right;

        if (largest == i)
            break;

        swap(&maxHeap[i], &maxHeap[largest]);
        i = largest;
    }
}

void createMinHeap()
{
    int i;

    minSize = n;

    for (i = 0; i < n; i++)
        minHeap[i] = people[i];

    for (i = minSize / 2 - 1; i >= 0; i--)
        minHeapifyDown(i);

    printf("Min-heap created based on age.\n");
}

void createMaxHeap()
{
    int i;

    maxSize = n;

    for (i = 0; i < n; i++)
        maxHeap[i] = people[i];

    for (i = maxSize / 2 - 1; i >= 0; i--)
        maxHeapifyDown(i);

    printf("Max-heap created based on weight.\n");
}

void readData()
{
    FILE *fp;
    int i;
    char buffer[100];

    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    fscanf(fp, "%d", &n);

    people = malloc(n * sizeof(struct person));
    minHeap = malloc((n + 100) * sizeof(struct person));
    maxHeap = malloc(n * sizeof(struct person));

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &people[i].id);
        fscanf(fp, "%s", buffer);

        people[i].name = malloc(100 * sizeof(char));
        sprintf(people[i].name, "%s", buffer);

        fscanf(fp, "%d %d %d",
               &people[i].age,
               &people[i].height,
               &people[i].weight);
    }

    fclose(fp);

    printf("Id Name Age Height Weight(pound)\n");

    for (i = 0; i < n; i++)
        printf("%d %s %d %d %d\n",
               people[i].id,
               people[i].name,
               people[i].age,
               people[i].height,
               people[i].weight);
}

void insertPerson()
{
    struct person p;
    char name[100];

    printf("Enter Id Name Age Height Weight: ");
    scanf("%d %s %d %d %d",
          &p.id, name, &p.age, &p.height, &p.weight);

    p.name = malloc(100 * sizeof(char));
    sprintf(p.name, "%s", name);

    minHeap[minSize] = p;
    minSize++;

    minHeapifyUp(minSize - 1);

    printf("Person inserted into Min-heap.\n");
}

void deleteOldest()
{
    int i, oldest = 0;

    if (minSize == 0)
    {
        printf("Min-heap is empty.\n");
        return;
    }

    for (i = 1; i < minSize; i++)
    {
        if (minHeap[i].age > minHeap[oldest].age)
            oldest = i;
    }

    printf("Deleted: %s\n", minHeap[oldest].name);

    free(minHeap[oldest].name);

    minHeap[oldest] = minHeap[minSize - 1];
    minSize--;

    if (oldest < minSize)
    {
        minHeapifyUp(oldest);
        minHeapifyDown(oldest);
    }
}

void displayYoungestWeight()
{
    float kg;

    if (minSize == 0)
    {
        printf("Min-heap not created.\n");
        return;
    }

    kg = minHeap[0].weight * 0.453592;

    printf("Weight of youngest student: %.2f kg\n", kg);
}

int main()
{
    int option;

    while (1)
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                readData();
                break;

            case 2:
                if (people == NULL)
                    printf("Read data first.\n");
                else
                    createMinHeap();
                break;

            case 3:
                if (people == NULL)
                    printf("Read data first.\n");
                else
                    createMaxHeap();
                break;

            case 4:
                displayYoungestWeight();
                break;

            case 5:
                if (minHeap == NULL)
                    printf("Read data first.\n");
                else
                    insertPerson();
                break;

            case 6:
                deleteOldest();
                break;

            case 7:
                free(people);
                free(minHeap);
                free(maxHeap);
                return 0;

            default:
                printf("Invalid option.\n");
        }
    }
}