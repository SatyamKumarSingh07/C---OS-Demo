#include<iostream>
using namespace std;

void allocateMemoryBlock(int p, int memoryblock[], int n) {
    for (int i = 0; i < n; i++) {
        if (memoryblock[i] >= p) {
            memoryblock[i] = memoryblock[i] - p;
            cout << "Space allocated to the process with size " << p << " at memory block " << (memoryblock[i] + p) << endl;
            break;
        }
    }
}

int main() {
    int memoryblock[] = {100, 500, 200, 450, 600};
    int process[] = {212, 417, 112, 426};
    int n_memoryblock = sizeof(memoryblock) / sizeof(memoryblock[0]);
    int n_process = sizeof(process) / sizeof(process[0]);

    for (int i = 0; i < n_process; i++) {
        allocateMemoryBlock(process[i], memoryblock, n_memoryblock);
    }

    return 0;
}
