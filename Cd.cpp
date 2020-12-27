 
//**********************************************************
//	PROJECT CD CAFE
//**********************************************************
 
#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
void edit_cd(void) ;
void edit_member(void) ;
void edit_menu(void);
void entry_menu(void) ;
void list_menu(void) ;
void cd_records(void) ;
void introduction(void) ;
void introduction(void)
{
	clrscr() ;
	gotoxy(31,5) ;cout<<"Welcome to Project" ;
	textcolor(RED+BLINK) ; textbackground(WHITE) ;
	gotoxy(33,7) ;cprintf(" CD CAFE") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	gotoxy(15,10) ;cout <<"This is the project where you can maintain records" ;
	gotoxy(15,11) ;cout <<"of CDS and MEMBERS." ;
	gotoxy(15,13) ;cout <<"One member can issue one cd at a time. If he/she" ;
	gotoxy(15,14) ;cout <<"does  not return cd within 15 days he/she have  to" ;
	gotoxy(15,15) ;cout <<"pay fine of Rs.20/- per day." ;
	//textcolor(LIGHTGRAY+BLINK) ;
	gotoxy(27,24) ;cprintf("Press any key to continue") ;
       //	textcolor(RED) ;
	getch() ;
}
//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//**********************************************************
 
class MENU
{
	public :
			void main_menu(void) ;
 
 
} ;
class CD
{
	public :
			void list(void) ;
			char *cdname(int) ;
	protected :void add_new_cd(int, char tname[33], char tcatagory[6], float, int, int);
			void update_copies(int, int, int) ;
			void modify(int, char[], char[], float) ;
			void deletion(void) ;
			int  cd_found(int) ;
			int  cdname_found(char []) ;
			int  recordno(int) ;
			int  available(int) ;
			char *cat_class(int) ;
			float cdprice(int) ;
			int  no_of_copies(int) ;
			int  cdcodeof(char[]) ;
			void display(int) ;
			int  reccount(void) ;
			void delete_rec(int) ;
	private :
			int   cdcode, copies ;
			char  name[33], catagory[6] ;
			float price ;
			int   avail ;
} ;
class MEMBER
{
	public :
			void list(void) ;
	protected :
	void add_mem(int, int, char [], char [], char[], int, int, int) ;
			void modify(int, char[], char[], char[]) ;
			void deletion(void) ;
			int  member_found(int) ;
			void update_cd(int, int, int, int, int) ;
 
			char *membername(int) ;
			char *memberphone(int) ;
			char *memberaddress(int) ;
			int  recordno(int) ;
			int  lastcode(void) ;
			int  issued(int) ;
			int  fine(int) ;
			void display(int) ;
			void delete_rec(int) ;
	private :
			int  memcode, cdcode ;
			char name[26], phone[10], address[33] ;
			int  dd, mm, yy ;// DATE OF RETURNING THE CD //
} ;
class WORKING : public CD, public MEMBER
{
 
