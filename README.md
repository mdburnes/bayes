# Requirements to compile on Linux

+ gcc -- the gnu compiler suite
+ make -- for running the makefile
+ pkgconf -- for providing command line in the makefile
+ gtkmm3 -- c++ bindings for GTK3.
  + gtk3 -- a requirement of gtkmm3

# Bayes theorem component names

+ P(H|E) = posterior probability
+ P(H) = prior probability
+ P(E|H) = likelihood
+ P(E) = evidence

# Bayes theorem

P(H|E) = P(E|H)*P(H) / P(E)

The problem is that we might not---and probably won't---be given all the evidence that we need in the denominator. For that, let's add a few more terms to allow us to caluclate P(E).

# More useful terms

P(¬H) = not the probability = 1 - P(H)
P(E|¬H) = evidence found in P(¬H) = false positives

# Bayes theorem expanded

P(H|E) = P(E|H)*P(E) / ( P(E|H)*P(E) + P(E|¬H)*P(¬H) )
