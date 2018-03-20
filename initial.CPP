
//**********************************************************
//	PROJECT    : WATER QUALITY INDEX
//      Prepared by: BHASKAR SEN 

//**********************************************************

//**********************************************************
//	INCLUDED HEADER FILES
//**********************************************************

#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//**********************************************************
class control
{
	public :
			void main_menu(void) ;
			void help(void) ;
	private :
			void edit_menu(void) ;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO INITIAL DEPOSIT
//**********************************************************

class initial
{
	public :
			void add_to_file(int, char t_name[30], char t_state[60], int, int) ;
			void display_list(void) ;
			void delete_data(int) ;
			void update_data(int, int) ;
			void modify(void) ;
			int  last_rno(void) ;
			int  found_data(int) ;
			char *return_name(int) ;
			char *return_state(int) ;
			int give_bod(int) ;
			int give_pH(int);
			int  recordno(int) ;
			void display(int) ;
			void staterec(char st[23]);
			void display_record()
			{
			  cout<<"\n River No="<<rno;
			  cout<<"\n Name="<<name;
			  cout<<"\n State="<<state;
			  cout<<"\n BOD="<<bod;
			  cout<<"\nPH="<<pH;
			  getch();
			}
	private :
			void  modify_data(int, char t_name[30], char t_state[60], int t_bod, int t_pH) ;
			void  box_for_list(void) ;

			int   rno ;
			char  name[30], state[60] ;
			int bod,t_bod ;
			int pH,t_pH;
} ;


//**********************************************************
// THIS CLASS CONTAINS FUNCTIONS RELATED TO TRANSACTIONS
//**********************************************************

class record
{
	public :
			void new_record(void) ;
			void close_record(void) ;
			void display_record(void) ;
			void clear(int,int) ;
	private :
			void  add_to_file(int,int,int) ;
			void  delete_record(int) ;
			void  display(int) ;
			void  box_for_display(int) ;

			int   rno ;
			char t_name[30], t[10], t_state[60] ;
			int t_p, t_pH,t_bod ;
			int bod,pH;

} ;

//**********************************************************
// FUNCTION TO DISPLAY MAIN MENU AND CALL OTHER FUNCTIONS
//**********************************************************

void control :: main_menu(void)
{
	char ch ;
	clrscr();
	while (1)
	{
		clrscr() ;
		gotoxy(32,7) ;
		cout<<" WATER QUALITY INDEX" ;
		gotoxy(38,10) ;
		cout<<" OPTIONS " ;
		gotoxy(30,12) ;
		cout <<"1: LIST OF ANALYSIS DONE" ;
		gotoxy(30,14) ;
		cout <<"2: CREATE NEW RIVER DATA" ;
		gotoxy(30,16);
		cout <<"3: EDIT DATA" ;
		gotoxy(30,18) ;
		cout <<"4: WATER QUALITY REPORT" ;
		gotoxy(30,20) ;
		cout <<"5: HELP" ;
		gotoxy(30,22);
		cout<<"6: STATE WISE ANLYSIS";
		gotoxy(30,24) ;
		cout <<"0: QUIT" ;
		cout<<"\t EXIT:<ESC>";
		gotoxy(29,26) ;
		cout <<"Enter your choice: " ;


		ch=getche();


		record a;
		switch(ch)
		{
		case '1':
			initial ini ;            //FOR LIST OF ANALYSIS DONE
			ini.display_list() ;
			 break;
		 case '2':
			a.new_record() ;         //CREATE NEW RIVER DATA
			break;
		 case '3':
			edit_menu() ;            //EDIT DATA
			break;
		 case '4':
			a.display_record() ;      //WATER QUALITY REPORT"
			break;
		 case '5':
			help();                     //help

			break;
		 case '6':
			char st[23];
			ini.staterec(st);	  //state wise rec				 default: exit(0);
			break;

			default: exit(0);
	       }
       }
}


//**********************************************************
// FUNCTION TO DISPLAY EDIT MENU AND CALL OTHER FUNCTIONS
//**********************************************************

void control :: edit_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		gotoxy(34,10) ;
		cout<<" EDIT MENU " ;
		gotoxy(31,12) ;
		cout <<"1: MODIFY DATA" ;
		gotoxy(31,13) ;
		cout <<"2: DELETE DATA" ;
		gotoxy(31,14) ;
		cout <<"0: QUIT" ;
		gotoxy(31,16) ;
		cout <<"Enter your choice: " ;
		ch = getche() ;
		getch();
		control c;
		switch(ch)
		 {
		 case '1':
			initial ini ;
			ini.modify() ;
			break ;
		 case '2':
			record a ;
			a.close_record() ;
			break ;
		 default: c.main_menu();
			break ;
		 }
	}
}



