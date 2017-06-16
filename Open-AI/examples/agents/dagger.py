# Murugeswari
# Implementation of API, DAGGER, AGGRAVATE and D-AGGRAVATE

import numpy as np
import tensorflow as tf
import pandas as pd

import argparse
import random

import gym

from gym.envs.rddl.NNClassifier import Classifier
from gym.envs.rddl.NNRegression import Regression

# Noop Agent
class NOOP(object) :
	def act(self, observation, reward, done) :
		return 0


# Random Agent
class Random(object) :
	def __init__(self) :
 		self.num_action_vars = ENV.num_action_vars

	def act(self, observation, reward, done) :
		return random.randint(0, self.num_action_vars)


# Expert Agent
# Agent has access to the environment (for the time being), but it calls only legitimate functions
class Expert(object) :
	def __init__(self) :
		self.num_action_vars = ENV.num_action_vars
		self.num_state_vars = ENV.num_state_vars
		self.episode_horizon = ENV.horizon
		self.problem = ENV.problem + ID
		self.X = np.zeros((NUM_EPISODES * self.episode_horizon, self.num_state_vars), dtype=np.int8)
		self.Y = np.zeros((NUM_EPISODES * self.episode_horizon, self.num_action_vars + 1), dtype=np.int8) # +1 to include NOOP
		self.iteration = 1
		self.meta = MODEL_DIR + self.problem + "expert" + str(self.iteration) + ".meta" # initially
		self.ckpt = MODEL_DIR + self.problem + "expert" + str(self.iteration) + ".ckpt" # initially
		self.rollout_meta = MODEL_DIR + self.problem + "expert" + str(self.iteration - 1) + ".meta" # initially
		self.rollout_ckpt = MODEL_DIR + self.problem + "expert" + str(self.iteration - 1) + ".ckpt" # initially


	# Rollout policy is the Random policy for iteration-1 and the deep-net policy of the previous iteration otherwise
	def rollout_policy_action(self, state, sess = 0, X1 = 0, Y1 = 0, YHAT = 0) :
		if self.iteration == 1 :	# rollout random policy
			return random.randint(0, self.num_action_vars)
		else :
			dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
			action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(state, np.int8),
				Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
			return action


	def compute_policy(self, iteration) :
		self.iteration = iteration
		if iteration == 1:
			for episode in range(NUM_EPISODES) :
				index_base = episode * self.episode_horizon
				current_state, end_of_episode = ENV.reset()
				tstep = 0 # time step
				while not end_of_episode :
					best_action = self.expert_action(current_state)
					action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8) # bit vector
					action_vector[best_action] = 1
					next_state, _, end_of_episode, _ = ENV._step(best_action) # take a real step in the environment
					index = index_base + tstep
					self.X[index] = current_state
					self.Y[index] = action_vector
					current_state = next_state
					tstep += 1
		else :
			self.rollout_meta = MODEL_DIR + self.problem + "expert" + str(self.iteration - 1) + ".meta"
			self.rollout_ckpt = MODEL_DIR + self.problem + "expert" + str(self.iteration - 1) + ".ckpt"
			ngraph = tf.Graph()
			with tf.Session(graph = ngraph) as sess :
				model = tf.train.import_meta_graph(self.rollout_meta)
				model.restore(sess, self.rollout_ckpt)
				X1 = tf.get_collection('X1')[0]
				Y1 = tf.get_collection('Y1')[0]
				YHAT = tf.get_collection('YHAT')[0]
				for episode in range(NUM_EPISODES) :
					index_base = episode * self.episode_horizon
					current_state, end_of_episode = ENV.reset()
					tstep = 0 # time step
					while not end_of_episode :
						best_action = self.expert_action(current_state, sess, X1, Y1, YHAT)
						action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8) # bit vector
						action_vector[best_action] = 1
						next_state, _, end_of_episode, _ = ENV._step(best_action) # take a real step in the environment
						index = index_base + tstep
						self.X[index] = current_state
						self.Y[index] = action_vector
						current_state = next_state
						tstep += 1


	def approximate_policy(self) :
		WR = pd.DataFrame(np.concatenate((self.X, self.Y), axis = 1))
		WR.to_csv(DATA_DIR + self.problem + "expert" + str(self.iteration) + ".csv", index = False, header = None)

		self.meta = MODEL_DIR + self.problem + "expert" + str(self.iteration) + ".meta"
		self.ckpt = MODEL_DIR + self.problem + "expert" + str(self.iteration) + ".ckpt"

		C = Classifier(self.X, self.Y, self.meta, self.ckpt)
		with tf.Graph().as_default() :
			C.train_network()
			C.test_network(self.X, self.Y)


	def dataset(self) :
		return self.X, self.Y


	def expert_action(self, current_state, sess = 0, X1 = 0, Y1 = 0, YHAT = 0) :
		qvalue_vector = np.zeros(self.num_action_vars + 1) # +1 for NOOP
		for k in range(NUM_ACTION_TRIALS) :
			for action in range(self.num_action_vars + 1) : # +1 for NOOP
				nxt, rwd = ENV.pseudostep(current_state, action)
				qvalue_vector[action] += rwd
				for t in range(TRAJECTORY_LENGTH - 1) :
					rollout_action = self.rollout_policy_action(nxt, sess, X1, Y1, YHAT)
					nxt, rwd = ENV.pseudostep(nxt, rollout_action)
					qvalue_vector[action] += rwd
		best_action = np.argmax(qvalue_vector)
		return best_action


	def expert_action_with_print(self, current_state, sess = 0, X1 = 0, Y1 = 0, YHAT = 0) :
		qvalue_vector = np.zeros(self.num_action_vars + 1) # +1 for NOOP
		for k in range(NUM_ACTION_TRIALS) :
			for action in range(self.num_action_vars + 1) : # +1 for NOOP
				print('curr: {}'.format(current_state))
				nxt, rwd = ENV.pseudostep(current_state, action)
				print('action: {} next: {} reward: {}'.format(action, nxt, rwd))
				qvalue_vector[action] += rwd
				for t in range(TRAJECTORY_LENGTH - 1) :
					rollout_action = self.rollout_policy_action(nxt, sess, X1, Y1, YHAT)
					nxt, rwd = ENV.pseudostep(nxt, rollout_action)
					print('rollout action: {} next: {} reward: {}'.format(rollout_action, nxt, rwd))
					qvalue_vector[action] += rwd
		best_action = np.argmax(qvalue_vector)
		print('qvalue_vector: {} best_action: {}'.format(qvalue_vector, best_action))
		return best_action


	def expert_qvalue(self, current_state, action, nsteps) :
		qvalue = 0
		for t in range(nsteps - 1) :
			action = self.expert_action(current_state)
			next_state, reward, end_of_episode, _ = ENV.step(action)
			qvalue += reward
			current_state = next_state
		return qvalue


	# For testing. Use run(), which loads the graph just once.
	def act(self, observation, reward, done) :
		ngraph = tf.Graph()
		with tf.Session(graph = ngraph) as sess :
			model = tf.train.import_meta_graph(self.meta)
			model.restore(sess, self.ckpt)
			X1 = tf.get_collection('X1')[0]
			Y1 = tf.get_collection('Y1')[0]
			YHAT = tf.get_collection('YHAT')[0]

			action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
			action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(observation, np.int8),
				Y1: np.matrix(action_vector, np.int8)}), axis=1)
			return action


	def run(self) :
		ngraph = tf.Graph()
		with tf.Session(graph = ngraph) as sess :
			model = tf.train.import_meta_graph(self.meta)
			model.restore(sess, self.ckpt)
			X1 = tf.get_collection('X1')[0]
			Y1 = tf.get_collection('Y1')[0]
			YHAT = tf.get_collection('YHAT')[0]

			dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
			for episode in range(NUM_EPISODES):
				episode_reward = 0	# epsiode reward
				reward = 0 # step reward
				current_state, end_of_episode = ENV.reset()	# current state and end-of-episode flag
				while not end_of_episode :
					action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(current_state, np.int8),
						Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
					next_state, reward, end_of_episode, _ = ENV.step(action) # next state and step reward
					print('state: {}  action: {}  reward: {} next: {}'.format(current_state, action, reward, next_state))
					current_state = next_state
					episode_reward += reward
				print('Episode Reward: {}'.format(episode_reward))
				print()



