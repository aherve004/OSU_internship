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

#include <sys/time.h>

using namespace std;


extern "C" void parse(char* pfile);
extern "C" void setInternalState(double s[], int n);
extern "C" double step(double s[], int n, int a[], int m);
extern "C" double next(int a);
extern "C" void getActions(int*  actions[], int a, int b);

//globals
bool parseFunctionCalled = false;
SearchEngine* libSearchEngine = NULL;
PDState internalState;

double randomSeq[20];


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
//double step(double s[], int n, int a){ //Alex : change of the actionIndex into an array
double step(double s[], int n, int a[], int m) {
  if (!parseFunctionCalled) return -10000.0;

  vector<double> v(s, s+n);
  PDState current = State(v, SearchEngine::horizon);
	
  //Alex : change action to an action vector
  vector<int> actionVector(a,a+m);
  vector<DeterministicEvaluatable*> prec;

  //Alex creation of an actionnState corresponding to the action given by the array a[]
  vector<ActionFluent*> scheduledActionFluents;
  for( int i=0 ; i<m ; i++){
    if(actionVector[i])
      scheduledActionFluents.push_back(libSearchEngine->actionFluents[i]);
  } 
  ActionState aState(0, actionVector, scheduledActionFluents, libSearchEngine->actionPreconditions);
  
  //display of the action
  cout<<"action: ";
  for(std::vector<int>::const_iterator i = actionVector.begin() ; i < actionVector.end() ; i++){
    cout<<*i<<" ";
  }
  cout<<endl;
  
  //Alex : set a randomSequence to force the random in sample so as to be able to compare two version
  //Need to be remove at the end
  randomSeq[0] = 0.840188;
  randomSeq[1] = 0.394383;
  randomSeq[2] = 0.783099;
  randomSeq[3] = 0.798440;
  randomSeq[4] = 0.911647;
  randomSeq[5] = 0.197551;
  randomSeq[6] = 0.335223;
  randomSeq[7] = 0.553970;
  randomSeq[8] = 0.768230;
  randomSeq[9] = 0.277775;
  randomSeq[10] = 0.31729;
  randomSeq[11] = 0.005260;
  randomSeq[12] = 0.934406;
  randomSeq[13] = 0.654133;
  randomSeq[14] = 0.997699;
  randomSeq[15] = 0.217523;
  randomSeq[16] = 0.557219;
  randomSeq[17] = 0.744560;
  randomSeq[18] = 0.138614;
  randomSeq[19] = 0.604297;
  //end

  //Alex test to change actionIndexSystem
  /*
    int actionIndex = 0;
    if (a > 0) {
    actionIndex = (SearchEngine::actionFluents).size() - a + 1;
    }
  */
  //end


  //Check the preconditions, Alex
  /*
    if(!libSearchEngine->actionIsApplicable(SearchEngine::actionStates[actionIndex], current)){
    return -9999.9; //We may return an error instead of a reward 
    }*/

  //Display statefluents
  current.printCompact(cout);
  cout<<endl;

  //TO BE removed
  /*for(int i=0 ; i<11 ; i++){
    for( int j=0 ; j<libSearchEngine->actionStates[i].state.size() ; j++){
      cout<<libSearchEngine->actionStates[i].state[j]<< " ";
    }
    cout<<endl;
  }
  */
  //Compute Reward
  double reward = 0;
  //libSearchEngine->calcReward(current, actionIndex, reward);//Alex : change actionIndex to actionState
  libSearchEngine->calcReward(current, aState, reward);
	
  //Get next state s'
  PDState next;
	
  //libSearchEngine->calcSuccessorState(current, actionIndex, next);//Alex : change actionIndex to actionState
  libSearchEngine->calcSuccessorState(current, aState, next);

  //Sample
  for (unsigned int i = 0; i < State::numberOfProbabilisticStateFluents; ++i) {
    next.sample(i, randomSeq, i);//alex: add of randomSeq to control the randomness of the sample (comparaison of versions)
    //next.sample(i);
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
  cout<<endl;

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

void getActions(int* actions[], int a, int b){

}

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

  //Alex : checking time spent in step
  struct timeval *  t1 = NULL;
  struct timeval * t2 = NULL;
  gettimeofday(t1, NULL);

  
  for (int i=0; i<10000; i++) {
    //printf("\nstep %d\n", i);
    step(s, n, a, m);
    //cout << step(s, n, a,m) << endl;
    //cout<<step(s,n)<<endl;
    }
  //cout<<step(s,n,a,m)<<endl;

  //Alex : checkin time
  gettimeofday(t2, NULL);
  printf("%ld seconds %ld microseconds\n", t2->tv_sec - t1->tv_sec, t2->tv_usec - t1->tv_usec);
  



  
  /*  setInternalState(s, n);
  for (int i=0; i<n+1; i++) {
    cout << next(i) << endl;
  }
  */
  return 0;
}
