//
// Created by Yaozy on 2020/3/14.
//

#ifndef FRAMEWORK_CONFIG_H
#define FRAMEWORK_CONFIG_H

#include <vector>
#include <string>
#include <any>
#include "DataPacket.h"

class RfidDev : public DataPacket {
public:
    RfidDev();

    RfidDev(const RfidDev &rfidDev);

    RfidDev &operator=(const RfidDev &rfidDev);

    ~RfidDev();

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string id;
    string name;
    string ip;
    int port;
};

class IPC : public DataPacket {
public:
    IPC();

    IPC(const IPC &iPC);

    IPC &operator=(const IPC &iPC);

    ~IPC();

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string source;
    string usr;
    string pwd;
    string ip;
    int port;
    int channel;
    string id;
    int mode;
    string name;
};

class Engine : public DataPacket {
public:
    Engine();

    Engine(const Engine &engine);

    Engine &operator=(const Engine &engine);

    ~Engine();

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string name;
    int id;
    string algorithmType;
};

class MyPoint : public DataPacket {
public:
    MyPoint();

    ~MyPoint();

    MyPoint(const MyPoint &point);

    MyPoint &operator=(const MyPoint &point);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    double x;
    double y;
};

class Region : public DataPacket {
public:
    Region();

    ~Region();

    Region(const Region &points);

    Region &operator=(const Region &points);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    vector<MyPoint> points;
};

class DetectArgs : public DataPacket {
public:
    DetectArgs();

    ~DetectArgs();

    DetectArgs(const DetectArgs &points);

    DetectArgs &operator=(const DetectArgs &points);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string iPCID;
    string regionType;
    int type;
    vector<Region> regionsList;
};

class SourceArgs : public DataPacket {
public:
    SourceArgs();

    ~SourceArgs();

    SourceArgs(const SourceArgs &sourceArgs);

    SourceArgs &operator=(const SourceArgs &sourceArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    int frameRate;
    string rfidDevId;
    vector<string> iPCIDList;
};

class ChooseArgs : public DataPacket {
public:
    ChooseArgs();

    ~ChooseArgs();

    ChooseArgs(const ChooseArgs &chooseArgs);

    ChooseArgs &operator=(const ChooseArgs &chooseArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    double score;
    int intervalSeconds;
    bool alarmSwitch;
};

class VehicleChooseArgs : public DataPacket {
public:
    VehicleChooseArgs();

    ~VehicleChooseArgs();

    VehicleChooseArgs(const VehicleChooseArgs &chooseArgs);

    VehicleChooseArgs &operator=(const VehicleChooseArgs &chooseArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    double score;
    int intervalSeconds;
    int pCount;
    int maxWaite;
    double minLicenseScore;
    double minCarScore;
    double areaRatio;
    bool alarmSwitch;
};

class EngineArgs : public DataPacket {
public:
    EngineArgs();

    ~EngineArgs();

    EngineArgs(const EngineArgs &engineArgs);

    EngineArgs &operator=(const EngineArgs &engineArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string algorithmType;
    vector<DetectArgs> detectArgsList;
    any chooseArgs;
};

class TransmissionArgs : public DataPacket {
public:
    TransmissionArgs();

    ~TransmissionArgs();

    TransmissionArgs(const TransmissionArgs &transmissionArgs);

    TransmissionArgs &operator=(const TransmissionArgs &transmissionArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string reportUrl;
    string id;
    string name;
    bool isUpLoad;
    bool isUpLoadAll;
};

class BusinessArgs : public DataPacket {
public:
    BusinessArgs();

    ~BusinessArgs();

    BusinessArgs(const BusinessArgs &businessArgs);

    BusinessArgs &operator=(const BusinessArgs &businessArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string name;
    string id;
    SourceArgs sourceArgs;
    EngineArgs engineArgs;
    vector<TransmissionArgs> transmissionArgsList;
};

class AuthArgs : public DataPacket {
public:
    AuthArgs();

    ~AuthArgs();

    AuthArgs(const AuthArgs &authArgs);

    AuthArgs &operator=(const AuthArgs &authArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    string sn;
    string key;
};

class DeviceArgs : public DataPacket {
public:
    DeviceArgs();

    ~DeviceArgs();

    DeviceArgs(const DeviceArgs &deviceArgs);

    DeviceArgs &operator=(const DeviceArgs &deviceArgs);

    void DecodeJson(cJSON *reader) override;

    void EncodeJson(cJSON *writer) override;

    vector<BusinessArgs> businessList;
    vector<Engine> engineList;
    vector<IPC> iPCList;
    vector<RfidDev> rfidDevList;
    AuthArgs authArgs;
};

class Licenses : public DataPacket {
public:
    vector<string> data;

    void DecodeJson(cJSON *Reader) override;

    void EncodeJson(cJSON *Writer) override;
};

#endif //FRAMEWORK_CONFIG_H
