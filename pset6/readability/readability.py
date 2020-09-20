from cs50 import get_string

def main():
    # Get User Input
    text = get_string("Text: ")

    # Words, Letters, Sentences, oh my!
    W = count_words(text)
    L = (count_letters(text) / W) * 100
    S = (count_sentences(text) / W) * 100
    index = (0.0588 * L) - (0.296 * S) - 15.8

    # Print Grade Level below 1
    if index < 1:
        print("Before Grade 1\n")
    # Print Grade Level if 16 or higher
    elif index >= 16:
        print("Grade 16+\n")
    # Print Grade level
    else:
        print("Grade " + str(round(index)))


#  Number of Letters
def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
    return letters

#  Number of Words
def count_words(text):
    words = 1
    for i in range(len(text)):
        if text[i].isspace():
            words += 1
    return words

#  Number of Sentences
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] == '!' or text[i] == '?' or text[i] == '.':
            sentences += 1
    return sentences

main()