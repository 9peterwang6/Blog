UCR CS177 Modeling And Simulation
=================================

### Lecture 1: Introduction

This course is about modeling via simulation. We may have learned to solve a real world problem by constructing a math model. You may also know about 3D modeling. But why do we need modeling? There are a few reasons:

1.  Design Evaluation: Building a physical and complex system is time-consuming and expensive. So we should determine whether a design works before building it rather than the other way round.
2.  Comparing Numerous Alternatives: Oftentimes there are a lot of possible strategies/methods to solve a problem/complete a task, we want to know which option is the best without trying all the possiblities.
3.  Emulate Dangerous or Impossible Situations: There are scenarios that are too dangerous to try (e.g. testing a war strategy, experimenting a possibly unstable chemical reactions, test safety systems in a nuclear reactor) or impossible to examine in real life (e.g. design a good defense for Quidditch). We need to construct a model to emulate this type of situations.
4.  Change Time Scales: On one hand, some events happen extremely fast (e.g. a car crash, a big bang). We want to slow them down to figure out what happened and why it happened during this entire event. On the other hand, some events happen relatively really slow (e.g. global warming, epidemics, extinction of endangered species). We would like to construct a model to see how things would go if the current situation persists (, which is kind of similar to the next reason).
5.  Predict the Future: We want to use the past experience to predict what is likely to happen in the future so we can prepare for it (e.g. weather forcasting) or make a profit (predicting stock prices, do high frequency trading based on price predictions a few milliseconds into the future).
6.  Cost Savings: It is very difficult to learn to fly aircrafts and newbies may make a lot of mistakes when learning, which may cause catastrophic outcomes. It is better we build a model aircraft and let newbies begin from there. Another example would be practice race driving. It may be costly to practice when prepping for a competition (e.g. Pikes Peak Internation Hill Climb, Formula One, WRC, etc) because you need to customize your race car often and it may not be possible to practice at the real course whenever you want. It is better we build a model, especially a simulation model so that we can not only practice but also try to see which customizations work before actually making the change.

It sounds to me that modeling is good enough for problem solving already. Why do we want to blend in with simulation? Here are a few reasons why we would like to use simulation with modeling:

1.  Evaluate complex models: models are good when you are considering only a handful of objects, but if the number of objects increases and these objects can affect each other, then it becomes extremely difficult to compute the exact solution because you are actually not 100% what is going to happen and what the impact will be to subsequent events (e.g. Dumping a ball onto the ground vs. dumping a full bucket of balls onto the ground. When you dump a full bucket of balls onto the ground, balls may collide with each other, the change of directions may cause new colides.). Simulation will be very helpful here. Essentially we are trying to let everything happen to see how well the model is working intead of mathematically proving the model is working because the model is too complicated.
2.  Hypothese testing: there are cases where the real system may not be available, we would like to predict effects of the change we would like to make on the current system (e.g. changing workload, operating policies).
3.  Validate analytical models: Analytical models require many simplifying assumptions. We can use simulation to test how sensitive the results are to each of those assumptions.
4.  Control extraneous factors: Simluation is useful when you want to compare your models on the exact same situation and see how each of them works. An example is record the workload from one day in a hospital emergency ward and play it back exactly for each scheduling policies or job assignments you want to compare.

Hmm... So we can use simulation to validate/test the model we created. Or we can build a simulation model to solve problems. But are there any drawbacks using simulation? There are and here they are:

1.  Simulation programs can be expensive, time-consuming to develop and run.
2.  Programs can be buggy.
3.  The simulation result is just an estimate. The solution it provides is not exact, meaning that it can change if you re-run the simulation although it may still fall into the pattern you find out. Not seeing something in your simulation does not mean that something cannot happen. It might be a black swan.

After knowing the pros and cons about simulation. We can actually dive into simulation modeling and see what people have done using simulation. You may ask why we do not seem to care about using simulation to validate models. That answer is to validate the model via simulation, we are also constructing a simulation model, but catered to the problem of validating the math model we created.

There are four types of simulation models if we consider the following two factors: (1)Are there factors of randomness? and (2)Is time a factor? Based on answers of the above questions we can categorize the model into:

