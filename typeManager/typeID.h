#ifndef TYPEID_H
#define TYPEID_H

class TypeID{
public:
    static const int INT = 1;
    static const int CHAR = INT + 1;
    
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

#endif