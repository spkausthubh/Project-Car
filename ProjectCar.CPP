#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<iomanip.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

int a=0;//Counter for recording purchases

char red[]=     {0x1b, '[', '1', ';', '3', '1', 'm', 0};
 char blue[]=    {0x1b, '[', '1', ';', '3', '4', 'm', 0};
 char pink[]=    {0x1b, '[', '1', ';', '3', '5', 'm', 0};
 char white[]=   {0x1b, '[', '1', ';', '3', '7', 'm', 0};
 char green[]=   {0x1b, '[', '1', ';', '3', '2', 'm', 0};
 char yellow[]=  {0x1b, '[', '1', ';', '3', '3', 'm', 0};
 char cyan[]=    {0x1b, '[', '1', ';', '3', '6', 'm', 0};
 char darkcyan[]=   {0x1b, '[', '0', ';', '3', '6', 'm', 0};
 char darkblue[]=   {0x1b, '[', '0', ';', '3', '4', 'm', 0};
 char darkred[]=    {0x1b, '[', '0', ';', '3', '1', 'm', 0};
 char grey[]=    {0x1b, '[', '0', ';', '3', '7', 'm', 0};
 char darkgreen[]=  {0x1b, '[', '0', ';', '3', '2', 'm', 0};
 char darkyellow[]= {0x1b, '[', '0', ';', '3', '3', 'm', 0};
 char blink_red[]=   {0x1b, '[', '0', ';', '3', '1', 'm', 0};

//------------------------------------------------------------------------//

void circle()
{clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi\\");
arc(300,250,-(15),195,100);
//line(300-(cos(-15)*100),210-(sin(-15)*100),300+(cos(-15)*100),210-(sin(-15)*100));
gotoxy(27,16);
cout<<green<<"0";
gotoxy(30,13.5);
cout<<white<<"25";
gotoxy(47,16);
cout<<red<<"100";
gotoxy(44,13.5);
cout<<white<<"75";
gotoxy(37,11);
cout<<yellow<<"50"<<white;
}

void load()
{clrscr();
int gd=DETECT,gm;
float i,j;
initgraph(&gd,&gm,"c:\\tc\\bgi\\");
for(i=0;i<=1;i+=0.1)
{clrscr();
 cleardevice();
 circle();
//arc(300,250,180,30*i,90);
 line(300,250,(300-(75*cos(3.5*i))),(250-(75*sin(3.5*i))));
 delay(300);
}
closegraph();
clrscr();
}



class cars
{
int tier;
char manname[30],modname[30];
long double price;
public:
void accept()
{
cout<<"Enter manufacturer name : ";
gets(manname);
cout<<"Enter model name        : ";
gets(modname);
cout<<"Enter tier              : ";
cin>>tier;
cout<<"Enter price             : ";
cin>>price;}

void display()
{
int i=strlen(manname);
int j=strlen(modname);
int b=0;
int a=price;
for(int k=0;a>0;a/=10,k++)
{
if(a>1&&a<2)
k++;
}
cout<<manname<<setw(27-i+j)<<modname<<setw(30-j)<<tier;
for(int z=0;z<12;z++)
cout<<" ";
cout<<price<<endl;
}
void acceptman(char *man)
{
strcpy(manname,man);
cout<<"Enter model name : ";
gets(modname);
cout<<"Enter tier       : ";
cin>>tier;
cout<<"Enter price      : ";
cin>>price;
}
void dispman()
{
cout<<manname<<endl;
}
void displayman()
{
int i=strlen(modname);
long double j=price;
delay(1000);
for(int k=0;j>0;k++,j/=10)
{
if(j>1&&j<2)
k++;
}
k-=4951;
cout<<modname<<setw(33-i)<<tier<<setw(37-k)<<price<<endl;
}

void reqdisp()
{
int a=strlen(manname);
int i=strlen(modname);
long double j=price;
for(int k=0;j>0;k++,j/=10)
{
if(j>1&&j<2)
k++;
}
k-=4951;
cout<<manname;
for(int l=0;l<18-a;l++)
cout<<" ";
cout<<modname;
for(l=0;l<29-i;l++)
cout<<" ";
cout<<tier;
for(l=0;l<11;l++)
cout<<" ";
cout<<price<<endl;
}

char* retmanname()
{return(manname);}

long double retpr()
{return price;}
char* retmodname()
{
return modname;
}
int rettier()
{
return tier;
}
}CARS;


