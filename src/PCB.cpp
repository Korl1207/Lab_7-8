#include "PCB.h"

#include <iostream>

namespace nsPCB {

PCB::PCB()
    : processID(0),
      processName(""),
      processStatus(Status::Waiting),
      commandCounter(0) {
  for (int i = 0; i < CPUREGISTERSIZE; ++i) cpuRegisters[i] = 0;
}

PCB::PCB(int processID, std::string& processName, Status processStatus,
         int commandCounter)
    : processID(processID),
      processName(processName),
      processStatus(processStatus),
      commandCounter(commandCounter) {
  for (int i = 0; i < CPUREGISTERSIZE; ++i) cpuRegisters[i] = 0;
}

void PCB::print() const {
  std::cout << "=== PCB ===" << std::endl;
  std::cout << "ID процесса: " << processID << std::endl;
  std::cout << "Название процесса: " << processName << std::endl;
  std::cout << "Статус процесса: "
            << ((processStatus == Status::Running)
                    ? "Running..."
                    : ((processStatus == Status::Stopped) ? "Stopped"
                                                          : "Waiting..."))
            << std::endl;
  std::cout << "Следующая исполняемая команда: " << commandCounter << std::endl;
  std::cout << "Регистры: " << std::endl;
  for (int i = 0; i < CPUREGISTERSIZE; ++i) std::cout << cpuRegisters[i] << " ";
  std::cout << std::endl << std::endl;
}

}  // namespace nsPCB