#ifndef Deck_h
#define Deck_h

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Deck
{
	private:
		int allCard[4][13] = { 0 };    /*建立一副撲克牌*/
	public:
		Deck();
		int getCard();                 /*抽牌*/
		void reset();                  /*重置撲克牌*/
};
#endif