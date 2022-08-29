//
// Created by root1 on 2022/8/28.
//
#ifndef INC_0828_PERSONLIT_H
#define INC_0828_PERSONLIT_H
#pragma once
#include<iostream>

using namespace std;
#define INITSIZE 10
#define STEP 5
//线性表的动态实现 常见操作 创销毁 增删改查找

//定义要线性表存数的数据类型
struct Person{
    int age;
    char gender;
    char name;
};
//定义线性表类型
struct PersonLit {
    //指针指向真实的存储数据
    Person * person;
    int maxSize;
    int length;
};
//创建一个线性表
void CreatList(PersonLit &personLit);
//销毁数据 就是释放内存
void DestoryList(PersonLit &personLit);
//展示表中的数据
void PrintList(const PersonLit &personLit);
// 以 step为步长扩展表的长度
void IncreaseList(PersonLit &personLit);
void GenerateData(PersonLit &personLit);
// 判断是否满了
bool IsFull(const PersonLit &personLit);
//判断是否为空表
bool IsEmpty(const PersonLit &personLit);
//添加数据 具体位置有程序输入
void InsertData(PersonLit &personLit,Person person);
//删除数据 传入是位置
void DeleteData(PersonLit &personLit);
//刷新界面
void Fresh();
void Run();
void ShowMenu();
void InquireByPosition(const PersonLit &personLit);
#endif //INC_0828_PERSONLIT_H
