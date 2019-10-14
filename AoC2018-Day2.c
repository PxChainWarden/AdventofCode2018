#include <stdio.h>
#include <stdlib.h>

#define wordsize 26

typedef struct link
{
    //============================================================================================ My linked list I don't like arrays
    char string[wordsize];
    struct link * next;
}link;

void insert(link ** head, char * value)
{
    //============================================================================================ Our insert function that inserts given input to linked list
    link * ptr = *head;
    if(ptr == NULL)
    {
        // If head contains nothing we make it contains something
        ptr = (link *)malloc(sizeof(link));
        for(int i = 0; i < wordsize; i++)
            ptr->string[i] = *(value + i);
        ptr->next = NULL;
        *head = ptr;
        return;
    }
    // If it contains something we want to put our new value end of the list
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = (link *)malloc(sizeof(link));
    for(int i = 0; i < wordsize; i++)
            ptr->next->string[i] = *(value + i);
    ptr->next->next = NULL;
}

int compare(char * word, char * input)
{
    //============================================================================================ A function that returns 1 only if 1 character is different in same location of 2 strings
    int flag = 0;
    for(int i = 0; i < wordsize; i++)
    {
        if(*(word + i) == *(input + i))
            continue;
        else if(flag > 1)
            return 0;
        else
            flag++;
    }
    if(flag == 1)
        return 1;
    else
     return 0;
}

char * fix(char * string1, char * string2)
{
    char * final = (char *)malloc(sizeof(char) * (wordsize - 1));
    for(int i = 0, flag = 0; i < wordsize; i++)
    {
        if(*(string1 + i) == *(string2 + i))
            *(final + i - flag) = *(string1 + i);
        else
            flag = 1;
    }
    return final;
}

int main()
{
    // Our linked list head
    link * head;
    // Our input string
    char * input = malloc(sizeof(char) * wordsize);
    // Some pointer we use later on
    char * anan = NULL;
    char * baban = NULL;
    // A array that will store character counts for each word
    int alphabet[26];
    // Some flag variables
    int TwoCount = 0, ThreeCount = 0, TwoFlag = 0, ThreeFlag = 0;

    for(int i = 0; i < 250; i++)
    {
        // Iterate through each word. We got 250 lines of input so i counts to 250
        // Clear the character counts
        for(int i = 0; i < 26; i++)
            alphabet[i] = 0;
        // Clear the flags
        TwoFlag = 0;
        ThreeFlag = 0;
        // Clear and redefine pointers
        link * ptr = head;
        link * ptr2 = head;
        for(int j = 0; j < i; j++)
            ptr = ptr->next;
        char * arr = ptr->string;

        // Get our input
        scanf("%s", input);
        insert(&head, input);

        // Count how many characters same and store them in alphabetic order
        for(int j = 0; j < 26; j++)
            alphabet[(int)*(input+j) - 97] += 1;
        // Check if we got double same or triple same characters
        for(int j = 0; j < 26; j++)
        {
            if(alphabet[j] == 2)
                TwoFlag = 1;
            else if(alphabet[j] == 3)
                ThreeFlag = 1;
        }
        // Check if we found our 1 character different string
        for(int j = 0; j < 250 && ptr2 != NULL && anan == NULL; j++, ptr2 = ptr2->next)
            if(compare(ptr2->string, arr))
            {
                anan = arr;
                baban = ptr2->string;
            }
        // We need to increse our double or triple same character counts if we found
        TwoCount += TwoFlag == 1 ? 1 : 0;
        ThreeCount += ThreeFlag == 1 ? 1 : 0;
    }
    // Print what we got
    printf("Double's count  : %d\nTriple's Count  : %d\nFinal           : %d * %d = %d \n", TwoCount, ThreeCount, TwoCount, ThreeCount, TwoCount * ThreeCount);
    printf("First string    : %s\nSeond string    : %s\n", anan, baban);
    printf("Final           : %s\n", fix(anan, baban));
    return 0;
}