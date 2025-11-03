from dice import roll_six_dice, roll_eight_dice, roll_ten_dice, roll_twelve_dice
from card import establish_deck_jokers, establish_deck_without_jokers, pick_cards
from coin import flip_coin

#Main menu option
MENU = """
Welcome to the gaming center!

Choose an option:
1. Flip a coin
2. Roll a dice
3. Draw a card
4. Exit

Selection: """

#normalizing answers to prompt
def normalize(text):
    return text.lower().strip()

#prompt dice choice roll
def prompt_die_choice():
    die_choice_prompt = input("""
Choose a dice option: 
1. 6-sided
2. 8-sided
3. 10-sided
4. 12-sided
5. Back to menu
    
Selection: """)

    return die_choice_prompt

#option to select whether jokers are in the deck
def prompt_joker_choice():
    joker_prompt = normalize(input("Would you like to remove the jokers from the deck? (y/n): "))
    return joker_prompt

while (user_input := input(MENU)) != "4":

#flipping a coin
    if user_input == "1":
        result = flip_coin()
        print(f"Result: {result}")

#rolling a die based on choice
    elif user_input == "2":
        dice_choice = prompt_die_choice()
        if dice_choice == "1":
            result = roll_six_dice()
            print(f"Result: {result}")
        elif dice_choice == "2":
            result = roll_eight_dice()
            print(f"Result: {result}")
        elif dice_choice == "3":
            result = roll_ten_dice()
            print(f"Result: {result}")
        elif dice_choice == "4":
            result = roll_twelve_dice()
            print(f"Result: {result}")
        elif dice_choice == "5":
            continue

#Picking a card from the deck
    elif user_input == "3":
        joker_choice = prompt_joker_choice()
        #establishing card decks and picking a card
        if joker_choice == "y":
            cards = establish_deck_without_jokers()
            result = pick_cards(cards)
            print(f"Result: {result}")
        elif joker_choice == "n":
            cards = establish_deck_jokers()
            result = pick_cards(cards)
            print(f"Result: {result}")

    else:
        print("Invalid input. Please try again.")



