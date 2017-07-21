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
PDState internalState;


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

}


//Simulate action a on state s and return s'
double step(double s[], int n, int a[], int m) {
	if (!parseFunctionCalled) return -10000.0;

	vector<double> v(s, s+n);
	PDState current = State(v, SearchEngine::horizon);

	//Alex : change action to an action vector
	vector<int> actionVector(a,a+m);
	vector<DeterministicEvaluatable*> prec;
	ActionState aState(0, actionVector, libSearchEngine->actionFluents, prec);


	//Alex test to change actionIndexSystem
	/*
	int actionIndex = 0;
	if (a > 0) {
		actionIndex = (SearchEngine::actionFluents).size() - a + 1;
	}
	*/
	/*
	int actionIndex = 0;
	if (a>0){
	  actionIndex = a;
	  }*/
	//end

	//Display action for debug
	/*cout << "action : ";
	(libSearchEngine->actionStates[actionIndex]).printCompact(cout);
	cout<<libSearchEngine->actionStates[actionIndex].index<<" aF:"<<libSearchEngine->actionFluents[actionIndex]->index<<":"<<libSearchEngine->actionFluents[actionIndex]->name<<endl;
	cout << endl;
	*/

	//Check the preconditions, Alex
	/*
	if(!libSearchEngine->actionIsApplicable(SearchEngine::actionStates[actionIndex], current)){
	  return -9999.9; //We may return an error instead of a reward 
	  }*/

	//Display statefluents
	current.printCompact(cout);
	cout<<endl;

	//Compute Reward
	double reward = 0;
	//libSearchEngine->calcReward(current, actionIndex, reward);//Alex : change actionIndex to actionVector
	//libSearchEngine->calcReward(current, actionVector, reward);
	libSearchEngine->calcReward(current, aState, reward);
	
	//Get next state s'
	PDState next;
	
	//libSearchEngine->calcSuccessorState(current, actionIndex, next);//Alex : change actionIndex to actionVector
	//libSearchEngine->calcSuccessorState(current, actionVector, next);	
	libSearchEngine->calcSuccessorState(current, aState, next);

	//Sample
	for (unsigned int i = 0; i < State::numberOfProbabilisticStateFluents; ++i) {
		next.sample(i);
	}

	//Set s to s'
	for (int i=0; i<State::numberOfDeterministicStateFluents; i++) {
		s[i] = next.deterministicStateFluent(i);
	}
	for (int j=0; j<State::numberOfProbabilisticStateFluents; j++) {
		s[j+State::numberOfDeterministicStateFluents] = next.probabilisticStateFluent(j);
	}

	//Display statefluents
	next.printCompact(cout);
	
	return reward;
}

/*
//Set internal State
void setInternalState(double s[], int n) {
	vector<double> v(s, s+n);
	PDState current = State(v, SearchEngine::horizon);
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
*/


int main(int argc, char** argv) {
  /*double s[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  */
  //double s[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  double s[] = {0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0};
  int n = end(s) - begin(s);
  int a[] = {0, 0, 1, 0, 1, 0, 1, 0, 0, 0};
  int m = end(a) - begin(a);
  parse(argv[1]);
  printf("parser ended\n");

  printf("\nstateFluents :\n");
  for(int i=0 ; i<libSearchEngine->stateFluents.size() ; i++){
    std::cout<<libSearchEngine->stateFluents[i]->index<<":"<<libSearchEngine->stateFluents[i]->name<<" ";
  }
  printf("\n\n");
  //printf("\nActionStates\n");

  /* ->segfault
  for(int i=0 ; i<libSearchEngine->stateFluents.size() ; i++){
    std::cout<<libSearchEngine->actionStates[0].scheduledActionFluents[i]->index<<":"<<libSearchEngine->actionStates[0].scheduledActionFluents[i]->name<<" ";
  }
  printf("\n");
  */

  
  for (int i=0; i<n+1; i++) {
    printf("\nstep %d\n", i);
    cout << step(s, n, a,m) << endl;
    }
  //cout<<step(s,n,a,m)<<endl;
  
  /*  setInternalState(s, n);
  for (int i=0; i<n+1; i++) {
    cout << next(i) << endl;
  }
  */
  return 0;
}
