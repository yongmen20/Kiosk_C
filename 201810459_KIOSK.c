#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#define Max 100

INPUT_RECORD rec;
DWORD dwNOER, CIN, mode;
int play = 0;
int p = 0;
int page = 1;
int check1 = 0;
int check2 = 0;
int check3 = 0;
int price1 = 0;
int price2 = 0;
int price3 = 0;
int price4 = 0;
int price_hap;
int price_all;



struct Sell_Product{
	char product[Max]; //僭ヶ薑爾 殮溘
	char price[Max]; //陛問薑爾 殮溘 
};

struct Buy_Product{	//摹鷗и僭ヶ薑爾1 
	char buy_product[Max];
	char buy_price[Max];
};
struct Buy_Product2{ //摹鷗и僭ヶ薑爾2
	char buy_product2[Max];
	char buy_price2[Max];
};
struct Buy_Product3{ //摹鷗и僭ヶ薑爾3
	char buy_product3[Max];
	char buy_price3[Max];
};
struct Buy_Product4{ //摹鷗и僭ヶ薑爾4
	char buy_product4[Max];
	char buy_price4[Max];
};

void Mouse_Control()
{
	int x, y;
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 夔樂璽 殮溘擊 嫡嬴菟歜.
	if (rec.EventType == MOUSE_EVENT) // 葆辦蝶 檜漸お橾 唳辦
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 謝難 幗が檜 贗葛腎歷擊 唳辦
	    {
	        x = rec.Event.MouseEvent.dwMousePosition.X; // X高 嫡嬴褥
	    	y = rec.Event.MouseEvent.dwMousePosition.Y; // Y高 嫡嬴褥
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //葆辦蝶 營�側瘓�
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check(&x, &y);
}

void Mouse_Check(int *cx, int *cy) //謝ル縑 評艇 褒ч高 
{
	int x, y;

	x = *cx;
	y = *cy;
	
	do{
		if(x >= 7 && x <= 24 && y >= 11 && y <= 15){
			play++;
			Sell_Product();
		}
				
		if(x >= 30 && x <= 47 && y >= 11 && y <= 15){
			play++;
			Change_Product();		
		}
			
		if(x >= 7 && x <= 24 && y >= 17 && y <= 21){
			play++;
			Reset_A();	
		}
			
		if(x >= 30 && x <= 47 && y >= 17 && y <= 21){
			play++;
			All_money();
		}
			
		if(x >= 7 && x <= 24 && y >= 23 && y <= 27){
			play++;
			Seller_name();		
		}
				
		if(x >= 30 && x <= 47 && y >= 23 && y <= 27){
			play++;
			List_Consol();	
		}
	}while(play != 0 );
	
	
}

void Mouse_Control2()
{
	int x2, y2;
	
	
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 夔樂璽 殮溘擊 嫡嬴菟歜.
	if (rec.EventType == MOUSE_EVENT) // 葆辦蝶 檜漸お橾 唳辦
	{
		if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 謝難 幗が檜 贗葛腎歷擊 唳辦
	    {
	        x2 = rec.Event.MouseEvent.dwMousePosition.X; // X高 嫡嬴褥
	    	y2 = rec.Event.MouseEvent.dwMousePosition.Y; // Y高 嫡嬴褥
	    }
   	} 	
   	system("cls");
    CIN = GetStdHandle(STD_INPUT_HANDLE); //葆辦蝶 營�側瘓�
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	Mouse_Check2(&x2, &y2);
}

void Mouse_Check2(int *dx, int *dy) //謝ル縑 評艇 褒ч高 
{
	int x2, y2;

	x2 = *dx;
	y2 = *dy;
	
	if(x2 >= 7 && x2 <= 46 && y2 >= 11 && y2 <= 15){
		if(check1 <= 3)
		{
			check1++;
		}	
	}
		
	else if(x2 >= 7 && x2 <= 46 && y2 >= 17 && y2 <= 21){
		if(check2 <= 3)
		{
			check2++;
		}
	}
		
	else if(x2 >= 7 && x2 <= 46 && y2 >= 23 && y2 <= 27){
		if(check3 <= 3)
		{
			check3++;
		}
	}
	else if(x2 >= 7 && x2 <= 17 && y2 >= 29 && y2 <= 31){ //檜瞪跡煙 
		if(p == 0){
			p = 0;
			page = 1;
		}		
		else if (p > 0){
			p = p - 3;
			page--;
		}
	}
	
	else if(x2 >= 36 && x2 <= 46 && y2 >= 29 && y2 <= 31){ //棻擠跡煙 
		if(p < 6){
			p = p + 3;
			page++;
		}
		else if(p == 6){
			p = 6;
			page = 3;
		}
	}
	
	else if(x2 >= 82 && x2 <= 93 && y2 >= 29 && y2 <= 31){ //唸薯 
		purchase_Screen();
	}
	else if(x2 == 0 && y2 == 0){
		play = 0;
	}

}

//撲薑詭景璽 轎溘
void Setting_Consol()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("Seller_name.txt", "r");
	fp1 = fopen("Seller_num.txt", "r");
	
	char name[20];
	char num[20];
	fgets(name, sizeof(name), fp); 
	fgets(num, sizeof(num), fp1);
	
	if (fp == NULL || sizeof(name) < 5)
	{
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤	                               ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤        <蛔煙脹 餌辨濠>         ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤      餌辨濠蒂 蛔煙ж撮蹂       ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤           <瞪�食醽�>           ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤       Tel. 000-0000-0000       ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	}
	
	else if(sizeof(name) == 20)
	{
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤	                               ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤        <蛔煙脹 餌辨濠>         ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤             %s             ﹤     ﹥ \n", name);
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤           <瞪�食醽�>           ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤       Tel. %s       ﹤     ﹥ \n", num);
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	}
		
	fclose(fp);
	fclose(fp1);
}

