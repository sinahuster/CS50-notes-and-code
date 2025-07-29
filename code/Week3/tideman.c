#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool is_connected(int w, int l);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Iterate over all candiadates, if name is the same as a candidate name, store
    // the candidates index in the ranks array and returns true, otherwise return false.
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Iterate over the number of candidates, and within that again but making sure j is always
    // larger than i. We then increment the preferences array for the indexes stored in ranks[]
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;

    // iterate over the number of candidates and within it iterate over the candidates again,
    // incremented by one
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // If the number of votes for eachis equal, we ignore and continue
            if (preferences[i][j] == preferences[j][i])
            {
                continue;
            }
            // If i is prefered over j, we add the pair i,j to pairs and increment the pair_count
            else if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            //// If j is prefered over i, we add the pair j,i to pairs and increment the pair_count
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Iterate over the number of pairs and within it iterate over the pairs, but one less time each
    // iteration, as we use bubble sort
    for (int j = 0; j < pair_count; j++)
    {
        for (int i = 0; i < pair_count - 1 - j; i++)
        {
            // If i,j have less of a difference to i+1,j+1, we swap then so the highest votes are at
            // the top
            if (preferences[pairs[i].winner][pairs[i].loser] <
                preferences[pairs[i + 1].winner][pairs[i + 1].loser])
            {
                pair temporary = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temporary;
            }
        }
    }
    return;
}

// This helper function will be used recursively in lock_pairs, to determine if there is a cycle
bool is_connected(int w, int l)
{
    // base case
    if (locked[l][w])
    {
        return true;
    }

    // Iterates over all possible connections and uses recursion to determine if i is connected to
    // w.
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[l][i])
        {
            if (is_connected(w, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Iterate through the pairs, check if a cycle will be made,
    // if not, lock the pairs, if it does, don't lock
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (is_connected(winner, loser))
        {
            continue;
        }
        else
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Define a boolean variable which will keep track of whether the the candidate
    // has any other candidates winning over them.
    bool source;

    // Iterate over the candidates, and if they are the second index of any true locked
    // boolean value then they are not the source.
    // If they are not then source remains true and they are the winner.
    for (int i = 0; i < candidate_count; i++)
    {
        source = true;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                source = false;
            }
        }
        if (source)
        {
            printf("%s\n", candidates[i]);
        }
    }

    return;
}