	public :
			void issuecd(void) ;
			void returncd(void) ;
			void add_cd(void) ;
			void add_member(void) ;
			void modify_cd(void) ;
			void modify_member(void) ;
			void delete_cd(void) ;
			void delete_member(void) ;
} ;
class DATE
{
	public :
			void extend_date(int,int,int,int) ;
			int  diff(int, int, int, int, int, int) ;
			int  day, mon, year ;
} ;
void DATE :: extend_date(int d1, int m1, int y1, int days)
{
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	for (int i=1; i<=days; i++)
	{
		d1++ ;
   if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	day  = d1 ;
	mon  = m1 ;
	year = y1 ;
}
int DATE :: diff(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0 ;
	if ((y2<y1 ) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days ;
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++ ;
		d1++ ;
	if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	return days ;
}
void MENU:: main_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(29,6) ;cout<<"C D    C A F E " ;
		gotoxy(29,7) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(30,10) ;cout <<"1. ADD NEW ENTRY" ;
		gotoxy(30,12) ;cout <<"2. LIST      " ;
		gotoxy(30,14) ;cout <<"3. EDIT      " ;
		gotoxy(30,16) ;cout <<"4. CD RECORDS" ;
		gotoxy(30,18) ;cout <<"5. HELP      " ;
		gotoxy(30,20) ;cout <<"0. QUIT      " ;
		gotoxy(30,22) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
			entry_menu();
		else
		if (ch == '2')
		     {
			list_menu();
		      }
		else
		if (ch == '3')
		    {
			edit_menu();
		     }
		else
		if (ch == '4')
		    {
 
			cd_records() ;
		    }
		else
		if (ch == '5')
		    {
			introduction() ;
		    }
		else
		if (ch == '0')
		      {
			clrscr();
			cout<<"\n \n \n \n \n \n \n \t \t \t \t" ;
			cout<<"Thanks for"<<"\n \t\t\t\t  working"<<"\n \t\t\t\t  with US!";
			cout<<"\n \n \t \t \t*****HAVE A VERY NICE DAY*****";
			break ;
		      }
	}
}
void edit_menu(void)
{
 
 
 
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;cout <<"E D I T  M E N U";
		gotoxy(32,10) ;cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. CDS" ;
		gotoxy(34,14) ;cout <<"2. MEMBERS" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
			edit_cd() ;
		else
		if (ch == '2')
 
			edit_member() ;
		else
		if (ch == '0')
			break ;
	}
 
 
}
void entry_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;cout <<"E N T R Y   M E N U";
		gotoxy(32,10) ;cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. MEMBERS"  ;
		gotoxy(34,14) ;cout <<"2. CDS";
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
		      {
			WORKING W;
			W.add_member();
		      }
		if (ch == '2')
		    {
		    WORKING W;
		    W.add_cd() ;
		   }
		if (ch == '0')
			break ;
	}
}
void list_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;cout <<" L I S T   M E N U";
		gotoxy(32,10) ;cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. CDS" ;
		gotoxy(34,14) ;cout <<"2. MEMBERS" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
		 {	CD C;
		       C.list() ;
		}
		else
		if (ch == '2')
		    {
			MEMBER M;
			M.list() ;
		    }
		if (ch == '0')
			break ;
	}
}
void cd_records(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(32,9) ;cout <<"CD R E C O R D S  M E N U";
		gotoxy(32,10) ;cout <<"~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. ISSUE CDS" ;
		gotoxy(34,14) ;cout <<"2. RETURNS CDS" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch =='1')
		    {
			WORKING W;
			W.issuecd() ;
		    }
		if (ch == '2')
		     {
			WORKING W;
			W.returncd() ;
		     }
		if (ch == '0')
			break ;
	}
}
void edit_cd(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(31,9) ;cout <<"E D I T  C D S";
		gotoxy(31,10) ;cout <<"~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. MODIFY" ;
		gotoxy(34,14) ;cout <<"2. DELETE" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(31,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
		{
			WORKING W ;
			W.modify_cd() ;
		}
		else
		if (ch == '2')
		{
			WORKING W ;
			W.delete_cd() ;
		}
		else
		if (ch == '0')
			break ;
	}
}
void edit_member(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(29,9) ;cout <<"E D I T  M E M B E R S";
		gotoxy(29,10) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(34,13) ;cout <<"1. MODIFY" ;
		gotoxy(34,14) ;cout <<"2. DELETE" ;
		gotoxy(34,15) ;cout <<"0. EXIT" ;
		gotoxy(29,17) ;cout <<"Enter your choice : " ;
		ch = getche() ;
		if (ch == 27)
			break ;
		else
		if (ch == '1')
		{
			WORKING W ;
			W.modify_member() ;
		}
		else
		if (ch == '2')
		{
			WORKING W ;
			W.delete_member() ;
		}
		else
		if (ch == '0')
			break ;
	}
}
int CD :: cd_found(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}
int CD :: cdname_found(char t1code[33])
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (!strcmpi(name,t1code))
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}
int CD :: recordno(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		count++ ;
		if (cdcode == tcode)
			break ;
	}
	file.close() ;
	return count ;
}
int CD :: available(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tavail=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			tavail = avail ;
			break ;
		}
	}
	file.close() ;
	return tavail ;
}
int CD :: no_of_copies(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tcopies=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			tcopies = copies ;
			break ;
		}
	}
	file.close() ;
	return tcopies ;
}
char *CD :: cdname(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char tname[33] ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			strcpy(tname,name) ;
			break ;
		}
	}
	file.close() ;
	return tname ;
}
char *CD :: cat_class(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char tcatagory[6] ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			strcpy(tcatagory,catagory) ;
			break ;
		}
	}
	file.close() ;
	return tcatagory ;
}
float CD :: cdprice(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	float tprice=0.0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			tprice = price ;
			break ;
		}
	}
	file.close() ;
	return tprice ;
}
 
