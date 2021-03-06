// thsi function returns the amount last for a given price 


int getLastPrice(int produceIt,int minarray[],int maxarray[],int pricearray[],int thesizemins,int thesizemax,int thesizeprice){
    int lastprice = 0,i,x;
    x = thesizemins / sizeof(minarray[0]);
    int k = produceIt;
    if((thesizemins / sizeof(minarray[0])) == (thesizemax / sizeof(maxarray[0])) && (thesizemax / sizeof(maxarray[0])) == (thesizeprice / sizeof(pricearray[0]))){
        for(i = 0 ; i < x;i++){
            if(k > minarray[i] && k <= maxarray[i]){
                lastprice +=  (k - minarray[i]) *  pricearray[i];
                break; 
            }else{
                lastprice += (maxarray[i] - minarray[i])*pricearray[i];
            }
        }
    }else{
        printf("\nError in the data given !! \n");
    }
    return lastprice;
}
/*=====                 here is the function that calculates          */
static int getTheDataPayedPrice(int unitsNeeded,int unitsUsedInMont,int minarray[],int maxarray[],int pricearray[],int thesizemins,int thesizemax,int thesizeprice){
    int k = unitsNeeded + unitsUsedInMont;
    int payedAmount = getLastPrice(unitsUsedInMont, minarray, maxarray, pricearray, thesizemins, thesizemax, thesizeprice);
    int lastprice = getLastPrice(k,minarray,maxarray,pricearray,thesizemins,thesizemax, thesizeprice);
    if(payedAmount != 0){
        lastprice -= payedAmount;
    }else{
        lastprice = getLastPrice(unitsNeeded ,minarray,maxarray,pricearray,thesizemins,thesizemax, thesizeprice);
    }
    return lastprice;
}
static int getThePayedPrice(int needed){

    struct Price price;
    
    // =========== here we are goimg to get the requiremets of the function   :===============
    // ============the units needed   ===================
    
    int unitsneeded = 0;
    unitsneeded = needed;
    
    
    // ============the previusly used units   ===================
    
    int meterNo = clientMeterNo;
    int month = todaydate;
    int prevUnits = 0,j;

    FILE *sellingFile;
    struct Selling selling;
    sellingFile = fopen("files/sellingFile.dat","rb");
    while(fread(&selling,sizeof(struct Selling),1,sellingFile)){
        if(selling.meter_number == clientMeterNo && selling.sold_month == month){
            prevUnits += selling.total_units;
            j++;
        }
    }
    if(j == 0){
        prevUnits = 0;
    }
    fclose(sellingFile);
    
    
    
    // ============  the three arrays      ===================
    
    // step 1 get the category id
    int categoryId = clientCategoryId;
    // visit the pricingCate
    int i = 0;
    int lastprice;
    int mins[5],maxs[5],prices[5];
    FILE *pricingFile;
    pricingFile = fopen("files/pricingFile.dat","rb+");
    while(fread(&price,sizeof(struct Price),1,pricingFile)){
        if(price.category_id == categoryId){
            mins[i] = price.minimumm;
            maxs[i] = price.maximum;
            prices[i] = price.price;
            i++;
        }
    }
    lastprice = getTheDataPayedPrice(unitsneeded,prevUnits,mins,maxs,prices, sizeof(mins), sizeof(maxs), sizeof(prices));
    return lastprice;
}
