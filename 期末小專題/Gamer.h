#ifndef Gamer_h
#define Gamer_h
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Gamer
{
	private:
		string name; 					   /*�W�r*/
		int score; 						   /*�P�դ���*/
		int money; 						   /*�������B*/
		int bet; 						   /*��`*/
		int handCard[2]; 				   /*��P*/
		static int publicCard[5];		   /*���P*/
		static int totalBet;			   /*�`��`*/
	public:
		Gamer(string, int, int);           /*�غc�l*/
		void tableDisplay();			   /*��ܤ��P*/
		void display();					   /*��ܪ��a�Ҧ���T*/
		void simpDisplay();				   /*��ܪ��a��T���F��P*/
		void addBet(int);				   /*�W�[��`*/
		int getBet();					   /*�^�ǽ�`����*/
		string getName();				   /*�^�ǦW��*/
		int getMoney();					   /*�^�ǫ������B*/
		int getScore();					   /*�^�ǵP�ձo��*/
		void resetTotalBet();			   /*���m�`��`*/
		void setHandCard1(int);			   /*�]�m�Ĥ@�i��P*/
		void setHandCard2(int);			   /*�]�m�ĤG�i��P*/
		void setPublicCard1(int);		   /*�]�m�Ĥ@�i���P*/
		void setPublicCard2(int);		   /*�]�m�ĤG�i���P*/
		void setPublicCard3(int);		   /*�]�m�ĤT�i���P*/
		void setPublicCard4(int);		   /*�]�m�ĥ|�i���P*/
		void setPublicCard5(int);		   /*�]�m�Ĥ��i���P*/
		void compare();					   /*�P�_�P�ձo��*/
		void lose();					   /*��a*/
		void win();						   /*Ĺ�a*/
		void tie();						   /*����*/

};
#endif