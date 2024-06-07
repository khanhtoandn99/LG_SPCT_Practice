#include <iostream>
#include <cstring>

using namespace std;

/**
 * "123abc456789abc"
 * "abc"
 */


int bruteForce_search(const char* des, const char* target) {
    bool bFound = true;
    int count = 0;
    int des_len = strlen(des);
    int target_len = strlen(target);

    for (int i = 0; i < des_len - target_len; i++) {
        for (int j = 0; j < target_len; j++) {
            // cout << target[j] << " " << des[j + i] << "-- ";
            if (target[j] != des[i + j]) {
                bFound = false;
                break;
            }
        }
        if (bFound == false) {
            bFound = true;
        } else {
            count++;
        }
        // cout << endl;
    }
    return count;
}

int main() {
    cout << "------------------ Brute force search ------------------" << endl;
    char des[] = "Many problems can be resolved using an exhaustive search, such as the traveling salesman problem and knapsack problem. The traveling salesman’s problem is that before returning to the starting place, the salesman must visit the N cities (only once) by using the shortest route.\0";
    char target[] = "problem\0";
    // bruteForce_search(des, target);
    cout << "Result: " << target << " appered " << bruteForce_search(des, target) << " times in " << des << endl;
    system("pause");
}