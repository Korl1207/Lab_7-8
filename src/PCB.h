// PCB.h
#ifndef PCB_H
#define PCB_H

#include <string>

namespace nsPCB {

const int CPUREGISTERSIZE = 16;
struct PCB {
  enum Status { Running, Waiting, Stopped };

  int processID;
  std::string processName;
  Status processStatus;
  int commandCounter;
  int cpuRegisters[CPUREGISTERSIZE];

  PCB();
  PCB(int processID, std::string& processName, Status processStatus,
      int commandCounter);

  void print() const;
};
}  // namespace nsPCB

#endif  // PCB_H