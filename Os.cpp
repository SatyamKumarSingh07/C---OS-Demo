#include <iostream>
#include <vector>
#include<climits>
#include <algorithm>
using namespace std;

// Define a structure for a process
struct Process {
    int id;           // Process ID
    int arrivalTime;  // Arrival Time
    int burstTime;    // Burst Time
    int priority;     // Priority
    int waitingTime;  // Waiting Time
    int turnaroundTime; // Turnaround Time
};

// Function to calculate Priority Scheduling order
vector<Process> priorityScheduling(vector<Process>& processes) {
    vector<Process> schedule;
    int currentTime = 0;

    while (!processes.empty()) {
        // Find the process with the highest priority and is ready to execute
        int highestPriority = INT_MAX;
        int selectedProcessIdx = -1;

        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                selectedProcessIdx = i;
            }
        }

        if (selectedProcessIdx == -1) {
            currentTime++;
        } else {
            Process selectedProcess = processes[selectedProcessIdx];
            processes.erase(processes.begin() + selectedProcessIdx);

            // Update waiting and turnaround times
            selectedProcess.waitingTime = currentTime - selectedProcess.arrivalTime;
            selectedProcess.turnaroundTime = selectedProcess.waitingTime + selectedProcess.burstTime;

            // Add the process to the schedule
            schedule.push_back(selectedProcess);
            currentTime += selectedProcess.burstTime;
        }
    }

    return schedule;
}

int main() {
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter Priority for Process " << i + 1 << ": ";
        cin >> processes[i].priority;
    }

    // Perform Priority Scheduling
    vector<Process> schedule = priorityScheduling(processes);

    // Calculate and print the Gantt chart
    cout << "Gantt Chart:" << endl;
    int totalTime = 0;
    for (const Process& p : schedule) {
        cout << "| P" << p.id << " ";
        totalTime += p.burstTime;
    }
    cout << "|" << endl;

    // Calculate and print average waiting time and average turnaround time
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;
    for (const Process& p : schedule) {
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    double avgWaitingTime = totalWaitingTime / n;
    double avgTurnaroundTime = totalTurnaroundTime / n;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}
