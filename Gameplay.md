
## Race attributes

The base points should all add up to 27 for each race
Human attack 9 health 9 stamina 9
Elf attack 7 health 10 stamina 10
Ork attack 12 health 9 stamina 6
Goblin attack 6 health 8 stamina 13
Goblin attack 10 health 10 stamina 7

---

## Attributes

### Health

### Attack

Attacks and heals get a "dice roll", an rng from 1 to 20, 1-3 action failed, 4-7 effect is reduced by 20 to 30%, 8-14 base effect, 15 to 19 effect is enhanced by 20 to 30$, 20 effect is doubled. Or implement "dice rolls" where 1-3 = big negative multiplier, but not 0

### Stamina

Stamina gives you a higher chance of blocking and can give you a chance to perform more actions. 
At the end of your turn in battle, a "dice roll" is performed that, if high enough, will let you 
perform an action again. NPCs don't get this chance. Your stamina is also your block. If your stamina 
is more than the opponent's stamina, a "dice roll" will determine wether the attack hits and with 
how many points.

---

Gameplay loop: prompt - options - choice - repeat
Options will eventually be like custom commands and should look like: ACTION TARGET
Example: Interact TavernKeeper, Attack Bandit1

Dialogue loops should look similar: prompt, response/choice, repeat

Response structure should be like the race picking at the start, with numbers.

When you enter a scene, you may get to see some interests and NPCs. By looking around and getting 
lucky, You may find more of these, giving you more options.

In a "scene", there should be an option to interact with every NPC present. These can be: speak, 
attack, leave. Every NPC you can speak to has a "good bye" option. You can attack any NPC, but some 
may receive help from nearby NPCs.
If an NPC is marked as hostile, speaking is not an option. If a character is marked as merchant, if 
you speak to them, you can barter.

---

## Actions
move to interest
speak with npc
attack npc
look around
Rest (near chairs and beds)

---

## Dice rolls

Dice rolls are a random number where the lowest outcome is 0 and the highest 20, but the steps go: 2, 
6, 12 and 20. 2 is a more like a coinflip, but for simplicity, let's put it under dice roll. The 
function performing it should look like D(int parameter) D for dice, paramterer is 2, 6, 12 or 20. 
Reason for this is that these dice would be called d6, d12 and d20.

---

## Battle sequence

Start:
	- Coin flip/D2 to see who starts
Battle:
	- Fighter 1's turn
	- Check if anyone died
	- Fighter 2's turn
	- Check if anyone died
	- Repeat from 

### Choice
ATTACK
Attacks the opponent. Attacks and heals get a "dice roll": 1 to 20 = 1-3 action failed; 4-7 = effect 
is reduced by 20 to 30%; 8-14 = base effect; 15 to 19 effect is enhanced by 20 to 30%, 20 = effect is doubled.

COUNTER
On the opponent's turn, if attacker's current stamina is higher than the opponent's, both sides will take damage. 
The attacker takes less than the target.

FLEE
The fighter may attempt to flee. This, when successful, will let the fighter get away from battle. They 
can still get attacked, and if they take damage, the flee gets interrupted.

A block gets performed on the opponent's turn. When the opponent attacks, your max stamina stats are compared and 
if your stamina is higher than opponent's, a D12 will determine hove much damage their attack deals. In case 
an attack is less than 0, it is set to 0. That means a block cannot hurt the attacker. Counter, on 
the other hand, can.
