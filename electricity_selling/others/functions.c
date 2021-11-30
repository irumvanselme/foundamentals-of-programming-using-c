/*========================  main functions     ====================*/
void insertIntoSelling(int thePrice,int date);

char passcode[100];


static void openAllFile(){
	FILE *categoriesFile;
	FILE *pricingFile;
	pricingFile = fopen("files/pricingFile.dat","wb+");
	categoriesFile = fopen("files/categoriesFile.dat","wb+");
	fclose(pricingFile);
	fclose(categoriesFile);

}


static void logInForm(){

	printf("\n\n\n\t       Welcome to the Electricity Selling Bill !!!    \n");
	printf("\t_______________________________________________________\n\n");
	printf("\t\tEnter your Passcode           : ");
	scanf("%s",passcode);
}

static int adminDashMenu(){
	int responce;
	printf("\t       Welcometo the admin pannel Here is our menu \n\n\n\n");
	printf("\n\t    I.0 USER MANAGMENT   \n");
	printf("\t     1. Insert a new user \n");
	printf("\t     2. view users \n");
	printf("\n\t    II.0 METER MANAGMENT   \n");
	printf("\t     3. Register a new meter \n");
	printf("\t     4. View availabe meters \n");
	printf("\n\t    III.0 REGISTRATION  \n");
	printf("\t     5. Insert a new client \n");
	printf("\t     6. View Available users \n");
	printf("\n\n\t     7. View Sellings done  \n");
	printf("\n\n_____________________________________\n\n");
	printf("\t     Enter your choice      : ");
	scanf("%d",&responce);
	return responce;
}




/*========================================  admin functions ============================================*/





static void insertANewUser(){
	int n = 0;
	FILE *usersFile;

	struct User user;

	usersFile = fopen("files/usersFile.dat","ab+");
	while(fread(&user,sizeof(struct User),1,usersFile)){
		n++;
	}
	fclose(usersFile);

	usersFile = fopen("files/usersFile.dat","ab+");


	char temp[100];
	user.user_id = n+1;
	printf("  Welcome to insert a new user   :-  \n\n");
	printf(" Enter the user id            : %d \n",user.user_id);
	printf(" Enter the user id card no    : ");
	scanf("%s",user.user_ID_card_no);
	printf(" Enter the Provience          : ");
	scanf("%s",user.Provience);
	printf(" Enter the District           : ");
	scanf("%s",user.District);
	printf(" Enter the Sector             : ");
	scanf("%s",user.Sector);
	printf(" Enter the email or tel       : ");
	scanf("%s",user.emailOrTel);
	printf(" Enter the user names         : ");
	scanf("%s",user.user_name);
	printf(" Enter the user category      : ");
	scanf("%s",user.user_category);
	printf(" Set a pass code              : ");
	scanf("%s",user.passcode);
	fwrite(&user,sizeof(struct User),1,usersFile);

	fclose(usersFile);

}


static void getAllUsers(){

	struct User user;

	FILE *usersFile;

	usersFile = fopen("files/usersFile.dat","rb+");

	printf("\n\n       HERE IS THE USERS OF YOUR SYSYTEM     \n\n");

	while(fread(&user,sizeof(struct User),1,usersFile)){
		printf("\tUser id [%d] \n",user.user_id);
		printf("\t    User Name      : %s \n",user.user_name);
		printf("\t    User ID no     : %s \n",user.user_ID_card_no);
		printf("\t    User Provience : %s \n",user.Provience);
		printf("\t    User District  : %s \n",user.District);
		printf("\t    User Sector    : %s \n",user.Sector);
		printf("\t    User email     : %s \n",user.emailOrTel);
		printf("\t    User Category  : %s \n",user.user_category);
		printf("\n");
	}
	printf("\n\n\n");
	fclose(usersFile);


}


static void registerNewMeter(){

	int n = 0;

	FILE *metersFile;

	struct Meter meter;

	metersFile = fopen("files/metersFile.dat","rb+");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		n++;
	}
	fclose(metersFile);



	metersFile = fopen("files/metersFile.dat","ab");
	meter.meter_id = n+1;


	printf("  Welcome to register a new meter   :-  \n\n");
	printf(" Enter the meter id            : %d\n",meter.meter_id);

	printf(" Enter the meter meter number  : ");
	scanf("%d",&meter.meter_no);
	int temp;
	meter.meter_status = 0;

	fwrite(&meter,sizeof(struct Meter),1,metersFile);

	fclose(metersFile);

}




static void viewAvailableMeter(){
	FILE *metersFile;

	struct Meter meter;

	metersFile = fopen("files/metersFile.dat","rb");

	printf("\n\n       HERE IS THE METERS IN YOUR SYSTEM     \n\n\n");
	printf("\tid\tmtrNo\tStatus\n\n");

	while(fread(&meter,sizeof(struct Meter),1,metersFile)){

		printf("\t%d",meter.meter_id);
		printf("\t%d",meter.meter_no);
		if(meter.meter_status == 1){
			printf("\tActivated");
		}else{
			printf("\tUnactivated");
		}
		printf("\n");
	}
	printf("\n\n\n");

	fclose(metersFile);
}
//        the getting the category    

