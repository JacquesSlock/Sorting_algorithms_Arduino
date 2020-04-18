void bubbleSort(int a[],int first, int last) {
    for(int i=0; i<(last); i++) {
        diffStep(a);
        for(int o=0; o<(last-(i)); o++) {
                compareStep();
                if(a[o] > a[o+1]) {
                    swapStep();
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
               }
        }
         
    }
}
