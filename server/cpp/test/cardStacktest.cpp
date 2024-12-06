#include "../src/cardStack.cpp"
#include "gtest/gtest.h"
TEST(CardStackTest, testAmt0){
    CardStack *Stack = new CardStack();

    EXPECT_EQ(Stack->get_cardAmt(), 0);
}

TEST(CardStackTest, testAmt3){
    CardStack *Stack = new CardStack();
    vector<Card> card;
    Card *newCard = new Card();
    card.push_back(*newCard);
    card.push_back(*newCard);
    card.push_back(*newCard);
    EXPECT_EQ(Stack->get_cardAmt(), 3);
    delete newCard;
}


TEST(CardStackTest, testName){
    CardStack *newStack = new CardStack();
    newStack->editName("result");
    EXPECT_EQ(newStack->getName(), "result");

}

TEST(CardStackTest, testTopcard){
    CardStack *newStack = new CardStack();
    EXPECT_EQ(newStack->topCard(), NULL);//if empty should be null
}


TEST(CardStackTest, testTopcard){
    CardStack *newStack = new CardStack();
    Card *newCard = new Card();
    newStack->addCard(*newCard);
    EXPECT_EQ(newStack->topCard(), *newCard);//if empty should be null
}

TEST(CardStackTest, testPickCard){
    CardStack *newStack = new CardStack();
    Card newCard = Card(1, "topic", "description");
    Card SecondCard = Card(2, "topic", "description");
    newStack->addCard(newCard);
    newStack->addCard(SecondCard);
    EXPECT_EQ(newStack->pickCard(newCard.get_pileID()), newCard);
}


