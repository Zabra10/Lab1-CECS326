#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void *child(void *ignored){
   while (1) // an infinite while loop that keeps iterating 
   {
    sleep(3); // the program sleeps/ pauses for 3 seconds
   printf("Child is done sleeping 3 seconds.\n"); // print a message saying child is done sleeping 3 seconds
   }
   
   
   return NULL; // returns NULL(nothing)
}

int main(int argc, char *argv[]){
   pthread_t child_thread, parent_thread; //  two threads child and parent
   // The pthread lets two separate actions hapen at the same time without waiting for one of them to execute for the other to start.
   int code,code2,ccc; // creates three integers assign them no values.
   char key; // creates a character with no assigned value

   code = pthread_create(&child_thread, NULL, child, NULL); // assign the child thread to the int code
    key = getchar(); // get a character from the user.
   
   while(1){ // an infinite while loop
       
       pthread_create(&parent_thread, NULL, child, NULL); //create the second thread that is called parent thread
               
       if(key ==0x0A){ // if the user presses the enter button.
       
        printf("Parent is done sleeping 5 seconds.\n"); // print that the parent is done sleeping
         
         pthread_cancel(parent_thread); // uses the cancel thread to cancel the parent.
         
      sleep(5); //the program sleeps/ pauses for 5 seconds
        printf("thread 2 was killed.\n"); //print a message saying thread 2 was killed
        
        break; //breaks the while loop.
   }
   }
   // the sleeping thread keeps printing the message while waiting for the input because it is only killed/cancelled once the enter has been pressed.
   //since it is two different threads they can work at the same time not one after the other.

   if(code){
      fprintf(stderr, "pthread_create failed with code %d\n", code);
   }
   
   return 0;
}
