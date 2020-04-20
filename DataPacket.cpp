//
// Created by Yaozy on 2019/10/9.
//
#include "DataPacket.h"

void GetJsonValue(cJSON * Node,string &Value){
    if (!cJSON_IsNull(Node) && (cJSON_IsString(Node) || cJSON_IsNumber(Node) ))
        Value = Node->valuestring;
    else
        Value = "";
}
void GetJsonValue(cJSON * Node,int &Value){
    if (!cJSON_IsNull(Node) && cJSON_IsNumber(Node))
        Value = Node->valueint;
    else
        Value = 0;
}
void GetJsonValue(cJSON * Node,double &Value){
    if (!cJSON_IsNull(Node) && cJSON_IsNumber(Node))
        Value = Node->valuedouble;
    else
        Value = 0.0;
}
void GetJsonValue(cJSON * Node,bool &Value) {
    Value = cJSON_IsTrue(Node) != 0;
}

void GetJsonValue(cJSON * Node,DataPacket &Value){
    Value.DecodeJson(Node);
}


cJSON * cJSON_Create(string &Value){
    return cJSON_CreateString(Value.c_str());
}

cJSON * cJSON_Create(int &Value){
    return cJSON_CreateNumber(Value);
}
cJSON * cJSON_Create(double &Value){
    return cJSON_CreateNumber(Value);
}

cJSON * cJSON_Create(float &Value){
    return cJSON_CreateNumber(Value);
}
cJSON * cJSON_Create(bool &Value){
    return cJSON_CreateBool(Value);
}
cJSON * cJSON_Create(DataPacket &Value){
    cJSON * Item = Value.CreateWriter();
    Value.EncodeJson(Item);
    return Item;
}
void DataPacket::Clear() {

}
string DataPacket::GetJsonText() {
    cJSON *writer = CreateWriter();
    try {
        EncodeJson(writer);
    } catch (...) {

    }
    char *p = cJSON_PrintUnformatted(writer);
    string json = p;
    cJSON_Delete(writer);
    free(p);
    return json;
}

void DataPacket::SetJsonText(const string &Text) {
    Clear();
    cJSON *reader = cJSON_Parse(Text.c_str());
    if (reader != nullptr) {
        try {
            DecodeJson(reader);
        } catch (...) {

        }
        cJSON_Delete(reader);
    }
}

cJSON *DataPacket::CreateWriter() {
    return cJSON_CreateObject();
}
