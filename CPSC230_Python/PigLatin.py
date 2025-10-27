def wordToPig(word):
    y = word[0]
    vowels = ['a','e','i','o','u']
    if y.lower() in vowels:
        word = word + 'yay'
    else:
        word = word.strip(word[0])
        word = word + y + 'ay'
    return(word)

print(wordToPig(str(input('Give me a word'))))
    
