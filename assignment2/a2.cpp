///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Filename: a2.cpp
//Author: Shayan Shadpour
//Student Number: 104399871
//Created on: 2020/01/28
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cmath>      // for std::sqrt
#include <array>      // for std::array
#include <vector>     // for std::vector
#include <limits>     // for std::numeric_limits
#include <string>     // for std::string
#include <istream>    // for std::istream
#include <ostream>    // for std::ostream
#include <iostream>   // for std::cin, std::cout
#include <algorithm>  // for std::transform

using namespace std;

struct rgb     //creating the struct for the colours
{
     unsigned char red;
     unsigned char green;
     unsigned char blue;
};

std::istream& operator >>(std::istream& is, rgb& colour) { //operator overload to input the struct from an istream

     using namespace std;

     unsigned r, g, b;

     if (is >> r >> g >> b)
     {
          colour.red = r;
          colour.green = g;
          colour.blue = b;
     }
     else
     {
          is.setstate(ios_base::failbit); //if any component can not be read in, the stream state is set to "fail"
     }

     return is;
}

std::ostream& operator <<(std::ostream& os, rgb const& colour) { //operator overload to output the struct to an ostream
     
     os << static_cast<unsigned>(colour.red) << ' ' << static_cast<unsigned>(colour.green) << ' ' << static_cast<unsigned>(colour.blue) << ' '
          ;
     return os; //return the newly formatted os
}

double distance(rgb const& a, rgb const& b) {
     return sqrt(pow((a.red - b.red), 2) + pow((a.green - b.green), 2) + pow((a.blue - b.blue), 2));
}


int main() {

     array<rgb, 16> const colours{ { //initializing the array of colour codes
    { 0x00, 0x00, 0x00 }, // 0: black
    { 0x80, 0x00, 0x00 }, // 1: maroon
    { 0x00, 0x80, 0x00 }, // 2: green
    { 0x80, 0x80, 0x00 }, // 3: olive
    { 0x00, 0x00, 0x80 }, // 4: navy
    { 0x80, 0x00, 0x80 }, // 5: purple
    { 0x00, 0x80, 0x80 }, // 6: teal
    { 0xC0, 0xC0, 0xC0 }, // 7: silver
    { 0x80, 0x80, 0x80 }, // 8: grey
    { 0xFF, 0x00, 0x00 }, // 9: red
    { 0x00, 0xFF, 0x00 }, // 10: lime
    { 0xFF, 0xFF, 0x00 }, // 11: yellow
    { 0x00, 0x00, 0xFF }, // 12: blue
    { 0xFF, 0x00, 0xFF }, // 13: fushsia
    { 0x00, 0xFF, 0xFF }, // 14: aqua
    { 0xFF, 0xFF, 0xFF }  // 15: white
  } };

     array<string, 16> const colour_names{ //initializing the array of colour names
       "black", "maroon", "green", "olive", "navy", "purple", "teal", "silver",
       "gray", "red", "lime", "yellow", "blue", "fushsia", "aqua", "white"
     };

     for (rgb value{}; cin >> value;) //loop which reads in rgb structure values
     {
          vector<double> distances; //declaring the distances vector
          distances.reserve(colours.size()); //reserving sufficient memory to hold all to-be-computed distance values

          transform //transform function to populate the vector with distance values
          (
               begin(colours), end(colours), back_inserter(distances), [&value](auto const& colour) //transform arguments
               {
                    return distance(colour, value); //returns complete output
               }
          );

          size_t index = std::numeric_limits<size_t>::max(); //initializing a size_t int to store the index of the colour with the smallest distance
          double smallest_distance = std::numeric_limits<double>::max(); //creating a double varaible to store the CURRENT smallest distance value

          for (auto i = begin(distances), iEnd = end(distances); i != iEnd; ++i) //creating a loop that iterates through distances and updates the smallest distance
          {

               if (*i < smallest_distance)
               {
                    smallest_distance = *i;
                    index = i - begin(distances);
               }

          }

          if (index > 15 ) //
          {
               cout << "ERROR accurred. Aborting...\n"; //error statement in case index is invalid
          }
          else
          {
               cout << colour_names[index] << '\n'; //outputting the name of the closest matching colour if found
          }

     }

}


     
