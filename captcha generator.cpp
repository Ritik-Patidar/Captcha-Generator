#include<iostream>
#include<time.h>
using namespace std ;

string captcha_generator(int n)
{
    char character[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
                          'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                          'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                          'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string captcha = "";
    for(int i = 0; i < n; i++ )
    {
        captcha = captcha + character[rand()%62];
    }
    return captcha;
}

int main()
{
    srand(time(0));
    int n = 5, flag = 0;
    string str;
    cout << "\n--------------------CAPTCHA GENERATOR--------------------" << endl;
    do{
        string generated_captcha = captcha_generator(n);
        cout << "CAPTCHA : " << generated_captcha << endl;

        cout << "Enter CAPTCHA to verify : ";
        cin >> str;
        if(generated_captcha == str)
        {
            cout << "\nCAPTCHA Verified sucessfully...";
            cout << "\n-------------------------------\n";
            flag = 0 ;
        }
        else
        {
            cout << "\nInvalid CAPTCHA ....!\nTry again\n" << endl;
            flag = 1 ;
        }
    }while(flag != 0);
}
