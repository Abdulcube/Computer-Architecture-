#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//I used a cache pointer that consists of multiple block pointers, mimicking an array.
//the cache is considered the structure **block.
typedef struct block{
int status;
unsigned long int tag;
//The blocks consists of time, tag, and status.


unsigned long int time;
}block;


unsigned long int inc;
//hits or miss
int memoryWritten, finalM;
int contin;
int lpp, loop;
/*Cache report:


A couple of string chars are present, to manipulate the inputs.
The first pointer of the cache points to a certain number of sets, while the second pointer points to the blocks.
Tag is the respective tag of the of the block.
Status refers to whether or not there is a tag present in the the set.
To find a tag that is necessary in the set, placing the set index in the first setarray, and the tagindex in the second set array, finds the tag.
The prefetcher changed the final and misses ratio greatly. Because more memory is present in the cache, the probabilty of a final is extremely higher and reflects on the ratio of finals and misses. The reads has increased though because, with a prefetch there must be a larger memory read for each memory prefetched.*/
char * abd;
int final, memoryREAD;
/*  for(int k = 0; k < setnum; k++){
     for(int i = 0; i < intnum; i++){
         printf("%lf\t", [k][i]);
     }
      printf("\n");
  }

}
*/
struct block** cache;
struct block** preCache;

block** create(int setnum,int assoc){
  //Allocate the memory for the cache
  cache=(block**)malloc(setnum*sizeof(block*));
  //allocate the memory for each block
  for(int firstSection=0;firstSection<setnum;firstSection++){
       cache[firstSection]=(block*)malloc((assoc)*sizeof(block));
  }
  //set each status to zero
  for(int firstSection=0;firstSection<setnum;firstSection++){
       for(int dual=0;dual<assoc;dual++){
         cache[firstSection][dual].status=0;
       }
  }
return cache;
}

block** createPre(int setnum,int assoc){
  preCache=(block**)malloc(setnum*sizeof(block*));
  for(int firstSection=0;firstSection<setnum;firstSection++){
       preCache[firstSection]=(block*)malloc((assoc)*sizeof(block));
  }
  for(int firstSection=0;firstSection<setnum;firstSection++){
       for(int dual=0;dual<assoc;dual++){
       //Tag is the respective tag of the of the block.

         preCache[firstSection][dual].status=0;
       }
  }
return preCache;
}


//help methodss------------------------------------------------------------

void plz(int assoc, unsigned long int indTN, unsigned long int indSN){
lpp=0;
	while(lpp<assoc){
  int low=0;
      if (preCache[indSN][lpp].status!=0 && preCache[indSN][lpp].tag==indTN){
           return;
      } else if( preCache[indSN][lpp].status!=0 && (assoc-1)==lpp){
        memoryREAD++;
        contin++;
        low=0;
        loop=0;
        	while(loop<assoc){
          if(preCache[indSN][loop].time<=preCache[indSN][low].time){
            contin=loop;
            low=loop;
          }
          loop++;
        }
        inc++;
        preCache[indSN][low].tag=indTN;
        preCache[indSN][low].time=inc;
        contin++;

        preCache[indSN][low].status=1;

        return;

      } else if (preCache[indSN][lpp].status==0){
        preCache[indSN][lpp].status=1;
        contin--;
        preCache[indSN][lpp].tag=indTN;
        contin++;
        inc++;
        preCache[indSN][lpp].time=inc;
        memoryREAD++;
      return;
    }
    lpp++;
}
return;
}