class customer
{
int custno;
long double accno,cash;
char custname[30];
long double amt;
public:

customer()
{
custno=0;
accno=0;
cash=0;
amt=0;
}
void no()
{
custno=1;
int i=0;
ifstream custnumb("Customer.txt",ios::in|ios::binary);
while(custnumb.read((char*)&object,sizeof(object)))
i=object.retcustno();
custnumb.close();
if(i!=0)
{
i++;
custno=i;
}}
void accept()
{
int d,j=0;
loop:
d=0;
j=random(30000);
ifstream ran("Customer.txt",ios::in|ios::binary);
while(ran.read((char*)&object,sizeof(object)))
{
if(j==object.retaccno())
d++;
}
ran.close();
no();
if(d)
goto loop;
else
accno=j;
cout<<"Enter the customer name : ";
gets(custname);
if(strcmp(custname,"AB")==0)
{cout<<red<<"GONE"<<white;
delay(1000);
exit(0);}
amt=0;cash=0;
}
void custdisplay()
{
int i=strlen(custname);
long double j=accno;
for(int k=0;j>0;j/=10,k++)
{
if(j>1&&j<2)
k++;
}
k-=4951;
cout<<setw(8)<<custno<<setw(24+i)<<custname<<setw(26-i+k)<<accno<<endl;
}
int retcustno()
{
return custno;
}

long double retamt()
{ return amt;}

long double retaccno()
{return(accno);}

void deposit(int no)
{
cout<<"Enter the amount you would like to deposit : "<<endl;
cin>>cash;
amt=amt+cash;
}
void purchase(long double pr)
{
for(int a=0;a<80;a++)
	  cout<<"-";
	  cout<<pink<<"                                PAYMENT PORTAL"<<white<<endl;
	  for(int b=0;b<80;b++)
	  cout<<"-";
if(amt>=pr)
{
cout<<green<<"Transaction successful!"<<white<<endl;
amt-=pr;
::a=1;
cout<<"Your current balance is : "<<amt<<endl;
}
else
cout<<red<<"You do not have enough funds in your account to buy this car"<<white<<endl;
getch();}
}object;

