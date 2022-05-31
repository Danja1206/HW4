#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
    enum suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    enum value {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
    Card(value _value = ACE, suit _suit = SPADES, bool _cardPosition = true) : v(_value), s(_suit), cardPosition(_cardPosition) {}
    void Flip() 
    {
        if (!cardPosition)
            cardPosition = true;
        else cardPosition = false;
    }
    value getValue()
    {
        if (cardPosition)
        {
            return v;
        }
    }
protected:
    value v;
    suit s;
    bool cardPosition;
};

class Hand
{
public:
    void Add(Card* aCard)
    {
        cards.push_back(aCard);
    }
    void Clear()
    {
        for (auto i : cards)
            delete i;
    }
    int getAmount()
    {
        if (cards.empty())
            return 0;
        int test = 0;
        for (auto crds : cards)
            test += crds->getValue();
        bool tests = false;
        for (auto crds : cards)
            if (crds->getValue() == crds->ACE) tests = true;
        if (tests && test <= 11)
            test += 10;
        return test;
    }
private:
    vector<Card*> cards;
};

int main()
{
    Card* C = new Card;
    //cout << C->getValue();
    //C->Flip();
    cout << C->getValue() << endl;
    Hand H;
    Hand* Hs = new Hand();
    H.Add(C);
    cout << H.getAmount();
}