//
/*  char j[1000];
  char opp;
  unsigned long long int add;
  fscanf(doc,"%s ", j);
//printf("j: %s\n", j);
//printf("%lu\n",sizeof(add) );

  while(strcmp("#eof",j)!=0){
  fscanf(doc, " %c %lx", &opp, &add);

    fscanf(doc,"%s ", j);

  }
}
*/
int main(int argc, char** argv){
  if(argc!=6){
    printf("error\n");
    return 0;
  }
  /*for(int x=0;x<7;x++){

  }*/
  //the original address
  unsigned long int address;
  //the new address

  //size of cache
  int cSize=atoi (argv[1]);
  //assoc
  char* associativity =argv[2];
  char* policy =argv[3];
  int bSize=atoi(argv[4]);
  int setnum=-1;
  //tag index
  unsigned long int indT, indS, sMKK;
  // set index
  char toRreira;

  //the mask of the set
  //prefetch index for tag
  //prefetch index for set
  //unsigned long int blockmask;
char filename[strlen(argv[5])];
  FILE* doc;
  abd=argv[5];
  strcpy(filename,abd);
  doc=fopen(argv[5],"r");
  if(doc==NULL){
    printf("error\n");
    //return 0;
  }

  //printf("mer43423454354543rrr\n");
/*  int cSize=atoi (argv[1]);
  char* associativity =argv[2];
  char* policy =argv[3];
  int bSize=atoi(argv[4]);

  FILE* doc;
  doc=fopen(argv[5],"r");
  if(doc==NULL){
    printf("error2 %s\n", argv[5]);
    //return 0;
  }

  char subbuff[6];
  if(strlen(associativity)> 6){
    int length=strlen(associativity)-6;
    char merr[length+1];
    memcpy( merr, &associativity[6],length );
    merr[length] = '\0';
    assoc=atoi(merr);
    sNum=cSize/((bSize)*assoc);

  }
  if(strcmp(associativity, "assoc") == 0){
    assoc=0;
    sNum=0;
  }*/
  char subbuff[6];
memcpy( subbuff, &associativity[0], 5 );
subbuff[5] = '\0';
  if ((strcmp(associativity, "direct") != 0) && (strcmp(subbuff, "assoc") != 0)) {
    printf("error\n");
    return 0;
  }
  if (strcmp(policy, "fifo") == 0|| strcmp(policy, "lru") == 0){
  } else {
    printf("error\n");
    return 0;
  }
//printf
//printf("mer444444rrr\n");
char firstChar=associativity[0];
  int assoc=-1;
  contin=assoc;
  if(firstChar=='d'){//direct map
  assoc=1;
  setnum=cSize/bSize;
}else if(strcmp(associativity, "assoc") == 0){//fullassoc
    setnum=1;
    assoc=cSize/bSize;
  }else{//n way associat chache
      int length=strlen(associativity)-6;
      char merr[length+1];
      memcpy( merr, &associativity[6],length );
      merr[length] = '\0';
      assoc=atoi(merr);
      setnum=cSize/bSize/assoc;
    }
int b=log(bSize)/log(2);
  cache=create(setnum,assoc);
  contin++;

int s=log(setnum)/log(2);
//setmask
  sMKK=((1<<s)-1);
  //char j[1000];
    char* wop=policy;
//first mem
    fscanf(doc,"%s", wop);
    //clear();


  while(strcmp("#eof",wop)!=0){
    fscanf(doc, " %c %lx", &toRreira, &address);

    indS = ( address >> b ) & sMKK;
    wop=abd;
    contin++;

    indT = address >> ( b +s );

      if(toRreira=='W'){
        lpp=0;
				while(lpp<assoc){
          int low;


            if(cache[indS][lpp].tag==indT && cache[indS][lpp].status!=0){
              final++;
              memoryWritten++;
              break;
            } else if((assoc-1)==lpp && cache[indS][lpp].status!=0){
              finalM++;
              memoryREAD++;
              memoryWritten++;
              low=0;
              
              loop=0;
        			while(loop<assoc){
                if(cache[indS][loop].time<=cache[indS][low].time){
              low=loop;
                }
                loop++;
              }
          //
              cache[indS][low].status=1;
              inc++;
              cache[indS][low].tag=indT;
              cache[indS][low].time=inc;
              break;

          } else if (cache[indS][lpp].status==0) {
            cache[indS][lpp].status=1;
            contin++;
            cache[indS][lpp].tag=indT;
            cache[indS][lpp].time=inc;

              finalM++;
              memoryREAD++;
              contin++;
              memoryWritten++;
              inc++;
                break;
            }
            lpp++;
          }
      }else if(toRreira=='R'){
      //  printf("%lu,%lu\n",indS,indT );
         lpp=0;
        	while(lpp<assoc){
          int low;
          if(cache[indS][lpp].tag==indT && cache[indS][lpp].status!=0){
          //final fame
                final++;
                break;

          } else if((assoc-1)==lpp && cache[indS][lpp].status!=0){
          //end of loop miss
              finalM++;
              memoryREAD++;
              low=0;
              loop=0;
        			while(loop<assoc){
          //checking for a time signing
            if(cache[indS][loop].time<=cache[indS][low].time){
              low=loop;
              }
              loop++;
              }
          //found
            cache[indS][low].status=1;
            cache[indS][low].tag=indT;
            inc++;
            cache[indS][low].time=inc;
            break;
          } else if (cache[indS][lpp].status==0) {            //miss
              finalM++;
              memoryREAD++;
              inc++;
              cache[indS][lpp].status=1;
              cache[indS][lpp].tag=indT;
              contin++;

              cache[indS][lpp].time=inc;
              break;
            }
            lpp++;
          }
        }

    fscanf(doc,"%s ", wop);
  }
    printf("no-prefetch\n");
    printf("Memory reads: %d\n",memoryREAD);
  printf("Memory writes: %d\n",memoryWritten);
  printf("Cache hits: %d\n",final);
  printf("Cache misses: %d\n",finalM);

  memoryREAD=0;
  memoryWritten=0;
    inc=0;
    finalM=0;
    contin=0;
    final=0;
  createPre(setnum,assoc);
    fclose(doc);

    doc=fopen(filename,"r");
    if(doc==NULL){
      printf("error\n");
      //return 0;
    }
    //printf("mer444444rrr\n");
    char* wor=wop;
    fscanf(doc,"%s", wor);
    //printf("3333333\n");

    while(strcmp("#eof",wop)!=0){
      fscanf(doc, " %c %lx", &toRreira, &address);
      indS=(address>>b)&sMKK;
    wop=abd;

      indT=address>>(b+s);
        unsigned long int prefetch=address+bSize;
      wop=abd;
      //return 0;
      unsigned long int indSN=(prefetch>>b)&sMKK;
      /*    merr[length] = '\0';
        assoc=atoi(merr);
        sNum=cSize/((bSize)*assoc);
        */
        unsigned long int indTN=prefetch>>(b+s);
      if(toRreira=='W'){
      lpp=0;
        	while(lpp<assoc){
          int low;
          if (preCache[indS][lpp].status!=0 && preCache[indS][lpp].tag==indT){
                final++;
                memoryWritten++;
                break;

            } else if( preCache[indS][lpp].status!=0 && (assoc-1)==lpp){
                  finalM++;
                  memoryREAD++;
                  memoryWritten++;
                  low=0;
                  loop=0;
        			while(loop<assoc){
                       if(preCache[indS][loop].time<=preCache[indS][low].time){
                          low=loop;
                     }
                     loop++;
                  }
            //
              preCache[indS][low].status=1;
                 inc++;
                 preCache[indS][low].tag=indT;
                     preCache[indS][low].time=inc;
                   //merrrrrr
                   plz(assoc,indTN,indSN);
                   //merrrrrr
                  break;

          } else if (preCache[indS][lpp].status==0){
            preCache[indS][lpp].status=1;
            //printf("%s\n", );
              preCache[indS][lpp].tag=indT;
            contin++;

              preCache[indS][lpp].time=inc;



                 finalM++;
                 memoryREAD++;
              contin++;
                 memoryWritten++;
                 inc++;
              //merrrrrr
              plz(assoc,indTN,indSN);

              //merrrrrr
                  break;
              }
              lpp++;
          }
      }else if(toRreira=='R'){
      //  printf("%lu,%lu\n",indS,indT );
      	lpp=0;
        while(lpp<assoc){
          int low;
          if (preCache[indS][lpp].status!=0 && preCache[indS][lpp].tag==indT){
          //final fame
                final++;
                break;

          } else if( preCache[indS][lpp].status!=0 && (assoc-1)==lpp){
          //end of loop miss
                finalM++;
                memoryREAD++;
                low=0;
                loop=0;
        			while(loop<assoc){
            //checking for a time signing
                if(preCache[indS][loop].time<=preCache[indS][low].time){
                    low=loop;
                }
                loop++;
                }
          //found
                preCache[indS][low].status=1;
                contin++;

                preCache[indS][low].tag=indT;
                inc++;

                preCache[indS][low].time=inc;
                //merrrrrr
              plz(assoc,indTN,indSN);

                //merrrrrr
                break;


          } else if (preCache[indS][lpp].status==0){
            //miss
              finalM++;
              memoryREAD++;
              inc++;
              preCache[indS][lpp].status=1;
              preCache[indS][lpp].tag=indT;
              contin++;

              preCache[indS][lpp].time=inc;
              //merrrrrr
              plz(assoc,indTN,indSN);
              //merrrrrr
              break;
            }
            lpp++;
            }
        }
      fscanf(doc,"%s ", wop);
  }

     printf("with-prefetch\n");
  printf("Memory reads: %d\n",memoryREAD);
  printf("Memory writes: %d\n",memoryWritten);
  printf("Cache hits: %d\n",final);
  printf("Cache misses: %d\n",finalM);
}



