objects = main.o mainwindow.o bayesgraph.o bayesdata.o

bayes : $(objects)
	g++ $(objects) -o bayes `pkg-config gtkmm-3.0 --libs`

main.o : main.cc mainwindow.hh bayesdata.hh
	g++ main.cc -c -o main.o `pkg-config gtkmm-3.0 --cflags`

mainwindow.o : mainwindow.cc mainwindow.hh bayesgraph.hh
	g++ mainwindow.cc -c -o mainwindow.o `pkg-config gtkmm-3.0 --cflags`

bayesgraph.o : bayesgraph.cc bayesgraph.hh
	g++ bayesgraph.cc -c -o bayesgraph.o `pkg-config gtkmm-3.0 --cflags`

bayesdata.o : bayesdata.cc bayesdata.hh
	g++ bayesdata.cc -c -o bayesdata.o `pkg-config gtkmm-3.0 --cflags`

.PHONY : clean

clean :
	-rm bayes $(objects)