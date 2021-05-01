main: main.cpp wav_reader2.o
	g++ -std=c++11 main.cpp wav_reader2.cpp -o main
	
wav_reader.o: wav_reader2.cpp wav_reader.h
	g++ -std=c++11 wav_reader2.cpp -c
	
clean:
	rm *.o
