#include <iostream>
#include <cassert>
using namespace std;

// Pure functions to check each parameter
bool isTemperatureOk(float temperature) {
  return (temperature >= 0 && temperature <= 45);
}

bool isSocOk(float soc) {
  return (soc >= 20 && soc <= 80);
}

bool isChargeRateOk(float chargeRate) {
  return (chargeRate <= 0.8);
}

// Pure function to determine battery health
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  return isTemperatureOk(temperature) &&
         isSocOk(soc) &&
         isChargeRateOk(chargeRate);
}

// Side-effect function to log errors
void logBatteryStatus(float temperature, float soc, float chargeRate) {
  if (!isTemperatureOk(temperature)) {
    cout << "Temperature out of range!\n";
  }
  if (!isSocOk(soc)) {
    cout << "State of Charge out of range!\n";
  }
  if (!isChargeRateOk(chargeRate)) {
    cout << "Charge Rate out of range!\n";
  }
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);

  // Optional: display detailed messages
  logBatteryStatus(50, 85, 0);
}
