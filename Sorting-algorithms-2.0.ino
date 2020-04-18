//bibliotheek voor een betere timer / library for a more precise timer
#include <eRCaGuy_Timer2_Counter.h>

#include<stdio.h>

//setup output pins to control gears
const int swap = 8;
const int diff = 9;
const int times = 10;
const int compare = 11;
const int memory = 12;


void setup() {
  //configure Timer2
  timer2.setup(); 
  //unsigned long timeStart = micros(); //units of 0.5us; the count accumulated by Timer2_Counter
  
  //acquire time stamps
  //unsigned long t_T2_count = micros(); //units of 0.5us; the count accumulated by Timer2_Counter
  //int normal_mem  = freeMemory();
  //Serial.println("Free memory:" + normal_mem);

  //setup serial 
  Serial.begin(9600);
  pinMode(swap, OUTPUT); 
  pinMode(diff, OUTPUT); 
  pinMode(times, OUTPUT);
  pinMode(compare, OUTPUT);
  pinMode(memory, OUTPUT);
  //digitalWrite(8, HIGH);// sets the digital pin 13 as output
  start();
  
}

//TODO
//wisselen van elementen input van fysisch systeem
//knoppen voor bijv voorgesorteerde arrays - keuzemenu > wachten op led 
// lesplan > na fysieke constructie
// gears maken


//setup variables
int i, count = 10 ;
float timer_step = 0;
static const unsigned long REFRESH_INTERVAL = 1000000; 
long lastRefreshTime = 0;
float loopTime, loopTime2, loopTime3, loopTime4, loopTime5, loopTime6, loopTime7;
float timeLost = 0;
float timeForStep;
void start() {
  
  
  int arr[count], arr_res[count];
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int mnd = random(count);

  // verschillende arrays 

  //pre-sorted array
//  for (i = 0; i < count; i++) {
//    arr[i] = i;
//    //Serial.print(arr[i]);
//  }

  //reverse array
//  for (i = 0; i < count; i++) {
//      arr[i] = count-i;
//      //Serial.print(arr[i]);
//    }

  //random array
  for (i = 0; i < count; i++) {
    arr[i] = random(0, 100);
    //Serial.print(arr[i]);
  }

  //zero array
//    for (i = 0; i < count; i++) {
//      arr[i] = 0;
//      //Serial.print(arr[i]);
//    }

  //reserve array om later array terug te kunnen vullen
  for (i = 0; i < count; i++) {
    arr_res[i] = arr[i];
  }

  //seriële print van startarray
  Serial.println("Startarray");
  printArray(arr, arr_size);

  //quicksort methode
  Serial.println("quicksort");  
  timeLost = 0;
  timer2.reset();
  quickSort(arr, 0, arr_size - 1);
  loopTime = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);

  
  fillArray(count,  arr, arr_res);
  
  Serial.println("Bubblesort");
  timeLost = 0;
  timer2.reset();
  bubbleSort(arr, 0, arr_size - 1);
  loopTime2 = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);
  
  fillArray(count,  arr, arr_res);

  Serial.println("Bogosort");
  timeLost = 0;
  timer2.reset();
  //bogosort(arr, arr_size);
  loopTime3 = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);
  
  fillArray(count,  arr, arr_res);

  Serial.println("mergeSort");
  timeLost = 0;
  timer2.reset();
  mergeSort(arr, 0, arr_size - 1);
  loopTime4 = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);
  
  fillArray(count,  arr, arr_res);

  Serial.println("selectionSort");
  timeLost = 0;
  timer2.reset();
  selectionSort(arr, arr_size);
  loopTime5 = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);
  
  fillArray(count,  arr, arr_res);

  Serial.println("Timsort");
  timeLost = 0;
  timer2.reset();
  timSort(arr, arr_size);
  loopTime6 = (timer2.get_count() - timeLost)/2;
  Serial.println();
  Serial.println("finished");
  printArray(arr, arr_size);
  
  fillArray(count,  arr, arr_res);


//werk niet naar behoren
//  timeStart = timer2.get_count()
  //treeSort(arr7, arr_size);
//  unsigned long loopTime7 = (timer2.get_count() - timeLost)/2;
//  Serial.println("finished");
//  printArray(arr, arr_size);
//  fillArray(count,  arr, arr_res);

  //
  //
  

  Serial.println("");
  //Serial.print("Quick: ");
  Serial.println(loopTime);
  //Serial.print("Bubble: ");
  Serial.println(loopTime2);
  //Serial.print("Bogo: ");
  Serial.println(loopTime3);
  //Serial.print("Mergesort: ");
  Serial.println(loopTime4);
  //Serial.print("Selection: ");
  Serial.println(loopTime5);
  //Serial.print("Tim: ");
  Serial.println(loopTime6);
  //Serial.println(loopTime7);
}


void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i) {
    Serial.print(arr[i]);
    Serial.print(" ");
  }
  Serial.print("\n");
}

void fillArray(int count, int arr[],int arr_res[]){
  for (int i = 0; i < count; i++) {
    arr[i] = arr_res[i];
  }
}
