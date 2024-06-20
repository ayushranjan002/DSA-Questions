
bool isPossible(const vector<int>& boards, int k, int mid) {
    int noOfPainters = 1;
    int totalTime = 0;
    int n = boards.size();
    
    for (int i = 0; i < n; i++) {
        if (totalTime + boards[i] <= mid) {
            totalTime += boards[i];
        } else {
            noOfPainters++;
            if (noOfPainters > k || boards[i] > mid) {
                return false;
            }
            totalTime = boards[i];  // Reset totalTime for the new painter
        }
    }
    return true;
}

int findLargestMinDistance(vector<int>& boards, int k) {
    int s = *max_element(boards.begin(), boards.end());//find the largest element in a given range of elements within a vector.
    int n = boards.size();
    int sum = accumulate(boards.begin(), boards.end(), 0);//calculate the sum of all elements within a specified range in a vector.
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (isPossible(boards, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
/*
bool isPossible(const vector<int>& boards, int k, int mid) {
int noOfPainters = 1;
int totalTime = 0;
int n = boards.size();
for (int i = 0; i < n; i++) {
if (totalTime + boards[i] < mid) {
totalTime += boards[i];
} else {
noOfPainters++;
if (noOfPainters > k || boards[i] > mid) {
return false;
}
totalTime = 0;
totalTime = boards[i];
}
}
return true;
}

int findLargestMinDistance(vector<int>& boards, int k) {
int s = 0;
int n = boards.size();
// Pre-calculate the sum of boards for efficiency
int sum = accumulate(boards.begin(), boards.end(), 0);
int e = sum;
int mid = s + (e - s) / 2;
int ans = -1;

while (s <= e) {
if (isPossible(boards, k, mid)) {
ans = mid;
e = mid - 1;
} else {
s = mid + 1;
}
mid = s + (e - s) / 2;
}
return ans;
}
*/
