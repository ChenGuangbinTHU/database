/*
 
 设定是这样，我们的数据库定为程序所在目录下的database文件夹为整个数据库的根目录
 然后数据库开一层文件夹，表项再开一层文件夹
 最里面再放数据
 
*/

#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H


#include "tableData.h"

class systemManager()
{
private:
    systemManager();//要在此检查
    static systemManager * m_pInstance;
    
    string nowDBname;
    
public:
    
    
    
    static systemManager * getInstance()
    {
        if(m_pInstance == NULL)
            m_pInstance = new systemManager();
        return m_pInstance;
    }
    
    int createTable(tableData *table);
    //在nowDBname的文件夹下创建一个与table名相同的子文件夹，若已存在则报错
    
    
    int dropTable(string tableName);
    //在nowDBname的文件夹下删除tableName文件夹，若不存在则报错
    
    
    int showTable(string tableName);
    //显示nowDBname的文件夹下tableName子文件夹的信息，若不存在则报错
    
    
    int createDatabase(string DBname);
    //创建DBname文件夹，若存在则报错
    
    
    int dropDatabase(string DBname);
    //删除DBname文件夹，若不存在则报错
    
    
    int useDatabase(string DBname);
    //修改nowDBname信息，检查该子文件夹是否存在，若不存在则报错
    
    int showDatabase();
    //显示根目录下所有子文件夹名字
    
};

#endif
