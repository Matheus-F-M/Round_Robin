#include <stdio.h>

struct process {
	int arrival_time;
	int burst_time;
};

void main()
{
	int quantity = 0, quantum = 0, remaining = 0, turnaround_time = 0, check_1 = 0, check_2 = 0, i;
	float avarage_active_time = 0.0, avarage_response_time = 0.0, avarage_wait_time = 0.0;

	scanf("%d %d", &quantity, &quantum);

	struct process process_list[quantity];
	int burst_list[quantity];

	for (i = 0; i < quantity; i++) {
		scanf("%d %d", &process_list[i].arrival_time, &process_list[i].burst_time);
		burst_list[i] = process_list[i].burst_time;
	}
	remaining = quantity;

	for (i = 0, turnaround_time = 0; remaining != 0;) {
		if (burst_list[i] > 0 && burst_list[i] <= quantum) {
			turnaround_time += burst_list[i];
			burst_list[i] = 0;
			check_2 = 1;
		}
		else if (burst_list[i] > 0) {
			burst_list[i] -= quantum;
			turnaround_time += quantum;

			if (check_1 == 1) {
				avarage_response_time++;
				check_1 = 0;
			}
		}
		if (check_2 == 1 && burst_list[i] == 0) {
			remaining--;
			avarage_wait_time += (turnaround_time - process_list[i].burst_time - process_list[i].arrival_time);
			avarage_active_time += (turnaround_time - process_list[i].arrival_time);
			check_2 = 0;
		}
		if (i == quantity - 1) {
			i = 0;
			check_1 = 1;
		}
		else if (process_list[i+1].arrival_time <= turnaround_time) {
			i++;
		}
		else {
			i = 0;
		}
	}
	avarage_active_time /= quantity;
	avarage_response_time /= quantity;
	avarage_wait_time /= quantity;
	avarage_active_time += 1;
	avarage_wait_time += 1;
	printf("RR %.1f %.1f %.1f\n", avarage_active_time , avarage_response_time, avarage_wait_time);
}