1.  Deterministic-Static Simulation: no randomness, not time-variant. Example: floating-point arithmetic (used to simulate real number arithmetic on computing systems. Since they are finite they introduce errors. You need to make sure that floating-point arithmetics have the desire precision you want when using it); scale models (an example is scaling down the galaxy to a size that we can display it in a museum. Because the actual galaxy is too big for a museum so we created a simulated galaxy).
2.  Deterministic-Dynamic Simulation: no randomness, time-variant. Example: computational fluid dynamics; finite-element methods (use numerical methods to solve differential equations set, the answer simulates liquid, gas, or structures)
3.  Stochastic-Static Simluation: has randomness, not time-variant. Example: Monte Carlo methods (an example using this method is determing the probability of showing heads in a coin flip. We try flipping a coin for N times and record the number of appearance of heads H, then (H/N) will be the probability of the showing heads in a coin flip. The larger the N is, the more accurate the result will be).
4.  Stochastic-Dynamic Simulation: has randomness, time-variant. Example: Brownian motion; Discret-event stochastic models(random walk). This course will focus on discret-event stochastic models (think of it as a Marcov chain).

An example: The Trained-Flea Experiment. A trained flea stands on a (2n+1) \* (2n+1) chess board (this enviromnemt setting is called system). Initially he stands on the middle square (this is called the initial state). Each time a bell rings, he hops randomly to 1 to 8 adjacent cells (this is called an event). The problem is to find the average number of hops before he falls off the board (this is the experiment, or what we are going to find out using simulation). To simulate the problem is simple, one can write some code to generate a possible path and record the path length. Run this program multiple times and then you will get a estimate of the average path length.

We can actually compare the math modeling and simulation modeling in this problem here by solving this problem. We can first solve a simpler version of this problem: The Trained-Flea Experiment on 3x3 chess board. Because the board is symmetric and that the flea's hopping action is memoryless, meaning that it can revisit a square, we can categorize the squares into three types: corner squares, mid-edge squares, and center. And then we solve this problem iteratively using dynamic programming. We can convert this problem to a finite horizon model with a simple "trick": suppose we ranout of food, so the flea will starve (to death) after his i-th hop. Thus, let a\_i, b\_i, c\_i be the respective average of hops until he falls off the board (or dies) - starting from each square class. We can quickly derive that a\_1 == b\_1 == c\_1 == 1 because the flea is on the board , so he needs at least one hop to fall of the board, and his food is only enough for him to make one hop only. When i is greater than 1, there are following conditions:

1.  If the flea is initially standing on a corner square, then a\_i = (5/8) \* 1 + (2/8) \* (1+b\_i-1) + (1/8) \* (1+c\_i-1) (i > 1)
2.  If the flea is initially standing on a mid-edge square, then b\_i = (3/8) \* 1 + (2/8) \* (1+a\_i-1) + (2/8) \* (1+b\_i-1) + (1/8) \* (1+c\_i-1)
3.  If the flea is initially standing on a center square, then c\_i = (4/8) \* (1+a\_i-1) + (4/8) \* (1+b\_i-1)

We can iterate these equations to eliminate the starvation "trick", the solution is the limit of c\_i as i approaches positive infinity. When i approaches positive infinity, then i ~= i - 1, so we can throw away the subscripts and get the following three equations:

*   a = (5/8) \* 1 + (2/8) \* (1+b) + (1/8) \* (1+c)
*   b = (3/8) \* 1 + (2/8) \* (1+a) + (2/8) \* (1+b) + (1/8) \* (1+c)
*   c = (4/8) \* (1+a) + (4/8) \* (1+b)

Solve the equations using Matlab is a = 2.0571, b = 2.5714, c = 3.3143. And we can expand the method to get a solution for a (2n+1) \* (2n+1) chess board.

Getting the exact solution is easier/faster/cheaper than writing a program to generate large numbers of sample paths. But if you want to add extra elements/restraints (e.g. a flew will not return to a visited square, a flew never choose the same direction twice in a row, or the board is not a square, or we have multiple fleas on the board, etc) to the model, it may be difficult to come up with a sleek solution like what we just did because we may not be able to apply the same techinque we used when a new constraint is added. But we are able to handle these changes when programming the simulation program. This actually gives an edge to the simulation model.

  
  

