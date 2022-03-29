#include "round_robin.h"
#include <iostream>
#include <queue>

void round_robin(std::list<Process> processes, int quantum) {
  double finish_time_avarage = 0.0, wait_time_avarage = 0.0, response_time_avarage = 0.0;
  int finish_time = 0, wait_time = 0, response_time = 0, i = quantum;
  int quantity = processes.size();

  std::list<Process>::iterator it = processes.begin();
  Process running;
  std::queue<Process> processes;
  bool process_running = false;
  for (int current_time = 0; true; current_time++) {

    while (it != processes.end() && current_time == (*it).arrival_time) {
      processes.push_back((*it));
      it++;
    }

    if (!process_running) {
      if (!processes.empty()) {
        running = processes.front();
        processes.pop_front();
        process_running = true;
        i = quantum;
        if (running.duration == running.remaining_burst) {
          response_time = current_time - running.arrival_time;
        }
      }
    } else {
      while (i > 0) {
        running.remaining_burst--;
        i--;
        if (running.remaining_burst == 0) {
          finish_time = wait_time + running.duration;
          process_running = false;
          finish_time_avarage += finish_time;
          response_time_avarage += response_time;
          wait_time_avarage += wait_time;
          break;
        }
        continue;
      }
    }
  }

  finishTimeAverage /= qtdProcess;
  responseTimeAverage /= qtdProcess;
  waitTimeAverage /= qtdProcess;

  std::cout << std::setprecision(1) << std::fixed;

  std::cout << "RR " << finishTimeAverage << " " << responseTimeAverage << " " << waitTimeAverage << std::endl;
}
