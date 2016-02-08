# SearchAlgorithmExercise
An implementation of BFS, DFS and A* search with topic of 24 points game, good for understanding the algorithm, not a good pr example, and some states are missed.

To compile:

    $ cd /[PATH_TO_THIS_DIRECTORY]/ 
    $ make

Problem Representation(shittiest part):
  Each state holds a number selected from the pool of 4 numbers(actually implemented with current expression hold in state, dumb), and an array for recording unused numbers.
  With four arithmetic operators replaced with value 0-3 representing + - * and /.
  The initial state is a single number with rest 3 numbers in the unused numbers array.
  
  Advantage(are you kidding?): have a certain deep of 4
  Drawbacks: 
  
    Need extra storage and computability to avoid repetitive states and increased the time the whole program cost. Fortunately that repetitive states won't cause a infinite loop.
    Can't cover the situation of (A*B)+(C*D)
    
Result:
  
  Deep first search beats A* search(LOL) beats breath first search.
  
  Reason:
  
    Simple heuristic function.
    Meaningless to add total cost into calculating fitness.
    All branches will come to an end at depth of 3.
    
Tech spec:

  A tree structure for SearchTree class
  A priority queue for Fringe class(first time implementing priority queue, didn't think of it to be such easy, Yay!)
  Put Node as an individual class as we have to put it into our fringe, and each instance holds an instance of the class, State.
  
I'm just a dumb CS student, don't be too hard on me.
[[逃
