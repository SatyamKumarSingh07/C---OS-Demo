#include <iostream>

using namespace std;

struct MemoryPartition {
    int size;
    bool allocated;
};

int main() {

    MemoryPartition memoryPartitions[] = {
        {100},{500},{200},{450},{600}
    };


    int requests[] = {212, 417, 112, 426};

    int totalMemory = 0;

    cout << "Memory Partition Status:" << endl;
    

    for (int i = 0; i < sizeof(requests) / sizeof(requests[0]); i++) {
        int requestedSize = requests[i];
        bool allocated = false;

        for (int j = 0; j < sizeof(memoryPartitions) / sizeof(memoryPartitions[0]); j++) {
            if (!memoryPartitions[j].allocated && memoryPartitions[j].size >= requestedSize) {
                memoryPartitions[j].allocated = true;
                allocated = true;
                totalMemory += memoryPartitions[j].size;
                cout << "Allocated " << requestedSize << " KB to request " << (i + 1) << " in partition " << (j + 1) << endl;
                break;
            }
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
