//
// Created by Yaozy on 2020/3/14.
//

#include "Config.h"


RfidDev::RfidDev(){
    port = 0;
}
RfidDev::RfidDev(const RfidDev &rfidDev) {
    id = rfidDev.id;
    name = rfidDev.name;
    ip = rfidDev.ip;
    port = rfidDev.port;
}

RfidDev & RfidDev::operator=(const RfidDev &rfidDev) {
    if (this == &rfidDev)
        return *this;
    id = rfidDev.id;
    name = rfidDev.name;
    ip = rfidDev.ip;
    port = rfidDev.port;
    return *this;
}

RfidDev::~RfidDev() =default;

void RfidDev::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "ID", id);
    GetJsonValue(reader, "Name", name);
    GetJsonValue(reader, "IP", ip);
    GetJsonValue(reader, "Port", port);

}

void RfidDev::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "ID", id);
    AddJsonValue(writer, "Name", name);
    AddJsonValue(writer, "IP", ip);
    AddJsonValue(writer, "Port", port);
}


IPC::IPC() {
    port = 554;
    channel = 101;
    mode = 0;
}

IPC::~IPC() = default;

IPC::IPC(const IPC &iPC) {
    source = iPC.source;
    usr = iPC.usr;
    pwd = iPC.pwd;
    ip = iPC.ip;
    port = iPC.port;
    channel = iPC.channel;
    id = iPC.id;
    mode = iPC.mode;
    name = iPC.name;
}

IPC &IPC::operator=(const IPC &iPC) {
    if (this == &iPC)
        return *this;
    source = iPC.source;
    usr = iPC.usr;
    pwd = iPC.pwd;
    ip = iPC.ip;
    port = iPC.port;
    channel = iPC.channel;
    id = iPC.id;
    mode = iPC.mode;
    name = iPC.name;
    return *this;
}

void IPC::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Source", source);
    GetJsonValue(reader, "Usr", usr);
    GetJsonValue(reader, "Pwd", pwd);
    GetJsonValue(reader, "IP", ip);
    GetJsonValue(reader, "Port", port);
    GetJsonValue(reader, "Channel", channel);
    GetJsonValue(reader, "ID", id);
    GetJsonValue(reader, "Mode", mode);
    GetJsonValue(reader, "Name", name);
}

void IPC::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Source", source);
    AddJsonValue(writer, "Usr", usr);
    AddJsonValue(writer, "Pwd", pwd);
    AddJsonValue(writer, "IP", ip);
    AddJsonValue(writer, "Port", port);
    AddJsonValue(writer, "Channel", channel);
    AddJsonValue(writer, "ID", id);
    AddJsonValue(writer, "Mode", mode);
    AddJsonValue(writer, "Name", name);
}

Engine::Engine() {
    id = 0;
}

Engine::~Engine() = default;


Engine::Engine(const Engine &engine) {
    name = engine.name;
    id = engine.id;
    algorithmType = engine.algorithmType;
}

Engine &Engine::operator=(const Engine &engine) {
    if (this == &engine)
        return *this;
    name = engine.name;
    id = engine.id;
    algorithmType = engine.algorithmType;
    return *this;
}

void Engine::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Name", name);
    GetJsonValue(reader, "ID", id);
    GetJsonValue(reader, "AlgorithmType", algorithmType);
}

void Engine::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Name", name);
    AddJsonValue(writer, "ID", id);
    AddJsonValue(writer, "AlgorithmType", algorithmType);
}


MyPoint::MyPoint() {
    x = 0;
    y = 0;
}

MyPoint::~MyPoint() = default;

MyPoint::MyPoint(const MyPoint &point) {
    x = point.x;
    y = point.y;
}

MyPoint &MyPoint::operator=(const MyPoint &point) {
    if (this == &point)
        return *this;
    x = point.x;
    y = point.y;
    return *this;
}

void MyPoint::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "X", x);
    GetJsonValue(reader, "Y", y);
}

void MyPoint::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "X", x);
    AddJsonValue(writer, "Y", y);
}


Region::Region() = default;

Region::~Region() = default;


Region::Region(const Region &region) {
    points = region.points;
}

Region &Region::operator=(const Region &region) {
    if (this == &region)
        return *this;
    points = region.points;
    return *this;
}

void Region::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Points", points);
}

void Region::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Points", points);
}

