// Hey guys , its Faisal's Program : TITLE >> {}
// Bank management system >>>>>>>
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
using namespace std;
//==============================================================================================================================================================================================
// sub-functions Declaration
void waitIcon();
char backButton();
long long int cashLaw();
void showAll();
int showSin();
void waitplusProcessingIcon();
int accNotFound();
void initializeplusOne();
// functions Declaration
int searchAccount();
int transactions();
int addAccount();
int updateAccount();
int deleteAccount();
int total = 0;
//==============================================================================================================================================================================================
class Customer
{
  
  private:
  string name;
  long double precash;
  static string dateOfAcCreation;
  public:
  long long int account_number;
  void inputDetails(string name, long long int account_number, long double precash)
  {
    this->name = name;
    this->account_number = account_number;
    this->precash = precash;
    dateOfAcCreation = " 25 09 24 ";
  }
  void updateAttributes(string name, long double precash, long long int account_number, char n)
  {
    if (n == '1')
      this->name = name;
    else if (n == '2')
      this->precash = precash;
    else
      this->account_number = account_number;
  }
  //=====================================================================================================================================================================
  void deposit(long double precash, char n)
  {
    if (n == '1')
    {
      (this->precash += precash);
    }
    else if (this->precash >= precash && n == '2')
    {
      (this->precash -= precash);
    }
  }
  //===========================================================================================================================================================
  void display()
  {
    cout << endl
         << "\t\t\t  Name : >> " << name;
    cout << endl
         << "\t\t\t  A/C NO. : " << account_number;
    cout << endl
         << "\t\t\t  Total_Cash : " << precash;
    cout << endl
         << "\t\t\t  DO/AC : " << dateOfAcCreation;
  }
  //==============================================================================================================================================================================================

} customer[30];
//==============================================================================================================================================================================================
// global variables
int size = sizeof(customer) / sizeof(Customer);
string Customer ::dateOfAcCreation = " 25 09 2024";
int cross = 0;
//==============================================================================================================================================================================================

