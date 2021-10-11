#include <bits/stdc++.h>
#define bitSize 6
using namespace std;

string complement(string binStr)
{
    int len = binStr.length();
    string compBinStr = "";
    //Taking 1's complement
    for (int i = 0; i < len; i++)
    {
        if (binStr[i] == '0')
        {
            compBinStr += '1';
        }
        else
        {
            compBinStr += '0';
        }
    }
    //Adding 1 to 1's complement to convert to 2's complement01
    bool flag = true;
    int j = 1;
    while (flag)
    {
        if (compBinStr[len - j] == '0')
        {
            compBinStr[len - j] = '1';
            flag = false;
        }
        else
        {
            compBinStr[len - j] = '0';
            j++;
        }

        if (j == len + 1)
        {
            break;
        }
    }
    return compBinStr;
}

string binary_conversion(int num)
{
    string binary_num = "";
    for (int i = 0; num > 0; i++)
    {
        binary_num += to_string(num % 2);
        num = num / 2;
    }
    reverse(binary_num.begin(), binary_num.end());
    int len = binary_num.length();
    string sign_int;
    for (int i = 0; i < bitSize - len; i++)
    {
        sign_int += '0';
    }
    sign_int += binary_num;
    return sign_int;
}

void addition(string *str1, string *str2)
{
    int carry = 0;
    for (int i = bitSize-1; i >= 0; i--)
    {
        
        if (((*str1)[i] == '0' && (*str2)[i] == '0' && carry == 0))
        {
            (*str1)[i] = '0';
            carry = 0;
        }
        else if (((*str1)[i] == '1' && (*str2)[i] == '0' && carry == 0))
        {
            (*str1)[i] = '1';
            carry = 0;
        }
        else if (((*str1)[i] == '1' && (*str2)[i] == '0' && carry == 1))
        {
            (*str1)[i] = '0';
            carry = 1;
        }
        else if (((*str1)[i] == '0' && (*str2)[i] == '0' && carry == 1))
        {
            (*str1)[i] = '1';
            carry = 0;
        }
        else if (((*str1)[i] == '0' && (*str2)[i] == '1' && carry == 0))
        {
            (*str1)[i] = '1';
            carry = 0;
        }
        else if (((*str1)[i] == '0' && (*str2)[i] == '1' && carry == 1))
        {
            (*str1)[i] = '0';
            carry = 1;
        }
        else if (((*str1)[i] == '1' && (*str2)[i] == '1' && carry == 0))
        {
            (*str1)[i] = '0';
            carry = 1;
        }
        else
        {
            (*str1)[i] = '1';
            carry = 1;
        }
    }
}


string boothMultiplication(string num1, string num2)
{
    string br = num1;
    string qr = num2;
    string br_1 = complement(br);

    cout << "Value of BR : " << br << endl;
    cout << "Value of BR(BAR) + 1 : " << br_1 << endl;
    cout << "Value of QR : " << qr << endl;

    int sc = qr.length(), qn_1 = 0; // SC is equal to the number of bits in QR
    string ac = "";

    for (int i = 0; i < bitSize; i++)
    {
        ac += '0';
    }
    cout << "Comment\t\tAC\tQR\tQN+1\tSC\n";
    cout << "Start"  << "\t"<< "\t" << ac << "\t" << qr << "\t" << qn_1 << "\t"
                 << sc << endl;
    for (sc;sc>0;sc--)
    {

        if ((qn_1 == 0 && qr[bitSize - 1] == '0') || (qn_1 == 1 && qr[bitSize - 1] == '1'))
        {
            qn_1 = (int)qr[bitSize - 1] - int('0') ;
            for (int i = bitSize - 1; i > 0; i--)
            {
                qr[i] = qr[i - 1]  ;
            }
            qr[0] = ac[bitSize - 1] ;
            for (int i = bitSize - 1; i > 0; i--)
            {
                ac[i] = ac[i - 1]; //ASHR
            }

            cout << "ASHR" << "\t"<< "\t" << ac << "\t" << qr << "\t" << qn_1 << "\t"
                 << sc << endl;
        }
        else if (qn_1 == 0 && qr[bitSize - 1] == '1')
        {           
            addition(&ac, &br_1); // AC + BR(BAR) + 1
            cout << "AC + BR(BAR)+1"<< "\t" << ac << "\t" << qr << "\t" << qn_1 << "\t"<< sc << endl;
            qn_1 = (int)qr[bitSize - 1]- int('0')  ;
            for (int i = bitSize - 1; i > 0; i--)
            {
                qr[i] = qr[i - 1];
            }
            qr[0] = ac[bitSize - 1];
            for (int i = bitSize - 1; i > 0; i--)
            {
                ac[i] = ac[i - 1]; //ASHR
            }

            cout << "ASHR"<< "\t" << "\t"<< ac << "\t" << qr << "\t" << qn_1 << "\t"<< sc << endl;
        }
        else
        {          
            addition(&ac, &br); // AC + BR
            

            cout << "AC + BR" << "\t"<< "\t" << ac << "\t" << qr << "\t" << qn_1 << "\t"
                 << sc << endl;
            qn_1 = (int)qr[bitSize - 1] - int('0') ;
            for (int i = bitSize - 1; i > 0; i--)
            {
                qr[i] = qr[i - 1];
            }
            qr[0] = ac[bitSize - 1];
            for (int i = bitSize - 1; i > 0; i--)
            {
                ac[i] = ac[i - 1]; // ASHR
            }

            cout << "ASHR" << "\t" << "\t"<< ac << "\t" << qr << "\t" << qn_1 << "\t" << sc << endl;
        }
    }sc--;

    return (ac+qr);
}

int main()
{
    int status;
    cout<< "Enter 1 for decimal and 0 for binary \n";
    cin>> status;
    string num1, num2;
    if(status==1){
        int n1,n2;
        cout << "Enter Multiplicand and Multiplier \n";
        cin >> n1 >> n2;
        num1 = binary_conversion(n1);
        num2 = binary_conversion(n2);
        cout<<num1;
    }
    else{
    
    cout << "Enter Multiplicand and Multiplier in "<< bitSize <<" bit format:  \n";
    cin >> num1 >> num2;
    }
    string binaryMultiplication = boothMultiplication(num1, num2);
    cout<<"Product: "<<binaryMultiplication<<endl;
    int sign = 1;
    string str = "";
    for (int i=1; i<binaryMultiplication.length();i++){
        str+=binaryMultiplication[i];
    }
    if (binaryMultiplication[0] == '1'){
        sign=-1;
        binaryMultiplication = complement(str);
    }
    int ans=0;
    for (int i=1;i<binaryMultiplication.length();i++){
        ans+= ((int)binaryMultiplication[i] - (int)'0')*pow(2,binaryMultiplication.length()-1-i); // converting to decimal
    }
    
    
    cout<<"The product of the two binary number is "<<sign*ans<<endl;
    return 0;
}