DetectArgs::DetectArgs() {
    type = 1;
};

DetectArgs::~DetectArgs() = default;

DetectArgs::DetectArgs(const DetectArgs &detectArgs) {
    regionsList = detectArgs.regionsList;
    iPCID = detectArgs.iPCID;
    regionType = detectArgs.regionType;
    type = detectArgs.type;
}

DetectArgs &DetectArgs::operator=(const DetectArgs &detectArgs) {
    if (this == &detectArgs)
        return *this;
    regionsList = detectArgs.regionsList;
    iPCID = detectArgs.iPCID;
    regionType = detectArgs.regionType;
    type = detectArgs.type;
    return *this;
}

void DetectArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "IPCID", iPCID);
    GetJsonValue(reader, "RegionType", regionType);
    GetJsonValue(reader, "Region", regionsList);
    GetJsonValue(reader, "Type", type);
}

void DetectArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "IPCID", iPCID);
    AddJsonValue(writer, "RegionType", regionType);
    AddJsonValue(writer, "Region", regionsList);
    AddJsonValue(writer, "Type", type);
}


SourceArgs::SourceArgs() {
    frameRate = 0;
};

SourceArgs::~SourceArgs() = default;

SourceArgs::SourceArgs(const SourceArgs &sourceArgs) {
    frameRate = sourceArgs.frameRate;
    iPCIDList = sourceArgs.iPCIDList;
    rfidDevId = sourceArgs.rfidDevId;
}

SourceArgs &SourceArgs::operator=(const SourceArgs &sourceArgs) {
    if (this == &sourceArgs)
        return *this;
    frameRate = sourceArgs.frameRate;
    iPCIDList = sourceArgs.iPCIDList;
    rfidDevId = sourceArgs.rfidDevId;
    return *this;
}

void SourceArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "FrameRate", frameRate);
    GetJsonValue(reader, "IPCIDs", iPCIDList);
    GetJsonValue(reader, "RfidDevID", rfidDevId);
}

void SourceArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "FrameRate", frameRate);
    AddJsonValue(writer, "IPCIDs", iPCIDList);
    AddJsonValue(writer, "RfidDevID", rfidDevId);
}


ChooseArgs::ChooseArgs() {
    score = 0;
    intervalSeconds = 0;
    alarmSwitch = false;
};

ChooseArgs::~ChooseArgs() = default;

ChooseArgs::ChooseArgs(const ChooseArgs &chooseArgs) {
    score = chooseArgs.score;
    intervalSeconds = chooseArgs.intervalSeconds;
    alarmSwitch = chooseArgs.alarmSwitch;
}

ChooseArgs &ChooseArgs::operator=(const ChooseArgs &chooseArgs) {
    if (this == &chooseArgs)
        return *this;
    score = chooseArgs.score;
    intervalSeconds = chooseArgs.intervalSeconds;
    alarmSwitch = chooseArgs.alarmSwitch;
    return *this;
}

void ChooseArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Score", score);
    GetJsonValue(reader, "IntervalSeconds", intervalSeconds);
    GetJsonValue(reader, "AlarmSwitch", alarmSwitch);
}

void ChooseArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Score", score);
    AddJsonValue(writer, "IntervalSeconds", intervalSeconds);
    AddJsonValue(writer, "AlarmSwitch", alarmSwitch);
}

VehicleChooseArgs::VehicleChooseArgs() {
    pCount = 15;
    maxWaite = 10;
    minLicenseScore = 0.9;
    minCarScore = 0.3;
    areaRatio = 0.6;
    score = 0.6;
    intervalSeconds = 10;
    alarmSwitch = false;
};

VehicleChooseArgs::~VehicleChooseArgs() = default;

VehicleChooseArgs::VehicleChooseArgs(const VehicleChooseArgs &chooseArgs) {
    pCount = chooseArgs.pCount;
    maxWaite = chooseArgs.maxWaite;
    minLicenseScore = chooseArgs.minLicenseScore;
    minCarScore = chooseArgs.minCarScore;
    areaRatio = chooseArgs.areaRatio;
    score = chooseArgs.score;
    intervalSeconds = chooseArgs.intervalSeconds;
    alarmSwitch = chooseArgs.alarmSwitch;
}