void subDeposite(long double cash, long long int account_number)
{
  char n = '1';
  for (int i = 0; i < total; i++)
  {
    if (account_number == customer[i].account_number)
    {
      customer[i].deposit(cash, n);
    }
  }
}
void subWithdraw(long double cash, long long int account_number)
{
  char n = '2';
  for (int i = 0; i < total; i++)
  {
    if (account_number == customer[i].account_number)
    {
      customer[i].deposit(cash, n);
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------------------

int main(void)
{
  // OOPs operationa>>>>>>>>>>

  cout << endl
       << endl
       << endl
       << "\t\t\t\t\t \5  Welcome to Vishal Bank \5 " << endl
       << endl;
  int close, count = 0;
  char *step = new char;
  string email, password;
start:
  count++;
  if (count > 3)
  {
    for (int i = 1; i <= 7; i++)
    {
      cout << "Warning..........!!"
           << "\t\t\t  You exceed limit...." << endl;

      sleep(1);
    }
    return 1;
  }

  cout << endl
       << "\t\t\t Login Account >> " << endl;
  cout << "\t\t\t Enter Bank Password: ";
  cin >> password;
  cout << "\t\t\t Enter your Email : ";
  cin >> email;

  if (password != "4633" && (email == "vishal@gmail.com"))
  {
    cout << endl
         << endl
         << "\t\t\t You entered Wrong password" << endl;
    waitIcon();
    system("CLS");
    goto start;
  }

  else if (password == "4633" && (email != "vishal@gmail.com"))
  {
    cout << endl
         << endl
         << "\t\t\t You entered Wrong email" << endl;
    waitIcon();
    system("CLS");
    goto start;
  }
  else if (password != "4633" && (email != "vishal@gmail.com"))
  {
    cout << endl
         << "\t\t\t No identity match.... " << endl;
    waitIcon();
    system("CLS");
    goto start;
  }
  else
  {
    cout << endl
         << endl;
    cout << "\t\t\t Press 1 to continue : ";
    cout << "\t\t\t press 2 to close Window : "
         << endl
         << endl
         << "\t\t\t >>> ";
    *step = getch();
    if (*step == '2')
      return 0;
    system("CLS");
  }

options:
  cout << endl
       << endl
       << endl
       << "\t\t\t<<=<=<=<=<=[ WELCOME To HOME WINDOW ]=>=>=>=>=>> " << endl
       << endl
       << endl;

  cout << "\t\t\t \4  Press 1 to < Add > Account << \4 >>" << endl
       << endl;
  cout << "\t\t\t \4  Press 2 to < Search > Account << \4 >>" << endl
       << endl;
  cout << "\t\t\t \4  Press 3 to < Update > Account << \4 >>" << endl
       << endl;
  cout << "\t\t\t \4  Press 4 to < Delete > Account << \4 >>" << endl
       << endl;
  cout << "\t\t\t \4  Press 5 to < transaction > Cash << \4 >>" << endl
       << endl;
  cout << "\t\t\t \4  Press 6 to < Log out > Page << \4 >>" << endl
       << endl
       << endl;

  char select;
  cout << "\t\t\t    >> ";
  select = getch();

  switch (select)
  {
  case '1':
    system("CLS");
    addAccount();
    system("CLS");
    goto options;
    break;
  case '2':
    system("CLS");
    searchAccount();
    system("CLS");
    goto options;
    break;
  case '3':
    system("CLS");
    updateAccount();
    system("CLS");
    goto options;
    break;
  case '4':
    system("CLS");
    deleteAccount();
    system("CLS");
    goto options;
    break;
  case '5':
    system("CLS");
    transactions();
    system("CLS");
    goto options;
    break;
  case '6':
    system("CLS");
    goto start;
    break;
  default:
    system("CLS");
    goto options;
    break;
  }

  return 0;
}
// sub - functions >>>>>>>>>>>>>>>
// void  subdeleteAccount()
// {
//   long long int accountNumber;
//   cout << "Enter Desired Account number to (delete) : ";
//   cin >> accountNumber;
//   for (int i = 0; i < total; i++)
//   {
//     if (accountNumber == customer[i].account_number)
//     {
//        for (int j = i; j < total; j++)
//       {
//         customer[j].name = customer[j + 1].name;
//         customer[j].account_number = customer[j + 1].account_number;
//         customer[j].precash = customer[j + 1].precash;
//         customer[j].dateOfAcCreation = " 25 09 24 ";
//         cout << " HELLO ";
//         total--;
//         break;
//      }
//     }
//   } 
// }
int accNotFound()
{
  system("CLS");
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t                       Processing";
  for (int i = 1; i <= 3; i += 1)
  {
    cout << ".";
    sleep(1);
  }
  system("CLS");
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t                        [ Not found ]";
  sleep(1);
  return -1;
}
void waitplusProcessingIcon()
{
  system("CLS");
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t                       Processing";
  for (int i = 1; i <= 3; i += 1)
  {
    cout << ".";
    sleep(1);
  }
  system("CLS");
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t                        [ DONE ]";
  sleep(1);
  system("CLS");
}
void waitIcon()
{
  cout << "\a\t\t\t Wait";
  for (int i = 1; i <= 4; i++)
  {
    cout << ".";
    sleep(1);
  }
}
char backButton()
{
  cout << endl
       << endl
       << "\t\t\t   => Press (B) to Back  ";
  cout << endl
       << endl
       << "\t\t\t  >> ";
start:
  char select;
  select = getch();
  if ((select == '1') || (select == '2') || (select == '3') || (select == 'b') || (select == 'B'))
  {
    return select;
  }
  else
    goto start;
}
long long int cashLaw(char n)
{
  string name;
  long long int accountNumber;
  cout << endl
       << endl
       << endl
       << "\t\t\t  Enter name and A/C no. also (CASH) <|-|> " << endl;
  cout << endl
       << endl
       << "\t\t\t  Enter name : >> ";
  cin >> name;
  cout << "\t\t\t  Enter A/C no. : >> ";
  cin >> accountNumber;

start:
  long double cash;
  cout << "\t\t\t  Enter Cash to transaction : ";
  cin >> cash;
  system("CLS");
  if (cash > 0)
  {
    cout << endl
         << endl
         << endl
         << "\t\t\t                  VALID CASH" << endl
         << "\t\t\t                  Processing";
  }
  else
  {

    cout << endl
         << endl
         << endl
         << "\t\t\t                 INVALID CASH" << endl;
    waitIcon();

    system("CLS");
    goto start;
  }
  for (int i = 0; i < 3; i++)
  {
    sleep(1);
    cout << ".";
  }
  system("CLS");
  cout << endl
       << endl
       << endl
       << "\t\t\t                      [ DONE ] ";
  sleep(1);

  if (n == '1')
    subDeposite(cash, accountNumber);
  else
    subWithdraw(cash, accountNumber);
}
int showSin()
{

  long long int accNumber;
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t  Enter Customer A/C number : ";
  cin >> accNumber;
  for (int i = 0; i < total; i++)
  {
    if (accNumber == customer[i].account_number)
    {
      customer[i].display();
      cross = i;
      break;
    }
  }
  if (accNumber != customer[cross].account_number)
  {
    return accNotFound();
  }
}
void showAll()
{

  for (int i = 0; i < total; i++)
  {
    cout << endl
         << endl
         << endl;
    cout << "\t\t\t  the Details of (" << i + 1 << ") Customer >>" << endl;
    customer[i].display();
  }
}

// functions >>>>>>>>>>
int addAccount(void)
{
  cout << endl
       << endl
       << "\t\t\t\t\t \5  Enter details to add  \5 " << "\n\n\n\n";
  string name;
  int choice;
  long double precash;
  long long int account_number;
  cout << "\t\t\t  Enter number of Customer to Add : ";
  cin >> choice;
  cout << endl;
  for (int i = total; i < total + choice; i++)
  {
    cout << "\t\t\t  Enter the details of Customer : " << i + 1 << " >>" << endl;
    cout << "\t\t\t  Enter name : ";
    cin >> name;
    cout << "\t\t\t  Enter A/c number ( 8 digitts ) : ";
    cin >> account_number;
    cout << "\t\t\t  Enter cash to deposite : ";
    cin >> precash;
    customer[i].inputDetails(name, account_number, precash);
    cout << endl
         << endl;
  }
  total += choice;
  { //>>>>>>>>>>>>>>>.
    system("CLS");
    cout << endl
         << endl
         << endl
         << endl
         << "\t\t\t                       Processing";
    for (int i = 1; i <= 3; i += 1)
    {
      cout << ".";
      sleep(1);
    }
    system("CLS");
    cout << endl
         << endl
         << endl
         << endl
         << "\t\t\t                        [ DONE ]";
    sleep(1);
    return 1;
  }
}
int searchAccount(void)
{
start:
  system("CLS");
  long long int accHolder, notFound;
  char select;
  cout << endl
       << endl;
  cout << "\t\t\t\4 Press (1) to show all Accounts <.>   ";
  cout << "\t\t\4 Press (2) to show single Account <.>  "
       << endl;
  select = backButton();
  if (select == 'b')
    return 1;
  switch (select)
  {
  case '1':
    system("CLS");
    showAll();
    break;
  case '2':
    system("CLS");
    notFound = showSin();
    break;
  }
  char ch;
  if (notFound != -1)
  {
    cout << endl
         << endl
         << endl
         << "\t\t\t  Press (any key) to release : ";
    ch = getch();
  }
  else
    goto start;
}
//-------------------------------------------------------------------------------------------------------------------------------------
int transactions(void)
{

  cout << endl
       << endl;
  cout << "\t\t\t\4  Press (1) to Deposite cash <.> ";
  cout << "\t\t\4  Press (2) to Withdraw cash <.> "
       << endl;
  char n = backButton();
  if (n == 'b' || n == 'B')
    return 1;
  switch (n)
  {
  case '1':
    system("CLS");
    cashLaw(n);
    break;

  case '2':
    system("CLS");
    cashLaw(n);
    break;
  }

  return 1;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
int updateAccount(void)
{
  string name;
  long double cash;
  long long int account_number;
  char ofwhich;
  char notFound = showSin();

  if (notFound != -1)
  {
  start:
    cout << endl
         << endl
         << "\t\t\t  What you want to update : >>>>> "
         << endl;
    cout << "\t\t\t  Press (1) to update name "
         << endl
         << "\t\t\t  Press (2) to update cash balance "
         << endl
         << "\t\t\t  Press (3) to update A/C no. "
         << endl;

    for (int i = 0; i < total; i++)
    {
    }
    char select = backButton();
    if (select == 'b' || select == 'B')
      return 1;
    switch (select)
    {

    case '1':
      ofwhich = '1';
      cout << endl
           << "\t\t\t  Enter name : ";
      cin >> name;
      customer[cross].updateAttributes(name, cash, account_number, ofwhich);
      break;

    case '2':
      ofwhich = '2';
      cout << endl
           << "\t\t\t  Enter Cash : ";
      cin >> cash;
      customer[cross].updateAttributes(name, cash, account_number, ofwhich);
      break;

    case '3':
      ofwhich = '3';
      cout << endl
           << "\t\t\t  Enter A/C no. : ";
      cin >> account_number;
      customer[cross].updateAttributes(name, cash, account_number, ofwhich);
      break;
    }
    waitplusProcessingIcon();
    cout << endl
         << endl
         << " \t\t\t  Press (1) to more updation , if not Press (any key) to release  ";
    char ch = getch();

    if (ch == '1')
    {
      goto start;
    }
  }
  system("CLS");
}
//-----------------------------------------------------------------------------------------------------------------------------
int deleteAccount(void)
{
  char select;
  cout << endl
       << endl
       << endl
       << endl
       << "\t\t\t\4 Press 1 for Delete all data <.>\t\t\4 Press 2 for Delete desired data <.>" << endl;

  select = backButton();
  if (select == 'b')
    return 1;
  switch (select)
  {
  case '1':
    total = 0;
    break;
  
  case '2':
  //subdeleteAccount();
    break;
  }
  waitplusProcessingIcon();
}