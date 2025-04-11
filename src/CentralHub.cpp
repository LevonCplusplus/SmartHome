#include "CentralHub.h"
class Device;

    void CentralHub::addDevice(std::shared_ptr<Device>  device)
    {
        m_devices.push_back(device);   
    }
    void CentralHub::removeDevice(std::shared_ptr<Device>  device)
    {
        for(int i{};i < m_devices.size(); ++i)
        {
            if(m_devices[i] == device){
                m_devices.erase(m_devices.begin()+i); 
            }
        }
    }
    void CentralHub:: ReceiveNotification(const std::string& notify,const std:: string& name){
        if(notify == "Thermostat")
        {
            for(int i{};i < m_devices.size(); ++i){
                if(std::dynamic_pointer_cast<Thermostat>(m_devices[i]) && m_devices[i]->getname() == name)
                {
                    std::shared_ptr<Thermostat> thermostat = std::dynamic_pointer_cast<Thermostat>(m_devices[i]);
                    int temp = thermostat -> GetTemperatureCelsius();
                    std::shared_ptr<AirConditioner> conditioner;
                    for(int i{};i < m_devices.size(); ++i){
                        if(std::dynamic_pointer_cast<AirConditioner>(m_devices[i]) && m_devices[i]->getname() == name)
                        {
                            conditioner = std::dynamic_pointer_cast<AirConditioner>(m_devices[i]);
                        }
                    }
                  if(temp > 30){
                    conditioner -> toCool();
                    thermostat -> SetTemperature(24);
                  }else if(temp < 18){
                    conditioner -> toHeat();
                    thermostat -> SetTemperature(24);
                  }


                }
            }

        }
        else if(notify == "Motion  Noticed")
        {
            TurnOnLightes(name);
        }
    }
    void CentralHub:: TurnOnLightes(const std:: string & room){
        for(int i{};i < m_devices.size(); ++i){
            if(std::dynamic_pointer_cast<Light>(m_devices[i]) && m_devices[i]->getname() == room)
            {
                std::shared_ptr<Light> light = std::dynamic_pointer_cast<Light>(m_devices[i]);
                light -> TurnOn();
            }
        }
    }
    void CentralHub:: ToHeatConditioner(const std:: string & room)
    {
        for(int i{};i < m_devices.size(); ++i){
            if(std::dynamic_pointer_cast<AirConditioner>(m_devices[i]) && m_devices[i]->getname() == room)
            {
                std::shared_ptr<AirConditioner> conditioner = std::dynamic_pointer_cast<AirConditioner>(m_devices[i]);
                conditioner -> toHeat();
            }
        }
    }
    void CentralHub:: TurnOffLights(const std::string& name){
        for(int i{};i < m_devices.size(); ++i){
            if(std::dynamic_pointer_cast<Light>(m_devices[i]) && m_devices[i]->getname() == name)
            {
                std::shared_ptr<Light> light =std::dynamic_pointer_cast<Light>(m_devices[i]);
                light -> TurnOff();
            }
        }
    }
    void CentralHub:: TurnOnAllLightes(){
        for(int i{};i < m_devices.size(); ++i){
            if(std::dynamic_pointer_cast<Light>(m_devices[i]))
            {
                std::shared_ptr<Light> light = std::dynamic_pointer_cast<Light>(m_devices[i]);
                light -> TurnOn();
            }
        }
    }
    
