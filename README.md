# FDF Project
## Overall overview
FDF is the first project on the graphical branch at 42. The program takes a map as a parameter and draws 3D representation.
You can rotate image around 3 axis with keyboard and mouse, change color style and change types of projection. All 
transformations are done with simple functions described in rotate.c and transform.c files without matrixes. Colors 
slowly change to the next point's color. Also if map contains a specific color for a point it handles it correctly.
Please use a menu on the left for additional information.
![](https://user-images.githubusercontent.com/39954654/61400434-e7fc8880-a8d8-11e9-84e3-a05ed7d4b76e.png)
## Credits
Greetings [to this guy](https://github.com/TheWeaklessOne) who helped me improve performance and add new features.
## Useful links
1. [man mlx](http://files.achedeuzot.me/42/mlx/man/)
2. [Key hooks codes for Mac](https://drive.google.com/file/d/0BwSwmEmxrHCeSmZiVjZjR3FuV0k/edit)
3. [Bresenham line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
## Installation
```
make
./fdf some_map.fdf
```
Works on Mac and Linux.
