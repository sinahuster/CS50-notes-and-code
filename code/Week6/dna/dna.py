import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing comand line arguement. Expected ./dna cvs-file tex-file")
        sys.exit(1)

    data = []
    # Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        csv_reader = csv.DictReader(file)
        for row in csv_reader:
            data.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        dna = file.readline().strip()

    # Find longest match of each STR in DNA sequence
    sequence = csv_reader.fieldnames
    longest = []
    for i in range(1, len(sequence)):
        match = longest_match(dna, sequence[i])
        longest.append(match)

    # Check database for matching profiles
    for row in data:
        match = True
        for i in range(len(longest)):
            if int(row[sequence[i+1]]) != longest[i]:
                match = False
                break
        if match:
            print(row['name'])
            sys.exit(0)
    print("No match")

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
