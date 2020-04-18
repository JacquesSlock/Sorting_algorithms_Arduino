boolean sortedBogo = true;
void isSorted_bogo(int a[], int n) 
{   
    sortedBogo = false;
    //Serial.println();
    for (int i=0; i < n; i++) {
        int mnd = random(n);
        int temp = a[i];
        a[i] = a[mnd];
        a[mnd] = temp;
        swapStep();
        diffStep(a);
    }
} 

boolean testArray(int a[], int n){
  boolean sorted_Bogo = false;
  for(int j=0; j < (n-1); j+=1) {
      compareStep();
      if (a[j] > a[j+1]) {
          sorted_Bogo = true; 
          }     
    }
     return !sorted_Bogo;
}


void bogosort(int a[], int n) 
{   
    // if array is not sorted then shuffle 
    // the array again 
    int timeBogo = micros();
    while (!testArray(a, n) && micros() - timeBogo <= 20000000 ){      
      isSorted_bogo(a, n) ;     
      timeStep(); 
    } 
}
      
