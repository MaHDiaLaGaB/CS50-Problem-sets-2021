import sys
import csv

# counting the dna sequences pairs
def count_dna_sequences(seq_name, dna_sample):
    count = 0
    while seq_name * (count + 1) in dna_sample:
        count += 1
    return count

# create dict full by the dna counts
def matching_dna(seq_name, dna_sample):
    match_dict = {}
    for x in seq_name:
        match_dict[x] = count_dna_sequences(x, dna_sample)
    return match_dict
    

def main():
    # check if the entry is vaild
    if len(sys.argv) != 3:
        sys.exit("Usage: python FILE is missing")
    
    # empty list and open the csv file and load it inside the list
    data_arr = []
    with open(sys.argv[1], 'r') as infile:
        reader = csv.DictReader(infile)
        for row in reader:
            data_arr.append(row)
        # take the name of the sequences from csv file
        seq_name = reader.fieldnames[1:]
    # open the txt file the john doe DNA
    with open(sys.argv[2], 'r') as sample_file:
        reader = sample_file.readline()
        dna_sample = reader
        
    # change the type of the values from string to int
    for dict in data_arr:
        for key in dict:
            if key in matching_dna(seq_name, dna_sample):
                dict[key] = int(dict[key])
    # create empty dict and fill it with the matching sequences 
    common_keys = {}
    for dict in data_arr:
        for key in dict:
            if key in matching_dna(seq_name, dna_sample):
                if dict[key] == matching_dna(seq_name, dna_sample)[key]:
                    common_keys["name"] = dict["name"]
                    common_keys[key] = dict[key]
        # test if the person is john doe or not
        if common_keys == dict:
            print(dict["name"])
            quit()
    print("No match")


if __name__ == "__main__":
    main()
