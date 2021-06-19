#include"Gamer.h"
int Gamer::publicCard[5] = { 52 ,52 ,52 ,52 ,52};/*設定公牌初值*/
int Gamer::totalBet = 0;/*設定總賭注初值*/
Gamer::Gamer(string n, int a, int b)/*建構子設定初值*/
{
	name = n;
	score = 0;
	money = 10000;
	bet = 0;
	handCard[0] = a;
	handCard[1] = b;
}						 
void Gamer::tableDisplay()
{
	cout << "\nPublic Card: ";
	for (int i = 0;i < 5;i++)/*輸出所有公牌的值*/
	{
		if (publicCard[i] == 52)
			cout << "NONE ";
		else
		{
			switch (publicCard[i] / 13)/*判斷花色*/
			{
			case 0:
				cout << "梅花";
				break;
			case 1:
				cout << "菱形";
				break;
			case 2:
				cout << "愛心";
				break;
			case 3:
				cout << "黑桃";
			}

			switch (publicCard[i] % 13)/*判斷點數*/
			{
			case 0:
				cout << 'A';
				break;
			case 1:
				cout << '2';
				break;
			case 2:
				cout << '3';
				break;
			case 3:
				cout << '4';
				break;
			case 4:
				cout << '5';
				break;
			case 5:
				cout << '6';
				break;
			case 6:
				cout << '7';
				break;
			case 7:
				cout << '8';
				break;
			case 8:
				cout << '9';
				break;
			case 9:
				cout << "10";
				break;
			case 10:
				cout << 'J';
				break;
			case 11:
				cout << 'Q';
				break;
			case 12:
				cout << 'K';
			}

		}
		cout << ' ';
	}
	cout << endl;

	cout << "Total Bet: " << totalBet << endl;/*輸出總賭注*/

	for (int i = 0;i < 40;i++)/*分隔線*/
	{
		cout << '-';
	}
	cout << endl;
}									 
void Gamer::display()
{
	cout << setw(5) << " " << name << "'s Cards : ";
	for (int i = 0;i < 2;i++)
	{
		switch (handCard[i] / 13)/*判斷花色*/
		{
		case 0:
			cout << "梅花";
			break;
		case 1:
			cout << "菱形";
			break;
		case 2:
			cout << "愛心";
			break;
		case 3:
			cout << "黑桃";
		}
		switch (handCard[i] % 13)/*判斷點數*/
		{
		case 0:
			cout << 'A';
			break;
		case 1:
			cout << '2';
			break;
		case 2:
			cout << '3';
			break;
		case 3:
			cout << '4';
			break;
		case 4:
			cout << '5';
			break;
		case 5:
			cout << '6';
			break;
		case 6:
			cout << '7';
			break;
		case 7:
			cout << '8';
			break;
		case 8:
			cout << '9';
			break;
		case 9:
			cout << "10";
			break;
		case 10:
			cout << 'J';
			break;
		case 11:
			cout << 'Q';
			break;
		case 12:
			cout << 'K';
		}
		cout << ' ';
	}
	cout << endl;

	cout << setw(5) << " " << "money: " << money << " bet: " << bet << endl;/*輸出玩家持有金額以及賭注*/

	for (int i = 0;i < 40;i++)/*分隔線*/
	{
		cout << '-';
	}
	cout << endl;
}										 
void Gamer::simpDisplay()
{
	cout << setw(5) << " " << name << "'s Cards : XX XX" << endl;/*輸出玩家名稱以及隱藏手牌*/

	cout << setw(5) << " " << "money: " << money << " bet: " << bet << endl;/*輸出玩家持有金額以及賭注*/

	for (int i = 0;i < 40;i++)/*分隔線*/
	{
		cout << '-';
	}
	cout << endl;
}									 
void Gamer::addBet(int a)
{
	bet += a;/*增加賭注*/
	money -= a;/*從持有金額扣掉增加的賭注*/
	totalBet += a;/*總賭注增加*/
}									 
int Gamer::getBet()
{
	return bet;/*回傳賭注*/
}										 
string Gamer::getName()
{
	return name;/*回傳名字*/
}									 
int Gamer::getMoney()
{
	return money;/*回傳持有金額*/
}										 
int Gamer::getScore()
{
	return score;/*回傳得分*/
}										 
void Gamer::resetTotalBet()
{
	totalBet = 0;/*重置總賭注*/
}								 
void Gamer::setHandCard1(int a)
{
	handCard[0] = a;/*設定第一張手牌*/
}							 
void Gamer::setHandCard2(int a)
{
	handCard[1] = a;/*設定第二張手牌*/
}							 
void Gamer::setPublicCard1(int a)
{
	publicCard[0] = a;/*設定第一張公牌*/
}							 
void Gamer::setPublicCard2(int a)
{
	publicCard[1] = a;/*設定第二張公牌*/
}							 
void Gamer::setPublicCard3(int a)
{
	publicCard[2] = a;/*設定第三張公牌*/
}							 
void Gamer::setPublicCard4(int a)
{
	publicCard[3] = a;/*設定第四張公牌*/
}							 
void Gamer::setPublicCard5(int a)
{
	publicCard[4] = a;/*設定第五張公牌*/
}							 
void Gamer::compare()
{
	int points[14] = { 0 };
	for (int i = 0;i < 5;i++)/*將公牌點數輸入points陣列*/
	{
		if (publicCard[i] < 52)
			points[publicCard[i] % 13]++;
	}
	for (int i = 0;i < 2;i++)/*將手牌點數輸入points陣列*/
	{
		if (handCard[i] < 52)
			points[handCard[i] % 13]++;
	}
	points[13] = points[0];/*因為A可以是1或14*/

	int suits[4] = { 0 };
	for (int i = 0;i < 5;i++)/*將公牌花色輸入suits陣列*/
	{
		if (publicCard[i] < 52)
			suits[publicCard[i] / 13]++;
	}
	for (int i = 0;i < 2;i++)/*將手牌花色輸入suits陣列*/
	{
		if (handCard[i] < 52)
			suits[handCard[i] / 13]++;
	}

	bool StraightFlush = false;/*設同花順為false*/
	bool Straight = false;	   /*設順子為false*/
	bool Flush = false;		   /*設同花為false*/
	bool FourOfAKind = false;  /*設鐵支為false*/
	bool FullHouse = false;	   /*設葫蘆為false*/
	bool ThreeOfAKind = false; /*設三條為false*/
	bool TwoPair = false;	   /*設兩對為false*/
	bool OnePair = false;	   /*設一對為false*/
	for (int i = 13;i > 3;i--)
	{
		if (points[i] && points[i - 1] && points[i - 2] && points[i - 3] && points[i - 4])
			Straight = true;/*連續五個點數不為零則為順子*/
	}
	for (int i = 0;i < 13;i++)
	{
		if (points[i] > 3)
			FourOfAKind = true;/*其中一項點數有四張或以上為鐵支*/
		else if (points[i] >= 3)
			ThreeOfAKind = true;/*其中一項點數有三張或以上為三條*/
		else if (points[i] >= 2)
			OnePair = true;/*其中一項點數有兩張或以上為一對*/
		for (int j = 0;j < 13;j++)
		{
			if (points[i] >= 3 && points[j] >= 2 && i != j)
			{
				FullHouse = true;/*取兩種點數。一種有三張或以上另一種有兩張或以上且兩種不為同一點數*/
			}
			else if (points[i] >= 2 && points[j] >= 2 && i != j)
			{
				TwoPair = true;/*取兩種點數。兩種都有兩張或以上且兩種不為同一點數*/
			}
		}
	}

	int cards[7];/*將五張公牌以及兩張手牌放入cards陣列*/
	for (int i = 0;i < 5;i++)
	{
		cards[i] = publicCard[i];
	}
	cards[5] = handCard[0];
	cards[6] = handCard[1];

	for (int i = 1; i < 7; i++)/*將cards陣列進行排序*/
	{
		int currentElement = cards[i];
		int k;
		for (k = i - 1; k >= 0 && cards[k] > currentElement; k--)
		{
			cards[k + 1] = cards[k];
		}
		cards[k + 1] = currentElement;
	}

	for (int i = 0;i < 3;i++)/*判斷是否為同花色的10 J Q K A*/
	{
		if (cards[i] == 0 && cards[i + 1] == 9 && cards[i + 2] == 10 && cards[i + 3] == 11 && cards[i + 4] == 12)
		{
			StraightFlush = true;
		}
		else if (cards[i] == 13 && cards[i + 1] == 22 && cards[i + 2] == 22 && cards[i + 3] == 23 && cards[i + 4] == 24)
		{
			StraightFlush = true;
		}
		else if (cards[i] == 26 && cards[i + 1] == 35 && cards[i + 2] == 36 && cards[i + 3] == 37 && cards[i + 4] == 38)
		{
			StraightFlush = true;
		}
		else if (cards[i] == 39 && cards[i + 1] == 48 && cards[i + 2] == 49 && cards[i + 3] == 50 && cards[i + 4] == 51)
		{
			StraightFlush = true;
		}
	}

	for (int i = 0;i < 3;i++)/*判斷是否為除了10 J Q K A的其他同花順*/
	{
		for (int j = 0;j < 9;j++)
		{
			if (cards[i] == j && cards[i + 1] == j + 1 && cards[i + 2] == j + 2 && cards[i + 3] == j + 3 && cards[i + 4] == j + 4)
			{
				StraightFlush = true;
			}
		}
		for (int j = 13;j < 22;j++)
		{
			if (cards[i] == j && cards[i + 1] == j + 1 && cards[i + 2] == j + 2 && cards[i + 3] == j + 3 && cards[i + 4] == j + 4)
			{
				StraightFlush = true;
			}
		}
		for (int j = 26;j < 35;j++)
		{
			if (cards[i] == j && cards[i + 1] == j + 1 && cards[i + 2] == j + 2 && cards[i + 3] == j + 3 && cards[i + 4] == j + 4)
			{
				StraightFlush = true;
			}
		}
		for (int j = 39;j < 48;j++)
		{
			if (cards[i] == j && cards[i + 1] == j + 1 && cards[i + 2] == j + 2 && cards[i + 3] == j + 3 && cards[i + 4] == j + 4)
			{
				StraightFlush = true;
			}
		}
	}

	if (StraightFlush)/*從最大的同花順到最小的一對改變玩家的得分數*/
		score = 8;
	else if (FourOfAKind)
		score = 7;
	else if (FullHouse)
		score = 6;
	else if (Flush)
		score = 5;
	else if (Straight)
		score = 4;
	else if (ThreeOfAKind)
		score = 3;
	else if (TwoPair)
		score = 2;
	else if (OnePair)
		score = 1;
}										 
void Gamer::lose()
{
	bet = 0;/*賭注歸零*/
	for (int i = 0;i < 5;i++)/*重置公牌*/
	{
		publicCard[i] = 52;
	}
}											 
void Gamer::win()
{
	bet = 0;/*賭注歸零*/
	money += totalBet;/*將總賭注加到持有金額*/
	totalBet = 0;/*總賭注歸零*/
	cout << setw(5) << " " << name << " WIN";
}											 
void Gamer::tie()
{
	bet = 0;/*賭注歸零*/
	money += totalBet / 2;/*總賭注對半分*/
	for (int i = 0;i < 5;i++)/*重置公牌*/
	{
		publicCard[i] = 52;
	}
}											 