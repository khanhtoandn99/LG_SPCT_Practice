#include <iostream>

using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer

void InputData(void);
void OutputData(void);
int Find(int start);
void Solve(void);

int bruteForce_search(int arr[], int arr_len, int target);
void getDiff(int A_start);
int diffVector[10][10] = {0};
int diffArr[100] = {0};

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void OutputData(void)
{
	cout << sol;
}

// int Find(int start)
// {
// 	int i;

// 	for (i = 0; i < M; i++) {
// 		if (B[i] != A[start + i]) return 0;
// 	}
// 	return 1;
// }

void Solve(void)
{
	int i;

	for (i = 0; i <= N - M; i++) {
		sol += Find(i);
	}
}

// Competitor code:
int bruteForce_search(int arr[], int arr_len, int target) {
    int count = 0;
    cout << "search " << target << " ";
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == target) count += 1;
    }
    cout << "count = " << count << endl;
    return count;
}

void getDiff(int A_start)
{
    cout << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            diffVector[i][j] = A[i + A_start] - B[j];
            diffArr[M*i + j] = A[i + A_start] - B[j];
            // cout << diffVector[i][j] << " ";
            cout << A[i + A_start] - B[j] << " ";
        }
    }
    cout << endl;
}

int Find(int start)
{
    int count = 0;
    int diff = -29999;

    for (int i = 0; i < M; i++) {
        cout << A[i + start];
    }
    cout << " >< ";
    for (int i = 0; i < M; i++) {
        cout << B[i];
    }
    getDiff(start);

    for (int i = 0; i < M*M; i++) {
        cout << "i = " << i << " ";
        if (bruteForce_search(diffArr, M*M, diffArr[i]) == M) {
            diff = diffArr[i];
            break;
        }
    }

    cout << "diff = " << diff << endl;
    if (diff == -29999) return 0;

    for (int i = 0; i < M; i++) {
        int diffCol_arr[M] = {0};
        for (int j = 0; j < M; j++) {
            diffCol_arr[j] = diffVector[j][i];
            cout << diffCol_arr[j] << " ";
        }
        cout << endl;
        if (bruteForce_search(diffCol_arr, M, diff) != 1)
            return 0;
    }
    cout << "Detected one more VIRUS!!!" << endl;
    return 1;
}

int main(void)
{
	InputData(); // Input

	Solve(); // Problem solving

	OutputData(); // Output

    system("pause");
	return 0;
}

/**
 * @brief BELOW is Original code (without cout)
 */
#ifdef CODE_ORIGIN
#include <iostream>
using namespace std;

int N; // Number of executable code data
int M; // Number of virus data
int A[20000 + 10]; // Executable code data
int B[10 + 10]; // Virus data

int sol; // Correct answer

// Competitor code:
int diffVector[10][10] = {0};
// Competitor code:
int diffArr[100] = {0};

void InputData(void)
{
	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < M; i++) {
		cin >> B[i];
	}
}

void OutputData(void)
{
	cout << sol;
}

// Competitor code:
int bruteForce_search(int arr[], int arr_len, int target) {
    int count = 0;
    for (int i = 0; i < arr_len; i++) {
        if (arr[i] == target) count += 1;
    }
    return count;
}

// Competitor code:
void getDiff(int A_start)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            diffVector[i][j] = A[i + A_start] - B[j];
            diffArr[M*i + j] = A[i + A_start] - B[j];
        }
    }
}

// Competitor code:
int Find(int start)
{
    int count = 0;
    int diff = -29999;

    getDiff(start);

    for (int i = 0; i < M*M; i++) {
        if (bruteForce_search(diffArr, M*M, diffArr[i]) == M) {
            diff = diffArr[i];
            break;
        }
    }

    if (diff == -29999) return 0;

    for (int i = 0; i < M; i++) {
        int diffCol_arr[M] = {0};
        for (int j = 0; j < M; j++) {
            diffCol_arr[j] = diffVector[j][i];
        }
        if (bruteForce_search(diffCol_arr, M, diff) != 1)
            return 0;
    }
    return 1;
}

void Solve(void)
{
	int i;

	for (i = 0; i <= N - M; i++) {
		sol += Find(i);
	}
}

int main(void)
{
	InputData(); // Input

	Solve(); // Problem solving

	OutputData(); // Output

	return 0;
}
#endif