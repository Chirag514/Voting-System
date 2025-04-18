# Mini Voting System in C

This is a simple command-line based **Voting System** written in C. It allows candidates to nominate themselves with a unique symbol and allows voters to vote for their preferred candidate or NOTA (None Of The Above). Finally, it declares the result based on the votes.

## Features

- Candidate nomination with unique symbol selection
- Voter interaction: view candidates and cast vote
- NOTA (None Of The Above) support
- Vote counting and result declaration
- Handles ties, NOTA majority, and multiple candidates with same votes

## How It Works

1. **Nomination Phase**:
   - Each candidate provides their name.
   - They choose a unique election symbol from a list.
   - Process continues until user opts to stop nominations.

2. **Voting Phase**:
   - Voters can view the list of candidates and their symbols.
   - Each voter casts one vote.
   - Voting for NOTA is also available.

3. **Result Phase**:
   - Counts all votes including NOTA.
   - Declares the winner if one exists, or notes the reason for no winner (tie, NOTA majority, etc.).

## How to Compile

Use a C compiler like `gcc`:

```bash
gcc -o voting_system ea38f273-9b9a-47ee-adf7-5b9dc85d24cc.c
