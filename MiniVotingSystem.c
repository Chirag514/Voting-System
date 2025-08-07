#include <stdio.h>
#define max 20
typedef struct
{
    int vote;
    char candname[max];
    int symbolno;
    char candsymbol[max];
} candidate;
candidate candinfo[max], voting[max];
char symbol[max] = {'*', '/', '.', '!', '@', '#', '$', '%', '^', '&', '(', ')', '{', '}', '[', ']', '~', '=', '+', '?'};
int symbolchosen[max];
int main();
int candidate_details()
{
    int i, j, k, num, candidate = 0;
    printf("The nomination process starts\n");
    for (i = 0; i < max; i++)
    {
        printf("Dear candidate %d write your name for nomination:\n", i + 1);
        scanf("%s", candinfo[i].candname);
        candidate++;
        printf("These are the election symbols:\n");
        for (j = 0; j < max; j++)
        {
            printf("%d %c\n", j + 1, symbol[j]);
        }
    label:
    {
        printf("Dear Candidate %d choose your election symbol:", i + 1);
        scanf("%d", &num);
    }
        if (symbolchosen[num - 1] == 1)
        {
            printf("This symbol is already choosed by other candidate\n");
            goto label;
        }
        symbolchosen[num - 1] = 1;
        candinfo[i].candsymbol[0] = symbol[num - 1];
        candinfo[i].candsymbol[1] = '\0';
        int nom;
        printf("Enter 0 if there is no more candidates for nomination\nOr Enter any other number if there is more candidates for nomination:");
        scanf("%d", &nom);
        if (nom == 0)
        {
            printf("There are %d candidates registered\n\n", candidate);
            break;
        }
    }
    return candidate;
}

int vote(int voters, int cand)
{
    int i, j, choice, c, NOTA = 0;
    for (i = 0; i < voters; i++)
    {
        printf("Voter [%d] Enter 1 to see candidate's name and their election symbol\nEnter 2 to vote\n", i + 1);
    label:
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("See the list of candidate and their election symbols:\n");
            for (j = 0; j < cand; j++)
            {
                printf("%d %s %s\n", j + 1, candinfo[j].candname, candinfo[j].candsymbol);
            }
            printf("Now you have to vote\n");
            goto label__;
        }
        else if (choice == 2)
        {
        label__:
        {
            printf("Voter[%d] give your vote:\nIf you want to give vote to NOTA(None of the above) enter 0:\n", i + 1);
        label_:
        {
            scanf("%d", &c);
        }
            if (c > cand)
            {
                printf("There are %d candidates,vote again\n", cand);
                goto label_;
            }
            else if (c == 0)
            {
                NOTA++;
            }
            voting[c - 1].vote++;
            for (j = 0; j < cand; j++)
            {
                printf("No. of votes for %d is %d\n", j + 1, voting[j].vote);
            }
            printf("No. of votes for NOTA is %d\n", NOTA);
        }
        }
        else
        {
            printf("Incorrect choice,again choose between 1 or 2\n");
            goto label;
        }
    }
    }
    return NOTA;
}
void result(int voters, int NOTA)
{
    int j = 0, k = 0, m, l[voters], equalvote = 0;
    int max_votes = voting[0].vote;
    for (int i = 0; i < voters; i++)
    {
        if (voting[i].vote > max_votes || i == 0)
        {
            max_votes = voting[i].vote;
            j = i + 1;
        }
        else if (voting[i].vote == max_votes && i != 0)
        {
            k = i + 1;
        }
    }
    if (voting[j - 1].vote > NOTA && j > k)
        printf("\n\nWinner of election is Candidate %d whose name is %s with %d votes.\n\n", j, candinfo[j - 1].candname, max_votes);
    else if (voting[j - 1].vote < NOTA)
    {
        printf("\n\nMajortiy of the voters have vote for NOTA that's why nobody wins.\n\n");
    }
    else if (voting[j - 1].vote = NOTA)
    {
        printf("\n\nThe number of votes for NOTA is equal to number of votes for candidate with majority that's why nobody wins.\n\n");
    }
    else if (j < k)
    {
        printf("\n\nThere is no majority for any one candidate that's why no candidate wins.\n\n");
    }
}
int main()
{
    printf("This program will do:\n1.Nomination for candidates\n2.Voting\n3.Result declaration\n\n");
    int cand, voters, NOTA;
    cand = candidate_details();
    printf("Enter the number of voters:");
    scanf("%d", &voters);
    NOTA = vote(voters, cand);
    result(voters, NOTA);
    printf("*********The election is done*********\n");
    printf("*********Thanks to all voters for giving their valuable votes*********\n\n");
    printf("*********Thanks for using my program as a mini voting system*********");

    return 0;

}