VehicleChooseArgs &VehicleChooseArgs::operator=(const VehicleChooseArgs &chooseArgs) {
    if (this == &chooseArgs)
        return *this;
    pCount = chooseArgs.pCount;
    maxWaite = chooseArgs.maxWaite;
    minLicenseScore = chooseArgs.minLicenseScore;
    minCarScore = chooseArgs.minCarScore;
    areaRatio = chooseArgs.areaRatio;
    score = chooseArgs.score;
    intervalSeconds = chooseArgs.intervalSeconds;
    alarmSwitch = chooseArgs.alarmSwitch;
    return *this;
}

void VehicleChooseArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "PCount", pCount);
    GetJsonValue(reader, "MaxWaite", maxWaite);
    GetJsonValue(reader, "MinLicenseScore", minLicenseScore);
    GetJsonValue(reader, "MinCarScore", minCarScore);
    GetJsonValue(reader, "AreaRatio", areaRatio);
    GetJsonValue(reader, "Score", score);
    GetJsonValue(reader, "IntervalSeconds", intervalSeconds);
    GetJsonValue(reader, "AlarmSwitch", alarmSwitch);
}

void VehicleChooseArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "PCount", pCount);
    AddJsonValue(writer, "MaxWaite", maxWaite);
    AddJsonValue(writer, "MinLicenseScore", minLicenseScore);
    AddJsonValue(writer, "MinCarScore", minCarScore);
    AddJsonValue(writer, "AreaRatio", areaRatio);
    AddJsonValue(writer, "Score", score);
    AddJsonValue(writer, "IntervalSeconds", intervalSeconds);
    AddJsonValue(writer, "AlarmSwitch", alarmSwitch);
}

EngineArgs::EngineArgs() = default;

EngineArgs::~EngineArgs() = default;

EngineArgs::EngineArgs(const EngineArgs &engineArgs) {
    chooseArgs = engineArgs.chooseArgs;
    algorithmType = engineArgs.algorithmType;
    detectArgsList = engineArgs.detectArgsList;
}

EngineArgs &EngineArgs::operator=(const EngineArgs &engineArgs) {
    if (this == &engineArgs)
        return *this;
    chooseArgs = engineArgs.chooseArgs;
    algorithmType = engineArgs.algorithmType;
    detectArgsList = engineArgs.detectArgsList;
    return *this;
}

void EngineArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "AlgorithmType", algorithmType);
    GetJsonValue(reader, "DetectArgs", detectArgsList);
    if (algorithmType == "VehicleDetect") {
        VehicleChooseArgs Tmp;
        GetJsonValue(reader, "ChooseArgs", Tmp);
        chooseArgs = Tmp;
    } else {
        ChooseArgs Tmp;
        GetJsonValue(reader, "ChooseArgs", Tmp);
        chooseArgs = Tmp;
    }
}

void EngineArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "AlgorithmType", algorithmType);
    AddJsonValue(writer, "DetectArgs", detectArgsList);
    if (algorithmType == "VehicleDetect" || algorithmType == "CarAlarm") {
        auto Tmp = any_cast<VehicleChooseArgs>(chooseArgs);
        AddJsonValue(writer, "ChooseArgs", Tmp);
    } else {
        auto Tmp = any_cast<ChooseArgs>(chooseArgs);
        AddJsonValue(writer, "ChooseArgs", Tmp);
    }
}

TransmissionArgs::TransmissionArgs() {
    isUpLoad = true;
    isUpLoadAll = true;
};

TransmissionArgs::~TransmissionArgs() = default;

TransmissionArgs::TransmissionArgs(const TransmissionArgs &transmissionArgs) {
    reportUrl = transmissionArgs.reportUrl;
    id = transmissionArgs.id;
    name = transmissionArgs.name;
    isUpLoad = transmissionArgs.isUpLoad;
    isUpLoadAll = transmissionArgs.isUpLoadAll;
}

TransmissionArgs &TransmissionArgs::operator=(const TransmissionArgs &transmissionArgs) {
    if (this == &transmissionArgs)
        return *this;
    reportUrl = transmissionArgs.reportUrl;
    id = transmissionArgs.id;
    name = transmissionArgs.name;
    isUpLoad = transmissionArgs.isUpLoad;
    isUpLoadAll = transmissionArgs.isUpLoadAll;
    return *this;
}

void TransmissionArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "ReportUrl", reportUrl);
    GetJsonValue(reader, "ID", id);
    GetJsonValue(reader, "Name", name);
    GetJsonValue(reader, "IsUpLoad", isUpLoad);
    GetJsonValue(reader, "IsUpLoadAll", isUpLoadAll);
}

void TransmissionArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "ReportUrl", reportUrl);
    AddJsonValue(writer, "ID", id);
    AddJsonValue(writer, "Name", name);
    AddJsonValue(writer, "IsUpLoad", isUpLoad);
    AddJsonValue(writer, "IsUpLoadAll", isUpLoadAll);
}

BusinessArgs::BusinessArgs() = default;

BusinessArgs::~BusinessArgs() = default;

BusinessArgs::BusinessArgs(const BusinessArgs &businessArgs) {
    id = businessArgs.id;
    name = businessArgs.name;
    sourceArgs = businessArgs.sourceArgs;
    engineArgs = businessArgs.engineArgs;
    transmissionArgsList = businessArgs.transmissionArgsList;
}

BusinessArgs &BusinessArgs::operator=(const BusinessArgs &businessArgs) {
    if (this == &businessArgs)
        return *this;
    id = businessArgs.id;
    name = businessArgs.name;
    sourceArgs = businessArgs.sourceArgs;
    engineArgs = businessArgs.engineArgs;
    transmissionArgsList = businessArgs.transmissionArgsList;
    return *this;
}

void BusinessArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "ID", id);
    GetJsonValue(reader, "Name", name);
    GetJsonValue(reader, "SourceArgs", sourceArgs);
    GetJsonValue(reader, "EngineArgs", engineArgs);
    GetJsonValue(reader, "TransmissionArgs", transmissionArgsList);
}

void BusinessArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "ID", id);
    AddJsonValue(writer, "Name", name);
    AddJsonValue(writer, "SourceArgs", sourceArgs);
    AddJsonValue(writer, "EngineArgs", engineArgs);
    AddJsonValue(writer, "TransmissionArgs", transmissionArgsList);
}

AuthArgs::AuthArgs() = default;

AuthArgs::~AuthArgs() = default;

AuthArgs::AuthArgs(const AuthArgs &authArgs) {
    sn = authArgs.sn;
    key = authArgs.key;
}

AuthArgs &AuthArgs::operator=(const AuthArgs &authArgs) {
    if (this == &authArgs)
        return *this;
    sn = authArgs.sn;
    key = authArgs.key;
    return *this;
}

void AuthArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Sn", sn);
    GetJsonValue(reader, "Key", key);
}

void AuthArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Sn", sn);
    AddJsonValue(writer, "Key", key);
}

DeviceArgs::DeviceArgs() = default;

DeviceArgs::~DeviceArgs() = default;

DeviceArgs::DeviceArgs(const DeviceArgs &deviceArgs) {
    businessList = deviceArgs.businessList;
    engineList = deviceArgs.engineList;
    iPCList = deviceArgs.iPCList;
    authArgs = deviceArgs.authArgs;
    rfidDevList = deviceArgs.rfidDevList;
}

DeviceArgs &DeviceArgs::operator=(const DeviceArgs &deviceArgs) {
    if (this == &deviceArgs)
        return *this;
    businessList = deviceArgs.businessList;
    engineList = deviceArgs.engineList;
    iPCList = deviceArgs.iPCList;
    authArgs = deviceArgs.authArgs;
    rfidDevList = deviceArgs.rfidDevList;
    return *this;
}

void DeviceArgs::DecodeJson(cJSON *reader) {
    GetJsonValue(reader, "Businesses", businessList);
    GetJsonValue(reader, "Engines", engineList);
    GetJsonValue(reader, "IPCs", iPCList);
    GetJsonValue(reader, "AuthArgs", authArgs);
    GetJsonValue(reader, "RfidDevs", rfidDevList);
}

void DeviceArgs::EncodeJson(cJSON *writer) {
    AddJsonValue(writer, "Businesses", businessList);
    AddJsonValue(writer, "Engines", engineList);
    AddJsonValue(writer, "IPCs", iPCList);
    AddJsonValue(writer, "AuthArgs", authArgs);
    AddJsonValue(writer, "RfidDevs", rfidDevList);
}

void Licenses::DecodeJson(cJSON *Reader) {
    GetJsonValue(Reader,"licenses",data);
}

void Licenses::EncodeJson(cJSON *Writer) {
    AddJsonValue(Writer,"licenses",data);
}