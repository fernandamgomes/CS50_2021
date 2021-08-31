import csv
import sys
import re


def main():

    global str_dict
    str_dict = {}

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Open database file and read people into memory from file
    dna = []
    database = sys.argv[1]
    with open(database) as csvfile:
        reader = csv.DictReader(csvfile)
        # Populate list of dicts
        for row in reader:
            dna.append(row)

    names = []
    # Create names list and delete the key 'name' from dna dicts
    # dna[i] belongs to name[i]
    for i in range(len(dna)):
        name = dna[i]['name']
        names.append(name)
        del dna[i]['name']

    # Convert dna values into integers
    for dicts in dna:
        for keys in dicts:
            dicts[keys] = int(dicts[keys])

    # Pattern = strs in database file
    pattern = []
    for key in dna[0].keys():
        pattern.append(key)

    # Open sequences file and read content into memory
    sequence = sys.argv[2]
    with open(sequence) as textfile:
        sequence = textfile.read()

    # Call str_count function - counts the number of times each str(pattern) repeats
    for i in range(len(pattern)):
        str_count(sequence, pattern[i])

    # Check for dna matches
    for i in range(len(dna)):
        if dna[i] == str_dict:
            print(names[i])
            quit()
    print("No match")


def str_count(main_str, strs):
    max_repetition = max(re.findall('((?:' + re.escape(strs) + ')*)', main_str), key=len)
    count = (len(max_repetition) // len(strs))
    str_dict.update({strs: int(count)})


main()
