
class BaseField
{
    private:
        char name[20];
    public:
        BaseField(char *name);
        // The method that will be called whenever a player lands on this particular field.
        // Has to be overriden from the sub-class.
        void onTokenLanded(/*Player player*/);
}
