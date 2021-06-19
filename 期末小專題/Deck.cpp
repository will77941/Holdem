#include"Deck.h"
Deck::Deck()
{
	
}
int Deck::getCard()
{
	srand((unsigned)time(NULL));
	int card = rand() % 52;/*�H�����@�i�P*/
	int	suit = card / 13;/*�P�����*/
	int point = card % 13;/*�P���I��*/
	if (allCard[suit][point]==0)/*0��ܵP�٨S�Q�⨫*/
	{
		allCard[suit][point]++;/*1��ܵP�Q�⨫*/
		return card;/*�^�ǳo�i�P*/
	}
	while(allCard[suit][point]==1)/*�Y�P�Q�⨫�h���Ʃ�P*/
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
	for (int i = 0;i < 4;i++)/*�N�P��Ҧ��P�]��0*/
	{
		for (int j = 0;j < 13;j++)
		{
			allCard[i][j] = 0;
		}
	}
}