
#include "recordManager.h"

#include <iostream>
#include <fstream>

#include <cstdio>

using namespace std;

bool RecordManager::createFile(string filePath)
{
    if(fm->createFile(filePath.c_str()))
    {
        printf("建立成功\n");
        return true;
    }else
    {
        printf("建立失败\n");
        return false;
    }
}

int RecordManager::deleteFile(string filePath)
{
    printf("删除一个已有文件\n");
    return remove(filePath.c_str());
    
}

int RecordManager::openFile(string filePath)
{
    int fileID;
    if(fm->openFile(filePath.c_str(),fileID))
    {
        printf("打开成功，ID: %d\n",fileID);
        return fileID;
    }else
    {
        printf("打开失败\n");
        return 0;
    }
    
}

int RecordManager::closeFile(int fileID)
{
    printf("关闭id为%d的文件\n",fileID);
    return fm->closeFile(fileID);
    
}

int RecordManager::insertRecord(Record* x)
{
    string dataBaseName = x->dataBaseName;
    string recordName = x->recordName;
    
    string fileName = "./data/"+dataBaseName+"/"+recordName+".data"
    
    int fileID = openFile(fileName);
    
    int cntLen = cnt + sizeof(int);
    int recordInEachPage = 8192 / cntLen;
    
    if(x->recordID > 0){
        int pageID = (x->recordID-1)/recordInEachPage + 1;
        BufType b = bpm->allocPage(fileID, pageID, index, false);
        
        int md = x->recordID%recordInEachPage;
        
        memcpy(b[md*cntLen], &(x->recordID), sizeof(int));
        memcpy(b[md*cntLen+sizeof(int)] ,x->data, cnt);
        bpm->markDirty(index); //标记脏页
        return x->recordID;
        
    }else
    {
        for(int pageID = 1; pageID < 1000; ++ pageID)
        {
            bool flag = false;
            int index;
            BufType b = bpm->allocPage(fileID, pageID, index, false);
            for(int j=0;j<recordInEachPage;++j)
            {
                ++x->recordID;
                int y;
                memcpy(&y, b[j*cntLen], sizeof(int));
                if (y==0)
                {
                    memcpy(b[j*cntLen], x->recordID, sizeof(int));
                    memcpy(b[j*cntLen+sizeof(int)], x->data, cnt);
                    flag=true;
                    bpm->markDirty(index);
                    bpm->writeBack(index);
                    break;
                }
            }
        if(flag)return x->recordID;
        }
    }
    
    //return 0;
    
}

int RecordManager::deleteRecord(Record *x)
{
    //把对应位置的id变成0就行
    string dataBaseName = x->dataBaseName;
    string recordName = x->recordName;
    
    string fileName = "./data/"+dataBaseName+"/"+recordName+".data"
    
    int fileID = openFile(fileName);
    
    int y = 0;
    
    int cntLen = cnt + sizeof(int);
    int recordInEachPage = 8192 / cntLen;
    int pageID = (x->recordID-1)/recordInEachPage + 1;
    BufType b = bpm->allocPage(fileID, pageID, index, false);
    
    int md = x->recordID%recordInEachPage;
    
    memcpy(b[md*cntLen], &y, sizeof(int));
    //memcpy(b[md*cntLen+sizeof(int)] ,x->data, cnt);
    bpm->markDirty(index); //标记脏页
//    return x->recordID;

    return 0;
    
}

int RecordManager::updateRecord(Record *x)
{
    string dataBaseName = x->dataBaseName;
    string recordName = x->recordName;
    
    string fileName = "./data/"+dataBaseName+"/"+recordName+".data"
    
    int fileID = openFile(fileName);
    
    //int y = 0;
    
    int cntLen = cnt + sizeof(int);
    int recordInEachPage = 8192 / cntLen;
    int pageID = (x->recordID-1)/recordInEachPage + 1;
    BufType b = bpm->allocPage(fileID, pageID, index, false);
    
    int md = x->recordID%recordInEachPage;
    
    //memcpy(b[md*cntLen], &y, sizeof(int));
    memcpy(x->data, b[md*cntLen+sizeof(int)] , cnt);
    bpm->markDirty(index); //标记脏页
    
    printf("更新记录\n");
    return 0;
    
}

int RecordManager::queryRecord(Record *x)
{
    printf("按照特定值询问一条记录\n");
    //目前还没有设定怎样算是特定记录，但我每条记录有一个独特的ID，update就是用这个来更新的
    return updateRecord(x);

    
}
RecordManager::RecordManager()
{
    FileManager* fm= new FileManager();
    BufPageManager* bpm = new BufPageManager(fm);
    
}

RecordManager::~RecordManager()
{
    delete fm; fm = NULL;
    delete bpm; bpm = NULL;
}

int RecordManager::createRecord(string dataBaseName, string recordName, int *ID_list, string* name_list, int len)
{
    string tName = "./data/" + dataBaseName + "/" + recordName + ".type.in";
    string dName = "./data/" + dataBaseName + "/" + recordName + ".data.in"
    fstream _file;
    _file.open(tName,ios::in);
    
    if(_file)
    {
        printf("this table has exists, create failed");
        return -1;
    }
    
    createFile(tName);
    createFile(dName);
    
    /*
     这一段其实要在tName里面写下这个表的结构
    */
    return 0;
    
}
