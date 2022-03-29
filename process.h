#ifndef PROCESS_H
#define PROCESS_H

struct Process {
  int arrival_time;
  int burst_time;
  int remainingburst;
};

Process process_maker(int arrival_time, int burst_time);

#endif
