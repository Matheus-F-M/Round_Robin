#include "process.h"
#include "round_robin.h"
#include <iostream>
#include <list>

using namespace std;

int main() {
  int quantity = 0, quantum = 0;
  int arrival_time = 0, burst_time = 0;
  list<Process> processes;
  cin >> quantity >> quantum;
  for (int i = 0; i < quantity; i++) {
    cin >> arrival_time >> burst_time;
    processes.push_back(process_maker(arrival_time, burst_time));
  }

  cout << "Starting RR" << endl;
  round_robin(processes, quantum);
}