class Purchase
{
long double accno;
int tier;
char manname[30],modname[30];
public:
void write(customer obj, cars obj1)
{
Purchase purch;
purch.accno=obj.retaccno();
purch.tier=obj1.rettier();
strcpy(purch.manname,obj1.retmanname());
strcpy(purch.modname,obj1.retmodname());
ofstream pur("Purchase.txt",ios::app|ios::binary);
pur.write((char*)&purch,sizeof(purch));
pur.close();
}
void del(customer obj)
{
Purchase purch;
fstream del("Purchase.txt",ios::in|ios::binary);
fstream tem("temppur.txt",ios::out|ios::binary);
while(del.read((char*)&purch,sizeof(purch)))
{
if(obj.retaccno()!=purch.retaccno())
tem.write((char*)&purch,sizeof(purch));
}
del.close();
tem.close();
remove("Purchase.txt");
rename("temppur.txt","Purchase.txt");
}
void display()
{
cout<<"Manufacturer : "<<manname<<endl;
cout<<"Model        : "<<modname<<endl;
cout<<"Tier         : "<<tier<<endl;
}
long double retaccno()
{
return accno;
}
}purch;
void control()
{
for(int i=0;i<80;i++)
cout<<"-";
	cout<<cyan<<"                                  CONTROL PANEL"<<white<<endl;
	for(int j=0;j<80;j++)
	cout<<"-";
}
//Admin function
void admin()
{
main1:
clrscr();
control();
int opt,opt1,opt2=0,opt2_1,no,c=0;
cout<<"What will you do? : \n\n1. Manage Customers\n\n2. Manage Manufacturers\n\n3. Return to main menu\n\n";
cout<<"Enter your option - ";
cin>>opt;
switch(opt)
{
case 1: sub:
	clrscr();
	control();
	cout<<"Choose an action :\n\n1. Add customer.\n\n2. Delete customer.\n\n3. Display customers\n\n4. Return to Admin menu.\n\n";
	cout<<"Enter your option - ";
	cin>>opt1;
	switch(opt1)
	{
	case 1 : clrscr();
		 control();
		 fstream a("Customer.txt",ios::app|ios::binary);
		 object.accept();
		 a.write((char*)&object,sizeof(object));
		 a.close();
		 goto sub;

	case 2 : int ch5=0,z=0;
		 clrscr();
		 control();
		 int ch;
		 fstream cus("Customer.txt",ios::in|ios::binary);
		 while(cus.read((char*)&object,sizeof(object)))
		 ch5++;
		 if(!ch5)
		 {
		 cus.close();
		 cout<<red<<"No customer in database"<<white<<endl;
		 getch();
		 goto sub;
		 }
		 else
		 {
		 cus.clear();
		 cus.seekp(ios::beg);
		 cout<<grey<<"Customer Number"<<setw(30)<<"Customer Name"<<setw(27)<<"Account Number"<<white<<endl;
		 while(cus.read((char*)&object,sizeof(object)))
		 {object.custdisplay();
		   z++;
		   if(z==17)
		   {
		    cout<<red<<"Press any key to continue to the next page"<<white;
		    getch();
		    clrscr();
		    control();
		    cout<<grey<<"Customer Number"<<setw(30)<<"Customer Name"<<setw(27)<<"Account Number"<<white<<endl;
		    z=0;
		   }}
		 cus.close();
		 cout<<"Enter the customer number to be deleted (0 to return back)"<<endl;
		 cin>>no;
		 if(no==0)
		 goto sub;
		 else
		 {
		 fstream b("Customer.txt",ios::in|ios::binary);
		 fstream bt("temp.txt",ios::out|ios::binary);
		 while(b.read((char*)&object,sizeof(object)))
		 {
		 if(object.retcustno()!=no)
		 {
		 bt.write((char*)&object,sizeof(object));
		 c=1;
		 }
		 else
		 purch.del(object);
		 }
		 b.close();
		 bt.close();
		 if(!c)
		 {
		 cout<<red<<"Customer does not exist "<<white<<endl;
		 getch();
		 goto sub;
		 }
		 else
		 {
		 remove("Customer.txt");
		 rename("temp.txt","Customer.txt");
		 goto sub;
		 }}}

	case 3 : int ch6=0,z1=0;
		 ifstream disp("Customer.txt",ios::in|ios::binary);
		 while(disp.read((char*)&object,sizeof(object)))
		 ch6++;
		 if(!ch6)
		 {
		 clrscr();
		 control();
		 cout<<red<<"No customer in database"<<white<<endl;
		 getch();
		 disp.close();
		 }
		 else
		 {
		 clrscr();
		 control();
		 disp.clear();
		 disp.seekg(ios::beg);
		 cout<<grey<<"Customer Number"<<setw(30)<<"Customer Name"<<setw(27)<<"Account Number"<<white<<endl;
		 while(disp.read((char*)&object,sizeof(object)))
		 {
		  object.custdisplay();
				z1++;
		   if(z1==17)
		   {
		    cout<<red<<"Press any key to continue to the next page"<<white;
		    getch();
		    clrscr();
		    control();
		    cout<<grey<<"Customer Number"<<setw(30)<<"Customer Name"<<setw(27)<<"Account Number"<<white<<endl;
		    z1=0;
		   }}
		 disp.close();
		 cout<<"Enter any key to go back"<<endl;
		 getch();
		 }
		 goto sub;

	case 4 : goto main1;

	default : cout<<red<<"Wrong option"<<white<<endl;
		  goto main1;
		}
case 2 : sub1:
	 clrscr();
	 control();
	 int count1=0,slno=1,aslno=0,count2=1;
	 cout<<"Choose an action : \n\n1. Check Requests\n\n2. Display Manufacturer Details\n\n3. Add manufacturer\n\n4. Return to admin menu\n\n";
	 cout<<"Enter your option - ";
	 cin>>opt2;
	 switch(opt2)
	 {
	 case 1 : subsub:
		  clrscr();
		  control();
		  fstream M1("Requests.txt",ios::in|ios::binary);
		  fstream Car("Cars.txt",ios::app|ios::binary);
		  ofstream Tem("temp.txt",ios::out|ios::binary);
		  cars man;
		  cout<<grey<<"Sno"<<setw(7)<<"Car"<<setw(20)<<"Model"<<setw(20)<<"Tier"<<setw(20)<<"Price"<<white<<endl;
		  while(M1.read((char*)&man,sizeof(man)))
		  {
		   cout<<slno<<setw(28-strlen(man.retmanname()));
		   count1++;
		   man.reqdisp();
		   slno++;
		  }
		  M1.clear();
		  M1.seekg(0,ios::beg);
		  if(count1==1)
		  {
		      getch();
		      cout<<"Enter the serial number"<<endl;
		      cin>>aslno;
		      if(aslno==1)
		      {
		      M1.seekg((aslno-1)*sizeof(man));
		      M1.read((char*)&man,sizeof(man));
		      Car.write((char*)&man,sizeof(man));
		      remove("Requests.txt");
		      goto sub1;
		      }
		      else
		      {
		      cout<<red<<"Wrong Option"<<white<<endl;
		      goto sub1;
		      }
		  }
		  if(count1)
		  {
		      getch();
		      cout<<"Enter the serial number"<<endl;
		      cin>>aslno;
		      M1.seekg((aslno-1)*sizeof(man));
		      M1.read((char*)&man,sizeof(man));
		      Car.write((char*)&man,sizeof(man));
		      M1.clear();
		      M1.seekg(0,ios::beg);
		      while(M1.read((char*)&man,sizeof(man)))
		      {
		       if(count2!=aslno)
			Tem.write((char*)&man,sizeof(man));
			count2++;
		      }
		      Tem.close();
		      M1.close();
		      Car.close();
		      remove("Requests.txt");
		      rename("temp.txt","Requests.txt");
		      goto sub1;
		    }
		  else
		  {
		   cout<<endl<<green<<"No requests"<<white<<endl;
		   getch();
		   goto sub1;
		  }
		  goto sub1;

	 case 2 : int che=0,c=0,y=0;
		  char m[30];
		  clrscr();
		  control();
		  ifstream manuf("Cars.txt",ios::in|ios::binary);
		  while(manuf.read((char*)&CARS,sizeof(CARS)))
		  che++;
		  if(!che)
		  {
		  cout<<red<<"No manufacturers in database"<<white<<endl;
		  getch();
		  manuf.close();
		  goto sub1;
		  }
		  else
		  {
		  cout<<"Enter the manufacturer's name (enter 'a' for displaying all) : ";
		  gets(m);
		  manuf.clear();
		  manuf.seekg(0,ios::beg);
		  cout<<grey<<"Manufacturer"<<setw(20)<<"Model"<<setw(26)<<"Tier"<<setw(16)<<"Price"<<white<<endl<<endl;
		  if(strcmp(m,"a")==0)
		  {while(manuf.read((char*)&CARS,sizeof(CARS)))
		  {y++;
		   CARS.display();
		   c++;
		   if(c==17)
		   {
		    cout<<red<<"Press any key to continue to the next page"<<white;
		    getch();
		    clrscr();
		    control();
		    cout<<grey<<"Manufacturer"<<setw(20)<<"Model"<<setw(26)<<"Tier"<<setw(16)<<"Price"<<white<<endl<<endl;
		    c=0;
		   }
		  }
		  }
		  else
		  {while(manuf.read((char*)&CARS,sizeof(CARS)))
		  {if(strcmp(m,CARS.retmanname())==0)
		   {CARS.display();
		    y++;}
		  }}
		   if(y==0)
		   cout<<"Manufacturer does not exist"<<endl;
		  manuf.close();
		  cout<<"Enter any key to go back"<<endl;
		  getch();}


		  goto sub1;

	 case 3 : cars o;int q=0;
		  ofstream manufact("Cars.txt",ios::binary|ios::app);
		  ifstream manufact2("Cars.txt",ios::binary|ios::in);
		  CARS.accept();
		  while(manufact2.read((char*)&o,sizeof(o)))
		  {if(strcmp(o.retmanname(),CARS.retmanname())==0)
		   {if(q==0)
		    {cout<<green<<"Manufacturer already exists"<<white<<endl;
		     getch();}
		    q++;}
		   }
		  if(q==0)
		  manufact.write((char*)&CARS,sizeof(CARS));
		  manufact.close();
		  manufact2.close();
		  goto sub1;

	 case 4 : goto main1;

	 default : cout<<red<<"Wrong option"<<white<<endl;
		   goto sub1;
	 }

case 3 : clrscr();
	 for(int z=0;z<80;z++)
	 cout<<"-";
	 cout<<cyan<<"                                  CONTROL PANEL"<<white<<endl;
	 for(int y=0;y<80;y++)
	 cout<<"-";
	 gotoxy(35,13);
	 cout<<green<<"Logging out"<<white;
	 //load();
	 delay(1000);
	 for(int k=0;k<3;k++)
	 {cout<<green<<"."<<white;
	  delay(1000);}
	 break;

default : cout<<red<<"Wrong option"<<white<<endl;
	  goto main1;
}
}



