#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct link
{
    //============================================================================================ My linked list I don't like arrays
    int value;
    struct link * next;
}link;

void insert(link ** head, int value)
{
    //============================================================================================ Our insert function that inserts given input to linked list
    link * ptr = *head;
    if(ptr == NULL)
    {
        // If head contains nothing we make it contains something
        ptr = (link *)malloc(sizeof(link));
        ptr->value = value;
        ptr->next = NULL;
        *head = ptr;
        return;
    }
    // If it contains something we want to put our new value end of the list
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = (link *)malloc(sizeof(link));
    ptr->next->value = value;
    ptr->next->next = NULL;
}

int find(link * head, int value)
{
    //============================================================================================ A function that checks if our value exist in given linked list, if exist returns that value else returns 0
    for(link * ptr = head; ptr != NULL; ptr = ptr->next)
        if(ptr->value == value)
            return value;
    return 0;
}

int main()
{
    // Our variables we needed
    link * prevFreqhead = NULL;
    link * prevInputhead = NULL;
    bool part2 = false, part1 = false;

    // Get inputs from given file until it reaches last input
    for(int inputFreq; inputFreq != 80922; insert(&prevInputhead, inputFreq))
        scanf("%d", &inputFreq);

    // Loop until we got what we want
    for(int currFreq = 0; !part2;)
    {
        // Iterate through inputs
        for(link * ptr = prevInputhead; ptr != NULL; ptr = ptr->next)
        {
            // Add inputs to our sum
            currFreq += ptr->value;
            // If we found that sum already exist we found what we want
            if(find(prevFreqhead, currFreq) && !part2)
            {
                printf("part 2 : %d \n", currFreq);
                part2 = true;
                break;
            }
            // If not we want to insert that unique value to our list
            insert(&prevFreqhead, currFreq);
        }
        if(!part1)
        {
            printf("part 1 : %d \n", currFreq);
            part1 = true;
        }
    }
    return 0;
}