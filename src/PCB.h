// PCB.h
#ifndef PCB_H
#define PCB_H

#include <string>

namespace nsPCB {

const int CPUREGISTERSIZE = 16;
struct PCB {
  enum Status {
    Running,
    Waiting,
    Stopped
  };  // Перечисление для статуса процесса

  int processID;
  std::string processName;
  Status processStatus;
  int commandCounter;
  int cpuRegisters[CPUREGISTERSIZE];

  // Конструкторы структуры
  PCB();
  PCB(const PCB* copyPCB);
  PCB(int processID, std::string processName, Status processStatus,
      int commandCounter);

  void print() const;  // Вывод всех значений в функции
};
}  // namespace nsPCB

#endif  // PCB_H