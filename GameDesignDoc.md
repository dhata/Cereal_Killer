# Cereal Killer
This game is a keybased game that uses the keys x and c to move the player and the m key to attack.

Written by Danielle Hata

----

## Objects
  1. Object A - Balloon
  	* moves straight, at any angle
  	* enters from N W E, exits from S E W
  2. Object B - Clover
  	* moves straight. After moving forward 10 paces, begins moving backward by 5 paces, then forward 10 paces again
  	* enters from N W E, exits from S E W 
  3. Object C - Moon
  	* moves zig zag. Moves forward 5 paces, then turns 45 degrees left, moves forward 5 paces, then turns 45 degrees right, repeat
  	* enters from N W E, could exit any side
  4. Object D - Diamond
  	* moves straight back and forth across the screen, bounces off the sides
  	* enters from the any side, does not exit unless destroyed
  5. Object E - Star
  	* moves randomly up, down, left right
  	* doesn't leave the screen. The number of stars cumulates and makes the game harder
  	* not killable, when it collides with other objects it destroys them
  6. Object F - Player (crystal)
  	* moves horizontally on the bottom of the screen.
  	* starts in the middle of the screen
  	* collisions don't matter
  7. Object G - Bullet (small crystal)
  	* move straight North from the center of the player.
  	* each bullet takes one point from the user's life
  	* collision with cereal gives more life

![alt text](images/balloon.gif "balloon") ![alt text](images/clover.gif "clover") ![alt text](images/moon.gif "moon") ![alt text](images/diamond.gif "diamond") ![alt text](images/star.gif "star") ![alt text](images/gradient2.png "player") ![alt text](images/purple.png "bullet")

Images from [First Fear](http://firstfear.deviantart.com/art/Pixel-LuckyCharms-Icons-269837586?q=gallery%3Afirstfear%2F2084580&qo=27)

## How to Play

There will be a docked gun at the bottom of the screen. You will shoot at the objects with crystals. There is a limited number of crystals, and when you run out of crystals, you die.
For every object you defeat, you get more crystals. There is no penalty for missing killing an object or when an object hits the gun.

### Equip
Uses the keys, x, c, and m
  1. **x** moves the gun to the left
  2. **c** moves the gun to the right
  3. **m** shoots a crystal

## Scoring

Score will increase by how many objects you kill. Points are granted based on the speed of the object killed. Each type of object grants a certain number of crystals. Score cannot go down.

## Lives

Player starts with 50 crystals, decreases 1 crystal for every shot out of the gun, increases crystals by killing objects. Each type of object gives a different crystal reward.
The game ends when the player runs out of crystals.

## UI Layout
| Graphic            | Qt Class    | Location         |
|--------------------|-------------|------------------|
| Start Button       | QPushButton | Top left         |
| Pause Button       | QPushButton | Top mid          |
| Quit Button        | QPushButton | Top right        |
| Name Entry         | QLineEdit   | Above Start      |
| Score              | QText       | Bottom right     |
| Crystal Count      | QText       | Bottom mid       |
| Score/Object Guide | QListView   | Right Navigation |
| Key Instructions   | QListView   | Right Navigation |

![alt text](images/layout.jpg "sample game layout")
