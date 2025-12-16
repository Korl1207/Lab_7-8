// ProcessList.h
#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"

class ProcessList {
  ListNode* head;  // Указатель на первый элемент списка

 public:
  ProcessList() : head(nullptr) {};  // Конструктор
  ~ProcessList();                    // Деструктор

  bool insert(const PCB* newPCB);  // Добавление элемента
  bool remove(int pid);            // Удаление элемента по ID

  void printList();  // Вывод списка на экран
};

#endif  // PROCESSLIST_H