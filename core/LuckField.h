#ifndef LUCK_FIELD_H
#define LUCK_FIELD_H

#include "NonBuyableField.h"
#include<string>
class LuckField: public NonBuyableField
{
    private:
        std::string helpText;
    protected:
    public:
        LuckField(char *name, int rent);
        /**
         * This is for displaying directly by the clients
         */
        const char* getHelpText();
        void calculateRent();
};

#endif // LUCK_FIELD_H
