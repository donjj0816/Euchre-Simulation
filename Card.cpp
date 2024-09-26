// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <string>
#include "Card.h"
// add any necessary #include or using directives here

// rank and suit names -- do not remove these
constexpr const char* const Card::RANK_TWO;
constexpr const char* const Card::RANK_THREE;
constexpr const char* const Card::RANK_FOUR;
constexpr const char* const Card::RANK_FIVE;
constexpr const char* const Card::RANK_SIX;
constexpr const char* const Card::RANK_SEVEN;
constexpr const char* const Card::RANK_EIGHT;
constexpr const char* const Card::RANK_NINE;
constexpr const char* const Card::RANK_TEN;
constexpr const char* const Card::RANK_JACK;
constexpr const char* const Card::RANK_QUEEN;
constexpr const char* const Card::RANK_KING;
constexpr const char* const Card::RANK_ACE;

constexpr const char* const Card::SUIT_SPADES;
constexpr const char* const Card::SUIT_HEARTS;
constexpr const char* const Card::SUIT_CLUBS;
constexpr const char* const Card::SUIT_DIAMONDS;

//Set Card to Two of Spades
Card::Card(): rank(RANK_TWO),
    suit(SUIT_SPADES){}

//Initialize Card to Specified Rank/Suit
Card::Card(const std::string &rank_in, const std::string &suit_in){
    suit = suit_in;
    rank = rank_in;
}

//Return Rank
std::string Card::get_rank() const {
    return rank;
}

//Return suit
std::string Card::get_suit() const {
    return suit;
}

//Return suit based on trump
std::string Card::get_suit(const std::string &trump) const{
    if (is_left_bower(trump)){
        return trump;
    } else {
        return suit;
    }
}

//Return true for Face card
bool Card::is_face() const {
    if (rank == RANK_JACK) {
        return true;
    } else if (rank == RANK_QUEEN) {
        return true;
    } else if (rank == RANK_KING) {
        return true;
    } else if (rank == RANK_ACE) {
        return true;
    } else {
        return false;
    }
}

//Return true if Jack of trump Suit
bool Card::is_right_bower(const std::string &trump) const {
    if (rank == RANK_JACK && suit == trump) {
        return true;
    } else {
    return false;
    }
}

//Return true if Jack of next Suit
bool Card::is_left_bower(const std::string &trump) const {
    if (rank == RANK_JACK && suit == Suit_next(trump)) {
        return true;
    } else {
        return false;
    }
}

//Return true if card is trump
bool Card::is_trump(const std::string &trump) const {
    if (suit == trump) {
        return true;
    } else if (is_left_bower(trump)) {
        return true;
    } else {
        return false;
    }
}


//rank
int rank_list(const Card &newcard) {
    std::string holder = RANK_NAMES_BY_WEIGHT[0];
    int number = 0;
    for(int j = 0; j < NUM_RANKS; j++) {
        holder = RANK_NAMES_BY_WEIGHT[j];
        if (RANK_NAMES_BY_WEIGHT[j] == newcard.get_rank()){
            number = j;
        }
    }
    return number;
}

//suit
int suit_list(const Card &newcard) {
    std::string holder = SUIT_NAMES_BY_WEIGHT[0];
    int number = 0;
    for(int j = 0; j < NUM_SUITS; j++) {
        holder = SUIT_NAMES_BY_WEIGHT[j];
        if (SUIT_NAMES_BY_WEIGHT[j] == newcard.get_rank()){
            number = j;
        }
    }
    return number;
}

//true if lhs lower than rhs or equal
bool operator<(const Card &lhs, const Card &rhs) {
    int left_rank = rank_list(lhs);
    
    int left_suit = suit_list(lhs);
    int right_rank = rank_list(rhs);
    int right_suit = suit_list(rhs);

    if (left_rank < right_rank) {
        return true;
    } else if (left_rank == right_rank && left_suit < right_suit) {
        return true;
    }
    return false;
}

//true if lhs lower than rhs or equal
bool operator<=(const Card &lhs, const Card &rhs) {
    int left_rank = rank_list(lhs);
    
    int left_suit = suit_list(lhs);
    int right_rank = rank_list(rhs);
    int right_suit = suit_list(rhs);

    if (left_rank < right_rank || left_rank == right_rank) {
        return true;
    } else if (left_rank == right_rank && left_suit < right_suit) {
        return true;
    }
    return false;
}


//true if lhs larger than rhs or equal
bool operator>(const Card &lhs, const Card &rhs) {
    int left_rank = rank_list(lhs);
    
    int left_suit = suit_list(lhs);
    int right_rank = rank_list(rhs);
    int right_suit = suit_list(rhs);

    if (left_rank > right_rank) {
        return true;
    } else if (left_rank == right_rank && left_suit > right_suit) {
        return true;
    }
    return false;
}

//true if lhs lower than rhs or equal
bool operator>=(const Card &lhs, const Card &rhs) {
    int left_rank = rank_list(lhs);
    
    int left_suit = suit_list(lhs);
    int right_rank = rank_list(rhs);
    int right_suit = suit_list(rhs);

    if (left_rank > right_rank || left_rank == right_rank) {
        return true;
    } else if (left_rank == right_rank && left_suit > right_suit) {
        return true;
    }
    return false;
}


//return true if same card
bool operator==(const Card &lhs, const Card &rhs) {
    if (rhs.get_rank() == lhs.get_rank()) {
        if (rhs.get_suit() == lhs.get_suit()) {
            return true;
        }
    }
    return false;
}

//return if not same card
bool operator!=(const Card &lhs, const Card &rhs) {
    if (rhs.get_rank() == lhs.get_rank()) {
        if (rhs.get_suit() == lhs.get_suit()) {
            return false;
        }
    }
    return true;
}


//Return next suit

std::string Suit_next(const std::string &suit) {
    if (suit == Card::SUIT_SPADES) {
        return Card::SUIT_CLUBS;
    } else if (suit == Card::SUIT_CLUBS) {
        return Card::SUIT_SPADES;
    } else if (suit == Card::SUIT_HEARTS) {
        return Card::SUIT_DIAMONDS;
    } else {
        return Card::SUIT_HEARTS;
    }
}

//Print card
std::ostream & operator<<(std::ostream &os, const Card &card) {
    os << card.get_rank() << " of " << card.get_suit();
    return os;
}

bool Card_less(const Card &a, const Card &b, const std::string &trump) {
    if (a.is_trump(trump)) {
        if (!b.is_trump(trump)) {
            return false;
        }
    } else if (!a.is_trump(trump)) {
        if (b.is_trump(trump)) {
            return true;
        }
    }
    return a<b;
}

bool Card_less(const Card &a, const Card &b, const Card &led_card,
               const std::string &trump) {
    if (a.is_trump(trump)) {
        if (!b.is_trump(trump)) {
            if (a.is_left_bower(trump)) {
                if (b.is_right_bower(trump)) {
                    return true;
                }else {
                    return false;
                }
            } else if (a.is_right_bower(trump)) {
                return false;
            } else if (b.is_right_bower(trump) | b.is_left_bower(trump)) {
                return true;
            } else {
                return a < b;
            }
        } else {
            return false;
        }
    } else {
        if (!b.is_trump(trump)) {
            return a<b;
        } else {
            return true;
        }
    }
}

// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec (see the appendices) before implementing
// the following operator overload functions:
//   operator<<
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=
