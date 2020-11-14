# pawn-rbits

[![Mergevos](https://img.shields.io/badge/Mergevos-pawn--rbits-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/pawn-rbits)

Ryder's rBits include because id doesn't have a Github repo.

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/pawn-rbits
```

Include in your code and begin using the library:

```pawn
#include <rbits>
```

## Usage

### Integer Limits
|Bit|Limits|
|----|-----|
|Bit1|0-1 (boolean)|
|Bit2|0-3|
|Bit4|0-15|
|Bit8|0-255 (char)|
|Bit16|0-65535|

### Declaration 

To declare a Bit Array, use the following code.

```pawn
new BitX: array<MAX_SIZE>;
``` 

_*Take into account that you must change X with a Bit Array type you want to create.*_
Thus, let's create Bit 4 nibble with a size of 32:

```pawn
new
    Bit4: b4_Nibble <32>
;
```
Pretty easy, huh?

### Setting and getting (originally written by RyDeR)

You can use the BitX_Set/Get function for this. For example:
```pawn
Bit4_Set(b4_Nibble, 0, 4);
```
This will set b4_Nibble at index 0 to a value of 4.

Retrieving the value is as simple as:
```pawn
Bit4_Get(b4_Nibble, 0);
```
This will return the value in b4_Nibble at index 0 which will be 4 in this case.

### Examples (originally written by RyDeR)

Here are some simple examples of what I mean by "saving lots of memory". I often see people doing things like this:
```pawn
#include <a_samp>
    
new
    bool: g_PlayerSpawned[MAX_PLAYERS]
;

public OnPlayerSpawn(playerid) {
    g_PlayerSpawned[playerid] = true;
}

public OnPlayerDeath(playerid) {
    g_PlayerSpawned[playerid] = false;
}

public OnPlayerDisconnect(playerid, reason) {
    g_PlayerSpawned[playerid] = false;
}

stock IsPlayerSpawned(playerid) {
    return g_PlayerSpawned[playerid];
}
```
The .amx size after compile is 726 bytes. Nothing much, but as you can see we're using 32-bit variables for only 0 and 1, so that's a waste of a lot memory. The most relevant bit type in this case would be 1-bit:

```pawn
#include <a_samp>
#include <rBits>

new
    Bit1: g_PlayerSpawned <MAX_PLAYERS>
;

public OnPlayerSpawn(playerid) {
    Bit1_Set(g_PlayerSpawned, playerid, true);
}

public OnPlayerDeath(playerid) {
    Bit1_Set(g_PlayerSpawned, playerid, false);
}

public OnPlayerDisconnect(playerid, reason) {
    Bit1_Set(g_PlayerSpawned, playerid, false);
}

stock IsPlayerSpawned(playerid) {
    return Bit1_Get(g_PlayerSpawned, playerid);
}
```

The .amx size of this after compile is only 473 bytes. Probably not a big deal right now, but imagine with larger arrays or just a couple of more arrays like this.

This is just analog all the rest of the bit-types, just make sure you pick the right bit-type for your value.


## Testing

To test, simply run the package and let y_testing do its job:

```bash
sampctl package run
```
