#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Activity {
    int start, finish;
};


bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}


void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare); 
    
    cout << "Selected Activities: \n";
    int lastFinishTime = 0;

    for (auto activity : activities) {
        if (activity.start >= lastFinishTime) {
            cout << "Start: " << activity.start << ", Finish: " << activity.finish << endl;
            lastFinishTime = activity.finish; // Update the last finish time
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    activitySelection(activities);
    return 0;
}
