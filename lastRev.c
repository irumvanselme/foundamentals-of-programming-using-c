/*#include<stdio.h>
#include<stdbool.h>

#define anselme "Anselme"
void main(){
    bool test = false;
    int num = 0x43234;
    if(!test)
        printf("This is true \n");
    else
        printf("This is not true \n");
    printf("%s\n",anselme);
}
#include<stdio.h>
enum week{Mon=10, Tue, Wed, Thur, Fri=10, Sat=16, Sun};
enum day{Mond, Tues, Wedn, Thurs, Frid=18, Satu=11, Sund};
int main() {
printf("The value of enum week: %d\t%d\t%d\t%d\t%d\t%d\t%d\n\n",Mon , Tue,
Wed, Thur, Fri, Sat, Sun);
printf("The default value of enum day: %d\t%d\t%d\t%d\t%d\t%d\t%d\n",Mond ,
Tues, Wedn, Thurs, Frid, Satu, Sund);
return 0;
}

#include<stdio.h>
int main() {
    int nums[] = {23,54,65,12,90,43};
    int k = sizeof(nums)/sizeof(int);
    printf("%d \n",k);
return 0;
}
*/
#include <stdio.h>
int main()
{
int var = 5;
printf("Value: %d\n", var);
printf("Address: %u \n", &var); //Notice, the ampersand(&) before var.
return 0;
}
