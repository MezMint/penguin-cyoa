#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get validated numeric choice
int getChoice(int min, int max) {
  int choice;
  while (true) {
    cin >> choice;
    if (cin.fail() || choice < min || choice > max) {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Invalid choice. Try again: " << endl;
    } else {
      return choice;
    }
  }
}

int main() {
  srand(time(0));

  cout << "Respond using the applicable number for each option. " << endl << endl;
  cout << "If you enter a number that isn’t an option, you will be prompted to enter an answer again. Non-numbers will crash. " << endl << endl;

  cout << "You’re a penguin adventurer, and it seems the king has an adventure for you. Will you accept it? " << endl << endl;
  cout << "1. Yes " << endl;
  cout << "2. No" << endl;

  int startChoice = getChoice(1, 2);

  if (startChoice == 2) {
    cout << "Oh, I guess you stay home then. That’s certainly one way to not risk dying. That’s the end of the game then. " << endl;
    return 0;
  }

  cout << endl;
  cout << "Alright, so you accept the quest, which is to head to the continent of Mainlandia and return the Aurora Borealis (renamed that despite being in the wrong pole due to the name being more iconic). " << endl;
  cout << "Ah right, I forgot to ask: Which class are you? " << endl << endl;

  cout << "1. Fighter" << endl;
  cout << "2. Ranger" << endl;
  cout << "3. Mage" << endl;

  int playerClass = getChoice(1, 3);
  string c = ""; 
  if (playerClass == 1) {
    c = "fighter";
  }
  else if (playerClass == 2) {
    c = "ranger";
  }
  else {
    c = "mage";
  }

  cout << endl;
  cout << "So, you’re a " << c << ". And what is your name? (Name must be at least 1 character and less than 9 characters. If name is not within those requirements, name will be set to Pengy): " << endl;

  string name;
  cin >> name;

  if (name.length() < 1 || name.length() > 8) {
    name = "Pengy";
  }

  string className;
  if (playerClass == 1) className = "fighter";
  if (playerClass == 2) className = "ranger";
  if (playerClass == 3) className = "mage";

  cout << endl;
  cout << "Alright, so you are " << name << " the " << className << ", and you are about to set out on a grand quest to steal the artifact containing the aurora borealis. The other penguins wish you the best of luck before you head out. The boat ride to Mainlandia is uneventful, but as you arrive you see a swarm of evil looking seagulls surrounding a mysterious bag… " << endl << endl;

  cout << "1. Investigate" << endl;
  cout << "2. Charge" << endl;
  cout << "3. Sneak to a better position " << endl;

  int encounter = getChoice(1, 3);

  // Failure cases
  if ((encounter == 1 && (playerClass == 1 || playerClass == 2))) {
    cout << "As you move in closer to investigate the bag, you find it’s full of magic items. You touch one and it blows up in your face, ending your adventure. Game over. " << endl;
    return 0;
  }

  if ((encounter == 2 && (playerClass == 2 || playerClass == 3))) {
    cout << "You run in and begin swinging your weapon, but quickly get swarmed by the seagulls, ending your adventure. Game over. " << endl;
    return 0;
  }

  if ((encounter == 3 && (playerClass == 1 || playerClass == 3))) {
    cout << "You attempt to sneak to a better location but are really bad at it. The seagulls catch you and swarm you, ending your adventure. Game over. " << endl;
    return 0;
  }

  // Success cases
  if (encounter == 1 && playerClass == 3) {
    cout << "You move closer to investigate the bag, and find it’s full of magic items. You quickly identify one to be an explosive rubber ducky, and use it to explode the seagulls, quickly ending the encounter. " << endl;
  }

  if (encounter == 2 && playerClass == 1) {
    cout << "You run in swinging your weapon and quickly defeat most of the seagulls. The remaining ones scatter, and the encounter is over. " << endl;
  }

  if (encounter == 3 && playerClass == 2) {
    cout << "You successfully sneak to a vantage point, and from there are able to snipe the seagulls safely from a distance. They never stood a chance, and the encounter is over. " << endl;
  }

  cout << endl;
  cout << "You move forward, eventually finding a town of finches you can rest at. Do you want to ask around to see if anyone could potentially help you locate the object containing the aurora borealis? " << endl;
  cout << "1. Yes" << endl;
  cout << "2. No" << endl;

  int town = getChoice(1, 2);

  if (town == 2) {
    cout << "Without help you later get hopelessly lost, ending the adventure. Game over. " << endl;
    return 0;
  }

  cout << "After a bit of asking around you find an old finch who seems to have some important info. One conversation later, and you’re now holding a map to the dungeon of mirrors, where the compass that lets you navigate the prismatic forest (the location where they decide that the aurora borealis is most likely being held) is held. " << endl << endl;

  cout << "After some more walking you’re able to reach the dungeon of mirrors. Looking inside, you understand why it got its name: it seems to be made almost entirely of mirrors in there. Upon entering, you’re greeted with a puzzle. It seems you must enter the correct number to proceed, with the correct number being the solution to 6 / 2(1 + 2). Enter the correct number to proceed: " << endl;

  int puzzle;

  if (playerClass == 3) {
    while (true) {
      cin >> puzzle;
      if (puzzle == 9) break;
      cout << "You think about entering " << puzzle << ", but decide against it, thinking that it’s the wrong number. " << endl;
    }
  } else {
    cin >> puzzle;
    if (puzzle != 9) {
      cout << "Shards of glass rain from the ceiling. The shards by themself are pretty harmless, but you collapse out of shame for failing such a simple puzzle, ending your adventure. Game over. " << endl;
      return 0;
    }
  }

  cout << "Seems that was the correct answer. The door forward opens. " << endl << endl;

  cout << "After proceeding further in, you’re met with another puzzle. However, it’s too simple to be worth mentioning. " << endl << endl;

  cout << "With that, you arrive at the room containing the prismatic compass. You see it sitting on a pedestal in the center of the room… " << endl << endl;

  cout << "1. Approach it carefully" << endl;
  cout << "2. Just grab it " << endl;
  cout << "3. Smash it with your weapon" << endl;

  int compass = getChoice(1, 3);

  if (compass == 1) {
    cout << "Unfortunately you approach it too carefully; a beam of sunlight from outside manages to bounce its way through the halls of mirrors in a particularly unfortunate way, causing you to nearly go blind and forcing you to retire in the nearby village, ending your adventure. Game over. " << endl;
    return 0;
  }

  if (compass == 3) {
    cout << "Why the heck did you do that?! Now you’ll never find your way through the prismatic forest! Not being able to face the consequences back home, you’re forced to retire in the nearby village, ending your adventure. Game over. " << endl;
    return 0;
  }

  cout << "Nothing bad happens as you grab it. You got the prismatic compass! " << endl;
  cout << "The instructions on the bottom say to follow its lead except for after every third layer of the prismatic forest, at which point if it tells you to go more to the left you should go to the right, while if it tells you to go more to the right you should go to the left. " << endl << endl;

  cout << "A while later, you arrive at the prismatic forest, conveniently heading in a direction such that when walking forward, the compass points north. As you approach the forest, the needle begins to shift, facing northeast… " << endl;
  cout << "1. Head right" << endl;
  cout << "2. Head left" << endl;
  cout << "3. Head forward" << endl;

  if (getChoice(1, 3) != 1) {
    cout << "Why would you do that? Now you’re hopelessly lost! Your adventure, and this game, are over. " << endl;
    return 0;
  }

  cout << "After making it past the first circle of trees, the needle shifts once more, now pointing purely north… " << endl << endl;

  cout << "1. Head right" << endl;
  cout << "2. Head left" << endl;
  cout << "3. Head forward" << endl;

  if (getChoice(1, 3) != 3) {
    cout << "Why would you do that? Now you’re hopelessly lost! Your adventure, and this game, are over. " << endl;
    return 0;
  }

  cout << "You’ve now made it past the 2nd layer of trees, and the needle shifts yet again, now pointing northwest… " << endl << endl;

  cout << "1. Head right" << endl;
  cout << "2. Head left" << endl;
  cout << "3. Head forward" << endl;

  if (getChoice(1, 3) != 1) {
    cout << "Why would you do that? Now you’re hopelessly lost! Your adventure, and this game, are over. " << endl;
    return 0;
  }

  cout << "And with that, you’ve navigated your way through the prismatic forest. Atop a pillar in a clearing ahead of you, you see some familiar gems, but collecting them won’t be so easy: A giant mothman floats in the air between you and the gems! It seems that in its desire to get the greatest lamp to be near, it ended up stealing the aurora borealis! " << endl << endl;

  // Final fight
  if (playerClass == 1) {
    cout << "1. Swing at the mothman " << endl;
    cout << "2. Raise your shield" << endl;
    cout << "3. Stop drop and roll" << endl;

    int f1 = getChoice(1, 3);

    if (f1 == 1) {
      cout << "You attempt to swing at the mothman, but it’s flying so you miss. It then swoops down and impales you, ending your adventure. Game over. " << endl;
      return 0;
    }

    if (f1 == 3) {
      cout << "You stop drop and roll. You weren’t even on fire, what was the goal there? The mothman looks confused for a moment before swooping down and impaling you, ending your adventure. Game over. " << endl;
      return 0;
    }

    cout << "You ready your shield, and just in time, as the mothman attempts to swoop down and impale you. You manage to block it, and now it’s within your reach. " << endl;

    cout << "1. Continue blocking" << endl;
    cout << "2. Swing at the mothman" << endl;
    cout << "3. Try to cast a spell you don’t know" << endl;

    int f2 = getChoice(1, 3);

    if (f2 == 1) {
      cout << "You keep blocking, but the mothman loops around behind you and impales you, ending your adventure. Game over. " << endl;
      return 0;
    }

    if (f2 == 3) {
      cout << "Your eyes go white, and you feel yourself grow immensely cold as you channel the power of forbidden ice magic. Oh wait, that’s actually just the feeling of dying since the mothman impaled you. You aren’t a magic user, silly! Game over. " << endl;
      return 0;
    }

    cout << "You swing at the mothman and your blade connects, swiftly decapitating the cryptid. With that, you’re able to claim the gems containing the aurora borealis and return home a hero! " << endl;
  }

  if (playerClass == 2) {
    cout << "1. Prepare to dodge roll" << endl;
    cout << "2. Shoot at the mothman" << endl;
    cout << "3. Ready your comedically large spoon" << endl;

    int r1 = getChoice(1, 3);

    if (r1 == 2) {
      cout << "You shoot at the mothman, but it’s too high up and you miss. As you’re busy preparing your next shot, the mothman swoops down and impales you, ending your adventure. Game over. " << endl;
      return 0;
    }

    if (r1 == 3) {
      cout << "Wait, since when did you have a comedically large spoon? Both you and the mothman spend an eternity pondering this question. This isn’t really a loss, but you also never return home with the gems containing the aurora borealis. " << endl;
      return 0;
    }

    cout << "You stop, then as the mothman approaches you drop and roll. It’s now much closer, in reach for whatever you want to do next. " << endl;

    cout << "1. Prepare to dodge again" << endl;
    cout << "2. Shoot at the mothman " << endl;
    cout << "3. Summon critters to attack the mothman " << endl;

    int r2 = getChoice(1, 3);

    if (r2 == 1) {
      cout << "You prepare to dodge, but this time the mothman is expecting it and is able to impale you, ending your adventure. Game over. " << endl;
      return 0;
    }

    if (r2 == 3) {
      cout << "You use your ranger magic to summon various critters: gerbils, mice, and the likes. Unfortunately these critters are rather small and fail to do anything to stop the mothman from impaling you, ending your adventure. Game over. " << endl;
      return 0;
    }

    cout << "You shoot at the mothman. Your arrow flies straight and true, hitting the mothman in the chest and sending it backwards before pinning to a tree. With that, you’re able to collect the gems containing the aurora borealis and return home a hero! " << endl;
  }

  if (playerClass == 3) {
    cout << "1. Illusion magic" << endl;
    cout << "2. Frost magic " << endl;
    cout << "3. Rubber ducky magic" << endl;

    int m1 = getChoice(1, 3);

    if (m1 == 2) {
      cout << "You attempt to cast frost magic, but you freeze up a bit. The mothman takes this opportunity to impale you, ending your adventure. Game over. " << endl;
      return 0;
    }

    if (m1 == 3) {
      cout << "Unfortunately you’re out of explosive rubber duckies. The sheer embarrassment of this complete lack of preparation ends your adventure long before the mothman can even begin to attack. Game over. " << endl;
      return 0;
    }

    int roll = rand() % 4;

    if (roll == 0) {
      cout << "The mothman is puzzled by your illusions, and picks a target at random to charge at. Unfortunately, that target is you, you get impaled, and your adventure has failed. Game over. If only you were luckier, perhaps this option would have worked… " << endl;
      return 0;
    } else {
      cout << "The mothman is puzzled by your illusions, and picks a target at random to charge at. They charge at one of your illusions, run into a tree, and knock themselves unconscious. With that, you’re able to claim the gems containing the aurora borealis and return home a hero! " << endl;
    }
  }

  return 0;
}
