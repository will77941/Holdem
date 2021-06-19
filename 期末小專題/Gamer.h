#ifndef Gamer_h
#define Gamer_h
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Gamer
{
	private:
		string name; 					   /*名字*/
		int score; 						   /*牌組分數*/
		int money; 						   /*持有金額*/
		int bet; 						   /*賭注*/
		int handCard[2]; 				   /*手牌*/
		static int publicCard[5];		   /*公牌*/
		static int totalBet;			   /*總賭注*/
	public:
		Gamer(string, int, int);           /*建構子*/
		void tableDisplay();			   /*顯示公牌*/
		void display();					   /*顯示玩家所有資訊*/
		void simpDisplay();				   /*顯示玩家資訊除了手牌*/
		void addBet(int);				   /*增加賭注*/
		int getBet();					   /*回傳賭注的值*/
		string getName();				   /*回傳名稱*/
		int getMoney();					   /*回傳持有金額*/
		int getScore();					   /*回傳牌組得分*/
		void resetTotalBet();			   /*重置總賭注*/
		void setHandCard1(int);			   /*設置第一張手牌*/
		void setHandCard2(int);			   /*設置第二張手牌*/
		void setPublicCard1(int);		   /*設置第一張公牌*/
		void setPublicCard2(int);		   /*設置第二張公牌*/
		void setPublicCard3(int);		   /*設置第三張公牌*/
		void setPublicCard4(int);		   /*設置第四張公牌*/
		void setPublicCard5(int);		   /*設置第五張公牌*/
		void compare();					   /*判斷牌組得分*/
		void lose();					   /*輸家*/
		void win();						   /*贏家*/
		void tie();						   /*平手*/

};
#endif