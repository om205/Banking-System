#ifndef __SECURE
#define __SECURE

class Encdec
{
    int key;
    public:
    Encdec(int);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
};

#endif