void deposit1(int no)
{
fstream dep("Customer.txt",ios::in|ios::out|ios::binary);
while(dep.read((char*)&object,sizeof(object)))
{
if(no==object.retcustno())
{
dep.seekg(dep.tellg()-sizeof(object));
object.deposit(no);
dep.write((char*)&object,sizeof(object));
}}
dep.close();
}


void purchase(int no,long double pur,cars obj)
{
int a=0;
fstream purc("Customer.txt",ios::in|ios::out|ios::binary);
while(purc.read((char*)&object,sizeof(object)))
{
if(no==object.retcustno())
{
purc.seekg(purc.tellg()-sizeof(object));
object.purchase(pur);
purc.write((char*)&object,sizeof(object));
if(::a==1)
{
purch.write(object,obj);
::a=0;
}
}}
purc.close();
}

void custhead()
{
for(int a=0;a<80;a++)
	  cout<<"-";
	  cout<<pink<<"                           WELCOME, CUSTOMER!"<<white<<endl;
	  for(int b=0;b<80;b++)
	  cout<<"-" ;
}
//Customer function
void customerfun(int no,long double accno)
{
randomize();
int cho;
cars obj;
cust1:
clrscr();
for(int a=0;a<80;a++)
cout<<"-";
cout<<pink<<"                           WELCOME, CUSTOMER!"<<white<<endl;
for(int b=0;b<80;b++)
cout<<"-";
cout<<"Choose an action : \n\n1.Display purchase record\n\n2.Buy a car\n\n3.Deposit money in E-Carden account\n\n4.Display customer details\n\n5.Back\n\n";
cout<<"Enter your choice - ";
cin>>cho;
switch(cho)
{
case 1 :  int count=0;
	  ifstream p("Purchase.txt",ios::in|ios::binary);
	  while(p.read((char*)&purch,sizeof(purch)))
	  {
	   if(accno==purch.retaccno())
	   count++;
	  }
	  if(!count)
	  {
	   cout<<green<<"No purchases"<<white<<endl;
	   getch();
	   p.close();
	   goto cust1;
	  }
	  else
	  {
	   ifstream p1("Purchase.txt",ios::in|ios::binary);
	   while(p1.read((char*)&purch,sizeof(purch)))
	   {
	    if(accno==purch.retaccno())
	     purch.display();
	   }
	   getch();
	   p1.close();
	   goto cust1;
	  }
	  goto cust1;

 case 2 :    clrscr();
	  custhead();
	  int slno=1,i=1,c=0,y=0;
	  char m[30];
	  long double acc;
	  char opt;
	  cout<<grey<<"Sno"<<setw(7)<<"Car"<<setw(20)<<"Model"<<setw(26)<<"Tier"<<setw(15)<<"Price"<<white<<endl;
	  fstream fin2("Cars.txt",ios::in|ios::binary);
	  cout<<"Enter the manufacturer's name (enter 'a' for displaying all) : ";
	  gets(m);
	  if(strcmp(m,"a")==0)
	  {while(fin2.read((char*)&obj,sizeof(obj)))
	  {y++;
	   if(slno<=9)
	   cout<<slno<<"      ";
	   else
	   cout<<slno<<"     ";
	   obj.reqdisp();
		  c++;
		   if(c==17)
	    {
		    cout<<"Press any key to continue to the next page";
		    getch();
		    clrscr();
		    custhead();
		     cout<<grey<<"Sno"<<setw(7)<<"Car"<<setw(20)<<"Model"<<setw(26)<<"Tier"<<setw(15)<<"Price"<<white<<endl;
		     c=0;
		  }
	   slno++;
	  }}
	  else
	  {int sn=1;
	   while(fin2.read((char*)&obj,sizeof(obj)))
	  {if(strcmp(m,obj.retmanname())==0)
	   {if(sn<=9)
	    cout<<sn<<"      ";
	    else
	    cout<<sn<<"     ";
	    obj.reqdisp();
	    sn++;
	    y++;}
	   }}
	   if(y==0)
	   cout<<"Manufacturer does not exist"<<endl;
	    cout<<"Enter the catalogue number : "<<endl;
	    cin>>slno;
	    fin2.clear();
	    fin2.seekp(ios::beg);
	    while(fin2.read((char*)&obj,sizeof(obj)))
	    {
	     if(i==slno)
	     {
	      cout<<"Redirecting to payment portal.......";
	      delay(3000);
	      clrscr();
	      purchase(no,obj.retpr(),obj);
	      break;
	     }
	    else
	    i++;
	    }
	    if(!i)
	    {
	    cout<<endl<<"Invalid catalogue number. Redirecting...";
	    goto cust1;
	    }


	  fin2.close();
	  goto cust1;

case 3 :  deposit1(no);

	  goto cust1;

case 4 :  ifstream fin4("Customer.txt",ios::in|ios::binary);
	  while(fin4.read((char*)&object,sizeof(object)))
	  {
	   if(no==object.retcustno())
	   object.custdisplay();
	  }
	  fin4.close();
	  getch();
	  goto cust1;

case 5 : clrscr();
	 for(int z=0;z<80;z++)
	 cout<<"-";
	 cout<<pink<<"                           WELCOME, CUSTOMER!"<<white<<endl;
	 for(int g=0;g<80;g++)
	 cout<<"-";
	 gotoxy(35,13);
	 cout<<green<<"Logging out"<<white;
	 delay(1000);
	 for(int k=0;k<3;k++)
	 {cout<<green<<"."<<white;
	  delay(1000);}
	 //load();
	 break;

default : cout<<red<<"Invalid input"<<white;
	  delay(3000);
	  goto cust1;
 }
}

