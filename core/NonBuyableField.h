#ifndef NON_BUYABLE_FIELD_H
#define NON_BUYABLE_FIELD_H

#include "Field.h"
#include<string>
class NonBuyableField: public Field
{
    private:
        std::string helpText;
    protected:
    public:
        NonBuyableField(char *name, int rent);
        NonBuyableField(const NonBuyableField& nbf);
        ~NonBuyableField();
        /**
         * This is for displaying directly by the clients
         */
        virtual void calculateRent();
        virtual const char* getHelpText();
};

#endif // NON_BUYABLE_FIELD_H
