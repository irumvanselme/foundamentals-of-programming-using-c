;

static void activateMeter(int id, int meterNumber)
{
   int k = 0;
   struct Meter meter;
   struct Meter metersCollection[k];
   FILE *meterfile;
    meterfile = fopen("files/metersFile.dat", "rb+");
        while(fread(&meter, sizeof(struct Meter),1, meterfile)){
            k++;
    }
    fclose(meterfile);
    

   meterfile=fopen("files/metersFile.dat","rb");
   fread(&metersCollection,sizeof(struct Meter),k,meterfile);
   fclose(meterfile);
   for(int i=0;i<1000;i++){
   if(metersCollection[i].meter_status==0){
      metersCollection[i].meter_status=1;
         /*  printf("      %d\n",metersCollection[i].status); */
   printf("        Customer meter number is : %d \n", metersCollection[i].meter_no);
   break;
   }
   }
       meterfile=fopen("files/metersFile.dat","wb");
       fwrite(&metersCollection,sizeof(struct Meter),k,meterfile);
   fclose(meterfile);
   
/*    FILE *metersData;
    int i = 0;
    struct Meter meter;
    struct Meter meters[1000];
    
    
    metersData = fopen("files/metersFile.dat", "rb+");
    while(fread(&meter, sizeof(struct Meter),1, metersData)){
        meters[i].meter_id = meter.meter_id;
        meters[i].meter_no = meter.meter_no;
        meters[i].meter_status = meter.meter_status;
        i++;
    }
    fclose(metersData);
    
    
    
    for(int j = 0; j < i ; j++){
        if(meters[i].meter_no == meterNumber){
            meters[i].meter_status = 1;
        }
    }
    metersData = fopen("files/metersFile.dat", "wb");
    fwrite(&meter, sizeof(struct Meter),1, metersData);
    fclose(metersData);
    metersData = fopen("files/metersFile.dat", "ab");
    for(int j = 0; j < i ; j++){
        meter.meter_id = meters[i].meter_id;
        meter.meter_no = meters[i].meter_no;
        meter.meter_status = meters[i].meter_status;
        fwrite(&meter, sizeof(struct Meter),1, metersData);
    }
    fclose(metersData);
 */   
/*    struct Customer customer;
    struct  CustomerMeter customerMeter;
    struct Meter meter;
    FILE *metersData;
    metersData = fopen("files/metersFile.dat", "rb+");
    while(fread(&meter, sizeof(struct Meter),1, metersData)){
        if(meter.meter_id == id-1){
            meter.meter_status = 1;
            meter.meter_id = id;
            meter.meter_no = meterNumber;
            fwrite(&meter, sizeof(struct Meter),1, metersData);
            break;
        }
    }
    fclose(metersData);*/
}

