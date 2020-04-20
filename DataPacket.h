//
// Created by Yaozy on 2019/10/9.
//

#ifndef DATAPACKET_H
#define DATAPACKET_H
#include <string>
#include <vector>
#include <type_traits>
#include <iostream>
#include "cJSON.h"
using namespace std;

class DataPacket;

void GetJsonValue(cJSON * Node,string &Value);
void GetJsonValue(cJSON * Node,int &Value);
void GetJsonValue(cJSON * Node,double &Value);
void GetJsonValue(cJSON * Node,bool &Value);
void GetJsonValue(cJSON * Node,DataPacket &Value);
template <typename T>
void GetJsonValue(cJSON * Node,vector<T> &Value){
    Value.clear();
    if (!cJSON_IsNull(Node) && cJSON_IsArray(Node)){
        int ArraySize = cJSON_GetArraySize(Node);
        for (int i = 0; i < ArraySize; ++i) {
            cJSON * Item = cJSON_GetArrayItem(Node,i);
            T Temp;
            GetJsonValue(Item,Temp);
            Value.emplace_back(Temp);
        }
    }
}

template <typename T>
void GetJsonValue(cJSON * Node,const char* NodeName,T &Value){
    cJSON * Temp = cJSON_GetObjectItem(Node,NodeName);
    GetJsonValue(Temp,Value);
}

template <typename T>
void GetJsonValue(cJSON * Node,const char* NodeName,vector<T> &Value){
    cJSON * Item = cJSON_GetObjectItem(Node,NodeName);
    GetJsonValue(Item,Value);
}

cJSON * cJSON_Create(string &Value);
cJSON * cJSON_Create(int &Value);
cJSON * cJSON_Create(double &Value);
cJSON * cJSON_Create(bool &Value);
cJSON * cJSON_Create(float &Value);
cJSON * cJSON_Create(DataPacket &Value);
template <typename T>
void AddJsonValue(cJSON * Node, const char *NodeName, T& Value){
    cJSON *Item = cJSON_Create(Value);
    cJSON_AddItemToObject(Node,NodeName,Item);
};

template <typename T>
void AddJsonValue(cJSON * Node, const char *NodeName, vector<T> &Value){
    cJSON *Obj = cJSON_CreateArray();
    for (int i = 0; i < Value.size(); ++i) {
        cJSON *Inode = cJSON_Create(Value[i]);
        cJSON_AddItemToArray(Obj,Inode);
    }
    cJSON_AddItemToObject(Node,NodeName,Obj);
}

class DataPacket{
private:

public:
    DataPacket()= default;
    ~DataPacket()= default;
    virtual void Clear();
    virtual string GetJsonText();
    virtual void SetJsonText(const string &Text);
    virtual cJSON *CreateWriter();
    virtual void EncodeJson(cJSON *writer) = 0;
    virtual void DecodeJson(cJSON *reader) = 0;
};
template <typename T >
class ObjectList : public DataPacket{
private:
    vector <T> _List;
public:
    ObjectList()= default;
    ~ObjectList()= default;
    T &operator[](int index){

        return _List[index];
    };
    void Add(T &item){
        _List.emplace_back(item);
    };
    void DecodeJson(cJSON *Reader) override {
        _List.clear();
        if (cJSON_IsArray(Reader)){
            int ArraySize = cJSON_GetArraySize(Reader);
            for (int i = 0; i < ArraySize; ++i) {
                cJSON *Item =cJSON_GetArrayItem(Reader,i);
                T Tmp;
                GetJsonValue(Item,Tmp);
                _List.emplace_back(Tmp);
            }
        }
    };
    void EncodeJson(cJSON *Writer) override{
        for (int i = 0; i < _List.size(); ++i) {
            cJSON * Item = cJSON_Create(_List[i]);
            cJSON_AddItemToArray(Writer,Item);
        }
    } ;
    cJSON *CreateWriter() override{
        return cJSON_CreateArray();
    } ;
    int Count(){
        return _List.size();
    };
    vector <T> &Items(){
        return _List;
    };
};



#endif //DATAPACKET_H
