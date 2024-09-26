// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

static void add_cards(Player *player_1) {
    Card a(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    Card d(Card::RANK_ACE, Card::SUIT_CLUBS);
    Card e(Card::RANK_KING, Card::SUIT_SPADES);

    player_1->add_card(a);
    player_1->add_card(b);
    player_1->add_card(c);
    player_1->add_card(d);
    player_1->add_card(e);
    
}

TEST(playe_get_name) {
    Player *don = Player_factory("don", "Simple");
    ASSERT_EQUAL("Don", don->get_name());
    delete don;
}

TEST(add_card) {
    Player *don = Player_factory("don", "Simple");
    
    Card a(Card::RANK_JACK, Card::SUIT_HEARTS);
    Card b(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card c(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card d(Card::RANK_KING, Card::SUIT_DIAMONDS);
    
    don->add_card(a);
    don->add_card(b);
    
    
    ASSERT_EQUAL(don->lead_card(Card::SUIT_DIAMONDS), c);
    ASSERT_EQUAL(don->lead_card(Card::SUIT_CLUBS), b);

}

TEST(make_trump) {
    Player *player_1 = Player_factory("Don", "Simple");
    add_cards(player_1);
}



TEST_MAIN()
