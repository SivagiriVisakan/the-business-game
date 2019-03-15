#ifndef COMPANY_H
#define COMPANY_H
#include "Field.h"

class Company : public Field
{
public:
    Company(char *name, int cost);
    void setCost(int c);
    void calculateRent();
};

#endif // COMPANY_H
