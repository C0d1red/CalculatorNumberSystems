#include "transfer.h"
#include "QtMath"

Transfer::Transfer()
{
}

void Transfer::RemoveChar(char* p, char c){
    if (NULL == p)
        return;
    char *pDest = p;
    while (*p){
        if(*p != c)
            *pDest++ = *p;
        p++;
    }
    *pDest = '\0';
}

char Transfer::Digit(int o){
    switch (o) {
         case 10:
             return 'A';
         case 11:
             return 'B';
         case 12:
             return 'C';
         case 13:
             return 'D';
         case 14:
             return 'E';
         case 15:
             return 'F';
        }
}

//transfer to 10SS
long long Transfer::ToTenSys(const char* number, int num_of_char, int sourceSys){
    long long numer_result_ten_sys = 0;
    if (sourceSys != 10) {
            for (int i = 0; i < num_of_char; i++) {
                switch (number[i])
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    numer_result_ten_sys += (number[i]-'0')*(pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'A':
                    numer_result_ten_sys += 10 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'B':
                    numer_result_ten_sys += 11 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'C':
                    numer_result_ten_sys += 12 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'D':
                    numer_result_ten_sys += 13 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'E':
                    numer_result_ten_sys += 14 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                case 'F':
                    numer_result_ten_sys += 15 * (pow(sourceSys, num_of_char - i - 1));
                    break;
                }
            }
    } else
        for(int i = 0; i<num_of_char; i++){
            numer_result_ten_sys += (number[i]-'0')*(pow(10, num_of_char-i-1));
        }
    return numer_result_ten_sys;
};

char* Transfer::changeNumSys(const char* number, int sourceSys, int finalSys, int num_of_char) {
    char *finalNumber = new char[45];
    long long numer_result_ten_sys = ToTenSys(number, num_of_char, sourceSys);;

    //zero for array (it's for check void space at the end)
    for (int i = 0; i < 45; i++){
        finalNumber[i] = 'M';
    }



    long over = 10; //remainder of division

    int array_counter = 0;

    //write to the array ramainder (i.e. transfer to final ss)
    while ((numer_result_ten_sys / finalSys) >= 1) {
        over = numer_result_ten_sys % finalSys;
        if(over<10){
            finalNumber[array_counter] = (char)(((int)'0') + over);
        }
        else
            finalNumber[array_counter] = Digit(over);
        array_counter++;
        numer_result_ten_sys /= finalSys;
    }
    over = numer_result_ten_sys % finalSys; //for last reminder
    finalNumber[array_counter] = (char)(((int)'0') + over); //for last reminder



    // reverse array
    for (int i = 0, j = array_counter+1; i < j; ++i, --j) {
        char t = finalNumber[i];
        finalNumber[i] = finalNumber[j];
        finalNumber[j] = t;
    }

    for (int i = array_counter+2; i<45; i++){
        finalNumber[i] = 'M';
    }
    finalNumber[array_counter+2] = '\0';



   RemoveChar(finalNumber, 'M');

   return finalNumber;
}



Transfer::~Transfer()
{
}

