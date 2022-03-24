#include <stdio.h>
#include <string.h>

const int MENU_SIZE = 6;
const int THRESHOLD = MENU_SIZE/3;
void printMenu(char menu[][50],int size){
	printf("Menu\n");
	for(int i = 0; i<size; i++){
		printf("%d-%s, ",i+1,menu[i]);
	}
	printf("\n");

}

void whatToEat(char menu[][50]){

	int countFood[MENU_SIZE];
	for(int i = 0; i<MENU_SIZE;i++) countFood[i] = 0;

	int numberOfPeople;
	printf("How many people are you guys ? :)\n");
	scanf("%d",&numberOfPeople);

	for(int i=0; i<numberOfPeople;i++){
		printMenu(menu,MENU_SIZE);
		printf("Person %d, Please select the one you want to order.\n",i+1);
		int orderNo = 0;
		scanf("%d",&orderNo);
		if (orderNo>MENU_SIZE or orderNo<1){
			i = i -1;
			printf("Please select the proper order!\n");
		}
		else{
			countFood[orderNo-1]+=1;
			printf("------------------------------------------------------\n");
		}


	}
	printf("Here what you guys have selected : \n");
	for(int i = 0; i<MENU_SIZE;i++) printf("%s : %d, ",menu[i],countFood[i]);
	printf("\n");
	int count = 0;
	for(int i = 0; i<MENU_SIZE;i++)
		if(countFood[i]>=THRESHOLD)count++;

	int lastIndex = 0;
	char shortMenu[count][50];
	for(int i = 0; i<MENU_SIZE;i++) 
	{
		if(countFood[i]>=THRESHOLD){
			strcpy(shortMenu[lastIndex] ,  menu[i]);
			lastIndex++;
		}
	}

	int sizeOfSM = sizeof(shortMenu)/sizeof(shortMenu[0]);
	if(sizeOfSM == 1){
		printf("Winner food is : %s\n",shortMenu[0]);

	}
	else if(sizeOfSM > 1){
		int countFoodSM[sizeOfSM];
		for(int i = 0; i<sizeOfSM;i++) countFoodSM[i] = 0;
		
		int maxFoodIndex = 0;
		int  maxFoodCount = 0;
		printf("\n--------------Second Tour!---------------\n");
		
		for(int i=0; i<numberOfPeople;i++){
			printMenu(shortMenu,sizeOfSM);
			printf("Person %d, Please select the one you want to order.\n",i+1);
			int orderNo = 0;
			scanf("%d",&orderNo);
			if (orderNo>sizeOfSM or orderNo<1){
				i = i -1;
				printf("Please select the proper order!\n");
			}
			else{
				countFoodSM[orderNo-1]+=1;
				if(countFoodSM[orderNo-1] > maxFoodCount) maxFoodIndex = orderNo-1;
				printf("------------------------------------------------------\n");
			}


		}
		printf("Here what you guys have selected : \n");
		for(int i = 0; i<sizeOfSM;i++) printf("%s : %d, ",shortMenu[i],countFoodSM[i]);
		printf("\n");
		printf("Winner food is : %s\n",shortMenu[maxFoodIndex]);

	}
	else{
	printf("You are eating at home/dorm today!\n");
	}

}


int main(){
	char menu[MENU_SIZE][50] = {"Kebap","Burger","Pasta","Lahmacun","Salad","Other"};
        whatToEat(menu);
}




