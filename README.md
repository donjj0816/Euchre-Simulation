# Euchre-Simulation
Euchre is a card game popular in Michigan.  The learning goals of this project include Abstract Data Types in C++, Derived Classes, Inheritance, and Polymorphism. C++-style Object Oriented Programming (OOP) with classes and virtual functions.  I finally have a program that simulates a game of Euchre, supporting a AI player and a Human player.


Players
There are four players numbered 0-3. If the players sat around the table, it would look like this:



There are two teams: players 0 and 2 are partners, as are 1 and 3. Each player has left and right neighbors. For example, 1 is to the left of 0, and 3 is to the right of 0. That means 1 is 0’s left neighbor, and 3 is 0’s right neighbor.

The Cards
Euchre uses a deck of 24 playing cards, each of which has two properties: a rank and a suit. The ranks are 9, 10, Jack, Queen, King, and Ace, and the suits are Spades, Hearts, Clubs, and Diamonds. Each card is unique — there are no duplicates. Throughout this document, we sometimes refer to ranks or suits using only the first letter of their name. Farther below, we describe how to determine the ordering of the cards.

Playing the Game
At a high level, a game of Euchre involves several rounds, which are called hands. Each hand consists of the following phases.

Each hand:

Setup table
Shuffle
Deal
Making Trump
Round One
Round Two
Trick Taking
Scoring
We describe each in more detail below.

Setup table
Shuffle
The dealer shuffles the deck at the beginning of each hand. The algorithm you will implement for shuffling is a variant of a riffle shuffle called an “in shuffle” (https://en.wikipedia.org/wiki/In_shuffle). Cut the deck exactly in half and then interleave the two halves, starting with the second half. Thus, the card originally at position 12 goes to position 0, the one originally at position 0 goes to position 1, the one originally at position 13 goes to position 2, and so on. Do this in-shuffle process 7 times.

You will also implement an option to run the game with shuffling disabled - when this option is chosen, just reset the pack any time shuffling would be called for. This may make for easier testing and debugging.

Deal
In each hand, one player is designated as the dealer (if humans were playing the game, the one who passes out the cards). In our game, player 0 deals during the first hand. Each subsequent hand, the role of dealer moves one player to the left.

Each player receives five cards, dealt in alternating batches of 3 and 2. That is, deal 3-2-3-2 cards then 2-3-2-3 cards, for a total of 5 cards each. The player to the left of the dealer receives the first batch, and dealing continues to the left until 8 batches have been dealt.

Four cards remain in the deck after the deal. The next card in the pack is called the upcard (it is turned face up, while the other cards are all face down). It plays a special role in the next phase. The three remaining cards are not used for the current hand.

Making Trump
During this phase, the trump suit is determined by whichever player chooses to order up.

Round One
The suit of the upcard is used to propose a trump suit whose cards become more valuable during the upcoming hand. Players are given the opportunity to order up (i.e. select the suit of the upcard to be the trump suit) or pass, starting with the player to the dealer’s left (also known as the eldest hand) and progressing once around the circle to the left. If any player orders up, the upcard’s suit becomes trump and the dealer is given the option to replace one of their cards with the upcard.

Round Two
If all players pass during the first round, there is a second round of making, again beginning with the eldest hand. The upcard’s suit is rejected and cannot be ordered up. Instead, the players may order up any suit other than the upcard’s suit. The dealer does not have the opportunity to pick up the upcard during round two.

If making reaches the dealer during the second round, a variant called screw the dealer is invoked: the dealer must order up a suit other than the rejected suit.

(Note for pro Euchre players: for simplicity, we have omitted “going alone” in this version.)

Trick Taking
Once the trump has been determined, five tricks are played. For each trick, players take turns laying down cards, and whoever played the highest card takes the trick.

During each trick, the player who plays first is called the leader. For the first trick, the eldest hand leads.

At the beginning of each trick, the leader leads a card, which affects which cards other players are allowed to play, as well as the value of each card played (see below). Each other player must follow suit (play a card with the same suit as the led card) if they are able, and otherwise may play any card (it is removed from their hand). Play moves to the left around the table, with each player playing one card.

A trick is won by the player who played the highest valued card (see below to determine comparative values). The winner of the trick leads the next one.

Scoring
The team that takes the majority of tricks receives points for that hand.

If the team that ordered up the trump suit takes 3 or 4 tricks, they get 1 point.
If the team that ordered up the trump suit takes all 5 tricks, they get 2 points. This is called a march.
If the team that did not order up takes 3, 4, or 5 tricks, they receive 2 points. This is called euchred.
Traditionally, the first side to reach 10 points wins the game. In this project, the number of points needed to win is specified when the program is run.

Value of cards
In order to determine which of two cards is better, you must pay attention to the context in which they are being compared. There are three separate contexts, which depend on whether or not a trump or led suit is present.

In the simplest case, cards are ordered by rank (A > K > Q > J > 10 > 9), with ties broken by suit (D > C > H > S).

If a trump suit is present, all trump cards are more valuable than non-trump cards. That means a 9 of the trump suit will beat an Ace of a non-trump suit. Additionally, two special cards called bowers take on different values than normal.

Right Bower: The Jack of the trump suit. This is the most valuable card in the game.
Left Bower: The Jack of the “same color” suit as trump is considered to be a trump (regardless of the suit printed on the card) and is the second most valuable card.
The suit of the left bower is called next, while the two suits of the opposite color are called cross suits.

If a led suit is present as well as a trump suit, the ordering is the same except that all cards of the led suit are considered more valuable than all non-trump-suit, non-led-suit cards. Note that it is possible for the trump suit and led suit to be the same.
