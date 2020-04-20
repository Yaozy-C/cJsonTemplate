//
// Created by Yaozy on 2020/3/14.
//

#include "Config.h"

IPC::IPC() {
    _Port = 554;
    _Channel = 101;
    _Mode = 0;
}

IPC::~IPC() = default;

IPC::IPC(const IPC & iPC){
    _Source = iPC._Source;
    _Usr = iPC._Usr;
    _Pwd = iPC._Pwd;
    _IP = iPC._IP;
    _Port = iPC._Port;
    _Channel = iPC._Channel;
    _ID = iPC._ID;
    _Mode = iPC._Mode;
    _Name = iPC._Name;
}

IPC & IPC::operator =(const IPC &iPC) {
    if(this==&iPC)
        return *this;
    _Source = iPC._Source;
    _Usr = iPC._Usr;
    _Pwd = iPC._Pwd;
    _IP = iPC._IP;
    _Port = iPC._Port;
    _Channel = iPC._Channel;
    _ID = iPC._ID;
    _Mode = iPC._Mode;
    _Name = iPC._Name;
    return *this;
}
void IPC::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"Source",_Source);
    GetJsonValue(reader,"Usr",_Usr);
    GetJsonValue(reader,"Pwd",_Pwd);
    GetJsonValue(reader,"IP",_IP);
    GetJsonValue(reader,"Port",_Port);
    GetJsonValue(reader,"Channel",_Channel);
    GetJsonValue(reader,"ID",_ID);
    GetJsonValue(reader,"Mode",_Mode);
    GetJsonValue(reader,"Name",_Name);
}

void IPC::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"Source",_Source);
    AddJsonValue(writer,"Usr",_Usr);
    AddJsonValue(writer,"Pwd",_Pwd);
    AddJsonValue(writer,"IP",_IP);
    AddJsonValue(writer,"Port",_Port);
    AddJsonValue(writer,"Channel",_Channel);
    AddJsonValue(writer,"ID",_ID);
    AddJsonValue(writer,"Mode",_Mode);
    AddJsonValue(writer,"Name",_Name);
}

Engine::Engine() {
    _ID = 0;
}

Engine::~Engine() = default;


Engine::Engine(const Engine & engine){
    _Name = engine._Name;
    _ID = engine._ID;
    _AlgorithmType = engine._AlgorithmType;
}

Engine & Engine::operator =(const Engine &engine) {
    if(this==&engine)
        return *this;
    _Name = engine._Name;
    _ID = engine._ID;
    _AlgorithmType = engine._AlgorithmType;
    return *this;
}
void Engine::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"Name",_Name);
    GetJsonValue(reader,"ID",_ID);
    GetJsonValue(reader,"AlgorithmType",_AlgorithmType);
}

void Engine::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"Name",_Name);
    AddJsonValue(writer,"ID",_ID);
    AddJsonValue(writer,"AlgorithmType",_AlgorithmType);
}


MyPoint::MyPoint() {
    _X = 0;
    _Y = 0;
}
MyPoint::~MyPoint() = default;

MyPoint::MyPoint(const MyPoint & point){
    _X = point._X;
    _Y = point._Y;
}

MyPoint & MyPoint::operator =(const MyPoint &point) {
    if(this==&point)
        return *this;
    _X = point._X;
    _Y = point._Y;
    return *this;
}
void MyPoint::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"X",_X);
    GetJsonValue(reader,"Y",_Y);
}

void MyPoint::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"X",_X);
    AddJsonValue(writer,"Y",_Y);
}


Region::Region() = default;

Region::~Region() = default;


Region::Region(const Region & points){
    _Points = points._Points;
}

Region & Region::operator =(const Region &points) {
    if(this==&points)
        return *this;
    _Points = points._Points;
    return *this;
}
void Region::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"Points",_Points);
}

void Region::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"Points",_Points);
}

DetectArgs::DetectArgs() = default;
DetectArgs::~DetectArgs() = default;

DetectArgs::DetectArgs(const DetectArgs & detectArgs){
    _RegionsList = detectArgs._RegionsList;
    _IPCID = detectArgs._IPCID;
    _RegionType = detectArgs._RegionType;
}

DetectArgs & DetectArgs::operator =(const DetectArgs &detectArgs) {
    if(this==&detectArgs)
        return *this;
    _RegionsList = detectArgs._RegionsList;
    _IPCID = detectArgs._IPCID;
    _RegionType = detectArgs._RegionType;
    return *this;
}
void DetectArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"IPCID",_IPCID);
    GetJsonValue(reader,"RegionType",_RegionType);
    GetJsonValue(reader,"Region",_RegionsList);
}

void DetectArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"IPCID",_IPCID);
    AddJsonValue(writer,"RegionType",_RegionType);
    AddJsonValue(writer,"Region",_RegionsList);
}


SourceArgs::SourceArgs() {
    _FrameRate = 0;
};
SourceArgs::~SourceArgs() = default;

SourceArgs::SourceArgs(const SourceArgs & sourceArgs){
    _FrameRate = sourceArgs._FrameRate;
    _IPCIDList = sourceArgs._IPCIDList;
}

