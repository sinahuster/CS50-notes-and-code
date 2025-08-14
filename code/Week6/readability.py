# define the main function
def main():
    # allow user to input the text
    text = str(input("Text: "))

    # call reading_level to calulate the reading level
    grade = reading_level(text)

    # determine which output to print
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 1 and grade < 16:
        print(f"Grade {grade}")
    else:
        print("Grade 16+")


# define reading_level which calculates the reading level of the text
def reading_level(text):
    sentences = 0
    letters = 0

    # count letters and sentences
    for char in text:
        if char.isalpha():
            letters += 1
        if char in ['.', '!', '?']:
            sentences += 1

    # count words
    words = len(text.split())

    # calculate the grade level using the algorithm 
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    return index


main()
