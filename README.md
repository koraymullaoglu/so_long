<h1 align="center">
	🕹️ so_long
</h1>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square"/>
	<img src="https://img.shields.io/github/languages/top/koraymullaoglu/so_long?color=%2312bab9&style=flat-square"/>
	<a href='https://www.linkedin.com/in/mullaoglukoray' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#contributing">Contributing</a> •
	<a href="#license">License</a>
</p>

## ABOUT

so_long is a basic 2D game in which a dolphin
escapes Earth after eating some fish. Instead of
a dolphin, fish, and the Earth, you can use any
character, any collectible and any place you want.



## HOW TO USE
#### 1º - Clone the repository
```git
git clone git@github.com:koraymullaoglu/so_long.git
```

#### 2º - Enter the project folder
```bash
cd so_long
```
#### 3º - Download MinilibX for Linux into the so_long folder.

#### MAKEFILE RULES

`make` or `make all` - Compile pipex files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
> Your program has to take as parameter a map description file ending with the .ber
extension.
```bash
./so_long maps/map.ber
```

- You must use the MiniLibX.
- You have to turn in a Makefile which will compile your source files

## GAME
> The player’s goal is to collect all collectibles on the map and then escape by choosing the shortest possible route.

- The W, A, S, and D keys must be used to move the main character
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).
- The game does not have to be in real time.

> The map can be composed of only these 5 characters: 
- 0 for an empty space,
- 1 for a wall,
- C for a collectible,
- E for a map exit,
- P for the player’s starting position.

>There is a simple valid map in maps/map.ber file

## NORMINETTE
> At 42 School, it is expected that almost every project is written following the Norm, which is the coding standard of the school.

```
- No for, do...while, switch, case, goto, ternary operators, or variable-length arrays allowed;
- Each function must be a maximum of 25 lines, not counting the function's curly brackets;
- Each line must be at most 80 columns wide, with comments included;
- A function can take 4 named parameters maximum;
- No assigns and declarations in the same line (unless static);
- You can't declare more than 5 variables per function;
- ...
```

* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`

## CONTRIBUTING

If you find any issues or have suggestions for improvements, feel free to fork the repository and open an issue or submit a pull request.

## LICENSE

This project is available under the MIT License. For further details, please refer to the [LICENSE](https://github.com/koraymullaoglu/pipex/blob/main/LICENSE) file.