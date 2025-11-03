import random

#Standard card suit variables
card_suit = ["Hearts", "Diamonds", "Clubs", "Spades"]

#establishing decks with jokers
def establish_deck_jokers():
    card_deck = []
    #Looping through suit and ranks to create card deck
    for suit in card_suit:
        for rank in range(1, 14):
            if rank == 1:
                card_deck.append(suit + " - Ace")
            elif rank == 11:
                card_deck.append(suit + " - Jacks")
            elif rank == 12:
                card_deck.append(suit + " - Queens")
            elif rank == 13:
                card_deck.append(suit + " - King")

#Adding both jokers to card deck
    card_deck.append("Big Joker")
    card_deck.append("Little Joker")

    return card_deck

#establishing card deck without jokers
def establish_deck_without_jokers():
    card_deck = []
    for suit in card_suit:
        for rank in range(1, 14):
            if rank == 1:
                card_deck.append(suit + " - Ace")
            elif rank == 11:
                card_deck.append(suit + " - Jacks")
            elif rank == 12:
                card_deck.append(suit + " - Queens")
            elif rank == 13:
                card_deck.append(suit + " - King")

    return card_deck

#simulating picking cards through random choice
def pick_cards(cards):
    return random.choice(cards)

