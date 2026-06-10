# Mini-Project-ACP
A lightweight, object-oriented 2D ASCII graphics editor in C. Supports drawing, moving, and deleting shapes in the console using rasterization algorithms.

run command in terminal to compile and execute the program:
gcc ACP-MINI-PROJECT.c -o ACP-MINI-PROJECT_v2 && ./ACP-MINI-PROJECT_v2

Test case:
clear the canvas after drawing a shape to draw another shape
1. Line Test Case: 
Menu Choice: 1 (Add Shape)
Type: 1 (Line)
Row Col: 10 10 (Starts at row 10, column 10)
Width: 20 (Draws 20 characters across)
Height: 0 (Keeps the line perfectly horizontal)
End Result: A horizontal line from column 10 to 30 on row 10.

2. Rectangle Test Case:
Menu Choice: 1 (Add Shape)
Type: 2 (Rectangle)
Row Col: 5 15 (Top-left corner at row 5, column 15)
Width: 30 (Extends to column 45, well within the 60 max)
Height: 15 (Extends to row 20, well within the 30 max)
End Result: A nicely proportioned 30x15 box.

3. Circle Test Case:
Menu Choice: 1 (Add Shape)
Type: 3 (Circle)
Row Col: 15 30 (The exact center of your 30x60 grid)
Width (Radius): 10 (Extends out to row 5/25 and col 20/40)
Height: 0 (Not needed for a circle)
End Result: A large, centered circle with 5 rows/10 columns of padding on all sides.

4. Triangle Test Case:
Menu Choice: 1 (Add Shape)
Type: 4 (Triangle)
Row Col: 10 30 (Starting at row 10, column 30)
Width (Base): 15 (Base width of 15 characters)
Height: 12 (Drops down to row 22)
End Result: A triangle that fits comfortably in the lower-middle half of the screen.

click on exit(7) to exit the program.