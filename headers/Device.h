#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>
#include "CentralHub.h"
class CentralHub;

class Device{
protected:
    std::string m_name;
    std::shared_ptr<CentralHub> m_mediator;
public:
    Device(std::shared_ptr<CentralHub> hub, const std::string& str) : m_mediator(hub), m_name(str) {}

    virtual std::string& getname();

   virtual ~Device() = default;
};

class Light : public Device {
    bool m_lighton;
public:
    Light(std::shared_ptr<CentralHub> hub, const std::string& str) : Device(hub, str), m_lighton(false) {}
    void TurnOn();
    void TurnOff();
};

class AirConditioner : public Device {
    bool m_ison;
public:
    AirConditioner(std::shared_ptr<CentralHub> hub, const std::string& str) : Device(hub, str), m_ison(false) {}
    void toHeat();
    void toCool();
    void TurnOff();
};

class Thermostat : public Device {
   int m_Temperature;
public:
   Thermostat(std::shared_ptr<CentralHub> hub, const std::string& str) : Device(hub, str), m_Temperature(0) {}
   int GetTemperatureCelsius();
   int GetTemperatureFahrenheit();
   void SetTemperature(int temp);
};

class DoorLock : public Device {
    bool m_isopen;
public:
    DoorLock(std::shared_ptr<CentralHub> hub, const std::string& str) : Device(hub, str), m_isopen(false) {}
    void OpenDoor();
    void CloseDoor();
};

class MotionSensor : public Device {
public:
    MotionSensor(std::shared_ptr<CentralHub> hub, const std::string& str) : Device(hub, str) {}
    void MotionNoticed();
};

class DeviceFactory {
public:
    virtual std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) = 0;
    virtual ~DeviceFactory() = default;
};

class LightFactory : public DeviceFactory {
public:
    std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) override {
        return std::make_shared<Light>(hub, str);
    } 
};

class DoorLockFactory : public DeviceFactory {
public:
    std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) override {
        return std::make_shared<DoorLock>(hub, str);
    } 
};

class ThermostatFactory : public DeviceFactory {
public:
    std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) override {
        return std::make_shared<Thermostat>(hub, str);
    } 
};

class MotionSensorFactory : public DeviceFactory {
public:
    std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) override {
        return std::make_shared<MotionSensor>(hub, str);
    } 
};

class AirConditionerFactory : public DeviceFactory {
public:
    std::shared_ptr<Device> createDevice(std::shared_ptr<CentralHub> hub, const std::string& str) override {
        return std::make_shared<AirConditioner>(hub, str);
    } 
};
#endif
