FractalsApp 1.0
Author: Grant Wehrli
The program is a simple program to render the mandelbrot set in the ppm image format.
The usage is simple, type in the domain and range of the desired render, and then chose the desired
iterations and the resolution. 

Examples: 
-2
2
-2
2
512
512
512
render1

-0.750
-0.760
0.095
0.105
1024
1000
1000
render2

The pictures are located in /Fractals/examples.

I recommed not going above 4000x4000 images as any larger takes a very long time, and 1024 maximum
iterations as a limit. It will render, but is not nessecarry unless you zoom to a tiny part.

I use http://paulcuth.me.uk/netpbm-viewer/ to view and download images, as PPM is not supported by
default on windows.
