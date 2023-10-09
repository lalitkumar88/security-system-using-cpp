#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
    int a, i=0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"............Security system............."<<endl;
    cout<<"__________________________________________"<<endl;
    cout<<"|..............1.Register................|"<<endl;
    cout<<"|..............2.Login...................|"<<endl;
    cout<<"|..............3.Change password.........|"<<endl;
    cout<<"|______________4.End program_____________|"<<endl;
    cout<<endl;

    do{
        cout<<endl;
        cout<<"Enter your choice:- \n";
        cin>>a;
        switch (a)
        {
        case 1:
        {
            cout<<"_____________________________________"<<endl;
            cout<<"|.............Register..............|"<<endl;
            cout<<"|___________________________________|"<<endl;
            cout<<"Please enter username:- \n";
            cin>>name;
            cout<<"Please enter the password:- \n";
            cin>>password0;
            cout<<"Please enter your age:- \n";
            cin>>age;

            ofstream of1;       //ofsream class for writing purpose
            of1.open("file.txt");
            if(of1.is_open())
            {
                of1<<name<<"\n";
                of1<<password0<<"\n";
                cout<<"Registration is done"<<endl;
            }
            break;
        }
        case 2:
        {
            i=0;

            cout<<"_____________________________________"<<endl;
            cout<<"|..............Login................|"<<endl;
            cout<<"|___________________________________|"<<endl;

            ifstream of2;       //ifstram class for reading purpose
            of2.open("file.txt");
            cout<<"Please enter username:- \n";
            cin>>user;
            cout<<"Please enter the password:- \n";
            cin>>pass;

            if(of2.is_open())
            {
                while(! of2.eof())//eof will return non-zero when end of file is reached
                {
                    while(getline(of2,text))
                    {
                        istringstream iss(text);

                        iss>>word;
                        creds[i]=word;
                        i++;
                    }

                    if((user==creds[0]) and (pass==creds[1]))
                    {
                        cout<<"...Login successfull...\n";
                        cout<<endl;

                        cout<<"Details\n";
                        cout<<"Username:- "+name<<endl;
                        cout<<"Password:- "+pass<<endl;
                        cout<<"Age:- "+age<<endl;
                    }
                    else//if case login credentials are not correct
                    {
                        cout<<endl;
                        cout<<".............Incorrect Credentials................."<<endl;
                        cout<<"|............Press 2 to login.....................|"<<endl;
                        cout<<"|............Press 3 to Change Password...........|"<<endl;

                    }
                }
            }
            break;
        }
        case 3:
        {
            i=0;
            cout<<"............Change the Password............."<<endl;
            ifstream of0;
            of0.open("file.txt");
            cout<<"Enter the old password:- \n";
            cin>>old;

            if(of0.is_open())
            {
                while(!of0.eof())
                {
                    while(getline(of0,text))
                    {
                        istringstream iss(text);
                        iss>>word1;
                        cp[i] = word1;
                        i++;                       
                    }

                    if(old==cp[1])
                    {
                        of0.close();

                        ofstream of1;
                        of1.open("file.txt");
                        if(of1.is_open())
                        {
                            cout<<"Enter your new password:- \n";
                            cin>>password1;
                            cout<<"Enter your password again:- \n";
                            cin>>password2;

                            if(password1 == password2)
                            {
                                of1<<cp[0]<<endl;
                                of1<<password1;
                                cout<<"Password changed successfully\n";
                            }

                            else
                            {
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Password donot match\n";
                            }
                            
                        }
                        
                    }
                    else
                    {
                        cout<<"Please enter a valid password\n";
                    }

                }
            }
            break;
        }
        case 4:
        {
            cout<<"|.....................Thank you!.....................|"<<endl;
            cout<<"|.....................Visit again....................|"<<endl;
            break;
        }
        default:
            cout<<"Enter a valid choice\n";
            break;
        }
    }
    while(a!=4);

    return 0;


}