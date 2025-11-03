import random

#establishing functions for each roll of different sided dice
def roll_six_dice():
    return random.randint(1, 6)

def roll_eight_dice():
    return random.randint(1, 8)

def roll_ten_dice():
    return random.randint(1, 10)

def roll_twelve_dice():
    return random.randint(1, 12)