int getClientCategory(){
	struct Category myCategory;
	int myRealOption;
	FILE *categoriesFile;
	printf("\n\n     Select the Client Category   \n\n");
	categoriesFile = fopen("files/categoriesFile.dat","rb+");
	while(fread(&myCategory,sizeof(struct Category),1,categoriesFile)){
		printf(" %d ",myCategory.id);
		printf(".%s \n",myCategory.category_name);
	}
	fclose(categoriesFile);
	printf("\n  Write your option      :  ");
	scanf("%d",&myRealOption);
	return myRealOption;
}





static void registerNewClient()
{
	FILE *clientFile;
	FILE *metersFile;
	int didIt = 0;
	struct Customer customer;


	struct  Meter meter;

	clientFile = fopen("files/clientFile.dat","rb");
	while(fread(&customer,sizeof(struct Customer),1,clientFile))
	{
		didIt++;
	}
	fclose(clientFile);

	//                       get the meter number 

	int meterNo = 0; 
	int meterId_cl;

	metersFile = fopen("files/metersFile.dat","rb");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		if(meter.meter_status == 0){
			meterNo = meter.meter_no;
			meterId_cl = meter.meter_no;
			break;
		}
	}
	fclose(metersFile);


	//                       get the category



	if(meterNo != 0){
		int optionOff = 0;

		clientFile = fopen("files/clientFile.dat","ab");
		
		customer.id = didIt+1;
		printf("The Client id is                       : %d \n", customer.id);
		printf("Enter the customer Name                : ");
		scanf("%s",customer.customer_name);
		printf("Enter the customer ID no               : ");
		scanf("%s",customer.customer_ID_card_no);
		printf("Enter the customer Provience           : ");
		scanf("%s",customer.Provience);
		printf("Enter the customer District            : ");
		scanf("%s",customer.District);
		printf("Enter the customer Sector              : ");
		scanf("%s",customer.Sector);
		printf("Enter the customer email Or Tel        : ");
		scanf("%s",customer.emailOrTel);
		printf("Enter the month of today               : ");
	    int mnt;
		scanf("%d",&mnt);
	    insertIntoSelling(2,mnt);
		optionOff = getClientCategory();
		optionOff--;
		activateMeter(meterId_cl,meterNo);
		printf("Enter the customer customer category   : %s \n",categoriesNames[optionOff]);
		printf("Enter the customer Meter number        : %d \n",meterNo);
		customer.category_id = optionOff+1;
		customer.meter_no = meterNo;
		strcpy(customer.customer_category,categoriesNames[optionOff]);
		printf("\n");

		fwrite(&customer,sizeof(struct Customer),1,clientFile);
		fclose(clientFile);
	}else{
		printf("     Errorr in Inserting a file    : -\n");
		printf("     It may be because of    \n       1. Not available meter \n\n\n");
	}
}


static void viewAllClients()
{

	FILE *clientFile;
	clientFile = fopen("files/clientFile.dat","rb");
	struct Customer customer;

	while(fread(&customer,sizeof(struct Customer),1,clientFile)){
		printf("\tClient id [%d]\n", customer.id);
		printf("\t    customer Name          : %s \n",customer.customer_name);
		printf("\t    customer ID no         : %s \n",customer.customer_ID_card_no);
		printf("\t    Customer Provience     : %s \n",customer.Provience);
		printf("\t    Customer District      : %s \n",customer.District);
		printf("\t    Customer Sector        : %s \n",customer.Sector);
		printf("\t    Customer email/Tel     : %s \n",customer.emailOrTel);
		printf("\t    Customer Category      : %s \n",customer.customer_category);
		printf("\t    Customer Meter number  : %d \n",customer.meter_no);
		printf("\n\n");
	}
	fclose(clientFile);
}

int getIfUserExist(){

	struct User user;

	FILE *usersFile;

	usersFile = fopen("files/usersFile.dat","rb+");
	int f = 0;
	while(fread(&user,sizeof(struct User),1,usersFile)){
		if(strcmp(user.passcode,passcode) == 0){
			f++;
		}
	}
	fclose(usersFile);
	if(f == 0){
		return f;
	}else{
		f = 1;
		return f;
	}

}
static int getusersOpt(){
	int opt;
	printf("\n\n       WELCOME TO USERS PANNEL     \n\n");
	printf("\n\n         HERE IS THE MENU       \n");
	printf("    1. Sell  Electricity      \n");
	printf("    2. Quit           \n");
	printf("\n\n   Enter the choice     : ");
	scanf("%d",&opt);
	return opt;
}
static void viewAllSelling(){
    printf("\n\n       HERE ARE THE RECIPT AT THE REG COMPANY   \n\n");
    FILE *mySellingFile;
    struct Selling selling;
    mySellingFile = fopen("files/sellingFile.dat","rb");
    while(fread(&selling,sizeof(struct Selling),1,mySellingFile)){
        int tax = selling.total_amount * 18/100;
        int tot = tax + selling.total_amount;
        printf("\tSelling Id  [%d] \n",selling.selling_id);
        printf("\t   Customer Id   : %d\n",selling.customer_id);
        printf("\t   Meter Number  : %d\n",selling.meter_number);
        printf("\t   Total Units   : %d\n",selling.total_units);
        printf("\t   Price         : %d\n",selling.total_amount);
        printf("\t   Tax           : %d\n",tax);
        printf("\t   Selling Date  : %s",selling.dateinText);
        printf("\t   Total Amount  : %d\n",tot);
        printf("\n\n\n");
    }
    fclose(mySellingFile);
}



















