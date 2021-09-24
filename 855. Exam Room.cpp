// ***
//
// There is an exam room with n seats in a single row labeled from 0 to n - 1.
//
// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there
// are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits
// at seat number 0.
//
// Design a class that simulates the mentioned exam room.
//
// Implement the ExamRoom class:
//
// ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
// int seat() Returns the label of the seat at which the next student will sit.
// void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will
// be a student sitting at seat p.
//
//
// Example 1:
//
// Input
// ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
// [[10], [], [], [], [], [4], []]
// Output
// [null, 0, 9, 4, 2, null, 5]
//
// Explanation
// ExamRoom examRoom = new ExamRoom(10);
// examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
// examRoom.seat(); // return 9, the student sits at the last seat number 9.
// examRoom.seat(); // return 4, the student sits at the last seat number 4.
// examRoom.seat(); // return 2, the student sits at the last seat number 2.
// examRoom.leave(4);
// examRoom.seat(); // return 5, the student sits at the last seat number 5.
//
// Constraints:
//
// 1 <= n <= 10^9
// It is guaranteed that there is a student sitting at seat p.
// At most 10^4 calls will be made to seat and leave.
//
// ***

// Extension of 849. Maximize Distance to Closest Person.
class ExamRoom {
public:
    ExamRoom(int n) { _n = n; }

    int seat() {
        // prevIdx: last seat which was occupied.
        // curIdx: current seat which is occupied.
        // chosenIdx: seat which we will choose.
        int prevIdx = -1, maxDist = 0, chosenIdx = 0;
        for (int curIdx : _occupied) {
            if (prevIdx == -1) {
                // Sit next to left wall
                maxDist = curIdx;
                chosenIdx = 0;
            } else {
                // Sit in between two people.
                if (maxDist < (curIdx - prevIdx) / 2) {
                    maxDist = (curIdx - prevIdx) / 2;
                    chosenIdx = prevIdx + maxDist;
                }
            }
            prevIdx = curIdx;
        }

        // Sit next to right wall.
        // Need to check if prevIdx != -1 because we can only consider sitting next the right wall
        // only if _occupied is not empty (someone is in the exam room). If the exam room is empty we have to sit by the
        // left wall.
        if (prevIdx != -1 and maxDist < (_n - 1) - prevIdx) {
            maxDist = (_n - 1) - prevIdx;
            chosenIdx = (_n - 1);
        }

        _occupied.insert(chosenIdx);
        return chosenIdx;
    }

    void leave(int p) { _occupied.erase(p); }

private:
    set<int> _occupied;
    int _n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