SourceArgs & SourceArgs::operator =(const SourceArgs &sourceArgs) {
    if(this==&sourceArgs)
        return *this;
    _FrameRate = sourceArgs._FrameRate;
    _IPCIDList = sourceArgs._IPCIDList;
    return *this;
}
void SourceArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"FrameRate",_FrameRate);
    GetJsonValue(reader,"IPCIDs",_IPCIDList);
}

void SourceArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"FrameRate",_FrameRate);
    AddJsonValue(writer,"IPCIDs",_IPCIDList);
}


ChooseArgs::ChooseArgs() {
    _Score = 0;
    _IntervalSeconds = 0;
    _AlarmSwitch = false;
};
ChooseArgs::~ChooseArgs() = default;

ChooseArgs::ChooseArgs(const ChooseArgs & chooseArgs){
    _Score = chooseArgs._Score;
    _IntervalSeconds = chooseArgs._IntervalSeconds;
    _AlarmSwitch = chooseArgs._AlarmSwitch;
}

ChooseArgs & ChooseArgs::operator =(const ChooseArgs &chooseArgs) {
    if(this==&chooseArgs)
        return *this;
    _Score = chooseArgs._Score;
    _IntervalSeconds = chooseArgs._IntervalSeconds;
    _AlarmSwitch = chooseArgs._AlarmSwitch;
    return *this;
}
void ChooseArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"Score",_Score);
    GetJsonValue(reader,"IntervalSeconds",_IntervalSeconds);
    GetJsonValue(reader,"AlarmSwitch",_AlarmSwitch);
}

void ChooseArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"Score",_Score);
    AddJsonValue(writer,"IntervalSeconds",_IntervalSeconds);
    AddJsonValue(writer,"AlarmSwitch",_AlarmSwitch);
}

VehicleChooseArgs::VehicleChooseArgs() {
    _PCount = 15;
    _MaxWaite = 10;
    _MinLicenseScore = 0.9;
    _MinCarScore = 0.3;
    _AreaRatio = 0.6;
    _Score = 0.6;
    _IntervalSeconds = 10;
    _AlarmSwitch = false;
};
VehicleChooseArgs::~VehicleChooseArgs() = default;

VehicleChooseArgs::VehicleChooseArgs(const VehicleChooseArgs & chooseArgs){
    _PCount = chooseArgs._PCount;
    _MaxWaite = chooseArgs._MaxWaite;
    _MinLicenseScore = chooseArgs._MinLicenseScore;
    _MinCarScore = chooseArgs._MinCarScore;
    _AreaRatio = chooseArgs._AreaRatio;
    _Score = chooseArgs._Score;
    _IntervalSeconds = chooseArgs._IntervalSeconds;
    _AlarmSwitch = chooseArgs._AlarmSwitch;
}

VehicleChooseArgs & VehicleChooseArgs::operator =(const VehicleChooseArgs &chooseArgs) {
    if(this==&chooseArgs)
        return *this;
    _PCount = chooseArgs._PCount;
    _MaxWaite = chooseArgs._MaxWaite;
    _MinLicenseScore = chooseArgs._MinLicenseScore;
    _MinCarScore = chooseArgs._MinCarScore;
    _AreaRatio = chooseArgs._AreaRatio;
    _Score = chooseArgs._Score;
    _IntervalSeconds = chooseArgs._IntervalSeconds;
    _AlarmSwitch = chooseArgs._AlarmSwitch;
    return *this;
}
void VehicleChooseArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"PCount",_PCount);
    GetJsonValue(reader,"MaxWaite",_MaxWaite);
    GetJsonValue(reader,"MinLicenseScore",_MinLicenseScore);
    GetJsonValue(reader,"MinCarScore",_MinCarScore);
    GetJsonValue(reader,"AreaRatio",_AreaRatio);
    GetJsonValue(reader,"Score",_Score);
    GetJsonValue(reader,"IntervalSeconds",_IntervalSeconds);
    GetJsonValue(reader,"AlarmSwitch",_AlarmSwitch);
}

void VehicleChooseArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"PCount",_PCount);
    AddJsonValue(writer,"MaxWaite",_MaxWaite);
    AddJsonValue(writer,"MinLicenseScore",_MinLicenseScore);
    AddJsonValue(writer,"MinCarScore",_MinCarScore);
    AddJsonValue(writer,"AreaRatio",_AreaRatio);
    AddJsonValue(writer,"Score",_Score);
    AddJsonValue(writer,"IntervalSeconds",_IntervalSeconds);
    AddJsonValue(writer,"AlarmSwitch",_AlarmSwitch);
}

EngineArgs::EngineArgs() =default;
EngineArgs::~EngineArgs() = default;

EngineArgs::EngineArgs(const EngineArgs & engineArgs){
    _ChooseArgs = engineArgs._ChooseArgs;
    _AlgorithmType = engineArgs._AlgorithmType;
    _DetectArgsList = engineArgs._DetectArgsList;
}

