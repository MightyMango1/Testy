#include "../src/card.cpp"
#include "gtest/gtest.h"


TEST(CardTest, TestConstructor){
    Card *newCard = new Card(1, "topic", "description");
    EXPECT_EQ(newCard->get_front(), "topic");
    EXPECT_EQ(newCard->get_back(), "description");
    EXPECT_EQ(newCard->get_pileID(), 1);
}


TEST(CardTest, TestFront){
    Card *newCard = new Card();
    newCard->edit_front("topic");
    EXPECT_EQ(newCard->get_front(), "topic");
}

TEST(CardTest, TestBack){
    Card *newCard = new Card();
    newCard->edit_back("description");
    EXPECT_EQ(newCard->get_back(), "description");
}


TEST(CardTest, TestID){
    Card *newCard = new Card(1, "topic", "description");
    EXPECT_EQ(newCard->get_pileID(), 1);
}



