# Cells:
(0,0)=0   (0,1)=1   (0,2)=2   (0,3)=3
(1,0)=4   (1,1)=5   (1,2)=6   (1,3)=7
(2,0)=8   (2,1)=9   (2,2)=10  (2,3)=11

Virtual nodes:
LEFT = 12
RIGHT = 13

If (0,0) is active, union(0, LEFT).

If (1,3) is active, union(7, RIGHT).

If later find(LEFT) == find(RIGHT) → means some chain of active cells connects a left wall cell to a right wall cell.
