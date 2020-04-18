//void swapStep(){
//    unsigned long timeForStep = micros();
//    digitalWrite(swap, HIGH); // sets the digital pin 8 on
//    delay(25);            // waits for a second
//    digitalWrite(swap, LOW); 
//    //delay(25);
//    Serial.print("|");
//   timeStart += (micros()-timeForStep);
//   //Serial.print(time2);
//   
//}
//
//void diffStep(int a[]){
//  unsigned long timeForStep = micros();
//  
//  int gemVerschil = 0;
//  digitalWrite(diff, HIGH); // sets the digital pin 13 on
//  delay(25);            // waits for a second
//  digitalWrite(diff, LOW); 
////  for (int x=0; x<count-1; x++) {
////    int diff_ = abs(a[x+1]-a[x]);
////    
//////    delay(diff_*10);
////    Serial.print(diff_);
////    Serial.print("-");
////    //gemVerschil += abs(a[x+1]-a[x]);
////  }
//// 
//  //gemVerschil = gemVerschil/count;
//  //Serial.print(gemVerschil);
////  
////  for (int x=0; x<count; x++) {
////      Serial.print(a[x]);
////      Serial.print("-");
////    }
//  Serial.print("#");
//  timeStart += (micros()-timeForStep);
//  memoryStep();
//}
//
//void timeStep(){
//  if(micros() - lastRefreshTime >= REFRESH_INTERVAL)
//  {
//    //Serial.println(lastRefreshTime);
//    lastRefreshTime += REFRESH_INTERVAL;
//    digitalWrite(times, HIGH); // sets the digital pin 8 on
//    delay(25);            // waits for a second
//    digitalWrite(times, LOW); 
//  }
//  
//}
//
void compareStep(){
    timeForStep = timer2.get_count();
    digitalWrite(compare, HIGH); // sets the digital pin 8 on
    delay(10);            // waits for a second
    digitalWrite(compare, LOW); 
    delay(10); 
////    //Serial.print("$");
   timeLost += timer2.get_count() - timeForStep + 63.5 ;
//  memoryStep();
}
//
//int freeMemory() {
//  char top;
//#ifdef __arm__
//  return &top - reinterpret_cast<char*>(sbrk(0));
//#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
//  return &top - __brkval;
//#else  // __arm__
//  return __brkval ? &top - __brkval : &top - __malloc_heap_start;
//#endif  // __arm__
//}
//
void memoryStep(){
  timeForStep = timer2.get_count();
////  //Serial.print(normal_mem -freeMemory());
  digitalWrite(memory, HIGH); // sets the digital pin 8 on
  delay(10);            // waits for a second
  digitalWrite(memory, LOW); 
  delay(10);
//  //Serial.print("µ");
  timeLost += timer2.get_count() - timeForStep + 63.5;
}
