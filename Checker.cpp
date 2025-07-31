#include <iostream>
#include <cassert>
#include <string>
using namespace std;

struct BatteryParam {
  string name;
  float value;
  float min;
  float max;
};

bool isInRange(float value, float min, float max) {
  return value >= min && value <= max;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  return isInRange(temperature, 0, 45) &&
         isInRange(soc, 20, 80) &&
         isInRange(chargeRate, 0, 0.8);
}

void logBatteryStatus(float temperature, float soc, float chargeRate) {
  BatteryParam params[] = {
    {"Temperature", temperature, 0, 45},
    {"State of Charge", soc, 20, 80},
    {"Charge Rate", chargeRate, 0, 0.8}
  };

  for (const auto& param : params) {
    if (!isInRange(param.value, param.min, param.max)) {
      cout << param.name << " out of range!\n";
    }
  }
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);

  logBatteryStatus(50, 85, 0); // Will print out-of-range messages
}