# DAGGER Agent
# Agent has access to the environment (for the time being), but it calls only legitimate functions
class Dagger(object) :
	def __init__(self) :
		self.num_action_vars = ENV.num_action_vars
		self.num_state_vars = ENV.num_state_vars
		self.episode_horizon = ENV.horizon
		self.problem = ENV.problem + ID
		self.max_iterations = 5
		self.X = np.zeros((NUM_EPISODES * self.episode_horizon * (self.max_iterations + 1), self.num_state_vars), dtype=np.int8)
		self.Y = np.zeros((NUM_EPISODES * self.episode_horizon * (self.max_iterations + 1), self.num_action_vars + 1), dtype=np.int8) # +1 to include NOOP
		self.meta = MODEL_DIR + self.problem + "expert1.meta"	# for iteration 1
		self.ckpt = MODEL_DIR + self.problem + "expert1.ckpt"	# for iteration 1


	def refine_policy(self) :
		expert_dataset_size = NUM_EPISODES * self.episode_horizon
		self.X[0:expert_dataset_size,:], self.Y[0:expert_dataset_size,:] = EXPERT.dataset()

		for iteration in range(self.max_iterations) :
			index_base = NUM_EPISODES * self.episode_horizon * (iteration + 1)
			ngraph = tf.Graph()
			with tf.Session(graph = ngraph) as sess :
				model = tf.train.import_meta_graph(self.meta)
				model.restore(sess, self.ckpt)
				X1 = tf.get_collection('X1')[0]
				Y1 = tf.get_collection('Y1')[0]
				YHAT = tf.get_collection('YHAT')[0]

				for episode in range(NUM_EPISODES) :
					index = index_base + (episode * self.episode_horizon)
					current_state, end_of_episode = ENV.reset()
					tstep = 0 # time step
					while not end_of_episode :
						dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
						action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(current_state, np.int8),
								Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
						next_state, _, end_of_episode, _ = ENV._step(action) # take a real step in the environment
						expert_action = EXPERT.expert_action(current_state)
						expert_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8) # bit vector
						expert_action_vector[expert_action] = 1
						print('state: {} action: {} expert: {} index: {}'.format(current_state, action, expert_action, index+tstep))
						self.X[index + tstep] = current_state
						self.Y[index + tstep] = expert_action_vector
						current_state = next_state
						tstep += 1

			self.meta = MODEL_DIR + self.problem + "dagger" + str(iteration + 1) + ".meta"
			self.ckpt = MODEL_DIR + self.problem + "dagger" + str(iteration + 1) + ".ckpt"
			dataset_size = NUM_EPISODES * self.episode_horizon * (iteration + 2)

			WR = pd.DataFrame(np.concatenate((self.X[0:dataset_size,:], self.Y[0:dataset_size,:]), axis = 1))
			WR.to_csv(DATA_DIR + self.problem + "dagger" + str(iteration + 1) + ".csv", index = False, header = None)

			C = Classifier(self.X[0:dataset_size,:], self.Y[0:dataset_size,:], self.meta, self.ckpt)
			with tf.Graph().as_default() :
				C.train_network()
				C.test_network(self.X[0:dataset_size,:], self.Y[0:dataset_size,:])


	def act(self, observation, reward, done) :
		ngraph = tf.Graph()
		with tf.Session(graph = ngraph) as sess :
			model = tf.train.import_meta_graph(self.meta)
			model.restore(sess, self.ckpt)
			X1 = tf.get_collection('X1')[0]
			Y1 = tf.get_collection('Y1')[0]
			YHAT = tf.get_collection('YHAT')[0]

			dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
			action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(observation, np.int8),
				Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
			return action


	def run(self) :
		ngraph = tf.Graph()
		with tf.Session(graph = ngraph) as sess :
			model = tf.train.import_meta_graph(self.meta)
			model.restore(sess, self.ckpt)
			X1 = tf.get_collection('X1')[0]
			Y1 = tf.get_collection('Y1')[0]
			YHAT = tf.get_collection('YHAT')[0]

			dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
			for episode in range(NUM_EPISODES):
				episode_reward = 0	# epsiode reward
				reward = 0 # step reward
				current_state, end_of_episode = ENV.reset()	# current state and end-of-episode flag
				while not end_of_episode :
					action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(current_state, np.int8),
						Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
					next_state, reward, end_of_episode, _ = ENV.step(action) # next state and step reward
					print('state: {}  action: {}  reward: {} next: {}'.format(current_state, action, reward, next_state))
					current_state = next_state
					episode_reward += reward
				print('Episode Reward: {}'.format(episode_reward))
				print()


