#include"Gamer.h"
#include"Deck.h"
using namespace std;

void show(Gamer player, Gamer computer)/*�H���a�����ݳ��W���ƻ�P*/
{
	player.tableDisplay();
	player.display();
	computer.simpDisplay();
}

void showALL(Gamer player, Gamer computer)/*�ݨ���W�Ҧ��P*/
{
	player.tableDisplay();
	player.display();
	computer.display();
}

void compare(Gamer& player, Gamer& computer)/*�������o���åB���t�`��`*/
{
	player.compare();/*�����a�P�ձo��*/
	computer.compare();/*���q���P�ձo��*/
	if (player.getScore() > computer.getScore())
	{
		player.win();
		computer.lose();
	}
	else if (player.getScore() < computer.getScore())
	{
		computer.win();
		player.lose();
	}
	else
	{
		player.tie();
		computer.tie();
		cout << "TIE";
		player.resetTotalBet();
	}
}

int main()
{
	cout << "Please type your name : ";
	string name;
	cin >> name;


	Deck deck;/*�إߵP��*/
	Gamer computer("computer", 0, 0);/*�إ߹q�����a*/
	Gamer player(name, 0, 0);
	int card;
	char a;

	do
	{
		card = deck.getCard();/*�o�P*/
		computer.setHandCard1(card);
		card = deck.getCard();
		computer.setHandCard2(card);
		card = deck.getCard();
		player.setHandCard1(card);
		card = deck.getCard();
		player.setHandCard2(card);

		for (int i = 0;i < 3;i++)
		{
			system("cls");
			show(player, computer);/*��ܹC������*/
			cout << "\nDo you want to surrender? (y/n) : ";
			cin >> a;
			while (a != 'y' && a != 'n')
			{
				cout << "Please type 'y' if you want to surrender; Type 'n' if not :";
				cin >> a;
			}
			if (a == 'y')/*���a��ܧ뭰*/
			{
				break;/*���Xfor�j��*/
			}
			else
			{
				cout << "How much money do you want to add to bet : ";
				int bet;
				cin >> bet;/*�]�w��`*/
				while (bet > player.getMoney())/*�p�G��`�񪱮a�����٦h*/
				{
					cout << "You don't have that much money, give a number below your money:";
					cin >> bet;/*���s�]�w��`*/
				}
				player.addBet(bet);
				if (bet > computer.getMoney())
				{
					bet = computer.getMoney();
				}
				computer.addBet(bet);/*���q����`*/

				if (i == 0)/*����T�i���P*/
				{
					card = deck.getCard();
					player.setPublicCard1(card);
					card = deck.getCard();
					player.setPublicCard2(card);
					card = deck.getCard();
					player.setPublicCard3(card);
				}
				else if (i == 1)/*����ĥ|�i���P*/
				{
					card = deck.getCard();
					player.setPublicCard4(card);
				}
				else/*����Ĥ��i���P*/
				{
					card = deck.getCard();
					player.setPublicCard5(card);
				}
			}
		}

		system("cls");
		showALL(player, computer);
		if (a == 'y')/*�p�G���a�뭰*/
		{
			player.lose();
			computer.win();
		}
		else
		{
			compare(player, computer);/*������a�P�q��������*/
		}
		deck.reset();/*���s�P��*/
		if (player.getMoney() == 0)/*���a���S��*/
		{
			system("cls");
			showALL(player, computer);/*��ܩҦ���T*/
			cout << "Congrats! computer win the whole game!";
		}
		else if (computer.getMoney() == 0)/*��q�����S��*/
		{
			system("cls");
			showALL(player, computer);/*��ܹC�����Ҧ���T*/
			cout << "Congrats! " << player.getName() << " win the whole game!";
		}
		else
		{
			cout << "\nWant to start another game? (y/n) : ";
			cin >> a;
		}
	} while (a == 'y' && player.getMoney() && computer.getMoney());
}