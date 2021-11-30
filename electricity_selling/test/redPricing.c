#include<stdio.h>
struct Price
{
	int id;
	int category_id;
	int minimumm;
	int maximum;
	int price;
};
int main(){
    struct Price price;
    FILE *myFile;
    myFile = fopen("../files/pricingFile.dat","rb+");
    while(fread(&price,sizeof(struct Price),1,myFile)){
        printf("\n\t%d \t%d \t%d \t%d \t%d",price.id, price.category_id,price.minimumm,price.maximum,price.price);
    }
    printf("\n");
    fclose(myFile);
    return 0;
}
