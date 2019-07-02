#ifndef TRANSFER_H
#define TRANSFER_H

class Transfer
{
public:
    Transfer();
    ~Transfer();
    char* changeNumSys(const char* number, int sourceSys, int finalSys, int num_of_char);
private:
    void RemoveChar(char* p, char c);
    char Digit(int o);
    long long ToTenSys(const char* number, int num_of_char, int sourceSys);
};



#endif // TRANSFER_H