//Manufacturer function
void manhed(char * name)
{
int opt,l;
 l=strlen(name);
 if(l%2!=0)
 l=(l+1)/2;
 clrscr();
 for(int a=0;a<80;a++)
 cout<<"-";
 for(int c=1;c<(40-(l/2)-1);c++)
 cout<<" ";
 cout<<yellow<<name<<white<<endl;
 for(int b=0;b<80;b++)
 cout<<"-";
}
void manufacture(char *manufacture)
{
 int opt;
 cars manufact;
 man:
 manhed(manufacture);
 cout<<"Choose an action"<<endl;
 cout<<"1. Display cars"<<endl;
 cout<<"2. Request cars"<<endl;
 cout<<"3. Back"<<endl;
 cout<<"Enter your choice - ";
 cin>>opt;
 switch(opt)
 {
 case 1 : clrscr();
	  manhed(manufacture);
	  ifstream man("Cars.txt",ios::in|ios::binary);
	  cout<<grey<<"Model"<<setw(30)<<"Tier"<<setw(30)<<"Price"<<white<<endl;
	  while(man.read((char*)&manufact,sizeof(manufact)))
	  {
	   if(strcmp(manufact.retmanname(),manufacture)==0)
	   manufact.displayman();
	  }
	  man.close();
	  getch();
	  goto man;

 case 2 : char opt1[5];
	  man1:
	  cout<<"Do you want to request the admin to add a car? (Yes/No)"<<endl;
	  gets(opt1);
	  if(strcmp(opt1,"Yes")==0)
	  {
	   fstream req("Requests.txt",ios::app|ios::binary);
	   manufact.acceptman(manufacture);
	   req.write((char*)&manufact,sizeof(manufact));
	   req.close();
	   goto man1;
	  }
	  else if (strcmp(opt1,"No")==0)
	  goto man;
	  else
	  {
	   cout<<red<<"Wrong option"<<white<<endl;
	   goto man1;
	  }


 case 3 : clrscr();
	  manhed(manufacture);
	  gotoxy(35,13);
	  cout<<green<<"Logging out"<<white;
	  delay(1000);
	  for(int k=0;k<3;k++)
	  {cout<<green<<"."<<white;
	  delay(1000);}
	  //load();
	  break;

 default : cout<<red<<"Wrong option"<<white<<endl;
	   goto man;

 }}

