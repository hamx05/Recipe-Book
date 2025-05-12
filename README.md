# Recipe Book

## About  
This was my **first ever programming project**, built in **C**. It helped me practice and apply my fundamentals of programming — from working with arrays and conditionals to structuring data and implementing basic control flows.

## Overview  
**Recipe Book** is a command-line C application that lets users find recipes based on available ingredients. Users can choose from 8 ingredients, and the program displays all recipes that can be made using exactly those.

### Features  
- Select from a pre-defined menu of ingredients 
- Get recipe matches based on exact ingredients  
- View detailed info:
  - Ingredients required
  - Cuisine type (mostly Pakistani)
  - Category
  - Cooking time
  - Calorie count
  - Rating
  - Step-by-step instructions  
- Around **20 pre-defined recipes**  
- Option to search again or exit

### File Structure  
- `RecipeData.h` – Data structures and function declarations  
- `RecipeFunctions.c` – Function implementations and recipe data  
- `RecipeBook.c` – Main function and program flow  

## How to Compile  
```bash
gcc RecipeBook.c RecipeFunctions.c -o recipebook
./recipebook
```
