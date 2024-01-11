#Rishikesh Suryavanshi
#Date: 10/01/2024

# In a file called figlet.py, implement a program that:

# Expects zero or two command-line arguments:
# Zero if the user would like to output text in a random font.
# Two if the user would like to output text in a specific font, in which case the first of the two should be -f or --font, and the second of the two should be the name of the font.
# Prompts the user for a str of text.
# Outputs that text in the desired font.
# If the user provides two command-line arguments and the first is not -f or --font or the second is not the name of a font, the program should exit via sys.exit with an error message.

from pyfiglet import Figlet
import random
import sys

def ranfonts():
    fonts = Figlet().getFonts()
    return random.choice(fonts)

def check(fon):
    fonts = Figlet().getFonts()
    for font in fonts:
        if(fon == font):
            return False
    return True



n = len(sys.argv)
if(n == 1):
    c = input("Input: ")
    font = Figlet(font = ranfonts())
    print("Output: \n", font.renderText(c))
elif(n == 3):
    if((sys.argv[1] != "-f" and sys.argv[1] != "--font") or check(sys.argv[2])):
        sys.exit("Invalid Usage")
    else:
        c = input("Input: ")
        font = Figlet(font = sys.argv[2])
        print("Output: \n", font.renderText(c))
else:
    sys.exit("Invalid Usage")