# Aggravate Agent
class Aggravate(object) :
	def __init__(self) :
		self.num_action_vars = ENV.num_action_vars
		self.num_state_vars = ENV.num_state_vars
		self.episode_horizon = ENV.horizon
		self.problem = ENV.problem + ID
		self.num_samples = 200
		self.max_iterations = 1
		self.X = np.zeros((NUM_EPISODES * self.num_samples * self.max_iterations, self.num_state_vars + self.num_action_vars + 2), dtype=np.int8)
		self.Y = np.zeros((NUM_EPISODES * self.num_samples * self.max_iterations, 1), dtype=np.int8) # +1 to include NOOP
		self.meta = MODEL_DIR + self.problem + "expert1.meta"	# for iteration 1
		self.ckpt = MODEL_DIR + self.problem + "expert1.ckpt"	# for iteration 1


	def refine_policy(self) :
		for iteration in range(self.max_iterations) :
			index_base = NUM_EPISODES * self.num_samples * iteration
			ngraph = tf.Graph()
			with tf.Session(graph = ngraph) as sess :
				model = tf.train.import_meta_graph(self.meta)
				model.restore(sess, self.ckpt)
				X1 = tf.get_collection('X1')[0]
				Y1 = tf.get_collection('Y1')[0]
				YHAT = tf.get_collection('YHAT')[0]

				for episode in range(NUM_EPISODES) :
					index = index_base + (episode * self.episode_horizon)
					for j in range(self.num_samples) :
						current_state, end_of_episode = ENV.reset()
						t = random.randint(0, self.episode_horizon - 1)
						dummy_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
						for i in range(t) :
							if iteration == 0 :
								best_action = np.argmax(sess.run(YHAT, feed_dict={X1: np.matrix(current_state, np.int8),
									Y1: np.matrix(dummy_action_vector, np.int8)}), axis=1)
							else :
								for action in range(self.num_action_vars + 1) :
									action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
									action_vector[action] = 1
									state_action_time = np.zeros(self.num_state_vars + self.num_action_vars + 2, dtype = np.int8)
									state_action_time[0:self.num_state_vars] = current_state
									state_action_time[self.num_state_vars:self.num_state_vars+self.num_action_vars+1] = exploratory_action_vector
									state_action_time[self.num_state_vars+self.num_action_vars+1:self.num_state_vars+self.num_action_vars+2] = i
									QHAT = sess.run(YHAT, feed_dict={X1: np.matrix(state_action_time, np.int8),
										Y1: np.matrix(dummy_qvalue, np.int8)})
									if action == 0 :
										best_action = action
										QMAX = QHAT
									elif QHAT > QMAX :
										best_action = action
										QMAX = QHAT

							next_state, _, end_of_episode, _ = ENV._step(best_action) # take a real step in the environment
							current_state = next_state

						exploratory_action = random.randint(0, self.num_action_vars)
						expert_qvalue = EXPERT.expert_qvalue(current_state, exploratory_action, self.episode_horizon - t)

						print('state: {} action: {} time step: {} expert qvalue: {} index: {}'.format(current_state, exploratory_action, t, expert_qvalue, index + j))
						exploratory_action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
						exploratory_action_vector[exploratory_action] = 1
						state_action_time = np.zeros(self.num_state_vars + self.num_action_vars + 2, dtype = np.int8)
						state_action_time[0:self.num_state_vars] = current_state
						state_action_time[self.num_state_vars:self.num_state_vars+self.num_action_vars+1] = exploratory_action_vector
						state_action_time[self.num_state_vars+self.num_action_vars+1:self.num_state_vars+self.num_action_vars+2] = t
						print('state_action_time: {} index+j: {}'.format(state_action_time, index+j))
						self.X[index + j] = state_action_time
						self.Y[index + j] = expert_qvalue


			self.meta = MODEL_DIR + self.problem + "aggravate" + str(iteration + 1) + ".meta"
			self.ckpt = MODEL_DIR + self.problem + "aggravate" + str(iteration + 1) + ".ckpt"
			dataset_size = NUM_EPISODES * self.episode_horizon * (iteration + 1)

			WR = pd.DataFrame(np.concatenate((self.X[0:dataset_size,:], self.Y[0:dataset_size,:]), axis = 1))
			WR.to_csv(DATA_DIR + self.problem + "aggravate" + str(iteration + 1) + ".csv", index = False, header = None)

			R = Regression(self.X[0:dataset_size,:], self.Y[0:dataset_size,:], self.meta, self.ckpt)
			with tf.Graph().as_default() :
				R.train_network()
				R.test_network(self.X[0:dataset_size,:], self.Y[0:dataset_size,:])


	def run(self) :
		ngraph = tf.Graph()
		with tf.Session(graph = ngraph) as sess :
			model = tf.train.import_meta_graph(self.meta)
			model.restore(sess, self.ckpt)
			X1 = tf.get_collection('X1')[0]
			Y1 = tf.get_collection('Y1')[0]
			YHAT = tf.get_collection('YHAT')[0]

			for episode in range(NUM_EPISODES):
				episode_reward = 0	# epsiode reward
				reward = 0 # step reward
				current_state, end_of_episode = ENV.reset()	# current state and end-of-episode flag
				dummy_qvalue = np.zeros(1, dtype = np.int8)
				tstep = 0
				while not end_of_episode :
					for action in range(self.num_action_vars + 1) :
						action_vector = np.zeros(self.num_action_vars + 1, dtype = np.int8)
						action_vector[action] = 1

						state_action_time = np.zeros(self.num_state_vars + self.num_action_vars + 2, dtype = np.int8)
						state_action_time[0:self.num_state_vars] = current_state
						state_action_time[self.num_state_vars:self.num_state_vars+self.num_action_vars+1] = action_vector
						state_action_time[self.num_state_vars+self.num_action_vars+1:self.num_state_vars+self.num_action_vars+2] = tstep

						QHAT = sess.run(YHAT, feed_dict={X1: np.matrix(state_action_time, np.int8),
							Y1: np.matrix(dummy_qvalue, np.int8)})
						print('action: {} qvalue: {}'.format(action, QHAT))
						if action == 0 :
							best_action = action
							QMAX = QHAT
						elif QHAT > QMAX :
							best_action = action
							QMAX = QHAT

					next_state, reward, end_of_episode, _ = ENV.step(best_action) # next state and step reward
					print('state: {}  action: {}  reward: {} next: {}'.format(current_state, best_action, reward, next_state))
					current_state = next_state
					episode_reward += reward
					tstep += 1

				print('Episode Reward: {}'.format(episode_reward))
				print()


if __name__ == '__main__':
	parser = argparse.ArgumentParser(description=None)
	parser.add_argument('env_id', nargs='?', default='RDDL-v1')
	args = parser.parse_args()

	# Create Environment
	ENV = gym.make(args.env_id)
	ENV.seed(0)


	# Globally used variables are capitalized
	# Run settings
	NUM_EPISODES = 1
	NUM_ACTION_TRIALS = 10
	TRAJECTORY_LENGTH = 3
	NUM_TRAJECTORIES = NUM_ACTION_TRIALS * TRAJECTORY_LENGTH
	MODEL_DIR = "./rddl/models/"
	DATA_DIR = "./rddl/data/"
	ID = "A"

	# Create Agent
	EXPERT = Expert()

	for i in range(1) :
		EXPERT.compute_policy(i+1)
		EXPERT.approximate_policy()
		EXPERT.run()

	NOVICE = Aggravate()
	NOVICE.refine_policy()
	NOVICE.run()

	ENV.close()
