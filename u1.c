#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL)); // srand takes seed as an input and its defined inside stdlib.h

    return rand() %n;
}

int greater(char char1, char char2)
{
    // Returns 1 id c1>c2 and 0 otherwise .If c1==c2 it will return -1

    if (char1 == char2)
    {
        return -1 ;
    }
    if((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }

    else if((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    else if((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int playerScore =0 ,compScore =0,temp ,i;
    char playerChar ,comChar;
    char dict[]={'r','p','s'};

    printf("Welcome to Rock ,paper, scissors\n");

    for( i=0; i<3 ; i++)
    {
        // Take Player 1's input
        printf("Player 1's turn :\n");
        printf("Choose 1 for Rock , 2 for paper ,3 for scissors\n");
        scanf("%d",&temp);
        getchar();
        playerChar =dict[temp-1];

        printf("You choose %c\n\n",playerChar);

        // Generate Computer's input

        printf("Computer's turn :\n");
        printf("Choose 1 for Rock , 2 for paper ,3 for scissors\n");
        temp = generateRandomNumber(3)+1;
        comChar =dict[temp-1];

        printf("CPU choose %c\n\n",comChar);

        // Compare the scores
        if(greater(comChar,playerChar)==1)
        {
            compScore += 1;
            printf("CPU got it ! \n");
        }
        else if(greater(comChar,playerChar)== -1)
        {
            compScore += 1;
            playerScore += 1;
            printf("It's a draw ! \n");
        }
        else
        {
            playerScore += 1;
            printf("You got it ! \n");
        }
        printf("You : %d\nCPU : %d\n\n\n",playerScore,compScore);
    }

    if (playerScore >compScore)
    {
        printf("You win the game \n");

    }
    if (playerScore <compScore)
    {
        printf("CPU win the game \n");
    }
    else if(playerScore ==compScore)
    {
        printf("It's draw\n");
    }


    return 0;
}