//**********************************************************
// FUNCTION TO DISPLAY HELP ABOUT PROJECT
//**********************************************************

void control :: help(void)
{
	clrscr() ;
	gotoxy(29,3); cout<<"WELCOME TO PROJECT WQI";
	gotoxy(10,6);  cout <<"In  this  Project  you  can keep  record  of  various rivers" ;
	gotoxy(10,7);  cout <<" ANALYSE REPORT      " ;
	gotoxy(10,9);  cout <<"      -> This  program is capable of holding any no. of records." ;
	gotoxy(10,11); cout <<"- In  first option you can see the list of all the rivers" ;
	gotoxy(10,12); cout <<"  river by giving simply record number" ;
	gotoxy(10,14); cout <<"- Through second option you can add data of a new river." ;
	gotoxy(10,16); cout <<"- In third option you can modify or delete any data.";
	gotoxy(10,18); cout <<"- In Fourth option you can see the report of a particular sample";
	gotoxy(10,20); cout <<"- In Fifth option you can access the help screen" ;
	gotoxy(10,22); cout <<"- And last option is Quit (Exit to Dos).  " ;
	gotoxy(26,25) ; cout<<" Press any key to continue.... ";
	getch() ;
}


//**********************************************************
// THIS FUNCTION RETURN LAST RECORD NO. IN THE FILE
// INITIAL.DAT
//**********************************************************

int initial :: last_rno(void)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;           //MOVING FILE POINTER TO BEG
	int count=0 ;
	while (file.read((char *) this, sizeof(initial)))
	{
		count = rno ;              //RECORDS COUNTED
	}
	file.close() ;
	getch();
	return count ;
}


//**********************************************************
// THIS FUNCTION RETURN RECORD NO. OF THE GIVEN RECORD NO.
// IN THE FILE INITIAL.DAT
//**********************************************************

int initial :: recordno(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(initial)))
	{
		count++ ;
		if (t_rno == rno)
			break ;
	}
	file.close() ;
	return count ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD FOR GIVEN RECORD NO.
// FROM THE FILE INITIAL.DAT
//**********************************************************

void initial :: display(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (t_rno == rno)
		{
			gotoxy(8,5) ;
			cout <<"RIVER NO. " <<rno ;
			gotoxy(10,8) ;
			cout <<"Name of river    : " <<name ;
			gotoxy(10,9) ;
			cout <<"State : " <<state ;
			gotoxy(10,10) ;
			cout <<"BOD : " <<bod ;
			gotoxy(10,11);
			cout<<"pH  : "<<pH;
			break ;
		}
	}
	file.close() ;
}


//**********************************************************
// THIS FUNCTION RETURN NAME FOR THE GIVEN RECORD NO.
// IN THE FILE INITIAL.DAT
//**********************************************************

char *initial :: return_name(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char t_name[30] ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (rno == t_rno)
		{
			strcpy(t_name,name) ;
			break ;
		}
	}
	file.close() ;
	return t_name ;
}


//**********************************************************
// THIS FUNCTION RETURN STATE FOR THE GIVEN RIVER NO.
// IN THE FILE INITIAL.DAT
//**********************************************************

char *initial :: return_state(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char t_state[60] ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (rno == t_rno)
		{
			strcpy(t_state,state) ;
			break ;
		}
	}
	file.close() ;
	return t_state ;
}


//**********************************************************
// THIS FUNCTION RETURN BOD FOR THE GIVEN RECORD NO.
// IN THE FILE INITIAL.DAT
//**********************************************************

int initial :: give_bod(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int t_bod ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (rno == t_rno)
		{
			t_bod =bod ;
			break ;
		}
	}
	file.close() ;
	return t_bod ;
}
/********************************************************
THIS FUNCTION RETURN pH FOR GIVEN RECORD NO. IN THE FILE
INITIAL.DAT
*********************************************************/
int initial :: give_pH(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int t_pH ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (rno == t_rno)
		{
			t_pH = pH ;
			break ;
		}
	}
	file.close() ;
	return t_pH ;
}

