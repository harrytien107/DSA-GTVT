#include "TrainMovement.h"
#include <bits/stdc++.h>

TrainMovement::TrainMovement(int numCars, const vector<int>& target) 
    : n(numCars), targetOrder(target) {}

bool TrainMovement::isTargetReached(const State& state) {
    return state.isCEqual(targetOrder);
}

State TrainMovement::moveAtoB(const State& current) {
    if (current.isAEmpty()) return current;
    
    State newState = current;
    newState.pushToB(newState.frontA());
    newState.popFromA();
    newState.addMove("Chuyen " + to_string(newState.frontB()) + " tu A -> B");
    return newState;
}

State TrainMovement::moveAtoC(const State& current) {
    if (current.isAEmpty()) return current;
    
    State newState = current;
    int value = newState.frontA();
    newState.pushToC(value);
    newState.popFromA();
    newState.addMove("Chuyen " + to_string(value) + " tu A -> C");
    return newState;
}

State TrainMovement::moveBtoC(const State& current) {
    if (current.isBEmpty()) return current;
    
    State newState = current;
    int value = newState.frontB();
    newState.pushToC(value);
    newState.popFromB();
    newState.addMove("Chuyen " + to_string(value) + " tu B -> C");
    return newState;
}

string getStateString(const State& state) {
    stringstream ss;
    
    for (int val : state.getA()) ss << val << ",";
    ss << "|";
    
    for (int val : state.getB()) ss << val << ",";
    ss << "|";
    
    for (int val : state.getC()) ss << val << ",";
    
    return ss.str();
}

vector<State> TrainMovement::getNextStates(const State& current) {
    vector<State> nextStates;
    
    if (!current.isAEmpty()) {
        nextStates.push_back(moveAtoB(current));
        nextStates.push_back(moveAtoC(current));
    }
    if (!current.isBEmpty()) {
        nextStates.push_back(moveBtoC(current));
    }
    
    return nextStates;
}

bool TrainMovement::findSolution() {
    State initialState;
    for (int i = 1; i <= n; i++) {
        initialState.pushToA(i);
    }

    queue<State> queue;
    set<string> visited;

    queue.push(initialState);
    visited.insert(getStateString(initialState));

    while (!queue.empty()) {
        State current = queue.front();
        queue.pop();

        if (isTargetReached(current)) {
            printSolution(current.getMoves());
            return true;
        }

        vector<State> nextStates = getNextStates(current);
        for (const State& next : nextStates) {
            string stateStr = getStateString(next);
            if (visited.find(stateStr) == visited.end()) {
                visited.insert(stateStr);
                queue.push(next);
            }
        }
    }

    return false;
}

void TrainMovement::printSolution(const vector<string>& moves) {
    cout << "Co " << moves.size() << " buoc:" << endl;
    for (const string& move : moves) {
        cout << move << endl;
    }
}