#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "Linkedlist.h"
using namespace std;


Linkedlist usersList("all-users.in");
string* usersUsername = usersList.convertToArray();



int main()
{

    string choice;
    string friendName;
    USER* myfriend;
    bool mainMenuState=true;
    bool loginMenustate;
    int loginMenuChoice;
    USER* user;
    string username;

    while(mainMenuState)
    {
        cout<<"******Main menu******"<<endl;
        cout<<"Login"<<endl;
        cout<<"Exit"<<endl;
        cin>>choice;
        if(choice=="Exit"||choice=="exit")
        {
            mainMenuState=false;
            break;
        }
        else if(choice=="Login"||choice=="login")
        {
            cout<<"Enter username: ";
            cin>>username;
            user=usersList.Search(username);
            if(user!=nullptr)
            {
                loginMenustate=true;
                while(loginMenustate)
                {
                    cout<<"******User menu******"<<endl;
                    cout<<"1- List all friends"<<endl;
                    cout<<"2- Search by username"<<endl;
                    cout<<"3- Add friend"<<endl;
                    cout<<"4- Remove friend"<<endl;
                    cout<<"5- People you may know"<<endl;
                    cout<<"6- Logout"<<endl;
                    cin>>loginMenuChoice;
                    switch(loginMenuChoice)
                    {
                    case 1:
                        USER* allfriends;
                        cout<<"Friends list:\n\n";
                        for(int i=0; i<usersList.getlength(); i++)
                        {
                            if(find(user->getfriendBST(),usersUsername[i])&&usersUsername[i]!=user->getUsername())
                            {
                                allfriends=usersList.Search(usersUsername[i]);
                                cout<<allfriends->getUsername()<<", "<<allfriends->getName()<<endl<<endl;


                            }

                        }

                        break;

                    case 2:
                        cout<<"Enter username: ";
                        cin>>friendName;
                        if(find(user->getfriendBST(),friendName))
                        {
                            cout<<"Friend info: ";
                            myfriend=usersList.Search(friendName);
                            myfriend->Print();
                            cout<<endl;

                        }
                        else
                        {
                            cout<<"not found"<<endl<<endl;
                        }
                        break;
                    case 3:
                        cout<<"Enter username: ";
                        cin>>friendName;
                        if(find(user->getfriendBST(),friendName))
                        {
                            cout<<"You are already friends\n"<<endl;
                        }
                        else
                        {
                            myfriend=usersList.Search(friendName);
                            if(myfriend==nullptr)
                            {
                                cout<<"user not found\n"<<endl;
                            }
                            else
                            {
                                user->addFriend(myfriend);
                                cout<<"You are now friends\n"<<endl;

                            }

                        }
                        break;

                    case 4:
                        cout<<"Enter username: ";
                        cin>>friendName;
                        myfriend=usersList.Search(friendName);
                        if(find(user->getfriendBST(),friendName))
                        {
                            user->deleteFriend(myfriend);
                            cout<<"done\n"<<endl;

                        }
                        break;

                    case 5:
                    {
                        string* usersUsername = usersList.convertToArray();
                        cout<<"people you may know:\n\n";
                        USER* mayKnow;
                        for(int i=0; i<usersList.getlength(); i++)
                        {
                            if(!find(user->getfriendBST(),usersUsername[i])&&usersUsername[i]!=user->getUsername())
                            {
                                mayKnow=usersList.Search(usersUsername[i]);
                                cout<<mayKnow->getUsername()<<", "<<mayKnow->getName()<<endl<<endl;


                            }

                        }
                        delete[] usersUsername;
                        break;

                    }


                    case 6:
                        loginMenustate=false;
                        break;
                    default:
                        break;

                    }


                }

            }
            else
            {
                cout<<"user not found"<<endl;
            }

        }

    }
    return 0;
}




