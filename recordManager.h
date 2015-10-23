#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "main.h"

class RecordManager{
    FileManager* fm= new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    
public:
    bool createFile(string filePath);
    int deleteFile();
    int openFile(string filePath);
    int closeFile(int fileID);
    
    int insertRecord();
    int deleteRecord();
    int updateRecord();
    int queryRecord();
    
    RecordManager();
}

#endif