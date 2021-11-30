;enum Categories{ Residential, NonResidentials, TelecomTowers, WaterTreatment, plantsAndWaterPumpingStations, Hotels, HealthFacilities, Broadcasters};
char *categoriesNames[8] = {"Residential","Non Residentials","Telecom Towers","Water Treatment","plants And Water Pumping Stations","Hotels","Health Facilities","Broadcasters"};
int categoryIds[10] = {1,1,1,2,2,3,4,5,6,7};
int minimums[10] = {0,15,50,0,100,0,0,0,0,0};
int maxmums[10] = {15,50,1000,100,1000,1000,1000,1000,1000,1000};
int prices[10] = {89,182,210,204,222,185,126,126,192,184};
static void theMainFnFile()
{
	FILE *categoriesFile;
	FILE *pricingFile;
	pricingFile = fopen("files/pricingFile.dat","wb+");
	categoriesFile = fopen("files/categoriesFile.dat","wb+");
	fclose(pricingFile);
	fclose(categoriesFile);



	struct Category myCategory;
	struct Price myPrice;




	int nIt = 0;
	//the categories file
	/*=========================   the begining of category   =========================*/
	categoriesFile = fopen("files/categoriesFile.dat","rb+");
	

	while(fread(&myCategory,sizeof(struct Category),1,categoriesFile)){
		nIt++;
	}
	fclose(categoriesFile);



	if(nIt == 0){
		enum Categories category;
		
		categoriesFile = fopen("files/categoriesFile.dat","ab+");
		for(int i = Residential; i < Broadcasters;i++){
			myCategory.id = i+1;
			strcpy(myCategory.category_name,categoriesNames[i]);
			fwrite(&myCategory,sizeof(struct Category),1,categoriesFile);
		}
		fclose(categoriesFile);
	}


	/*=========================   the end of category   =========================*/





	/*=========================   the begining of pricing   =========================*/


	pricingFile = fopen("files/pricingFile.dat","rb+");

	nIt = 0;

	while(fread(&myPrice,sizeof(struct Price),1,pricingFile)){
		nIt++;
	}

	fclose(pricingFile);

	pricingFile = fopen("files/pricingFile.dat","ab+");

	if(nIt == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			myPrice.id = i+1;
			myPrice.category_id = categoryIds[i];
			myPrice.minimumm = minimums[i];
			myPrice.maximum = maxmums[i];
			myPrice.price = prices[i];
			fwrite(&myPrice,sizeof(struct Price),1,pricingFile);
		}
	}

	fclose(pricingFile);

	/*=========================   the end of pricingg   =========================*/


	
}
