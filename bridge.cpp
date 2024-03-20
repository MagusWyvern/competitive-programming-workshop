#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int updateSlowest(vector<int> people) {
    int slowest = people[0];
    for (int i : people) {
        if (i > slowest) {
            slowest = i;
        }
    }
    return slowest;
}

int updateSecondSlowest(vector<int> people) {
    int slowest = updateSlowest(people);
    int secondSlowest = people[0];
    for (int i : people) {
        if (i > secondSlowest && i < slowest) {
            secondSlowest = i;
        }
    }
    return secondSlowest;
}

int main() {
    int peopleCount;
    cin >> peopleCount;
    vector<int> people;
    for (int i = 0; i < peopleCount; i++) {
        int temp;
        cin >> temp;
        people.push_back(temp);
    }
    sort(people.begin(), people.end());

    int fastest = people[0];
    int secondFastest = people[1];

    vector<int> people_left = people;
    int totalTime = 0;
    vector<vector<int>> sequence;

    while (people_left.size() > 3) {
        int slowest = updateSlowest(people_left);
        int secondSlowest = updateSecondSlowest(people_left);

        int firstMethod = 2 * fastest + slowest + secondSlowest;
        int secondMethod = 2 * slowest + fastest + secondFastest;

        if (firstMethod < secondMethod) {
            totalTime += firstMethod;
            sequence.push_back({fastest, secondFastest});
            sequence.push_back({fastest});
            sequence.push_back({slowest, secondSlowest});
            sequence.push_back({secondFastest});
        } else {
            totalTime += secondMethod;
            sequence.push_back({fastest, slowest});
            sequence.push_back({fastest});
            sequence.push_back({fastest, secondFastest});
            sequence.push_back({fastest});
        }
        people_left.erase(find(people_left.begin(), people_left.end(), slowest));
        people_left.erase(find(people_left.begin(), people_left.end(), secondSlowest));
    }
    if (people_left.size() == 3) {
        sequence.push_back({people_left[0], people_left[1]});
        sequence.push_back({people_left[0]});
        sequence.push_back({people_left[0], people_left[2]});
        people_left.clear();
    }
    if (people_left.size() == 2) {
        sequence.push_back(people_left);
        people_left.clear();
    }
    if (people_left.size() == 1) {
        sequence.push_back(people_left);
        people_left.clear();
    }
    cout << totalTime << endl;
    for (auto i: sequence) {
        for (auto j: i) {
            cout << j;
        }
        cout << endl;
    }
}