//**********************************************************
// THIS FUNCTION RETURN 1 IF THE GIVEN RECORD NO. FOUND
// IN THE FILE INITIAL.DAT
//**********************************************************

int initial :: found_data(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(initial)))
	{
		if (rno == t_rno)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}



//**********************************************************
// THIS FUNCTION DRAWS THE BOX FOR THE LIST OF ANALYSIS DONE
//**********************************************************

void initial :: box_for_list()        //FOR LAYOUT OF DISPLAY
{
	gotoxy(4,4) ;
	cout<<"RIVER NO.          NAME OF RIVER                     STATE";
}


//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF RECORD IN FILE
// INITIAL.DAT
//**********************************************************

void initial :: display_list(void)
{
	clrscr() ;
	box_for_list() ;
	int row=6, flag ;
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(initial)))
	{
		flag = 0 ;
		gotoxy(7,row) ;
		cout <<rno ;
		gotoxy(25,row) ;
		cout <<name ;
		gotoxy(57,row) ;
		puts(state) ;
		row++ ;
		if (row == 23)
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(4,24) ;
			cout <<"Press any key to see more records..." ;
			getch() ;
			clrscr() ;
			box_for_list() ;
		}
	}
	file.close() ;
	if (!flag)
	{
		gotoxy(4,24) ;
		cout <<"Press any key to continue..." ;
		getch() ;
	}
}


//**********************************************************
// THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE
// INITIAL.DAT
//**********************************************************

void initial :: add_to_file(int t_rno, char t_name[30], char t_state[60], int t_bod , int t_pH)
{
	rno = t_rno ;
	strcpy(name,t_name) ;
	strcpy(state,t_state) ;
	bod = t_bod ;
	pH = t_pH;
	fstream file ;
	file.open("INITIAL.DAT", ios::binary|ios::out|ios::app) ;
	  file.write((char *) this, sizeof(initial)) ;

	  getch();
	file.close() ;
}


//**********************************************************
// THIS FUNCTION DELETES DATA FOR THE GIVEN RECORD NO.
// FROM THE FILE INITIAL.DAT
//**********************************************************

