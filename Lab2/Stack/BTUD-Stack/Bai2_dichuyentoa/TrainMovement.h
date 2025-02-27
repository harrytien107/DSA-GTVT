#ifndef TRAIN_MOVEMENT_H
#define TRAIN_MOVEMENT_H

#include <vector>
#include <stack>
#include <string>
using namespace std;

class State {
private:
    vector<int> A;          // Queue A
    stack<int> B;           // Stack B
    vector<int> C;          // Queue C
    vector<string> moves;

public:
    State() = default;
    
    // Getters
    const vector<int>& getA() const { return A; }
    const stack<int>& getB() const { return B; }
    const vector<int>& getC() const { return C; }
    const vector<string>& getMoves() const { return moves; }
    
    // Modifiers for A
    void pushToA(int value) { A.push_back(value); }
    void popFromA() { if (!A.empty()) A.erase(A.begin()); }
    bool isAEmpty() const { return A.empty(); }
    int frontA() const { return A.empty() ? -1 : A.front(); }
    
    // Modifiers for B
    void pushToB(int value) { B.push(value); }
    void popFromB() { if (!B.empty()) B.pop(); }
    bool isBEmpty() const { return B.empty(); }
    int topB() const { return B.empty() ? -1 : B.top(); }
    
    // Modifiers for C
    void pushToC(int value) { C.push_back(value); }
    bool isCEqual(const vector<int>& target) const { return C == target; }
    
    // Move history
    void addMove(const string& move) { moves.push_back(move); }
};

class TrainMovement {
private:
    int n;
    vector<int> targetOrder;

    bool isTargetReached(const State& state);
    State moveAtoB(const State& current);
    State moveAtoC(const State& current);
    State moveBtoC(const State& current);
    vector<State> getNextStates(const State& current);

public:
    TrainMovement(int numCars, const vector<int>& target);
    bool findSolution();
    void printSolution(const vector<string>& moves);
};

#endif