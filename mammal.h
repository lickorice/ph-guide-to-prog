
#include <sstream>
#include <string>

using namespace std;

class Mammal{
    public:
    short mLegs;
    string mFur;
    bool mTail;


    Mammal(short legs, string fur, bool tail){
        mLegs = legs;
        mFur  = fur;
        mTail = tail; 

    }
    string getMammal(){
        ostringstream ss;
        ss<<endl<<"legs: " <<mLegs;
        ss<<endl<<"Kind of fur: " <<mFur;
        ss<<endl<<"Presence of tail: " <<mTail;
        return ss.str();
    }

//end of brack ,and i put semicolon pero di ko alam kung gagano sa mingw
};
