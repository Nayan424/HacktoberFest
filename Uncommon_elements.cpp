#include <iostream>

using namespace std;

int main() {

   int len1 = 5, len2 = 4;

   char str1[len1] = "afbde", str2[len2] = "wabq";

   cout << "Uncommon Elements :" <<endl;

   //loop to calculate str1- str2

   for(int i = 0; i < len1; i++) {

      for(int j = 0; j < len2; j++) {

         if(str1[i] == str2[j])

            break;

         //when the end of string is reached

         else if(j == len2-1) {

            cout << str1[i] << endl;

            break;

         }

      }

   }

   //loop to calculate str2- str1

   for(int i = 0; i < len2; i++) {

      for(int j = 0; j < len1; j++) {

         if(str2[i] == str1[j])

            break;

         else if(j == len1-1) {

            cout << str2[i] << endl;

            break;

         }

      }

   }

   return 0;

}
