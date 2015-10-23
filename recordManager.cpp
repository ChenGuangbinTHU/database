
#include "recordManager.h"

#include <cstdio>

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

int RecordManager::insertRecord()
{
    printf("加入一条新记录\n");
    return 0;
    
}

int RecordManager::deleteRecord()
{
    printf("删除一条记录\n");
    return 0;
    
}

int RecordManager::updateRecord()
{
    printf("更新记录\n");
    return 0;
    
}

int RecordManager::queryRecord()
{
    printf("按照特定值询问一条记录\n");
    return 0;
    
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
