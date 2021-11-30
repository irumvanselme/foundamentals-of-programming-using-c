int clientMeterNo;
int theClintsUnit = 0;
int todaydate;
int clientCategoryId;
static int getThePayedPrice();
struct tempClient{
 char customerNames[200];
 int meterNo;
 int customerId;
 char categoryName[200];
 int CategoryId;
}tempC;
int umujinya1;
int umujinya2;
int gotIt = 0;
void getTheIncomingClient(int price){
	FILE *clientFile;
	FILE *tempCategories;
	struct tempClient tempC;
	struct Category category;
	clientFile = fopen("files/clientFile.dat","rb");
	struct Customer customer;

	while(fread(&customer,sizeof(struct Customer),1,clientFile)){
		int ff,kk;
		if(clientMeterNo == customer.meter_no){
			printf("    Your Names are   : %s \n",customer.customer_name);
			printf("\n\n    Confirm if it is you [1/0]  :");
			scanf("%d",&ff);
			if(ff == 1){
				strcpy(tempC.customerNames,customer.customer_name);
				tempC.meterNo = customer.meter_no;
				tempC.customerId = customer.id;
				umujinya1 = tempC.meterNo;
				umujinya2 = tempC.customerId;
				clientCategoryId = customer.category_id;
				int my2k;
				tempCategories = fopen("files/categoriesFile.dat","rb");
				while(fread(&category,sizeof(struct Category),1,tempCategories)){
					if(category.id == customer.category_id){
						my2k = customer.category_id;
						strcpy(tempC.categoryName,customer.customer_category);
						break;

					}
				}
				fclose(tempCategories);
				gotIt = 1;
                price = getThePayedPrice(price);
                time_t t;
                time(&t);
				int tax = price * 18/100; 
				int tot = tax+price;
				char time[100];
				
				strcpy(time,ctime(&t));
				printf("\n\n\t\t\t     REG RECIPT   \n\n");
				printf("\t+---------------------------------------------------------------\n");
				printf("\t|\t\t Names         :  %s \n", tempC.customerNames);
				printf("\t|\t\t Category      :  %s \n", tempC.categoryName);
				printf("\t|\t\t PRICE 100%%    :  %d Frw\n", price);
				printf("\t|\t\t TAX   18%%     :  %d Frw\n", tax);
				printf("\t|\t\t TOTAL PRICE   :  %d Frw\n", tot);
				printf("\t|\t\t Current Time  :  %s",time);
				printf("\t+---------------------------------------------------------------\n");
				printf("\n\n");
			}
			kk++;
			break;
		}
	}
	fclose(clientFile);
}
/*void getReport(int price){
	int tax = price * 18/100; 
	int tot = tax+price;
	printf("\n\n\t\t\t THE PRICE  \n\n");
	printf("\t\t\t Names   ====================>  %s \n", tempC.customerNames);
	printf("\t\t\t Category ===================>  %s \n", tempC.categoryName);
	printf("\t\t\t PRICE  < 100 > =============>  %d \n", price);
	printf("\t\t\t TAX   < 18 > ===============>  %d \n", tax);
	printf("\t\t\t TOTAL PRICE ================>  %d \n\n\n", tot);
}*/
static void insertIntoSelling(int thePrice,int date){
	struct tempClient tempC;
    time_t t;
    time(&t);
	struct Selling selling;
	int on = 0;
	FILE *sellingElectricity;
	sellingElectricity = fopen("files/sellingFile.dat","ab+");
	while(fread(&selling,sizeof(struct Selling),1,sellingElectricity)){
		on++;
	}
	selling.selling_id = on+1;
	selling.customer_id = umujinya2;
	selling.meter_number = umujinya1;
	selling.total_units = theClintsUnit;
	selling.sold_month = date;
	strcpy(selling.dateinText,ctime(&t));
	selling.total_amount = thePrice;
	fwrite(&selling,sizeof(struct Selling),1,sellingElectricity);
	fclose(sellingElectricity);
}
void insertIntoClinetMeter(){
	struct tempClient tempC;
	struct CustomerMeter customersmeter;
	int on = 0;
	FILE *CustomerMeterFile;
	CustomerMeterFile = fopen("files/customerMeterFile.dat","ab+");
	while(fread(&customersmeter,sizeof(struct CustomerMeter),1,CustomerMeterFile)){
		on++;
	}
	customersmeter.id = on+1;
	customersmeter.customer_id = tempC.customerId;
	customersmeter.meter_no = tempC.meterNo;
	fwrite(&customersmeter,sizeof(struct CustomerMeter),1,CustomerMeterFile);
	fclose(CustomerMeterFile);
}
static void sellElectricity(){
	printf("   Enter the meter number of the client   :  ");
	scanf("%d",&clientMeterNo);
	printf("   How many units do you want             :  ");
	scanf("%d",&theClintsUnit);
	printf("   In which Month are we    [1 - 12]      :  ");
	scanf("%d",&todaydate);
	int price;
	getTheIncomingClient(theClintsUnit);
	if(gotIt == 1){
		insertIntoSelling(price,todaydate);
		insertIntoClinetMeter(price);
		//getReport(price);
	}else if(gotIt == 0){
		printf("\n\t\tYour Meter Number does not exist try again  : \n\n");
	}
	printf("\nThank You\n");
}
