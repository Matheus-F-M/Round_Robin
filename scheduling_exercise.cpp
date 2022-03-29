#include<iostream>
using namespace std;

void get_waiting_time(int processes[], int n,int burst_time[], int wait_time[], int quantum)
{
    int remaining_burst_time[n];
    for (int i = 0 ; i < n ; i++)
        remaining_burst_time[i] = burst_time[i];
 
    int current_time = 0;
    while (1)
    {
        bool complete = true;
        for (int i = 0 ; i < n; i++)
        {
            if (remaining_burst_time[i] > 0)
            {
                complete = false;
                if (remaining_burst_time[i] > quantum)
                {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else
                {
                    current_time = current_time + remaining_burst_time[i];
                    wait_time[i] = current_time - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (complete == true) {
            break;
        }
    }
}
void get_turn_around_time(int processes[], int n,int burst_time[], int wait_time[], int turn_around_time[])
{
    for (int i = 0; i < n ; i++) {
        turn_around_time[i] = burst_time[i] + wait_time[i];
    }
}
void get_avarage(int processes[], int n, int burst_time[],int quantum)
{
    int wait_time[n], turn_around_time[n], total_wait_time = 0, total_turn_around_time = 0;
    get_waiting_time(processes, n, burst_time, wait_time, quantum);
    get_turn_around_time(processes, n, burst_time, wait_time, turn_around_time);
    for (int i=0; i<n; i++)
    {
        total_wait_time = total_wait_time + wait_time[i];
        total_turn_around_time = total_turn_around_time + turn_around_time[i];
    }
 
    cout << (float)total_wait_time / (float)n << " " << (float)total_turn_around_time / (float)n;
}

int main()
{
    int quantity = 0;
    int quantum = 0;
    int arrival_time = 0;
    int burst_time = 0;

    cin >> quantity >> quantum;

    int processes[quantity];
    int processes_bt[quantity];
    int n = sizeof(processes) / sizeof (processes[0]);
 
    for(int i = 0; i < quantity; i++)
    {
        cin >> arrival_time >> burst_time;
        processes[i] = arrival_time;
        processes_bt[i] = burst_time;
    }
    get_avarage(processes, n, processes_bt, quantum);
    return 0;
}
