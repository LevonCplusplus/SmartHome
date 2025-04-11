#ifndef CENTRULHUB_H
#define CENTRULHUB_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Device.h"
class Device;

class CentralHub{
    std::vector<std::shared_ptr<Device>> m_devices;
public:
    void addDevice(std::shared_ptr<Device>  device);
    
    void removeDevice(std::shared_ptr<Device>  device);
   
    void ReceiveNotification(const std::string& notify,const std:: string& name);
    void TurnOnLightes(const std:: string & room);
    void ToHeatConditioner(const std:: string & room);
   
    void TurnOffLights(const std::string& name);
    void TurnOnAllLightes();
};
#endif