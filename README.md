# fract_ol
Graphic project (School 21/Ecole42). Using MiniLibX graphics library.
Fractal exploration program.

![Julia's fractal](https://github.com/kclassie/fract_ol/blob/main/img/Julia.png)

## USAGE:
______________________________________________
To run the program enter: ./fractol <name of fractal>[(float)k1 (float)k2]
where k1, k2 - the parameters for Julia fractal (from -1 to 1)
default values: [-0.4, 0.6]).
______________________________________________________
List of available fractals:
* Mandelbrot
* Julia
* Burning_Ship.
______________________________________________________
- Press ARROWS to move the image.
- Scroll UP and DOWN to zoom the fractal.
- Press C-key to change the palette.
- For exit press ESC or close the window.
  
![Mandelbrot's fractal](https://github.com/kclassie/fract_ol/blob/main/img/Mandelbrot.png)  

The code follows 42's strict norms:

- Functions must not exceed 25 lines
- Max 5 functions in a .c file
- Cannot stick variable declaration and initialization on the same line
- Max 5 variables per block
- Max 4 parameters per function
- Forbidden keywords: for, do ... while, switch, case, goto
- Only existing C functions exit, open, close, write, read, malloc, free, and the functions of minilibx (libmlx) and math.h are allowed. Although other functions may be used in bonus features. Image export in this project's case used fopen, fwrite & fclose.

![Fractal Burning Ship](https://github.com/kclassie/fract_ol/blob/main/img/Burning_Ship.png) 
  
