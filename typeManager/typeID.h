#ifndef TYPEID_H
#define TYPEID_H

#include <cstring>
using namespace std;

class TypeID{
public:
    static const int INT;
    static const int CHAR;
    
    static int getLength(int iD){
        
        switch iD{
            
            case INT:{
                return sizeof(int);
            }
            case CHAR:{
                return sizeof(char);
            }
        }
    }
    

};

static const int TypeID::INT = 1;
static const int TypeID::CHAR = 2;

#endif