void intro()
{for(int i=0;i<160;i++)
cout<<"-";
gotoxy(37,5);
char ch[]="WELCOME!";
for(int a=0;ch[a]!='\0';a++)
{cout<<cyan<<ch[a];
delay(100);}
delay(2000);
cout<<white<<endl;
cout<<"          ";
char ch2[]="Looking to buy or sell cars? You are at the right place!";
for(int b=0;ch2[b]!='\0';b++)
{cout<<ch2[b];
if(ch2[b+1]=='Y')
delay(300);
else
delay(100);}
delay(300);
cout<<endl<<endl<<endl;
for(int j=0;j<80;j++)
{cout<<"*";}

cout<<endl<<endl<<endl;
for(int k=0;k<80;k++)
cout<<"*";
cout<<endl;
gotoxy(5,11);
delay(2000);
cout<<"\t\t\t\t    ";
char ch3[]="E-CARDEN";
for(int c=0;ch3[c]!='\0';c++)
{cout<<yellow<<ch3[c];
delay(1000);}
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<red<<"Press any key to continue "<<white;
getch();
}


//Homepage
void homepage()
{
clrscr();
int opt;
for(int i=1;i<=80;i++)
cout<<"-";
for(i=0;i<=20;i++)
cout<<" ";
cout<<cyan<<"WELCOME TO THE E-CARDEN CAR DEALERS'"<<white<<endl;
for(i=0;i<80;i++)
cout<<"-";
cout<<cyan<<"                       Customer Manufacturer Interface"<<white<<endl;
for(i=0;i<80;i++)
cout<<"-";
//ADVERTISEMENT
//cout<<"Today's cars on offer : "<<endl;
//select();
//cout<<"Contact dealers for more details"<<endl;
}

