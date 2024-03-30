#include <iostream>
#include <climits>

using namespace std;

struct MemoryPartition {
    int size;
    bool allocated;
};

int main() {
    
    MemoryPartition memoryPartitions[] = {
        {100, false},
        {500, false},
        {200, false},
        {450, false},
        {600, false}
    };
    int requests[] = {212, 417, 112, 426};

    int totalMemory = 0;

   
    for (int i = 0; i < sizeof(requests) / sizeof(requests[0]); i++) {
        int requestedSize = requests[i];
        bool allocated = false;
        int worstFitPartitionIndex = -1;
        int worstFitSize = -1;

        for (int j = 0; j < sizeof(memoryPartitions) / sizeof(memoryPartitions[0]); j++) {
            if (!memoryPartitions[j].allocated && memoryPartitions[j].size >= requestedSize) {
                if (memoryPartitions[j].size > worstFitSize) {
                    worstFitPartitionIndex = j;
                    worstFitSize = memoryPartitions[j].size;
                }
            }
        }

        if (worstFitPartitionIndex != -1) {
            memoryPartitions[worstFitPartitionIndex].allocated = true;
            allocated = true;
            totalMemory += memoryPartitions[worstFitPartitionIndex].size;
            cout << "Allocated " << requestedSize << " KB to request " << (i + 1) << " in partition " << (worstFitPartitionIndex + 1) << endl;
        }

        if (!allocated) {
            cout << "Request " << (i + 1) << " of " << requestedSize << " KB cannot be allocated." << endl;
        }
    }


    cout << "Memory Partition Status:" << endl;
    for (int i = 0; i < sizeof(memoryPartitions) / sizeof(memoryPartitions[0]); i++) {
        cout << "Partition " << (i + 1) << ": " << (memoryPartitions[i].allocated ? "Allocated" : "Free") << " - Size: " << memoryPartitions[i].size << " KB" << endl;
    }

 
    cout << "Total allocated memory: " << totalMemory << " KB" << endl;

    return 0;
}
