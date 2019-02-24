#ifndef COMPANY_H
#define COMPANY_H
#include "BaseField.h"

class Company : public BaseField
{
public:
    Company();
    void onTokenLanded(Player &player);
};

#endif // COMPANY_H
