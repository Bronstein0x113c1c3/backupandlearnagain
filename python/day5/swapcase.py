def swapcase(str):
    newstring = ""
    for a in str:
        #'a': 'a'->'A(lowercase)': 'A(uppercase)'
        if (a.isupper())==True:
            newstring+=(a.lower())
        #'A': 'A'->'a'(lowercase): 'A(uppercase)'
        elif ((a.islower())==True):
            newstring+=(a.upper())
        #'': ' '->' '(space)
        else:
            newstring+=' '
    return newstring
print(swapcase("i am LEARNing pyThON"))

            