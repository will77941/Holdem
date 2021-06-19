#include"Gamer.h"
#include"Deck.h"
using namespace std;

void show(Gamer player, Gamer computer)/*以玩家視角看場上有甚麼牌*/
{
	player.tableDisplay();
	player.display();
	computer.simpDisplay();
}

void showALL(Gamer player, Gamer computer)/*看到場上所有牌*/
{
	player.tableDisplay();
	player.display();
	computer.display();
}

void compare(Gamer& player, Gamer& computer)/*比較雙方得分並且分配總賭注*/
{
	player.compare();/*取玩家牌組得分*/
	computer.compare();/*取電腦牌組得分*/
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


	Deck deck;/*建立牌堆*/
	Gamer computer("computer", 0, 0);/*建立電腦玩家*/
	Gamer player(name, 0, 0);
	int card;
	char a;

	do
	{
		card = deck.getCard();/*發牌*/
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
			show(player, computer);/*顯示遊戲介面*/
			cout << "\nDo you want to surrender? (y/n) : ";
			cin >> a;
			while (a != 'y' && a != 'n')
			{
				cout << "Please type 'y' if you want to surrender; Type 'n' if not :";
				cin >> a;
			}
			if (a == 'y')/*當玩家選擇投降*/
			{
				break;/*跳出for迴圈*/
			}
			else
			{
				cout << "How much money do you want to add to bet : ";
				int bet;
				cin >> bet;/*設定賭注*/
				while (bet > player.getMoney())/*如果賭注比玩家的錢還多*/
				{
					cout << "You don't have that much money, give a number below your money:";
					cin >> bet;/*重新設定賭注*/
				}
				player.addBet(bet);
				if (bet > computer.getMoney())
				{
					bet = computer.getMoney();
				}
				computer.addBet(bet);/*讓電腦跟注*/

				if (i == 0)/*抽取三張公牌*/
				{
					card = deck.getCard();
					player.setPublicCard1(card);
					card = deck.getCard();
					player.setPublicCard2(card);
					card = deck.getCard();
					player.setPublicCard3(card);
				}
				else if (i == 1)/*抽取第四張公牌*/
				{
					card = deck.getCard();
					player.setPublicCard4(card);
				}
				else/*抽取第五張公牌*/
				{
					card = deck.getCard();
					player.setPublicCard5(card);
				}
			}
		}

		system("cls");
		showALL(player, computer);
		if (a == 'y')/*如果玩家投降*/
		{
			player.lose();
			computer.win();
		}
		else
		{
			compare(player, computer);/*比較玩家與電腦的分數*/
		}
		deck.reset();/*重製牌堆*/
		if (player.getMoney() == 0)/*當玩家輸到沒錢*/
		{
			system("cls");
			showALL(player, computer);/*顯示所有資訊*/
			cout << "Congrats! computer win the whole game!";
		}
		else if (computer.getMoney() == 0)/*當電腦輸到沒錢*/
		{
			system("cls");
			showALL(player, computer);/*顯示遊戲內所有資訊*/
			cout << "Congrats! " << player.getName() << " win the whole game!";
		}
		else
		{
			cout << "\nWant to start another game? (y/n) : ";
			cin >> a;
		}
	} while (a == 'y' && player.getMoney() && computer.getMoney());
}