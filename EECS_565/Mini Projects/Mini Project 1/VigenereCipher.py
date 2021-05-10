"""
Author: Joseph Pennington

Vigenere Cipher & Brute Force Password Cracker
EECS 565 Mini Project 1

Required files: dict.txt
Enter valid Vigenere ciphertext, key length, and length of first word
The program will evaluate every possible key against the ciphertext
If the first word is in dict.txt, the program will decrypt the whole ciphertext
"""

#Imports for timing & generating all possible keys
import time
from itertools import product

#Cleans input (All uppercase, removes spaces)
def cleanInput(inputText):
    inputText = inputText.upper()
    inputText = inputText.replace(" ","")
    return(inputText)

#Vigenere encrypt
def encrypt(plainText, key, keyLength, firstWordLength):
    encryptText = []
    tempASCII = 0
    tempChar = ''
    position = 0
    cipherTextLength = len(plainText)

    for i in range(0, cipherTextLength):
        if(position >= keyLength):
            position = 0
        tempASCII = (ord('A') + (((ord(plainText[i]) + ord(key[position])) + 26) % 26))
        tempChar = chr(tempASCII)
        encryptText.append(tempChar)
        position += 1

    outString = ""
    return(outString.join(encryptText))

#Vigenere decrypt
#Decrypts first word & checks if in dictionary
#If in dictionary, decrypt entire string
#Save final string & key to tuple
def decrypt(cipherText, key, keyLength, firstWordLength):
    plainText = []
    tempASCII = 0
    tempChar = ''
    position = 0
    cipherTextLength = len(cipherText)
    foundTuple = ()


    for i in range(0, firstWordLength):
        if(position >= keyLength):
            position = 0
        tempASCII = (ord('A') + (((ord(cipherText[i]) - ord(key[position])) + 26) % 26))
        tempChar = chr(tempASCII)
        plainText.append(tempChar)
        position += 1

    outString = ''.join(plainText)
    
    if(dictionaryCompare(outString[0:firstWordLength])):
        plainText = []
        tempASCII = 0
        tempChar = ''
        position = 0
        
        for i in range(0, cipherTextLength):
            if(position >= keyLength):
                position = 0
            tempASCII = (ord('A') + (((ord(cipherText[i]) - ord(key[position])) + 26) % 26))
            tempChar = chr(tempASCII)
            plainText.append(tempChar)
            position += 1

        outString = ''.join(plainText)
        
        foundTuple = (outString, key)
        m_passwords.append(foundTuple)
        print(m_passwords)
    

#Checks if first word is in dict.txt
def dictionaryCompare(compareString):
    if compareString in m_dictionary:
        return(True)
    else:
        return(False)

#Saves words of firstWordLength from dict.txt
def saveDictionary(firstWordLength):
    tempDict = []
    with open('dict.txt', 'r') as infile:
        for word in infile:
            word = word.strip()
            if len(word) == firstWordLength:
                tempDict.append(word)
    return(tempDict)

#Generates a list of the English Alphabet
def saveAlphabet():
    temp = []
    alpha = 'A'
    for i in range(0,26):
        temp.append(alpha)
        alpha = chr(ord(alpha)+1)
    return(temp)

#Generates all possible keys of keyLength
def possibleKeys(alphabet, keyLength):
    #tempKeyList = [''.join(key) for key in product(alphabet, repeat=keyLength)]
    count = 0
    
    for key in product(alphabet, repeat = keyLength):
        count +=1
        key = ''.join(key)
        if count % 1000000 == 0:
            print(count)
            print(key)
        decrypt(m_cipherText, key, m_keyLength, m_firstWordLength)
        

#Begins decryption process of all possible keys
#Times process
#Prints all valid passwords & keys
def bruteForceCrack(cipherText, keyLength, firstWordLength):

    print('\n')
    print("Starting Timer")
    start = time.time()
    
    possibleKeys(m_alphabet, keyLength)

    end = time.time()
    print("Ending Timer")
    print("Time Elapsed: ", end-start, " seconds")
    print('\n')

    print("All possible plain texts and keys")
    print(m_passwords)


#Cipher text to decrypt
m_cipherText = str(input("Enter ciphertext: "))
m_cipherText = cleanInput(m_cipherText)

#Length of key
m_keyLength = int(input("Enter key length: "))

#Length of first word
m_firstWordLength = int(input("Enter first word length: "))

#List of English alphabet
m_alphabet = saveAlphabet()

#List of all dictionary entries of m_firstWordLength
m_dictionary = saveDictionary(m_firstWordLength)

#List to store all valid passwords & keys
m_passwords = []

#Calls bruteForceCrack
def main():
    bruteForceCrack(m_cipherText, m_keyLength, m_firstWordLength)

    
if __name__ == "__main__":
    main()

'''
1. MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX

key length = 2; firstWordLength = 6

2. PSPDYLOAFSGFREQKKPOERNIYVSDZSUOVGXSRRIPWERDIPCFSDIQZIASEJVCGXAYBGYXFPSREKFMEXEBIYDGFKREOWGXEQSXSKXGYRRRVMEKFFIPIWJSKFDJMBGCC

keyLength=3; firstWordLength = 7

3. MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA

keyLength=4; firstWordLength = 10

4. SQLIMXEEKSXMDOSBITOTYVECRDXSCRURZYPOHRG

keyLength=5; firstWordLength = 11

5. LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS

keyLength=6; firstWordLength = 9

6. VVVLZWWPBWHZDKBTXLDCGOTGTGRWAQWZSDHEMXLBELUMO

keyLength=7; firstWordLength = 13
'''












