#ifndef Deck_h
#define Deck_h

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Deck
{
	private:
		int allCard[4][13] = { 0 };    /*�إߤ@�Ƽ��J�P*/
	public:
		Deck();
		int getCard();                 /*��P*/
		void reset();                  /*���m���J�P*/
};
#endif