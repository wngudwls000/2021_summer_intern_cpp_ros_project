#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid);
  int Pid() const;                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  void CpuUtilization(long idle, long active);
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(const Process& a) const;  // TODO: See src/process.cpp
  bool operator>(const Process& a) const;

  // TODO: Declare any necessary private members
 private:
  int pid_;
  float utilization = 0;
  long prev_system, prev_active = 0;
};

#endif