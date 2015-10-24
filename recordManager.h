#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "main.h"
#include <cstring>

using namespace std;

class RecordManager{
    FileManager* fm= new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    
public:
    bool createFile(string filePath);
    int deleteFile(string filePath);
    int openFile(string filePath);
    int closeFile(int fileID);
    
    int createRecord(string dataBaseName, string recordName, int *ID_list, string* name_list, int len);
    int insertRecord(Record* x);
    int deleteRecord(string filePath);
    int updateRecord();
    int queryRecord();
    
    RecordManager();
}

#endif
