#include "const.h"

//fn definitions
void i_perm();
void f_perm();
void test();
void rounds(int no);
void write_file();

int main(int argc, char *argv[]){

  fpi = fopen("ip.txt","r");
  fpo = fopen("op.txt","a");
  fpm = fopen("m.txt", "a");
  int i = 0;
  buff_read = 8;

  // main loop for block by block read from file
  while(buff_read > 0){
    buff_read_b = buff_read;
    buff_read = fread(block, 1, block_size, fpi);
    
    if(buff_read<8)for(int i = buff_read_b; i<block_size; i++)block[i]=0; //zero padding of last 8 bytes
    
    // initial permutation 
    i_perm();
    write_file(fpm);
    
    
    // all other calculations to be implemented here 
      

    // final permutation
    f_perm();
    write_file(fpo);
    
    printf("Read %u of 8 bytes\n", buff_read);
  }

  printf("buff_read: %d\n", buff_read_b);
  
  set_bit(63,1); 
  
  for(int i=0;i<8;i++) {
   for(int j = 7; j >= 0; j--) printf("%d", (block[i] >> j) & 1);
     printf(" ");
  }
  printf("%s\n",block);
    

  fclose(fpi);
  fclose(fpo);
  return 0;
}



void i_perm(){
  
  memcpy(block_og, block, block_size);
  
  for (int i = 0; i<64; i++) {
    
    set_bit((i+1),get_bit(ip[i])); 

  }



}

void f_perm(){
  
  memcpy(block_og, block, block_size);
  
  for (int i = 0; i<64; i++) {
    
    set_bit((i+1),get_bit(ip_in[i])); 

  }

}

void write_file(FILE *p){

  for(int i=0; i<block_size; i++){
    
    fprintf(p, "%c", block[i]);

  
  }


}


void test() {
 for(int i=0;i<8;i++) {
      for(int j = 7; j >= 0; j--) printf("%d", (block[i] >> j) & 1);
      printf(" ");
    }
    
    i_perm(); //IP
    
    //after IP 
    for(int i=0;i<8;i++) {
      for(int j = 7; j >= 0; j--) printf("%d", (block[i] >> j) & 1);
      printf(" ");
    }
    
    f_perm();
    
    // after FP
    for(int i=0;i<8;i++) {
      for(int j = 7; j >= 0; j--) printf("%d", (block[i] >> j) & 1);
      printf(" ");
    }
    for(int i=0;i<8;i++) {
      printf("%c", block[i]);
    }
    printf("\n");
    printf("%d", get_bit(3));
    printf("\n");


}