### Lecture 2: Constructing a Model

Here are some steps we should take when constructing a simulation model:

1.  Formulate the problem and plan the study: figure out what you want to do with the simulation model you want to build (e.g. compare different alternatives, evaluate a strategy in a simulated environment);
2.  Collect data, define a model: here we need to follow the KISS principle: Keep It Simple Stupid;
3.  Test for validity: after coming up with a simulation model, we need to determine whether it captures the key features of the target system we want to simulate. We can do this by describing our model to domain experts, user, and other stake-holders;
4.  Construct the program and "verify" its correct operation: code your simulation model, and check: if your random number generator works correctly, if each random variable follows its chosen probability distribution, if each model component does what it supposed to, and if the "infrastructure" code in your model works fine;
5.  Make pilot runs and validate: make sure your simulation model works as expected. Test your model with boundary cases, test if your model can reproduce the behavior of an existing system with known parameter settings. If no, then go back to step 2 to collect more data snd refine the model. If yes, you can start your experiment;
6.  Design the experiment: there are a few things to keep in mind. You need to decide on an acceptable level of confidence in your conclusions. And you need to think about how to reduce variance in your models.
7.  Make production runs
8.  Analyze the outputs: we need to remember that each output is determined by a bunch of randoms numbers, which means that the result is just an estimate. We must provide confidence intervals for each output value.
9.  Document the process and implement the conclusions

A simulation program should consist of the following components:

*   System State: system state should include the following things:
    *   Entities (customers, resources, etc):
        *   They have attributes such as location, arrival time, service demand. We can define an entity using struct or class in C++
        *   They may belong to groupings of similar entities (e.g. waiting lines). We can use a vector or list in C++ to capture such groupings.
        *   Different entity types may be related (e.g. server and customer). We may use pointers or a dictionary to store such mappings.
    *   Stochastic variables: they are used to represent tntity attributes, event times, etc
    *   Strategies: they are used when comparing different versions of a model, represented by flag variables, separate functions
