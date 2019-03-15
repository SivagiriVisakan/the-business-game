

enum FieldLevel {NotUpgradable = -1, LevelOne = 1, LevelTwo = 2, LevelThree = 3}; 
  
class Field
{
    private:
    protected:
        char *name;
        enum FieldLevel level;
        int cost; // The initial cost of the Field (for buying)
        int rent; // The rent that has to be paid if opponent lands here(changes depending on level)

    public:
        Field(char *name);
        enum FieldLevel getCurrentLevel(){return level;}
        int getRent() { return rent; }
        virtual void setCost(int c)=0;
        virtual void calculateRent()=0;

};
