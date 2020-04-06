PereiroJose_Resultados_hw3.pdf: Trayectoria.jpg PereiroJose_Resultados_hw3.tex
	pdflatex PereiroJose_Resultados_hw3.tex 
Trayectoria.jpg: PereiroJose_ODE.cpp PereiroJose_PDE.cpp PereiroJose_plots_hw3.py
	c++ PereiroJose_ODE.cpp
	./a.out > datos_primer_punto.txt
	rm a.out
	c++ PereiroJose_PDE.cpp
	./a.out init.dat > datos_segundo_punto.txt
	rm a.out
	python3 PereiroJose_plots_hw3.py