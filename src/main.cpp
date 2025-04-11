#include "CentralHub.h"

int main(){
    std::shared_ptr<CentralHub> hub = std::make_shared<CentralHub>();
    std::shared_ptr<Device> Device1 = LightFactory().createDevice(hub, "Bathroom");
    std::shared_ptr<Device> Device2 = AirConditionerFactory().createDevice(hub, "Bathroom");
    std::shared_ptr<Device> Device3 = ThermostatFactory().createDevice(hub, "Bathroom");
    std::shared_ptr<Device> Device4 = MotionSensorFactory().createDevice(hub, "Bathroom");
    hub ->addDevice(Device1);
    hub ->addDevice(Device2);
    hub ->addDevice(Device3);
    hub ->addDevice(Device4);
    while (true) {
        
        std::time_t now = std::time(nullptr);
        std::tm *local_time = std::localtime(&now);
        
        
        if (local_time->tm_hour == 16 && local_time->tm_min == 5) {
            
            hub -> TurnOnAllLightes();
            std::this_thread::sleep_for(std::chrono::minutes(1));  
        }
        
        
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }


}
