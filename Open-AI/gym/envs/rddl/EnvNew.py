# Murugeswari
# RDDL Environment

import os
import random
import ctypes
import numpy as np
import time

#import gym

#from gym import Env
#from gym.utils import seeding


class RDDLEnv() :
	def __init__(self, domain, instance) :
		# Domain and Problem file names
		self.domain = domain + '_mdp'
		self.problem = domain + '_inst_mdp__' + instance

		# Seed Random number generator
		#self._seed()

		# Run rddl-parser executable
		os.system("./rddl/lib/rddl-parser " + "./rddl/domains/" + self.domain + ".rddl " + \
            "./rddl/domains/"  + self.problem + ".rddl" + " ./rddl/parsed/")
                print('parsed')
		f = open('./rddl/parsed/' + self.problem)
		p = "##"		# Values of p are hard-coded in PROST. Should not be changed.
		for l in f:
			if (p == "## horizon\n") :
				h = int(l)
			elif (p == "## number of action fluents\n") :
				num_act = int(l)
			elif (p == "## number of det state fluents\n") :
				num_det = int(l)
			elif (p == "## number of prob state fluents\n") :
				num_prob = int(l)
			elif (p == "## initial state\n") :
				init = [int(i) for i in l.split()]
				break
			p = l
		f.close()

		# Problem parameters
		self.num_state_vars = num_det + num_prob	# number of state variables
		self.num_action_vars = num_act				# number of action variables
		self.initial_state = init
		self.state = np.array(self.initial_state)	# current state
		self.horizon = h	# episode horizon
		self.tstep = 1		# current time step
		self.done = False	# end_of_episode flag
		self.reward = 0		# episode reward

		# Set up RDDL Simulator clibxx.dylib
		self.rddlsim = ctypes.CDLL('./rddl/lib/clibxx.so')
		self.rddlsim.step.restype = ctypes.c_double

		# Initialize Simulator
		#parser_output = ctypes.create_string_buffer(b'./rddl/parsed/'+bytearray(self.problem, "utf8"))
		#self.rddlsim.parse(parser_output.value)

		# Murugeswari
		parsed_file_name = './rddl/parsed/' + self.problem
		parsed_file_name_byteobject = parsed_file_name.encode()
		parsed_file_name_ctype = ctypes.create_string_buffer(parsed_file_name_byteobject, len(parsed_file_name_byteobject))
		self.rddlsim.parse(parsed_file_name_ctype.value)


	# Do not understand this yet. Almost all other sample environments have it, so we have it too.
	#def _seed(self, seed=None):
		#self.np_random, seed = seeding.np_random(seed)
		#return [seed]


	# Take a real step in the environment. Current state changes.
	def _step(self, action_var) :
		# Convert state and action to c-types
		s = self.state
		ss = s.tolist()
		sss = (ctypes.c_double * len(ss))(*ss)
		action = (ctypes.c_int)(action_var)

		# Call Simulator
		reward = self.rddlsim.step(sss, len(ss), action)
		self.state = np.array(sss, dtype=np.int8)
		self.reward = self.reward + reward

		# Advance time step
		self.tstep = self.tstep + 1
		if self.tstep > self.horizon:
			self.done = True

		return self.state, reward, self.done, {}


	# Take an imaginary step to get the next state and reward. Current state does not change.
	def pseudostep(self, curr_state, action_var):
		# Convert state and action to c-types
		s = np.array(curr_state)
		ss = s.tolist()
		sss = (ctypes.c_double * len(ss))(*ss)
		action = (ctypes.c_int)(action_var)

		# Call Simulator
		reward = self.rddlsim.step(sss, len(ss), action)
		next_state = np.array(sss, dtype=np.int8)

		return next_state, reward


	def _reset(self):
		self.state = np.array(self.initial_state)
		self.tstep = 1
		self.done = False
		self.reward = 0
		return self.state, self.done


	def _close(self):
		print("Environment Closed")

if __name__ == '__main__':
	#ENV = gym.make('RDDL-v1')
	#ENV.seed(0)
        problem_list = ["game_of_life","navigation","sysadmin","tamarisk"]
	NUM_EPISODES = 10000
        for prob in problem_list :
                for j in range(10) :
                        ENV = RDDLEnv(prob, str(j+1))
                        #ENV = RDDLEnv("navigation", "1")

                        time_sum = 0.0
                        reward_sum = 0.0
                        
                        for i in range(NUM_EPISODES):
                                reward = 0	# epsiode reward
                                rwd = 0 # step reward
                                curr, done = ENV._reset()	# current state and end-of-episode flag
                                while not done :
                                        action = random.randint(0, ENV.num_action_vars) # choose a random action
                                        #action = 0
                                        t0 = time.clock()
                                        nxt, rwd, done, _ = ENV._step(action) # next state and step reward
                                        time_sum += time.clock() - t0
                                        #print('state: {}  action: {}  reward: {} next: {}'.format(curr, action, rwd, nxt))
                                        curr = nxt
                                        reward += rwd
                                        reward_sum += reward
                                        #print('time to finish the while loop = {}' .format(time_sum))
                                        #print('Episode Reward: {}'.format(reward))
                                        #print()
                        print('\n')
                        print('#########################################################################')
                        print('##problem : {}_inst_mdp__{}##' .format(prob, j+1))
                        print('time average : {} sec for a run over {} episodes' .format(time_sum/NUM_EPISODES, NUM_EPISODES))
                        print('reward average : {}' .format(reward_sum/NUM_EPISODES))
                        ENV._close()
                        print('#########################################################################')
                        print('\n')
