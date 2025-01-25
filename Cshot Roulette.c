#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void usemagnifyingglassP(int B[], int index)
{
    printf("You used a magnifying glass to see the bullet.\n");
    printf("The current bullet in the chamber is: %d\n", B[index]);
}

void usemagnifyingglassO(int B[], int index, int *turn, int *HealthP)
{
    printf("The opponent used a magnifying glass to see the bullet.\n");
    printf("The current bullet in the chamber is: %d\n", B[index]);
    if (B[index] == 1)
    {
        printf("The opponent chose to hit you.\n");
        *HealthP = *HealthP - 1;
        printf("Your health is now %d.\n", *HealthP);
    }
    else
    {
        printf("The opponent chose to hit you.\n");
        *HealthP = *HealthP;
        printf("Your health is still %d.\n", *HealthP);
    }
    *turn = 0;
}

void usedeshiP(int B[], int *index, int BN)
{
    printf("You drank deshi and shot the bullet in the air.\n");
    printf("The current bullet in the chamber is skipped: %d\n", B[*index]);
    if (*index < BN - 1)
    {
        (*index)++;
    }
    else
    {
        printf("No more bullets left! No one wins.\n");
        printf("please run again the programs this function does not work correctly");
    }
}

void usedeshiO(int B[], int *index, int BN, int *turn)
{
    printf("The opponent drank deshi and shot the bullet in the air.\n");
    printf("The current bullet in the chamber is skipped: %d\n", B[*index]);
    if (*index < BN - 1)
    {
        (*index)++;
    }
    else
    {
        printf("No more bullets left! No one wins.\n");
    }
    *turn = 1;
}

void usepatanjalikadhaP(int *HealthP)
{
    printf("You drank Patanjali kadha.\n");
    *HealthP = *HealthP + 1;
    printf("Your health is now %d.\n", *HealthP);
}

void usepatanjalikadhaO(int *HealthO, int *turn)
{
    printf("The opponent drank Patanjali kadha.\n");
    *HealthO = *HealthO + 1;
    printf("The opponent's health is now %d.\n", *HealthO);
    *turn = 1;
}

void usegamblingpillsP(int *HealthP)
{
    int choice;
    srand(time(NULL));
    printf("You tried your luck and took gambling pills.\n");
    choice = rand() % 2 + 1;
    switch (choice)
    {
    case 1:
        *HealthP = *HealthP + 2;
        printf("Your health increased to %d.\n", *HealthP);
        break;

    case 2:
        *HealthP = *HealthP - 2;
        printf("Your health decreased to %d.\n", *HealthP);
        break;
    }
}

void usegamblingpillsO(int *HealthO, int *turn)
{
    int choice;
    srand(time(NULL));
    printf("The opponent tried his luck and took gambling pills.\n");
    choice = rand() % 2 + 1;
    switch (choice)
    {
    case 1:
        *HealthO = *HealthO + 2;
        printf("The opponent's health increased to %d.\n", *HealthO);
        break;

    case 2:
        *HealthO = *HealthO - 2;
        printf("The opponent's health decreased to %d.\n", *HealthO);
        break;
    }
    *turn = 1;
}

void useconverterP(int B[], int index)
{
    B[index] = !B[index];
    printf("The bullet in the chamber has been converted.\n");
}

void useconverterO(int B[], int index, int *turn)
{
    B[index] = !B[index];
    printf("The bullet in the chamber has been converted.\n");
    *turn = 1;
}
void usemakeitdoublebarrelP(int B[], int index, int *turn, int *HealthO)
{
    printf("user used another barrel and made gun double barreled\n");
    if (B[index] == 1)
    {
        *HealthO = *HealthO - 2;
        printf("\nopponent's health:%d", *HealthO);
    }
    else
    {
        *HealthO = *HealthO;
        printf("\nbad luck is on your side,opponent's health:%d", *HealthO);
    }
    *turn = 1;
}
void usemakeitdoublebarrelO(int B[], int index, int *turn, int *HealthP)
{
    printf("\nopponent used another barrel to make the gun double barreled");
    if (B[index] == 0)
    {
        *HealthP = *HealthP - 2;
        printf("\nopponent hit with you,your health:%d", *HealthP);
    }
    else
    {
        *HealthP = *HealthP;
        printf("\nyour luck was good it not a bullet,your health:%d", *HealthP);
    }
    *turn = 0;
}

