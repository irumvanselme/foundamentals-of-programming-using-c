#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/*
int hours, minutes, seconds, day, month, year;
time_t now;
time(&now);
struct tm *local = localtime(&now);
hours = local->tm_hour;
minutes = local->tm_min;         
seconds = local->tm_sec;         
day = local->tm_mday;            
theMonth = local->tm_mon + 1;       
year = local->tm_year + 1900;

*/


#include "others/structures.c"
#include "others/activationMeter.c"
#include "others/pricingCate.c"
#include "others/sellIt.c"
#include "others/functions.c"
#include "others/lastDay.c"

int main()

{
	theMainFnFile();
	system("clear");
	int officialOption;
	int qn;
	logInForm();
	if( strcmp(passcode,"admin123") == 0 ){
		do{
			system("clear");
			if(officialOption == 1){
				insertANewUser();
			}else if(officialOption == 2){
				getAllUsers();
			}else if(officialOption == 3){
				registerNewMeter();
			}else if(officialOption == 4){
				viewAvailableMeter();
			}else if(officialOption == 5){
				registerNewClient();
			}else if(officialOption == 6){
				viewAllClients();
			}else if(officialOption == 7){
				viewAllSelling();
			}
			printf("    Do you want to continue [1/0]  :");
			scanf("%d",&qn);
			if(qn == 0){
				officialOption = -1;
			}else{
				system("clear");
				officialOption = adminDashMenu();
			}
		}while(officialOption != -1);
	}else{
		int usersOption = getIfUserExist(passcode);
		system("clear");
		if(usersOption == 1){
			int theoffusersopt = getusersOpt();
			
			if(theoffusersopt == 1){
				system("clear");
				sellElectricity();
			}
		}else{
			printf("Please Wait a moment ...\n");
		}
	}
	return 0;
}