//僭ヶ蛔煙
void Sell_Product()
{
	struct Sell_Product SP;
	
	FILE* fp;
	fp = fopen("Sell_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};


	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}

	else if (fp != NULL)
	{
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤   っ衙й 僭ヶ曖 檜葷擊 殮溘    ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤   殮溘и 僭ヶ曖 陛問擊 殮溘    ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.price);
		fp = fopen("Sell_Product.txt", "a");
		fputs(SP.product, fp);
		fputs(" ", fp); 
		fputs(SP.price, fp);
		fputs(" ", fp); 
		fputs("\n", fp);
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp); 
	play = 0;
}

//僭ヶ薑爾ら餵
void Change_Product()
{
	struct Sell_Product SP;
	
	FILE* fp; // 檗橫螢 だ橾 
	fp = fopen("Sell_Product.txt", "r+");

	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	char buffer[Max], *token;
	char str2[Max], str2_price[Max];
	int find_pos; 

	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}

	else
	{
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤   熱薑ж堅濠 ж朝 僭ヶ殮溘     ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(SP.product);
		
		
		while(fgets(buffer, Max, fp) != NULL)
		{		
			token = strstr(buffer, SP.product);	
			if(strstr(buffer, SP.product) == NULL)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
				printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
				printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤  殮溘и 僭ヶ檜 襄營ж雖 彊擠.. ﹤     ﹥ \n");
				printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");	
				sleep(2);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				fclose(fp);
				play = 0;
				break;
			}
			else
			{
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
				printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
				printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤       熱薑腎朝 僭ヶ殮溘        ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
				printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				gets(str2);			
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
				printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
				printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
				printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤   熱薑и 僭ヶ曖 陛問擊 殮溘    ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
				printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
				printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥                                                                                                            ﹥ \n");
				printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				gets(str2_price);
			
				find_pos = strlen(buffer) - (token - buffer) + 1;
				fseek(fp, (-1)*find_pos, SEEK_CUR);
				fputs(str2, fp);
				fputs(" ", fp);
				fputs(str2_price, fp);
				fputs(" ", fp);
				fputs("\n", fp);
				fseek(fp, find_pos - (strlen(str2) + strlen(str2_price) + 2), SEEK_CUR);
			}
		}
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp);
	play = 0;
}

