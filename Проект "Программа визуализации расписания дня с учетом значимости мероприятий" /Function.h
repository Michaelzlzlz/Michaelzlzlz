#include <iostream>
using namespace std;
extern char saveFile[101];
extern char saveFile1[101];
std::string& Convert_String_to_string(System::String^ s, std::string& os); 
System::String^ Convert_string_to_String(std::string& os, System::String^ s);
std::string& Convert_String_to_string(System::String^ s);
System::String^ Convert_string_to_String(std::string& os); 
System::String^ Convert_char_to_String(char* ch); 
char* Convert_String_to_char(System::String^ string);