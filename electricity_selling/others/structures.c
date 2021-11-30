
struct User
{
	int user_id;
	char user_name[100];
	char user_ID_card_no[16];
	char Provience[100];
	char District[100];
	char passcode[100];
	char Sector[100];
	char emailOrTel[200];
	char user_category[30];
};
struct Customer
{
	int id;
	char customer_name[100];
	char customer_ID_card_no[16];
	char Provience[100];
	char District[100];
	char Sector[100];
	char emailOrTel[200];
	char customer_category[20];
	int meter_no;
	int category_id;
};
struct Meter
{
	int meter_id;
	int meter_no;
	int meter_status;
};
struct Category
{
	int id;
	char category_name[100];
};
struct Price
{
	int id;
	int category_id;
	int minimumm;
	int maximum;
	int price;
};
struct Selling
{
	int selling_id;
	int customer_id;
	int meter_number;
	int total_units;
	int sold_month;
	char dateinText[200];
	int total_amount;
};
struct CustomerMeter
{
	int id;
	int customer_id;
	int meter_no;
}
