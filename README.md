# ht-mcrl2-gen

Generates mCRL2 model of a d-dimensional communication grid connected in a hypertorus


Description:
------------

mCRL2 [1] is a formal specification language with an associated toolset. The toolset can be used for modelling, validation and verification of concurrent systems and protocols. It can be run on Windows, Linux, Apple Mac OS X and FreeBSD. 

ht-mcrl2-gen generates mCRL2 model of a d-dimensional communication grid connected in a hypertorus as described in [1,2], ports' buffers removed. 

There is a d-dimensional square grid of size k. In each grid node a packet switching (and computing) device is situated which works in full duplex mode based on store-and-forward principle with its ports situated on facets of a unit-size hypercube. In each dimension, the opposite facets of the obtained k x k x ... x k hypercube are connected to create a closed structure of a hypertorus.

The model represents a state-of-art balance of simplicity and descriptive power. It allows us to recognize deadlocks characteristic to the transmission principle "store-and-forward" without considering the packet structure and the queue discipline. It uses nondeterministic forwarding decision (independent of the destination port availability) and sectioned structure of the internal buffer; a section counts packets forwarded to the corresponding port. 

Please, consult ht2d3k1p2b.pdf and ht2d4k1p2b.pdf for pictures of the 2-dimensional grid Petri net model.

mCRL2 [1] implements fast search of deadlocks allowing us to handle rather bulky models of multidimensional grids.


Command line formats:
--------------------

>ht-mcrl2-gen d k p b > ht.mcrl2


Parameters:
-----------

d   number of dimensions;

k   size of grid;

p   number of packets in the first buffer section;

b   buffer size limitation (p<=b).


Output (file) format:
---------------------

.mcrl2 is a plain-text file containing a model in the mCRL2 language as specified on https://mcrl2.org


Tools to analyze generated models:
----------------------------------

mCRL2 [1] toolset: ``mcrl22lps`` - linearization of the model; ``lpssim`` - simulator; ``xsim`` - simulater with GUI; ``lps2lts`` - generates a labelled transition system from a linear process using a state space generator; ``ltsview`` - visualise a labelled transition system using a 3D view etc 


An example:
-----------

>ht-mcrl2-gen 2 4 1 2 > ht2d4k1p2b.mcrl2

- generate a model of a square grid of size 4 with closed opposite edges (surface of torus); each device contains 1 packet forwarded to the first port, the buffer size limitation is 2;

>mcrl22lps -v ht2d4k1p2b.mcrl2 ht2d4k1p2b.lps

- linearise the model to obtain a Linear Process Specification saved in .lps file;

>lps2lts -D -vrjittyc -sr ht2d4k1p2b.lps -t1

- create the state space using depth first search until the first deadlock is found.


References:
-----------

1. J.F. Groote, M.R. Mousavi. Modeling and analysis of communicating systems. The MIT press. 2014. https://mcrl2.org

2. Dmitry A. Zaitsev, Ivan D. Zaitsev and Tatiana R. Shmeleva. Infinite Petri Nets: Part 1, Modeling Square Grid Structures, Complex Systems, 26(2), 2017, 157-195. http://wpmedia.wolfram.com/uploads/sites/13/2018/02/26-2-4.pdf

3. Dmitry A. Zaitsev, Ivan D. Zaitsev and Tatiana R. Shmeleva. Infinite Petri Nets: Part 2, Modeling Triangular, Hexagonal, Hypercube and Hypertorus Structures, Complex Systems, 26(4), 2017, 341-371. http://wpmedia.wolfram.com/uploads/sites/13/2018/04/26-4-3.pdf


-------------------------------------------------------------
2018 Jan Friso Groote & Dmitry Zaitsev & Tim Willemse, tue.nl
-------------------------------------------------------------

