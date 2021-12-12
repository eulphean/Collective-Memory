#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // Open file to store the results in.
  arduino.open("arduino.txt", ofFile::WriteOnly);
  
  // Buffer to read the data from.
  
  ofBuffer buffer = ofBufferFromFile("book.txt");
  auto text = buffer.getText();

  // Split all the paragraphs based on "~" (tilda)
  auto paras = ofSplitString(text, "~");

  for (auto p : paras) {
    // Split by ' ' and now I have characters.
    auto words = ofSplitString(p, " ");
    for (auto w: words) {
      int sum = 0;
      for (char c: w) {
        sum += (int) c;
      }
      arduino << ofUTF8Length(w) << 'N' << abs(sum) << 'W';
    }
    arduino << 'P';
  }

  arduino.close();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
