unitree [("A", 2), ("B", 6), ("C", 2), ("D", 4),("E", 5), ("F",2), ("G",2)] [3,1,0,0,2,0,0]

the array on the right indicates how many children the departments have, respectively

the tree is like this:

```md
	A
	├── B
	│   └── C
	│
	├── D
	│
	└── E
	    ├── F
	    └── G

```


to give a simple example, i will remove the numbers in brackets:

`unitree [("A"), ("B"), ("C"), ("D")] [2,1,0,0]`

A is parent of B and D

B is parent of C.
