// ***
//
// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k),
// where h is the height of the person and k is the number of people in front of this person who have a height greater
// than or equal to h. Write an algorithm to reconstruct the queue.
//
// Note:
// The number of people is less than 1,100.
//
// Example
//
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
// ***
//
// Sort by height (taller person to the left, shorter person to the right)
// When two people have the same height, the person with less people in front of him takes precedence over the person
// with more people in front.
//
// Original: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// After sorted: [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
// Return: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(),
         [](vector<int>& a, vector<int>& b) { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });

    vector<vector<int>> toReturn;
    for (auto currentPerson : people) {
        // For currentPerson, we know there are currentPerson[1] number of people who are in front of currentPerson
        // and whose heights are higher than currentPerson. Since people array has already been sorted by decreasing
        // height, we simply insert currentPerson to the position at (toReturn.begin() + currentPerson[1]), which
        // is the postiion currentPerson belongs to.
        int numOfPeopleInFrontOfCurrentPerson = currentPerson[1];
        toReturn.insert(toReturn.begin() + numOfPeopleInFrontOfCurrentPerson, currentPerson);
    }

    return toReturn;
}