void initial :: delete_data(int t_rno)
{
	fstream file ;
	file.open("INITIAL.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(initial)))// ; !file.eof() )
	{
	       //	file.read((char *) this, sizeof(initial)) ;

		if ( file.eof() )
			break ;
		if ( rno != t_rno )
		{
			temp.write((char *) this, sizeof(initial)) ;
			 getch();
	       }
	}
	file.close() ;
	temp.close() ;
	file.open("INITIAL.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( temp.read((char *) this, sizeof(initial)))// ;!temp.eof() )
	{
		//temp.read((char *) this, sizeof(initial)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(initial)) ;
		getch();
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION UPDATE BOD FOR THE GIVEN RECORD NO.
// IN THE FILE INITIAL.DAT
//**********************************************************

void initial :: update_data(int t_rno, int t_bod)
{
	int recno ;
	recno = recordno(t_rno) ;
	fstream file ;
	file.open("INITIAL.DAT", ios::out | ios::ate) ;
	bod = t_bod ;
	int location ;
	location = (recno-1) * sizeof(initial) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(initial)) ;
	file.close() ;
}



//**********************************************************
// THIS FUNCTION MODIFIES THE RECORD FOR THE GIVEN DATA
// IN THE FILE INITIAL.DAT
//**********************************************************

void initial :: modify_data(int t_rno, char t_name[30], char t_state[60], int t_bod, int t_pH)
{
	int recno;
	recno = recordno(t_rno) ;
	fstream file ;
	file.open("INITIAL.DAT", ios::out | ios::ate) ;
	strcpy(name,t_name) ;
	strcpy(state,t_state) ;
	bod = t_bod;
	pH = t_pH;
	int location ;
	location = (recno-1) * sizeof(initial) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(initial)) ;
	file.close() ;
}



//**********************************************************
// THIS FUNCTION GIVE THE DATA TO MODIFY THE RECORD IN THE
// FILE INITIAL.DAT
//**********************************************************

void initial :: modify(void)
{
	clrscr() ;
	char t_acc[10] ;
	int t, t_rno ;
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,5) ;
	cout <<"Enter the sample no. " ;
	gets(t_acc) ;
	t = atoi(t_acc) ;
	t_rno = t ;
	if (t_rno == 0)
		return ;
	clrscr() ;
	if (!found_data(t_rno))
	{
		gotoxy(5,5) ;
		cout <<"\7sample not found" ;
		getch() ;
		return ;
	}
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(3,3) ;
	cout<<" ";
	gotoxy(30,3) ;
	char ch ;
	display(t_rno) ;
	record a ;
	do
	{
		a.clear(5,13) ;
		gotoxy(5,13) ;
		cout <<"Modify this river's data (y/n): " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	int modified=0, valid ;
	char t_name[30], t_state[60] ;
	int t_bod,t_pH;
	gotoxy(5,15) ;
	cout <<"Name of river: " ;
	gotoxy(5,16) ;
	cout <<"State: " ;
	gotoxy(5,17);
	cout<<"BOD: ";
	gotoxy(5,18);
	cout<<"pH: ";
	do
	{
		a.clear(20,15) ;
		a.clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER NAME ";
		valid = 1 ;
		gotoxy(20,15) ;
		gets(t_name) ;
		strupr(t_name) ;
		if (t_name[0] == '0')
			return ;
		if (strlen(t_name) > 25)
		{
			valid = 0 ;
			gotoxy(5,23) ;
			cout<<"\7NAME SHOULD NOT GREATER THAN 25" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t_name) > 0)
		modified = 1 ;
	do
	{
		a.clear(15,16) ;
		a.clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER STATE +" ;
		valid = 1 ;
		gotoxy(15,16) ;
		gets(t_state) ;
		strupr(t_state) ;
		if (t_state[0] == '0')
			return ;
		if (strlen(t_state) > 55)
		{
			valid = 0 ;
			gotoxy(5,23) ;
			cout<<"\7SHOULD NOT BLANK OR GREATER THAN 55" ;
			getch() ;
		}
	} while (!valid) ;
	if (strlen(t_state) > 0)
		modified = 1 ;

       do
       {       a.clear(15,17);
	       a.clear(5,23);
	       gotoxy(5,23);
	       cout<<"enter the new BOD : ";
	       valid=1;
	       gotoxy(15,17);
	       cin>>t_bod;
	       if(t_bod==0)
	       return;

       }while(!valid);
       if(t_bod>=0)
       modified=1;
       do
       {       a.clear(15,18);
	       a.clear(5,23);
	       gotoxy(5,23);
	       cout<<"ENTER THE pH : ";
	       valid=1;
	       gotoxy(15,18);
	       cin>>t_pH;
	       if(t_pH==0)
	       return;
	       if (t_pH > 14)
		{
			valid = 0 ;
			gotoxy(5,23) ;
			cout<<"\7pH SHOULD NOT GREATER THAN 14" ;
			getch() ;
		}


       }while(!valid);
       if(t_pH<15)
       modified=1;

       if (!modified)
		return ;
       a.clear(5,23) ;
	do
	{
		a.clear(5,19) ;
		gotoxy(5,19) ;
		cout <<"Do you want to save changes (y/n): " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	modify_data(t_rno,t_name,t_state,t_bod,t_pH) ;
	gotoxy(5,21) ;
	cout <<"\7Record Modified" ;
	gotoxy(5,23) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}


//**********************************************************
// THIS FUNCTION CLEAR THE GIVEN ROW AND COLUMNS
//**********************************************************

void record :: clear(int col, int row)
{
	for (int i=col; i<=78; i++)
	{
		gotoxy(i,row) ;
		cout <<" " ;
	}
}


//**********************************************************
// THIS FUNCTION ADDS THE GIVEN DATA INTO THE FILE
// WQI.DAT
//**********************************************************

void record :: add_to_file(int t_rno,int t_bod,int t_pH)
{
	fstream file ;
	file.open("WQI.DAT", ios::app) ;
	rno = t_rno ;
	bod = t_bod ;
	pH = t_pH;
	file.write((char *) this, sizeof(record)) ;
	file.close() ;
}


///*********************************************************
// THIS FUNCTION DELETES THE RECORD FOR GIVEN SAMPLE NO.
// FROM FILE WQI.DAT
//**********************************************************

void record :: delete_record(int t_rno)
{
	fstream file ;
	file.open("WQI.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( file.read((char *) this, sizeof(record)))// ;!file.eof() )
	{
	       //	file.read((char *) this, sizeof(record)) ;
		if ( file.eof() )
			break ;
		if ( rno != t_rno )
			temp.write((char *) this, sizeof(record)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("WQI.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( temp.read((char *) this, sizeof(record)))// ;!temp.eof() )
	{
//		temp.read((char *) this, sizeof(record)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(record)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION ACCEPTS THE DATA TO ADD RECORDS IN THE
// FILE WQI.DAT
//**********************************************************

void record :: new_record(void)
{
	char ch ;
	int i, valid ;
	clrscr() ;
	initial ini ;
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(3,3) ;
	for (i=1; i<=76; i++) cout<<" ";
	gotoxy(32,3) ;
	cout<<"ADD NEW RECORD" ;
	int t_rno ;
	t_rno = ini.last_rno() ;
	t_rno++ ;
	cout<<t_rno;
	getch();
	if (t_rno == 1)
	{
		ini.add_to_file(t_rno,"abc","xyz",1,1) ;

			ini.delete_data(t_rno) ;
		add_to_file(t_rno,1,1) ;
		delete_record(t_rno) ;
	}

	gotoxy(5,8) ;
	cout <<"Sample no. # " <<t_rno ;
	gotoxy(5,10) ;
	cout <<"Name of river : " ;
	gotoxy(5,12) ;
	cout <<"State from which sample is taken : " ;
	gotoxy(5,14) ;
	cout <<"BOD level : " ;
	gotoxy(5,16) ;
	cout <<"pH : " ;
	do
	{	clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER NAME OF THE RIVER" ;
		valid = 1 ;
		gotoxy(21,10) ;
		gets(t_name) ;
		strupr(t_name) ;
		if (t_name[0] == '0')
			return ;
		if (strlen(t_name) == 0 || strlen(t_name) > 25)
		{
			valid = 0 ;
			gotoxy(5,23) ;
			cprintf("\7NAME SHOULD NOT BLANK OR GREATER THAN 25") ;
			getch() ;
		}
	} while (!valid) ;
	do
	{	clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER STATE FROM WHERE SAMPLES ARE TAKEN" ;
		valid = 1 ;
		gotoxy(40,12) ;
		gets(t_state) ;
		strupr(t_state) ;
		if (t_state[0] == '0')
			return ;
		if (strlen(t_state) == 0 || strlen(t_state) > 55)
		{
			valid = 0 ;
			gotoxy(5,23) ;
			cprintf("\7SHOULD NOT BLANK OR GREATER THAN 55") ;
			getch() ;
		}
	} while (!valid) ;
	do
	{	clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER BOD LEVEL" ;
		valid = 1 ;
		gotoxy(18,14) ;
		cin>>t_bod;
		if (t_bod == 0)
			return ;

	} while (!valid) ;
	do
	{
		clear(23,14) ;
		clear(5,23) ;
		gotoxy(5,23) ;
		cout <<"ENTER pH" ;
		valid = 1 ;
		gotoxy(10,16) ;
		cin>>t_pH ;
		if (t_pH == '0')
			return ;
		if (t_pH > 14)
		{
			valid = 0 ;
			clear(5,23);
			gotoxy(5,23) ;
			cout<<"\7SHOULD NOT GREATER THAN 14          " ;
			getch() ;
		}
	} while (!valid) ;
	clear(5,23) ;
	do
	{
		clear(5,17) ;
		valid = 1 ;
		gotoxy(5,17) ;
		cout <<"Do you want to save the record (y/n) : " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	float t_sno, t_interest ;
	t_sno = t_pH;
	ini.add_to_file(t_rno,t_name,t_state,t_bod,t_pH);
	add_to_file(t_rno,t_sno,t_pH) ;
}


//**********************************************************
// THIS FUNCTION DRAWS THE BOX FOR DISPLAYING RECORD FROM
// FILE WQI.DAT
//**********************************************************

void record :: box_for_display(int t_rno)
{
	gotoxy(4,2) ;
	cout <<"Sample no. " <<t_rno ;
	initial ini ;
	char t_name[30] ;
	strcpy(t_name,ini.return_name(t_rno)) ;
	char t_state[60] ;
	strcpy(t_state,ini.return_state(t_rno)) ;
	int b;
	b=ini.give_bod(t_rno);
	int p;
	p=ini.give_pH(t_rno);
	gotoxy(5,5) ;
	cout<<"This water sample is of "<<t_name<<" river. ";
	gotoxy(5,7) ;
	cout<<"It is taken from "<<t_state<<" state. ";
	gotoxy(5,9);
	cout<<"Its BOD(Biological Oxygen Demand) level is "<<b<<" ppm.";
	gotoxy(5,11);
	cout<<"The normal level of BOD is 100 ppm.";
	gotoxy(5,13);
	if(b==100)
	cout<<"This river fulfills the demand of oxygen for its aquatic life.";
	else
	cout<<"This river doesnot fulfill the demand of oxygen for its aquatic life.";
	gotoxy(5,15);
	cout<<"Its pH is "<<p<<".";
	gotoxy(5,17);
	if(p<6)
	cout<<"Water is ACIDIC in nature and not fit for drinking.";
	else if(p>8)
	cout<<"Water is BASIC in nature and not fit for drinking. ";
	else
	cout<<"It is NEUTRAL and fit for drinking. ";
	getch();

}

//**********************************************************
// THIS FUNCTION DISPLAY RECORD FROM THE FILE WQI.DAT
//**********************************************************

void record :: display_record(void)
{
	clrscr() ;
	char t_acc[10] ;
	int t, t_rno ;
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,5) ;
	cout <<"Enter the sample no. " ;
	gets(t_acc) ;
	t = atoi(t_acc) ;
	t_rno = t ;
	if (t_rno == 0)
		return ;
	clrscr() ;
	initial ini ;
	if (!ini.found_data(t_rno))
	{
		gotoxy(5,5) ;
		cout <<"\7Sample not found" ;
		getch() ;
		return ;
	}
	box_for_display(t_rno) ;
	int row=7, flag ;
	fstream file ;
	file.open("WQI.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(record)))
	{
		if (rno == t_rno)
		{
			flag = 0 ;
			gotoxy(4,row) ;
			row++ ;
			if (row == 23)
			{
				flag = 1 ;
				row = 7 ;
				gotoxy(4,24) ;
				cout <<"Press any key to continue..." ;
				getch() ;
				clrscr() ;
				box_for_display(t_rno) ;
			}
		}
	}
	file.close() ;
	if (!flag)
	{
		gotoxy(4,24) ;
		cout <<"Press any key to continue..." ;
		getch() ;
	}
}

//**********************************************************
// THIS FUNCTION CLOSE THE RECORD (DELETE RECORD).
//**********************************************************

void record :: close_record(void)
{
	clrscr() ;
	char t_acc[10] ;
	int t, t_rno ;
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,5) ;
	cout <<"Enter the sample no. " ;
	gets(t_acc) ;
	t = atoi(t_acc) ;
	t_rno = t ;
	if (t_rno == 0)
		return ;
	clrscr() ;
	initial ini ;
	if (!ini.found_data(t_rno))
	{
		gotoxy(5,5) ;
		cout <<"\7Record not found" ;
		getch() ;
		return ;
	}
	gotoxy(71,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(3,3) ;
	for (int i=1; i<=76; i++) cout<<" ";
	gotoxy(30,3) ;
	cout<<"DELETE SCREEN";
	char ch ;
	ini.display(t_rno) ;
	do
	{
		clear(5,15) ;
		gotoxy(5,15) ;
		cout <<"Delete this record (y/n): " ;
		ch = getche() ;
		if (ch == '0')
			return ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	ini.delete_data(t_rno) ;
	delete_record(t_rno) ;
	gotoxy(5,20) ;
	cout <<"\7Record Deleted" ;
	gotoxy(5,23) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}

//************************************************************
// THIS FUNCTION COLLECTS RECORD OF A SINGLE STATE
//************************************************************
void initial::staterec(char st[23])
{       clrscr();
	cout<<"enter the  name of state";
	gets(st);
	initial i;
      //	record i;

	ifstream df;
	df.open("INITIAL.DAT", ios::in) ;
	df.seekg(0,ios::beg) ;
	char t_state[60] ;
	int f=0;
	while (df.read((char *) this, sizeof(initial)))
	{
		if (strcmpi(st,state)==0)
		{
		       //	i.display_list();
		       display_record();
			f=1;
		}
	}

	if(f==0)
	cout<<st<<  "data is not available";



	df.close() ;

 }

//************************************************************
// THIS IS MAIN FUNCTION CALLING HELP AND MAIN MENU FUNCTIONS
//************************************************************

void main(void)
{       textbackground(7);
	textcolor(6);
	control c ;
	c.main_menu() ;
}