EngineArgs & EngineArgs::operator =(const EngineArgs &engineArgs) {
    if(this==&engineArgs)
        return *this;
    _ChooseArgs = engineArgs._ChooseArgs;
    _AlgorithmType = engineArgs._AlgorithmType;
    _DetectArgsList = engineArgs._DetectArgsList;
    return *this;
}
void EngineArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"AlgorithmType",_AlgorithmType);
    GetJsonValue(reader,"DetectArgs",_DetectArgsList);
    if (_AlgorithmType == "VehicleDetect"){
        VehicleChooseArgs Tmp;
        GetJsonValue(reader,"ChooseArgs",Tmp);
        _ChooseArgs = Tmp;
    } else{
        ChooseArgs Tmp;
        GetJsonValue(reader,"ChooseArgs",Tmp);
        _ChooseArgs = Tmp;
    }
}

void EngineArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"AlgorithmType",_AlgorithmType);
    AddJsonValue(writer,"DetectArgs",_DetectArgsList);
    if (_AlgorithmType == "VehicleDetect"){
        auto Tmp = any_cast<VehicleChooseArgs>(_ChooseArgs);
        AddJsonValue(writer,"ChooseArgs",Tmp);
    } else{
        auto Tmp = any_cast<ChooseArgs>(_ChooseArgs);
        AddJsonValue(writer,"ChooseArgs",Tmp);
    }
}

TransmissionArgs::TransmissionArgs() = default;
TransmissionArgs::~TransmissionArgs() = default;

TransmissionArgs::TransmissionArgs(const TransmissionArgs & transmissionArgs){
    _ReportUrl = transmissionArgs._ReportUrl;
    _Key = transmissionArgs._Key;
    _ID = transmissionArgs._ID;
    _Name = transmissionArgs._Name;
}

TransmissionArgs & TransmissionArgs::operator =(const TransmissionArgs &transmissionArgs) {
    if(this==&transmissionArgs)
        return *this;
    _ReportUrl = transmissionArgs._ReportUrl;
    _Key = transmissionArgs._Key;
    _ID = transmissionArgs._ID;
    _Name = transmissionArgs._Name;
    return *this;
}
void TransmissionArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"ReportUrl",_ReportUrl);
    GetJsonValue(reader,"Key",_Key);
    GetJsonValue(reader,"ID",_ID);
    GetJsonValue(reader,"Name",_Name);
}

void TransmissionArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"ReportUrl",_ReportUrl);
    AddJsonValue(writer,"Key",_Key);
    AddJsonValue(writer,"ID",_ID);
    AddJsonValue(writer,"Name",_Name);
}

BusinessArgs::BusinessArgs() = default;
BusinessArgs::~BusinessArgs() = default;

BusinessArgs::BusinessArgs(const BusinessArgs & businessArgs){
    _ID = businessArgs._ID;
    _Name = businessArgs._Name;
    _SourceArgs = businessArgs._SourceArgs;
    _EngineArgs = businessArgs._EngineArgs;
    _TransmissionArgsList = businessArgs._TransmissionArgsList;
}

BusinessArgs & BusinessArgs::operator =(const BusinessArgs &businessArgs) {
    if(this==&businessArgs)
        return *this;
    _ID = businessArgs._ID;
    _Name = businessArgs._Name;
    _SourceArgs = businessArgs._SourceArgs;
    _EngineArgs = businessArgs._EngineArgs;
    _TransmissionArgsList = businessArgs._TransmissionArgsList;
    return *this;
}
void BusinessArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"ID",_ID);
    GetJsonValue(reader,"Name",_Name);
    GetJsonValue(reader,"SourceArgs",_SourceArgs);
    GetJsonValue(reader,"EngineArgs",_EngineArgs);
    GetJsonValue(reader,"TransmissionArgs",_TransmissionArgsList);
}

void BusinessArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"ID",_ID);
    AddJsonValue(writer,"Name",_Name);
    AddJsonValue(writer,"SourceArgs",_SourceArgs);
    AddJsonValue(writer,"EngineArgs",_EngineArgs);
    AddJsonValue(writer,"TransmissionArgs",_TransmissionArgsList);
}

DeviceArgs::DeviceArgs() = default;
DeviceArgs::~DeviceArgs() = default;

DeviceArgs::DeviceArgs(const DeviceArgs & deviceArgs){
    _BusinessList = deviceArgs._BusinessList;
    _EngineList = deviceArgs._EngineList;
    _IPCList = deviceArgs._IPCList;
}

DeviceArgs & DeviceArgs::operator =(const DeviceArgs &deviceArgs) {
    if(this==&deviceArgs)
        return *this;
    _BusinessList = deviceArgs._BusinessList;
    _EngineList = deviceArgs._EngineList;
    _IPCList = deviceArgs._IPCList;
    return *this;
}
void DeviceArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader,"Businesses",_BusinessList);
    GetJsonValue(reader,"Engines",_EngineList);
    GetJsonValue(reader,"IPCs",_IPCList);
}

void DeviceArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer,"Businesses",_BusinessList);
    AddJsonValue(writer,"Engines",_EngineList);
    AddJsonValue(writer,"IPCs",_IPCList);
}