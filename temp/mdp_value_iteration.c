#include <stdio.h>
#define MAX(a, b) ((a>b)?a:b)

struct state{
  float * actions[2];
  float reward;
};

float value_iteration(struct state *tab, int state, int k);

float sum_on_state(struct state *tab, int state, int action, int k){
  float res = 0;
  int i;
  for( i=0 ; i<3 ; i++ ){
    if (tab[state].actions[action][i] != 0){
      res += tab[state].actions[action][i] * value_iteration(tab, i, k);
    }
  }
  return res;
}

float value_iteration(struct state *tab, int state, int k ){
  if (k <= 0){
    return tab[state].reward;
  }
  else{
    float val1 = sum_on_state(tab, state, 0, k-1);
    float val2 = sum_on_state(tab, state, 1, k-1);
    return tab[state].reward + 0.9*MAX(val1,val2); 
  }
}

int main(){
  int nb_state = 3;

  float attendre[3] = {0.8, 0, 0.2}; //state 0 : actions 0
  float bouger[3] = {0.5, 0.5, 0}; //state 0 : actions 1
  float defendre_1[3] = {0.25, 0.2, 0.55}; //state 1 : actions 0
  float fuir_1[3] = {0.4, 0.3, 0.3}; //state 1 : actions 1
  float defendre_2[3] = {0.3, 0, 0.7}; //state 2 : actions 0
  float fuir_2[3] = {0, 0.7, 0.3}; //state 2 : actions 1

  struct state tab_state[nb_state];
  tab_state[0].reward = 2;
  tab_state[0].actions[0] = attendre;
  tab_state[0].actions[1] = bouger;

  tab_state[1].reward = -1;
  tab_state[1].actions[0] = defendre_1;
  tab_state[1].actions[1] = fuir_1;
  
  tab_state[2].reward = -5;
  tab_state[2].actions[0] = defendre_2;
  tab_state[2].actions[1] = fuir_2;

  printf("V0(Tranquille) = %f\n", value_iteration(tab_state, 0, 0));
  printf("V1(Tranquille) = %f\n\n", value_iteration(tab_state, 0, 1));

  printf("V0(Encerclé) = %f\n", value_iteration(tab_state, 1, 0));
  printf("V1(Encerclé) = %f\n\n", value_iteration(tab_state, 1, 1));

  printf("V0(Attrapé) = %f\n", value_iteration(tab_state, 2, 0));
  printf("V1(Attrapé) = %f\n\n", value_iteration(tab_state, 2, 1));

    return 0;
}