//薑爾蟾晦��
void Reset_A()
{
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	char ask;

	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
	printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
	printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
	printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
	printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤  蟾晦�� ж衛啊蝗棲梱? >> y/n   ﹤     ﹥ \n");
	printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
	printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
	scanf("%c", &ask);

	if (ask == 'y')
	{
		remove("Seller_name.txt");
		remove("Seller_num.txt"); 
		remove("Sell_Product.txt");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤         蟾晦�� 諫猿 !!         ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		Sleep(2000);
	}
	else if (ask == 'n')
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤         蟾晦�� 鏃模...         ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		Sleep(2000);
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	play = 0;
}

//識 熱櫛 
void All_money()
{
	FILE* fp;
	fp = fopen("Buy_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	int price;
	
	if(fp == NULL)
	{
		fp = fopen("Buy_Product.txt", "w");
	}	
	
	else
	{
		fscanf(fp, "%d", &price);
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤      雖旎梱雖曖 っ衙熱櫛       ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		if(price == NULL || price == 0)
			printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >> 0 錳                      ﹤     ﹥ \n", price);	
		else 
			printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >> %8d 錳               ﹤     ﹥ \n", price);	
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		sleep(2);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		play = 0;
	}
	fclose(fp); 
}

//餌辨濠蛔煙
void Seller_name()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("Seller_name.txt", "r");
	fp1 = fopen("Seller_num.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	
	char name[20];
	char num[20];

	if ((fp == NULL))
	{
		fp = fopen("Seller_name.txt", "w");
		fp1 = fopen("Seller_num.txt", "w");
	}

	else
	{
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤  п渡晦晦曖 婦葬濠 檜葷 殮溘   ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(name);
		fprintf(fp = fopen("Seller_name.txt", "w"), "%s", name);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥﹥     ﹥ \n");
		printf("﹥     ﹥               ﹥                 ﹥             ﹥           ﹥       ﹥﹥    ﹥     ﹥             ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥           ﹥       ﹥  ﹥  ﹥     ﹥    ﹥﹥     ﹥ \n");
		printf("﹥                 ﹥   ﹥                 ﹥             ﹥           ﹥       ﹥    ﹥﹥     ﹥      ﹥     ﹥ \n");
		printf("﹥       ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥             ﹥         ﹥﹥﹥     ﹥      ﹥       ﹥﹥﹥       ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤   僭ヶ蛔煙   ﹤     ﹤ 僭ヶ薑爾ら餵 ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤  餌辨濠 瞪�食醽�(-んл 殮溘)   ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤   >>                           ﹤     ﹥ \n");
		printf("﹥     ﹤  薑爾蟾晦��  ﹤     ﹤  識熱殮�挫�  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤  餌辨濠蛔煙  ﹤     ﹤  衛蝶蠱褒ч  ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤              ﹤     ﹤              ﹤                     ﹤                                ﹤     ﹥ \n");
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹤﹤﹤﹤﹤﹤﹤﹤﹤                     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥                                                                                                            ﹥ \n");
		printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
		gets(num);
		fprintf(fp1 = fopen("Seller_num.txt", "w"), "%s", num);
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Clear);
	fclose(fp); 
	fclose(fp1);
	play = 0;
}

//褒ч詭景璽 褒ч
void List_Consol()
{	
	struct Buy_Product BP[3];
	struct Buy_Product2 BP2[3];
	struct Buy_Product3 BP3[3];
	struct Buy_Product4 BP4[3];

	Mouse_Control2();
	FILE* fp;
	fp = fopen("Sell_Product.txt", "r");
	COORD Coor = {77, 18};
	COORD Clear = {0, 0};
	
	struct Sell_Product SP[Max];
	int i = 0;
	int idx = 0;
	int check = 0;
	check1 == 0;
	check2 == 0;
	check3 == 0;
	price1 = 0;
	price2 = 0;
	price3 = 0;
	price4 = 0;
	char buffer[Max], *token;
	
	if (fp == NULL)
	{
		fp = fopen("Sell_Product.txt", "w");
	}
	while(!feof(fp))
	{
		i = 0;
		fgets(buffer, Max, fp);
		token = strtok(buffer, " ");
		while (token != NULL)
		{
			if (i == 0)
			{
				strcpy(SP[idx].product, token);
			}
			else if (i == 1)
			{
				strcpy(SP[idx].price, token);
			}
			i++;
			token = strtok(NULL, " ");
		}
		idx++;
	}
	
	int show1 = strlen(SP[p].product) + strlen(SP[p].price);
	int show2 = strlen(SP[p+1].product) + strlen(SP[p+1].price);
	int show3 = strlen(SP[p+2].product) + strlen(SP[p+2].price);
	
	
	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                              ﹥           ﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥                             ﹥ \n");
	printf("﹥                              ﹥             ﹥     ﹥                   ﹥                                 ﹥ \n");
	printf("﹥                              ﹥             ﹥       ﹥﹥﹥﹥﹥         ﹥                                 ﹥ \n");
	printf("﹥                              ﹥             ﹥                 ﹥       ﹥                                 ﹥ \n");
	printf("﹥                              ﹥﹥﹥﹥﹥   ﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥                                 ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n");
	if(show2 < 3)
	{
		printf("﹥     ﹤                                    ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if (show1 == 7)
	{
		printf("﹥     ﹤%s %s                            ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 8)
	{		
		printf("﹥     ﹤%s %s                           ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);	
	}
	else if(show1 == 9)
	{
		printf("﹥     ﹤%s %s                          ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 10)
	{
		printf("﹥     ﹤%s %s                         ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 11)
	{
		printf("﹥     ﹤%s %s                        ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 12)
	{
		printf("﹥     ﹤%s %s                       ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 13)
	{
		printf("﹥     ﹤%s %s                      ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	else if(show1 == 14)
	{
		printf("﹥     ﹤%s %s                     ﹤                      ﹤          <摹鷗и 僭ヶ>         ﹤     ﹥ \n", SP[p].product, SP[p].price);
	}
	//1廓簞 蘊 
	printf("﹥     ﹤                                    ﹤                      ");
	if(p == 0 || p == 3 || p == 6)
	{
		if(check == 0)
		{
			if(check1 == 1)
			{
				strcpy(BP[0].buy_product, SP[p].product);
				strcpy(BP[0].buy_price, SP[p].price);
				price1 = atoi(BP[0].buy_price);
				
				if (show1 == 7)
				{	
					printf("﹤%s %s                        ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
				else if (show1 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP[0].buy_product, BP[0].buy_price);	
				}
			}
			else if(check2 == 1) 
			{
				strcpy(BP[1].buy_product, SP[p+1].product);
				strcpy(BP[1].buy_price, SP[p+1].price);
				price1 = atoi(BP[1].buy_price);
					
				if (show2 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
				else if (show2 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP[1].buy_product, BP[1].buy_price);	
				}
			}
			else if(check3 == 1) 
			{
				strcpy(BP[2].buy_product, SP[p+2].product);
				strcpy(BP[2].buy_price, SP[p+2].price);
				price1 = atoi(BP[2].buy_price);
				
				if (show3 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
				else if (show3 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				} 
				else if (show3 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP[2].buy_product, BP[2].buy_price);	
				}
			}
			else
			{
				printf("﹤                                ﹤     ﹥ \n");
			}
			check ++;
		}
		
		//2廓簞 蘊 
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ");
		if(check == 1)
		{
			if(check1 == 2)
			{
				strcpy(BP2[0].buy_product2, SP[p].product);
				strcpy(BP2[0].buy_price2, SP[p].price);
				price2 = atoi(BP2[0].buy_price2);
				
				if (show1 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
				else if (show1 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP2[0].buy_product2, BP2[0].buy_price2);	
				}
			}
			else if(check2 == 2)
			{
				strcpy(BP2[1].buy_product2, SP[p+1].product);
				strcpy(BP2[1].buy_price2, SP[p+1].price);
				price2 = atoi(BP2[1].buy_price2);
				
				if (show2 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
				else if (show2 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP2[1].buy_product2, BP2[1].buy_price2);	
				}
			}
			else if(check3 == 2)
			{
				strcpy(BP2[2].buy_product2, SP[p+2].product);
				strcpy(BP2[2].buy_price2, SP[p+2].price);
				price2 = atoi(BP2[2].buy_price2);
				
				if (show3 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
				else if (show3 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP2[2].buy_product2, BP2[2].buy_price2);	
				}
			}
			else
			{
				printf("﹤                                ﹤     ﹥ \n");
			}
			check++;
		}
	
		//3廓簞 蘊 
		printf("﹥                                                                   ");
		if(check == 2)
		{
			if(check1 == 3)
			{
				strcpy(BP3[0].buy_product3, SP[p].product);
				strcpy(BP3[0].buy_price3, SP[p].price);
				price3 = atoi(BP3[0].buy_price3);

				if (show1 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
				else if (show1 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP3[0].buy_product3, BP3[0].buy_price3);	
				}
			}
			else if(check2 == 3)
			{
				strcpy(BP3[1].buy_product3, SP[p+1].product);
				strcpy(BP3[1].buy_price3, SP[p+1].price);
				price3 = atoi(BP3[1].buy_price3);
					
				if (show2 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
				else if (show2 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP3[1].buy_product3, BP3[1].buy_price3);	
				}
			}
			else if(check3 == 3)
			{
				strcpy(BP3[2].buy_product3, SP[p+2].product);
				strcpy(BP3[2].buy_price3, SP[p+2].price);
				price3 = atoi(BP3[2].buy_price3);
				
				if (show3 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
				else if (show3 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP3[2].buy_product3, BP3[2].buy_price3);	
				}
			}
			else
			{
				printf("﹤                                ﹤     ﹥ \n"); 
			}
			check++;
		}

		//4廓簞 還 
		printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ");
		if(check == 3)
		{
			if(check1 == 4)
			{
				strcpy(BP4[0].buy_product4, SP[p].product);
				strcpy(BP4[0].buy_price4, SP[p].price);
				price4 = atoi(BP4[0].buy_price4);

				if (show1 == 7)
				{	
					printf("﹤%s %s                        ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
				else if (show1 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP4[0].buy_product4, BP4[0].buy_price4);	
				}
			}
			else if(check2 == 4)
			{
				strcpy(BP4[1].buy_product4, SP[p+1].product);
				strcpy(BP4[1].buy_price4, SP[p+1].price);
				price4 = atoi(BP4[1].buy_price4);
					
				if (show2 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
				else if (show2 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP4[1].buy_product4, BP4[1].buy_price4);	
				}
			}
			else if(check3 == 4)
			{
				strcpy(BP4[2].buy_product4, SP[p+2].product);
				strcpy(BP4[2].buy_price4, SP[p+2].price);
				price4 = atoi(BP4[2].buy_price4);
					
				if (show3 == 7)
				{
					printf("﹤%s %s                        ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 8)
				{
					printf("﹤%s %s                       ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 9)
				{
					printf("﹤%s %s                      ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 10)
				{
					printf("﹤%s %s                     ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 11)
				{
					printf("﹤%s %s                    ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 12)
				{
					printf("﹤%s %s                   ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 13)
				{
					printf("﹤%s %s                  ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
				else if (show3 == 14)
				{
					printf("﹤%s %s                 ﹤     ﹥ \n", BP4[2].buy_product4, BP4[2].buy_price4);	
				}
			}
			else
			{
				printf("﹤                                ﹤     ﹥ \n");
			}
		}
	}
	printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n");
	if(show2 < 3)
	{
		printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 7)
	{
		printf("﹥     ﹤%s %s                            ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 8)
	{
		printf("﹥     ﹤%s %s                           ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 9)
	{
		printf("﹥     ﹤%s %s                          ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 10)
	{
		printf("﹥     ﹤%s %s                         ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 11)
	{
		printf("﹥     ﹤%s %s                        ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 12)
	{
		printf("﹥     ﹤%s %s                       ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 13)
	{
		printf("﹥     ﹤%s %s                      ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	else if(show2 == 14)
	{
		printf("﹥     ﹤%s %s                     ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+1].product, SP[p+1].price);
	}
	
	printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ﹤                                ﹤     ﹥ \n");
	printf("﹥                                                                   ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n");
	if(show3 < 3)
	{
		printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 7)
	{
		printf("﹥     ﹤%s %s                            ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 8)
	{
		printf("﹥     ﹤%s %s                           ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 9)
	{
		printf("﹥     ﹤%s %s                          ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 10)
	{
		printf("﹥     ﹤%s %s                         ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 11)
	{
		printf("﹥     ﹤%s %s                        ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}	
	else if(show3 == 12)
	{
		printf("﹥     ﹤%s %s                       ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 13)
	{
		printf("﹥     ﹤%s %s                      ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	else if(show3 == 14)
	{
		printf("﹥     ﹤%s %s                     ﹤                      ﹤                                ﹤     ﹥ \n", SP[p+2].product, SP[p+2].price);
	}
	printf("﹥     ﹤                                    ﹤                      ﹤                                ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤                      ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥    忙          忖                 忙          忖                                  忙式式式式式式式式式式式忖                ﹥ \n");
	printf("﹥    弛 檜瞪 跡煙弛        %d        弛 棻擠 跡煙弛                                  弛    唸薯   弛                ﹥ \n", page);
	printf("﹥    戌          戎                 戌          戎                                  戌式式式式式式式式式式式戎                ﹥ \n");
	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");	
	
	fclose(fp);
}
//唸薯�飛�
void purchase_Screen()
{
	FILE* fp; // 檗橫螢 だ橾 
	fp = fopen("Buy_Product.txt", "r");

	if (fp == NULL)
	{
		fp = fopen("Buy_Product.txt", "w");
	}
	
	price_hap = 0;
	fscanf(fp, "%d", &price_all);
	
	price_hap = price1 + price2 + price3 + price4;	
	price_all = price_all + price_hap;
	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                              ﹥           ﹥﹥﹥     ﹥﹥﹥﹥﹥     ﹥﹥﹥﹥﹥                             ﹥ \n");
	printf("﹥                              ﹥             ﹥     ﹥                   ﹥                                 ﹥ \n");
	printf("﹥                              ﹥             ﹥       ﹥﹥﹥﹥﹥         ﹥                                 ﹥ \n");
	printf("﹥                              ﹥             ﹥                 ﹥       ﹥                                 ﹥ \n");
	printf("﹥                              ﹥﹥﹥﹥﹥   ﹥﹥﹥     ﹥﹥﹥﹥﹥         ﹥                                 ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥    收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收    ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                    唸薯陛 諫猿腎歷蝗棲棻!                                    ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                    識 旎擋 : %8d                                        ﹤     ﹥ \n", price_hap);
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤                                                                                              ﹤     ﹥ \n");
	printf("﹥     ﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤﹤     ﹥ \n");
	printf("﹥                                                                                                            ﹥ \n");
	printf("﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥ \n");
	check1 = 0;
	check2 = 0;
	check3 = 0;
	fp = fopen("Buy_Product.txt", "w");
	fprintf(fp, "%d", price_all);
	sleep(2);
	fclose(fp);
}

int main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	system("mode con:cols=113 lines=34");

	do
	{
		Mouse_Control();
		Setting_Consol();
	}while(play == 0);	

	return 0;
}
