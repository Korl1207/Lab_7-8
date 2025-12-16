#include <iostream>
#include <string>

#include "ProcessList.h"

int main() {
  // Создаем список процессов
  ProcessList pl;
  std::cout << "Создан список процессов" << std::endl;

  PCB* pcb1 = new PCB(1, "First process", nsPCB::PCB::Status::Running, 5);
  PCB* pcb2 = new PCB(2, "Second process", nsPCB::PCB::Status::Running, 14);
  PCB* pcb3 = new PCB(3, "Third process", nsPCB::PCB::Status::Stopped, 4);
  PCB* pcb4 = new PCB(4, "Fourth process", nsPCB::PCB::Status::Waiting, 6);
  PCB* pcb5 = new PCB(5, "Fifth process", nsPCB::PCB::Status::Waiting, 8);

  // Добавляем PCB в список
  pl.insert(pcb1);
  pl.insert(pcb2);
  pl.insert(pcb3);
  pl.insert(pcb4);
  pl.insert(pcb5);
  std::cout << "Добавлено 5 процессов" << std::endl << std::endl;
  pl.printList();

  // Тестирование функции добавления элемента
  if (pl.insert(pcb2)) {
    std::cout << "Удалось добавить существующий процесс" << std::endl;
  } else {
    std::cout << "Не удалось добавить существующий процесс" << std::endl;
  }

  // Тестирование функции удаления элемента
  if (pl.remove(pcb3->processID)) {
    std::cout << "Удалось удалить существующий процесс" << std::endl;
  } else {
    std::cout << "Не удалось удалить существующий процесс" << std::endl;
  }

  if (pl.remove(pcb3->processID)) {
    std::cout << "Удалось удалить несуществующий процесс" << std::endl;
  } else {
    std::cout << "Не удалось удалить несуществующий процесс" << std::endl;
  }
  // Вывод конечного результата
  pl.printList();
}