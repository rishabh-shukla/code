#include<iostream>
#include<string>
using namespace std;
#include "education.h"
#include "staff.h"
#include "teacher.h"
#include "officer.h"
#include "typist.h"
#include "regular_typist.h"
#include "casual_typist.h"
int main(){
    int k,a1,a2,a3,a4,c1=0,c2=0,c3=0,c4=0;
    string n;
    cout<<"             INSTITUTE STAFF DATABASE\n";
    cout<<"             ........................\n";

    //taking the input for the number of staffs

    cout<<"ENTER THE NUMBER OF TEACHERS-";
    cin>>a1;
    cout<<"\nENTER THE NUMBER OF OFFICERS-";
    cin>>a2;
    cout<<"\nENTER THE NUMBER OF REGULAR TYPISTS-";
    cin>>a3;
    cout<<"\nENTER THE NUMBER OF CASUAL TYPISTS-";
    cin>>a4;

    //allocating memory dynamically for staffs

    teacher *T=new teacher[a1];
    officer *O=new officer[a2];
    regular_typist *R_T=new regular_typist[a3];
    casual_typist *C_T=new casual_typist[a4];
    while(1)                                                //Menu for Institute Staff Database
    {
        cout<<"\n1 FOR TEACHER\n"<<"2 FOR OFFICER\n"<<"3 FOR TYPIST\n"<<"4 FOR EXIT\n";
        cin>>n;
        if(n=="1")                                             //SubMenu for Teacher staff of institute
        {
            while(1){
                cout<<"1.DISPLAY\n"<<"2.INSERT\n"<<"3.MAIN_MENU\n";
                cin>>k;
                if(k==1)
                {
                    if(c1==0)
                        cout<<"THERE ARE NO TEACHER IN STAFF\n"<<endl;
                    for(int i=0;i<c1;i++)
                    {
                        T[i].display();
                        cout<<endl;
                    }
                }
                else if(k==2)
                {
                    if(c1==a1)
                            cout<<"MORE TEACHERS CANNOT BE ADDED\n\n";

                    else{
                        string ss1,ss2,ss3,ss4,ss5,ss6;
                        cout<<"ENTER THE NAME OF TEACHER-:";
                        cin>>ss1;
                        cout<<"\nENTER THE CODE OF TEACHER-:";
                        cin>>ss2;
                        cout<<"\nENTER THE SUBJECT OF TEACHER-:";
                        cin>>ss3;
                        cout<<"\nENTER THE PUBLICATION OF TEACHER-:";
                        cin>>ss4;
                        cout<<"\nENTER THE GENERAL QUALIFICATION OF TEACHER-:";
                        cin>>ss5;
                        cout<<"\nENTER THE PROFFETIONAL QUALIFICATION OF TEACHER-:";
                        cin>>ss6;
                        T[c1].teacher1(ss1,ss2,ss3,ss4,ss5,ss6);
                        c1++;
                    }
                }
                else if(k==3)
                    break;
                else
                    cout<<"INVALID INPUT\n";
            }
        }
        else if(n=="2")                                  //SubMenu for officer staff of institute
        {
            while(1){
                cout<<"1.DISPLAY\n"<<"2.INSERT\n"<<"3.MAIN_MENU\n";
                cin>>k;
                if(k==1)
                {
                    if(c2==0)
                        cout<<"THERE ARE NO OFFICER IN STAFF\n"<<endl;
                    for(int i=0;i<c2;i++)
                    {
                        O[i].display();
                        cout<<endl;
                    }
                }
                else if(k==2)
                {
                    if(c1==a1)
                            cout<<"MORE OFFICER CANNOT BE ADDED\n\n";
                    else{
                        string ss1,ss2,ss3,ss4,ss5;
                        cout<<"ENTER THE NAME OF OFFICER-:";
                        cin>>ss1;
                        cout<<"\nENTER THE CODE OF OFFICER-:";
                        cin>>ss2;
                        cout<<"\nENTER THE RANK OF OFFICER-:";
                        cin>>ss3;
                        cout<<"\nENTER THE GENERAL QUALIFICATION OF OFFICER-:";
                        cin>>ss4;
                        cout<<"\nENTER THE PROFFETIONAL QUALIFICATION OF OFFICER-:";
                        cin>>ss5;
                        O[c2].officer1(ss1,ss2,ss3,ss4,ss5);
                        c2++;
                    }
                }
                else if(k==3)
                    break;
                else
                    cout<<"INVALID INPUT\n";
            }
        }
        else if(n=="3")                                    //SubMenu for Typist staff of institute
        {
            while(1)
            {
                int kk;
                cout<<"ENTER 1 FOR REGULAR TYPIST\n"<<"ENTER 2 FOR CASUAL TYPIST\n"<<"ENTER 3 FOR MAIN MENU\n";
                cin>>kk;
                if(kk==1){   //SubMenu for regular_typist staff of institute
                    while(1){
                        cout<<"1.DISPLAY\n"<<"2.INSERT\n"<<"3.MAIN_MENU\n";
                        cin>>k;
                        if(k==1)
                        {
                            if(c3==0)
                                cout<<"THERE ARE NO REGULAR TYPIST IN STAFF\n"<<endl;
                            for(int i=0;i<c3;i++)
                            {
                                R_T[i].display();
                                cout<<endl;
                            }
                        }
                        else if(k==2)
                        {
                            if(c1==a1)
                                cout<<"MORE REGULAR TYPIST CANNOT BE ADDER\n\n";
                            else{
                                string ss1,ss2;
                                int ss3;
                                cout<<"ENTER THE NAME OF TYPIST-:";
                                cin>>ss1;
                                cout<<"\nENTER THE CODE OF TYPIST-:";
                                cin>>ss2;
                                cout<<"\nENTER THE SPEED OF TYPIST-:";
                                cin>>ss3;
                                R_T[c3].regular_typist1(ss1,ss2,ss3);
                                c3++;
                            }
                        }
                        else if(k==3)
                            break;
                        else

                            cout<<"INVALID INPUT\n";
                    }
                }
                else if(kk==2){      //SubMenu for casual_typist staff of institute
                    while(1){
                        cout<<"1.DISPLAY\n"<<"2.INSERT\n"<<"3.MAIN_MENU\n";
                        cin>>k;
                        if(k==1)
                        {
                            for(int i=0;i<c4;i++)
                            {
                                if(c2==0)
                                    cout<<"THERE ARE NO CASUAL TYPIST IN STAFF\n"<<endl;
                                C_T[i].display();
                                cout<<endl;
                            }
                        }
                        else if(k==2)
                        {
                            if(c1==a1)
                                cout<<"MORE CASUAL TYPIST CANNOT BE ADDER\n\n";
                            else{
                                string ss1,ss2;
                                int ss3;
                                cout<<"ENTER THE NAME OF TYPIST-:";
                                cin>>ss1;
                                cout<<"\nENTER THE CODE OF TYPIST-:";
                                cin>>ss2;
                                cout<<"\nENTER THE SPEED OF TYPIST-:";
                                cin>>ss3;
                                C_T[c4].casual_typist1(ss1,ss2,ss3);
                                c4++;
                            }
                        }
                        else if(k==3)
                            break;
                        else
                            cout<<"INVALID INPUT\n";
                    }
                }
                else if(kk==3)
                    break;
                else
                    cout<<"INVALID INPUT\n";
            }
        }
        else if(n=="4")
            break;
        else
            cout<<"INVALID INPUT\n";
    }
    return 0;
}
