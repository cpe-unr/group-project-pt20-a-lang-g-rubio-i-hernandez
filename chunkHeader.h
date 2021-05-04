#ifndef CHUNK_HEAD_H
#define CHUNK_HEAD_H
/**
 * A generic chunk header which only includes the name of the chunk and it's size
 */
  
typedef struct generic_chunk{
	char* title[4];
	int size;
};
#endif //CHUNK_HEAD_H	
