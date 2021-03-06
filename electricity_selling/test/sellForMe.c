#include<stdio.h>


// thsi function returns the amount last for a given price 


int getLastPrice(int produceIt,int minarray[],int maxarray[],int pricearray[],int thesizemins,int thesizemax,int thesizeprice){
    int lastprice = 0,x,y,z,i,nice;
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

// thsi function is the mother function   

int getMyLastPrice(int unitsNeeded,int unitsUsedInMont,int minarray[],int maxarray[],int pricearray[],int thesizemins,int thesizemax,int thesizeprice){
    int k = unitsNeeded + unitsUsedInMont;
    
    int payedAmount = getLastPrice(unitsUsedInMont, minarray,maxarray,pricearray,thesizemins,thesizemax, thesizeprice);
    int lastprice = getLastPrice(k,minarray,maxarray,pricearray,thesizemins,thesizemax, thesizeprice);
    
    lastprice -= payedAmount;
    return lastprice;
}
int main(){
    int mins[] = {0,15,50};
    int maxs[] = {15,50,1000};
    int prices[] = {89,182,210};
    int price = getMyLastPrice(1,15,mins,maxs,prices,sizeof(mins),sizeof(maxs),sizeof(prices));
    printf("\n\n\t\t\t\t%d\n",price);
    return 0;
}
