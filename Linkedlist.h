#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include <bits/stdc++.h>
using namespace std;
class USER;

class TreapNode
{
public :

    int priority;
    string key;

    TreapNode* right, * left;

    TreapNode()
    {

        key = "";
        priority = 0;
        right = left = NULL;
    }

    //this method work to give every username random priority

    TreapNode(string username)
    {
        key = username;
        priority = rand() % (100-1)+1;
        left = right = NULL;
    }

};



    //this medthod to do right rotation

void rightRotation(TreapNode* &root)
{

    TreapNode* L = root->left;
    TreapNode* R = root->left->right;
    L->right = root;
    root->left= R;
    root = L;

}

//this method to do right rotation

void leftRotation(TreapNode* &root)
{
    TreapNode* R = root->right;
    TreapNode* L = root->right->left;
    R->left = root;
    root->right= L;
    root = R;
}


void add(TreapNode* &root,string username)
{
    //if root is null then this is the first node in the treap
    if (root == nullptr)
    {
        root= new TreapNode(username);
        return ;
    }

    //If root isn't null and the key is less than the root go left
    else if (username < root->key)
    {
        add(root->left,username);
        if (root->left != nullptr && root->left->priority > root->priority)
            rightRotation(root);

    }

    else
    {
        add( root->right,username);
        //check if the heap property is violated
        if (root->right!= nullptr && root->right->priority > root->priority)
            leftRotation(root);

    }

}

void deleteNode(TreapNode* &root, string username)
{

    if (root == nullptr)
        return;
    if (username < root->key)
        deleteNode(root->left, username);
    else if (username> root->key)
        deleteNode(root->right, username);

    else
    {
        if (root->left ==nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->left && root->right)
        {
            if (root->left->priority < root->right->priority)
            {
                leftRotation(root);
                deleteNode(root->left, username);
            }
            else
            {
                rightRotation(root);
                deleteNode(root->right, username);
            }
        }

        else
        {
            TreapNode* child = (root->left)? root->left: root->right;
            TreapNode* current = root;
            root = child;
            delete current;
        }
    }
}
//method to check of elment
bool find(TreapNode* root,string username)
{
    if (root == nullptr)
        return false;
    if (root->key == username)
        return true;
    if (username < root->key)
        return find(root->left, username);
    return find(root->right, username);
}

void printInOrder(TreapNode* root)
{

    if (root)
    {

        printInOrder(root->left);
        cout << root->key << endl;
        printInOrder(root->right);


    }
}


class USER
{
private:
    string username;
    string name;
    string email;
    TreapNode* friendBST = nullptr;


public:
    string getName()
    {
        return name;
    }
    string getUsername()
    {
        return username;
    }
    string getEmail()
    {
        return email;
    }
    USER() {}
    USER(string Username,string Name,string Email)
    {
        username=Username;
        name=Name;
        email=Email;

    }
    string handel(const string s)
    {
        auto start = s.begin();
        while (start != s.end() && isspace(*start))
        {
            start++;
        }

        auto end = s.end();
        do
        {
            end--;
        }
        while (distance(start, end) > 0 && isspace(*end));

        return string(start, end + 1);


    }
    TreapNode* getfriendBST(){return friendBST;}
    void setFriends(string file)
    {

        string username1,username2;
        ifstream out(file);

        while(!out.eof())
        {
            getline(out,username1,',');

            username1=handel(username1);

            getline(out,username2,'\n');
            username2= handel(username2);
            if(this->getUsername()==username1)
            {
                add(this->friendBST,username2);
            }
            else if(this->getUsername()==username2)
            {
                add(friendBST,username1);
            }

        }

        out.close();
    }
    bool addFriend(USER* _user)
    {
        if(find(this->friendBST,_user->getUsername())){
            return true;
        }
        else{
            add(this->friendBST,_user->getUsername());
            _user->addFriend(this);
            return false;
        }
    }
    bool deleteFriend(USER* _user)
    {
        if(find(this->friendBST,_user->getUsername()))
        {
            deleteNode(this->friendBST,_user->getUsername());
            _user->deleteFriend(this);
            return true;
        }
        else
        {
            return false;
        }
    }
    void listOfFriends()
    {
        printInOrder(friendBST);
    }
    void Print()
    {
        cout<<username<<" ";
        cout<<name<<" ";
        cout<<email<<" ";
        cout<<endl<<endl;
    }
};


class Linkedlist
{
    class Node
    {
    public:
        USER user;
        Node*next;
    };
    Node*first;
    Node*last;
    int length;
public:
    Linkedlist()
    {
        first=last=NULL;
        length=0;
    }
    Linkedlist(string file)
    {

        string Username,Name,Email;
        ifstream out(file);

        while(!out.eof())
        {
            getline(out,Username,',');
            Username=handel(Username);
            getline(out,Name,',');
            Name=handel(Name);
            getline(out,Email,'\n');
            Email= handel(Email);
            insertIntolast(Username,Name,Email);
        }
        out.close();

    }
    string handel(const string s)
    {
        auto start = s.begin();
        while (start != s.end() && isspace(*start))
        {
            start++;
        }

        auto end = s.end();
        do
        {
            end--;
        }
        while (distance(start, end) > 0 && isspace(*end));

        return string(start, end + 1);


    }

    int getlength()
    {
        Node* current = first;
        int counter = 0;
        while (current != NULL)
        {
            counter++;
            current = current->next;
        }
        return counter;
    }

    string* convertToArray()
    {


        int len = this->getlength();


        string* arr =new string[len];

        int index = 0;
        Node* current = first;


        while (current != NULL)
        {
            arr[index++] = current->user.getUsername();
            current = current->next;
        }


        return arr;
    }

    void insertIntolast(string Username,string Name,string Email)
    {
        USER _user(Username,Name,Email);

        Node*newnode=new Node;
        newnode->user =_user;
        newnode->user.setFriends("all-users-relations.in");

        if(length==0)
        {
            first=last=newnode;
            newnode->next=NULL;
        }
        else
        {
            last->next=newnode;
            newnode->next=NULL;
            last=newnode;
        }
        length++;
    }

    USER* Search(string userName)
    {
        Node* cur=first;
        while (cur!=nullptr)
        {
            if (cur->user.getUsername()==userName)
            {
                return &cur->user;
            }
            cur=cur->next;


        }
        return nullptr;
    }

    void print()
    {
        Node*cur=first;
        while (cur!=NULL)
        {
            cur->user.Print();

            cur=cur->next;
        }
        cout<<endl;
    }


    ~Linkedlist()
    {
        Node * ptr =first;
        while(ptr!=NULL)
        {
            first=first->next;
            delete ptr;
            ptr=first;
        }
    }

};


#endif // LINKEDLIST_H_INCLUDED
