# Cereal Killer
This game is a keybased game that uses the arrow keys to aim at cereal and the space bar to attack.

Written by Danielle Hata

----

## Objects
  1. Object A - Balloon
  	* moves straight, at any angle
  	* enters from N W E, exits from S E W
  2. Object B - Clover
  	* moves straight. After moving forward 10 paces, begins moving backward by 5 paces, then forward 10 paces again
  	* enters from N W E, exits from S E W
  3. Object C - Diamond
  	* moves zig zag. Moves forward 5 paces, then turns 45 degrees left, moves forward 5 paces, then turns 45 degrees right, repeat
  	* enters from N W E, could exit any side
  4. Object D - Moon
  	* moves horizontally at a 20 degree angle back and forth across the screen, bounces off the right and left sides
  	* enters from the top, exits from the bottom.
  5. Object E - Star
  	* moves randomly up, down, left right
  	* enters from N W E, could exit any side
  	* not killable, when it collides with other objects it destroys them
Images from [First Fear]("http://firstfear.deviantart.com/art/Pixel-LuckyCharms-Icons-269837586?q=gallery%3Afirstfear%2F2084580&qo=27")

## How to Play

There will be a docked gun at the bottom of the screen in the middle. You will shoot at the objects with bubbles. There is a limited number of bubbles, and when you run out of bubbles, you die.
For every object you defeat, you get more bubbles. There is no penalty for missing killing an object or when an object hits the gun.

### Equip
Uses the keys, x, c, and enter
  1. **x** turns the gun to the left
  2. **c** turns the gun to the right
  3. **enter** shoots a bubble

## Scoring

Score will increase by how many objects you kill. Points are granted based on the speed of the object killed. Each type of object grants a certain number of bubbles. Score cannot go down.

## Lives

Player starts with 50 bubbles, decreases 1 bubble for every shot out of the gun, increases bubbles by killing objects. Each type of object gives a different bubble reward.
The game ends when the player runs out of bubbles.

## UI Layout
| Graphic            | Qt Class    | Location         |
|--------------------|-------------|------------------|
| Start Button       | QPushButton | Top left         |
| Pause Button       | QPushButton | Top mid          |
| Quit Button        | QPushButton | Top right        |
| Name Entry         | QLineEdit   | Above Start      |
| Score              | QText       | Bottom right     |
| Bubble Count       | QText       | Bottom mid       |
| Score/Object Guide | QListView   | Right Navigation |
| Key Instructions   | QListView   | Right Navigation |

![alt text](http://i46.tinypic.com/e9atds.jpg)
