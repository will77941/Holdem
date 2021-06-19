#include"Deck.h"
Deck::Deck()
{
	
}
int Deck::getCard()
{
	srand((unsigned)time(NULL));
	int card = rand() % 52;/*隨機取一張牌*/
	int	suit = card / 13;/*牌的花色*/
	int point = card % 13;/*牌的點數*/
	if (allCard[suit][point]==0)/*0表示牌還沒被抽走*/
	{
		allCard[suit][point]++;/*1表示牌被抽走*/
		return card;/*回傳這張牌*/
	}
	while(allCard[suit][point]==1)/*若牌被抽走則重複抽牌*/
	{
		card = rand() % 52;
		suit = card / 13;
		point = card % 13;
	}
	allCard[suit][point]++;
	return card;
}
void Deck::reset()
{
	for (int i = 0;i < 4;i++)/*將牌堆所有牌設為0*/
	{
		for (int j = 0;j < 13;j++)
		{
			allCard[i][j] = 0;
		}
	}
}