#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <cstring>
#include <locale>     //for tolower function
#include <cstddef>   //for NULL
#include <fstream>  //to read file
#include "BinarySearchTree.h"
using namespace std;

int S_line=0;
int titleflag=0;
string cmmnd="",title="";

bool check4num(char* x)
{
	int numbers_flag=0;
	for(int j=0 ; x[j]!='\0' ; j++)
	{
		if ( (int)x[j]>=48 && (int)x[j]<=57 )
		{
			continue;
		}
		else
		{
			numbers_flag=1;
			break;
		}
	}
	if(numbers_flag==1)
	{
		return false;
	}
	else if(numbers_flag==0)
	{
		return true;
	}
}


string getcommand(string & line)
{
	S_line=0;
	string returne="";
	while(line[S_line]!=' ' && S_line<=4)
	{
		returne=returne+line[S_line];
		S_line++;
	}
	if(line[S_line]==' ')
	{
		S_line++;
	}
	return returne;
}


string gettitle(string & line)
{
	S_line=getcommand(line).length()+1;
	string returne="";
	if(line[S_line]!='"')
	{
		titleflag=1;
		returne=returne+line[S_line];
		S_line++;
		while(line[S_line]!=' ')
		{
			returne=returne+line[S_line];
			S_line++;
		}
		return returne;
	}
	else if(line[S_line]=='"')
	{
		
		returne=returne+line[S_line];
		S_line++;
		while(line[S_line]!='"')
		{
		    //checker=checker+line[S_line]+line[S_line+1];
			returne=returne+line[S_line];
			S_line++;
		}
		returne=returne+line[S_line];
		S_line++;
		int x=line.length();
		if(S_line>=x)
		{
			titleflag=1;
			return returne;
		}
		else if(S_line<x)
		{
			S_line++;
			return returne;
		}
	}
}

int getday(string & line)
{
    if(cmmnd=="ADD" || cmmnd=="MOD")
    {
       S_line=0;
       S_line=getcommand(line).length()+gettitle(line).length()+2;
    }
    else
    {
        S_line=0;
        S_line=getcommand(line).length()+1;

    }
	char xx[100];
	int i=0;
	while( line[S_line]!=' ' && line[S_line]!='\0')
	{
		xx[i]=line[S_line];
		xx[i+1]='\0';
		i++;
		S_line++;
	}
	if(check4num(xx))
	{
		int returne = 0;
		returne=atoi(xx);
		if(returne>=1 && returne<365)
			return returne;
		else if(returne<1 && returne>=365)
			return -1;
	}
	else if(!check4num(xx));
	{
		return -1;
	}
}


int gethour(string & line)
{
	double fla=0;
	if(cmmnd=="ADD" || cmmnd=="MOD")
    {
        S_line=getcommand(line).length()+gettitle(line).length()+2;
    }
    else
    {
        S_line=0;
        S_line=getcommand(line).length()+1;
    }
    while(line[S_line]!=' ' && line[S_line]!='\0')
    {
        S_line++;
        fla=1;
    }
    if (fla == 1)
    {
        S_line=S_line+1;
    }
	int i=0;
	char xx[100];
	while( line[S_line]!=' ' && line[S_line]!='\0')
	{
		xx[i]=line[S_line];
		xx[i+1]='\0';
		i++;
		S_line++;
	}
	if(check4num(xx))
	{
		int returne = 0;
		returne=atoi(xx);
		if(returne>=0 && returne<24)
			return returne;
		else if(returne<0 && returne>=24)
			return -1;
	}
	else if(!check4num(xx));
	{
		return -1;
	}
}

