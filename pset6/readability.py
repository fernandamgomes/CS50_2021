texto = str(input("Text: "))
letras = frases = 0
palavras = 1

for char in (texto):
    if char.isalpha():
        letras = letras + 1
    elif char.isspace():
        palavras = palavras + 1
    elif char in [".", "!", "?"]:
        frases = frases + 1

if texto[0] == " ":
    palavras = palavras - 1
#  Coleman-Liau index
L = 100 * letras / float(palavras)
# L is the average number of letters per 100 words
S = 100 * frases / float(palavras)
# S is the average number of sentences per 100 words in the text
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print reading level
if index > 16:
    print("Grade 16+")
elif (index < 1):
    print("Before Grade 1")
else:
    print("Grade", + index)
    
