#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/


int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


bool Password::has_mixed_case(string password) {
  int has_both = 0;
  bool checkedLower = false;
  bool checkedUpper = false;
  for(char c : password) {
    if (islower(c) && !checkedLower) {
      has_both++;
      checkedLower = true;
    } else if (isupper(c) && !checkedUpper) {
      has_both++;
      checkedUpper = true;
    }
  }

  if (has_both == 2) {
    return true;
  } else  {
    return false;
  }
}

Password::Password() {
  pass_history.push_back("ChicoCA-95929");
}


void Password::set(string p) {
  int all_true = 0;
  bool exists = false;
  if(p.size() >= 8 && p.size() < 20) {
    all_true++;
  }
  if (count_leading_characters(p) <= 3) {
    all_true++;
  } 
  if (has_mixed_case(p)) {
    all_true++;
  } 
  for (string password : pass_history) {
    if (p == password) {
      exists = true;
      break;
    }
  }
  if (all_true == 3 && !exists) {
    pass_history.push_back(p);
  }

}


/*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
bool Password::authenticate(string p) {
  if (pass_history[pass_history.size()-1] == p) {
    return true;
  } 
  return false;
}