int CD :: cdcodeof(char t1code[33])
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int tcode=0 ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (!strcmpi(name,t1code))
		{
			tcode = cdcode ;
			break ;
		}
	}
	file.close() ;
	return tcode ;
}
int CD :: reccount(void)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(CD)))
		count++ ;
	file.close() ;
	return count ;
}
void CD :: delete_rec(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(CD)) ;
		if ( file.eof() )
			break ;
		if ( cdcode != tcode )
			temp.write((char *) this, sizeof(CD)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("CD.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(CD)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(CD)) ;
	}
	file.close() ;
	temp.close() ;
}
void CD :: add_new_cd(int tcode,char tname[33], char tcatagory[6],
 float tprice, int tcopies, int tavail)
{
	fstream file ;
	file.open("CD.DAT", ios::app) ;
	cdcode = tcode ;
	strcpy(name,tname) ;
	strcpy(catagory,tcatagory) ;
	price = tprice ;
	copies = tcopies ;
	avail = tavail ;
	file.write((char *) this, sizeof(CD)) ;
	file.close() ;
}
void CD :: update_copies(int tcode, int tcopies, int tavail)
{
	int recno ;
	recno = recordno(tcode) ;
	fstream file ;
	file.open("CD.DAT", ios::out | ios::ate) ;
	copies = tcopies ;
	avail = tavail ;
	int location ;
	location = (recno-1) * sizeof(CD) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(CD)) ;
	file.close() ;
}
//*************************************************************************
// THIS FUNCTION MODIFY THE RECORD IN THE CD FILE FOR THE GIVEN CD CODE
//**************************************************************************
void CD :: modify(int tcode, char tname[33],
 char tcatagory[6], float tprice)
{
	int recno ;
	recno = recordno(tcode) ;
	fstream file ;
	file.open("CD.DAT", ios::out | ios::ate) ;
	strcpy(name,tname) ;
	strcpy(catagory,tcatagory) ;
	price = tprice ;
	int location ;
	location = (recno-1) * sizeof(CD) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(CD)) ;
	file.close() ;
}
void CD :: display(int tcode)
{
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CD)))
	{
		if (cdcode == tcode)
		{
			gotoxy(5,5) ;cout <<"cd Code   : " <<cdcode ;
			gotoxy(5,7) ;cout <<"cd Name   : " <<name ;
			gotoxy(5,8) ;cout <<"catagory : " <<catagory ;
			gotoxy(5,9) ;cout <<"Price       : Rs." <<price ;
			gotoxy(5,10) ;cout <<"Copies      : " <<price ;
			gotoxy(5,11) ;cout <<"Available   : " <<avail ;
			break ;
		}
	}
	file.close() ;
}
void CD :: list(void)
{
	clrscr() ;
	int row = 6 , found=0, flag=0 ;
	char ch ;
	gotoxy(33,2) ;cout <<"LIST OF CDS" ;
	gotoxy(32,3) ;cout <<"~~~~~~~~~~~~~~~" ;
	gotoxy(1,4) ;cout <<"CODE  CD NAME                         CATAGORY                  PRICE   COPIES" ;
	gotoxy(1,5) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ;
	file.open("CD.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CD)))
	{
		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(2,row) ;
		cout <<cdcode ;
		gotoxy(7,row) ;
		cout <<name ;
		gotoxy(40,row) ;
		cout <<catagory ;
		gotoxy(66,row) ;
		cout <<price ;
		gotoxy(73,row) ;
		cout <<copies ;
	       //	textbackground(WHITE) ; textcolor(RED) ;
		gotoxy(40,row+1) ;
		cprintf("STATUS: ") ;
	       //	textcolor(BLACK+BLINK) ;
		cprintf("%d copies available",avail) ;
	       //	textbackground(BLACK) ; textcolor(LIGHTGRAY) ;
		if ( row == 22 )
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(1,25) ;cout <<"Press any key to continue or Press <ESC> to exit" ;
			ch = getch() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(33,2) ;cout<<"LIST OF CDS" ;
			gotoxy(32,3) ;cout <<"~~~~~~~~~~~~~~~" ;
			gotoxy(1,4) ;cout <<"CODE  CD NAME    CATAGORY   PRICE  COPIES" ;
			gotoxy(1,5) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		}
		else
			row = row + 2 ;
	}
	if (!found)
	{
		gotoxy(5,10) ;cout <<"\7Records not found" ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}
int MEMBER :: member_found(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}
int MEMBER :: issued(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int missue=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			missue = cdcode ;
			break ;
		}
	}
	file.close() ;
	return missue ;
}
int MEMBER :: fine(int mcode)
{
	DATE D ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int days, t_fine ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			days = D.diff(dd,mm,yy,d1,m1,y1) ;
			t_fine = days * 20 ;
			break ;
		}
	}
	file.close() ;
	return t_fine ;
}
int MEMBER :: lastcode(void)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int mcode=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
		mcode = memcode ;
	file.close() ;
	return mcode ;
}
char *MEMBER :: membername(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char mname[26] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(mname,name) ;
			break ;
		}
	}
	file.close() ;
	return mname ;
}
char *MEMBER :: memberphone(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char mphone[10] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(mphone,phone) ;
			break ;
		}
	}
	file.close() ;
	return mphone ;
}
char *MEMBER :: memberaddress(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char maddress[33] ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			strcpy(maddress,address) ;
			break ;
		}
	}
	file.close() ;
	return maddress ;
}
int MEMBER :: recordno(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		count++ ;
		if (memcode == mcode)
			break ;
	}
	file.close() ;
	return count ;
}
void MEMBER :: delete_rec(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(MEMBER)) ;
		if ( file.eof() )
			break ;
		if ( memcode != mcode )
			temp.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("MEMBER.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(MEMBER)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
}
void MEMBER :: update_cd(int mcode, int tcode, int d1, int m1, int y1)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(MEMBER)) ;
		if ( file.eof() )
			break ;
		if ( memcode == mcode )
		{
			cdcode = tcode ;
			dd = d1 ;
			mm = m1 ;
			yy = y1 ;
			temp.write((char *) this, sizeof(MEMBER)) ;
		}
		else
			temp.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("MEMBER.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(MEMBER)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(MEMBER)) ;
	}
	file.close() ;
	temp.close() ;
}
void MEMBER :: modify(int mcode, char mname[26], char mphone[10],
 char maddress[33])
{
	int recno ;
	recno = recordno(mcode) ;
	fstream file ;
	file.open("MEMBER.DAT", ios::out | ios::ate) ;
	strcpy(name,mname) ;
	strcpy(phone,mphone) ;
	strcpy(address,maddress) ;
	int location ;
	location = (recno-1) * sizeof(MEMBER) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(MEMBER)) ;
	file.close() ;
}
void MEMBER :: add_mem(int mcode, int ccode,
char mname[26], char maddress[33], char mphone[10],
 int d1, int m1, int y1)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::app) ;
	memcode = mcode ;
	cdcode = ccode ;
	strcpy(name,mname) ;
	strcpy(address,maddress) ;
	strcpy(phone,mphone) ;
	dd = d1 ;
	mm = m1 ;
	yy = y1 ;
	file.write((char *) this, sizeof(MEMBER)) ;
	file.close() ;
}
void MEMBER :: display(int mcode)
{
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		if (memcode == mcode)
		{
			gotoxy(5,3) ;cout <<"Member Code # " <<mcode ;
			gotoxy(5,4) ;cout <<"~~~~~~~~~~~~~~~~~" ;
			gotoxy(5,6) ;cout <<"Name    : " <<name ;
			gotoxy(5,7) ;cout <<"Phone   : " <<phone ;
			gotoxy(5,8) ;cout <<"Address : " <<address ;
			break ;
		}
	}
	file.close() ;
}
void MEMBER :: list(void)
{
	clrscr() ;
	CD C ;
	int row = 6 , found=0, flag=0 ;
	char ch ;
	gotoxy(32,2) ;cout <<"LIST OF MEMBERS" ;
	gotoxy(31,3) ;cout <<"~~~~~~~~~~~~~~~~~" ;
	gotoxy(1,4) ;cout <<"CODE  CD CODE     NAME                PHONE        ADDRESS" ;
	gotoxy(1,5) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ;
	file.open("MEMBER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(MEMBER)))
	{
		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(2,row) ;cout <<memcode ;
		gotoxy(10,row) ;cout <<cdcode ;
		gotoxy(19,row) ;cout <<name ;
		gotoxy(38,row) ;cout <<phone ;
		gotoxy(50,row);cout<<address;
	      //	textbackground(WHITE) ; textcolor(BLACK) ;
		gotoxy(7,row+1) ;
		if (cdcode == 0)
			cprintf("CD NAME: (Not Issued)") ;
		else
		{
			cprintf("CD NAME: %s",C.cdname(cdcode)) ;
			gotoxy(42,row+1) ;cprintf("Date of return: ") ;
			textcolor(BLACK+BLINK) ;
			cprintf("%d/%d/%d",dd,mm,yy) ;
		}
		//	textbackground(BLACK) ; textcolor(LIGHTGRAY) ;
		if ( row == 22 )
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(1,25) ;cout <<"Press any key to continue or Press <ESC>"<<"to exit" ;
			ch = getch() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(32,2) ;cout <<"LIST OF MEMBERS" ;
			gotoxy(31,3) ;cout <<"~~~~~~~~~~~~~~~~~" ;
			gotoxy(1,4) ;cout <<"CODE  CD CODE   NAME                         PHONE" ;
			gotoxy(1,5) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		}
		else
			row = row + 2 ;
	}
	if (!found)
	{
		gotoxy(5,10) ;cout <<"\7Records not found" ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}
void WORKING :: add_cd(void)
{
	if (!reccount())  // MEMBER FUNCTION OF CD
	{
		add_new_cd(0,"null","null",0.0,0,0) ;
		CD::delete_rec(0) ;
	}
	char ch ;
	int tcode, tcopies, tavail ;
	char tname[33], tcatagory[6] ;
	float tprice=0.0 ;
	do
	{
		int found=0, valid=0 ;
		int tc ;
		float t2=0.0 ;
		char t[10], t1[10] ;
		clrscr() ;
		gotoxy(29,3) ;cout <<"ADDITION OF THE CDS" ;
		gotoxy(29,4) ;cout <<"~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
		gotoxy(5,25) ;cout<<"Enter code no. of the cd" ;
		gotoxy(5,5) ;cout <<"Code no. " ;
		gets(t) ;
		tc = atoi(t) ;
		tcode = tc ;
		if (tcode == 0)
			return ;
		if (cd_found(tcode))
		{
			found = 1 ;
			gotoxy(19,8) ;cout <<cdname(tcode) ;
			gotoxy(19,9) ;cout <<cat_class(tcode) ;
			gotoxy(22,10) ;cout <<cdprice(tcode) ;
		}
		gotoxy(5,8) ;cout <<"Cd Name   : " ;
		gotoxy(5,9) ;cout <<"type : " ;
		gotoxy(5,10) ;cout <<"Price       : Rs." ;
		gotoxy(5,12) ;cout <<"Copies      : " ;
		valid = 0 ;
		while (!valid && !found)
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter the name of the cd" ;
			gotoxy(19,8) ; clreol() ;
			gets(tname) ;
			strupr(tname) ;
			if (tname[0] == '0')
				return ;
			if (strlen(tname) < 1 || strlen(tname) > 32)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly (Range: 1..32)" ;
				getch() ;
			}
		}
		valid = 0 ;
		while (!valid && !found)
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter the type of the cd" ;
			gotoxy(19,9) ; clreol() ;
			gets(tcatagory) ;
			strupr(tcatagory) ;
			if (tcatagory[0] == '0')
				return ;
			if (strlen(tcatagory) < 1 || strlen(tcatagory) > 25)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly (Range: 1..25)" ;
				getch() ;
			}
		}
		valid = 0 ;
		while (!valid && !found)
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter the price of the cd" ;
			gotoxy(22,10) ; clreol() ;
			gets(t1) ;
			t2 = atof(t1) ;
			tprice = t2 ;
			if (t1[0] == '0')
				return ;
			if (tprice < 1 || tprice > 9999)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly" ;
				getch() ;
			}
		}
		valid = 0 ;
		while (!valid)
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter no. of copies of cd to be added" ;
			gotoxy(19,12) ; clreol() ;
			gets(t) ;
			tc = atoi(t) ;
			tcopies = tc ;
			if (t[0] == '0')
				return ;
			if (tcopies < 1 || tcopies > 50)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly" ;
				getch() ;
			}
		}
		tavail = available(tcode) + tcopies ;
		tcopies = no_of_copies(tcode) + tcopies ;
		gotoxy(5,25) ; clreol() ;
		do
		{
			gotoxy(5,15) ; clreol() ;
			cout <<"Do you want to save (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
 
		if (ch == 'Y')
		{
			if (found)
				update_copies(tcode,tcopies,tavail) ;
			else
	add_new_cd(tcode,tname,tcatagory,tprice,tcopies,tavail) ;
		}
		do
		{
			gotoxy(5,17) ; clreol() ;
			cout <<"Do you want to add more (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
		} while (ch != 'Y' && ch != 'N') ;
	} while (ch == 'Y') ;
}
void WORKING :: add_member(void)
{
	char ch ;
	int mcode, ccode ;
	char mname[26], mphone[10], maddress[33] ;
	int d1, m1, y1 ;
	mcode = lastcode() ;
	mcode++ ;
	do
	{
		int valid=0 ;
		clrscr() ;
		gotoxy(28,3) ;cout <<"ADDITION OF THE MEMBERS" ;
		gotoxy(28,4) ;cout <<"~~~~~~~~~~~~~~~~~~~~~~~" ;
		gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
		gotoxy(5,7) ;cout<<"Member Code # " <<mcode ;
		gotoxy(5,8) ;cout <<"~~~~~~~~~~~~~~~~~" ;
		gotoxy(5,10) ;cout <<"Name    : " ;
		gotoxy(5,12) ;cout <<"Phone   : " ;
		gotoxy(5,14) ;cout <<"Address : " ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter the name of the New Member" ;
			gotoxy(15,10) ; clreol() ;
			gets(mname) ;
			strupr(mname) ;
			if (mname[0] == '0')
				return ;
			if (strlen(mname) < 1 || strlen(mname) > 25)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly (Range: 1..25)" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter Phone no. of the Member or Press <ENTER> for none" ;
			gotoxy(15,12) ; clreol() ;
			gets(mphone) ;
			if (mphone[0] == '0')
				return ;
			if ((strlen(mphone) < 7 && strlen(mphone) > 0) || (strlen(mphone) > 9))
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly" ;
				getch() ;
			}
		} while (!valid) ;
		if (strlen(mphone) == 0)
			strcpy(mphone,"-") ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter the address of the New Member" ;
			gotoxy(15,14) ; clreol() ;
			gets(maddress) ;
			strupr(maddress) ;
			if (maddress[0] == '0')
				return ;
			if (strlen(maddress) < 1 || strlen(maddress) > 32)
			{
				valid = 0 ;
				gotoxy(5,25) ; clreol() ;
				cout<<"\7Enter correctly (Range: 1..32)" ;
				getch() ;
			}
		} while (!valid) ;
		gotoxy(5,25) ; clreol() ;
		do
		{
			gotoxy(5,17) ; clreol() ;
			cout <<"Do you want to save (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'Y')
		{
			ccode = 0 ;
			d1 = 0 ;
			m1 = 0 ;
			y1 = 0 ;
			add_mem(mcode,ccode,mname,maddress,mphone,d1,m1,y1) ;
			mcode++ ;
		}
		do
		{
			gotoxy(5,19) ; clreol() ;
			cout <<"Do you want to add more (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'Y' && ch != 'N') ;
	} while (ch == 'Y') ;
}
void WORKING :: issuecd(void)
{
	CD C ;
	MEMBER M ;
	DATE D ;
	char t1code[33], ch ;
	int t2code=0, tcode=0, mcode=0 ;
	int valid ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(5,2) ;cout <<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,5) ;cout<<"Enter Code or Name of the cd to be issued" ;
			gotoxy(5,6) ;cout <<"                  or                       " ;
			gotoxy(5,7) ;cout <<"Press <ENTER> for help  " ;
			gets(t1code) ;
			if (t1code[0] == '0')
				return ;
			if (strlen(t1code) == 0)
				C.list() ;
			else
				break ;
		}
		t2code = atoi(t1code) ;
		tcode = t2code ;
		if((tcode==0&&!cdname_found(t1code))||(tcode!=0&&!cd_found(tcode)))
		{
			valid = 0 ;
			gotoxy(5,10) ;cout<<"\7Record not found" ;
			gotoxy(5,11) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	if (tcode == 0)
		tcode = cdcodeof(t1code) ;
	if (!available(tcode))
	{
		gotoxy(5,10) ;cout<<"\7Sorry! cd (" <<cdname(tcode) <<") is not available" ;
		gotoxy(5,11) ;cout <<"Kindly issue any other cd" ;
		gotoxy(5,12) ;cout <<"See List of cds" ;
		getch() ;
		return ;
	}
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,2) ;cout<<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
			gotoxy(5,5) ;cout <<"cd Name: " <<cdname(tcode) ;
			gotoxy(5,7) ;cout <<"Enter Code no. of the Member" ;
			gotoxy(5,8) ;cout <<"            or              " ;
			gotoxy(5,9) ;cout <<"Press <ENTER> for help  " ;
			gets(t1code) ;
			if (t1code[0] == '0')
				return ;
			if (strlen(t1code) == 0)
				M.list() ;
			else
				break ;
		}
		t2code = atoi(t1code) ;
		mcode = t2code ;
		if (mcode == 0)
		{
			valid = 0 ;
			gotoxy(5,25) ;cout<<"\7Enter Correctly" ;
			getch() ;
		}
		if (!member_found(mcode) && valid)
		{
			valid = 0 ;
			gotoxy(5,13) ;cout <<"\7Record not found" ;
			gotoxy(5,14) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	int tcopies, tavail ;
	tcopies = no_of_copies(tcode) ;  // member function of BOOK
	tavail  = available(tcode) - 1 ;  // member function of BOOK
	update_copies(tcode,tcopies,tavail) ;  // member function of BOOK
	D.extend_date(d1,m1,y1,15) ;
	d1 = D.day ;
	m1 = D.mon ;
	y1 = D.year ;
	update_cd(mcode,tcode,d1,m1,y1) ;  // member function of MEMBER
	gotoxy(5,13) ;cout<<"\7cd is issued to " <<membername(mcode) ;
	gotoxy(5,15) ;cout <<"Date of Return : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	getch() ;
}
void WORKING :: returncd(void)
{
	MEMBER M ;
	char t1code[5], ch ;
	int t2code=0, mcode=0, valid ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,2) ;cout<<"Date : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
			gotoxy(5,7) ;cout <<"Enter Code no. of the Member who wants to return cd" ;
			gotoxy(5,8) ;cout <<"                        or              " ;
			gotoxy(5,9) ;cout <<"Press <ENTER> for help  " ;
			gets(t1code) ;
			if (t1code[0] == '0')
				return ;
			if (strlen(t1code) == 0)
				M.list() ;
			else
				break ;
		}
		t2code = atoi(t1code) ;
		mcode = t2code ;
		if (mcode == 0)
		{
			valid = 0 ;
			gotoxy(5,25) ;cout<<"\7Enter Correctly" ;
			getch() ;
		}
		if (!member_found(mcode) && valid)
		{
			valid = 0 ;
			gotoxy(5,13) ;cout <<"\7Record not found" ;
			gotoxy(5,14) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
		if (!issued(mcode) && valid)
		{
			valid = 0 ;
			gotoxy(5,13) ;cout<<"\7Member have no cd to return" ;
			gotoxy(5,14) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	int ccode, tcopies, tavail ;
	ccode = issued(mcode) ;
	gotoxy(5,13) ;cout<<"cd Code : " <<ccode ;
	gotoxy(5,14) ;cout <<"cd Name : " <<cdname(ccode) ;
	tcopies = no_of_copies(ccode) ;
	tavail = available(ccode) + 1 ;
	long int f ;
	f = fine(mcode) ;
	if (f != 0)
	{
		gotoxy(5,16) ;cout <<"You have to pay a fine of Rs." <<f ;
		gotoxy(5,17) ;cout <<"Please do not delay the Return of cd again" ;
	}
	update_copies(ccode,tcopies,tavail) ;
	update_cd(mcode,0,0,0,0) ;
	gotoxy(5,19) ;cout <<"\7cd has been returned" ;
	getch() ;
}
void WORKING :: modify_cd(void)
{
	CD C ;
	char t1code[5], tname[33], tcatagory[6], *t1, ch ;
	int t2code=0, tcode=0 ;
	float t2=0.0, tprice=0.0 ;
	int valid ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,5) ;cout<<"Enter Code or Name of the cd to be modified" ;
			gotoxy(5,6) ;cout <<"                  or                       " ;
			gotoxy(5,7) ;cout <<"Press <ENTER> for help  " ;
			gets(t1code) ;
			if (t1code[0] == '0')
				return ;
			if (strlen(t1code) == 0)
				C.list() ;
			else
				break ;
		}
		t2code = atoi(t1code) ;
		tcode = t2code ;
		if((tcode==0&&!cdname_found(t1code))||(tcode!=0&&!cd_found(tcode)))
		{
			valid = 0 ;
			gotoxy(5,10) ;cout<<"\7Record not found" ;
			gotoxy(5,11) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	if (tcode == 0)
		tcode = cdcodeof(t1code) ;
	clrscr() ;
	gotoxy(72,1) ;cout<<"&lt;0>=Exit" ;
	CD::display(tcode) ;
	do
	{
		gotoxy(5,13) ; clreol() ;
		cout<<"Do you want to modify this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	gotoxy(5,16) ;cout <<"CD Name   : " ;
	gotoxy(5,17) ;cout <<"type : " ;
	gotoxy(5,18) ;cout <<"Price       : Rs." ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the name of the cd or <ENTER> for no change" ;
		gotoxy(19,16) ; clreol() ;
		gets(tname) ;
		strupr(tname) ;
		if (tname[0] == '0')
			return ;
		if (strlen(tname) > 32)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly (Range: 1..32)" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(tname) == 0)
		strcpy(tname,cdname(tcode)) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the type or <ENTER> for no change" ;
		gotoxy(19,17) ; clreol() ;
		gets(tcatagory) ;
		strupr(tcatagory) ;
		if (tcatagory[0] == '0')
			return ;
		if (strlen(tcatagory) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly (Range: 1..25)" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(tcatagory) == 0)
		strcpy(tcatagory,cat_class(tcode)) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter price or <ENTER> for no change" ;
		gotoxy(22,18) ; clreol() ;
		gets(t1) ;
		t2 = atof(t1) ;
		tprice = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
			break ;
		if (tprice < 1 || tprice > 9999)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t1) == 0)
		tprice = cdprice(tcode) ;
	gotoxy(5,25) ; clreol() ;
	do
	{
		gotoxy(5,20) ; clreol() ;
		cout <<"Do you want to save changes (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	CD::modify(tcode,tname,tcatagory,tprice) ;
	gotoxy(5,23) ;cout <<"\7Record Modified" ;
	getch() ;
}
void WORKING :: modify_member(void)
{
	MEMBER M ;
	char m1code[10], mname[26], mphone[10], maddress[33], ch ;
	int m2code=0, mcode=0 ;
	int valid ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,7) ;cout<<"Enter Code no. of the Member to be Modify" ;
			gotoxy(5,8) ;cout <<"                        or              " ;
			gotoxy(5,9) ;cout <<"Press <ENTER> for help  " ;
			gets(m1code) ;
			m2code = atoi(m1code) ;
			mcode = m2code ;
			if (m1code[0] == '0')
				return ;
			if (strlen(m1code) == 0)
				M.list() ;
			else
				break ;
		}
		if (mcode == 0)
		{
			valid = 0 ;
			gotoxy(5,25) ;cout<<"\7Enter Correctly" ;
			getch() ;
		}
		if (valid && !member_found(mcode))
		{
			valid = 0 ;
			gotoxy(5,13) ;cout <<"\7Record not found" ;
			gotoxy(5,14) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	clrscr() ;
	gotoxy(72,1) ;cout<<"&lt;0>=Exit" ;
	MEMBER::display(mcode) ;
	do
	{
		gotoxy(5,10) ; clreol() ;
		cout<<"Do you want to modify this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	gotoxy(5,13) ;cout <<"Name    : " ;
	gotoxy(5,14) ;cout <<"Phone   : " ;
	gotoxy(5,15) ;cout <<"Address : " ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the name of the member or <ENTER> for no change" ;
		gotoxy(19,13) ; clreol() ;
		gets(mname) ;
		strupr(mname) ;
		if (mname[0] == '0')
			return ;
		if (strlen(mname) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly (Range: 1..25)" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(mname) == 0)
		strcpy(mname,membername(mcode)) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the Phone no. of Member or <ENTER> for no change" ;
		gotoxy(19,14) ; clreol() ;
		gets(mphone) ;
		if (mphone[0] == '0')
			return ;
		if((strlen(mphone)<7 && strlen(mphone)>0)||(strlen(mphone)>9))
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(mphone) == 0)
		strcpy(mphone,memberphone(mcode)) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the address of the member or <ENTER> for no change" ;
		gotoxy(19,15) ; clreol() ;
		gets(maddress) ;
		strupr(maddress) ;
		if (maddress[0] == '0')
			return ;
		if (strlen(maddress) > 32)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout<<"\7Enter correctly (Range: 1..32)" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(maddress) == 0)
		strcpy(maddress,memberaddress(mcode)) ;
	gotoxy(5,25) ; clreol() ;
	do
	{
		gotoxy(5,18) ; clreol() ;
		cout <<"Do you want to save changes (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	MEMBER::modify(mcode,mname,mphone,maddress) ;
	gotoxy(5,23) ;cout <<"\7Record Modified" ;
	getch() ;
}
void WORKING :: delete_cd(void)
{
	CD C ;
	char t1code[5], tname[33], tcatagory[6], ch ;
	int t2code=0, tcode=0 ;
	int valid ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,5) ;cout<<"Enter Code or Name of the cd to be Deleted" ;
			gotoxy(5,6) ;cout <<"                  or                       " ;
			gotoxy(5,7) ;cout <<"Press <ENTER> for help  " ;
			gets(t1code) ;
			if (t1code[0] == '0')
				return ;
			if (strlen(t1code) == 0)
				C.list() ;
			else
				break ;
		}
		t2code = atoi(t1code) ;
		tcode = t2code ;
		if((tcode==0&&!cdname_found(t1code))||(tcode!=0&&!cd_found(tcode)))
		{
			valid = 0 ;
			gotoxy(5,10) ;cout<<"\7Record not found" ;
			gotoxy(5,11) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	if (tcode == 0)
		tcode = cdcodeof(t1code) ;
	clrscr() ;
	gotoxy(72,1) ;cout<<"&lt;0>=Exit" ;
	CD::display(tcode) ;
	do
	{
		gotoxy(5,13) ; clreol() ;
		cout<<"Do you want to delete this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	int tavail, tcopies ;
	tavail = available(tcode) ;
	tcopies = no_of_copies(tcode) ;
	if (tavail != tcopies)
	{
		gotoxy(5,15) ;cout <<"\7Record cannot be deleted. This cd is issued." ;
		getch() ;
		return ;
	}
	CD::delete_rec(tcode) ;
	gotoxy(5,23) ;cout <<"\7Record Deleted" ;
	getch() ;
}
void WORKING :: delete_member(void)
{
	MEMBER M ;
	char m1code[5], mname[26], mphone[10], maddress[33], ch ;
	int m2code=0, mcode=0 ;
	int valid ;
	do
	{
		valid = 1 ;
		while (1)
		{
			clrscr() ;
			gotoxy(72,1) ;cout <<"&lt;0>=Exit" ;
			gotoxy(5,7) ;cout<<"Enter Code no. of the Member to be Deleted" ;
			gotoxy(5,8) ;cout <<"                        or              " ;
			gotoxy(5,9) ;cout <<"Press <ENTER> for help  " ;
			gets(m1code) ;
			m2code = atoi(m1code) ;
			mcode = m2code ;
			if (m1code[0] == '0')
				return ;
			if (strlen(m1code) == 0)
				M.list() ;
			else
				break ;
		}
		if (mcode == 0)
		{
			valid = 0 ;
			gotoxy(5,25) ;cout<<"\7Enter Correctly" ;
			getch() ;
		}
		if (valid && !member_found(mcode))
		{
			valid = 0 ;
			gotoxy(5,13) ;cout <<"\7Record not found" ;
			gotoxy(5,14) ;cout <<"Press <ESC> to exit or any other key to continue..." ;
			ch = getch() ;
			if (ch == 27)
				return ;
		}
	} while (!valid) ;
	clrscr() ;
	gotoxy(72,1) ;cout<<"&lt;0>=Exit" ;
	MEMBER::display(mcode) ;
	do
	{
		gotoxy(5,10) ; clreol() ;
		cout<<"Do you want to Delete this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	if (issued(mcode))
	{
		gotoxy(5,15) ;cout <<"\7Record cannot be delete. Member has a cd" ;
		getch() ;
		return ;
	}
	MEMBER::delete_rec(mcode) ;
	gotoxy(5,23) ;cout <<"\7Record Modified" ;
	getch() ;
}
void main()
{
	introduction() ;
	MENU menu ;
	menu.main_menu() ;
	getch();
}
