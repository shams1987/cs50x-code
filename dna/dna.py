import csv
from sys import argv


def main():

    # TODO: Check for command-line
    if len(argv) != 3:
        print("python dna.py data.csv sequence.txt")
        exit()

    # TODO: Read database file into a variable
    with open(argv[1], "r") as csvfile:
        reader = csv.reader(csvfile)
        db_file = list(reader)

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    matches = []
    length = len(db_file[0])
    for i in range(1, length):
        matches.append(longest_match(sequence, db_file[0][i]))

    # TODO: Check database for matching profiles

    # initialize cvariables
    potential_match = "No match"
    count = 0
    l = len(db_file)
    m = len(matches)

    # for each databse, iterate through matches
    for i in range(1, l):
        for j in range(m):
            if matches[j] == int(db_file[i][j+1]):
                count += 1
        # check count equlas number of items in matches
        if count == len(matches):
            potential_match = db_file[i][0]
            break
        else:
            count = 0
    print(potential_match)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
