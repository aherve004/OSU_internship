// Murugeswari
/* RDDL Simulator - C Library */

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
#include "parser.h"
#include "search_engine.h"
#include "utils/math_utils.h"


using namespace std;


extern "C" void parse(char* pfile);
extern "C" void setInternalState(double s[], int n);
extern "C" double step(double s[], int n, int a);
extern "C" double next(int a);


//globals
bool parseFunctionCalled = false;
SearchEngine* libSearchEngine = NULL;
State internalState;


//Parse rddl-parser output file
void parse(char* pfile) {
	string problemFileName = pfile;
	Parser parser(problemFileName);

	std::cout << "Parsing ... " << problemFileName << std::endl;
	map<string, int> stateVariableIndices;
	vector<vector<string>> stateVariableValues;
	parser.parseTask(stateVariableIndices, stateVariableValues);
	parseFunctionCalled = true;
	cout << "Done" << endl;

	MathUtils::rnd->seed(time(0));
	libSearchEngine = new ProbabilisticSearchEngine("lib");

	// Test
	SearchEngine::printTask(cout);
}


//Simulate action a on state s and return s'
double step(double s[], int n, int a) {
	if (!parseFunctionCalled) return -10000.0;

	vector<double> v(s, s+n);

	//Alex : gather State and PDState as State
	//PDState current = State(v, SearchEngine::horizon);
	State current = State(v,  SearchEngine::horizon);
	//Alex :end

	printf("actionFluents.size : %ld\n",(SearchEngine::actionFluents).size());
	int actionIndex = 0;
	if (a > 0) {
		actionIndex = (SearchEngine::actionFluents).size() - a + 1;
		
		//Test
		cout << "a: " << a << " actionIndex: " << actionIndex << endl;
		//(libSearchEngine->actionStates[actionIndex]).printCompact(cout);
		//cout << endl;
	}

	//Compute Reward
	double reward = 0;
	libSearchEngine->calcReward(current, actionIndex, reward);

	//Get next state s'
	//Alex : gather State and PDState as State
	//PDState next;
	State next;
	//Alex : end

	printf("11111\n");
	libSearchEngine->calcSuccessorState(current, actionIndex, next);
	printf("2222\n");
	for (unsigned int i = 0; i < State::numberOfProbabilisticStateFluents; ++i) {
		next.sample(i);
	}
	printf("3333\n");
	//Set s to s'
	for (int i=0; i<State::numberOfDeterministicStateFluents; i++) {
		s[i] = next.deterministicStateFluent(i);
	}
	for (int j=0; j<State::numberOfProbabilisticStateFluents; j++) {
		s[j+State::numberOfDeterministicStateFluents] = next.probabilisticStateFluent(j);
	}
	printf("end step\n");
	return reward;
}


//Set internal State
void setInternalState(double s[], int n) {
	vector<double> v(s, s+n);
	//Alex : gather State and PDState as State
	//PDState current = State(v, SearchEngine::horizon);
	State current = State(v, SearchEngine::horizon);
	internalState = current;
}


//Simulate action a on internal state and return just the reward
double next(int a) {
	if (!parseFunctionCalled) return -10000.0;

	int actionIndex = 0;
	if (a > 0) {
		actionIndex = (SearchEngine::actionFluents).size() - a + 1;
	}

	//Compute Reward
	double reward = 0;
	libSearchEngine->calcReward(internalState, actionIndex, reward);

	//Get next state s'
	PDState next;
	libSearchEngine->calcSuccessorState(internalState, actionIndex, next);
	for (unsigned int i = 0; i < State::numberOfProbabilisticStateFluents; ++i) {
		next.sample(i);
	}

	//set internalState to next
	internalState = next;

	return reward;
}



int main(int argc, char** argv) {
  /*double s[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  */
  double s[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int n = end(s) - begin(s);
  parse(argv[1]);
  printf("parser ended\n");
  for (int i=0; i<n+1; i++) {
    printf("step %d\n", i);
    cout << step(s, n, i) << endl;
  }

  setInternalState(s, n);
  for (int i=0; i<n+1; i++) {
    cout << next(i) << endl;
  }
  
  return 0;
}
