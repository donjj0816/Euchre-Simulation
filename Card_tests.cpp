// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, c.get_suit());
}

// Add more test cases here
TEST(get_card_tests) {
    Card a(Card::RANK_TEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_TEN, a.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, a.get_suit());
    
    Card b(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(Card::RANK_ACE, b.get_rank());
    ASSERT_EQUAL(Card::SUIT_HEARTS, b.get_suit());
    
    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_EQUAL(Card::RANK_JACK, c.get_rank());
    ASSERT_EQUAL(Card::SUIT_SPADES, c.get_suit());
    
    Card d(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Card::RANK_QUEEN, d.get_rank());
    ASSERT_EQUAL(Card::SUIT_DIAMONDS, d.get_suit());
    
    Card e(Card::RANK_KING, Card::SUIT_CLUBS);
    ASSERT_EQUAL(Card::RANK_KING, e.get_rank());
    ASSERT_EQUAL(Card::SUIT_CLUBS, e.get_suit());
}

TEST(is_face) {
    Card a(Card::RANK_KING, Card::SUIT_CLUBS);
    ASSERT_EQUAL(a.is_face(), true);
    
    Card b(Card::RANK_ACE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b.is_face(), true);

    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_EQUAL(c.is_face(), true);

    Card d(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(d.is_face(), true);
    
    Card e(Card::RANK_TEN, Card::SUIT_CLUBS);
    ASSERT_EQUAL(e.is_face(), false);
    
    Card f(Card::RANK_NINE, Card::SUIT_HEARTS);
    ASSERT_EQUAL(f.is_face(), false);

    Card g(Card::RANK_EIGHT, Card::SUIT_SPADES);
    ASSERT_EQUAL(g.is_face(), false);

    Card h(Card::RANK_SEVEN, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(h.is_face(), false);
}

TEST(is_bower) {
    //left bower
    Card a(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(a.is_left_bower(Card::SUIT_SPADES), true);


    Card b(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b.is_left_bower(Card::SUIT_DIAMONDS), true);


    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_EQUAL(c.is_left_bower(Card::SUIT_CLUBS), true);


    Card d(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(d.is_left_bower(Card::SUIT_HEARTS), true);

    
    //right bower
    Card e(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(e.is_right_bower(Card::SUIT_CLUBS), true);


    Card f(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(f.is_right_bower(Card::SUIT_HEARTS), true);


    Card g(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_EQUAL(g.is_right_bower(Card::SUIT_SPADES), true);


    Card h(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(h.is_right_bower(Card::SUIT_DIAMONDS), true);

}

TEST(is_trump) {
    
    Card a(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(a.is_trump(Card::SUIT_SPADES), true);
    ASSERT_EQUAL(a.is_trump(Card::SUIT_CLUBS), true);

    Card b(Card::RANK_JACK, Card::SUIT_HEARTS);
    ASSERT_EQUAL(b.is_trump(Card::SUIT_DIAMONDS), true);
    ASSERT_EQUAL(b.is_trump(Card::SUIT_HEARTS), true);

    Card c(Card::RANK_JACK, Card::SUIT_SPADES);
    ASSERT_EQUAL(c.is_trump(Card::SUIT_SPADES), true);
    ASSERT_EQUAL(c.is_trump(Card::SUIT_CLUBS), true);

    Card d(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(d.is_trump(Card::SUIT_DIAMONDS), true);
    ASSERT_EQUAL(d.is_trump(Card::SUIT_HEARTS), true);
    
    Card e(Card::RANK_JACK, Card::SUIT_CLUBS);
    ASSERT_EQUAL(a.is_trump(Card::SUIT_HEARTS), false);
    ASSERT_EQUAL(a.is_trump(Card::SUIT_DIAMONDS), false);
}

TEST(operators) {
    Card a(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card e(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card f(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card g(Card::RANK_ACE, Card::SUIT_DIAMONDS);
    Card h(Card::RANK_NINE, Card::SUIT_CLUBS);


    
    //less than
    ASSERT_EQUAL(a<b, false);
    ASSERT_EQUAL(b<c, true);
    ASSERT_EQUAL(a<b, false);
    ASSERT_EQUAL(d<c, true);
    ASSERT_EQUAL(g<c, false);
    ASSERT_EQUAL(g<c, false);


    //Greater than
    ASSERT_EQUAL(a>b, true);
    ASSERT_EQUAL(b>c, false);
    ASSERT_EQUAL(a>b, true);
    ASSERT_EQUAL(d>c, false);
    ASSERT_EQUAL(g>c, true);

    
    //less than or equal
    ASSERT_EQUAL(a<=b, false);
    ASSERT_EQUAL(b<=c, true);
    ASSERT_EQUAL(h<=f, true);
    ASSERT_EQUAL(d<=c, true);
    
    //less than or equal
    ASSERT_EQUAL(a>=b, true);
    ASSERT_EQUAL(b>=c, false);
    ASSERT_EQUAL(h>=f, false);
    ASSERT_EQUAL(d>=c, false);

    //equal
    ASSERT_EQUAL(a==b, false);
    ASSERT_EQUAL(b==c, false);
    ASSERT_EQUAL(a==f, true);
    ASSERT_EQUAL(d==e, true);
    
    //Not equal
    ASSERT_EQUAL(a!=b, true);
    ASSERT_EQUAL(b!=c, true);
    ASSERT_EQUAL(a!=f, false);
    ASSERT_EQUAL(d!=e, false);
}

TEST(suit_next) {
    ASSERT_EQUAL(Suit_next(Card::SUIT_DIAMONDS), Card::SUIT_HEARTS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_CLUBS), Card::SUIT_SPADES);
    ASSERT_EQUAL(Suit_next(Card::SUIT_HEARTS), Card::SUIT_DIAMONDS);
    ASSERT_EQUAL(Suit_next(Card::SUIT_SPADES), Card::SUIT_CLUBS);
}

TEST(card_less_using_trump) {
    Card a(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card e(Card::RANK_ACE, Card::SUIT_DIAMONDS);

    
    ASSERT_EQUAL(Card_less(a, b, Card::SUIT_DIAMONDS), false);
    ASSERT_EQUAL(Card_less(b, c, Card::SUIT_SPADES), true);
    ASSERT_EQUAL(Card_less(b, c, Card::SUIT_CLUBS), true);
    ASSERT_EQUAL(Card_less(a, e, Card::SUIT_DIAMONDS), true);
    ASSERT_EQUAL(Card_less(e, e, Card::SUIT_DIAMONDS), false);

}

TEST(card_less_using_both) {
    Card a(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    Card b(Card::RANK_TEN, Card::SUIT_HEARTS);
    Card c(Card::RANK_KING, Card::SUIT_SPADES);
    Card d(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    Card e(Card::RANK_ACE, Card::SUIT_DIAMONDS);

    ASSERT_EQUAL(Card_less(a, d, b, Card::SUIT_DIAMONDS), false);
    ASSERT_EQUAL(Card_less(d, a, b, Card::SUIT_DIAMONDS), true);
    ASSERT_EQUAL(Card_less(e, d, a, Card::SUIT_DIAMONDS), false);
    ASSERT_EQUAL(Card_less(b, d, e, Card::SUIT_CLUBS), true);
    ASSERT_EQUAL(Card_less(c, a, d, Card::SUIT_CLUBS), false);
    ASSERT_EQUAL(Card_less(d, c, c, Card::SUIT_HEARTS), true);
    ASSERT_EQUAL(Card_less(a, e, c, Card::SUIT_HEARTS), false);
    ASSERT_EQUAL(Card_less(c, d, a, Card::SUIT_SPADES), false);
    ASSERT_EQUAL(Card_less(e, a, b, Card::SUIT_SPADES), false);

}

TEST(streamo){
    Card a(Card::RANK_ACE, Card::SUIT_HEARTS);
    Card b(Card::RANK_TEN, Card::SUIT_SPADES);
    
    //Card a
    ostringstream a_of_h;
    a_of_h << a;
    
    ASSERT_EQUAL(a_of_h.str(), "Ace of Hearts");
    
    //Card b
    ostringstream t_of_s;
    t_of_s << b;
    
    ASSERT_EQUAL(t_of_s.str(), "Ten of Spades");

}

TEST_MAIN()
