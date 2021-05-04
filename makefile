main: main.cpp wav_reader2.o
	g++ -std=c++11 main.cpp wav_reader2.cpp -o main
	
wav_reader.o: wav_reader2.cpp wav_reader.h
	g++ -std=c++11 wav_reader2.cpp -c
NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -std=c++11 NoiseGate.cpp -c
Normal.o: Normal.cpp Normal.h
	g++ -std=c++11 Normal.cpp -c
Echo.o: Echo.cpp Echo.h
	g++ -std=c++11 Echo.cpp -c
cvs.o: cvs.cpp cvs.h
	g++ -std=c++11 cvs.cpp -c
Processor.o: Processor.cpp Processor.h
	g++ -std=c++11 Processor.cpp -c
mylib.a: mylib.o
	ar suvr mylib.a Processor.o Normal.o Echo.o NoiseGate.o

	
clean:
	rm *.o main
