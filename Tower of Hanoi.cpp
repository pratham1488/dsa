#include <iostream>
#include <vector>
#include <cmath>

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    towerOfHanoi(disks - 1, source, destination, auxiliary);
    std::cout << "Move disk " << disks << " from " << source << " to " << destination << std::endl;
    towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 20; // Change this to test for different number of disks

    if (numDisks < 1 || numDisks > 20) {
        std::cout << "Number of disks must be between 1 and 20." << std::endl;
        return 1;
    }

    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
