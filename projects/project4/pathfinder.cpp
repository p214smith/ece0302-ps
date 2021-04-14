#include "deque.hpp"
#include "./lib/image.h"
#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>

struct Loc {
  int row;
  int col;
};

int main(int argc, char *argv[])
{
  if (argc != 3) {
    std::cout << "Usage: compare"
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;}
  Image<Pixel> inputImage = readFromFile(argv[1]);
  Loc start;
  int redSquares=0;
  for (intmax_t i = 0; i < inputImage.width(); ++i)
      for (intmax_t j = 0; j < inputImage.height(); ++j) {
        if (inputImage(i,j)!=WHITE && inputImage(i,j)!= BLACK && inputImage(i,j)!= RED)
        {
          std::cout <<"ERROR! Invalid color in maze";
          return EXIT_FAILURE;
        }
        if (inputImage(i,j) == RED){
          start.row = i;
          start.col = j;
          redSquares++;}
          if (redSquares > 1)
          {
            std::cout <<"ERROR!  To many red squares";
            return EXIT_FAILURE;
          }
        }
  if (start.row == 0 || start.row == inputImage.height()-1||start.col == 0 || start.col == inputImage.width()-1){
    inputImage(start.row,start.col)=GREEN;
    writeToFile(inputImage,argv[2]);
    std::cout << "SOLUTION FOUND";
    return EXIT_SUCCESS;
  }
  Deque<Loc> frontier;
  Deque<Loc> explored;
  frontier.pushFront(start);

while (true){
  if (frontier.isEmpty()){
    std::cout << "NO SOLUTION FOUND";
    writeToFile(inputImage,argv[2]);
    return EXIT_SUCCESS;
  }
  
  start = frontier.back();
  frontier.popBack();
  explored.pushFront(start);
  
  if ( inputImage(start.row-1 , start.col)== WHITE)
  {
    
    Loc nextLoc;
    nextLoc.row = start.row-1;
    nextLoc.col = start.col;
    
    if(frontier.findItem(nextLoc) == false && explored.findItem(nextLoc)== false)
    {
      
      if (nextLoc.row == 0 || nextLoc.row == (inputImage.height()-1)||nextLoc.col == 0 || nextLoc.col == (inputImage.width()-1)){
    inputImage(nextLoc.row,nextLoc.col) = GREEN;
    std::cout << "SOLUTION FOUND";
    writeToFile(inputImage,argv[2]);
    return EXIT_SUCCESS;
    }
    
    frontier.pushFront(nextLoc);
  }
 
  }
    if ( inputImage(start.row+1 , start.col)== WHITE)
  {
   
    Loc nextLoc;
    nextLoc.row = start.row+1;
    nextLoc.col = start.col;
    
    if(frontier.findItem(nextLoc) == false && explored.findItem(nextLoc) == false)
    {
      
      if (nextLoc.row == 0 || nextLoc.row == (inputImage.height()-1)||nextLoc.col == 0 || nextLoc.col == (inputImage.width()-1)){
    inputImage(nextLoc.row,nextLoc.col)= GREEN;
    std::cout << "SOLUTION FOUND";
    writeToFile(inputImage,argv[2]);
    return EXIT_SUCCESS;
    }
    frontier.pushFront(nextLoc);
    
  }
  }
   if ( inputImage(start.row, start.col-1)== WHITE)
  {
    
    Loc nextLoc;
    nextLoc.row = start.row;
    nextLoc.col = start.col-1;
    
    if(frontier.findItem(nextLoc) == false && explored.findItem(nextLoc)==false)
    {
      if (nextLoc.row == 0 || nextLoc.row == (inputImage.height()-1) ||nextLoc.col == 0 || nextLoc.col == (inputImage.width()-1)){
    inputImage(nextLoc.row,nextLoc.col)= GREEN;
    std::cout << "SOLUTION FOUND";
    writeToFile(inputImage,argv[2]);
    
    return EXIT_SUCCESS;
    }
    frontier.pushFront(nextLoc);
    
  }
  
  }
   if ( inputImage(start.row, start.col+1)==WHITE)
  {
    
    Loc nextLoc;
    nextLoc.row = start.row;
    nextLoc.col = start.col+1;
    
    if(frontier.findItem(nextLoc) == false && explored.findItem(nextLoc) == false)
    {
      if (nextLoc.row == 0 || nextLoc.row == (inputImage.height()-1)||nextLoc.col == 0 || nextLoc.col == (inputImage.width()-1)){
    inputImage(nextLoc.row,nextLoc.col)=GREEN;
    std::cout << "SOLUTION FOUND";
    writeToFile(inputImage,argv[2]);
    return EXIT_SUCCESS;
    }
    frontier.pushFront(nextLoc);
    
  }
 
  }

}
}


bool operator==(const Loc &a, const Loc &b) {
  return (a.row == b.row) && (a.col == b.col) ;}