int main()
{
    int BN, It, HealthO, HealthP, B[8], i, j, I[5], choice, turn, playagain, hasone = 0, useitemchoice, itemIndex = 0, itemchoice, gameover;
    srand(time(NULL));

    printf("------------ Welcome to Cshot Roulette ------------\n");
    printf("------------ I hope you die, my friend ------------\n\n");

    printf("The opponent is a computer, not AI, so basically he's dumb. It's a shame if you lose to him.\n\n");
    printf("Just so you know, items are as follows:\n");
    printf("1 = Magnifying glass\n");
    printf("2 = Deshi daaru\n");
    printf("3 = Patanjali kadha\n");
    printf("4 = Gambling pills\n");
    printf("5 = Converter\n");
    printf("6 = make it double barreled\n\n");

    do
    {
        int It, BN, i, j, hasone = 0, itemIndex = 0, size = sizeof(B) / sizeof(B[0]), true = 0, false = 0, count1 = 0, count0 = 0;
        HealthO = 3, HealthP = 3, turn = 0, gameover = 0, B[8], I[5];
        BN = rand() % 7 + 2;
        printf("Number of bullets: %d\n", BN);

        for (i = 0; i < BN; i++)
        {
            B[i] = rand() % 2;
            if (B[i] == 1)
            {
                hasone = 1;
            }
        }
        if (!hasone)
        {
            B[rand() % BN] = 1;
        }
        for (i = 0; i < BN; i++)
        {
            if (B[i] == 1)
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }
        printf("Number of true bullets: %d\n", count1);
        printf("Number of false bullets: %d\n", count0);
        printf("\nRandom array (B): ");
        for (i = 0; i < BN; i++)
        {
            printf("%d ", B[i]);
        }
        printf("\n");

        It = rand() % 6 + 1;
        printf("Number of items: %d\n", It);
        printf("Random array (I): ");
        for (j = 0; j < It; j++)
        {
            I[j] = rand() % 6 + 1;
            printf("%d ", I[j]);
        }
        printf("\n");

        for (i = 0; i < BN && HealthO > 0 && HealthP > 0; i++)
        {
            printf("\nCurrent Health - Opponent: %d, You: %d\n", HealthO, HealthP);

            if (turn == 0)
            {
                do
                {
                    printf("Do you want to use an item? Y(1)/N(2): ");
                    scanf("%d", &useitemchoice);
                    if (useitemchoice == 1)
                    {
                        if (itemIndex < It)
                        {
                            switch (I[itemIndex])
                            {
                            case 1:
                                usemagnifyingglassP(B, i);
                                break;
                            case 2:
                                usedeshiP(B, &i, BN);
                                break;
                            case 3:
                                usepatanjalikadhaP(&HealthP);
                                break;
                            case 4:
                                usegamblingpillsP(&HealthP);
                                break;
                            case 5:
                                useconverterP(B, i);
                                break;
                            case 6:
                                usemakeitdoublebarrelP(B, i, &turn, &HealthO);
                                break;
                            default:
                                printf("Invalid item\n");
                                break;
                            }
                            itemIndex++;
                        }
                        else
                        {
                            printf("No items left lol.\n");
                        }
                    }
                } while (BN > 8);
                if (turn == 0)
                {
                    printf("Enter your choice: 1 (hit the opponent), 2 (hit yourself): ");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        if (B[i] == 1)
                        {
                            HealthO = HealthO - 1;
                            printf("Opponent's health: %d\n", HealthO);
                        }
                        else
                        {
                            printf("Opponent's health: %d\n", HealthO);
                        }
                        break;

                    case 2:
                        if (B[i] == 1)
                        {
                            printf("lol It's a bullet, you got hit,hahahaha........\n");
                            HealthP = HealthP - 1;
                            printf("Your health: %d\n", HealthP);
                        }
                        else
                        {
                            printf("Oh, you lucky bastard! Your health doesn't decrease.\n");
                            continue;
                        }
                        break;

                    default:
                        printf("Wrong choice.\n");
                        break;
                    }
                    turn = 1 - turn;
                }
            }
            else
            {
                do
                {
                    useitemchoice = rand() % 2 + 1;
                    if (useitemchoice == 1)
                    {
                        printf("The opponent used an item.\n");
                        if (itemIndex < It)
                        {
                            switch (I[itemIndex])
                            {
                            case 1:
                                usemagnifyingglassO(B, i, &turn, &HealthP);
                                break;
                            case 2:
                                usedeshiO(B, &i, BN, &turn);
                                break;
                            case 3:
                                usepatanjalikadhaO(&HealthO, &turn);
                                break;
                            case 4:
                                usegamblingpillsO(&HealthO, &turn);
                                break;
                            case 5:
                                useconverterO(B, i, &turn);
                                break;
                            case 6:
                                usemakeitdoublebarrelO(B, i, &turn, &HealthP);
                                break;
                            default:
                                printf("Invalid item\n");
                                break;
                            }
                            itemIndex++;
                        }
                        else
                        {
                            printf("No items left you dumb Opponent.\n");
                        }
                    }
                    else
                    {
                        printf("The opponent is smart, so he's not using an item.\n");
                    }
                } while (BN > 8);
                if (turn == 1)
                {
                    choice = rand() % 2 + 1;
                    if (choice == 1)
                    {
                        printf("The opponent chose to hit you.\n");
                    }
                    else
                    {
                        printf("The opponent chose to hit himself.\n");
                    }
                    switch (choice)
                    {
                    case 1:
                        if (B[i] == 1)
                        {
                            HealthP = HealthP - 1;
                            printf("Your health: %d\n", HealthP);
                        }
                        else
                        {
                            printf("Your health: %d\n", HealthP);
                        }
                        break;

                    case 2:
                        if (B[i] == 1)
                        {
                            printf("The opponent doesn't realize he's not AI and he doesn't have any brain, so he shot himself.\n");
                            HealthO = HealthO - 1;
                            printf("Opponent's health: %d\n", HealthO);
                        }
                        else
                        {
                            printf("The opponent is lucky that it was not a bullet.\n");
                            continue;
                        }
                        break;

                    default:
                        printf("Wrong choice.\n");
                        break;
                    }
                    turn = 1 - turn;
                }
            }
        }
        if (HealthO == 0)
        {
            printf("You win!\n");
        }
        else if (HealthP == 0)
        {
            printf("The opponent wins!\n");
        }
        else
        {
            printf("No one wins.\n");
        }
        printf("Do you want to play again? (1 for yes, 2 for no): ");
        scanf("%d", &playagain);
    } while (playagain == 1);

    return 0;
}