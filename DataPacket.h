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

void GetJsonValue(cJSON *node, string &value);

void GetJsonValue(cJSON *node, int &value);

void GetJsonValue(cJSON *node, double &value);

void GetJsonValue(cJSON *node, bool &value);

void GetJsonValue(cJSON *node, DataPacket &value);

template<typename T>
void GetJsonValue(cJSON *node, vector<T> &value) {
    value.clear();
    if (!cJSON_IsNull(node) && cJSON_IsArray(node)) {
        int ArraySize = cJSON_GetArraySize(node);
        for (int i = 0; i < ArraySize; ++i) {
            cJSON *Item = cJSON_GetArrayItem(node, i);
            T Temp;
            GetJsonValue(Item, Temp);
            value.emplace_back(Temp);
        }
    }
}

template<typename T>
void GetJsonValue(cJSON *node, const char *nodeName, T &value) {
    cJSON *Temp = cJSON_GetObjectItem(node, nodeName);
    GetJsonValue(Temp, value);
}

template<typename T>
void GetJsonValue(cJSON *node, const char *nodeName, vector<T> &value) {
    cJSON *Item = cJSON_GetObjectItem(node, nodeName);
    GetJsonValue(Item, value);
}

cJSON *cJSON_Create(string &value);

cJSON *cJSON_Create(int &value);

cJSON *cJSON_Create(double &value);

cJSON *cJSON_Create(bool &value);

cJSON *cJSON_Create(float &value);

cJSON *cJSON_Create(DataPacket &value);

template<typename T>
void AddJsonValue(cJSON *node, const char *nodeName, T &Value) {
    cJSON *Item = cJSON_Create(Value);
    cJSON_AddItemToObject(node, nodeName, Item);
}

template<typename T>
void AddJsonValue(cJSON *node, const char *nodeName, vector<T> &value) {
    cJSON *Obj = cJSON_CreateArray();
    for (int i = 0; i < value.size(); ++i) {
        cJSON *Inode = cJSON_Create(value[i]);
        cJSON_AddItemToArray(Obj, Inode);
    }
    cJSON_AddItemToObject(node, nodeName, Obj);
}

class DataPacket {
private:

public:
    DataPacket() = default;

    ~DataPacket() = default;

    virtual void Clear();

    virtual string GetJsonText();

    virtual void SetJsonText(const string &text);

    virtual cJSON *CreateWriter();

    virtual void EncodeJson(cJSON *writer) = 0;

    virtual void DecodeJson(cJSON *reader) = 0;
};

template<typename T>
class ObjectList : public DataPacket {
private:
    vector<T> list;
public:
    ObjectList() = default;

    ~ObjectList() = default;

    T &operator[](int index) {
        return list[index];
    };

    void Add(T &item) {
        list.emplace_back(item);
    };

    void DecodeJson(cJSON *reader) override {
        list.clear();
        if (cJSON_IsArray(reader)) {
            int ArraySize = cJSON_GetArraySize(reader);
            for (int i = 0; i < ArraySize; ++i) {
                cJSON *Item = cJSON_GetArrayItem(reader, i);
                T Tmp;
                GetJsonValue(Item, Tmp);
                list.emplace_back(Tmp);
            }
        }
    };

    void EncodeJson(cJSON *writer) override {
        for (int i = 0; i < list.size(); ++i) {
            cJSON *Item = cJSON_Create(list[i]);
            cJSON_AddItemToArray(writer, Item);
        }
    };

    cJSON *CreateWriter() override {
        return cJSON_CreateArray();
    };

    int Count() {
        return list.size();
    };

    vector<T> &Items() {
        return list;
    };
};


#endif //DATAPACKET_H