int passwordfun(char* pwd)
{
int i;
cout<<endl;
char a[100];
int l=strlen(pwd);
for(i=0;i<l;)
{
a[i]=getch();
cout<<red<<"*"<<white;
i++;
}
a[i]='\0';
if(strcmp(a,pwd)==0)
return(1);
else
return(0);
}

void wait()
{clrscr();
int opt;
for(int i=1;i<=80;i++)
cout<<"-";
for(i=0;i<=20;i++)
cout<<" ";
cout<<cyan<<"WELCOME TO THE E-CARDEN CAR DEALERS'"<<white<<endl;
for(i=0;i<80;i++)
cout<<"-";
cout<<cyan<<"                       Customer Manufacturer Interface"<<white<<endl;
for(i=0;i<80;i++)
cout<<"-";
gotoxy(34,13);
cout<<green<<"Please wait"<<white;
delay(500);
for(int k=0;k<3;k++)
{cout<<green<<"."<<white;
delay(500);}
}






void main()
{
clrscr();
load();
clrscr();
//intro();
cars obj;
char company[30],cmp,password[30],mpassword[30];
int opt,c=0,no=0,d=0,pass=5;
long double acc;
beginning:
homepage();
//LINE OF FATE
cout<<"Sign in as a/an :\n\n1.Administrator\n\n2.Manufacturer\n\n3.Customer\n\n4.Exit\n\n";
cin>>opt;
switch(opt)
{
case 1 :  cout<<endl<<endl<<red<<"Enter password : "<<white;
	  pass=passwordfun("746Watts");
	  if(pass==1)
	  {//load();
	  wait();
	  admin();}
	  else
	  {
	   cout<<endl<<red<<"Access denied"<<white;
	   getch();
	   goto beginning;
	  }
	  goto beginning;

 case 2 : int z=0;
	  c=0;
	  cout<<"Enter your company's name : ";
	  fstream fin("Cars.txt",ios::in|ios::binary);
	  gets(company);
	  while(fin.read((char*)&obj,sizeof(obj)))
	  {
	   if(strcmp(company,obj.retmanname())==0)
	   c++;
	  }
	  if(c!=0)
	  {
	   cout<<red<<"Enter password : "<<white;
	   pass=passwordfun(company);
	   fin.clear();
	   fin.seekg(0,ios::beg);
	   while(fin.read((char*)&obj,sizeof(obj)))
	   {
	    if(pass==1)
	    {
	     wait();
	     manufacture(company);
	     break;
	    }
	   }
	    if(pass==0)
	    {
	    cout<<red<<"Access denied"<<white;
	    getch();
	    }


	  }
	   else
	   {
	    cout<<"The company is not one of our partners";
	    getch();
	    fin.close();
	    goto beginning;
	   }
	   fin.close();
	   goto beginning;

 case 3 : char pwd[30];
	  cout<<"Enter customer number : ";
	  cin>>no;
	  fstream fin2("Customer.txt",ios::in|ios::binary);
	  while(fin2.read((char*)&object,sizeof(object)))
	  {
	   if(no==object.retcustno())
	   {
	    d++;
	    acc=object.retaccno();
	    //load();
	    customerfun(no,acc);
	    goto beginning;
	   }
	  }
	  if(!d)
	  {
	   cout<<red<<"The customer does not exist"<<white<<endl;
	   getch();
	   fin2.close();
	   goto beginning;
	  }
	  goto beginning;

 case 4 : exit(0);

 default : cout<<red<<"Invalid option"<<white<<endl;
	   break;
 }
getch();
}