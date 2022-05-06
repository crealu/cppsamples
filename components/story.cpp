#include <iostream>
#include <stdio.h>
// #include <SDL2/SDL.h>
using namespace std;

class StoryScript {
public:
  StoryScript();
  ~StoryScript();

  void writeText(int current);

protected:
  string *script;
};

StoryScript::StoryScript() {
  string text[] = {
    "Serene voyager unbound by perpetuated chasm, the trial of times forgotten can only one bear.",
    "So... what brings you to Midoritierra?",
    "...",
    "...",
    "Excuse my unmannerliness... for I have yet to introduce myself.",
    "I am the sourcerer of these plains,",
    "maintainer of peace and order,",
    "caster of the breeze of tranquility,",
    "wielder of the inifinte grön magic.",
    "And my friends call me G."
  };

  int textLength = sizeof(text)/sizeof(text[0]);
  script = new string[textLength];

  for (int t = 0; t < textLength; t++)
    script[t] = text[t];
}

StoryScript::~StoryScript() {}

void StoryScript::writeText(int current) {
  const char *dialog = script[current].c_str();
  cout << dialog << "\n";
}

int main() {
  StoryScript green;
  int current = 0;
  char c;

  while (c != 'e') {
    cout << "n/b ? ";
    cin >> c;
    green.writeText(current);
    if (c == 'n' && current != 9)
      current += 1;

    if (c == 'b' && current != 0)
      current -= 1;
  }

  return 0;
}