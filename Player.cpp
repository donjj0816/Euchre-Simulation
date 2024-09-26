#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Player.h"


class simp : public Player {
public:
    simp() : size(0){}
    simp(std::string player_name) : size(0) {
        name = player_name;
    }
    
    //pull name
    const std::string & get_name() const {
        return name;
    }
    
    //add a card to deck
    void add_card(const Card &c) {
        cards.push_back(c);
        size ++;
    }
    
    //See if player wants to make trump or pass
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const {
        //Requires in first or second round
        assert(round<=2);
        int place_holder = 0;
        
        //round 1 action
        if (round == 1) {
            for (int i = 0; i < size; i++) {
                if (cards[i].is_face() && cards[i].is_trump(upcard.get_suit())) {
                    place_holder++; }
            } if (place_holder >= 2) {
                    return true; }
        } else {
            //round 2 action
            place_holder = 0;
            
            if (is_dealer) {
                order_up_suit = Suit_next(upcard.get_suit());
                return true;
            }
            for (int k = 0; k < size; k++) {
                if (cards[k].is_trump(Suit_next(upcard.get_suit()))
                    && cards[k].is_face()) {
                    place_holder ++;
                } if (place_holder >= 1) {
                    order_up_suit = Suit_next(upcard.get_suit());
                return true;
                }
            }
        }
        return false;
    }
    
    void add_and_discard(const Card &upcard) {
        assert(cards.size() >= 1);
        
        Card low = cards[0];
        Card holder2 = upcard;
                
        for (int j = 0; j < size; j++) {
            if (Card_less(cards[j], low, upcard.get_suit())) {
                holder2 = cards[j];
                cards[j] = low;
                low = holder2;
            }
        }
    }
    
    Card lead_card(const std::string &trump) {
        int number = 0;
        for (int j = 0; j < size; size++) {
            if (!cards[j].is_trump(trump)) {
                number = j;
            }
        }
        int number2 = size - 1;
        if (number != 0) {
            Card new_card = Card(cards[number].get_rank(), cards[number].get_suit());
            for (int k = number; k < number2; k++) {
                cards[k] = cards[k + 1];
            }
        size = size - 1;
        return Card(cards[number].get_rank(), cards[number].get_suit());
        }
        
    Card first = Card(cards[size - 1].get_rank(), cards[size - 1].get_suit());
    size = size - 1;
        return first;
}
    
//    Card play_card(const Card &led_card, const std::string &trump) {
//        cout << "Simple player " << name;
//    }
    
private:
    std::vector<Card> cards;
    std::string name = "Simple";
    int size;
    
};


class human : public Player {
public:
    human() : size(0){}
    human(std::string player_name) : size(0) {
        name = player_name;
    }
    
    //pull name
    const std::string & get_name() const {
        return name;
    }
    
    //add a card to deck
    void add_card(const Card &c) {
        cards.push_back(c);
        size ++;
    }
    
    //See if player wants to make trump or pass
    bool make_trump(const Card &upcard, bool is_dealer,
                    int round, std::string &order_up_suit) const {
        //Requires in first or second round
        assert(round<=2);
        int place_holder = 0;
        
        //round 1 action
        if (round == 1) {
            for (int i = 0; i < size; i++) {
                if (cards[i].is_face() && cards[i].is_trump(upcard.get_suit())) {
                    place_holder++; }
            } if (place_holder >= 2) {
                    return true; }
        } else {
            //round 2 action
            place_holder = 0;
            
            if (is_dealer) {
                order_up_suit = Suit_next(upcard.get_suit());
                return true;
            }
            for (int k = 0; k < size; k++) {
                if (cards[k].is_trump(Suit_next(upcard.get_suit()))
                    && cards[k].is_face()) {
                    place_holder ++;
                } if (place_holder >= 1) {
                    order_up_suit = Suit_next(upcard.get_suit());
                return true;
                }
            }
        }
        return false;
    }
    
    void add_and_discard(const Card &upcard) {
        assert(cards.size() >= 1);
        
        Card low = cards[0];
        Card holder2 = upcard;
                
        for (int j = 0; j < size; j++) {
            if (Card_less(cards[j], low, upcard.get_suit())) {
                holder2 = cards[j];
                cards[j] = low;
                low = holder2;
            }
        }
    }
    
    Card lead_card(const std::string &trump) {
        int number = 0;
        for (int j = 0; j < size; size++) {
            if (!cards[j].is_trump(trump)) {
                number = j;
            }
        }
        int number2 = size - 1;
        if (number != 0) {
            Card new_card = Card(cards[number].get_rank(), cards[number].get_suit());
            for (int k = number; k < number2; k++) {
                cards[k] = cards[k + 1];
            }
        size = size - 1;
        return Card(cards[number].get_rank(), cards[number].get_suit());
        }
        
    Card first = Card(cards[size - 1].get_rank(), cards[size - 1].get_suit());
    size = size - 1;
        return first;
}
    
private:
    std::vector<Card> cards;
    std::string name = "Simple";
    int size;
    
};

//return pointer with name and strategy
//Player * Player_factory(const std::string &name, const std::string &strategy) {
//    if (strategy == "Simple") {
//        return  *simp(name);
//    } else if (strategy == "Human"){
//        return *human(name);
//    } else {
//        assert(false);
//        return nullptr;
//    }
//}
