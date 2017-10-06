# mandelbrot_distributed_computing
Erzeugen von Mandelbrot-Fraktalen mithilfe von einem Raspberry Pi Cluster

## Was?
Es werden mehrere Raspberry Pi's geclustert. Jeder Raspberry Pi bekommt ein Teilbild zu berechnen.
Am Ende wird das Teilbild zusammengefügt. 

## Wie?
Das Mandelbrot-Fraktal wird mithilfe eines eigen programmiertem Mandelbrot-Renderer (C++) erzeugt. Mithilfe von MPI (Message Passing Interface) wird das Cluster realisiert.

## Von
Jonas Tejada Heidenhain
Adrian Reuter
