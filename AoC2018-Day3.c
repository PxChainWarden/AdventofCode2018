#include <stdio.h>

void setArray(int * array, int posI, int posJ, int length, int width)
{
    // A function that inserts +1 to our rectangles area
    for(int i = posI; i < posI + width; i++)
        for(int j = posJ; j < posJ + length; j++)
            *(array + i * 1100 + j) += 1;
}

int check(int * array, int posI, int posJ, int length, int width)
{
    // A function that checks if our rectangle overlap
    for(int i = posI; i < posI + width; i++)
        for(int j = posJ; j < posJ + length; j++)
            if(*(array + i * 1100 + j) != 1)
                return 0;
    return 1;
}

int main()
{
    // Our variables
    int overlap = 0,part2 = 0;
    int inputArray[1347 * 5];
    int array[1100*1100];

    // Make our main array full of 0
    for(int i = 0; i < 1100*1100; i++)
        array[i] = 0;
    
    // Get our inputs
    for(int i = 0; i < 1347; i++)
    {
        scanf(" #%d @ %d,%d: %dx%d", &inputArray[i * 5], &inputArray[i * 5 + 1], &inputArray[i * 5 + 2], &inputArray[i * 5 + 3], &inputArray[i * 5 + 4]);
        setArray(array, inputArray[i * 5 + 2], inputArray[i * 5 + 1], inputArray[i * 5 + 3], inputArray[i * 5 + 4]);
    }
    
    // Search main array
    for(int i = 0; i < 1100*1100; i++)
    {
        // If our arrays elements bigger than 1 that means there is a overlap and if we found overlap we want to increase overlap count
        if(array[i] > 1)
            overlap += 1;
        
        // We want to keep i lower than 1347(our input count) and check if our rectangle overlaps
        if(!part2 && i < 1347 && check(array, inputArray[i * 5 + 2], inputArray[i * 5 + 1], inputArray[i * 5 + 3], inputArray[i * 5 + 4]))
        {
            // Print our rectangle id and make sure we dont search that rectangle again
            printf("Part 2 : %d\n", inputArray[i * 5]);
            part2 = 1;
        }
    }
    
    // Print our overlap count
    printf("Part 1 : %d\n", overlap);
    return 0;
}