ofstream opfile ;
int main(int argc,char**argv)
{
	if(argc!=3)
    {
	    cout<<"wrong number of files\n";
		//opfile<<"Invalid arguments\n"<<endl;
    }
    else
    {
		ifstream ipfile (argv[1]);
        opfile.open(argv[2]);
		if(!ipfile)
		{
            cout<<"input file not found\n"<<endl;
			opfile<<"input file not found\n"<<endl;
            return 0;
        }

		///////////////////////////////////////
		string line="";
		string tempp="";
		typedef BinarySearchTree BST;
		typedef BST * BSTPtr;
		BSTPtr b(new BST);
		while ( getline (ipfile,line) )
        {
            tempp="";
			int ha=line.length();
			if(line[ha-1]=='\r')
			{
				for(int zee=0 ; zee<(ha-1) ; zee++)
				{
					tempp=tempp+line[zee];
				}
				line=tempp;
			}
			cmmnd="";
            title="";
            int day,hour;
			S_line=0;
			cmmnd=getcommand(line);
			if( cmmnd == "ADD" )
			{
				double flag=0;
				title=gettitle(line);
				day=getday(line);
				hour=gethour(line);
				int check,spaces=0;
				S_line=5+title.length();
				while(line[S_line]!='\0')
                {
                   if(line[S_line]==' ')
                        spaces++;
                        S_line++;
                }
                if(spaces>1)
                {
                    cout<<"Invalid arguments\n";
                    opfile<<"Invalid arguments\n";
                }
				if(titleflag == 1)
				{
					cout<<"Invalid title"<<endl;
					opfile<<"Invalid title"<<endl;
					flag=1;
				}
				if(day == -1)
				{
					cout<<"Invalid day"<<endl;
					opfile<<"Invalid day"<<endl;
					flag=1;
				}
				if(hour == -1)
				{
					cout<<"Invalid hour"<<endl;
					opfile<<"Invalid hour"<<endl;
					flag=1;
				}
				if(flag == 0)
				{
					b->add(title,day,hour);
					extern int conflictflag;
					if(conflictflag==1)
                    {
                        cout<<"Conflict "<<day<<" "<<hour<<endl;
                        opfile<<"Conflict "<<day<<" "<<hour<<endl;
                        conflictflag=0;
                    }
				}
			}
			else if( cmmnd == "MOD" )
			{
				int flag=0;
				title=gettitle(line);
				day=getday(line);
				hour=gethour(line);
				int check,spaces=0;
				S_line=5+title.length();
				while(line[S_line]!='\0')
                {
                   if(line[S_line]==' ')
                        spaces++;
                        S_line++;
                }
                if(spaces>1)
                {
                    cout<<"Invalid arguments\n";
                    opfile<<"Invalid arguments\n";
                }
				if(titleflag == 1)
				{
					cout<<"Invalid title"<<endl;
					opfile<<"Invalid title"<<endl;
					flag=1;
				}
				if(day == -1)
				{
					cout<<"Invalid day"<<endl;
					opfile<<"Invalid day"<<endl;
					flag=1;
				}
				if(hour == -1)
				{
					cout<<"Invalid hour"<<endl;
					opfile<<"Invalid hour"<<endl;
					flag=1;
				}
				if(flag == 0)
				{
					b->modify(title,day,hour);
					extern int modifyflag;
					if(modifyflag==1)
                    {
                        cout<<"Empty "<<day<<' '<<hour<<endl;
                        opfile<<"Empty "<<day<<' '<<hour<<endl;
                    }
				}
			}
			else if( cmmnd == "Print" )
			{
				if(line.length()!= 5)
				{
					cout<<"Invalid arguments"<<endl;
					opfile<<"Invalid arguments"<<endl;
				}
				else if(line.length() == 5)
				{
				    extern int printflag;
					b->print(b);
					if(printflag==0)
                    {
                        cout<<"Empty Planner"<<endl;
                        opfile<<"Empty Planner"<<endl;
                    }
				}
			}
			else if( cmmnd == "Find" )
			{
				int flag=0;
				day=getday(line);
				hour=gethour(line);
				int check,spaces=0;
				S_line=5;
				while(line[S_line]!='\0')
                {
                   if(line[S_line]==' ')
                        spaces++;
                        S_line++;
                }
                if(spaces>1)
                {
                     cout<<"Invalid arguments\n";
                     opfile<<"Invalid arguments\n";
                }
				if(day == -1)
				{
					cout<<"Invalid day"<<endl;
					opfile<<"Invalid day"<<endl;
					flag=1;
				}
				if(hour == -1)
				{
					cout<<"Invalid hour"<<endl;
					opfile<<"Invalid hour"<<endl;
					flag=1;
				}
				string titlee="";
				if(flag == 0)
				{
					titlee=b->find(day,hour);
					if(titlee == "" )
                    {
                        cout<<"Empty "<<day<<' '<<hour<<endl;
                        opfile<<"Empty "<<day<<' '<<hour<<endl;
                    }
                    else if(titlee != "")
                    {
                        cout<<titlee<<endl;
                        opfile<<titlee<<endl;
                    }
				}
			}
			else if( cmmnd == "DEL")
			{
				int flag=0;
				day=getday(line);
				hour=gethour(line);
				int check,spaces=0;
				S_line=4;
				while(line[S_line]!='\0')
                {
                   if(line[S_line]==' ')
                        spaces++;
                        S_line++;
                }
                if(spaces>1)
                {
                    cout<<"Invalid arguments\n";
                    opfile<<"Invalid arguments\n";
                }
				if(day == -1)
				{
					cout<<"Invalid day"<<endl;
					opfile<<"Invalid day"<<endl;
					flag=1;
				}
				if(hour == -1)
				{
					cout<<"Invalid hour"<<endl;
					opfile<<"Invalid hour"<<endl;
					flag=1;
				}
				if(flag == 0)
				{
				    string titlee="";
				    titlee=b->find(day,hour);
					if(titlee == "" )
                    {
                        cout<<"Empty "<<day<<' '<<hour<<endl;
                        opfile<<"Empty "<<day<<' '<<hour<<endl;
                    }
                    else
                        b=b->delet(b,day,hour);
				}
			}
			else
			{
				cout<<"Invalid command"<<endl;
				opfile<<"Invalid command"<<endl;
			}

			cmmnd="";
			title="";
			line="";
        }
	}
}
