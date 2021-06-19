#include"Gamer.h"
int Gamer::publicCard[5] = { 52 ,52 ,52 ,52 ,52};/*�]�w���P���*/
int Gamer::totalBet = 0;/*�]�w�`��`���*/
Gamer::Gamer(string n, int a, int b)/*�غc�l�]�w���*/
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
	for (int i = 0;i < 5;i++)/*��X�Ҧ����P����*/
	{
		if (publicCard[i] == 52)
			cout << "NONE ";
		else
		{
			switch (publicCard[i] / 13)/*�P�_���*/
			{
			case 0:
				cout << "����";
				break;
			case 1:
				cout << "�٧�";
				break;
			case 2:
				cout << "�R��";
				break;
			case 3:
				cout << "�®�";
			}

			switch (publicCard[i] % 13)/*�P�_�I��*/
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

	cout << "Total Bet: " << totalBet << endl;/*��X�`��`*/

	for (int i = 0;i < 40;i++)/*���j�u*/
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
		switch (handCard[i] / 13)/*�P�_���*/
		{
		case 0:
			cout << "����";
			break;
		case 1:
			cout << "�٧�";
			break;
		case 2:
			cout << "�R��";
			break;
		case 3:
			cout << "�®�";
		}
		switch (handCard[i] % 13)/*�P�_�I��*/
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

	cout << setw(5) << " " << "money: " << money << " bet: " << bet << endl;/*��X���a�������B�H�ν�`*/

	for (int i = 0;i < 40;i++)/*���j�u*/
	{
		cout << '-';
	}
	cout << endl;
}										 
void Gamer::simpDisplay()
{
	cout << setw(5) << " " << name << "'s Cards : XX XX" << endl;/*��X���a�W�٥H�����ä�P*/

	cout << setw(5) << " " << "money: " << money << " bet: " << bet << endl;/*��X���a�������B�H�ν�`*/

	for (int i = 0;i < 40;i++)/*���j�u*/
	{
		cout << '-';
	}
	cout << endl;
}									 
void Gamer::addBet(int a)
{
	bet += a;/*�W�[��`*/
	money -= a;/*�q�������B�����W�[����`*/
	totalBet += a;/*�`��`�W�[*/
}									 
int Gamer::getBet()
{
	return bet;/*�^�ǽ�`*/
}										 
string Gamer::getName()
{
	return name;/*�^�ǦW�r*/
}									 
int Gamer::getMoney()
{
	return money;/*�^�ǫ������B*/
}										 
int Gamer::getScore()
{
	return score;/*�^�Ǳo��*/
}										 
void Gamer::resetTotalBet()
{
	totalBet = 0;/*���m�`��`*/
}								 
void Gamer::setHandCard1(int a)
{
	handCard[0] = a;/*�]�w�Ĥ@�i��P*/
}							 
void Gamer::setHandCard2(int a)
{
	handCard[1] = a;/*�]�w�ĤG�i��P*/
}							 
void Gamer::setPublicCard1(int a)
{
	publicCard[0] = a;/*�]�w�Ĥ@�i���P*/
}							 
void Gamer::setPublicCard2(int a)
{
	publicCard[1] = a;/*�]�w�ĤG�i���P*/
}							 
void Gamer::setPublicCard3(int a)
{
	publicCard[2] = a;/*�]�w�ĤT�i���P*/
}							 
void Gamer::setPublicCard4(int a)
{
	publicCard[3] = a;/*�]�w�ĥ|�i���P*/
}							 
void Gamer::setPublicCard5(int a)
{
	publicCard[4] = a;/*�]�w�Ĥ��i���P*/
}							 
void Gamer::compare()
{
	int points[14] = { 0 };
	for (int i = 0;i < 5;i++)/*�N���P�I�ƿ�Jpoints�}�C*/
	{
		if (publicCard[i] < 52)
			points[publicCard[i] % 13]++;
	}
	for (int i = 0;i < 2;i++)/*�N��P�I�ƿ�Jpoints�}�C*/
	{
		if (handCard[i] < 52)
			points[handCard[i] % 13]++;
	}
	points[13] = points[0];/*�]��A�i�H�O1��14*/

	int suits[4] = { 0 };
	for (int i = 0;i < 5;i++)/*�N���P����Jsuits�}�C*/
	{
		if (publicCard[i] < 52)
			suits[publicCard[i] / 13]++;
	}
	for (int i = 0;i < 2;i++)/*�N��P����Jsuits�}�C*/
	{
		if (handCard[i] < 52)
			suits[handCard[i] / 13]++;
	}

	bool StraightFlush = false;/*�]�P�ᶶ��false*/
	bool Straight = false;	   /*�]���l��false*/
	bool Flush = false;		   /*�]�P�ᬰfalse*/
	bool FourOfAKind = false;  /*�]�K�䬰false*/
	bool FullHouse = false;	   /*�]��Ī��false*/
	bool ThreeOfAKind = false; /*�]�T����false*/
	bool TwoPair = false;	   /*�]��אּfalse*/
	bool OnePair = false;	   /*�]�@�אּfalse*/
	for (int i = 13;i > 3;i--)
	{
		if (points[i] && points[i - 1] && points[i - 2] && points[i - 3] && points[i - 4])
			Straight = true;/*�s�򤭭��I�Ƥ����s�h�����l*/
	}
	for (int i = 0;i < 13;i++)
	{
		if (points[i] > 3)
			FourOfAKind = true;/*�䤤�@���I�Ʀ��|�i�ΥH�W���K��*/
		else if (points[i] >= 3)
			ThreeOfAKind = true;/*�䤤�@���I�Ʀ��T�i�ΥH�W���T��*/
		else if (points[i] >= 2)
			OnePair = true;/*�䤤�@���I�Ʀ���i�ΥH�W���@��*/
		for (int j = 0;j < 13;j++)
		{
			if (points[i] >= 3 && points[j] >= 2 && i != j)
			{
				FullHouse = true;/*������I�ơC�@�ئ��T�i�ΥH�W�t�@�ئ���i�ΥH�W�B��ؤ����P�@�I��*/
			}
			else if (points[i] >= 2 && points[j] >= 2 && i != j)
			{
				TwoPair = true;/*������I�ơC��س�����i�ΥH�W�B��ؤ����P�@�I��*/
			}
		}
	}

	int cards[7];/*�N���i���P�H�Ψ�i��P��Jcards�}�C*/
	for (int i = 0;i < 5;i++)
	{
		cards[i] = publicCard[i];
	}
	cards[5] = handCard[0];
	cards[6] = handCard[1];

	for (int i = 1; i < 7; i++)/*�Ncards�}�C�i��Ƨ�*/
	{
		int currentElement = cards[i];
		int k;
		for (k = i - 1; k >= 0 && cards[k] > currentElement; k--)
		{
			cards[k + 1] = cards[k];
		}
		cards[k + 1] = currentElement;
	}

	for (int i = 0;i < 3;i++)/*�P�_�O�_���P��⪺10 J Q K A*/
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

	for (int i = 0;i < 3;i++)/*�P�_�O�_�����F10 J Q K A����L�P�ᶶ*/
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

	if (StraightFlush)/*�q�̤j���P�ᶶ��̤p���@����ܪ��a���o����*/
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
	bet = 0;/*��`�k�s*/
	for (int i = 0;i < 5;i++)/*���m���P*/
	{
		publicCard[i] = 52;
	}
}											 
void Gamer::win()
{
	bet = 0;/*��`�k�s*/
	money += totalBet;/*�N�`��`�[��������B*/
	totalBet = 0;/*�`��`�k�s*/
	cout << setw(5) << " " << name << " WIN";
}											 
void Gamer::tie()
{
	bet = 0;/*��`�k�s*/
	money += totalBet / 2;/*�`��`��b��*/
	for (int i = 0;i < 5;i++)/*���m���P*/
	{
		publicCard[i] = 52;
	}
}											 