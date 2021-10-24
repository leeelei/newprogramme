// ReadConfig.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct configItem
{
    char key[20];
    char value[50];
};

configItem configList[] = {
    {"ip", 0},
    {"port", 0},
    {"line", 0}
};

/*
* 这个函数是对给定的一个字符串寻找以等号分开的键值对
* src -- 源字符串
* key -- 键
* value -- 值
*/
int strkv(char *src, char *key, char *value)
{
    char *p, *q;
    int len;
    p = strchr(src, '=');//p找到等号
    q = strchr(src, '\n');//q找到换行

    //如果有等号有换行
    if (p != NULL && q != NULL)
    {
        *q = '\0'; //将换行设置为字符串结尾
        strncpy(key, src, p-src); //将等号前的内容拷入key中
        strcpy(value, p+1); //将等号后的内容拷入value中，跳过等号所以p需要加1
        return 1;
    }
    return 0;
}

/*
*  读取配置函数
*
*/
void Config(char * configFilePath, struct configItem* configVar, int configNum)
{
    int i;
    FILE * pfile;
    char buf[50] = "";  //缓冲字符串
    char key[50] = "";  //配置变量名
    char value[50] = ""; //配置变量值

    //打开配置文件
    pfile = fopen(configFilePath, "r");

    if (pfile == NULL)
    {
        printf("配置文件打开失败!\n");
        exit(-1);
    }

    //依次读取文件的每一行
    while (fgets(buf, 50, pfile))
    {
        //读取键值对
        if (strkv(buf, key, value))
        {
            //读取成功则循环匹配数组
            for (i = 0; i < configNum; i++)
            {
                //名称相等则匹配成功，拷贝value值
                if (strcmp(key, configVar[i].key) == 0)
                {
                    strcpy(configVar[i].value, value);
                }
            }
            //key字符串在strkv函数内部没有给结束符'\0'，需要这里重置一下
            //value在strkv中已经给了结束符'\0'
            memset(key, 0, strlen(key));
        }

    }
    fclose(pfile);
}

void main()
{
    int i;
    //读取配置文件
    Config("C:\\config.txt",
        configList,
        sizeof(configList)/sizeof(struct configItem)
        );

    for (i = 0; i < sizeof(configList)/sizeof(struct configItem); i++)
    {
        printf("%s=%s \n", configList[i].key, configList[i].value);
    }
    system("pause");
}
