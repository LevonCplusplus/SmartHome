#include "Device.h"
class CentralHub;
    
std::string& Device:: getname(){
        return m_name;
}

void Light:: TurnOn()
{  
    m_lighton = true;
    std:: cout << "Light is turned on in " << m_name << std::endl;
}
void Light:: TurnOff(){
    m_lighton = false;
    std:: cout << "Light in " << m_name <<" is turnned off!" << std::endl;
}
    


void AirConditioner:: toHeat()
{
    m_ison = true;
    std::cout << "Temperature is 18 Air Conditioner is turned on ..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << "Temperature is 24 Air conditioner is turned off! " << std::endl;
    TurnOff();
}
void AirConditioner:: toCool()
{
    m_ison = true;
    std::cout << "Temperature is 30 Air Conditioner is on ..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << "Temperature is 24 Air conditioner is turned off! " << std::endl;
    TurnOff();
}
void AirConditioner:: TurnOff()
{
    m_ison = false;
}


int Thermostat:: GetTemperatureCelsius(){
    return m_Temperature;
}
int Thermostat:: GetTemperatureFahrenheit(){
    return (m_Temperature * 9/5) + 32;
}
void Thermostat:: SetTemperature(int temp){
    m_Temperature = temp;
    m_mediator -> ReceiveNotification("Thermostat",this -> m_name);
}


void DoorLock:: OpenDoor(){
    m_isopen = true;
}
void DoorLock::  CloseDoor(){
    m_isopen = false;
}

void MotionSensor:: MotionNoticed(){
    m_mediator -> ReceiveNotification("Motion Noticed",this -> m_name);
}    

