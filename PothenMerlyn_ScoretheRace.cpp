// Merlyn Pothen 

// if checker == 2, then the string the user inputted has equal amount of
// players

// if checker == 1, then the string the user inputted DOES NOT have equal number
// of players and we are asking in a loop for a new string

// if checker == 0, then after asking the user for ANOTHER string, it finally
// has equal amount of players

#include <iostream>
using namespace std;

// method to print results
void result(int w, char letter[], int equal[], double scores[]) {
  cout << "There are " << w << " teams" << endl;
  cout << "Each team has " << equal[0] << " runners" << endl;

  // loop to print teams and scores
  int a = 0;
  while (a < w) {
    cout << "Team " << letter[a] << " score is: " << scores[a] << endl;
    a++;
  }

  cout << endl;

  // finding the highest score
  int d = scores[0];
  int g = 0;

  for (int i = 1; i < w; i++) {
    if (scores[i] < d) {
      g = i;
      d = scores[i];
    }
  }

  cout << "The winning team is team " << letter[g] << " with a score of "
       << scores[g] << endl
       << endl;
}

int main() {

  // store outcome
  string s;

  // for while loop
  int check = 0;

  // loop to keep asking user for info
  while (check == 0) {

  a:
    cout << "Enter the results of the race: ";
    cin >> s;

    // terminate program
    if (s == "done") {
      check = 1;
      return 0;
    }

    int q = s.length();

    // STORE LETTERS INTO ORDER ARRAY to rearrange alphabetically
    char order[q];
    for (int i = 0; i < q; i++) {
      order[i] = s[i];
    }

    // REORDER THE ARRAY alphabetically. Example: ZZAZAA to AAAZZZ
    char temp;
    for (int i = 0; i < q; i++) {
      for (int j = i + 1; j < q; j++) {
        if (order[j] < order[i]) {
          temp = order[i];
          order[i] = order[j];
          order[j] = temp;
        }
      }
    }

    // NUMBER OF TEAMS (WHICH IS W)
    int w = 0;
    int e;
    for (int i = 0; i < q; i++) {
      e = i + 1;
      while (order[i] == order[e]) {
        e++;
      }
      if (order[i] != order[e]) {
        w++;
        i = e;
      }
    }

    // LETTERS NOT DUPLICATED. Example: AAAZZZ to AZ
    char letter[w];
    int t = 0;
    for (int i = 0; i < q; i++) {
      e = i + 1;
      while (order[i] == order[e]) {
        e++;
      }
      if (order[i] != order[e]) {
        letter[t] = order[e - 1];
        t++;
        i = e;
      }
    }

    // to check if there is equal players on each team. remember to change m to
    // 0 or else the value will keep on adding the players on all teams.
    int equal[w];
    int m = 0;
    int b = 0;

    for (int i = 0; i < w; i++) {
      for (int j = 0; j < q; j++) {
        if (letter[i] == s[j]) {
          m++;
        }
      }
      equal[b] = m;
      m = 0;
      b++;
    }

    // store scores
    double scores[w];
    int p = 0;

    // add up the scores
    double u = 0;

    // compare AZ with ZZAZAA. Find where they match and add the rankings up
    // together.
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < q; j++) {
        if (letter[i] == s[j]) {
          u = u + (j + 1);
        }
      }
      scores[p] = u / equal[0];
      u = 0;
      p++;
    }

    // compare first number with rest of the numbers.
    int v = equal[0];

    int checker = 2;

    for (int i = 1; i < w; i++) {
      if (v != equal[i]) {
        checker = 1;
      }
    }
    if (checker == 1) {
      cout << "ERROR! Try again :)" << endl;
    }

    // keep on asking user for input until equal number of players.
    while (checker == 1) {

      // go ALL THE WAY BACK to the beginning of the function
      goto a;
    }

    // if output has equal number of players
    if (checker == 0) {
      result(w, letter, equal, scores);
      break;
    }

    // getting equal number of players the first time without asking again
    if (checker == 2) {
      result(w, letter, equal, scores);
    }
  }

  return 0;
}