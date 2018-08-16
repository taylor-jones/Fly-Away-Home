# Text/2D Map Game

This is text-based game with a 2d map that I completed as a project for coursework at Oregon State University. The inspiration for the gameplay is from the original ToeJam & Earl game for Sega Genesis, though this is obviously much simpler.


### How To play
Clone the repository and then (from within the cloned directory) run Make. That produces an executable file named "play" that can be run to play the game.


## Synopsis

The player is represented by an alien. The Alien’s spaceship has crash landed on Earth, and the pieces of the spaceship are scattered on the different islands (of Earth). In order to return back to your home land, you must collect the different ship pieces (which puts your spaceship back together) at which point you can hop in the spaceship and fly home. The Earth you experience in the game is represented by different islands (levels), and there is one ship piece on each island. Your overall goal is to find all the ship pieces so you can put the spaceship back together. However, the goal on each island is to find a single ship piece and
then find the elevator, which is how you’re able to move up to the next island. No matter which island you’re on when you find the final ship piece, the spaceship will appear. Once it does, all you have to do is get to the spaceship and then you’re home free back to your motherland. Along your journey, you’ll have to endure the different terrains of earth, possibly interact with different
types of earthlings, and maybe even use some cash or other presents to aid you along the way. All of this is described in detail below.


<br>

# Game Details

## Spaces

At the root of the game’s structure is the Space class. A space (in my game) is a single location on an Island, and an Island essentially acts as a linked structure of Spaces (though Islands also have several other properties). The Game itself is made up of 8 Islands.

Spaces each have 6 pointers to other Spaces:
- Top
- Bottom
- Left
- Right
- Above
- Below

Top, Bottom, Left, and Right are 2D pointers (in the dimensions of reality sense) since they point to the neighboring spaces on the same island. Above and below are 3D pointers since they point to spaces on the island above and below the current island.

There are 9 different types of Spaces in the game, each of which is represented by its own class (which derives from an abstract Space class). Each type of Space provides a different experience for the Alien (and some experiences are based on additional conditions):
  - Grass - (green) - this is the default type of Space on earth.
    - While on grass, the Alien moves at a normal speed, and each step drains the Alien of 1 energy point. No other conditions affect the Alien’s experience on Grass.
  - Water - (blue) 
    - While In water, the Alien moves at a normal speed, but its energy is drained 3x as fast, so 3 energy points for each step. However, if the Alien gets out of the water before losing all of its energy then the energy is restored to the value it was at whenever the Alien first entered the water.
  - Road - (dark grey)  
    - While on the road, the Alien moves twice as fast as normal, so 2 spaces for each step, but is only drained 1 energy point per step.
  - Sand - (yellow)
    - While in sand, the Alien has a 50% chance of not being able to move each step. The Alien is still drained 1 energy point each step whether able to move or not.
  - Slider - (light grey)
    - Whenever on a slider, the Alien is automatically moved to the end of the slider spaces (like a people-mover). The Alien is only drained 1 energy point no matter how long the slider is.
  - Outer Space - (black)
    - Even though you’re an Alien, you still can’t fly (on your own), so if you walk into an outer-space space, you’ll fall down to the island below (and that’ll cost you 25 energy points).
  - Homeland (magenta)
    - Whenever you’re back on your homeland, everything is good again, so each step will actually increase your energy by 1 point. 
    
    
*These last 2 types of spaces are a bit different than the others, and there was some question as to whether to represent these as Spaces or Items (which I’ll describe further), but ultimately I chose to represent them as Spaces due to their being stationary.*

- Elevator (red)
  - The elevator most the Alien up to the next Island. It cost no energy.
- Mailbox (white)
  - The mailbox gives the Alien an opportunity to purchase food or other items that can aid the Alien’s health or capabilities.


*Additionally, since the spaces on each island are unknown (until you traverse them), they’ll be represented by question marks. Once you move over a space, it will permanently stay uncovered.*


<br>

## Alien
As mentioned, you play the game as the Alien, and there’s only 1 of you in the game - you. There’s a bunch of information kept about you during gameplay, and your stats are displayed at the top of the terminal so that you can keep an eye on things. You may move choose from a persistent menu of actions during the game, and you may collect items (which you’ll keep in your bag until you’re ready to use them) and/or you may interact with Earthlings. Some of your notable attributes are:

- Lives - you start with 3, and anytime that your energy goes down to 0, you lose a life. You won’t be pulled out of the game or moved when this happens, but if you lose all your energy and have 0 lives left, the game is over.

- Rank - at the beginning of the game, you’re given a silly rank. There are 9 of these, and the terminology is adopted directly from Toejam & Earl. You can jump up to the next rank by gaining points (which is done by eating food). Whenever you move up to a higher rank, your energy bar is greater, so you’re able to live longer. However, it gets harder & harder to keep ranking up.

- Cash - you start with no cash, but if you’re lucky you’ll find cash lying around the islands. You can use this to purchase presents or food from the mailbox.

- Bag - your bag starts empty, and it has a capacity of 5 items. Whenever you pick up a present or purchase one from the mailbox, you’ll add it to your bag. Whenever you use a present, you’ll remove it from your bag. At any point, you can drop items from your bag in order to make space.

- Ship Pieces - as described earlier, you need these to get off the island. The good news is, they don’t take up bag space. Also, there’s 1 and only 1 on each island.

- Active Item - whenever one of your items is in use, you’ll be able to see what it is and how much longer it’ll last. Each of the items is described in detail in the Items section.


<br>

## Items
The game contains multiple instances of many of these types of Items, but not every Item is necessarily present on each Island. There are 10 different types of items in the game, and they may show up for different reasons or in different contexts.

*Note: Items marked as presents (P) can either be found lying around the island or
bought from the mailbox.*

- Money - money can be found lying around the islands. To pick it up, just move over it, and you’ll be given an a message that you’ve collected it (Note: money does not take up bag space)

- Food - food is similar to money in that it’s found lying around, and you pick it up the same way, except food increases points and money increases cash (Note: food also doesn’t take up bag space, unless bought from the mailbox)

- Binoculars (P) - if you use binoculars, you’ll be able to uncover all the Spaces in a chosen direction.

- Inner Tube (P) - While using the innertube, you’re able to float in water without losing any energy.

- Icarus Wings (P) - Icarus Wings allow you to move (fly) over Outer Space without falling the the island below. They also allow you to fly over Shark-infested waters undetected.

- Speed Skates (P) - While using Speed Skates on a Road space, you’ll speed up to 3x the normal speed.

- Decoy (P) - If you place a decoy in shark-infested waters, and sharks in the water will go after the decoy instead of you.

- Doorway (P) - If you place a doorway on the island, you can walk through it to be transported to another random location on the same island.

- Ship Piece - you can’t buy these. You’ll have to find them.

- Spaceship - This only appears when all your ship pieces are found.



<br>

## Earthlings
Note: The game contains multiple instances of each of these types of Earthlings, but not every Earthing is necessarily present on each Island

The game contains 4 different types of Earthlings, each of which you can interact with in different ways.
- Shark - Sharks can only be in the water, but you want to stay away from them. One hit from these will cost you 25 energy points, and they’ll come for you as soon as you get in their water.

- Wizard - the Wizard only moves horizontally across the island. If you find him, he’ll offer to replenish your energy for a small fee.

- Cartographer - the Cartographer likes to explore the limits of the island, so he’s often found at the edges (all though, sometimes you’ll find him cutting across the island if he’s interrupted at an edge). If you find him, he may offer to give or sell you his maps to uncover the entire island. Sometimes he’s generous sometimes he’s greedy.

- Bookie - the Bookie will do just about anything to get you to gamble. He’s got a couple of games that he likes to play, and he’ll offer to let you gamble with your money or your energy.



<br>

### Final Notes
- The Alien is limited by its health. Every move requires energy, and once it runs out, you lose the game.
- In order to complete the game, you must find all the ship pieces to put the ship together, which flies you back to your Homeland (the final Island). If you make it here before all your energy is gone, you win.
- Many of the elements/locations of elements on the island are randomly generated and should be different from game to game.

<br>

### Easter Egg
- There’s a way to get a specific Bookie to offer you a deal that could win the game early for you. What you need to do is interact with the Bookie on level 2, twice. The first time, he won’t offer the deal. You’ll need to decline his first few offers, and then he’ll offer you something really nice, but it’s risky.
