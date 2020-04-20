#include <iostream>
#include "Config.h"



int main() {
    string Json = "{\n"
                  "  \"IPCs\": [\n"
                  "    {\n"
                  "      \"ID\": \"8\",\n"
                  "      \"Source\": \"rtsp://admin:pengye2019@192.168.6.25:554/Streaming/Channels/101/\",\n"
                  "      \"Usr\": \"admin\",\n"
                  "      \"Pwd\": \"\",\n"
                  "      \"IP\": \"192.168.6.25\",\n"
                  "      \"Port\": 554,\n"
                  "      \"Channel\": 101,\n"
                  "      \"Mode\": 0,\n"
                  "      \"Img\": \"/images/57d7f789-9051-4bb8-b4e2-86bab3d83a4e.jpg\",\n"
                  "      \"Name\": \"46456456456\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"ID\": \"1\",\n"
                  "      \"Source\": \"rtsp://admin:pengye2019@192.168.6.20:554/Streaming/Channels/101/\",\n"
                  "      \"Usr\": \"admin\",\n"
                  "      \"Pwd\": \"\",\n"
                  "      \"IP\": \"192.168.6.20\",\n"
                  "      \"Port\": 554,\n"
                  "      \"Channel\": 101,\n"
                  "      \"Mode\": 0,\n"
                  "      \"Img\": \"/images/6e79bdcf-95de-4abf-bb28-d8b797e21ffd.jpg\",\n"
                  "      \"Name\": \"213123213123\"\n"
                  "    }\n"
                  "  ],\n"
                  "  \"Engines\": [\n"
                  "    {\n"
                  "      \"Name\": \"安全帽引擎GPU版本\",\n"
                  "      \"ID\": \"1\",\n"
                  "      \"AlgorithmType\": \"SafeHatGPU\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \" 安全帽引擎CPU版本\",\n"
                  "      \"ID\": \"2\",\n"
                  "      \"AlgorithmType\": \"SafeHatCPU\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"人员进出引擎\",\n"
                  "      \"ID\": \"3\",\n"
                  "      \"AlgorithmType\": \"StrangerIntrusion\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"危险区域检测引擎\",\n"
                  "      \"ID\": \"4\",\n"
                  "      \"AlgorithmType\": \"CrossBorder\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"裸土覆盖引擎\",\n"
                  "      \"ID\": \"5\",\n"
                  "      \"AlgorithmType\": \"BareSoilCoverage\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"车辆识别引擎\",\n"
                  "      \"ID\": \"6\",\n"
                  "      \"AlgorithmType\": \"VehicleDetect\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"基坑识别引擎\",\n"
                  "      \"ID\": \"7\",\n"
                  "      \"AlgorithmType\": \"FoundationPit\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    },\n"
                  "    {\n"
                  "      \"Name\": \"电瓶车识别引擎\",\n"
                  "      \"ID\": \"8\",\n"
                  "      \"AlgorithmType\": \"BatteryCar\",\n"
                  "      \"DefaultArgs\": {}\n"
                  "    }\n"
                  "  ],\n"
                  "  \"Businesses\": [\n"
                  "    {\n"
                  "      \"SourceArgs\": {\n"
                  "        \"FrameRate\": 2,\n"
                  "        \"IPCIDs\": [\n"
                  "          \"1\"\n"
                  "        ]\n"
                  "      },\n"
                  "      \"EngineArgs\": {\n"
                  "        \"_uuid\": \"345fb829-94e3-557e-1f35-132e82c2e948\",\n"
                  "        \"_isShow\": true,\n"
                  "        \"AlgorithmType\": \"SafeHatCPU\",\n"
                  "        \"DetectArgs\": [\n"
                  "          {\n"
                  "            \"_uuid\": \"7d032cd4-8f39-d1ff-2c36-8e196bf9b02e\",\n"
                  "            \"_isShow\": true,\n"
                  "            \"MaxID\": 0,\n"
                  "            \"_Items\": [],\n"
                  "            \"IPCID\": \"\",\n"
                  "            \"Region\": [],\n"
                  "            \"RegionType\": \"\",\n"
                  "            \"Type\": 1\n"
                  "          }\n"
                  "        ],\n"
                  "        \"ChooseArgs\": {\n"
                  "          \"_uuid\": \"9337fc4e-a811-dfe5-1597-2c931b8cd384\",\n"
                  "          \"_isShow\": true,\n"
                  "          \"Score\": 0.6,\n"
                  "          \"IntervalSeconds\": 20,\n"
                  "          \"MinCarScore\": 0,\n"
                  "          \"AreaRatio\": 0,\n"
                  "          \"MinLicenseScore\": 0,\n"
                  "          \"PCount\": 0,\n"
                  "          \"AlarmSwitch\": false\n"
                  "        }\n"
                  "      },\n"
                  "      \"TransmissionArgs\": [\n"
                  "        {\n"
                  "          \"ID\": \"\",\n"
                  "          \"Name\": \"\",\n"
                  "          \"ReportUrl\": \"http://192.0.0.14:6953/Service/RecognitionDataMgeSvr.assx/UploadRecognitionData\",\n"
                  "          \"Key\": \"PengeSoft\"\n"
                  "        }\n"
                  "      ],\n"
                  "      \"Name\": \"安全帽识别业务2\",\n"
                  "      \"ID\": \"py002\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"SourceArgs\": {\n"
                  "        \"FrameRate\": 10,\n"
                  "        \"IPCIDs\": [\n"
                  "          \"8\"\n"
                  "        ]\n"
                  "      },\n"
                  "      \"EngineArgs\": {\n"
                  "        \"_uuid\": \"bb6ed649-0883-f552-21a6-3f6491020081\",\n"
                  "        \"_isShow\": true,\n"
                  "        \"AlgorithmType\": \"StrangerIntrusion\",\n"
                  "        \"DetectArgs\": [],\n"
                  "        \"ChooseArgs\": {\n"
                  "          \"_uuid\": \"f3b419bf-1b33-d668-54e1-ea80bd5cad2b\",\n"
                  "          \"_isShow\": true,\n"
                  "          \"Score\": 0.6,\n"
                  "          \"IntervalSeconds\": 20,\n"
                  "          \"MinCarScore\": 0,\n"
                  "          \"AreaRatio\": 0,\n"
                  "          \"MinLicenseScore\": 0,\n"
                  "          \"PCount\": 0,\n"
                  "          \"AlarmSwitch\": false\n"
                  "        }\n"
                  "      },\n"
                  "      \"TransmissionArgs\": [\n"
                  "        {\n"
                  "          \"ID\": \"\",\n"
                  "          \"Name\": \"\",\n"
                  "          \"ReportUrl\": \"http://192.0.0.14:6953/Service/RecognitionDataMgeSvr.assx/UploadRecognitionData\",\n"
                  "          \"Key\": \"PengeSoft\"\n"
                  "        }\n"
                  "      ],\n"
                  "      \"Name\": \"陌生人人员闯入\",\n"
                  "      \"ID\": \"py004\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"SourceArgs\": {\n"
                  "        \"FrameRate\": 5,\n"
                  "        \"IPCIDs\": [\n"
                  "          \"8\"\n"
                  "        ]\n"
                  "      },\n"
                  "      \"EngineArgs\": {\n"
                  "        \"_uuid\": \"a7f3bfde-4d5c-9123-ba92-944236564da4\",\n"
                  "        \"_isShow\": true,\n"
                  "        \"AlgorithmType\": \"CrossBorder\",\n"
                  "        \"DetectArgs\": [\n"
                  "          {\n"
                  "            \"_uuid\": \"fa8b8780-c774-e463-860a-12e3afd80c90\",\n"
                  "            \"_isShow\": true,\n"
                  "            \"MaxID\": 0,\n"
                  "            \"_Items\": [],\n"
                  "            \"IPCID\": \"8\",\n"
                  "            \"Region\": [\n"
                  "              {\n"
                  "                \"_uuid\": \"16f40a2b-3f12-64be-9e8d-551cfe93ff24\",\n"
                  "                \"_isShow\": true,\n"
                  "                \"Points\": [\n"
                  "                  {\n"
                  "                    \"_uuid\": \"bf49c65a-125a-919d-1f8b-168497e3fa2f\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.2571785268414482,\n"
                  "                    \"Y\": 0.30284552845528456\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"d8ac9537-312a-d43e-a687-73dbd595a361\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.27091136079900124,\n"
                  "                    \"Y\": 0.7723577235772358\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"0d625125-7ef1-e374-e403-68a60a15e6eb\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.6054931335830213,\n"
                  "                    \"Y\": 0.7398373983739838\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"660e8728-b1a2-1630-88a5-cd29b219339e\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.5705368289637952,\n"
                  "                    \"Y\": 0.21747967479674796\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"33ff32b7-15e5-fb5c-66bb-511455f50aa0\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.2571785268414482,\n"
                  "                    \"Y\": 0.30284552845528456\n"
                  "                  }\n"
                  "                ]\n"
                  "              }\n"
                  "            ],\n"
                  "            \"RegionType\": \"\",\n"
                  "            \"Type\": 1\n"
                  "          }\n"
                  "        ],\n"
                  "        \"ChooseArgs\": {\n"
                  "          \"_uuid\": \"6c97ed3e-b6b8-cd97-0287-efe951e56978\",\n"
                  "          \"_isShow\": true,\n"
                  "          \"Score\": 0.8,\n"
                  "          \"IntervalSeconds\": 10,\n"
                  "          \"MinCarScore\": 0,\n"
                  "          \"AreaRatio\": 0,\n"
                  "          \"MinLicenseScore\": 0,\n"
                  "          \"PCount\": 0,\n"
                  "          \"AlarmSwitch\": true\n"
                  "        }\n"
                  "      },\n"
                  "      \"TransmissionArgs\": [\n"
                  "        {\n"
                  "          \"ID\": \"\",\n"
                  "          \"Name\": \"\",\n"
                  "          \"ReportUrl\": \"http://192.0.0.14:6953/Service/RecognitionDataMgeSvr.assx/UploadRecognitionData\",\n"
                  "          \"Key\": \"PengeSoft\"\n"
                  "        }\n"
                  "      ],\n"
                  "      \"Name\": \"危险区域 检测业务\",\n"
                  "      \"ID\": \"de8be663-b5a1-4e57-a998-c59b96ff3e52\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"SourceArgs\": {\n"
                  "        \"FrameRate\": 2,\n"
                  "        \"IPCIDs\": [\n"
                  "          \"8\"\n"
                  "        ]\n"
                  "      },\n"
                  "      \"EngineArgs\": {\n"
                  "        \"_uuid\": \"996d3ae6-03e2-b6fa-0de0-ed0d68546bf5\",\n"
                  "        \"_isShow\": true,\n"
                  "        \"AlgorithmType\": \"BareSoilCoverage\",\n"
                  "        \"DetectArgs\": [\n"
                  "          {\n"
                  "            \"_uuid\": \"af9046a9-e2c1-2e79-f9aa-f1dfed013335\",\n"
                  "            \"_isShow\": true,\n"
                  "            \"MaxID\": 0,\n"
                  "            \"_Items\": [],\n"
                  "            \"IPCID\": \"8\",\n"
                  "            \"Region\": [\n"
                  "              {\n"
                  "                \"_uuid\": \"140c46d7-08d9-9f8b-cdfc-d12659d8d5e4\",\n"
                  "                \"_isShow\": true,\n"
                  "                \"Points\": [\n"
                  "                  {\n"
                  "                    \"_uuid\": \"4a8a72f5-e1ee-8037-0be6-54a80e6176ff\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.16104868913857678,\n"
                  "                    \"Y\": 0.3434959349593496\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"52f65514-93d4-293a-e9ce-502a14c6bc94\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.5380774032459426,\n"
                  "                    \"Y\": 0.8800813008130082\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"964be18c-1753-66b4-01d5-69845de7a344\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.83645443196005,\n"
                  "                    \"Y\": 0.43902439024390244\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"aaaeafc3-a257-86ea-dffc-8aee5bfef76f\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.5580524344569289,\n"
                  "                    \"Y\": 0.18292682926829268\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"3250911f-898d-e24f-4bb1-5c88638ee491\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.5780274656679151,\n"
                  "                    \"Y\": 0.49796747967479676\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"6da8bf42-36a8-d287-4baf-c2a00449dcf6\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.4469413233458177,\n"
                  "                    \"Y\": 0.18699186991869918\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"2667398b-0c15-8602-c370-88289801dcc2\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.29712858926342073,\n"
                  "                    \"Y\": 0.21951219512195122\n"
                  "                  },\n"
                  "                  {\n"
                  "                    \"_uuid\": \"84a36a81-a547-72bf-e018-2f8f957cec7a\",\n"
                  "                    \"_isShow\": true,\n"
                  "                    \"X\": 0.16104868913857678,\n"
                  "                    \"Y\": 0.3434959349593496\n"
                  "                  }\n"
                  "                ]\n"
                  "              }\n"
                  "            ],\n"
                  "            \"RegionType\": \"\",\n"
                  "            \"Type\": 1\n"
                  "          }\n"
                  "        ],\n"
                  "        \"ChooseArgs\": {\n"
                  "          \"_uuid\": \"9c5dce53-1e7c-61ae-2300-9cd131c167d5\",\n"
                  "          \"_isShow\": true,\n"
                  "          \"Score\": 0.8,\n"
                  "          \"IntervalSeconds\": 10,\n"
                  "          \"MinCarScore\": 0,\n"
                  "          \"AreaRatio\": 0,\n"
                  "          \"MinLicenseScore\": 0,\n"
                  "          \"PCount\": 0,\n"
                  "          \"AlarmSwitch\": true\n"
                  "        }\n"
                  "      },\n"
                  "      \"TransmissionArgs\": [\n"
                  "        {\n"
                  "          \"ID\": \"\",\n"
                  "          \"Name\": \"\",\n"
                  "          \"ReportUrl\": \"http://192.0.0.14:6953/Service/RecognitionDataMgeSvr.assx/UploadRecognitionData\",\n"
                  "          \"Key\": \"PengeSoft\"\n"
                  "        }\n"
                  "      ],\n"
                  "      \"Name\": \"裸土覆 盖检测业务\",\n"
                  "      \"ID\": \"7faf8492-a718-4e87-a421-80a9cb1714dc\"\n"
                  "    },\n"
                  "    {\n"
                  "      \"SourceArgs\": {\n"
                  "        \"FrameRate\": 2,\n"
                  "        \"IPCIDs\": [\n"
                  "          \"8\"\n"
                  "        ]\n"
                  "      },\n"
                  "      \"EngineArgs\": {\n"
                  "        \"_uuid\": \"ce0a28e9-88ee-d9d7-2004-e9d7ec801f8c\",\n"
                  "        \"_isShow\": true,\n"
                  "        \"AlgorithmType\": \"SafeHatCPU\",\n"
                  "        \"DetectArgs\": [\n"
                  "          {\n"
                  "            \"_uuid\": \"459925bc-dbce-eedc-e082-e74e5dfddcb2\",\n"
                  "            \"_isShow\": true,\n"
                  "            \"MaxID\": 0,\n"
                  "            \"_Items\": [],\n"
                  "            \"IPCID\": \"\",\n"
                  "            \"Region\": [],\n"
                  "            \"RegionType\": \"\",\n"
                  "            \"Type\": 1\n"
                  "          }\n"
                  "        ],\n"
                  "        \"ChooseArgs\": {\n"
                  "          \"_uuid\": \"5f229578-2801-0547-21ca-39a16835d164\",\n"
                  "          \"_isShow\": true,\n"
                  "          \"Score\": 0.8,\n"
                  "          \"IntervalSeconds\": 10,\n"
                  "          \"MinCarScore\": 0,\n"
                  "          \"AreaRatio\": 0,\n"
                  "          \"MinLicenseScore\": 0,\n"
                  "          \"PCount\": 0,\n"
                  "          \"AlarmSwitch\": true\n"
                  "        }\n"
                  "      },\n"
                  "      \"TransmissionArgs\": [\n"
                  "        {\n"
                  "          \"ID\": \"\",\n"
                  "          \"Name\": \"\",\n"
                  "          \"ReportUrl\": \"http://192.0.0.14:6953/Service/RecognitionDataMgeSvr.assx/UploadRecognitionData\",\n"
                  "          \"Key\": \"PengeSoft\"\n"
                  "        }\n"
                  "      ],\n"
                  "      \"Name\": \"安全帽CPU检 查业务\",\n"
                  "      \"ID\": \"75adc765-195c-46dd-8143-d7ad7f91137b\"\n"
                  "    }\n"
                  "  ]\n"
                  "}";
    DeviceArgs _DeviceArgs;
    _DeviceArgs.SetJsonText(Json);

    cout<<_DeviceArgs.GetJsonText()<<endl;
    return 0;
}
