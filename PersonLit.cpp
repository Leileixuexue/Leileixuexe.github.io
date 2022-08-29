//
// Created by root1 on 2022/8/28.
//
#include "PersonLit.h"
void ShowMenu()
{
    cout<<"welcome to use my program"<<endl;
    cout<<" ------1: creat a linear list"<<endl;
    cout<<" ------2: print a linear list"<<endl;
    cout<<" ------3: delete a linear list element"<<endl;
    cout<<" ------4: add a linear list element"<<endl;
    cout<<" ------5: destory a linear list "<<endl;
    cout<<" ------6: index element by position "<<endl;
    cout<<" ------7: exit program "<<endl;
    cout<<"\tset your choice"<<endl;

}
void Run()
{

    //创建临时数据用来进行添加
    Person p1={12,'m','c'};
    //创建线性表的对象
    PersonLit personLit1={nullptr,0,0};
    while(true)
    {
        ShowMenu();
        int flag(0);
        cin>>flag;
        if (flag==-1)
        {
            break;
        }
        switch (flag) {
            case 1:
                CreatList(personLit1);

                break;
            case 2:
                PrintList(personLit1);
                break;
            case 3:
                DeleteData(personLit1);
                break;
            case 4:
                InsertData(personLit1,p1);
                break;
            case 5:
                DestoryList(personLit1);
                break;
//                按照索引查找数据
            case 6:
                InquireByPosition(personLit1);
                break;
            case 7:
            {
                cout<<"welcome use again"<<endl;
                system("pause");
                return;
            }
            default:
            {
                cout<<"please set your insert"<<endl;
                cin>>flag;
                Fresh();
            }
        }
    }
}
//创建线性表完成内存分配和初始化
void CreatList(PersonLit &personLit)
{
    //分配内存
    personLit.person=new Person [INITSIZE];
    //初始化每一个数据元素 可以不用
    for (int i = 0; i < INITSIZE; ++i) {
        personLit.person[i].name='a';
        personLit.person[i].gender='m';
        personLit.person[i].age=i*10;
    }
    //初始化数据元素之后的操作
    personLit.length=0;
    personLit.maxSize=INITSIZE;
    //完成创建的提示
    cout<<"you hava creat a list capacity is "<<INITSIZE<<
        " have "<<personLit.length<<" items"<<endl;
    Fresh();
}
//回收内存 完成数据销毁
void DestoryList(PersonLit &personLit)
{
//    如果是没有数据
    if (personLit.person== nullptr)
    {
        cout<<"your list not assign space"<<endl;
        Fresh();
        return;
    }

    cout<<"YOU have crash a list whit "<<personLit.length
    <<"items and capacity is"<<personLit.maxSize<<endl;
    personLit.length=0;
    personLit.maxSize=INITSIZE;
    //释放内存
    delete [] personLit.person;
//    删完之后要置空
    personLit.person= nullptr;
    Fresh();
}
void PrintList(const PersonLit &personLit) {
    cout<<"YOU are going to print your list"<<endl;
    //检查 是否是空表 空白表没有数据
    if (IsEmpty(personLit))
    {
        cout<<"you have no data to show"<<endl;
        Fresh();
        return;
    }
    cout<<"your list contain "<<personLit.length<<"items:"<<endl;
    //打印每一条数据
    for (int i = 0; i < personLit.length; ++i) {
        cout<<"\tNO "<<i+1<<" data "<<"name :"<<personLit.person[i].name
            <<" age :"<<personLit.person[i].age<<endl;
    }
    Fresh();
}
//随机产生3条数据
void GenerateData(PersonLit &personLit)
{
//    判断是否满了
    if (IsFull(personLit))
    {
        cout<<"your list id full"<<endl;
        return;
    }
    //已经对数据进行过初始化了
    personLit.length=personLit.length+1;
    cout<<"we have generate 3 data"<<endl;
}
void IncreaseList(PersonLit &personLit)
{
    cout<<"YOU are going to increase a list :"<<endl;
    cout<<"Before Maxsize :"<<personLit.maxSize<<endl;
    cout<<"before length :"<<personLit.length<<endl;
    //1.移交控制权
    Person *tmp=personLit.person;
    //重新分配空间 在原有的maxsize上增长
    personLit.person=new Person[personLit.maxSize+STEP];
    //数据迁移
    for (int i = 0; i < personLit.maxSize; ++i) {
        personLit.person[i].age=tmp[i].age;
        personLit.person[i].name=tmp[i].name;
        personLit.person[i].gender=tmp[i].gender;
    }
    //扩展最大长度
    personLit.maxSize=personLit.maxSize+STEP;
    cout<<"you have increase your list"<<endl;
    cout<<"after Maxsize :"<<personLit.maxSize<<endl;
    cout<<"after length :"<<personLit.length<<endl;
    //销毁原来的数据 很重要
    delete [] tmp;
    cout<<"your list have grow once"<<endl;
    Fresh();
}
//判空
bool IsEmpty(const PersonLit &personLit)
{
    return (personLit.person== nullptr||personLit.length==0);
}
bool IsFull(const PersonLit &personLit)
{
    return personLit.length==personLit.maxSize;
}
//添加数据
void InsertData(PersonLit & personLit,Person person)
{
//    需要判断是否分配空间
    if (personLit.person== nullptr)
    {
        cout<<"your list is not assign space"<<endl;
        Fresh();
        return;
    }
    //万一满了 没有地方存放数据
    if(personLit.length==personLit.maxSize)
    {
        cout<<"your list is if full we will increase it"<<endl;
        IncreaseList(personLit);

    }
    cout<<"YOU are going to insert a data in list have "
    <<personLit.length<<" items before insert"<<endl;
    int position(0);
    cout<<"please set your position"<<endl;
    cin>>position;
    //检查位置是否合法 合法的插入位置是【1，length+1】
    while (position<=0||position>personLit.length+1)
    {
        cout<<"your insert position is wrong please check carefully"<<endl;
        cin>>position;
    }
    cout<<"your insert position is "<<position<<endl;
//    cout<<"your input data is:"<<endl;
//    PrintList(personLit);
//    腾出位置
    for (int i = personLit.length; i >=position ; --i) {
        personLit.person[i].name=personLit.person[i-1].name;
        personLit.person[i].age=personLit.person[i-1].age;
        personLit.person[i].gender=personLit.person[i-1].gender;
    }
    //添加数据
    personLit.person[position-1].age=person.age;
    personLit.person[position-1].name=person.name;
    personLit.person[position-1].gender=person.gender;
    personLit.length=personLit.length+1;
    cout<<"YOU have finished data insert"<<endl;
    Fresh();
//    cout<<"here is your list after insert"<<endl;
//    PrintList(personLit);
}
//删除数据
void DeleteData(PersonLit &personLit)
{
    //   判空
    if(IsEmpty(personLit))
    {
        cout<<"your list is empty"<<endl;
        Fresh();
        return;
    }
    cout<<"YOU are gong to delete a list"<<endl;
//    cout<<"before your list is"<<endl;
//    PrintList(personLit);
    int position(0);
    cout<<"please set your delete position"<<endl;
    cin>>position;
    while(position<1||position>personLit.length)
    {
        cout<<"your delete position is wrong please check carefully"<<endl;
        cin>>position;
    }
    cout<<"your delete position is"<<position<<endl;
    //删除数据 从后往前删除
    for (int i = position; i < personLit.length; ++i) {
        personLit.person[i-1].age=personLit.person[i].age;
        personLit.person[i-1].gender=personLit.person[i].gender;
        personLit.person[i-1].name=personLit.person[i].name;
    }
    personLit.length=personLit.length-1;
    cout<<"you have delete a data in position "<<position<<endl;
    Fresh();
//    cout<<"after insert position "<<position<<endl;
//    PrintList(personLit);
}
void Fresh()
{
    system("pause");
    system("cls");
}
void InquireByPosition(const PersonLit &personLit)
{
    cout<<"YOU are going to index element by id"<<endl;
//    万一是空表
    if (IsEmpty(personLit))
    {
        cout<<"your list is empty nothing to index"<<endl;
        Fresh();
        return;
    }
    cout<<"please set your position to be index"<<endl;
    int posotion(0);
//    检查position合法性【1，length】
    while(posotion<1||posotion>personLit.length)
    {
        cout<<"your input position is wrong please check again"<<endl;
        cin>>posotion;
    }
//    返回第position个位置的数据
    Person person=personLit.person[posotion-1];
    cout<<"here is data we indexed:"<<endl;
    cout<<"\t name :"<<person.name<<endl;
    cout<<"\t age :"<<person.age<<endl;
    cout<<"\t gender :"<<person.gender<<endl;
    Fresh();
}


