# TODO

from cs50 import get_string
import string

text = get_string("Text: ")
#  initialize variables
words, letters, sentences = 1, 0, 0

# loop thrpugh the text to count words, letters and sentences
for char in text:
    if char == " ":
        words += 1
    elif char in string.ascii_letters:
        letters += 1
    elif char in [".", "!", "?"]:
        sentences += 1

# calculate grade
L = (letters / words) * 100
S = (sentences / words) * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)

# edege cases
if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(grade))