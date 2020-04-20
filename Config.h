//
// Created by Yaozy on 2020/3/14.
//

#ifndef FRAMEWORK_CONFIG_H
#define FRAMEWORK_CONFIG_H

#include <vector>
#include <string>
#include <any>
#include "DataPacket.h"

class IPC : public DataPacket {
public:
    IPC();
    IPC(const IPC &iPC);
    IPC& operator=(const IPC &iPC);
    ~IPC();
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    string _Source;
    string _Usr;
    string _Pwd;
    string _IP;
    int _Port;
    int _Channel;
    string _ID;
    int _Mode;
    string _Name;
};

class Engine : public DataPacket {
public:
    Engine();
    Engine(const Engine &engine);
    Engine& operator=(const Engine &engine);
    ~Engine();
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    string _Name;
    int _ID;
    string _AlgorithmType;
};

class MyPoint : public DataPacket {
public:
    MyPoint();
    ~MyPoint();
    MyPoint(const MyPoint & point);
    MyPoint& operator=(const MyPoint &point);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    double _X;
    double _Y;
};

class Region : public DataPacket {
public:
    Region();
    ~Region();
    Region(const Region &points);
    Region &operator=(const Region &points);
    void DecodeJson(cJSON *reader) override;
    void EncodeJson(cJSON *writer) override;
    vector<MyPoint> _Points;
};

class DetectArgs : public DataPacket {
public:
    DetectArgs();
    ~DetectArgs();
    DetectArgs(const DetectArgs &points);
    DetectArgs &operator=(const DetectArgs &points);
    void DecodeJson(cJSON *reader) override;
    void EncodeJson(cJSON *writer) override;
    string _IPCID;
    string _RegionType;
    vector<Region> _RegionsList;
};

class  SourceArgs : public DataPacket {
public:
    SourceArgs();
    ~SourceArgs();
    SourceArgs(const SourceArgs & sourceArgs);
    SourceArgs& operator=(const SourceArgs &sourceArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    int _FrameRate;
    vector<string> _IPCIDList;
};

class ChooseArgs : public DataPacket{
public:
    ChooseArgs();
    ~ChooseArgs();
    ChooseArgs(const ChooseArgs & ChooseArgs);
    ChooseArgs& operator=(const ChooseArgs &ChooseArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    double _Score;
    int _IntervalSeconds;
    bool _AlarmSwitch;
};
class VehicleChooseArgs : public DataPacket{
public:
    VehicleChooseArgs();
    ~VehicleChooseArgs();
    VehicleChooseArgs(const VehicleChooseArgs & ChooseArgs);
    VehicleChooseArgs& operator=(const VehicleChooseArgs &ChooseArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    double _Score;
    int _IntervalSeconds;
    int _PCount;
    int _MaxWaite;
    double _MinLicenseScore;
    double _MinCarScore;
    double _AreaRatio;
    bool _AlarmSwitch;
};
class EngineArgs : public DataPacket {
public:
    EngineArgs();
    ~EngineArgs();
    EngineArgs(const EngineArgs & engineArgs);
    EngineArgs& operator=(const EngineArgs &engineArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    string _AlgorithmType;
    vector<DetectArgs> _DetectArgsList;
    any _ChooseArgs;
};

class TransmissionArgs : public DataPacket {
public:
    TransmissionArgs();
    ~TransmissionArgs();
    TransmissionArgs(const TransmissionArgs & transmissionArgs);
    TransmissionArgs& operator=(const TransmissionArgs &transmissionArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    string _ReportUrl;
    string _Key;
    string _ID;
    string _Name;
};
class BusinessArgs : public DataPacket {
public:
    BusinessArgs();
    ~BusinessArgs();
    BusinessArgs(const BusinessArgs & businessArgs);
    BusinessArgs& operator=(const BusinessArgs &businessArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    string _Name;
    string _ID;
    SourceArgs _SourceArgs;
    EngineArgs _EngineArgs;
    vector<TransmissionArgs> _TransmissionArgsList;
};


class DeviceArgs : public DataPacket {
public:
    DeviceArgs();
    ~DeviceArgs();
    DeviceArgs(const DeviceArgs & DeviceArgs);
    DeviceArgs& operator=(const DeviceArgs &DeviceArgs);
    void DecodeJson(cJSON *reader) override ;
    void EncodeJson(cJSON *writer) override ;
    vector<BusinessArgs> _BusinessList;
    vector <Engine> _EngineList;
    vector<IPC> _IPCList;
};
#endif //FRAMEWORK_CONFIG_H