*   Simulation clock
*   Events: an "atomic action" that updates the system states. Note that carrying out one event often triggers the creation of other events (e.g. each arrival event schedules the next arrival event, a start service event schedules the same customer's end serice event)
*   Event Scheduling: scheduling determines how the system states in the model evolves over time. There are two ways to schedule events: time-driven and event-driven scheduling. As their names entail, time-driven scheduling loops through time and look for events that happen during each step, whereas event-driven scheduling loops uses a priority queue to store the events and go through them one by one, advancing time accordingly. Note that Time-driven scheduling is only useful when the timing of the events are roughly evenly spaced because if we choose a step that is too small we increase the program runtime by increasing the total number of iterations. If we choose a step that is too large we may end up artificially creating simultaneous sequential events which may not make sense.
*   Program instrumentation: Data structures that record information about the simulation model. This is external to the actual model. Speaking of measurements, here are some of the items that you may be interested in tracking:
    *   See if a specific events occur (dam bursts? hospital has no beds?)
    *   Count occurrences
    *   Find minimum or maximum valus
    *   Properties of attribute values (e.g. what fraction of customers wait longer 10 minutes; what is the 90th percentile of customer wait)
*   Report generator: you should have the same piece of code to produce "snap shots" during program execution, the code should be able to compute, tabulate and summarize the instrumentaion. The reason for "snap shots" is that we need to see the long-term trends of the output to find out if the system is actually behaving randomly.

When doing measurements in a simulation model, there are two types of average we may need to compute: time average and population avarage. Time avarage is a weighted average with weight being the lifetime of a specific value. Whereas population average is a weighted average based on population. Here is a very interesting example about time-average and population-average:

*   Suppose lightbulbs suffer from infant mortality problems.There is some kind of manufacturing defect that causes 75% of the lightbulbs to fail after 1000 hours; while the remaining 25% will last for 37000 hours before failure. The population average shows that the average lifetime for a lightbulb is 10000 hours. With population-average you may think that it is acceptable, but when you randomly pick a lightbulb, 75% percent you end up having a defected one. You actually need to buy at least eight lightbulbs at a time to guarantine a approx. 90% chance that you at least buy one normal lightbulb. How can I buy less lightbulbs but maintain the chance that I have a normal lightbulb?
*   To do so, we need to use an extra equipment: the in-store lightbulb display that is used to demonstrate different style of lightbulb's color temperature and brightness. You should be able to find such display in Home Depot. The purchasing algorithm works as follows: 1) Find a box containing a new bulb of the desired style; 2) Swap the new bulb with the coresponding display sample; 3) Purchase the display sample and take it home. How does this in-store display help? We can demonstrate it using time-average.
*   Suppose at time 0, a new sample is placed into the display. Once a sample is installed, its residual lifetime drops to zero at a slope of -1. Each burnt-out bulb is replaced immediately with a new sample so the lightbulb at the display is always on. Suppose I visit Home Depot at a random time, since a good bulb occupies 37 times as much time as a defective bulb, that means more likely the lightbulb at the display is a normal bulb. In fact, even though there are 3 times as much defective bulbs than normal bulbs, we still end up a probability of (0.25 \* 37000) / (0.25 \* 37000 + 0.75 \* 1000) = 0.925. But because I come in at a random time, my display sample will be mid way through its life on average. The average residual lifetime for my display sample is: 0.075 \* (1000/2) + 0.925 \* (37000/2) = 17150 hours, much better than the expected average.
*   A major drawback of this algorithm is that it only works for purchasing one bulb. If you want another bulb, then you may try going to another store, or wait 1000+ hours and return to the same store to try again (and hope nobody else tried your Purchasing Algorithm during that time).

As for population average, there is one type of data we would like to know: the average number of customers in the system at any time. To get this number, one may need to do a scan over the each unit of time to compute the average. But there is a much quicker way to find out this number, if we know the average arrival rate of customers to the system and the average time in system for customers. This is Little's Law: average number of customers in the system = average time in system for customers \* the average arrival rate of customers to the system.

A concrete example is [the gas station example](../supplements/UCR-CS177_GasStationSimulationModel.cpp).

  
  

### Lecture 3, 4, 5: CSIM Programming

This course teaches you how to use a programming package called CSIM from [Mesquite Software](https://www.mesquite.com/).

I think it is better to use examples to learn the components of CSIM. Here are some example programs of CSIM:

*   A compile script provided by the course instructor Professor Mart Molle. Replace the "$\*" with your program: /usr/bin/g++ -DCPP -DGPP -I/usr/csshare/pkgs/csim\_cpp-19.0/lib -m32 $\* /usr/csshare/pkgs/csim\_cpp-19.0/lib/csim.cpp.a -lm
*   [A "Hello World" program](../supplements/UCR-CS177_CSIMHelloWorld.cpp)
*   [The gas station example rewritten in CSIM](../supplements/UCR-CS177_GasStationCSIM.cpp)
*   [An airport shuttle system simulation (one Bus, one terminal and one carlot)](../supplements/UCR0CS177_AirportShuttleSimV1.cpp)
*   [Airport shuttle system simulation version 2 (extends the previous model with multiple terminals)](../supplements/UCR0CS177_AirportShuttleSimV2.cpp)
*   [Airport shuttle system simulation version 3 (extends the version 2 with multiple buses and a sensible strategy to dispatch buses so as to avoid the scenario that one passenger wakes up the entire crew with more than one buses resting)](../supplements/UCR0CS177_AirportShuttleSimV3.cpp)

  
  

### Lecture 6: Review of Probability and Statistics

Probability: a numeric value between 0 and 1 representing how likely an event is going to happen. Having 0 probability means the result is impossible whereas having 1 probability means the result is inevitable. We can determine the probability of an event by two methods:

*   Experimental method: essentially a Monte-Carlo method which conduct many repitions of the experiment and report the proportion that match the chosen result.
*   Non-Experimental method: list all possible outcomes for the experiment, and assgin each outcome a (most likely equal) probability. Then we define the event to be a subset of those outcomes and sum probabilities of the outcomes included in the defined event.

For an event, we can assign each outcome of this event a value to reflect the result triggered by the event outcome. We use a **random variable (r.v.)** to store such values. An r.v. can be of the following two types:

*   Discrete r.v.: Can take only a finite number of distinct values. We use a probability mass function (pmf) to denote the probability of the appearance of each possible value. Note that each function value is greater than or equal to 0 and less than or equal to 1. The sum of every indivial value of this pmf is exactly 1.
*   Continuous r.v.: Can take any real value within some range. In this case, there is an infinite number of possible values so the probability of the apperance of each possible value is 0. But the probability of a value falling in a certain range may not be 0 so we actually focus on finding out this type of probability. This type of probability can be visualized if we can plot the entire valid range of values. On the chart, the probability of a certain range of values is actually how much the area determined by this range of numbers and the axis overlaps with the area determined by the valid range of numbers and the axis. We use integration to compute these areas. So the probability is denoted via the integral of the random variable's probability density function (pdf) f(x). If x is outside of the event's valid range, then f(x) = 0, otherwise f(x) is greater than or equal to 0 (f(x) is NOT A PROBABILITY and there is no hard upper limit for f(x)). The intergral of f(x)dx over its entire valid range is 1.

Since we focus on different things when dealing with each type of random variables. Mathematicians came up with a solution to unify the focus by introducing a cumulative probability distribution function (PDF) F(x). F(x) = P(X less than or equal to x) so now everything is about how much the area determined by (X less than or equal to x) and the axis overlaps with the entire valid range of values and the axis. By convention, pdf is f() and PDF is F(); f\_X() means pdf for r.v. X and F\_X means PDF for r.v. X.

Most systems we care about contain more than one random variables, so we need to consider a joint distribution of all random variables: F\_{X1, X2, ..., Xn}(x1, x2, ..., xn) = P(X1 less than or equal to x1, X2 less than or equal to x2, ..., Xn less than or equal to xn). However, we know very little about the properties of the joint distribution in general. And we actually focus more on the marginal distribution of one of the variables Xj by using repeated integration from negative infinity and positive infinity by every variable except Xj to find F\_Xj(xj).

There is an easier way to find the marginal probability or join probability. If the random variables X1, X2, ..., Xn are mutually independent, then the joint PDF factors into the product of their individual marginal PDFs. One thing to point out is that Xi and Xj do not have causal relationship does not mean that Xi and Xj are independent.

For a random variable X, we can compute the expected value/mean E\[X\] (or mu\_X) and the variance of the variable Var(X):

*   E\[X\] = x1\*f1 + x2\*f2 + ... + xn\*fn if X is discrete.
*   E\[X\] = integral of x\*f(x)dx between a and b if X is continuous ranging from a to b.
*   E\[g(X)\] = g(x1)\*f1 + g(x2)\*f2 + ... + g(xn)\*fn if X is discrete.
*   E\[g(X)\] = integral of g(x)f(x)dx between a and b if X is continuous ranging from a to b.
*   E\[a\*g(X) + b\*h(X)\] = a \* E(g(X)\] + b \* E(\[h(X)\]
*   Var(X) = E\[(X - E\[X\])\*\*2\] = E\[X\*\*2\] - E\[X\]\*\*2 if we expand the former formula.
*   Standard deviation (denoted as sigma) of r.v. is the square root of its variance. The reason to introduce the standard deviation is to make it comparable with the r.v.
*   If we have random variables Xi and Xj, we can compute their convariance Cij = E\[(Xi - E\[Xi\]) \* (Xj - E\[Xj\])\]. If Cij > 0 then Xi and Xj are positively correlated; if Cij = 0 then Xi and Xj are uncorrelated; if Cij < 0 then Xj and Xj are negatively correlated.
*   Cij is not directly comparable with Xi or Xj. To make things comparable, we introduce Correlation cij = Cij / (sigma\_i \* sigma\_j) = Cij / (E\[Xi\] \* E\[Xj\]). The value is never outside the interval -1(opposite) and +1 (identical).

You may wonder how probability theory helps in sumulation models. When a simulation model runs, we can set up checkpoints at different time to record the state of our model. If we repeat the experiment multiple times we get multiple observations and study the states. This process is called a stochastic process. Running a stochastic process should end up having a collection of r.v.s, X\_t1, X\_t2, ... with:

*   A common sample space: each r.v. must take its values from the same set of choices.
*   Indexed by time.

If X\_ti and X\_tj are mutually independent, then the process is memoryless (Monte-Carlo Method, independent and identically distributed (i.i.d.) r.v.s). If otherwise then the process has memory, which means X\_ti may influence X\_tj if ti is less than tj (Markov Chain). For the latter, we may end up having an equilibrium state. Please note that X\_t1, X\_t2, ... may have different distribution that can still produce a common sample space. If for each r.v.s in a random the process the expected value is the same regardless of their distribution, then the process is stationary. If the covariance between r.v.s are the same, then the process is covariance stationary.

  
  

### Lecture 7: Confidence Intervals

In the previous lecture we talked about stochastic processes. Let's consider the a stochastic process with n i.i.d.r.v.s X1, X2, ..., Xn. The distribution of Xi has a finite theoretic mean mu and a finite theoretic variace sigma\*\*2. We are not sure about the value of neither mu nor sigma, and we would like to run this stochastic process to find estimates of mu and sigma.

After running the process, we obtain an observation for each r.v. x1, x2, ..., xn. To find the estimate of mu, we simply compute the arithmetic average of these n observations. Denote this value as avg(Xi, n) = sum(xi, n)/n where xi is an observation value of Xi. To find the estimate of sigma\*\*2, instead of using avg((Xi - avg(Xi, n))\*\*2, n) = sum((xi - sum(xi, n)/n)\*\*2, n)/n, we use sum((xi - sum(xi, n)/n)\*\*2, n)/(n - 1) to estimate the sigma\*\*2. Doing this we will have E\[sum((xi - sum(xi, n)/n)\*\*2, n)/(n - 1)\] = sum((E\[Xi\] - sum(E\[Xi\], n)/n)\*\*2, n)/(n - 1) = sigma\*\*2, making it an unbiased estimate. The course instructor has his perspective. When n = 1, sigma\*\*2 = 0. This is correct because it tells you that variability is impossible with only one outcome. When n = 1, your variance estimate gives you a zero divide exception, which tells you that you cannot observe variability with one sample.

One thing I would like to point out is that repeat a stochastic process with one random variable X1 n times is equivalent to running a stochastic process n i.i.d.r.v.s X1, X2, ..., Xn. The latter is formally used in textbooks but it is essentially the same thing as the former in my opinion.

One way or another, when n approaches positive infinity, your sample mean approaches mu. Formally, that means P(limit(n->+inifinity, avg(X, n))) = 1 for X whose values are from any distribution with n i.i.d. samples (be it an observation of X1, X2, ..., Xn or n observations of X1). This is the Strong Law of Large Numbers.

There is another fundamental and useful law in Statistics: the Central Limit Theorem (CLT). It states that if the value of random variable X is from a distribution with finite mean mu and finite variance sigma\*\*2, we can define (but not compute, because mu and sigma\*\*2 are unknown) a random variable Z = (avg(X, n) - mu) / sqrt(sigma\*\*2/n) such that as n approaches positive infinity, the value of Z will come from a distribution more and more similar to N(0, 1), which is the "standard normal" distribution with zero mean and unit variance.

We can use the CLT to estimate the parameters of the disribution that produces values of random variable X. What makes this estimation special is that we can guarantee how accurate the estimation can be, which means we can determine a range with some accuracy rate that the actual parameter value will fall within the range. This range is called confidence interval. Here is how we can compute the confidence interval:

*   Suppose we have a collection of n i.i.d samples from a random variable X (or an observation for i.i.d.r.v.s X1, X1, ..., Xn). Here we don't know the mu and sigma\*\*2 of the distribution that X has but we know they are finite. Our goal is to find the confidence interval for mu.
*   Compute sample\_mean = avg(X, n) and sample\_adjusted\_variance sum((xi - sum(xi, n)/n)\*\*2, n)/(n - 1) and choose Type One Error probability alpha. Type One Error means failing to tell something is right when it is right. There is another type of error called Type Two Error which means failing to tell something is wrong when it is wrong. The value of alpha is usually 0.95 or 0.99.
*   Recognize that degrees of freedom v = n - 1, and look up the t-distribution values table for t\_{v, 1 - alpha/2}.
*   Then we know that interval \[sample\_mean - t\_{v, 1 - alpha/2} \* sqrt(sample\_adjusted\_variance / n), sample\_mean + t\_{v, 1 - alpha/2} \* sqrt(sample\_variance / n)\] fails to include mu with probability alpha. Which means that (1 - alpha) of the time mu should fall within our confidence interval.
*   If the variance of the distribution is known, then we will use the Standard Normal Distribution (denoted as z). And the confidence interval becomes \[sample\_mean - z\_{alpha/2} \* sqrt(sigma\*\*2/n), sample\_mean + z\_{1 - alpha/2} \* sqrt(sigma\*\*2/n)\].

The above steps to compute the confidence interval is often used in Hypothesis Testing: We are given a collection of n i.i.d samples from a random variable X (or an observation for i.i.d.r.v.s X1, X1, ..., Xn), and we don't know the mu and sigma\*\*2 of the distribution that X has but we know they are finite. Someone has claimed the Null Hypothesis H0 that mu = mu0. Can we refute this claim? Here Null Hypothesis means something that needs to be investigated to tell if it happens due to randomness. There is an Alternaive Hypothesis which is the exact opposite of your Null Hypothesis. Most often we would like to refute the Null Hypothesis to show that we have findings that are not happening by chance. Here is how we do it:

*   Compute sample\_mean = avg(X, n) and sample\_adjusted\_variance sum((xi - sum(xi, n)/n)\*\*2, n)/(n - 1) and choose Type One Error probability alpha.
*   Recognize that degrees of freedom v = n - 1, and look up the t-distribution values table for t\_{v, 1 - alpha/2}.
*   Compute (sample\_mean - mu0) / sqrt(sample\_variance / n)
*   If abs((sample\_mean - mu0) / sqrt(sample\_variance / n)) > t\_{v, 1 - alpha/2} then we can reject the Null Hypothesis at significance level alpha. That means (1-alpha) of the time mu0 does not fall within the confidence interval of mu. Otherwise we cannot reject the Null Hypothesis, that means we are not sure. Note that a Hypothesis Testing is subject to both Type One Error (by probability alpha) if we can reject the Null Hypothesis and Type Two Error (by an unknown probability delta) if we cannot reject the Null Hypothesis.

When we write a program to compute the sample mean and sample variance, we notice that if we use the naive formulas mentioned above to compute the sample mean, we only need to read each sample once (one-pass), whereas we need to read each sample twice when we want to compute the sample variace using the naive formula (two-passes). Two passes are bad for large number of samples because we need to store all of them somewhere to retrieve it during the second pass. We can rewrite the naive formula to so that sample\_variance = sum((xi - sum(xi, n)/n)\*\*2, n)/(n - 1) = (sum(x\*\*2, n) - n \* (sum(x, n)/n)\*\*2) / (n - 1). But when sum(x\*\*2, n) is very close to n \* (sum(x, n)/n)\*\*2 and sum(x, n)/n is large in absolute value, we will end up losing many signification digits and thus the result has a large error. [Plant Math](https://planetmath.org/onepassalgorithmtocomputesamplevariance) has a one-pass algorithm to compute sample variance. The key here is to use the sample mean and the sample variance for the first m numbers and update the sample mean and sample variance after reading the next input:

1.  Let sample\_mean\_m = sum(xi, m)/m and distance\_m = sum((xi - sample\_mean\_m)\*\*2, m). They are known numbers that can be computed and updated starting from m = 1.
2.  Read x\_{m+1}.
3.  Compute delta = x\_{m+1} - sample\_mean\_m.
4.  Compute sample\_mean\_{m+1} = sample\_mean\_m + delta/(m+1).
5.  Compute distance\_{m+1} = distance\_m + (x+{m+1} - sample\_mean\_{m+1}) \* delta.
6.  When there is no sample left, output sample\_mean\_m and distance\_m/(m-1).

  
  

### Lecture 8 & 9: Choosing Input Distributions And Goodness of Fit

A stochastic simulation program must have some variables whose values are "randomly generated". How to choose distributions for these variables?

1.  Using a priori knowledge (e.g. symmetric events).
2.  Try a normal distribution if the value is the sum (or average) of large numbers of independent elements. An example: raw scores (sum of marks of each question) in a class with large numbers of enrolled students.
3.  For inter-arrival times, use Poisson distribution.
4.  If you only know about the minimum and maximum values of the variable. Use a uniform distribution. This should be the last resort.
5.  If you can collect empirical data, and ou cannot find one distribution that is a good fit, you may need to construct an empirical distribution. But normally, you can plot the distribution of the data you collect and look for theorectical distributions that best match the properties of the dataset (be it observed or prior knowledge). Then use the empirical data to fit parameters for the chosen distribution via Maximum Likelihood Estimation (MLE). The last step is to validate if the distribution fits well with the empirical data via a goodness-of-fit test.

MLE process:

1.  Obtain data.
2.  Generate a set of possible parameter values.
3.  Construct the likelihood function L: L(theta;x1, ..., xn) = f(x1, x2, ..., xn | theta) = f(x1|theta) \* f(x2|theta) \* ... \* f(xn|theta), f is the pdf of the distribution.
4.  The theta that maximizes L is the MLE of the distribution parameter.

To validate if the consturcted distribution fits well with the empirical data, we mainly use the following two methods: Quantile-Quantile Plots (aka Q-Q Plots) and Chi-squared Test.

Steps to draw Q-Q Plots:

1.  Determine a way to compute quantile based on the size of the empirical dataset.
2.  Compute the quantile for each value of the empirical dataset.
3.  Use your constructed theoretical distribution and generate data points from within the same range of the empirical data.
4.  Compute the quantile for each value of the generated dataset.
5.  Plot the Quantile-Quantile Plot, each point (x\_i, y\_i) is the data point from the two datasets having the same quantile, x\_i is from the empirical dataset and y\_i is from the theorectical distribution.

To compute the quantile, one can use the following ways:

*   Method 1: Sort the data ascendingly and index them. The index value / size is the quantile value. Use this method when the size of the empirical dataset is small. One can generate from the theorectical distribution a dataset of the same size and sort it ascendingly so that having the same index value means having the same quantile value.
*   Method 2: Compute percentile because we know that a% quantile = a-th percentile. Use this method when the size of the empirical dataset is large.

If the two distributions are identical, then we will get a straight line that passes through the origin and has a slope of 1; If the rwo distributions only differ by a location parameter (b as in a\*x + b), then we get a straight line with slope 1 that does not pass through the origin; If the two distributions differ only by a scale parameter (a as in a\*x +b), then we get a straight line whose slope is not 1; Otherwise we end up not having a straight line.

Steps to perform a Chi-squared Test:

1.  Start with your set of raw observations X\_1, ..., X\_n.
2.  Choose (k - 1) movable cut points to partition the x-axis into k bins: \[-infinity, a\_1), \[a\_1, a\_2), ..., \[a\_{k-1}, +infinity).
3.  Count the number of samples that fall within each bin to obtain \[N\_1, N\_2, ..., N\_k\], where sum(\[N\_1, N\_2, ..., N\_k\]) = n.
4.  Calculate the probabilities of hitting each bin for your theorectical distribution as p\_j = F\_theta(a\_j) - F\_theta(a\_{j-1}). F is the CDF of your theorectical distribution. Assume a\_0 = -infinity and a\_k = +infinity.
5.  Find the computed Chi-squared statistic for your dataset: chi-squared\_{computed} = \[(N\_1 - n \* p\_1) \*\* 2 / (n \* p\_1)\] + ... + \[(N\_k - n \* p\_k) \*\* 2 / (n \* p\_k)\].
6.  Find chi-squared\_{k-1, 1-alpha} from the tabulated distribution, where: 1) (k-1) is a rwo index in the table, representing the degrees of freedom. 2) (1-alpha) is a column index representing Type One Error probabilities.
7.  Reject a match with confidence level alpha if chi-squared\_{computed} > chi-squared\_{k-1, 1-alpha}.

  
  

Steps to do a simulation:

1.  Come up with something on which you want to run a simulation.
2.  Construct a simulation model and validate it.
3.  Choose a distribution for each random variable in the simulation model.
4.  Run the model a few times, compute the confidence interval for the model output.
5.  Analyze the model output.